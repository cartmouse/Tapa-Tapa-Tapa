/*
  ==============================================================================

    Delay.h
    Created: 5 Apr 2020 10:14:13am
    Author:  Tom Cartwright

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Delay
{
public:
    Delay();
    ~Delay() {};

    // ==================== Methods ===============================================
    // Set methods
    void setWetDry(float wetDry);
    void setFeedback(float Feedback);
    void setDelayTime(float delayTimeMS);
    void setTapMix(float tapMix);
    void setTapProportion(float tapProportion);

    // Get methods
    float getWetDry(void);
    float getFeedback(void);
    float getMix(void);
    float getDelayTime(void);
    float getTapProportion(void);
    float getMaxDelay(void);

    // Other public methods
    void initialise(double sampleRate);
    float processDelay(float input);

private:
    // ==================== Methods ===============================================
    int calculateReadPoint(int nDelaySamples);
    int calculateTotalDelaySamples(float delayTimeMS);
    int calculateTapDelaySamples(float delayTimeMS);

    // ==================== Members ===============================================
    // Delay control parameters
    float mWetDry;
    float mFeedback;
    float mMix;
    float mTotalDelayMS;
    float mTapProportion;

    // Delay line information
    float mMaxDelaySeconds;
    int mMaxDelaySamples;
    int mWritePoint;

    // Sample storage
    float mInputSample;
    float mDelayOutputSample;
    int mTotalSampleDelay;
    int mTapSampleDelay;

    // Other members
    float mSampleRate;
    float mCutoffFreq;

    // Smoothed value objects to remove audio glitches controls are changed
    SmoothedValue<int> mTotalSampleDelaySmoother;
    SmoothedValue<int> mTapSampleDelaySmoother;
    SmoothedValue<float> mWetDrySmoother;
    SmoothedValue<float> mTapMixSmoother;
    SmoothedValue<float> mFeedbackSmoother;

    // Audio buffer for the delay line
    AudioBuffer<float> mDelayLine;

    // Filter objects
    dsp::IIR::Filter<float> mLowPassN;
    dsp::IIR::Filter<float> mLowPassM;
};