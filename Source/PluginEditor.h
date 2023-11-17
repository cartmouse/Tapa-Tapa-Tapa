/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
                                                                    //[/Comments]
*/
class TomCartwrightCw3AudioProcessorEditor  : public AudioProcessorEditor,
                                              public Slider::Listener
{
public:
    //==============================================================================
    TomCartwrightCw3AudioProcessorEditor (TomCartwrightCw3AudioProcessor& p);
    ~TomCartwrightCw3AudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    String LcdDisplay_3(String string);
    String LcdDisplay_4(String string);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* lcdm2n___ttf;
    static const int lcdm2n___ttfSize;
    static const char* gothic_ttf;
    static const int gothic_ttfSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TomCartwrightCw3AudioProcessor& processor;
    Font mDigital;
    Font mGothic;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> WetDry;
    std::unique_ptr<Label> WetDryLabel;
    std::unique_ptr<Slider> Feedback;
    std::unique_ptr<Label> FeedbackLabel;
    std::unique_ptr<Slider> TimeSlider;
    std::unique_ptr<Label> TotalDelayLabel;
    std::unique_ptr<Slider> TapSlider;
    std::unique_ptr<Label> TapProportionLabel;
    std::unique_ptr<Slider> Mix;
    std::unique_ptr<Label> MixLabel;
    std::unique_ptr<Label> FeedbackDisplay;
    std::unique_ptr<Label> TimeDisplay;
    std::unique_ptr<Label> TapDisplay;
    std::unique_ptr<Label> WetDryDisplay;
    std::unique_ptr<Label> MixDisplay;
    std::unique_ptr<Label> PercentLabel;
    std::unique_ptr<Label> PercentLabel2;
    std::unique_ptr<Label> MsLabel;
    std::unique_ptr<Label> DryLabel;
    std::unique_ptr<Label> WetLabel;
    std::unique_ptr<Label> NoTapLabel;
    std::unique_ptr<Label> AllTapLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TomCartwrightCw3AudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

