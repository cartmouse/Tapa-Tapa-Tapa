/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "TapatapatapaAudioProcessor.h"
#include "TapatapatapaAudioProcessorEditor.h"

//==============================================================================
TapatapatapaAudioProcessor::TapatapatapaAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput("Input", AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", AudioChannelSet::stereo(), true)
#endif
    ),
    parameters(*this, nullptr, Identifier("TapaTapaTapa"),
        {
            std::make_unique<AudioParameterFloat> ( "feedback",
                                                    "Feedback",
                                                    NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                                                    0.5f ),
            std::make_unique<AudioParameterFloat> ( "time",
                                                    "Time",
                                                    NormalisableRange<float>(0.0f, mMaxDelaySeconds * 1000.0f, 1.0f),
                                                    1000.0f ),
            std::make_unique<AudioParameterFloat> ( "tap",
                                                    "Tap",
                                                    NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                                                    0.5f ),
            std::make_unique<AudioParameterFloat> ( "cutoff",
                                                    "Cutoff",
                                                    NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.3f),
                                                    2000.0f),
            std::make_unique<AudioParameterFloat> ( "tapMix",
                                                    "TapMix",
                                                    NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                                                    0.5f ),
            std::make_unique<AudioParameterFloat> ( "wetDry",
                                                    "WetDry",
                                                    NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                                                    0.5f )
        }), mFilter(dsp::IIR::Coefficients<float>::makeLowPass(44100, 20000.0f))
#endif
{
    feedbackParam = parameters.getRawParameterValue("feedback");
    timeParam = parameters.getRawParameterValue("time");
    tapParam = parameters.getRawParameterValue("tap");
    cutoffParam = parameters.getRawParameterValue("cutoff");
    tapMixParam = parameters.getRawParameterValue("tapMix");
    wetDryParam = parameters.getRawParameterValue("wetDry");
}

TapatapatapaAudioProcessor::~TapatapatapaAudioProcessor()
{
}

//==============================================================================
const String TapatapatapaAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TapatapatapaAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TapatapatapaAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TapatapatapaAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TapatapatapaAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TapatapatapaAudioProcessor::getNumPrograms()
{
    return 1;
}

int TapatapatapaAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TapatapatapaAudioProcessor::setCurrentProgram (int index)
{
}

const String TapatapatapaAudioProcessor::getProgramName (int index)
{
    return {};
}

void TapatapatapaAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TapatapatapaAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // ========== Delay Line ==========
    auto bufferSize = mMaxDelaySeconds * (sampleRate + samplesPerBlock);
    mDelayLine.setSize(getTotalNumInputChannels(), bufferSize);
    mDelayLine.clear();

    mFeedbackBuffer.setSize(getTotalNumInputChannels(), bufferSize);
    mFeedbackBuffer.clear();

    // ========== Filter ==========
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();

    mFilter.prepare(spec);
    mFilter.reset();

    // ========== Other ==========
    mSampleRate = sampleRate;
}

void TapatapatapaAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TapatapatapaAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TapatapatapaAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // Process input
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        // Input to delay line
        fillDelayLine(buffer, channel, false, mPrevWetDry, *wetDryParam);
        // Add feedback
        fillDelayLine(mFeedbackBuffer, channel, true);
    }

    // Process ouput
    for (int channel = 0; channel < totalNumOutputChannels; ++channel)
    {
        auto tapGainStart = mPrevTapMix * mPrevWetDry;
        float tapGainEnd = *tapMixParam * *wetDryParam;
        auto totalGainStart = (1.0f - mPrevTapMix) * mPrevWetDry;
        float totalGainEnd = (1.0f - *tapMixParam) * *wetDryParam;

        // Add input to output
        buffer.copyFromWithRamp(channel, 0, buffer.getReadPointer(channel), buffer.getNumSamples(), 1.0f - mPrevWetDry, 1.0f - *wetDryParam);

        // Read from delay after tap
        readDelayLine(buffer, channel, calcReadPnt(*timeParam * *tapParam), true, tapGainStart, tapGainEnd);

        // Read from delay after total
        readDelayLine(buffer, channel, calcReadPnt(*timeParam), true, totalGainStart, totalGainEnd);

        // Write for feedback
        mFeedbackBuffer.copyFromWithRamp(channel, 0, buffer.getReadPointer(channel), buffer.getNumSamples(), mPrevFeedback, *feedbackParam);
    }

    filterBuffer(buffer, *cutoffParam);

    mWritePnt += buffer.getNumSamples();
    mWritePnt %= mDelayLine.getNumSamples();

    mPrevFeedback = *feedbackParam;
    mPrevTapMix = *tapMixParam;
    mPrevWetDry = *wetDryParam;
}

//==============================================================================
bool TapatapatapaAudioProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor* TapatapatapaAudioProcessor::createEditor()
{
    return new TapatapatapaAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void TapatapatapaAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void TapatapatapaAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(ValueTree::fromXml(*xmlState));
}

//==============================================================================
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TapatapatapaAudioProcessor();
}

//==============================================================================
// CUSTOM METHODS
//==============================================================================

// Fill the delay line with samples from audio block
void TapatapatapaAudioProcessor::fillDelayLine(AudioBuffer<float>& buffer, int channel, bool add)
{
    if (mWritePnt + buffer.getNumSamples() <= mDelayLine.getNumSamples())
    {
        if (add)
            mDelayLine.addFrom(channel, mWritePnt, buffer.getReadPointer(channel), buffer.getNumSamples());
        else
            mDelayLine.copyFrom(channel, mWritePnt, buffer.getReadPointer(channel), buffer.getNumSamples());
    }
    else
    {
        const auto midPos = mDelayLine.getNumSamples() - mWritePnt;
        if (add)
        {
            mDelayLine.addFrom(channel, mWritePnt, buffer.getReadPointer(channel), midPos);
            mDelayLine.addFrom(channel, 0, buffer.getReadPointer(channel, midPos), buffer.getNumSamples() - midPos);
        }
        else
        {
            mDelayLine.copyFrom(channel, mWritePnt, buffer.getReadPointer(channel), midPos);
            mDelayLine.copyFrom(channel, 0, buffer.getReadPointer(channel, midPos), buffer.getNumSamples() - midPos);
        }
    }
}

// Fill the delay line with samples from audio block
void TapatapatapaAudioProcessor::fillDelayLine(AudioBuffer<float>& buffer, int channel, bool add, float startGain, float endGain)
{
    if (mWritePnt + buffer.getNumSamples() <= mDelayLine.getNumSamples())
    {
        if (add)
            mDelayLine.addFromWithRamp(channel, mWritePnt, buffer.getReadPointer(channel), buffer.getNumSamples(), startGain, endGain);
        else
            mDelayLine.copyFromWithRamp(channel, mWritePnt, buffer.getReadPointer(channel), buffer.getNumSamples(), startGain, endGain);
    }
    else
    {
        const auto midPos = mDelayLine.getNumSamples() - mWritePnt;
        if (add)
        {
            mDelayLine.addFromWithRamp(channel, mWritePnt, buffer.getReadPointer(channel), midPos, startGain, endGain);
            mDelayLine.addFromWithRamp(channel, 0, buffer.getReadPointer(channel, midPos), buffer.getNumSamples() - midPos, startGain, endGain);
        }
        else
        {
            mDelayLine.copyFromWithRamp(channel, mWritePnt, buffer.getReadPointer(channel), midPos, startGain, endGain);
            mDelayLine.copyFromWithRamp(channel, 0, buffer.getReadPointer(channel, midPos), buffer.getNumSamples() - midPos, startGain, endGain);
        }
    }
}

// Read from the delay line at a given read point
void TapatapatapaAudioProcessor::readDelayLine(AudioBuffer<float>& buffer, int channel, int readPnt, bool add, float startGain, float endGain)
{
    auto bufferLength = buffer.getNumSamples();
    auto delayLineLength = mDelayLine.getNumSamples();

    if (readPnt + bufferLength <= delayLineLength)
    {
        if (add)
            buffer.addFromWithRamp(channel, 0, mDelayLine.getReadPointer(channel, readPnt), bufferLength, startGain, endGain);
        else
            buffer.copyFromWithRamp(channel, 0, mDelayLine.getReadPointer(channel, readPnt), bufferLength, startGain, endGain);
    }
    else
    {
        const auto midPos = mDelayLine.getNumSamples() - readPnt;
        if (add)
        {
            buffer.addFromWithRamp(channel, 0, mDelayLine.getReadPointer(channel, readPnt), midPos, startGain, endGain);
            buffer.addFromWithRamp(channel, midPos, mDelayLine.getReadPointer(channel), bufferLength - midPos, startGain, endGain);
        }
        else
        {
            buffer.copyFromWithRamp(channel, 0, mDelayLine.getReadPointer(channel, readPnt), midPos, startGain, endGain);
            buffer.copyFromWithRamp(channel, midPos, mDelayLine.getReadPointer(channel), bufferLength - midPos, startGain, endGain);
        }
    }
}

void TapatapatapaAudioProcessor::filterBuffer(AudioBuffer<float>& buffer, float cutoffParam)
{
    dsp::AudioBlock <float> block(buffer);
    *mFilter.state = *dsp::IIR::Coefficients<float>::makeLowPass(mSampleRate, cutoffParam);
    mFilter.process(dsp::ProcessContextReplacing<float>(block));
}

// Calculate read point from current write point and a given delay time
int TapatapatapaAudioProcessor::calcReadPnt(float timeMS) const
{
    // read delayed signal
    int readPnt = roundToInt(mWritePnt - (mSampleRate * timeMS / 1000.0));
    if (readPnt < 0)
        readPnt += mDelayLine.getNumSamples();

    return readPnt;
}
