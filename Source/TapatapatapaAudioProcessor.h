/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class TapatapatapaAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    TapatapatapaAudioProcessor();
    ~TapatapatapaAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //==============================================================================
    void fillDelayLine(AudioBuffer<float>& buffer, int channel, bool add);
    void fillDelayLine(AudioBuffer<float>& buffer, int channel, bool add, float startGain, float endGain);
    void readDelayLine(AudioBuffer<float>& buffer, int channel, int readPnt, bool add, float startGain, float endGain);
    void filterBuffer(AudioBuffer<float>& buffer, float cutoffParam);
    int calcReadPnt(float timeMS) const;

    float mMaxDelaySeconds{ 2.0 };

private:
    //==============================================================================
    AudioProcessorValueTreeState parameters;

    std::atomic<float>* feedbackParam = nullptr;
    std::atomic<float>* timeParam = nullptr;
    std::atomic<float>* tapParam = nullptr;
    std::atomic<float>* tapMixParam = nullptr;
    std::atomic<float>* wetDryParam = nullptr;
    std::atomic<float>* cutoffParam = nullptr;

    //==============================================================================
    dsp::ProcessorDuplicator <dsp::IIR::Filter<float>, dsp::IIR::Coefficients <float>> mFilter;
    AudioBuffer<float> mDelayLine;
    AudioBuffer<float> mFeedbackBuffer;

    int mWritePnt{ 0 };
    int mReadPnt{ 0 };
    float mCutoff{ 0.0 };
    float mSampleRate{ 0.0 };

    float mPrevFeedback{ 0.0f };
    float mPrevTapMix{ 0.0f };
    float mPrevWetDry{ 0.0f };

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TapatapatapaAudioProcessor)

};
