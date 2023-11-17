/*
  ==============================================================================

    PluginProcessor.cpp
    Author:  Tom Cartwright

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TomCartwrightCw3AudioProcessor::TomCartwrightCw3AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                        .withInput ("Input",   AudioChannelSet::mono(), true)
                        .withOutput ("Output", AudioChannelSet::mono(), true)
                       )
#endif
{
}

TomCartwrightCw3AudioProcessor::~TomCartwrightCw3AudioProcessor()
{
}

//==============================================================================
const String TomCartwrightCw3AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TomCartwrightCw3AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TomCartwrightCw3AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TomCartwrightCw3AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TomCartwrightCw3AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TomCartwrightCw3AudioProcessor::getNumPrograms()
{
    return 1;
}

int TomCartwrightCw3AudioProcessor::getCurrentProgram()
{
    return 0;
}

void TomCartwrightCw3AudioProcessor::setCurrentProgram (int index)
{
}

const String TomCartwrightCw3AudioProcessor::getProgramName (int index)
{
    return {};
}

void TomCartwrightCw3AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TomCartwrightCw3AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    delay.initialise(sampleRate);
}

void TomCartwrightCw3AudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TomCartwrightCw3AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // Check for mono bus only
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TomCartwrightCw3AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    auto numSamples = buffer.getNumSamples();


    if (totalNumInputChannels == 1 && totalNumOutputChannels == 1)
    {
        const float* input = buffer.getReadPointer(0);
        float* output = buffer.getWritePointer(0);

        for (int iSample = 0; iSample < numSamples; iSample++)
        {
            output[iSample] = delay.processDelay(input[iSample]);
        }
    }
}

//==============================================================================
bool TomCartwrightCw3AudioProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor* TomCartwrightCw3AudioProcessor::createEditor()
{
    return new TomCartwrightCw3AudioProcessorEditor (*this);
}

//==============================================================================
void TomCartwrightCw3AudioProcessor::getStateInformation (MemoryBlock& destData)
{
}

void TomCartwrightCw3AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

//==============================================================================
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TomCartwrightCw3AudioProcessor();
}
