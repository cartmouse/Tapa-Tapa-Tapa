/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "TapatapatapaAudioProcessor.h"
#include "TapatapatapaAudioProcessorEditor.h"

//==============================================================================
TapatapatapaAudioProcessorEditor::TapatapatapaAudioProcessorEditor (TapatapatapaAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState (vts)
{
    // ========== Feedback ==========
    // Slider
    addAndMakeVisible(mFeedbackSlider);
    feedbackAttachment.reset(new SliderAttachment(valueTreeState, "feedback", mFeedbackSlider));

    // Label
    addAndMakeVisible(mFeedbackLabel);
    mFeedbackLabel.setText("Feedback", dontSendNotification);
    mFeedbackLabel.setJustificationType(Justification::centred);

    // ========== Time ==========
    // Slider
    addAndMakeVisible(mTimeSlider);
    mTimeSlider.setTextValueSuffix(" ms");
    timeAttachment.reset(new SliderAttachment(valueTreeState, "time", mTimeSlider));

    // Label
    addAndMakeVisible(mTimeLabel);
    mTimeLabel.setText("Time", dontSendNotification);
    mTimeLabel.setJustificationType(Justification::centred);

    // ========== Tap ==========
    // Slider
    addAndMakeVisible(mTapSlider);
    tapAttachment.reset(new SliderAttachment(valueTreeState, "tap", mTapSlider));

    // Label
    addAndMakeVisible(mTapLabel);
    mTapLabel.setText("Tap", dontSendNotification);
    mTapLabel.setJustificationType(Justification::centred);

    // ========== Cutoff ==========
    // Slider
    addAndMakeVisible(mCutoffSlider);
    mCutoffSlider.setTextValueSuffix(" Hz");
    cutoffAttachment.reset(new SliderAttachment(valueTreeState, "cutoff", mCutoffSlider));

    // Label
    addAndMakeVisible(mCutoffLabel);
    mCutoffLabel.setText("Cutoff", dontSendNotification);
    mCutoffLabel.setJustificationType(Justification::centred);

    // ========== Tap Mix ==========
    // Slider
    addAndMakeVisible(mTapMixSlider);
    tapMixAttachment.reset(new SliderAttachment(valueTreeState, "tapMix", mTapMixSlider));

    // Label
    addAndMakeVisible(mTapMixLabel);
    mTapMixLabel.setText("Tap Mix", dontSendNotification);
    mTapMixLabel.setJustificationType(Justification::centred);

    // ========== Wet Dry ==========
    // Slider
    addAndMakeVisible(mWetDrySlider);
    wetDryAttachment.reset(new SliderAttachment(valueTreeState, "wetDry", mWetDrySlider));

    // Label
    addAndMakeVisible(mWetDryLabel);
    mWetDryLabel.setText("Wet Dry", dontSendNotification);
    mWetDryLabel.setJustificationType(Justification::centred);

    // ========== Other ==========
    
    setLookAndFeel(&newLookAndFeel);

    setSize (800, 500);
}

TapatapatapaAudioProcessorEditor::~TapatapatapaAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

//==============================================================================
void TapatapatapaAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void TapatapatapaAudioProcessorEditor::resized()
{
    auto winHeight = getLocalBounds().getHeight();
    auto winWidth = getLocalBounds().getWidth();

    auto dialBox = getLocalBounds();
    dialBox.removeFromTop(winHeight * 0.1);
    dialBox.removeFromBottom(winHeight * 0.1);
    dialBox.removeFromLeft(winWidth * 0.05);
    dialBox.removeFromRight(winWidth * 0.05);

    auto labelBox = dialBox;
    labelBox.removeFromBottom(dialBox.getHeight() * 0.9);

    const auto width = dialBox.getWidth() / 6;
    mFeedbackSlider.setBounds(dialBox.removeFromLeft(width));
    mFeedbackLabel.setBounds(labelBox.removeFromLeft(width));

    mTimeSlider.setBounds(dialBox.removeFromLeft(width));
    mTimeLabel.setBounds(labelBox.removeFromLeft(width));

    mTapSlider.setBounds(dialBox.removeFromLeft(width));
    mTapLabel.setBounds(labelBox.removeFromLeft(width));

    mCutoffSlider.setBounds(dialBox.removeFromLeft(width));
    mCutoffLabel.setBounds(labelBox.removeFromLeft(width));

    mTapMixSlider.setBounds(dialBox.removeFromLeft(width));
    mTapMixLabel.setBounds(labelBox.removeFromLeft(width));

    mWetDrySlider.setBounds(dialBox.removeFromLeft(width));
    mWetDryLabel.setBounds(labelBox.removeFromLeft(width));
}