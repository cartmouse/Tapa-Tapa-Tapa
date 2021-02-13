/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "TapatapatapaAudioProcessor.h"
#include "newLookAndFeel.h"

//==============================================================================
typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

class TapatapatapaAudioProcessorEditor : public AudioProcessorEditor
{
public:
    TapatapatapaAudioProcessorEditor (TapatapatapaAudioProcessor&, AudioProcessorValueTreeState&);
    ~TapatapatapaAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;


private:
    TapatapatapaAudioProcessor& processor;

    NewLookAndFeel newLookAndFeel;

    AudioProcessorValueTreeState& valueTreeState;

    Slider mFeedbackSlider{ Slider::RotaryHorizontalVerticalDrag, Slider::TextBoxBelow };
    Label mFeedbackLabel;
    Label mFeedbackDisplay;
    std::unique_ptr<SliderAttachment> feedbackAttachment;

    Slider mTimeSlider{ Slider::RotaryHorizontalVerticalDrag, Slider::TextBoxBelow };
    Label mTimeLabel;
    Label mTimeDisplay;
    std::unique_ptr<SliderAttachment> timeAttachment;

    Slider mTapSlider{ Slider::RotaryHorizontalVerticalDrag, Slider::TextBoxBelow };
    Label mTapLabel;
    Label mTapDisplay;
    std::unique_ptr<SliderAttachment> tapAttachment;
    
    Slider mCutoffSlider{ Slider::RotaryHorizontalVerticalDrag, Slider::TextBoxBelow };
    Label mCutoffLabel;
    Label mCutoffDisplay;
    std::unique_ptr<SliderAttachment> cutoffAttachment;

    Slider mTapMixSlider{ Slider::RotaryHorizontalVerticalDrag, Slider::TextBoxBelow };
    Label mTapMixLabel;
    Label mTapMixDisplay;
    std::unique_ptr<SliderAttachment> tapMixAttachment;

    Slider mWetDrySlider{ Slider::RotaryHorizontalVerticalDrag, Slider::TextBoxBelow };
    Label mWetDryLabel;
    Label mWetDryDisplay;
    std::unique_ptr<SliderAttachment> wetDryAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapatapatapaAudioProcessorEditor)
};
