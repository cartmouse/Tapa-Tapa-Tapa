/*
  ==============================================================================

    Delay.cpp
    Created: 5 Apr 2020 10:14:13am
    Author:  Tom Cartwright

  ==============================================================================
*/

#include "Delay.h"

// constructor
// =========================================
// Initialise all members

Delay::Delay()
{
    // Delay line values
    mMaxDelaySeconds = 3.0;
    mSampleRate = 0;
    mMaxDelaySamples = 0;
    mWritePoint = 0;
    mTotalSampleDelay = 0;
    mTapSampleDelay = 0;

    // Control values
    mWetDry = 0.5;
    mFeedback = 0.5;
    mMix = 0.5;
    mTapProportion = 0.5f;
    mTotalDelayMS = mMaxDelaySeconds * 500.0f;

    // Cutoff frequency for the filters
    mCutoffFreq = 2000.0f;

    // Input and output samples
    mInputSample = 0.0f;
    mDelayOutputSample = 0.0f;
}


// processDelay
// =========================================
// Public method that takes a sample and passes it through the delay architecture

float Delay::processDelay(float inputSample)
{
    mInputSample = inputSample;

    // Retrive control values from smoothers
    auto totalSampleDelay = mTotalSampleDelaySmoother.getNextValue();
    auto variableSampleDelay = mTapSampleDelaySmoother.getNextValue();
    auto feedbackGain = mFeedbackSmoother.getNextValue();
    auto wetDryGain = mWetDrySmoother.getNextValue();
    auto tapMixGain = mTapMixSmoother.getNextValue();

    // Sum input with feedback and write to delay line
    float newSample = mInputSample + (mDelayOutputSample * feedbackGain);

    mDelayLine.setSample(0, mWritePoint, newSample);

    // Read from the delay line
    auto delaySample = mDelayLine.getSample(0, calculateReadPoint(totalSampleDelay));
    auto tapSample = mDelayLine.getSample(0, calculateReadPoint(variableSampleDelay));

    // Filter the samples from the delay line and calculate delay output
    auto filteredDelaySample = mLowPassM.processSample(delaySample);
    auto filteredTapSample = mLowPassN.processSample(tapSample);
    mDelayOutputSample = (filteredDelaySample * (1 - tapMixGain)) + (filteredTapSample * tapMixGain);

    // Iterate write index and wrap round delay line
    ++mWritePoint %= mMaxDelaySamples;

    return (mDelayOutputSample * wetDryGain) + (inputSample * (1 - wetDryGain));
}


// ========== Calculation Methods =================================================

int Delay::calculateReadPoint(int nDelaySamples)
{
    return ( mWritePoint - nDelaySamples + mMaxDelaySamples ) % mMaxDelaySamples;
}

int Delay::calculateTapDelaySamples(float delayTimeMS)
{
    return (int)((delayTimeMS / 1000.0f) * mTapProportion * mSampleRate);
}

int Delay::calculateTotalDelaySamples(float delayTimeMS)
{
    return (int)((delayTimeMS / 1000.0f) * mSampleRate);
}

// ========== "Set" Methods =======================================================
// Public methods for assigning values to private members, calculating sample delay
// times and set the target value for the smoothers

void Delay::setWetDry(float wetDry)
{
    mWetDrySmoother.setTargetValue(wetDry);
    mWetDry = wetDry;
}

void Delay::setFeedback(float feedback)
{
    mFeedbackSmoother.setTargetValue(feedback);
    mFeedback = feedback;
}

void Delay::setDelayTime(float delayTimeMS)
{
    mTotalSampleDelay = calculateTotalDelaySamples(delayTimeMS);
    mTapSampleDelay = calculateTapDelaySamples(delayTimeMS);

    mTotalSampleDelaySmoother.setTargetValue(mTotalSampleDelay);
    mTapSampleDelaySmoother.setTargetValue(mTapSampleDelay);

    mTotalDelayMS = delayTimeMS;
}

void Delay::setTapProportion(float tapProportion)
{
    mTapSampleDelay = calculateTapDelaySamples(mTotalDelayMS);
    mTapSampleDelaySmoother.setTargetValue(mTapSampleDelay);

    mTapProportion = tapProportion;
}

void Delay::setTapMix(float tapMix)
{ 
    mTapMixSmoother.setTargetValue(tapMix);
    mMix = tapMix;
}


// ========== "Get" Methods =======================================================
// Public methods for retrieving values from private members

float Delay::getWetDry(void)
{
    return mWetDry;
}

float Delay::getFeedback(void)
{
    return mFeedback;
}

float Delay::getDelayTime(void)
{
    return mTotalDelayMS;
}

float Delay::getTapProportion(void)
{
    return mTapProportion;
}

float Delay::getMix(void)
{
    return mMix;
}

float Delay::getMaxDelay(void)
{
    return mMaxDelaySeconds * 1000.0f;
}


// initalise
// =========================================
// Method to set initalise members and objects needed before audio 
// can be passed through the rest of the delay architecture

void Delay::initialise(double sampleRate)
{
    // ======== Members ====================
    mSampleRate = (float)sampleRate;
    mMaxDelaySamples = (int)(sampleRate * mMaxDelaySeconds + 1);
    mWritePoint = 0;
    mTotalSampleDelay = calculateTotalDelaySamples(mTotalDelayMS);
    mTapSampleDelay = calculateTapDelaySamples(mTotalDelayMS);

    // ======== Delay Line =================
    mDelayLine.setSize(1, mMaxDelaySamples);
    mDelayLine.clear();

    // ======== Filters ====================
    auto coeffs = dsp::IIR::Coefficients<float>::makeFirstOrderLowPass(sampleRate, mCutoffFreq);

    mLowPassN.coefficients = coeffs;
    mLowPassM.coefficients = coeffs;

    // ======== Smoothers ==================
    auto rampTimeSeconds = 0.3;

    mTotalSampleDelaySmoother.reset(sampleRate, rampTimeSeconds);
    mTotalSampleDelaySmoother.setCurrentAndTargetValue(mTotalSampleDelay);

    mTapSampleDelaySmoother.reset(sampleRate, rampTimeSeconds);
    mTapSampleDelaySmoother.setCurrentAndTargetValue(mTapSampleDelay);

    mWetDrySmoother.reset(sampleRate, rampTimeSeconds);
    mWetDrySmoother.setCurrentAndTargetValue(mWetDry);

    mTapMixSmoother.reset(sampleRate, rampTimeSeconds);
    mTapMixSmoother.setCurrentAndTargetValue(mMix);

    mFeedbackSmoother.reset(sampleRate, rampTimeSeconds);
    mFeedbackSmoother.setCurrentAndTargetValue(mFeedback);
}