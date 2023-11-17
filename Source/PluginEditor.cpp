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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TomCartwrightCw3AudioProcessorEditor::TomCartwrightCw3AudioProcessorEditor (TomCartwrightCw3AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    WetDry.reset (new Slider ("wetDrySlider"));
    addAndMakeVisible (WetDry.get());
    WetDry->setRange (0, 1, 0.01);
    WetDry->setSliderStyle (Slider::LinearHorizontal);
    WetDry->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    WetDry->setColour (Slider::backgroundColourId, Colour (0xff858585));
    WetDry->setColour (Slider::thumbColourId, Colour (0xffd9d9d9));
    WetDry->setColour (Slider::trackColourId, Colour (0xffd9d9d9));
    WetDry->setColour (Slider::rotarySliderFillColourId, Colour (0x00606060));
    WetDry->setColour (Slider::rotarySliderOutlineColourId, Colour (0x00808080));
    WetDry->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    WetDry->addListener (this);

    WetDry->setBounds (20, 24, 316, 48);

    WetDryLabel.reset (new Label ("wetDryLabel",
                                  TRANS("DRY/WET\n")));
    addAndMakeVisible (WetDryLabel.get());
    WetDryLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    WetDryLabel->setJustificationType (Justification::centred);
    WetDryLabel->setEditable (false, false, false);
    WetDryLabel->setColour (TextEditor::textColourId, Colours::black);
    WetDryLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WetDryLabel->setBounds (32, 4, 84, 16);

    Feedback.reset (new Slider ("feedbackSlider"));
    addAndMakeVisible (Feedback.get());
    Feedback->setRange (0, 0.99, 0.01);
    Feedback->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    Feedback->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Feedback->setColour (Slider::backgroundColourId, Colour (0x00263238));
    Feedback->setColour (Slider::thumbColourId, Colour (0xffd9d9d9));
    Feedback->setColour (Slider::trackColourId, Colour (0x00606060));
    Feedback->setColour (Slider::rotarySliderFillColourId, Colour (0xffd9d9d9));
    Feedback->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff858585));
    Feedback->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Feedback->addListener (this);

    Feedback->setBounds (366, 132, 104, 96);

    FeedbackLabel.reset (new Label ("feedbackLabel",
                                    TRANS("FEEDBACK")));
    addAndMakeVisible (FeedbackLabel.get());
    FeedbackLabel->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    FeedbackLabel->setJustificationType (Justification::centred);
    FeedbackLabel->setEditable (false, false, false);
    FeedbackLabel->setColour (TextEditor::textColourId, Colours::black);
    FeedbackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    FeedbackLabel->setBounds (374, 4, 80, 16);

    TimeSlider.reset (new Slider ("timeSlider"));
    addAndMakeVisible (TimeSlider.get());
    TimeSlider->setRange (1, 3000, 1);
    TimeSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    TimeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    TimeSlider->setColour (Slider::backgroundColourId, Colour (0x00263238));
    TimeSlider->setColour (Slider::thumbColourId, Colour (0xffd9d9d9));
    TimeSlider->setColour (Slider::trackColourId, Colour (0x00606060));
    TimeSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffd9d9d9));
    TimeSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff858585));
    TimeSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    TimeSlider->addListener (this);

    TimeSlider->setBounds (506, 132, 104, 96);

    TotalDelayLabel.reset (new Label ("totalDelayLabel",
                                      TRANS("TIME")));
    addAndMakeVisible (TotalDelayLabel.get());
    TotalDelayLabel->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    TotalDelayLabel->setJustificationType (Justification::centred);
    TotalDelayLabel->setEditable (false, false, false);
    TotalDelayLabel->setColour (TextEditor::textColourId, Colours::black);
    TotalDelayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    TotalDelayLabel->setBounds (514, 4, 44, 16);

    TapSlider.reset (new Slider ("tapSlider"));
    addAndMakeVisible (TapSlider.get());
    TapSlider->setRange (0, 1, 0.01);
    TapSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    TapSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    TapSlider->setColour (Slider::backgroundColourId, Colour (0x00263238));
    TapSlider->setColour (Slider::thumbColourId, Colour (0xffd9d9d9));
    TapSlider->setColour (Slider::trackColourId, Colour (0x00606060));
    TapSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffd9d9d9));
    TapSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff858585));
    TapSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    TapSlider->addListener (this);

    TapSlider->setBounds (646, 132, 104, 96);

    TapProportionLabel.reset (new Label ("tapProportionLabel",
                                         TRANS("TAP")));
    addAndMakeVisible (TapProportionLabel.get());
    TapProportionLabel->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    TapProportionLabel->setJustificationType (Justification::centred);
    TapProportionLabel->setEditable (false, false, false);
    TapProportionLabel->setColour (TextEditor::textColourId, Colours::black);
    TapProportionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    TapProportionLabel->setBounds (654, 4, 35, 16);

    Mix.reset (new Slider ("mixSlider"));
    addAndMakeVisible (Mix.get());
    Mix->setRange (0, 1, 0.01);
    Mix->setSliderStyle (Slider::LinearHorizontal);
    Mix->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Mix->setColour (Slider::backgroundColourId, Colour (0xff858585));
    Mix->setColour (Slider::thumbColourId, Colour (0xffd9d9d9));
    Mix->setColour (Slider::trackColourId, Colour (0xffd9d9d9));
    Mix->setColour (Slider::rotarySliderFillColourId, Colour (0x00606060));
    Mix->setColour (Slider::rotarySliderOutlineColourId, Colour (0x00808080));
    Mix->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Mix->addListener (this);

    Mix->setBounds (20, 140, 316, 48);

    MixLabel.reset (new Label ("mixLabel",
                               TRANS("TAP MIX")));
    addAndMakeVisible (MixLabel.get());
    MixLabel->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    MixLabel->setJustificationType (Justification::centred);
    MixLabel->setEditable (false, false, false);
    MixLabel->setColour (TextEditor::textColourId, Colours::black);
    MixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    MixLabel->setBounds (32, 120, 72, 16);

    FeedbackDisplay.reset (new Label ("feedbackDisplay",
                                      TRANS("000")));
    addAndMakeVisible (FeedbackDisplay.get());
    FeedbackDisplay->setFont (Font (Font::getDefaultMonospacedFontName(), 40.00f, Font::plain).withTypefaceStyle ("Regular"));
    FeedbackDisplay->setJustificationType (Justification::centred);
    FeedbackDisplay->setEditable (false, false, false);
    FeedbackDisplay->setColour (Label::backgroundColourId, Colours::black);
    FeedbackDisplay->setColour (Label::textColourId, Colours::red);
    FeedbackDisplay->setColour (Label::outlineColourId, Colour (0x00808080));
    FeedbackDisplay->setColour (TextEditor::textColourId, Colours::black);
    FeedbackDisplay->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    TimeDisplay.reset (new Label ("timeDisplay",
                                  TRANS("0000")));
    addAndMakeVisible (TimeDisplay.get());
    TimeDisplay->setFont (Font (Font::getDefaultMonospacedFontName(), 40.00f, Font::plain).withTypefaceStyle ("Regular"));
    TimeDisplay->setJustificationType (Justification::centred);
    TimeDisplay->setEditable (false, false, false);
    TimeDisplay->setColour (Label::backgroundColourId, Colours::black);
    TimeDisplay->setColour (Label::textColourId, Colours::red);
    TimeDisplay->setColour (Label::outlineColourId, Colour (0x00808080));
    TimeDisplay->setColour (TextEditor::textColourId, Colours::black);
    TimeDisplay->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    TapDisplay.reset (new Label ("tapDisplay",
                                 TRANS("000")));
    addAndMakeVisible (TapDisplay.get());
    TapDisplay->setFont (Font (Font::getDefaultMonospacedFontName(), 40.00f, Font::plain).withTypefaceStyle ("Regular"));
    TapDisplay->setJustificationType (Justification::centred);
    TapDisplay->setEditable (false, false, false);
    TapDisplay->setColour (Label::backgroundColourId, Colours::black);
    TapDisplay->setColour (Label::textColourId, Colours::red);
    TapDisplay->setColour (Label::outlineColourId, Colour (0x00808080));
    TapDisplay->setColour (TextEditor::textColourId, Colours::black);
    TapDisplay->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WetDryDisplay.reset (new Label ("wetDryDisplay",
                                    TRANS("000\n")));
    addAndMakeVisible (WetDryDisplay.get());
    WetDryDisplay->setFont (Font (Font::getDefaultMonospacedFontName(), 40.00f, Font::plain).withTypefaceStyle ("Regular"));
    WetDryDisplay->setJustificationType (Justification::centred);
    WetDryDisplay->setEditable (false, false, false);
    WetDryDisplay->setColour (Label::backgroundColourId, Colours::black);
    WetDryDisplay->setColour (Label::textColourId, Colours::red);
    WetDryDisplay->setColour (Label::outlineColourId, Colour (0x00808080));
    WetDryDisplay->setColour (TextEditor::textColourId, Colours::black);
    WetDryDisplay->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    MixDisplay.reset (new Label ("mixDisplay",
                                 TRANS("000")));
    addAndMakeVisible (MixDisplay.get());
    MixDisplay->setFont (Font (Font::getDefaultMonospacedFontName(), 40.00f, Font::plain).withTypefaceStyle ("Regular"));
    MixDisplay->setJustificationType (Justification::centred);
    MixDisplay->setEditable (false, false, false);
    MixDisplay->setColour (Label::backgroundColourId, Colours::black);
    MixDisplay->setColour (Label::textColourId, Colours::red);
    MixDisplay->setColour (Label::outlineColourId, Colour (0x00808080));
    MixDisplay->setColour (TextEditor::textColourId, Colours::black);
    MixDisplay->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PercentLabel.reset (new Label ("percentLabel",
                                   TRANS("%")));
    addAndMakeVisible (PercentLabel.get());
    PercentLabel->setFont (Font (30.00f, Font::plain).withTypefaceStyle ("Regular"));
    PercentLabel->setJustificationType (Justification::centred);
    PercentLabel->setEditable (false, false, false);
    PercentLabel->setColour (TextEditor::textColourId, Colours::black);
    PercentLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PercentLabel2.reset (new Label ("percentLabel",
                                    TRANS("%")));
    addAndMakeVisible (PercentLabel2.get());
    PercentLabel2->setFont (Font (30.00f, Font::plain).withTypefaceStyle ("Regular"));
    PercentLabel2->setJustificationType (Justification::centred);
    PercentLabel2->setEditable (false, false, false);
    PercentLabel2->setColour (TextEditor::textColourId, Colours::black);
    PercentLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    MsLabel.reset (new Label ("msLabel",
                              TRANS("ms")));
    addAndMakeVisible (MsLabel.get());
    MsLabel->setFont (Font (30.00f, Font::plain).withTypefaceStyle ("Regular"));
    MsLabel->setJustificationType (Justification::centred);
    MsLabel->setEditable (false, false, false);
    MsLabel->setColour (TextEditor::textColourId, Colours::black);
    MsLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    DryLabel.reset (new Label ("dryLabel",
                               TRANS("DRY")));
    addAndMakeVisible (DryLabel.get());
    DryLabel->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    DryLabel->setJustificationType (Justification::centred);
    DryLabel->setEditable (false, false, false);
    DryLabel->setColour (TextEditor::textColourId, Colours::black);
    DryLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WetLabel.reset (new Label ("wetLabel",
                               TRANS("WET")));
    addAndMakeVisible (WetLabel.get());
    WetLabel->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    WetLabel->setJustificationType (Justification::centred);
    WetLabel->setEditable (false, false, false);
    WetLabel->setColour (TextEditor::textColourId, Colours::black);
    WetLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    NoTapLabel.reset (new Label ("noTapLabel",
                                 TRANS("NO TAP")));
    addAndMakeVisible (NoTapLabel.get());
    NoTapLabel->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    NoTapLabel->setJustificationType (Justification::centred);
    NoTapLabel->setEditable (false, false, false);
    NoTapLabel->setColour (TextEditor::textColourId, Colours::black);
    NoTapLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    AllTapLabel.reset (new Label ("allTapLabel",
                                  TRANS("ALL TAP")));
    addAndMakeVisible (AllTapLabel.get());
    AllTapLabel->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    AllTapLabel->setJustificationType (Justification::centred);
    AllTapLabel->setEditable (false, false, false);
    AllTapLabel->setColour (TextEditor::textColourId, Colours::black);
    AllTapLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (780, 252);


    //[Constructor] You can add your own custom stuff here..
    // Set the range of the total time dial in line with the defined max delay
    TimeSlider->setRange(1.0, processor.delay.getMaxDelay(), 1.0);

    // Set default values of the sliders and dials
    WetDry->setValue( processor.delay.getWetDry() );
    Feedback->setValue( processor.delay.getFeedback() );
    TimeSlider->setValue( processor.delay.getDelayTime() );
    TapSlider->setValue( processor.delay.getTapProportion() );
    Mix->setValue( processor.delay.getMix() );

    // Set font for labels
    mGothic = Font(Typeface::createSystemTypefaceFor(gothic_ttf, gothic_ttfSize));
    mGothic.setHeight(20.0f);

    WetDryLabel->setFont(mGothic);
    WetLabel->setFont(mGothic);
    DryLabel->setFont(mGothic);
    MixLabel->setFont(mGothic);
    AllTapLabel->setFont(mGothic);
    NoTapLabel->setFont(mGothic);
    FeedbackLabel->setFont(mGothic);
    TotalDelayLabel->setFont(mGothic);
    TapProportionLabel->setFont(mGothic);

    mGothic.setHeight(30.0f);
    MsLabel->setFont(mGothic);

    // Set font for LCD style displays
    mDigital = Font( Typeface::createSystemTypefaceFor(lcdm2n___ttf, lcdm2n___ttfSize) );
    mDigital.setHeight(35.0f);

    WetDryDisplay->setFont(mDigital);
    MixDisplay->setFont(mDigital);
    FeedbackDisplay->setFont(mDigital);
    TimeDisplay->setFont(mDigital);
    TapDisplay->setFont(mDigital);
    //[/Constructor]
}

TomCartwrightCw3AudioProcessorEditor::~TomCartwrightCw3AudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    WetDry = nullptr;
    WetDryLabel = nullptr;
    Feedback = nullptr;
    FeedbackLabel = nullptr;
    TimeSlider = nullptr;
    TotalDelayLabel = nullptr;
    TapSlider = nullptr;
    TapProportionLabel = nullptr;
    Mix = nullptr;
    MixLabel = nullptr;
    FeedbackDisplay = nullptr;
    TimeDisplay = nullptr;
    TapDisplay = nullptr;
    WetDryDisplay = nullptr;
    MixDisplay = nullptr;
    PercentLabel = nullptr;
    PercentLabel2 = nullptr;
    MsLabel = nullptr;
    DryLabel = nullptr;
    WetLabel = nullptr;
    NoTapLabel = nullptr;
    AllTapLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    setLookAndFeel(nullptr);
    //[/Destructor]
}

//==============================================================================
void TomCartwrightCw3AudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff262626));

    {
        float x = 489.0f, y = 10.0f, width = 140.0f, height = 233.0f;
        Colour strokeColour = Colour (0xffd9d9d9);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 3.000f);
    }

    {
        float x = 629.0f, y = 10.0f, width = 140.0f, height = 233.0f;
        Colour strokeColour = Colour (0xffd9d9d9);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 3.000f);
    }

    {
        int x = 514, y = 8, width = 44, height = 8;
        Colour fillColour = Colour (0xff262626);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 654, y = 8, width = 36, height = 8;
        Colour fillColour = Colour (0xff262626);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        float x = 348.0f, y = 10.0f, width = 140.0f, height = 232.0f;
        Colour strokeColour = Colour (0xffd9d9d9);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 3.000f);
    }

    {
        int x = 374, y = 8, width = 80, height = 8;
        Colour fillColour = Colour (0xff262626);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        float x = 6.0f, y = 10.0f, width = 342.0f, height = 116.0f;
        Colour strokeColour = Colour (0xffd9d9d9);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 3.000f);
    }

    {
        int x = 32, y = 8, width = 84, height = 8;
        Colour fillColour = Colour (0xff262626);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        float x = 6.0f, y = 126.0f, width = 342.0f, height = 116.0f;
        Colour strokeColour = Colour (0xffd9d9d9);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 3.000f);
    }

    {
        int x = 32, y = 120, width = 72, height = 12;
        Colour fillColour = Colour (0xff262626);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TomCartwrightCw3AudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    FeedbackDisplay->setBounds (366 + 104 / 2 + 2 - (112 / 2), 132 + -40 - (48 / 2), 112, 48);
    TimeDisplay->setBounds (506 + 104 / 2 + 2 - (112 / 2), 132 + -40 - (48 / 2), 112, 48);
    TapDisplay->setBounds (646 + 104 / 2 + 2 - (112 / 2), 132 + -40 - (48 / 2), 112, 48);
    WetDryDisplay->setBounds (20 + 316 / 2 - (112 / 2), 24 + 48 - 8, 112, 44);
    MixDisplay->setBounds (20 + 316 / 2 - (112 / 2), 140 + 48 - 8, 112, 44);
    PercentLabel->setBounds (366 + 104 / 2 - (32 / 2), 132 + 96 / 2 + -140 - (32 / 2), 32, 32);
    PercentLabel2->setBounds (646 + 104 / 2 + 2 - (32 / 2), 132 + 96 / 2 + -140 - (32 / 2), 32, 32);
    MsLabel->setBounds (506 + 104 / 2 - (44 / 2), 132 + 96 / 2 + -140 - (24 / 2), 44, 24);
    DryLabel->setBounds (20 + 0, 24 + 48 - 4, 44, 16);
    WetLabel->setBounds (20 + 316 - 44, 24 + 48 - 4, 44, 16);
    NoTapLabel->setBounds (20 + 0, 140 + 48 - 4, 64, 16);
    AllTapLabel->setBounds (20 + 316 - 64, 140 + 48 - 4, 64, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TomCartwrightCw3AudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == WetDry.get())
    {
        //[UserSliderCode_WetDry] -- add your slider handling code here..
        auto wetDry = (float)WetDry->getValue();
        processor.delay.setWetDry(wetDry);

        String wetDryString = LcdDisplay_3(String(wetDry * 100));

        WetDryDisplay->setText(wetDryString, NotificationType::dontSendNotification);
        //[/UserSliderCode_WetDry]
    }
    else if (sliderThatWasMoved == Feedback.get())
    {
        //[UserSliderCode_Feedback] -- add your slider handling code here..
        auto feedback = (float)Feedback->getValue();
        processor.delay.setFeedback(feedback);

        String feedbackString = LcdDisplay_3(String(feedback * 100));

        FeedbackDisplay->setText(feedbackString, NotificationType::dontSendNotification);
        //[/UserSliderCode_Feedback]
    }
    else if (sliderThatWasMoved == TimeSlider.get())
    {
        //[UserSliderCode_TimeSlider] -- add your slider handling code here..
        auto time = (float)TimeSlider->getValue();
        processor.delay.setDelayTime(time);

        String newString = LcdDisplay_4(String(time));

        TimeDisplay->setText(newString, NotificationType::dontSendNotification);
        //[/UserSliderCode_TimeSlider]
    }
    else if (sliderThatWasMoved == TapSlider.get())
    {
        //[UserSliderCode_TapSlider] -- add your slider handling code here..
        auto tap = (float)TapSlider->getValue();
        processor.delay.setTapProportion(tap);

        String tapString = LcdDisplay_3(String(tap * 100));

        TapDisplay->setText(tapString, NotificationType::dontSendNotification);
        //[/UserSliderCode_TapSlider]
    }
    else if (sliderThatWasMoved == Mix.get())
    {
        //[UserSliderCode_Mix] -- add your slider handling code here..
        auto mix = (float)Mix->getValue();
        processor.delay.setTapMix(mix);

        String mixString = LcdDisplay_3(String(mix * 100));

        MixDisplay->setText(mixString, NotificationType::dontSendNotification);
        //[/UserSliderCode_Mix]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

String TomCartwrightCw3AudioProcessorEditor::LcdDisplay_3(String string)
{
    String zero = String(0);

    String newString;

    auto stringLength = string.length();
    if (stringLength == 3)
    {
        newString = string;
    }
    if (stringLength == 2)
    {
        newString.append(zero, 3);
        newString.append(string, 3);
    }
    if (stringLength == 1)
    {
        newString.append(zero, 3);
        newString.append(zero, 3);
        newString.append(string, 3);
    }

    return newString;
}

String TomCartwrightCw3AudioProcessorEditor::LcdDisplay_4(String string)
{
    String zero = String(0);
    String newString;
    auto stringLength = string.length();

    if (stringLength == 4)
    {
        newString = string;
    }
    if (stringLength == 3)
    {
        newString.append(zero, 3);
        newString.append(string, 3);
    }
    if (stringLength == 2)
    {
        newString.append(zero, 3);
        newString.append(zero, 3);
        newString.append(string, 3);
    }
    if (stringLength == 1)
    {
        newString.append(zero, 3);
        newString.append(zero, 3);
        newString.append(zero, 3);
        newString.append(string, 3);
    }

    return newString;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TomCartwrightCw3AudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="TomCartwrightCw3AudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="780" initialHeight="252">
  <BACKGROUND backgroundColour="ff262626">
    <ROUNDRECT pos="489 10 140 233" cornerSize="10.0" fill="solid: 2a66a5" hasStroke="1"
               stroke="3, mitered, butt" strokeColour="solid: ffd9d9d9"/>
    <ROUNDRECT pos="629 10 140 233" cornerSize="10.0" fill="solid: 2a66a5" hasStroke="1"
               stroke="3, mitered, butt" strokeColour="solid: ffd9d9d9"/>
    <RECT pos="514 8 44 8" fill="solid: ff262626" hasStroke="0"/>
    <RECT pos="654 8 36 8" fill="solid: ff262626" hasStroke="0"/>
    <ROUNDRECT pos="348 10 140 232" cornerSize="10.0" fill="solid: 2a66a5" hasStroke="1"
               stroke="3, mitered, butt" strokeColour="solid: ffd9d9d9"/>
    <RECT pos="374 8 80 8" fill="solid: ff262626" hasStroke="0"/>
    <ROUNDRECT pos="6 10 342 116" cornerSize="10.0" fill="solid: 2a66a5" hasStroke="1"
               stroke="3, mitered, butt" strokeColour="solid: ffd9d9d9"/>
    <RECT pos="32 8 84 8" fill="solid: ff262626" hasStroke="0"/>
    <ROUNDRECT pos="6 126 342 116" cornerSize="10.0" fill="solid: 2a66a5" hasStroke="1"
               stroke="3, mitered, butt" strokeColour="solid: ffd9d9d9"/>
    <RECT pos="32 120 72 12" fill="solid: ff262626" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="wetDrySlider" id="d91121836ccadf15" memberName="WetDry"
          virtualName="" explicitFocusOrder="0" pos="20 24 316 48" bkgcol="ff858585"
          thumbcol="ffd9d9d9" trackcol="ffd9d9d9" rotarysliderfill="606060"
          rotaryslideroutline="808080" textboxoutline="8e989b" min="0.0"
          max="1.0" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="wetDryLabel" id="258ffa9491a574d" memberName="WetDryLabel"
         virtualName="" explicitFocusOrder="0" pos="32 4 84 16" edTextCol="ff000000"
         edBkgCol="0" labelText="DRY/WET&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="feedbackSlider" id="857cf75bc1409bed" memberName="Feedback"
          virtualName="" explicitFocusOrder="0" pos="366 132 104 96" bkgcol="263238"
          thumbcol="ffd9d9d9" trackcol="606060" rotarysliderfill="ffd9d9d9"
          rotaryslideroutline="ff858585" textboxoutline="8e989b" min="0.0"
          max="0.99" int="0.01" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="feedbackLabel" id="f9377d4ae95ac6f3" memberName="FeedbackLabel"
         virtualName="" explicitFocusOrder="0" pos="374 4 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="FEEDBACK" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="timeSlider" id="789c775e03aed9d6" memberName="TimeSlider"
          virtualName="" explicitFocusOrder="0" pos="506 132 104 96" bkgcol="263238"
          thumbcol="ffd9d9d9" trackcol="606060" rotarysliderfill="ffd9d9d9"
          rotaryslideroutline="ff858585" textboxoutline="8e989b" min="1.0"
          max="3000.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="totalDelayLabel" id="efb5708361d629ef" memberName="TotalDelayLabel"
         virtualName="" explicitFocusOrder="0" pos="514 4 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TIME" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="tapSlider" id="6ca02ae590d61171" memberName="TapSlider"
          virtualName="" explicitFocusOrder="0" pos="646 132 104 96" bkgcol="263238"
          thumbcol="ffd9d9d9" trackcol="606060" rotarysliderfill="ffd9d9d9"
          rotaryslideroutline="ff858585" textboxoutline="8e989b" min="0.0"
          max="1.0" int="0.01" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="tapProportionLabel" id="f66ddbeeae7842c9" memberName="TapProportionLabel"
         virtualName="" explicitFocusOrder="0" pos="654 4 35 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TAP" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="mixSlider" id="5723846340759291" memberName="Mix" virtualName=""
          explicitFocusOrder="0" pos="20 140 316 48" bkgcol="ff858585"
          thumbcol="ffd9d9d9" trackcol="ffd9d9d9" rotarysliderfill="606060"
          rotaryslideroutline="808080" textboxoutline="8e989b" min="0.0"
          max="1.0" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="mixLabel" id="492ad46bec17d783" memberName="MixLabel" virtualName=""
         explicitFocusOrder="0" pos="32 120 72 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TAP MIX" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="feedbackDisplay" id="5833c4418bd16ccc" memberName="FeedbackDisplay"
         virtualName="" explicitFocusOrder="0" pos="2Cc -40c 112 48" posRelativeX="857cf75bc1409bed"
         posRelativeY="857cf75bc1409bed" bkgCol="ff000000" textCol="ffff0000"
         outlineCol="808080" edTextCol="ff000000" edBkgCol="0" labelText="000"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="40.0" kerning="0.0"
         bold="0" italic="0" justification="36"/>
  <LABEL name="timeDisplay" id="f9ab36fa3a3f6e3e" memberName="TimeDisplay"
         virtualName="" explicitFocusOrder="0" pos="2Cc -40c 112 48" posRelativeX="789c775e03aed9d6"
         posRelativeY="789c775e03aed9d6" bkgCol="ff000000" textCol="ffff0000"
         outlineCol="808080" edTextCol="ff000000" edBkgCol="0" labelText="0000"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="40.0" kerning="0.0"
         bold="0" italic="0" justification="36"/>
  <LABEL name="tapDisplay" id="bb5ceab9d17ae210" memberName="TapDisplay"
         virtualName="" explicitFocusOrder="0" pos="2Cc -40c 112 48" posRelativeX="6ca02ae590d61171"
         posRelativeY="6ca02ae590d61171" bkgCol="ff000000" textCol="ffff0000"
         outlineCol="808080" edTextCol="ff000000" edBkgCol="0" labelText="000"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="40.0" kerning="0.0"
         bold="0" italic="0" justification="36"/>
  <LABEL name="wetDryDisplay" id="faf01fdaadfd7f1" memberName="WetDryDisplay"
         virtualName="" explicitFocusOrder="0" pos="0Cc 8R 112 44" posRelativeX="d91121836ccadf15"
         posRelativeY="d91121836ccadf15" bkgCol="ff000000" textCol="ffff0000"
         outlineCol="808080" edTextCol="ff000000" edBkgCol="0" labelText="000&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="40.0" kerning="0.0"
         bold="0" italic="0" justification="36"/>
  <LABEL name="mixDisplay" id="f58b5941367d3fa" memberName="MixDisplay"
         virtualName="" explicitFocusOrder="0" pos="0Cc 8R 112 44" posRelativeX="5723846340759291"
         posRelativeY="5723846340759291" bkgCol="ff000000" textCol="ffff0000"
         outlineCol="808080" edTextCol="ff000000" edBkgCol="0" labelText="000"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="40.0" kerning="0.0"
         bold="0" italic="0" justification="36"/>
  <LABEL name="percentLabel" id="30aec37e5dc55a5" memberName="PercentLabel"
         virtualName="" explicitFocusOrder="0" pos="0Cc -140Cc 32 32"
         posRelativeX="857cf75bc1409bed" posRelativeY="857cf75bc1409bed"
         edTextCol="ff000000" edBkgCol="0" labelText="%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="30.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="percentLabel" id="3baadd2f1767c487" memberName="PercentLabel2"
         virtualName="" explicitFocusOrder="0" pos="2Cc -140Cc 32 32"
         posRelativeX="6ca02ae590d61171" posRelativeY="6ca02ae590d61171"
         edTextCol="ff000000" edBkgCol="0" labelText="%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="30.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="msLabel" id="d54e3fc60b425250" memberName="MsLabel" virtualName=""
         explicitFocusOrder="0" pos="0Cc -140Cc 44 24" posRelativeX="789c775e03aed9d6"
         posRelativeY="6ca02ae590d61171" edTextCol="ff000000" edBkgCol="0"
         labelText="ms" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="30.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="dryLabel" id="c5761c9956c40eb5" memberName="DryLabel" virtualName=""
         explicitFocusOrder="0" pos="0 4R 44 16" posRelativeX="d91121836ccadf15"
         posRelativeY="d91121836ccadf15" edTextCol="ff000000" edBkgCol="0"
         labelText="DRY" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="wetLabel" id="7d678eb6420fdb99" memberName="WetLabel" virtualName=""
         explicitFocusOrder="0" pos="0Rr 4R 44 16" posRelativeX="d91121836ccadf15"
         posRelativeY="d91121836ccadf15" edTextCol="ff000000" edBkgCol="0"
         labelText="WET" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="noTapLabel" id="f2c5bb69fad7076d" memberName="NoTapLabel"
         virtualName="" explicitFocusOrder="0" pos="0 4R 64 16" posRelativeX="5723846340759291"
         posRelativeY="5723846340759291" edTextCol="ff000000" edBkgCol="0"
         labelText="NO TAP" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="allTapLabel" id="c870a1b5ad33d270" memberName="AllTapLabel"
         virtualName="" explicitFocusOrder="0" pos="0Rr 4R 64 16" posRelativeX="5723846340759291"
         posRelativeY="5723846340759291" edTextCol="ff000000" edBkgCol="0"
         labelText="ALL TAP" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: lcdm2n___ttf, 27480, "../Fonts/LCDM2N__.TTF"
static const unsigned char resource_TomCartwrightCw3AudioProcessorEditor_lcdm2n___ttf[] = { 0,1,0,0,0,14,0,48,0,3,0,176,79,83,47,50,129,250,111,244,0,0,106,140,0,0,0,78,99,109,97,112,21,80,71,96,0,0,98,
136,0,0,2,60,99,118,116,32,245,27,90,50,0,0,4,24,0,0,0,40,102,112,103,109,131,51,194,79,0,0,4,4,0,0,0,20,103,108,121,102,54,105,41,241,0,0,4,108,0,0,90,110,104,100,109,120,196,68,68,28,0,0,100,196,0,0,
5,200,104,101,97,100,13,121,6,141,0,0,106,220,0,0,0,54,104,104,101,97,5,75,1,135,0,0,107,20,0,0,0,36,104,109,116,120,179,51,14,4,0,0,96,72,0,0,1,104,108,111,99,97,0,15,51,246,0,0,94,220,0,0,1,108,109,
97,120,112,0,252,1,136,0,0,107,56,0,0,0,32,110,97,109,101,221,189,195,224,0,0,0,236,0,0,3,21,112,111,115,116,8,197,8,135,0,0,97,176,0,0,0,214,112,114,101,112,161,251,91,153,0,0,4,64,0,0,0,44,0,0,0,21,
1,2,0,0,0,0,0,0,0,0,0,114,0,57,0,0,0,0,0,0,0,1,0,16,0,179,0,0,0,0,0,0,0,2,0,12,0,201,0,0,0,0,0,0,0,3,0,82,1,43,0,0,0,0,0,0,0,4,0,30,0,228,0,0,0,0,0,0,0,5,0,72,1,161,0,0,0,0,0,0,0,6,0,28,1,247,0,1,0,0,
0,0,0,0,0,57,0,0,0,1,0,0,0,0,0,1,0,8,0,171,0,1,0,0,0,0,0,2,0,6,0,195,0,1,0,0,0,0,0,3,0,41,1,2,0,1,0,0,0,0,0,4,0,15,0,213,0,1,0,0,0,0,0,5,0,36,1,125,0,1,0,0,0,0,0,6,0,14,1,233,0,3,0,1,4,9,0,0,0,114,0,57,
0,3,0,1,4,9,0,1,0,16,0,179,0,3,0,1,4,9,0,2,0,12,0,201,0,3,0,1,4,9,0,3,0,82,1,43,0,3,0,1,4,9,0,4,0,30,0,228,0,3,0,1,4,9,0,5,0,72,1,161,0,3,0,1,4,9,0,6,0,28,1,247,67,111,112,121,114,105,103,104,116,32,169,
32,49,57,57,57,32,98,121,32,83,97,109,117,101,108,32,82,101,121,110,111,108,100,115,46,32,65,108,108,32,114,105,103,104,116,115,32,114,101,115,101,114,118,101,100,46,0,67,0,111,0,112,0,121,0,114,0,105,
0,103,0,104,0,116,0,32,0,169,0,32,0,49,0,57,0,57,0,57,0,32,0,98,0,121,0,32,0,83,0,97,0,109,0,117,0,101,0,108,0,32,0,82,0,101,0,121,0,110,0,111,0,108,0,100,0,115,0,46,0,32,0,65,0,108,0,108,0,32,0,114,0,
105,0,103,0,104,0,116,0,115,0,32,0,114,0,101,0,115,0,101,0,114,0,118,0,101,0,100,0,46,76,67,68,77,111,110,111,50,0,76,0,67,0,68,0,77,0,111,0,110,0,111,0,50,78,111,114,109,97,108,0,78,0,111,0,114,0,109,
0,97,0,108,76,67,68,77,111,110,111,50,32,78,111,114,109,97,108,0,76,0,67,0,68,0,77,0,111,0,110,0,111,0,50,0,32,0,78,0,111,0,114,0,109,0,97,0,108,65,108,116,115,121,115,32,70,111,110,116,111,103,114,97,
112,104,101,114,32,52,46,48,46,52,32,76,67,68,77,111,110,111,50,32,78,111,114,109,97,108,0,65,0,108,0,116,0,115,0,121,0,115,0,32,0,70,0,111,0,110,0,116,0,111,0,103,0,114,0,97,0,112,0,104,0,101,0,114,0,
32,0,52,0,46,0,48,0,46,0,52,0,32,0,76,0,67,0,68,0,77,0,111,0,110,0,111,0,50,0,32,0,78,0,111,0,114,0,109,0,97,0,108,65,108,116,115,121,115,32,70,111,110,116,111,103,114,97,112,104,101,114,32,52,46,48,46,
52,32,49,57,57,57,47,49,48,47,51,48,0,65,0,108,0,116,0,115,0,121,0,115,0,32,0,70,0,111,0,110,0,116,0,111,0,103,0,114,0,97,0,112,0,104,0,101,0,114,0,32,0,52,0,46,0,48,0,46,0,52,0,32,0,49,0,57,0,57,0,57,
0,47,0,49,0,48,0,47,0,51,0,48,76,67,68,77,111,110,111,50,78,111,114,109,97,108,0,76,0,67,0,68,0,77,0,111,0,110,0,111,0,50,0,78,0,111,0,114,0,109,0,97,0,108,0,0,0,64,1,0,44,118,69,32,176,3,37,69,35,97,
104,24,35,104,96,68,45,0,1,3,31,0,75,0,75,0,178,0,113,0,49,90,103,18,6,210,184,106,24,248,42,97,163,14,64,238,210,128,58,39,85,162,135,0,1,0,13,64,13,6,6,5,5,4,4,3,3,1,1,0,0,1,141,184,1,255,133,69,104,
68,69,104,68,69,104,68,69,104,68,69,104,68,69,104,68,177,2,2,69,104,68,0,2,0,64,0,0,1,195,3,32,0,3,0,7,0,93,64,29,1,8,8,64,9,2,7,1,0,6,3,2,5,4,2,0,7,6,2,1,2,1,1,3,0,0,1,0,70,118,47,55,24,0,63,60,63,60,
16,253,60,16,253,60,1,47,60,185,0,5,255,255,253,60,47,60,185,0,4,255,255,253,60,0,49,48,1,73,104,185,0,0,0,8,73,104,97,176,64,82,88,56,17,55,185,0,8,255,192,56,89,51,17,33,17,37,33,17,33,64,1,131,254,
190,1,1,254,255,3,32,252,224,64,2,160,0,0,3,0,170,0,2,1,89,3,30,0,3,0,9,0,15,0,155,64,74,1,16,16,64,17,15,11,8,5,3,15,12,9,6,2,0,2,1,2,3,6,3,0,1,1,2,0,0,1,3,2,3,0,6,0,1,2,2,3,1,1,2,10,10,11,9,8,9,15,14,
15,4,3,4,5,12,11,12,7,7,8,13,13,14,6,6,13,14,1,1,0,1,2,70,118,47,55,24,0,63,63,1,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,1,46,46,46,46,46,46,
0,46,46,46,46,49,48,1,73,104,185,0,2,0,16,73,104,97,176,64,82,88,56,17,55,185,0,16,255,192,56,89,55,7,39,63,1,7,39,63,1,23,55,7,39,19,55,23,243,42,31,42,46,42,32,29,42,32,15,43,32,44,42,32,39,37,37,37,
66,37,37,206,37,37,104,37,37,1,53,37,37,0,2,0,161,2,62,1,98,2,231,0,5,0,11,0,146,64,69,1,12,12,64,13,11,11,8,5,2,2,1,2,3,4,3,4,6,6,7,11,11,6,3,2,3,4,4,4,5,7,7,8,6,6,7,5,4,5,0,3,0,1,3,3,4,2,2,3,8,7,8,9,
3,9,10,6,6,7,11,11,6,10,4,7,1,1,2,70,118,47,55,24,0,47,60,47,60,1,135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,1,46,46,46,46,0,49,48,1,73,104,185,
0,2,0,12,73,104,97,176,64,82,88,56,17,55,185,0,12,255,192,56,89,19,7,39,63,1,31,1,7,39,63,1,23,234,42,31,13,42,32,93,42,32,14,42,31,2,98,36,36,97,36,36,97,36,36,97,36,36,0,0,10,255,249,0,0,2,10,3,32,0,
5,0,14,0,20,0,26,0,32,0,38,0,47,0,53,0,59,0,65,0,0,55,7,39,63,1,23,5,7,33,39,55,51,23,55,51,55,7,39,19,55,23,39,7,35,39,55,51,15,1,35,39,55,51,39,7,39,19,55,23,37,7,35,39,7,35,39,55,33,23,7,39,63,1,23,
3,7,39,19,55,23,3,7,39,19,55,23,67,42,32,5,43,32,1,47,43,254,250,32,42,80,44,59,80,91,43,32,37,42,32,44,43,80,32,43,80,152,43,80,32,43,80,92,42,32,36,43,32,1,66,43,80,44,59,79,32,42,1,6,72,43,32,6,42,
32,220,42,32,36,42,32,87,42,32,36,42,32,89,37,37,41,38,38,93,37,37,38,52,52,14,37,37,1,3,37,37,52,37,37,37,37,37,37,37,15,37,37,1,3,37,37,52,38,52,52,38,37,130,38,38,41,37,37,254,253,37,37,1,3,37,37,253,
146,37,37,1,3,37,37,0,1,0,214,2,62,1,45,2,231,0,5,0,75,64,26,1,6,6,64,7,5,5,2,2,1,2,3,3,3,4,0,0,1,5,5,0,4,1,1,2,70,118,47,55,24,0,47,47,1,135,46,8,196,8,252,8,196,1,46,46,0,49,48,1,73,104,185,0,2,0,6,
73,104,97,176,64,82,88,56,17,55,185,0,6,255,192,56,89,1,7,39,63,1,23,1,32,42,32,13,42,32,2,98,36,36,97,36,36,0,0,4,0,124,0,0,1,135,3,32,0,5,0,11,0,17,0,23,0,222,64,107,1,24,24,64,25,0,16,15,13,10,8,7,
21,18,17,14,11,8,3,0,0,5,0,1,3,3,2,3,4,9,9,4,17,16,17,6,6,7,11,10,11,12,3,12,13,15,8,9,9,10,14,14,9,21,20,21,22,3,19,18,18,19,2,3,3,3,4,0,0,1,5,5,0,23,18,3,18,19,21,21,22,13,12,13,14,14,15,20,20,14,2,
1,2,4,23,22,2,19,20,19,0,5,4,1,1,14,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,8,196,8,196,8,196,8,252,14,196,135,46,8,196,8,252,14,196,135,46,14,196,14,252,8,196,135,46,8,196,14,196,14,
196,8,252,8,196,8,196,8,196,135,46,14,196,8,196,14,252,8,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,49,48,1,73,104,185,0,14,0,24,73,104,97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,1,7,35,39,
55,51,3,7,35,19,55,23,3,7,39,19,51,23,19,7,35,39,55,51,1,135,42,46,32,42,46,110,47,33,42,43,32,88,42,32,42,33,36,54,42,46,32,42,46,2,251,38,38,37,254,164,42,1,45,37,37,253,146,37,37,1,45,42,254,201,37,
37,38,0,0,4,0,124,0,0,1,135,3,32,0,5,0,11,0,17,0,23,0,222,64,107,1,24,24,64,25,11,17,16,13,10,7,6,21,18,17,14,11,8,3,0,0,5,0,1,3,4,3,3,4,15,15,16,8,7,8,14,13,14,9,3,9,10,17,6,12,12,13,11,11,12,21,20,21,
22,3,18,23,18,19,12,12,19,2,3,3,3,4,10,9,10,0,0,1,11,11,6,5,5,11,23,18,3,18,19,21,21,22,20,20,21,2,1,2,4,23,22,2,19,20,19,0,5,4,1,1,21,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,8,196,
8,252,14,196,135,46,8,196,8,196,8,196,8,252,14,196,135,46,14,196,8,196,14,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,14,196,14,252,8,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,
46,46,49,48,1,73,104,185,0,21,0,24,73,104,97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,1,7,35,39,55,51,19,35,39,19,55,23,3,7,39,19,55,51,3,7,35,39,55,51,1,90,42,46,32,42,46,35,33,36,37,42,32,87,43,
32,37,47,33,102,42,46,32,42,46,2,251,38,38,37,254,122,42,1,3,37,37,253,146,37,37,1,3,42,254,159,37,37,38,0,0,4,0,167,1,65,1,92,1,224,0,5,0,11,0,17,0,23,0,217,64,100,1,24,24,64,25,11,23,20,17,14,11,8,5,
2,23,0,5,18,3,3,20,20,3,15,8,14,9,3,17,12,11,11,12,9,8,9,10,3,7,6,6,7,18,23,18,19,3,22,21,21,22,1,2,3,2,3,5,5,0,4,4,5,16,17,3,17,12,14,14,15,13,13,14,8,7,1,3,0,2,3,23,22,16,3,15,2,12,11,10,4,3,3,20,19,
13,3,12,1,20,70,118,47,55,24,0,47,23,60,47,23,60,16,253,23,60,16,253,23,60,1,135,46,8,196,8,252,14,196,135,46,8,196,8,252,14,196,135,46,14,196,14,252,8,196,135,46,14,196,14,252,8,196,135,46,14,196,14,
196,14,252,14,196,14,196,14,196,135,46,14,196,14,252,14,196,14,196,14,196,1,46,46,46,46,46,46,46,46,0,49,48,1,73,104,185,0,20,0,24,73,104,97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,19,35,39,55,51,
31,1,7,35,63,1,51,7,35,39,55,51,23,15,1,35,63,1,51,249,48,18,6,49,18,85,24,48,7,24,48,22,49,18,7,48,18,93,24,48,7,24,48,1,155,20,49,21,27,21,48,21,159,21,48,21,27,21,48,21,0,4,0,101,0,239,1,158,2,49,0,
5,0,11,0,17,0,23,0,232,64,121,1,24,24,64,25,6,22,1,23,20,15,12,9,6,5,2,22,22,23,9,8,9,21,20,21,10,3,10,11,7,7,8,6,6,7,12,17,12,1,1,2,0,5,0,13,3,13,14,16,16,17,15,15,16,9,9,10,8,7,8,2,5,2,3,6,6,7,11,11,
6,12,12,13,17,16,17,23,5,23,18,15,15,16,14,14,15,2,1,2,20,19,20,3,3,3,4,23,22,23,18,18,19,5,5,18,14,13,8,3,7,2,17,16,11,3,10,4,19,1,15,70,118,47,55,24,0,47,47,47,23,60,253,23,60,1,135,46,8,196,8,196,8,
252,8,196,8,196,135,46,8,196,8,252,8,196,8,196,135,46,8,196,8,252,8,196,8,196,135,46,8,196,8,252,8,196,8,196,8,196,135,46,8,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,0,46,46,49,48,1,73,104,
185,0,15,0,24,73,104,97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,1,7,39,63,1,31,1,7,35,39,55,51,15,1,35,39,55,51,23,7,39,63,1,23,1,45,41,32,10,42,32,102,42,68,32,42,68,139,42,68,32,42,68,66,42,32,
11,41,32,1,195,36,36,73,37,37,124,37,37,37,37,37,37,37,161,37,37,73,36,36,0,1,0,212,255,222,1,47,0,115,0,4,0,94,64,37,1,5,5,64,6,4,4,1,1,0,1,2,3,2,3,0,0,1,4,4,0,0,1,3,1,2,3,3,4,2,2,3,3,1,1,1,70,118,47,
55,24,0,47,47,1,135,46,8,196,8,252,14,196,135,46,8,196,8,252,8,196,1,46,46,0,49,48,1,73,104,185,0,1,0,5,73,104,97,176,64,82,88,56,17,55,185,0,5,255,192,56,89,37,7,63,1,23,1,41,85,16,43,32,40,74,112,37,
37,0,1,0,88,1,107,1,171,1,181,0,5,0,57,64,15,1,6,6,64,7,0,3,0,5,4,2,1,1,3,70,118,47,55,24,0,47,60,47,60,1,46,46,0,49,48,1,73,104,185,0,3,0,6,73,104,97,176,64,82,88,56,17,55,185,0,6,255,192,56,89,1,7,33,
39,55,33,1,171,43,254,248,32,43,1,8,1,144,37,37,37,0,0,1,0,218,0,3,1,41,0,115,0,5,0,111,64,46,1,6,6,64,7,5,5,2,2,1,2,3,3,3,4,0,0,1,5,5,0,3,4,3,4,5,1,1,2,0,0,1,4,3,4,5,3,2,1,1,2,4,1,1,2,70,118,47,55,24,
0,47,47,1,135,46,14,196,14,252,8,196,135,46,8,196,8,252,14,196,135,46,8,196,8,252,8,196,1,46,46,0,49,48,1,73,104,185,0,2,0,6,73,104,97,176,64,82,88,56,17,55,185,0,6,255,192,56,89,37,7,39,63,1,23,1,36,
42,32,5,42,32,40,37,37,38,37,37,0,2,255,241,0,0,2,18,3,32,0,5,0,11,0,105,64,40,1,12,12,64,13,5,11,10,2,1,11,8,5,2,10,3,2,3,9,8,9,4,3,6,11,6,1,7,0,0,7,8,7,0,5,4,1,1,8,70,118,47,55,24,0,63,60,63,60,1,135,
46,14,196,14,196,8,196,14,252,8,196,8,196,14,196,1,46,46,46,46,0,46,46,46,46,49,48,1,73,104,185,0,8,0,12,73,104,97,176,64,82,88,56,17,55,185,0,12,255,192,56,89,1,3,35,55,19,51,1,3,35,55,19,51,2,9,216,
36,13,199,49,254,215,199,49,9,216,36,2,224,254,186,90,1,44,254,12,254,212,64,1,69,0,0,6,255,249,0,0,2,10,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,192,64,93,1,36,36,64,37,23,28,25,22,19,10,7,4,1,33,30,29,26,
23,20,15,12,11,8,5,2,6,6,7,5,4,5,11,10,11,0,3,0,1,8,7,8,3,3,4,9,9,10,2,2,9,27,27,28,20,19,20,26,25,26,21,3,21,22,29,28,29,18,18,19,24,24,25,23,23,24,14,13,2,16,35,34,2,31,32,31,0,17,16,1,1,2,70,118,47,
55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,
46,49,48,1,73,104,185,0,2,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,55,7,39,19,55,23,55,7,39,19,55,23,37,7,33,39,55,33,19,7,39,19,55,23,3,7,39,19,55,23,3,7,33,39,55,33,68,43,32,37,42,
32,15,43,32,37,42,32,1,66,43,254,250,32,43,1,6,40,42,32,36,43,32,88,42,32,36,43,32,96,43,254,250,32,43,1,6,89,37,37,1,3,37,37,104,37,37,1,3,37,37,52,38,38,37,254,164,37,37,1,3,37,37,253,146,37,37,1,3,
37,37,254,201,37,37,38,0,3,0,162,0,2,1,97,3,30,0,5,0,10,0,16,0,196,64,99,1,17,17,64,18,5,15,10,7,1,16,13,10,8,5,2,16,15,16,0,0,1,5,4,5,11,4,11,12,9,9,10,8,8,9,14,14,15,2,1,2,13,12,13,3,3,3,4,16,15,16,
0,0,1,11,11,12,5,5,11,6,10,6,7,3,7,8,10,10,6,3,2,3,4,4,5,9,9,4,10,9,10,6,3,6,7,9,9,10,8,8,9,12,0,4,1,1,8,70,118,47,55,24,0,63,63,1,135,46,8,196,8,252,8,196,135,46,8,196,8,196,8,196,8,252,8,196,135,46,
8,196,8,196,8,196,8,252,8,196,8,196,8,196,135,46,8,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,0,46,46,46,46,49,48,1,73,104,185,0,8,0,17,73,104,97,176,64,82,88,56,17,55,185,0,17,255,192,56,89,1,7,
39,19,55,23,15,1,39,63,1,19,7,39,19,55,23,1,54,42,32,44,42,31,117,45,29,5,84,1,42,32,44,42,31,1,195,36,36,1,54,37,37,131,39,34,37,74,253,71,37,34,1,57,36,36,0,6,255,244,0,0,2,15,3,32,0,5,0,11,0,17,0,23,
0,28,0,32,0,239,64,120,1,33,33,64,34,17,27,25,16,13,4,1,30,29,28,25,21,18,17,14,9,6,5,2,5,4,5,0,3,0,1,26,26,27,2,1,2,3,3,4,25,25,3,28,27,28,24,3,24,25,26,26,27,2,1,2,3,3,4,25,25,3,0,1,3,1,2,9,8,9,10,10,
11,3,3,10,14,13,14,15,3,15,16,12,12,13,17,17,12,1,0,1,2,3,5,4,4,5,8,7,2,10,23,22,2,20,19,32,31,2,29,30,29,0,11,10,1,1,25,70,118,47,55,24,0,63,60,63,60,16,253,60,47,60,253,60,16,253,60,1,135,46,14,196,
14,252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,8,196,8,252,14,196,135,46,8,196,8,196,8,196,8,252,8,196,135,46,8,196,8,196,8,196,8,252,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,
49,48,1,73,104,185,0,25,0,33,73,104,97,176,64,82,88,56,17,55,185,0,33,255,192,56,89,19,7,39,63,1,23,37,7,33,39,55,33,19,7,39,19,55,23,3,7,33,39,55,33,1,7,19,55,23,1,33,55,33,155,43,32,6,42,32,1,66,42,
254,249,32,43,1,6,41,43,32,36,43,32,95,42,254,248,32,43,1,7,254,185,85,47,43,32,1,47,254,100,85,1,7,2,158,38,38,41,37,37,52,38,38,37,254,164,37,37,1,3,37,37,254,201,37,37,37,254,164,74,1,79,37,37,254,
162,75,0,5,0,1,0,0,2,2,3,32,0,5,0,11,0,17,0,23,0,29,0,148,64,67,1,30,30,64,31,5,22,19,4,1,27,24,23,20,15,12,9,6,5,2,21,21,22,2,1,2,20,19,20,3,3,3,4,23,22,23,0,0,1,18,18,19,5,5,18,8,7,2,10,17,16,2,14,13,
29,28,2,25,26,25,0,11,10,1,1,27,70,118,47,55,24,0,63,60,63,60,16,253,60,47,60,253,60,16,253,60,1,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,49,48,1,
73,104,185,0,27,0,30,73,104,97,176,64,82,88,56,17,55,185,0,30,255,192,56,89,1,7,39,19,55,23,39,7,33,39,55,33,3,7,35,39,55,51,19,7,39,19,55,23,3,7,33,39,55,33,1,222,43,32,37,42,32,44,43,254,220,32,42,1,
36,18,43,233,33,43,234,40,43,32,37,42,32,95,43,254,220,32,42,1,37,1,196,37,37,1,3,37,37,52,38,38,37,254,112,37,37,37,254,164,37,37,1,3,37,37,254,201,37,37,38,0,0,4,0,15,0,2,1,244,3,30,0,5,0,11,0,17,0,
23,0,147,64,68,1,24,24,64,25,5,22,10,7,1,23,20,15,12,11,8,5,2,21,21,22,2,1,2,20,19,20,3,3,3,4,23,22,23,0,0,1,18,18,19,5,5,18,11,10,11,6,3,6,7,9,9,10,8,8,9,17,16,2,14,13,19,0,4,1,1,8,70,118,47,55,24,0,
63,63,47,60,253,60,1,135,46,8,196,8,252,8,196,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,49,48,1,73,104,185,0,8,0,24,73,104,97,176,64,82,88,56,17,55,185,0,
24,255,192,56,89,1,7,39,19,55,23,1,7,39,19,55,23,1,7,33,39,55,33,19,7,39,19,55,23,1,200,42,32,43,43,32,254,102,43,32,37,43,32,1,14,43,254,249,32,42,1,8,33,42,32,43,43,32,1,196,37,37,1,53,37,37,254,203,
37,37,1,8,37,37,254,196,37,37,37,254,114,37,37,1,53,37,37,0,0,6,255,250,0,0,2,9,3,32,0,3,0,8,0,14,0,20,0,26,0,32,0,232,64,114,1,33,33,64,34,0,31,28,19,16,7,6,5,32,29,24,21,20,17,12,9,8,6,3,0,8,7,8,4,3,
4,5,6,7,7,8,29,29,7,32,31,32,27,3,27,28,6,7,7,8,29,29,7,17,16,17,18,3,18,19,15,15,16,20,20,15,30,31,3,31,32,28,28,29,27,27,28,31,30,31,32,3,28,27,28,24,24,25,29,23,23,29,2,1,2,0,14,13,2,11,10,26,25,2,
22,23,22,0,3,0,1,1,29,70,118,47,55,24,0,63,60,63,60,16,253,60,47,60,253,60,16,253,60,1,135,46,14,196,8,196,8,196,14,252,8,196,135,46,8,196,8,252,14,196,135,46,8,196,8,252,8,196,135,46,8,196,14,196,8,252,
8,196,135,46,8,196,14,196,8,252,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,49,48,1,73,104,185,0,29,0,33,73,104,97,176,64,82,88,56,17,55,185,0,33,255,192,56,89,1,7,33,39,19,7,35,
19,23,1,7,33,39,55,33,19,7,39,19,55,23,3,7,33,39,55,33,37,7,39,63,1,23,2,9,85,254,249,65,13,48,34,53,65,1,15,43,254,249,32,42,1,8,40,42,32,36,42,32,97,42,254,250,32,42,1,6,254,237,42,32,6,42,32,3,32,75,
75,254,164,42,1,119,76,254,203,37,37,37,254,164,37,37,1,3,37,37,254,201,37,37,38,14,37,37,41,38,38,0,6,0,16,0,0,1,243,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,177,64,82,1,36,36,64,37,0,28,25,16,15,13,10,8,
7,33,30,29,26,21,18,17,14,11,8,3,0,17,16,17,6,6,7,11,10,11,12,3,12,13,15,8,9,9,10,14,14,9,26,25,26,27,3,27,28,24,24,25,29,29,24,2,1,2,4,23,22,2,19,35,34,2,32,31,20,19,0,5,4,1,1,14,70,118,47,55,24,0,63,
60,63,60,47,60,253,60,16,253,60,16,253,60,1,135,46,8,196,8,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,
0,14,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,1,7,33,39,55,33,1,7,35,19,55,23,3,7,39,19,51,23,1,7,33,39,55,33,55,7,39,19,55,23,39,7,33,39,55,33,1,243,42,254,249,32,43,1,6,254,186,47,
33,42,43,32,88,42,32,42,33,36,1,14,42,254,250,33,43,1,6,92,43,32,37,42,32,45,42,254,248,32,43,1,7,2,251,38,38,37,254,164,42,1,45,37,37,253,146,37,37,1,45,42,254,201,37,37,38,14,37,37,1,3,37,37,52,37,37,
37,0,0,3,0,11,0,0,1,248,3,32,0,5,0,11,0,17,0,121,64,49,1,18,18,64,19,0,17,16,11,10,8,7,17,14,11,8,3,0,9,8,9,10,3,7,6,6,7,15,14,15,16,3,13,12,12,13,2,1,2,4,14,13,0,5,4,1,1,14,70,118,47,55,24,0,63,60,63,
60,16,253,60,1,135,46,14,196,14,252,8,196,135,46,14,196,14,252,8,196,1,46,46,46,46,46,46,0,46,46,46,46,46,46,49,48,1,73,104,185,0,14,0,18,73,104,97,176,64,82,88,56,17,55,185,0,18,255,192,56,89,1,7,33,
39,55,33,15,1,35,63,1,51,11,1,35,55,19,51,1,248,43,254,174,32,42,1,83,40,101,35,11,143,2,192,200,49,9,216,36,2,251,38,38,37,241,149,80,214,254,113,254,207,64,1,69,0,7,255,249,0,0,2,10,3,32,0,5,0,11,0,
17,0,23,0,29,0,35,0,41,0,205,64,100,1,42,42,64,43,35,34,31,28,25,16,13,10,7,39,36,35,32,29,26,21,18,17,14,11,8,3,0,17,16,17,6,6,7,11,10,11,12,3,12,13,15,15,16,8,7,8,9,9,10,14,14,9,32,31,32,27,27,28,26,
25,26,33,3,33,34,30,30,31,29,28,29,24,24,25,35,35,24,2,1,2,4,23,22,2,19,41,40,2,38,37,20,19,0,5,4,1,1,14,70,118,47,55,24,0,63,60,63,60,47,60,253,60,16,253,60,16,253,60,1,135,46,8,196,8,196,8,196,8,252,
8,196,8,196,8,196,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,14,0,42,73,104,97,176,64,82,88,56,17,55,185,
0,42,255,192,56,89,1,7,33,39,55,33,1,7,39,19,55,23,3,7,39,19,55,23,1,7,33,39,55,33,55,7,39,19,55,23,55,7,39,19,55,23,3,7,33,39,55,33,1,221,43,254,250,32,43,1,6,254,186,43,32,37,42,32,87,43,32,37,42,32,
1,15,43,254,250,32,43,1,6,91,42,32,36,43,32,14,42,32,36,43,32,96,43,254,249,32,42,1,8,2,251,38,38,37,254,164,37,37,1,3,37,37,253,146,37,37,1,3,37,37,254,201,37,37,38,14,37,37,1,3,37,37,104,37,37,1,3,37,
37,254,201,37,37,37,0,0,6,0,16,0,0,1,243,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,177,64,82,1,36,36,64,37,17,28,25,16,13,12,11,10,7,33,30,29,26,21,18,17,14,11,8,3,0,14,13,14,9,9,10,8,7,8,15,3,15,16,12,11,6,
6,7,17,17,6,29,28,29,24,3,24,25,27,27,28,26,26,27,5,4,2,1,20,19,2,22,32,31,2,35,34,23,22,1,2,1,0,1,3,70,118,47,55,24,0,63,60,63,60,47,60,253,60,16,253,60,16,253,60,1,135,46,8,196,8,252,8,196,135,46,8,
196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,3,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,37,7,33,39,
55,33,55,7,39,19,55,51,55,35,39,19,55,23,39,7,33,39,55,33,1,7,39,19,55,23,1,7,33,39,55,33,1,97,43,254,250,32,42,1,7,91,43,32,37,47,33,3,33,36,37,42,32,44,43,254,250,32,42,1,6,254,186,42,32,36,43,32,1,
16,43,254,249,32,42,1,8,37,37,37,38,14,37,37,1,3,42,20,42,1,3,37,37,52,38,38,37,254,164,37,37,1,3,37,37,254,201,37,37,37,0,0,2,0,200,0,2,1,59,1,114,0,5,0,11,0,177,64,84,1,12,12,64,13,5,10,1,11,8,5,2,2,
1,2,3,3,3,4,0,0,1,5,5,0,0,1,3,1,2,4,4,5,3,3,4,11,10,11,6,3,6,7,9,9,10,8,8,9,9,10,3,10,11,7,7,8,6,6,7,1,0,1,2,3,5,4,4,5,10,9,10,11,3,8,7,7,8,4,7,0,1,8,70,118,47,55,24,0,63,47,1,135,46,14,196,14,252,8,196,
135,46,14,196,14,252,8,196,135,46,8,196,8,252,14,196,135,46,8,196,8,252,8,196,135,46,8,196,8,252,14,196,135,46,8,196,8,252,8,196,1,46,46,46,46,0,46,46,49,48,1,73,104,185,0,8,0,12,73,104,97,176,64,82,88,
56,17,55,185,0,12,255,192,56,89,1,7,39,63,1,23,3,7,39,63,1,23,1,54,42,33,6,42,32,41,42,32,5,42,33,1,39,38,38,37,38,38,254,219,37,37,38,37,37,0,2,0,194,255,222,1,65,1,114,0,5,0,10,0,161,64,76,1,11,11,64,
12,5,9,1,10,7,5,2,2,1,2,3,3,3,4,0,0,1,5,5,0,0,1,3,1,2,4,4,5,3,3,4,7,6,7,8,3,8,9,6,6,7,10,10,6,8,7,8,9,3,9,10,7,7,8,6,6,7,1,0,1,2,3,5,4,4,5,4,7,1,7,70,118,47,55,24,0,47,47,1,135,46,14,196,14,252,8,196,
135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,8,252,14,196,135,46,8,196,8,252,8,196,1,46,46,46,46,0,46,46,49,48,1,73,104,185,0,7,0,11,73,104,97,176,64,82,88,56,17,55,185,0,11,255,192,
56,89,1,7,39,63,1,23,3,7,63,1,23,1,59,42,32,5,43,32,42,85,16,43,32,1,39,38,38,37,38,38,254,220,74,112,37,37,0,0,2,0,166,0,81,1,93,2,207,0,5,0,11,0,69,64,21,1,12,12,64,13,5,10,9,2,1,11,8,5,2,5,4,7,6,1,
8,70,118,47,55,24,0,47,60,47,60,1,46,46,46,46,0,46,46,46,46,49,48,1,73,104,185,0,8,0,12,73,104,97,176,64,82,88,56,17,55,185,0,12,255,192,56,89,1,7,35,63,1,51,3,35,39,55,51,23,1,73,108,41,12,155,2,90,2,
91,11,41,61,2,67,169,80,229,253,130,229,80,169,0,2,0,63,0,0,1,196,1,179,0,5,0,11,0,76,64,26,1,12,12,64,13,0,9,6,3,0,2,1,2,4,11,10,2,7,5,4,8,7,0,1,9,70,118,47,55,24,0,63,60,47,60,16,253,60,16,253,60,1,
46,46,46,46,0,49,48,1,73,104,185,0,9,0,12,73,104,97,176,64,82,88,56,17,55,185,0,12,255,192,56,89,1,7,33,39,55,33,3,7,33,39,55,33,1,196,43,254,249,33,43,1,8,19,43,254,249,32,43,1,7,1,142,38,38,37,254,114,
37,37,38,0,0,2,0,166,0,81,1,93,2,207,0,5,0,11,0,69,64,21,1,12,12,64,13,5,11,10,1,0,11,8,5,2,4,3,8,7,1,8,70,118,47,55,24,0,47,60,47,60,1,46,46,46,46,0,46,46,46,46,49,48,1,73,104,185,0,8,0,12,73,104,97,
176,64,82,88,56,17,55,185,0,12,255,192,56,89,1,35,39,55,51,23,15,1,35,63,1,51,1,82,41,61,20,2,91,26,155,2,20,108,41,1,154,169,140,229,180,229,140,169,0,0,5,0,67,0,2,1,192,3,32,0,5,0,11,0,17,0,23,0,27,
0,231,64,119,1,28,28,64,29,11,27,22,19,10,7,26,24,23,20,15,12,11,8,3,0,26,25,26,27,6,27,24,25,25,26,24,24,25,27,26,27,24,6,24,25,26,26,27,25,25,26,21,20,21,16,5,16,17,12,17,12,13,13,14,6,6,13,14,13,14,
15,5,15,16,12,12,13,17,17,12,8,7,8,9,3,9,10,6,6,7,11,11,6,23,22,23,18,3,18,19,21,21,22,20,20,21,2,1,2,4,14,13,2,17,16,25,0,5,4,1,1,3,70,118,47,55,24,0,63,60,63,47,60,253,60,16,253,60,1,135,46,8,196,8,
252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,8,196,8,252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,49,48,1,73,
104,185,0,3,0,28,73,104,97,176,64,82,88,56,17,55,185,0,28,255,192,56,89,1,7,33,39,55,33,19,7,39,63,1,23,3,7,35,39,55,51,3,7,39,63,1,23,3,7,39,55,1,145,45,254,255,32,42,1,7,40,43,36,36,45,34,95,43,80,32,
49,69,131,43,32,29,42,32,43,42,32,42,2,253,40,38,37,254,164,37,42,254,39,39,254,201,37,37,42,254,214,38,38,204,37,37,254,203,37,37,38,0,0,6,255,244,0,2,2,15,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,190,64,
88,1,36,36,64,37,23,29,28,22,19,18,10,8,7,4,3,33,30,29,26,23,20,15,12,11,8,5,2,6,6,7,5,4,5,11,10,11,0,3,0,1,8,3,9,9,10,2,2,9,27,27,28,20,19,20,26,25,26,21,3,21,22,29,18,24,24,25,23,23,24,14,13,2,16,35,
34,2,32,31,17,16,1,25,1,0,1,2,70,118,47,55,24,0,63,60,63,60,47,60,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,
46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,2,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,55,7,39,19,51,23,55,7,35,19,55,23,37,7,33,39,55,33,19,35,39,19,
55,23,3,7,39,19,55,51,39,7,33,39,55,33,63,43,32,49,33,36,16,48,34,42,44,32,1,67,42,254,249,32,43,1,6,36,34,36,36,44,32,94,43,32,43,48,33,52,42,254,248,32,42,1,8,39,37,37,1,95,42,104,42,1,43,39,37,52,38,
38,37,254,122,42,1,3,38,38,253,96,37,37,1,53,42,10,37,37,37,0,0,7,255,243,0,0,2,16,3,32,0,4,0,9,0,14,0,20,0,26,0,32,0,37,0,205,64,98,1,38,38,64,39,20,31,28,19,16,8,7,6,3,2,1,35,33,32,29,24,21,20,17,13,
10,9,7,4,1,5,5,6,4,3,4,9,8,9,0,3,0,1,7,2,8,8,9,1,1,8,30,30,31,17,16,17,29,28,29,18,3,18,19,32,31,32,15,15,16,27,27,28,20,20,27,12,11,2,13,23,22,2,26,25,37,36,2,34,35,34,0,14,13,1,1,1,70,118,47,55,24,0,
63,60,63,60,16,253,60,47,60,253,60,16,253,60,1,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,
46,46,46,46,46,46,46,49,48,1,73,104,185,0,1,0,38,73,104,97,176,64,82,88,56,17,55,185,0,38,255,192,56,89,55,7,19,51,23,55,7,35,19,23,37,7,33,39,33,19,7,39,19,55,23,3,7,33,39,55,33,19,7,39,19,55,23,3,7,
33,55,33,73,86,53,33,36,14,47,33,53,64,1,67,43,254,249,64,1,82,40,42,32,36,42,33,96,43,254,249,32,42,1,8,40,42,32,36,43,32,96,43,254,174,85,1,8,89,74,1,119,42,104,42,1,119,74,52,38,75,254,164,37,37,1,
3,37,37,254,201,37,37,37,254,164,37,37,1,3,37,37,254,201,37,75,0,6,255,249,0,0,2,10,3,32,0,5,0,11,0,17,0,23,0,29,0,35,1,3,64,128,1,36,36,64,37,5,34,31,22,21,19,16,14,13,4,1,35,32,27,24,23,20,17,14,9,6,
5,2,0,1,3,1,2,4,4,5,3,3,4,23,22,23,12,12,13,17,16,17,18,3,18,19,21,14,15,15,16,20,20,15,32,31,32,33,3,33,34,30,30,31,35,35,30,33,34,3,34,35,24,29,24,25,25,26,30,30,25,1,0,1,2,3,6,6,7,4,3,4,5,11,11,5,34,
33,34,35,3,32,31,31,32,8,7,2,10,29,28,2,25,26,25,0,11,10,1,1,20,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,14,196,14,252,8,196,135,46,14,196,8,196,8,196,14,252,8,196,135,46,8,196,8,196,
8,252,14,196,135,46,8,196,8,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,8,252,14,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,
185,0,20,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,1,7,39,63,1,23,39,7,33,39,55,33,1,7,35,19,55,23,3,7,39,19,51,23,1,7,33,39,55,33,55,7,39,63,1,23,2,4,43,32,6,43,32,45,43,254,250,32,
43,1,6,254,186,48,33,43,42,32,87,43,32,43,32,36,1,15,43,254,250,32,43,1,6,91,42,32,6,42,32,2,158,38,38,41,37,37,52,38,38,37,254,164,42,1,45,37,37,253,146,37,37,1,45,42,254,201,37,37,38,14,37,37,41,38,
38,0,6,255,243,0,0,2,16,3,32,0,4,0,9,0,14,0,20,0,26,0,31,0,192,64,89,1,32,32,64,33,20,26,25,22,19,16,15,8,7,6,3,2,1,29,27,26,23,20,17,13,10,9,7,4,1,5,5,6,4,3,4,9,8,9,0,3,0,1,7,2,8,8,9,1,1,8,24,24,25,17,
16,17,23,22,23,18,3,18,19,26,15,21,21,22,20,20,21,12,11,2,13,31,30,2,28,29,28,0,14,13,1,1,1,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,
8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,1,0,32,73,104,97,176,64,82,88,56,17,55,185,0,32,255,192,56,
89,55,7,19,51,23,55,7,35,19,23,37,7,33,39,33,19,35,39,19,55,23,3,7,39,19,55,51,3,7,33,55,33,73,86,53,33,36,14,47,33,53,64,1,67,43,254,249,64,1,82,34,33,35,36,42,33,88,42,32,36,47,33,101,43,254,174,85,
1,8,89,74,1,119,42,104,42,1,119,74,52,38,75,254,122,42,1,3,37,37,253,146,37,37,1,3,42,254,159,37,75,0,5,0,16,0,0,1,243,3,32,0,5,0,11,0,17,0,23,0,29,0,148,64,65,1,30,30,64,31,0,22,21,19,10,8,7,27,24,23,
20,15,12,11,8,3,0,23,22,23,6,6,7,11,10,11,18,3,18,19,21,8,9,9,10,20,20,9,2,1,2,4,17,16,2,14,13,29,28,2,25,26,25,0,5,4,1,1,20,70,118,47,55,24,0,63,60,63,60,16,253,60,47,60,253,60,16,253,60,1,135,46,8,196,
14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,49,48,1,73,104,185,0,20,0,30,73,104,97,176,64,82,88,56,17,55,185,0,30,255,192,56,89,1,7,33,39,55,33,1,7,35,19,
55,23,19,7,35,39,55,51,1,7,39,19,51,23,1,7,33,39,55,33,1,243,42,254,249,32,43,1,6,254,186,47,33,42,43,32,210,42,204,32,43,203,254,246,42,32,42,33,36,1,14,42,254,250,33,43,1,6,2,251,38,38,37,254,164,42,
1,45,37,37,254,201,37,37,37,254,164,37,37,1,45,42,254,201,37,37,38,0,0,4,0,12,0,1,1,247,3,32,0,5,0,11,0,17,0,23,0,133,64,57,1,24,24,64,25,0,22,21,10,8,7,23,20,15,12,11,8,3,0,23,22,23,6,6,7,11,10,11,18,
3,18,19,21,8,9,9,10,20,20,9,2,1,2,4,17,16,2,14,13,19,0,5,4,1,1,20,70,118,47,55,24,0,63,60,63,47,60,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,0,46,
46,46,46,46,49,48,1,73,104,185,0,20,0,24,73,104,97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,1,7,33,39,55,33,1,7,35,19,55,23,19,7,35,39,55,51,1,7,39,19,51,23,1,247,43,254,250,32,43,1,6,254,186,48,33,
43,42,32,211,43,203,32,42,204,254,239,43,32,49,33,36,2,251,38,38,37,254,164,42,1,45,37,37,254,201,37,37,37,254,113,37,37,1,96,42,0,6,0,14,0,0,1,245,3,32,0,5,0,11,0,17,0,23,0,28,0,33,0,177,64,82,1,34,34,
64,35,28,28,25,16,15,13,10,8,7,32,29,28,26,21,18,17,14,11,8,3,0,17,16,17,6,6,7,11,10,11,12,3,12,13,15,8,9,9,10,14,14,9,26,25,26,27,3,27,28,24,24,25,28,28,24,2,1,2,4,23,22,2,19,33,29,2,31,30,20,19,0,5,
4,1,1,14,70,118,47,55,24,0,63,60,63,60,47,60,253,60,16,253,60,16,253,60,1,135,46,8,196,8,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,
46,46,46,46,49,48,1,73,104,185,0,14,0,34,73,104,97,176,64,82,88,56,17,55,185,0,34,255,192,56,89,1,7,33,39,55,33,1,7,35,19,55,23,3,7,39,19,51,23,1,7,33,39,55,33,55,7,39,19,55,39,7,35,39,55,1,241,42,254,
249,32,43,1,6,254,186,47,33,42,42,32,87,42,32,42,33,35,1,15,42,254,249,32,43,1,6,92,43,32,36,85,12,85,80,32,42,2,251,38,38,37,254,164,42,1,45,37,37,253,146,37,37,1,45,42,254,201,37,37,38,14,37,37,1,3,
74,15,74,37,37,0,5,255,242,0,2,2,17,3,30,0,5,0,11,0,17,0,23,0,29,0,175,64,80,1,30,30,64,31,5,28,27,23,22,8,7,1,0,29,26,23,20,15,12,11,8,5,2,21,21,22,2,1,2,20,19,20,3,3,3,4,23,0,18,18,19,5,5,18,29,28,29,
6,6,7,11,10,11,24,3,24,25,27,8,9,9,10,26,26,9,17,16,2,14,13,25,19,0,10,4,1,1,26,70,118,47,55,24,0,63,60,63,60,47,60,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,
8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,26,0,30,73,104,97,176,64,82,88,56,17,55,185,0,30,255,192,56,89,1,35,39,19,55,23,1,7,35,19,55,23,1,
7,33,39,55,33,19,7,39,19,55,51,1,7,39,19,51,23,1,224,33,36,43,43,32,254,102,48,33,50,42,32,1,8,43,254,249,32,42,1,8,33,42,32,43,48,33,254,96,43,32,49,33,36,1,154,42,1,53,37,37,254,203,42,1,95,37,37,254,
151,37,37,37,254,114,37,37,1,53,42,254,161,37,37,1,95,42,0,2,0,170,0,2,1,89,3,30,0,5,0,11,0,105,64,44,1,12,12,64,13,5,10,1,11,8,5,2,9,9,10,2,1,2,8,7,8,3,3,3,4,11,10,11,0,0,1,6,6,7,5,5,6,7,0,4,1,1,8,70,
118,47,55,24,0,63,63,1,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,1,46,46,46,46,0,46,46,49,48,1,73,104,185,0,8,0,12,73,104,97,176,64,82,88,56,17,55,185,0,12,255,192,56,89,1,7,39,19,55,23,3,7,39,
19,55,23,1,46,42,32,43,42,32,101,42,32,43,42,32,1,196,37,37,1,53,37,37,253,46,37,37,1,53,37,37,0,4,255,245,0,0,2,14,3,32,0,5,0,11,0,17,0,23,0,195,64,93,1,24,24,64,25,5,22,19,11,10,7,1,0,23,20,15,12,11,
8,5,2,9,9,10,2,1,2,8,7,8,3,3,3,4,11,0,6,6,7,5,5,6,23,22,23,18,3,18,19,21,21,22,20,20,21,21,22,3,22,23,19,19,20,18,18,19,22,21,22,23,3,19,18,19,15,15,16,20,14,14,20,17,16,2,13,14,13,0,4,1,1,20,70,118,47,
55,24,0,63,63,60,16,253,60,1,135,46,14,196,8,196,8,196,14,252,8,196,135,46,8,196,8,252,14,196,135,46,8,196,8,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,0,46,
46,46,46,46,46,46,49,48,1,73,104,185,0,20,0,24,73,104,97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,1,35,39,19,55,23,3,7,39,19,55,51,3,7,33,39,55,33,37,7,39,63,1,23,1,220,32,36,43,43,32,95,42,32,36,
48,33,103,43,254,250,32,42,1,7,254,237,43,32,6,42,32,1,154,42,1,55,37,37,253,94,37,37,1,3,42,254,159,37,37,38,14,37,37,41,38,38,0,5,255,242,0,0,2,17,3,32,0,5,0,11,0,17,0,23,0,29,0,178,64,81,1,30,30,64,
31,5,28,27,22,21,8,7,2,1,29,26,23,20,15,12,11,8,5,3,0,5,0,1,3,4,3,3,4,29,28,29,6,6,7,11,10,11,24,3,24,25,27,8,9,9,10,26,26,9,22,23,3,23,18,20,20,21,19,19,20,14,13,2,17,16,25,19,18,0,10,5,4,1,1,26,70,118,
47,55,24,0,63,60,60,63,60,60,47,60,253,60,1,135,46,8,196,8,252,14,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,14,196,14,252,8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,
46,46,49,48,1,73,104,185,0,26,0,30,73,104,97,176,64,82,88,56,17,55,185,0,30,255,192,56,89,1,3,35,39,19,51,1,7,35,19,55,23,19,7,35,39,55,51,19,35,3,55,51,19,5,7,39,19,51,23,2,7,220,37,25,248,44,254,102,
48,33,49,43,32,80,43,79,32,42,80,207,44,147,33,37,130,254,147,43,32,49,33,36,2,219,254,191,30,1,104,254,164,42,1,95,37,37,254,151,37,37,37,254,75,1,104,30,254,191,30,37,37,1,95,42,0,0,3,0,67,0,0,1,192,
3,30,0,5,0,11,0,17,0,120,64,50,1,18,18,64,19,12,10,9,7,2,1,15,12,11,8,5,2,11,10,11,0,0,1,5,4,5,6,3,6,7,9,2,3,3,4,8,8,3,17,16,2,13,14,13,0,4,1,1,8,70,118,47,55,24,0,63,63,60,16,253,60,1,135,46,8,196,14,
196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,0,46,46,46,46,46,49,48,1,73,104,185,0,8,0,18,73,104,97,176,64,82,88,56,17,55,185,0,18,255,192,56,89,19,7,35,19,55,23,3,7,39,19,51,23,1,7,33,39,55,
33,192,47,33,49,43,32,95,42,32,42,33,36,1,14,42,254,249,32,43,1,6,1,196,42,1,95,37,37,253,96,37,37,1,45,42,254,201,37,37,38,0,6,255,241,0,0,2,18,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,222,64,105,1,36,36,
64,37,5,34,33,29,28,20,19,16,15,13,12,11,10,8,7,1,0,35,32,29,26,23,20,17,14,11,8,5,2,27,27,28,2,1,2,26,25,26,3,3,3,4,29,0,24,24,25,5,5,24,6,11,6,7,3,10,9,9,10,35,34,35,18,18,19,23,22,23,30,3,30,31,33,
20,21,21,22,32,32,21,13,14,3,14,15,17,17,12,16,16,17,31,25,0,22,4,1,1,32,70,118,47,55,24,0,63,60,63,60,1,135,46,8,196,8,252,14,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,14,196,14,252,
8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,32,0,36,73,104,97,176,64,82,88,56,
17,55,185,0,36,255,192,56,89,1,35,39,19,55,23,15,1,35,63,1,51,3,35,39,55,51,23,15,1,35,19,55,23,1,7,39,19,55,51,1,7,39,19,51,23,1,225,33,36,43,43,32,124,106,31,12,144,2,179,31,63,20,2,84,142,48,33,50,
43,32,1,10,43,32,44,48,33,254,94,43,32,49,33,36,1,155,41,1,55,37,37,198,155,86,215,254,211,155,146,215,44,41,1,96,37,37,253,42,37,37,1,55,41,254,160,37,37,1,96,41,0,0,5,255,242,0,2,2,17,3,30,0,5,0,11,
0,17,0,23,0,29,0,193,64,90,1,30,30,64,31,23,29,28,19,18,16,15,13,12,8,7,4,3,29,26,23,20,17,14,11,8,5,2,6,6,7,5,4,5,11,10,11,0,3,0,1,8,3,9,9,10,2,2,9,27,27,28,20,19,20,26,25,26,21,3,21,22,29,18,24,24,25,
23,23,24,13,14,3,14,15,17,17,12,16,16,17,22,10,1,25,1,0,1,2,70,118,47,55,24,0,63,60,63,60,1,135,46,8,196,8,252,14,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,
8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,2,0,30,73,104,97,176,64,82,88,56,17,55,185,0,30,255,192,56,89,55,7,39,19,51,23,55,7,35,19,55,
23,19,35,39,55,51,31,1,35,39,19,55,23,3,7,39,19,55,51,61,43,32,49,33,36,15,48,33,50,42,32,228,47,175,10,33,188,80,32,36,43,43,32,102,42,32,43,48,33,39,37,37,1,95,42,104,42,1,95,37,37,254,208,203,76,220,
106,42,1,53,37,37,253,46,37,37,1,53,42,0,0,6,255,249,0,0,2,10,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,192,64,89,1,36,36,64,37,23,29,28,25,22,19,18,10,8,7,4,3,1,33,30,29,26,23,20,15,12,11,8,5,2,6,6,7,5,4,5,
11,10,11,0,3,0,1,8,3,9,9,10,2,2,9,27,27,28,20,19,20,26,25,26,21,3,21,22,29,18,24,24,25,23,23,24,14,13,2,16,35,34,2,31,32,31,0,17,16,1,1,2,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,8,196,
14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,2,0,36,73,104,
97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,55,7,39,19,51,23,55,7,35,19,55,23,37,7,33,39,55,33,19,35,39,19,55,23,3,7,39,19,55,51,3,7,33,39,55,33,68,43,32,42,33,36,15,48,33,43,42,32,1,66,43,254,250,
32,43,1,6,35,33,36,36,43,32,88,42,32,36,48,33,102,43,254,250,32,43,1,6,89,37,37,1,45,42,104,42,1,45,37,37,52,38,38,37,254,122,42,1,3,37,37,253,146,37,37,1,3,42,254,159,37,37,38,0,5,255,245,0,2,2,14,3,
32,0,5,0,10,0,15,0,21,0,27,0,162,64,74,1,28,28,64,29,5,26,25,14,13,12,4,1,27,24,19,16,15,13,9,6,5,2,2,1,2,3,3,3,4,0,0,1,5,5,0,27,26,27,11,11,12,15,14,15,22,3,22,23,25,13,14,14,15,24,24,14,8,7,2,9,21,20,
2,18,17,23,0,10,9,1,1,24,70,118,47,55,24,0,63,60,63,47,60,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,8,252,8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,
46,46,49,48,1,73,104,185,0,24,0,28,73,104,97,176,64,82,88,56,17,55,185,0,28,255,192,56,89,1,7,39,19,55,23,39,7,33,39,33,1,7,35,19,23,1,7,33,39,55,33,1,7,39,19,51,23,1,234,42,32,36,42,32,44,43,254,249,
64,1,82,254,184,47,33,53,64,1,16,43,254,249,32,42,1,8,254,176,42,32,49,33,36,1,196,37,37,1,3,37,37,52,38,75,254,164,42,1,119,74,254,201,37,37,37,254,114,37,37,1,95,42,0,0,7,255,249,0,0,2,10,3,32,0,5,0,
11,0,17,0,23,0,29,0,35,0,39,0,248,64,121,1,40,40,64,41,23,38,36,29,28,25,22,19,18,10,8,7,4,3,1,39,37,33,30,29,26,23,20,15,12,11,8,5,2,37,36,37,38,4,38,39,29,18,24,24,25,23,23,24,6,6,7,5,4,5,11,10,11,0,
3,0,1,8,3,9,9,10,2,2,9,27,27,28,20,19,20,26,25,26,21,3,21,22,29,18,24,24,25,23,23,24,37,36,37,38,3,38,39,36,36,37,39,39,36,14,13,2,16,35,34,2,31,32,31,0,17,16,1,1,2,70,118,47,55,24,0,63,60,63,60,16,253,
60,16,253,60,1,135,46,8,196,8,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,1,46,46,46,46,46,46,
46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,2,0,40,73,104,97,176,64,82,88,56,17,55,185,0,40,255,192,56,89,55,7,39,19,51,23,55,7,35,19,55,23,37,7,33,39,55,33,
19,35,39,19,55,23,3,7,39,19,55,51,3,7,33,39,55,33,47,1,55,23,68,43,32,42,33,36,15,48,33,43,42,32,1,66,43,254,250,32,43,1,6,35,33,36,36,43,32,88,42,32,36,48,33,102,43,254,250,32,43,1,6,3,70,19,68,89,37,
37,1,45,42,104,42,1,45,37,37,52,38,38,37,254,122,42,1,3,37,37,253,146,37,37,1,3,42,254,159,37,37,38,34,107,136,118,0,6,255,245,0,0,2,14,3,32,0,5,0,10,0,15,0,21,0,27,0,33,0,191,64,89,1,34,34,64,35,5,32,
31,26,25,14,13,12,4,1,33,30,27,24,19,16,15,13,9,6,5,2,2,1,2,3,3,3,4,0,0,1,5,5,0,33,32,33,11,11,12,15,14,15,28,3,28,29,31,13,14,14,15,30,30,14,26,25,26,27,3,24,23,23,24,8,7,2,9,18,17,2,21,20,29,23,22,0,
10,9,1,1,30,70,118,47,55,24,0,63,60,63,60,60,47,60,253,60,16,253,60,1,135,46,14,196,14,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,8,252,8,196,1,46,46,46,46,46,46,46,46,46,
46,46,46,0,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,30,0,34,73,104,97,176,64,82,88,56,17,55,185,0,34,255,192,56,89,1,7,39,19,55,23,39,7,33,39,33,1,7,35,19,23,1,7,33,39,55,33,19,35,3,55,51,19,37,
7,39,19,51,23,1,234,42,32,36,42,32,44,43,254,249,65,1,83,254,184,47,33,53,64,1,16,43,254,249,32,42,1,8,28,65,240,6,61,243,254,143,42,32,49,33,36,1,196,37,37,1,3,37,37,52,38,75,254,164,42,1,119,74,254,
201,37,37,37,254,75,1,45,41,254,207,2,37,37,1,95,42,0,7,255,249,0,0,2,10,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,41,0,249,64,124,1,42,42,64,43,5,40,37,28,25,16,13,4,1,41,38,33,30,29,26,21,18,17,14,9,6,5,2,
17,16,17,12,3,12,13,15,15,16,14,14,15,26,25,26,27,3,27,28,24,24,25,29,29,24,41,40,41,36,3,36,37,39,39,40,38,38,39,39,40,3,40,41,37,37,38,36,36,37,1,0,1,2,3,4,3,4,5,11,11,5,40,39,40,41,3,37,36,37,38,32,
32,38,8,7,2,10,23,22,2,20,19,35,34,2,31,32,31,0,11,10,1,1,38,70,118,47,55,24,0,63,60,63,60,16,253,60,47,60,253,60,16,253,60,1,135,46,14,196,8,196,14,252,8,196,135,46,14,196,8,196,14,252,8,196,135,46,8,
196,8,252,14,196,135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,38,0,42,73,104,97,
176,64,82,88,56,17,55,185,0,42,255,192,56,89,1,7,39,63,1,23,39,7,33,39,55,33,1,7,39,19,55,23,1,7,33,39,55,33,19,7,39,19,55,23,3,7,33,39,55,33,37,7,39,63,1,23,2,5,43,32,6,42,32,44,43,254,250,32,42,1,6,
254,186,42,32,36,43,32,1,15,43,254,248,32,43,1,8,40,43,32,37,42,32,97,42,254,250,33,43,1,6,254,237,42,32,5,43,32,2,158,38,38,41,37,37,52,38,38,37,254,164,37,37,1,3,37,37,254,201,37,37,37,254,164,37,37,
1,3,37,37,254,201,37,37,38,14,37,37,41,38,38,0,3,0,49,0,2,1,210,3,32,0,8,0,14,0,20,0,126,64,56,1,21,21,64,22,0,19,13,10,3,20,17,14,11,6,0,20,19,20,9,9,10,14,13,14,15,3,15,16,18,18,19,11,10,11,12,12,13,
17,17,12,5,4,2,3,1,2,7,16,0,8,7,1,1,6,70,118,47,55,24,0,63,60,63,16,253,23,60,1,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,0,46,46,46,46,49,48,1,73,104,185,0,6,0,21,73,104,97,
176,64,82,88,56,17,55,185,0,21,255,192,56,89,1,7,35,39,7,35,39,55,33,3,7,39,19,55,23,3,7,39,19,55,23,1,210,43,119,45,58,120,32,43,1,86,183,43,32,36,43,32,94,43,32,43,43,32,2,251,38,52,52,38,37,254,164,
37,37,1,3,37,37,253,96,37,37,1,53,37,37,0,0,5,255,246,0,0,2,13,3,30,0,5,0,11,0,17,0,23,0,29,0,177,64,81,1,30,30,64,31,29,25,24,23,22,19,10,9,7,2,1,29,26,23,20,15,12,11,8,5,2,11,10,11,0,0,1,5,4,5,6,3,6,
7,9,2,3,3,4,8,8,3,26,25,26,21,21,22,20,19,20,27,3,27,28,24,23,18,18,19,29,29,18,17,16,2,13,14,13,0,28,4,1,1,8,70,118,47,55,24,0,63,60,63,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,
135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,8,0,30,73,104,97,176,64,82,88,56,17,55,185,0,30,255,192,56,89,19,
7,35,19,55,23,3,7,39,19,51,23,1,7,33,39,55,33,55,7,39,19,55,51,55,35,39,19,55,23,115,47,33,49,43,32,95,42,32,42,33,36,1,14,42,254,250,32,42,1,6,92,43,32,37,47,33,3,33,36,44,42,32,1,196,42,1,95,37,37,253,
96,37,37,1,45,42,254,201,37,37,38,14,37,37,1,3,42,20,42,1,53,37,37,0,0,4,0,7,0,0,1,252,3,30,0,5,0,11,0,17,0,23,0,182,64,88,1,24,24,64,25,5,22,21,17,16,8,7,1,0,23,20,17,14,11,8,5,2,2,3,3,3,4,17,16,17,0,
0,1,12,12,13,5,5,12,11,10,11,6,3,6,7,9,9,10,8,8,9,15,14,15,16,3,16,17,13,12,12,13,22,21,22,23,3,23,18,20,20,21,19,19,20,19,18,14,3,13,0,10,4,1,1,20,70,118,47,55,24,0,63,60,63,23,60,1,135,46,8,196,8,252,
8,196,135,46,14,196,8,252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,8,196,8,196,8,252,14,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,20,0,24,73,104,97,176,64,82,88,56,
17,55,185,0,24,255,192,56,89,1,35,39,19,55,23,1,7,35,19,55,23,1,3,35,55,19,51,1,35,3,55,51,19,1,203,58,13,45,43,32,254,100,21,57,49,42,32,1,52,228,31,14,188,64,254,225,30,132,6,64,106,1,154,31,1,64,37,
37,254,192,31,1,95,37,37,254,96,254,167,100,1,34,254,122,1,89,45,254,222,0,6,255,241,0,0,2,18,3,31,0,5,0,11,0,17,0,23,0,29,0,35,0,222,64,105,1,36,36,64,37,5,34,33,29,28,26,25,22,21,19,18,17,16,8,7,1,0,
35,32,29,26,23,20,17,14,11,8,5,2,15,15,16,2,1,2,14,13,14,3,3,3,4,17,0,12,12,13,5,5,12,35,34,35,6,6,7,11,10,11,30,3,30,31,33,8,9,9,10,32,32,9,27,26,27,28,3,25,24,24,25,22,23,3,23,18,20,20,21,19,19,20,31,
13,0,10,4,1,1,32,70,118,47,55,24,0,63,60,63,60,1,135,46,8,196,8,252,14,196,135,46,14,196,14,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,
196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,32,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,1,35,39,19,55,23,1,7,35,
19,55,23,1,7,39,19,55,51,3,35,39,55,51,23,39,7,35,63,1,51,3,7,39,19,51,23,1,224,33,36,44,43,32,254,100,47,34,50,43,32,1,10,43,32,44,47,34,139,2,83,12,31,63,127,144,2,20,107,31,185,43,32,50,33,36,1,154,
42,1,54,37,37,254,202,42,1,96,37,37,253,43,37,37,1,54,42,254,212,215,85,154,69,215,146,154,254,160,37,37,1,96,42,0,4,255,241,0,0,2,18,3,32,0,5,0,11,0,17,0,23,0,168,64,77,1,24,24,64,25,5,23,22,16,15,7,
6,2,1,23,20,17,14,11,8,5,2,3,2,3,4,3,1,0,0,1,18,23,18,19,3,22,21,21,22,10,11,3,11,6,8,8,9,7,7,8,13,14,3,14,15,17,17,12,16,16,17,20,19,13,3,12,0,10,9,5,3,4,1,1,20,70,118,47,55,24,0,63,23,60,63,23,60,1,
135,46,8,196,8,252,14,196,135,46,8,196,8,252,14,196,135,46,14,196,14,252,8,196,135,46,14,196,14,252,8,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,20,0,24,73,104,97,176,
64,82,88,56,17,55,185,0,24,255,192,56,89,1,3,35,55,19,51,1,35,3,55,51,27,1,35,3,55,51,19,39,3,35,55,19,51,2,8,210,41,12,200,49,254,230,40,120,10,48,114,157,48,114,11,41,120,193,200,49,10,210,41,2,219,
254,191,85,1,49,254,122,1,65,69,254,207,254,17,1,49,84,254,192,236,254,207,69,1,64,0,0,3,0,32,0,0,1,227,3,32,0,5,0,11,0,17,0,141,64,65,1,18,18,64,19,5,16,7,6,2,1,17,14,11,8,5,2,0,5,0,1,3,4,4,5,3,3,4,17,
16,17,12,3,12,13,15,15,16,14,14,15,10,9,10,11,3,11,6,8,8,9,7,7,8,13,0,10,9,5,3,4,1,1,8,70,118,47,55,24,0,63,23,60,63,1,135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,14,252,8,196,1,46,
46,46,46,46,46,0,46,46,46,46,46,49,48,1,73,104,185,0,8,0,18,73,104,97,176,64,82,88,56,17,55,185,0,18,255,192,56,89,1,3,35,55,19,51,1,35,3,55,51,19,3,7,39,19,55,23,1,219,213,45,11,196,59,254,225,46,118,
8,58,109,15,43,32,43,43,32,2,234,254,175,80,1,55,254,121,1,81,54,254,201,254,60,37,37,1,54,37,37,0,0,4,0,27,0,0,1,232,3,32,0,5,0,11,0,17,0,23,0,136,64,57,1,24,24,64,25,0,17,16,14,13,11,10,8,7,21,18,17,
14,11,8,3,0,6,11,6,7,3,10,9,9,10,15,14,15,16,3,13,12,12,13,2,1,2,4,23,22,2,19,20,19,0,5,4,1,1,21,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,14,196,14,252,8,196,135,46,14,196,14,252,8,196,
1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,21,0,24,73,104,97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,1,7,33,39,55,33,15,1,35,63,1,51,3,7,35,63,1,51,19,7,33,39,55,33,
1,232,43,254,240,32,42,1,16,33,117,36,12,148,12,207,148,12,19,117,36,130,43,254,238,32,43,1,18,2,251,38,38,37,226,164,85,209,254,113,209,130,163,254,160,37,37,38,0,4,0,92,0,0,1,167,3,32,0,4,0,9,0,14,0,
19,0,135,64,58,1,20,20,64,21,4,13,12,11,8,7,6,19,16,14,11,9,7,4,3,14,13,14,5,5,6,9,8,9,10,3,10,11,12,7,8,8,9,11,11,8,2,1,2,3,18,17,2,15,16,15,0,4,3,1,1,11,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,
60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,49,48,1,73,104,185,0,11,0,20,73,104,97,176,64,82,88,56,17,55,185,0,20,255,192,56,89,1,7,35,39,51,3,
7,35,19,23,3,7,19,51,23,19,35,55,51,23,1,164,59,80,64,206,195,47,33,52,64,87,85,53,33,35,98,206,85,79,45,3,9,52,75,254,164,42,1,119,74,253,146,74,1,119,42,254,164,75,52,0,2,0,89,0,0,1,170,3,32,0,5,0,11,
0,107,64,42,1,12,12,64,13,11,10,9,1,0,11,8,5,2,10,5,5,0,4,11,3,11,6,8,8,9,1,2,2,3,7,7,2,7,6,0,4,3,1,1,2,70,118,47,55,24,0,63,60,63,60,1,135,46,8,196,14,196,8,196,8,252,14,196,8,196,14,196,1,46,46,46,46,
0,46,46,46,46,49,48,1,73,104,185,0,2,0,12,73,104,97,176,64,82,88,56,17,55,185,0,12,255,192,56,89,19,35,3,55,51,27,1,35,3,55,51,19,248,35,124,9,48,115,156,48,115,12,36,124,1,154,1,70,64,254,212,254,12,
1,44,89,254,187,0,0,4,0,92,0,0,1,167,3,32,0,4,0,9,0,14,0,19,0,135,64,58,1,20,20,64,21,9,14,13,10,9,6,5,16,15,14,11,9,7,3,0,12,12,13,7,6,7,11,10,11,8,3,8,9,14,5,10,10,11,9,9,10,2,1,2,0,19,18,2,15,16,15,
0,4,0,1,1,16,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,49,48,1,73,104,185,0,16,0,20,73,104,97,
176,64,82,88,56,17,55,185,0,20,255,192,56,89,1,7,35,39,55,19,35,39,19,55,3,39,19,55,51,3,35,63,1,51,1,154,85,79,45,3,166,33,35,36,85,108,64,36,47,33,69,206,3,59,80,3,32,75,52,23,254,122,42,1,3,74,252,
254,74,1,3,42,254,122,23,52,0,0,1,0,89,0,0,1,170,0,75,0,5,0,58,64,16,1,6,6,64,7,0,3,0,5,4,2,1,0,1,3,70,118,47,55,24,0,63,60,47,60,1,46,46,0,49,48,1,73,104,185,0,3,0,6,73,104,97,176,64,82,88,56,17,55,185,
0,6,255,192,56,89,37,7,33,39,55,33,1,170,42,254,249,32,42,1,7,37,37,37,38,0,0,6,255,244,0,2,2,15,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,190,64,88,1,36,36,64,37,23,29,28,22,19,18,10,8,7,4,3,33,30,29,26,23,
20,15,12,11,8,5,2,6,6,7,5,4,5,11,10,11,0,3,0,1,8,3,9,9,10,2,2,9,27,27,28,20,19,20,26,25,26,21,3,21,22,29,18,24,24,25,23,23,24,14,13,2,16,35,34,2,32,31,17,16,1,25,1,0,1,2,70,118,47,55,24,0,63,60,63,60,
47,60,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,49,
48,1,73,104,185,0,2,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,55,7,39,19,51,23,55,7,35,19,55,23,37,7,33,39,55,33,19,35,39,19,55,23,3,7,39,19,55,51,39,7,33,39,55,33,63,43,32,49,33,36,
16,48,34,42,44,32,1,67,42,254,249,32,43,1,6,36,34,36,36,44,32,94,43,32,43,48,33,52,42,254,248,32,42,1,8,39,37,37,1,95,42,104,42,1,43,39,37,52,38,38,37,254,122,42,1,3,38,38,253,96,37,37,1,53,42,10,37,37,
37,0,0,7,255,243,0,0,2,16,3,32,0,4,0,9,0,14,0,20,0,26,0,32,0,37,0,205,64,98,1,38,38,64,39,20,31,28,19,16,8,7,6,3,2,1,35,33,32,29,24,21,20,17,13,10,9,7,4,1,5,5,6,4,3,4,9,8,9,0,3,0,1,7,2,8,8,9,1,1,8,30,
30,31,17,16,17,29,28,29,18,3,18,19,32,31,32,15,15,16,27,27,28,20,20,27,12,11,2,13,23,22,2,26,25,37,36,2,34,35,34,0,14,13,1,1,1,70,118,47,55,24,0,63,60,63,60,16,253,60,47,60,253,60,16,253,60,1,135,46,8,
196,8,196,8,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,1,0,38,73,104,
97,176,64,82,88,56,17,55,185,0,38,255,192,56,89,55,7,19,51,23,55,7,35,19,23,37,7,33,39,33,19,7,39,19,55,23,3,7,33,39,55,33,19,7,39,19,55,23,3,7,33,55,33,73,86,53,33,36,14,47,33,53,64,1,67,43,254,249,64,
1,82,40,42,32,36,42,33,96,43,254,249,32,42,1,8,40,42,32,36,43,32,96,43,254,174,85,1,8,89,74,1,119,42,104,42,1,119,74,52,38,75,254,164,37,37,1,3,37,37,254,201,37,37,37,254,164,37,37,1,3,37,37,254,201,37,
75,0,6,255,249,0,0,2,10,3,32,0,5,0,11,0,17,0,23,0,29,0,35,1,3,64,128,1,36,36,64,37,5,34,31,22,21,19,16,14,13,4,1,35,32,27,24,23,20,17,14,9,6,5,2,0,1,3,1,2,4,4,5,3,3,4,23,22,23,12,12,13,17,16,17,18,3,18,
19,21,14,15,15,16,20,20,15,32,31,32,33,3,33,34,30,30,31,35,35,30,33,34,3,34,35,24,29,24,25,25,26,30,30,25,1,0,1,2,3,6,6,7,4,3,4,5,11,11,5,34,33,34,35,3,32,31,31,32,8,7,2,10,29,28,2,25,26,25,0,11,10,1,
1,20,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,14,196,14,252,8,196,135,46,14,196,8,196,8,196,14,252,8,196,135,46,8,196,8,196,8,252,14,196,135,46,8,196,8,252,8,196,135,46,8,196,14,196,
14,196,8,252,8,196,8,196,8,196,135,46,8,196,8,252,14,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,20,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,
192,56,89,1,7,39,63,1,23,39,7,33,39,55,33,1,7,35,19,55,23,3,7,39,19,51,23,1,7,33,39,55,33,55,7,39,63,1,23,2,4,43,32,6,43,32,45,43,254,250,32,43,1,6,254,186,48,33,43,42,32,87,43,32,43,32,36,1,15,43,254,
250,32,43,1,6,91,42,32,6,42,32,2,158,38,38,41,37,37,52,38,38,37,254,164,42,1,45,37,37,253,146,37,37,1,45,42,254,201,37,37,38,14,37,37,41,38,38,0,6,255,243,0,0,2,16,3,32,0,4,0,9,0,14,0,20,0,26,0,31,0,192,
64,89,1,32,32,64,33,20,26,25,22,19,16,15,8,7,6,3,2,1,29,27,26,23,20,17,13,10,9,7,4,1,5,5,6,4,3,4,9,8,9,0,3,0,1,7,2,8,8,9,1,1,8,24,24,25,17,16,17,23,22,23,18,3,18,19,26,15,21,21,22,20,20,21,12,11,2,13,
31,30,2,28,29,28,0,14,13,1,1,1,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,
46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,1,0,32,73,104,97,176,64,82,88,56,17,55,185,0,32,255,192,56,89,55,7,19,51,23,55,7,35,19,23,37,7,33,39,33,19,35,39,19,55,23,
3,7,39,19,55,51,3,7,33,55,33,73,86,53,33,36,14,47,33,53,64,1,67,43,254,249,64,1,82,34,33,35,36,42,33,88,42,32,36,47,33,101,43,254,174,85,1,8,89,74,1,119,42,104,42,1,119,74,52,38,75,254,122,42,1,3,37,37,
253,146,37,37,1,3,42,254,159,37,75,0,5,0,16,0,0,1,243,3,32,0,5,0,11,0,17,0,23,0,29,0,148,64,65,1,30,30,64,31,0,22,21,19,10,8,7,27,24,23,20,15,12,11,8,3,0,23,22,23,6,6,7,11,10,11,18,3,18,19,21,8,9,9,10,
20,20,9,2,1,2,4,17,16,2,14,13,29,28,2,25,26,25,0,5,4,1,1,20,70,118,47,55,24,0,63,60,63,60,16,253,60,47,60,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,
46,46,0,46,46,46,46,46,46,49,48,1,73,104,185,0,20,0,30,73,104,97,176,64,82,88,56,17,55,185,0,30,255,192,56,89,1,7,33,39,55,33,1,7,35,19,55,23,19,7,35,39,55,51,1,7,39,19,51,23,1,7,33,39,55,33,1,243,42,
254,249,32,43,1,6,254,186,47,33,42,43,32,210,42,204,32,43,203,254,246,42,32,42,33,36,1,14,42,254,250,33,43,1,6,2,251,38,38,37,254,164,42,1,45,37,37,254,201,37,37,37,254,164,37,37,1,45,42,254,201,37,37,
38,0,0,4,0,12,0,1,1,247,3,32,0,5,0,11,0,17,0,23,0,133,64,57,1,24,24,64,25,0,22,21,10,8,7,23,20,15,12,11,8,3,0,23,22,23,6,6,7,11,10,11,18,3,18,19,21,8,9,9,10,20,20,9,2,1,2,4,17,16,2,14,13,19,0,5,4,1,1,
20,70,118,47,55,24,0,63,60,63,47,60,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,49,48,1,73,104,185,0,20,0,24,73,104,97,176,64,82,88,
56,17,55,185,0,24,255,192,56,89,1,7,33,39,55,33,1,7,35,19,55,23,19,7,35,39,55,51,1,7,39,19,51,23,1,247,43,254,250,32,43,1,6,254,186,48,33,43,42,32,211,43,203,32,42,204,254,239,43,32,49,33,36,2,251,38,
38,37,254,164,42,1,45,37,37,254,201,37,37,37,254,113,37,37,1,96,42,0,6,0,14,0,0,1,245,3,32,0,5,0,11,0,17,0,23,0,28,0,33,0,177,64,82,1,34,34,64,35,28,28,25,16,15,13,10,8,7,32,29,28,26,21,18,17,14,11,8,
3,0,17,16,17,6,6,7,11,10,11,12,3,12,13,15,8,9,9,10,14,14,9,26,25,26,27,3,27,28,24,24,25,28,28,24,2,1,2,4,23,22,2,19,33,29,2,31,30,20,19,0,5,4,1,1,14,70,118,47,55,24,0,63,60,63,60,47,60,253,60,16,253,60,
16,253,60,1,135,46,8,196,8,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,14,0,34,73,104,97,176,64,82,
88,56,17,55,185,0,34,255,192,56,89,1,7,33,39,55,33,1,7,35,19,55,23,3,7,39,19,51,23,1,7,33,39,55,33,55,7,39,19,55,39,7,35,39,55,1,241,42,254,249,32,43,1,6,254,186,47,33,42,42,32,87,42,32,42,33,35,1,15,
42,254,249,32,43,1,6,92,43,32,36,85,12,85,80,32,42,2,251,38,38,37,254,164,42,1,45,37,37,253,146,37,37,1,45,42,254,201,37,37,38,14,37,37,1,3,74,15,74,37,37,0,5,255,242,0,2,2,17,3,30,0,5,0,11,0,17,0,23,
0,29,0,175,64,80,1,30,30,64,31,5,28,27,23,22,8,7,1,0,29,26,23,20,15,12,11,8,5,2,21,21,22,2,1,2,20,19,20,3,3,3,4,23,0,18,18,19,5,5,18,29,28,29,6,6,7,11,10,11,24,3,24,25,27,8,9,9,10,26,26,9,17,16,2,14,13,
25,19,0,10,4,1,1,26,70,118,47,55,24,0,63,60,63,60,47,60,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,0,
46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,26,0,30,73,104,97,176,64,82,88,56,17,55,185,0,30,255,192,56,89,1,35,39,19,55,23,1,7,35,19,55,23,1,7,33,39,55,33,19,7,39,19,55,51,1,7,39,19,51,23,1,224,33,36,
43,43,32,254,102,48,33,50,42,32,1,8,43,254,249,32,42,1,8,33,42,32,43,48,33,254,96,43,32,49,33,36,1,154,42,1,53,37,37,254,203,42,1,95,37,37,254,151,37,37,37,254,114,37,37,1,53,42,254,161,37,37,1,95,42,
0,2,0,170,0,2,1,89,3,30,0,5,0,11,0,105,64,44,1,12,12,64,13,5,10,1,11,8,5,2,9,9,10,2,1,2,8,7,8,3,3,3,4,11,10,11,0,0,1,6,6,7,5,5,6,7,0,4,1,1,8,70,118,47,55,24,0,63,63,1,135,46,8,196,8,196,8,196,8,252,8,
196,8,196,8,196,1,46,46,46,46,0,46,46,49,48,1,73,104,185,0,8,0,12,73,104,97,176,64,82,88,56,17,55,185,0,12,255,192,56,89,1,7,39,19,55,23,3,7,39,19,55,23,1,46,42,32,43,42,32,101,42,32,43,42,32,1,196,37,
37,1,53,37,37,253,46,37,37,1,53,37,37,0,4,255,245,0,0,2,14,3,32,0,5,0,11,0,17,0,23,0,195,64,93,1,24,24,64,25,5,22,19,11,10,7,1,0,23,20,15,12,11,8,5,2,9,9,10,2,1,2,8,7,8,3,3,3,4,11,0,6,6,7,5,5,6,23,22,
23,18,3,18,19,21,21,22,20,20,21,21,22,3,22,23,19,19,20,18,18,19,22,21,22,23,3,19,18,19,15,15,16,20,14,14,20,17,16,2,13,14,13,0,4,1,1,20,70,118,47,55,24,0,63,63,60,16,253,60,1,135,46,14,196,8,196,8,196,
14,252,8,196,135,46,8,196,8,252,14,196,135,46,8,196,8,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,49,48,1,73,104,185,0,20,0,24,73,104,
97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,1,35,39,19,55,23,3,7,39,19,55,51,3,7,33,39,55,33,37,7,39,63,1,23,1,220,32,36,43,43,32,95,42,32,36,48,33,103,43,254,250,32,42,1,7,254,237,43,32,6,42,32,1,
154,42,1,55,37,37,253,94,37,37,1,3,42,254,159,37,37,38,14,37,37,41,38,38,0,5,255,242,0,0,2,17,3,32,0,5,0,11,0,17,0,23,0,29,0,178,64,81,1,30,30,64,31,5,28,27,22,21,8,7,2,1,29,26,23,20,15,12,11,8,5,3,0,
5,0,1,3,4,3,3,4,29,28,29,6,6,7,11,10,11,24,3,24,25,27,8,9,9,10,26,26,9,22,23,3,23,18,20,20,21,19,19,20,14,13,2,17,16,25,19,18,0,10,5,4,1,1,26,70,118,47,55,24,0,63,60,60,63,60,60,47,60,253,60,1,135,46,
8,196,8,252,14,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,14,196,14,252,8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,26,0,30,73,104,97,176,64,
82,88,56,17,55,185,0,30,255,192,56,89,1,3,35,39,19,51,1,7,35,19,55,23,19,7,35,39,55,51,19,35,3,55,51,19,5,7,39,19,51,23,2,7,220,37,25,248,44,254,102,48,33,49,43,32,80,43,79,32,42,80,207,44,147,33,37,130,
254,147,43,32,49,33,36,2,219,254,191,30,1,104,254,164,42,1,95,37,37,254,151,37,37,37,254,75,1,104,30,254,191,30,37,37,1,95,42,0,0,3,0,67,0,0,1,192,3,30,0,5,0,11,0,17,0,120,64,50,1,18,18,64,19,12,10,9,
7,2,1,15,12,11,8,5,2,11,10,11,0,0,1,5,4,5,6,3,6,7,9,2,3,3,4,8,8,3,17,16,2,13,14,13,0,4,1,1,8,70,118,47,55,24,0,63,63,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,
46,0,46,46,46,46,46,49,48,1,73,104,185,0,8,0,18,73,104,97,176,64,82,88,56,17,55,185,0,18,255,192,56,89,19,7,35,19,55,23,3,7,39,19,51,23,1,7,33,39,55,33,192,47,33,49,43,32,95,42,32,42,33,36,1,14,42,254,
249,32,43,1,6,1,196,42,1,95,37,37,253,96,37,37,1,45,42,254,201,37,37,38,0,6,255,241,0,0,2,18,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,222,64,105,1,36,36,64,37,5,34,33,29,28,20,19,16,15,13,12,11,10,8,7,1,0,
35,32,29,26,23,20,17,14,11,8,5,2,27,27,28,2,1,2,26,25,26,3,3,3,4,29,0,24,24,25,5,5,24,6,11,6,7,3,10,9,9,10,35,34,35,18,18,19,23,22,23,30,3,30,31,33,20,21,21,22,32,32,21,13,14,3,14,15,17,17,12,16,16,17,
31,25,0,22,4,1,1,32,70,118,47,55,24,0,63,60,63,60,1,135,46,8,196,8,252,14,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,14,196,14,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,
8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,32,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,1,35,39,19,55,23,15,1,
35,63,1,51,3,35,39,55,51,23,15,1,35,19,55,23,1,7,39,19,55,51,1,7,39,19,51,23,1,225,33,36,43,43,32,124,106,31,12,144,2,179,31,63,20,2,84,142,48,33,50,43,32,1,10,43,32,44,48,33,254,94,43,32,49,33,36,1,155,
41,1,55,37,37,198,155,86,215,254,211,155,146,215,44,41,1,96,37,37,253,42,37,37,1,55,41,254,160,37,37,1,96,41,0,0,5,255,242,0,2,2,17,3,30,0,5,0,11,0,17,0,23,0,29,0,193,64,90,1,30,30,64,31,23,29,28,19,18,
16,15,13,12,8,7,4,3,29,26,23,20,17,14,11,8,5,2,6,6,7,5,4,5,11,10,11,0,3,0,1,8,3,9,9,10,2,2,9,27,27,28,20,19,20,26,25,26,21,3,21,22,29,18,24,24,25,23,23,24,13,14,3,14,15,17,17,12,16,16,17,22,10,1,25,1,
0,1,2,70,118,47,55,24,0,63,60,63,60,1,135,46,8,196,8,252,14,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,0,
46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,2,0,30,73,104,97,176,64,82,88,56,17,55,185,0,30,255,192,56,89,55,7,39,19,51,23,55,7,35,19,55,23,19,35,39,55,51,31,1,35,39,19,55,23,3,7,39,19,55,
51,61,43,32,49,33,36,15,48,33,50,42,32,228,47,175,10,33,188,80,32,36,43,43,32,102,42,32,43,48,33,39,37,37,1,95,42,104,42,1,95,37,37,254,208,203,76,220,106,42,1,53,37,37,253,46,37,37,1,53,42,0,0,6,255,
249,0,0,2,10,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,192,64,89,1,36,36,64,37,23,29,28,25,22,19,18,10,8,7,4,3,1,33,30,29,26,23,20,15,12,11,8,5,2,6,6,7,5,4,5,11,10,11,0,3,0,1,8,3,9,9,10,2,2,9,27,27,28,20,19,
20,26,25,26,21,3,21,22,29,18,24,24,25,23,23,24,14,13,2,16,35,34,2,31,32,31,0,17,16,1,1,2,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,
196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,2,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,
55,7,39,19,51,23,55,7,35,19,55,23,37,7,33,39,55,33,19,35,39,19,55,23,3,7,39,19,55,51,3,7,33,39,55,33,68,43,32,42,33,36,15,48,33,43,42,32,1,66,43,254,250,32,43,1,6,35,33,36,36,43,32,88,42,32,36,48,33,102,
43,254,250,32,43,1,6,89,37,37,1,45,42,104,42,1,45,37,37,52,38,38,37,254,122,42,1,3,37,37,253,146,37,37,1,3,42,254,159,37,37,38,0,5,255,245,0,2,2,14,3,32,0,5,0,10,0,15,0,21,0,27,0,162,64,74,1,28,28,64,
29,5,26,25,14,13,12,4,1,27,24,19,16,15,13,9,6,5,2,2,1,2,3,3,3,4,0,0,1,5,5,0,27,26,27,11,11,12,15,14,15,22,3,22,23,25,13,14,14,15,24,24,14,8,7,2,9,21,20,2,18,17,23,0,10,9,1,1,24,70,118,47,55,24,0,63,60,
63,47,60,253,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,8,252,8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,49,48,1,73,104,185,0,24,0,28,73,104,97,176,
64,82,88,56,17,55,185,0,28,255,192,56,89,1,7,39,19,55,23,39,7,33,39,33,1,7,35,19,23,1,7,33,39,55,33,1,7,39,19,51,23,1,234,42,32,36,42,32,44,43,254,249,64,1,82,254,184,47,33,53,64,1,16,43,254,249,32,42,
1,8,254,176,42,32,49,33,36,1,196,37,37,1,3,37,37,52,38,75,254,164,42,1,119,74,254,201,37,37,37,254,114,37,37,1,95,42,0,0,7,255,249,0,0,2,10,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,39,0,248,64,121,1,40,40,
64,41,23,38,36,29,28,25,22,19,18,10,8,7,4,3,1,39,37,33,30,29,26,23,20,15,12,11,8,5,2,37,36,37,38,4,38,39,29,18,24,24,25,23,23,24,6,6,7,5,4,5,11,10,11,0,3,0,1,8,3,9,9,10,2,2,9,27,27,28,20,19,20,26,25,26,
21,3,21,22,29,18,24,24,25,23,23,24,37,36,37,38,3,38,39,36,36,37,39,39,36,14,13,2,16,35,34,2,31,32,31,0,17,16,1,1,2,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,8,196,8,252,8,196,135,46,8,
196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,
46,46,46,46,46,46,49,48,1,73,104,185,0,2,0,40,73,104,97,176,64,82,88,56,17,55,185,0,40,255,192,56,89,55,7,39,19,51,23,55,7,35,19,55,23,37,7,33,39,55,33,19,35,39,19,55,23,3,7,39,19,55,51,3,7,33,39,55,33,
47,1,55,23,68,43,32,42,33,36,15,48,33,43,42,32,1,66,43,254,250,32,43,1,6,35,33,36,36,43,32,88,42,32,36,48,33,102,43,254,250,32,43,1,6,3,70,19,68,89,37,37,1,45,42,104,42,1,45,37,37,52,38,38,37,254,122,
42,1,3,37,37,253,146,37,37,1,3,42,254,159,37,37,38,34,107,136,118,0,6,255,245,0,0,2,14,3,32,0,5,0,10,0,15,0,21,0,27,0,33,0,191,64,89,1,34,34,64,35,5,32,31,26,25,14,13,12,4,1,33,30,27,24,19,16,15,13,9,
6,5,2,2,1,2,3,3,3,4,0,0,1,5,5,0,33,32,33,11,11,12,15,14,15,28,3,28,29,31,13,14,14,15,30,30,14,26,25,26,27,3,24,23,23,24,8,7,2,9,18,17,2,21,20,29,23,22,0,10,9,1,1,30,70,118,47,55,24,0,63,60,63,60,60,47,
60,253,60,16,253,60,1,135,46,14,196,14,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,8,252,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,49,48,1,
73,104,185,0,30,0,34,73,104,97,176,64,82,88,56,17,55,185,0,34,255,192,56,89,1,7,39,19,55,23,39,7,33,39,33,1,7,35,19,23,1,7,33,39,55,33,19,35,3,55,51,19,37,7,39,19,51,23,1,234,42,32,36,42,32,44,43,254,
249,65,1,83,254,184,47,33,53,64,1,16,43,254,249,32,42,1,8,28,65,240,6,61,243,254,143,42,32,49,33,36,1,196,37,37,1,3,37,37,52,38,75,254,164,42,1,119,74,254,201,37,37,37,254,75,1,45,41,254,207,2,37,37,1,
95,42,0,7,255,249,0,0,2,10,3,32,0,5,0,11,0,17,0,23,0,29,0,35,0,41,0,249,64,124,1,42,42,64,43,5,40,37,28,25,16,13,4,1,41,38,33,30,29,26,21,18,17,14,9,6,5,2,17,16,17,12,3,12,13,15,15,16,14,14,15,26,25,26,
27,3,27,28,24,24,25,29,29,24,41,40,41,36,3,36,37,39,39,40,38,38,39,39,40,3,40,41,37,37,38,36,36,37,1,0,1,2,3,4,3,4,5,11,11,5,40,39,40,41,3,37,36,37,38,32,32,38,8,7,2,10,23,22,2,20,19,35,34,2,31,32,31,
0,11,10,1,1,38,70,118,47,55,24,0,63,60,63,60,16,253,60,47,60,253,60,16,253,60,1,135,46,14,196,8,196,14,252,8,196,135,46,14,196,8,196,14,252,8,196,135,46,8,196,8,252,14,196,135,46,8,196,8,252,8,196,135,
46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,38,0,42,73,104,97,176,64,82,88,56,17,55,185,0,42,255,192,56,89,
1,7,39,63,1,23,39,7,33,39,55,33,1,7,39,19,55,23,1,7,33,39,55,33,19,7,39,19,55,23,3,7,33,39,55,33,37,7,39,63,1,23,2,5,43,32,6,42,32,44,43,254,250,32,42,1,6,254,186,42,32,36,43,32,1,15,43,254,248,32,43,
1,8,40,43,32,37,42,32,97,42,254,250,33,43,1,6,254,237,42,32,5,43,32,2,158,38,38,41,37,37,52,38,38,37,254,164,37,37,1,3,37,37,254,201,37,37,37,254,164,37,37,1,3,37,37,254,201,37,37,38,14,37,37,41,38,38,
0,3,0,49,0,2,1,210,3,32,0,8,0,14,0,20,0,126,64,56,1,21,21,64,22,0,19,13,10,3,20,17,14,11,6,0,20,19,20,9,9,10,14,13,14,15,3,15,16,18,18,19,11,10,11,12,12,13,17,17,12,5,4,2,3,1,2,7,16,0,8,7,1,1,6,70,118,
47,55,24,0,63,60,63,16,253,23,60,1,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,0,46,46,46,46,49,48,1,73,104,185,0,6,0,21,73,104,97,176,64,82,88,56,17,55,185,0,21,255,192,56,89,
1,7,35,39,7,35,39,55,33,3,7,39,19,55,23,3,7,39,19,55,23,1,210,43,119,45,58,120,32,43,1,86,183,43,32,36,43,32,94,43,32,43,43,32,2,251,38,52,52,38,37,254,164,37,37,1,3,37,37,253,96,37,37,1,53,37,37,0,0,
5,255,246,0,0,2,13,3,30,0,5,0,11,0,17,0,23,0,29,0,177,64,81,1,30,30,64,31,29,25,24,23,22,19,10,9,7,2,1,29,26,23,20,15,12,11,8,5,2,11,10,11,0,0,1,5,4,5,6,3,6,7,9,2,3,3,4,8,8,3,26,25,26,21,21,22,20,19,20,
27,3,27,28,24,23,18,18,19,29,29,18,17,16,2,13,14,13,0,28,4,1,1,8,70,118,47,55,24,0,63,60,63,60,16,253,60,1,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,
8,196,1,46,46,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,8,0,30,73,104,97,176,64,82,88,56,17,55,185,0,30,255,192,56,89,19,7,35,19,55,23,3,7,39,19,51,23,1,7,33,39,55,33,
55,7,39,19,55,51,55,35,39,19,55,23,115,47,33,49,43,32,95,42,32,42,33,36,1,14,42,254,250,32,42,1,6,92,43,32,37,47,33,3,33,36,44,42,32,1,196,42,1,95,37,37,253,96,37,37,1,45,42,254,201,37,37,38,14,37,37,
1,3,42,20,42,1,53,37,37,0,0,4,0,7,0,0,1,252,3,30,0,5,0,11,0,17,0,23,0,182,64,88,1,24,24,64,25,5,22,21,17,16,8,7,1,0,23,20,17,14,11,8,5,2,2,3,3,3,4,17,16,17,0,0,1,12,12,13,5,5,12,11,10,11,6,3,6,7,9,9,10,
8,8,9,15,14,15,16,3,16,17,13,12,12,13,22,21,22,23,3,23,18,20,20,21,19,19,20,19,18,14,3,13,0,10,4,1,1,20,70,118,47,55,24,0,63,60,63,23,60,1,135,46,8,196,8,252,8,196,135,46,14,196,8,252,8,196,135,46,8,196,
8,252,8,196,135,46,8,196,8,196,8,196,8,252,14,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,20,0,24,73,104,97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,1,35,39,19,55,
23,1,7,35,19,55,23,1,3,35,55,19,51,1,35,3,55,51,19,1,203,58,13,45,43,32,254,100,21,57,49,42,32,1,52,228,31,14,188,64,254,225,30,132,6,64,106,1,154,31,1,64,37,37,254,192,31,1,95,37,37,254,96,254,167,100,
1,34,254,122,1,89,45,254,222,0,6,255,241,0,0,2,18,3,31,0,5,0,11,0,17,0,23,0,29,0,35,0,222,64,105,1,36,36,64,37,5,34,33,29,28,26,25,22,21,19,18,17,16,8,7,1,0,35,32,29,26,23,20,17,14,11,8,5,2,15,15,16,2,
1,2,14,13,14,3,3,3,4,17,0,12,12,13,5,5,12,35,34,35,6,6,7,11,10,11,30,3,30,31,33,8,9,9,10,32,32,9,27,26,27,28,3,25,24,24,25,22,23,3,23,18,20,20,21,19,19,20,31,13,0,10,4,1,1,32,70,118,47,55,24,0,63,60,63,
60,1,135,46,8,196,8,252,14,196,135,46,14,196,14,252,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,135,46,8,196,14,196,14,196,8,252,8,196,8,196,8,196,1,46,46,46,46,46,46,46,46,46,46,46,46,0,
46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,32,0,36,73,104,97,176,64,82,88,56,17,55,185,0,36,255,192,56,89,1,35,39,19,55,23,1,7,35,19,55,23,1,7,39,19,55,51,3,35,39,55,51,23,39,
7,35,63,1,51,3,7,39,19,51,23,1,224,33,36,44,43,32,254,100,47,34,50,43,32,1,10,43,32,44,47,34,139,2,83,12,31,63,127,144,2,20,107,31,185,43,32,50,33,36,1,154,42,1,54,37,37,254,202,42,1,96,37,37,253,43,37,
37,1,54,42,254,212,215,85,154,69,215,146,154,254,160,37,37,1,96,42,0,4,255,241,0,0,2,18,3,32,0,5,0,11,0,17,0,23,0,168,64,77,1,24,24,64,25,5,23,22,16,15,7,6,2,1,23,20,17,14,11,8,5,2,3,2,3,4,3,1,0,0,1,18,
23,18,19,3,22,21,21,22,10,11,3,11,6,8,8,9,7,7,8,13,14,3,14,15,17,17,12,16,16,17,20,19,13,3,12,0,10,9,5,3,4,1,1,20,70,118,47,55,24,0,63,23,60,63,23,60,1,135,46,8,196,8,252,14,196,135,46,8,196,8,252,14,
196,135,46,14,196,14,252,8,196,135,46,14,196,14,252,8,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,49,48,1,73,104,185,0,20,0,24,73,104,97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,1,3,35,
55,19,51,1,35,3,55,51,27,1,35,3,55,51,19,39,3,35,55,19,51,2,8,210,41,12,200,49,254,230,40,120,10,48,114,157,48,114,11,41,120,193,200,49,10,210,41,2,219,254,191,85,1,49,254,122,1,65,69,254,207,254,17,1,
49,84,254,192,236,254,207,69,1,64,0,0,3,0,32,0,0,1,227,3,32,0,5,0,11,0,17,0,141,64,65,1,18,18,64,19,5,16,7,6,2,1,17,14,11,8,5,2,0,5,0,1,3,4,4,5,3,3,4,17,16,17,12,3,12,13,15,15,16,14,14,15,10,9,10,11,3,
11,6,8,8,9,7,7,8,13,0,10,9,5,3,4,1,1,8,70,118,47,55,24,0,63,23,60,63,1,135,46,8,196,8,252,8,196,135,46,8,196,8,252,8,196,135,46,8,196,14,252,8,196,1,46,46,46,46,46,46,0,46,46,46,46,46,49,48,1,73,104,185,
0,8,0,18,73,104,97,176,64,82,88,56,17,55,185,0,18,255,192,56,89,1,3,35,55,19,51,1,35,3,55,51,19,3,7,39,19,55,23,1,219,213,45,11,196,59,254,225,46,118,8,58,109,15,43,32,43,43,32,2,234,254,175,80,1,55,254,
121,1,81,54,254,201,254,60,37,37,1,54,37,37,0,0,4,0,27,0,0,1,232,3,32,0,5,0,11,0,17,0,23,0,136,64,57,1,24,24,64,25,0,17,16,14,13,11,10,8,7,21,18,17,14,11,8,3,0,6,11,6,7,3,10,9,9,10,15,14,15,16,3,13,12,
12,13,2,1,2,4,23,22,2,19,20,19,0,5,4,1,1,21,70,118,47,55,24,0,63,60,63,60,16,253,60,16,253,60,1,135,46,14,196,14,252,8,196,135,46,14,196,14,252,8,196,1,46,46,46,46,46,46,46,46,0,46,46,46,46,46,46,46,46,
49,48,1,73,104,185,0,21,0,24,73,104,97,176,64,82,88,56,17,55,185,0,24,255,192,56,89,1,7,33,39,55,33,15,1,35,63,1,51,3,7,35,63,1,51,19,7,33,39,55,33,1,232,43,254,240,32,42,1,16,33,117,36,12,148,12,207,
148,12,19,117,36,130,43,254,238,32,43,1,18,2,251,38,38,37,226,164,85,209,254,113,209,130,163,254,160,37,37,38,0,2,0,164,255,219,1,95,3,69,0,5,0,11,0,103,64,42,1,12,12,64,13,5,10,1,11,8,5,2,9,9,10,2,1,
2,8,7,8,3,3,3,4,11,10,11,0,0,1,6,6,7,5,5,6,4,7,1,8,70,118,47,55,24,0,47,47,1,135,46,8,196,8,196,8,196,8,252,8,196,8,196,8,196,1,46,46,46,46,0,46,46,49,48,1,73,104,185,0,8,0,12,73,104,97,176,64,82,88,56,
17,55,185,0,12,255,192,56,89,1,7,39,19,55,23,3,7,39,19,55,23,1,46,42,32,48,43,32,112,43,32,49,42,32,1,196,37,37,1,92,37,37,252,224,37,37,1,92,37,37,0,0,0,0,0,0,0,0,0,134,0,0,0,134,0,0,0,134,0,0,0,134,
0,0,1,100,0,0,2,44,0,0,3,18,0,0,3,128,0,0,4,188,0,0,5,248,0,0,7,38,0,0,8,104,0,0,8,228,0,0,9,64,0,0,9,208,0,0,10,114,0,0,11,190,0,0,12,204,0,0,14,64,0,0,15,74,0,0,16,68,0,0,17,176,0,0,18,238,0,0,19,176,
0,0,21,34,0,0,22,94,0,0,23,70,0,0,24,28,0,0,24,148,0,0,25,24,0,0,25,144,0,0,26,230,0,0,28,44,0,0,29,140,0,0,31,26,0,0,32,86,0,0,33,98,0,0,34,72,0,0,35,126,0,0,36,166,0,0,37,72,0,0,38,108,0,0,39,148,0,
0,40,88,0,0,41,190,0,0,42,240,0,0,44,56,0,0,45,78,0,0,46,220,0,0,48,34,0,0,49,190,0,0,50,146,0,0,51,184,0,0,52,210,0,0,54,56,0,0,55,66,0,0,56,30,0,0,57,2,0,0,57,218,0,0,58,124,0,0,59,86,0,0,59,178,0,0,
60,248,0,0,62,88,0,0,63,230,0,0,65,34,0,0,66,46,0,0,67,20,0,0,68,74,0,0,69,114,0,0,70,20,0,0,71,56,0,0,72,96,0,0,73,36,0,0,74,138,0,0,75,188,0,0,77,4,0,0,78,26,0,0,79,168,0,0,80,238,0,0,82,138,0,0,83,
94,0,0,84,132,0,0,85,158,0,0,87,4,0,0,88,14,0,0,88,234,0,0,89,206,0,0,90,110,0,0,90,110,2,3,0,64,0,0,0,0,2,3,0,0,2,3,0,0,2,3,0,170,2,3,0,161,2,3,255,249,2,3,0,214,2,3,0,124,2,3,0,124,2,3,0,167,2,3,0,101,
2,3,0,212,2,3,0,88,2,3,0,218,2,3,255,241,2,3,255,249,2,3,0,162,2,3,255,244,2,3,0,1,2,3,0,15,2,3,255,250,2,3,0,16,2,3,0,11,2,3,255,249,2,3,0,16,2,3,0,200,2,3,0,194,2,3,0,166,2,3,0,63,2,3,0,166,2,3,0,67,
2,3,255,244,2,3,255,243,2,3,255,249,2,3,255,243,2,3,0,16,2,3,0,12,2,3,0,14,2,3,255,242,2,3,0,170,2,3,255,245,2,3,255,242,2,3,0,67,2,3,255,241,2,3,255,242,2,3,255,249,2,3,255,245,2,3,255,249,2,3,255,245,
2,3,255,249,2,3,0,49,2,3,255,246,2,3,0,7,2,3,255,241,2,3,255,241,2,3,0,32,2,3,0,27,2,3,0,92,2,3,0,89,2,3,0,92,2,3,0,89,2,3,255,244,2,3,255,243,2,3,255,249,2,3,255,243,2,3,0,16,2,3,0,12,2,3,0,14,2,3,255,
242,2,3,0,170,2,3,255,245,2,3,255,242,2,3,0,67,2,3,255,241,2,3,255,242,2,3,255,249,2,3,255,245,2,3,255,249,2,3,255,245,2,3,255,249,2,3,0,49,2,3,255,246,2,3,0,7,2,3,255,241,2,3,255,241,2,3,0,32,2,3,0,27,
2,3,0,164,2,3,0,0,0,2,0,0,0,0,0,0,255,123,0,20,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,90,0,0,0,1,0,2,0,3,0,4,0,5,0,7,0,10,0,11,0,12,0,13,0,14,0,15,0,16,0,17,0,18,0,19,0,20,0,21,0,22,0,23,0,24,0,25,
0,26,0,27,0,28,0,29,0,30,0,31,0,32,0,33,0,34,0,36,0,37,0,38,0,39,0,40,0,41,0,42,0,43,0,44,0,45,0,46,0,47,0,48,0,49,0,50,0,51,0,52,0,53,0,54,0,55,0,56,0,57,0,58,0,59,0,60,0,61,0,62,0,63,0,64,0,66,0,68,
0,69,0,70,0,71,0,72,0,73,0,74,0,75,0,76,0,77,0,78,0,79,0,80,0,81,0,82,0,83,0,84,0,85,0,86,0,87,0,88,0,89,0,90,0,91,0,92,0,93,0,95,0,172,0,0,0,0,0,3,0,0,0,0,0,0,1,36,0,1,0,0,0,0,0,28,0,3,0,1,0,0,1,36,0,
0,1,6,0,0,1,0,0,0,0,0,0,0,0,3,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,4,5,0,6,0,0,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,0,32,33,34,35,36,37,38,39,40,41,42,43,44,
45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,0,61,0,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,0,88,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,89,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
0,0,0,4,1,24,0,0,0,22,0,16,0,3,0,6,0,34,0,36,0,44,0,63,0,93,0,95,0,122,0,124,0,160,32,16,255,255,0,0,0,32,0,36,0,39,0,46,0,65,0,95,0,97,0,124,0,160,32,16,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,22,0,26,0,26,0,36,0,70,0,126,0,126,0,176,0,176,0,176,255,255,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10,0,11,0,12,0,14,0,15,0,16,0,17,0,18,0,19,0,20,0,21,0,22,0,23,0,24,0,25,0,26,0,27,0,28,0,29,0,30,0,31,
0,32,0,33,0,34,0,35,0,36,0,37,0,38,0,39,0,40,0,41,0,42,0,43,0,44,0,45,0,46,0,47,0,48,0,49,0,50,0,51,0,52,0,53,0,54,0,55,0,56,0,57,0,58,0,59,0,60,0,61,0,62,0,63,0,64,0,65,0,66,0,67,0,68,0,69,0,70,0,71,
0,72,0,73,0,74,0,75,0,76,0,77,0,78,0,79,0,80,0,81,0,82,0,83,0,84,0,85,0,86,0,87,0,88,0,89,0,13,0,0,0,0,0,16,0,0,0,92,9,5,5,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,5,5,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,11,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,12,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,13,7,7,0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,14,7,7,0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,15,8,8,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,16,8,8,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,17,9,9,0,9,
9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,18,9,9,0,9,9,9,9,9,9,9,9,9,
9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,19,10,10,0,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,20,10,10,0,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,21,11,11,0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,22,11,11,0,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,23,12,12,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,24,12,12,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
12,0,0,2,3,1,144,0,5,0,1,2,188,2,138,0,0,0,143,2,188,2,138,0,0,1,197,0,50,1,3,0,0,0,0,4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,65,108,116,115,0,64,0,32,32,16,3,69,255,56,0,0,3,69,0,37,0,0,0,1,0,
0,0,1,0,0,79,67,131,157,95,15,60,245,0,0,3,232,0,1,0,0,180,64,97,70,67,224,0,0,180,64,97,70,255,241,255,219,2,18,3,69,0,0,0,3,0,2,0,1,0,0,0,0,0,1,0,0,3,69,255,56,0,0,2,3,255,241,255,241,2,18,0,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,90,0,1,0,0,0,90,0,66,0,10,0,0,0,0,0,2,0,8,0,64,0,10,0,0,0,132,1,3,0,1,0,1,0,0};

const char* TomCartwrightCw3AudioProcessorEditor::lcdm2n___ttf = (const char*) resource_TomCartwrightCw3AudioProcessorEditor_lcdm2n___ttf;
const int TomCartwrightCw3AudioProcessorEditor::lcdm2n___ttfSize = 27480;

// JUCER_RESOURCE: gothic_ttf, 137568, "../Fonts/GOTHIC.TTF"
static const unsigned char resource_TomCartwrightCw3AudioProcessorEditor_gothic_ttf[] = { 0,1,0,0,0,18,1,0,0,4,0,32,68,83,73,71,64,20,212,129,0,2,5,60,0,0,20,36,76,84,83,72,166,218,146,70,0,0,37,112,0,
0,2,158,79,83,47,50,112,246,103,13,0,0,1,168,0,0,0,86,86,68,77,88,112,233,121,163,0,0,40,16,0,0,5,170,99,109,97,112,209,5,166,97,0,0,25,248,0,0,6,62,99,118,116,32,161,73,152,149,0,0,58,0,0,0,4,240,102,
112,103,109,81,228,12,13,0,0,53,60,0,0,4,196,103,97,115,112,0,28,0,9,0,0,2,0,0,0,0,16,103,108,121,102,3,43,252,75,0,0,154,68,0,1,87,188,104,100,109,120,212,9,69,164,0,0,73,88,0,0,80,236,104,101,97,100,
190,200,104,107,0,0,1,44,0,0,0,54,104,104,101,97,15,236,9,9,0,0,1,100,0,0,0,36,104,109,116,120,132,156,24,158,0,0,62,240,0,0,10,104,108,111,99,97,27,142,197,165,0,0,32,56,0,0,5,54,109,97,120,112,6,36,
8,219,0,0,1,136,0,0,0,32,110,97,109,101,33,232,104,62,0,0,2,16,0,0,23,229,112,111,115,116,69,128,193,159,0,1,242,0,0,0,19,57,112,114,101,112,142,216,112,205,0,0,45,188,0,0,7,125,0,1,0,0,0,2,89,154,21,
74,177,36,95,15,60,245,0,27,8,0,0,0,0,0,165,75,30,171,0,0,0,0,178,112,165,32,254,165,253,140,9,56,8,122,0,0,0,11,0,1,0,0,0,0,0,0,0,1,0,0,8,12,254,61,0,0,9,141,254,165,254,164,9,56,0,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,2,154,0,1,0,0,2,154,0,242,0,60,0,70,0,5,0,2,0,16,0,35,0,62,0,0,2,247,7,125,0,3,0,1,0,1,3,227,1,144,0,5,0,0,5,154,5,51,0,0,0,138,5,154,5,51,0,0,2,18,0,102,2,18,2,4,2,11,5,2,2,2,2,2,2,4,0,0,
2,135,0,0,0,0,0,0,0,0,0,0,0,0,77,79,78,79,0,64,0,32,251,2,6,0,254,86,0,229,7,197,1,195,32,0,0,159,223,215,0,0,0,0,0,0,0,3,0,8,0,2,0,21,0,1,255,255,0,3,0,0,0,47,2,58,0,1,0,0,0,0,0,0,0,126,0,0,0,1,0,0,0,
0,0,1,0,14,0,126,0,1,0,0,0,0,0,2,0,7,0,140,0,1,0,0,0,0,0,3,0,29,0,147,0,1,0,0,0,0,0,4,0,14,0,176,0,1,0,0,0,0,0,5,0,12,21,135,0,1,0,0,0,0,0,6,0,13,0,190,0,1,0,0,0,0,0,7,0,62,0,203,0,3,0,1,4,3,0,2,0,12,
1,9,0,3,0,1,4,5,0,2,0,16,1,21,0,3,0,1,4,6,0,2,0,12,1,37,0,3,0,1,4,7,0,2,0,16,1,49,0,3,0,1,4,8,0,2,0,16,1,65,0,3,0,1,4,9,0,0,0,252,1,81,0,3,0,1,4,9,0,1,0,28,2,77,0,3,0,1,4,9,0,2,0,14,2,105,0,3,0,1,4,9,
0,3,0,58,2,119,0,3,0,1,4,9,0,4,0,28,2,177,0,3,0,1,4,9,0,5,0,24,21,147,0,3,0,1,4,9,0,6,0,26,2,205,0,3,0,1,4,9,0,7,0,124,2,231,0,3,0,1,4,9,0,8,0,50,3,99,0,3,0,1,4,9,0,9,0,56,3,149,0,3,0,1,4,9,0,10,3,196,
3,205,0,3,0,1,4,9,0,11,0,102,7,145,0,3,0,1,4,9,0,12,0,104,7,247,0,3,0,1,4,9,0,13,11,206,8,95,0,3,0,1,4,9,0,14,0,92,20,45,0,3,0,1,4,10,0,2,0,12,20,137,0,3,0,1,4,11,0,2,0,16,20,149,0,3,0,1,4,12,0,2,0,12,
20,165,0,3,0,1,4,14,0,2,0,12,20,177,0,3,0,1,4,16,0,2,0,14,20,189,0,3,0,1,4,19,0,2,0,18,20,203,0,3,0,1,4,20,0,2,0,12,20,221,0,3,0,1,4,21,0,2,0,16,20,233,0,3,0,1,4,22,0,2,0,12,20,249,0,3,0,1,4,25,0,2,0,
14,21,5,0,3,0,1,4,27,0,2,0,16,21,19,0,3,0,1,4,29,0,2,0,12,21,35,0,3,0,1,4,31,0,2,0,12,21,47,0,3,0,1,4,36,0,2,0,14,21,59,0,3,0,1,4,45,0,2,0,14,21,73,0,3,0,1,8,10,0,2,0,12,21,87,0,3,0,1,8,22,0,2,0,12,21,
99,0,3,0,1,12,10,0,2,0,12,21,111,0,3,0,1,12,12,0,2,0,12,21,123,84,121,112,101,102,97,99,101,32,169,32,84,104,101,32,77,111,110,111,116,121,112,101,32,67,111,114,112,111,114,97,116,105,111,110,32,112,108,
99,46,32,68,97,116,97,32,169,32,84,104,101,32,77,111,110,111,116,121,112,101,32,67,111,114,112,111,114,97,116,105,111,110,32,112,108,99,32,47,32,84,121,112,101,32,83,111,108,117,116,105,111,110,115,32,
73,110,99,46,32,49,57,57,48,45,57,49,32,65,108,108,32,82,105,103,104,116,115,32,82,101,115,101,114,118,101,100,67,101,110,116,117,114,121,32,71,111,116,104,105,99,82,101,103,117,108,97,114,67,101,110,
116,117,114,121,32,71,111,116,104,105,99,32,82,101,103,117,108,97,114,32,58,32,49,57,57,49,67,101,110,116,117,114,121,32,71,111,116,104,105,99,67,101,110,116,117,114,121,71,111,116,104,105,99,67,101,110,
116,117,114,121,32,71,111,116,104,105,99,32,105,115,32,97,32,116,114,97,100,101,109,97,114,107,32,111,102,32,84,104,101,32,77,111,110,111,116,121,112,101,32,67,111,114,112,111,114,97,116,105,111,110,32,
112,108,99,46,0,78,0,111,0,114,0,109,0,97,0,108,0,111,0,98,0,121,1,13,0,101,0,106,0,110,0,233,0,110,0,111,0,114,0,109,0,97,0,108,0,83,0,116,0,97,0,110,0,100,0,97,0,114,0,100,3,154,3,177,3,189,3,191,3,
189,3,185,3,186,3,172,0,84,0,121,0,112,0,101,0,102,0,97,0,99,0,101,0,32,0,169,0,32,0,84,0,104,0,101,0,32,0,77,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,32,0,67,0,111,0,114,0,112,0,111,0,114,0,97,0,116,
0,105,0,111,0,110,0,32,0,112,0,108,0,99,0,46,0,32,0,68,0,97,0,116,0,97,0,32,0,169,0,32,0,84,0,104,0,101,0,32,0,77,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,32,0,67,0,111,0,114,0,112,0,111,0,114,0,97,
0,116,0,105,0,111,0,110,0,32,0,112,0,108,0,99,0,32,0,47,0,32,0,84,0,121,0,112,0,101,0,32,0,83,0,111,0,108,0,117,0,116,0,105,0,111,0,110,0,115,0,32,0,73,0,110,0,99,0,46,0,32,0,49,0,57,0,57,0,48,0,45,0,
57,0,49,0,32,0,65,0,108,0,108,0,32,0,82,0,105,0,103,0,104,0,116,0,115,0,32,0,82,0,101,0,115,0,101,0,114,0,118,0,101,0,100,0,67,0,101,0,110,0,116,0,117,0,114,0,121,0,32,0,71,0,111,0,116,0,104,0,105,0,99,
0,82,0,101,0,103,0,117,0,108,0,97,0,114,0,67,0,101,0,110,0,116,0,117,0,114,0,121,0,32,0,71,0,111,0,116,0,104,0,105,0,99,0,32,0,82,0,101,0,103,0,117,0,108,0,97,0,114,0,32,0,58,0,32,0,49,0,57,0,57,0,49,
0,67,0,101,0,110,0,116,0,117,0,114,0,121,0,32,0,71,0,111,0,116,0,104,0,105,0,99,0,67,0,101,0,110,0,116,0,117,0,114,0,121,0,71,0,111,0,116,0,104,0,105,0,99,0,67,0,101,0,110,0,116,0,117,0,114,0,121,0,32,
0,71,0,111,0,116,0,104,0,105,0,99,0,32,0,105,0,115,0,32,0,97,0,32,0,116,0,114,0,97,0,100,0,101,0,109,0,97,0,114,0,107,0,32,0,111,0,102,0,32,0,84,0,104,0,101,0,32,0,77,0,111,0,110,0,111,0,116,0,121,0,112,
0,101,0,32,0,67,0,111,0,114,0,112,0,111,0,114,0,97,0,116,0,105,0,111,0,110,0,32,0,112,0,108,0,99,0,46,0,77,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,32,0,84,0,121,0,112,0,111,0,103,0,114,0,97,0,112,
0,104,0,121,0,44,0,32,0,73,0,110,0,99,0,46,0,77,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,32,0,84,0,121,0,112,0,101,0,32,0,68,0,114,0,97,0,119,0,105,0,110,0,103,0,32,0,79,0,102,0,102,0,105,0,99,0,101,
0,65,0,32,0,100,0,101,0,115,0,105,0,103,0,110,0,32,0,98,0,97,0,115,0,101,0,100,0,32,0,111,0,110,0,32,0,77,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,32,0,50,0,48,0,116,0,104,0,32,0,67,0,101,0,110,0,116,
0,117,0,114,0,121,0,44,0,32,0,119,0,104,0,105,0,99,0,104,0,32,0,119,0,97,0,115,0,32,0,100,0,114,0,97,0,119,0,110,0,32,0,98,0,121,0,32,0,83,0,111,0,108,0,32,0,72,0,101,0,115,0,115,0,32,0,98,0,101,0,116,
0,119,0,101,0,101,0,110,0,32,0,49,0,57,0,51,0,54,0,32,0,97,0,110,0,100,0,32,0,49,0,57,0,52,0,55,0,46,0,32,0,67,0,101,0,110,0,116,0,117,0,114,0,121,0,32,0,71,0,111,0,116,0,104,0,105,0,99,0,32,0,109,0,97,
0,105,0,110,0,116,0,97,0,105,0,110,0,115,0,32,0,116,0,104,0,101,0,32,0,98,0,97,0,115,0,105,0,99,0,32,0,100,0,101,0,115,0,105,0,103,0,110,0,32,0,111,0,102,0,32,0,50,0,48,0,116,0,104,0,32,0,67,0,101,0,110,
0,116,0,117,0,114,0,121,0,32,0,98,0,117,0,116,0,32,0,104,0,97,0,115,0,32,0,97,0,110,0,32,0,101,0,110,0,108,0,97,0,114,0,103,0,101,0,100,0,32,0,39,0,120,0,39,0,32,0,104,0,101,0,105,0,103,0,104,0,116,0,
32,0,97,0,110,0,100,0,32,0,104,0,97,0,115,0,32,0,98,0,101,0,101,0,110,0,32,0,109,0,111,0,100,0,105,0,102,0,105,0,101,0,100,0,32,0,116,0,111,0,32,0,101,0,110,0,115,0,117,0,114,0,101,0,32,0,115,0,97,0,116,
0,105,0,115,0,102,0,97,0,99,0,116,0,111,0,114,0,121,0,32,0,111,0,117,0,116,0,112,0,117,0,116,0,32,0,102,0,114,0,111,0,109,0,32,0,109,0,111,0,100,0,101,0,114,0,110,0,32,0,100,0,105,0,103,0,105,0,116,0,
97,0,108,0,32,0,115,0,121,0,115,0,116,0,101,0,109,0,115,0,46,0,32,0,84,0,104,0,101,0,32,0,100,0,101,0,115,0,105,0,103,0,110,0,32,0,105,0,115,0,32,0,105,0,110,0,102,0,108,0,117,0,101,0,110,0,99,0,101,0,
100,0,32,0,98,0,121,0,32,0,116,0,104,0,101,0,32,0,103,0,101,0,111,0,109,0,101,0,116,0,114,0,105,0,99,0,32,0,115,0,116,0,121,0,108,0,101,0,32,0,115,0,97,0,110,0,115,0,32,0,115,0,101,0,114,0,105,0,102,0,
32,0,102,0,97,0,99,0,101,0,115,0,32,0,119,0,104,0,105,0,99,0,104,0,32,0,119,0,101,0,114,0,101,0,32,0,112,0,111,0,112,0,117,0,108,0,97,0,114,0,32,0,100,0,117,0,114,0,105,0,110,0,103,0,32,0,116,0,104,0,
101,0,32,0,49,0,57,0,50,0,48,0,39,0,115,0,32,0,97,0,110,0,100,0,32,0,51,0,48,0,39,0,115,0,46,0,32,0,85,0,115,0,101,0,102,0,117,0,108,0,32,0,102,0,111,0,114,0,32,0,104,0,101,0,97,0,100,0,108,0,105,0,110,
0,101,0,115,0,32,0,97,0,110,0,100,0,32,0,103,0,101,0,110,0,101,0,114,0,97,0,108,0,32,0,100,0,105,0,115,0,112,0,108,0,97,0,121,0,32,0,119,0,111,0,114,0,107,0,32,0,97,0,110,0,100,0,32,0,102,0,111,0,114,
0,32,0,115,0,109,0,97,0,108,0,108,0,32,0,113,0,117,0,97,0,110,0,116,0,105,0,116,0,105,0,101,0,115,0,32,0,111,0,102,0,32,0,116,0,101,0,120,0,116,0,44,0,32,0,112,0,97,0,114,0,116,0,105,0,99,0,117,0,108,
0,97,0,114,0,108,0,121,0,32,0,105,0,110,0,32,0,97,0,100,0,118,0,101,0,114,0,116,0,105,0,115,0,105,0,110,0,103,0,46,0,104,0,116,0,116,0,112,0,58,0,47,0,47,0,119,0,119,0,119,0,46,0,109,0,111,0,110,0,111,
0,116,0,121,0,112,0,101,0,46,0,99,0,111,0,109,0,47,0,104,0,116,0,109,0,108,0,47,0,109,0,116,0,110,0,97,0,109,0,101,0,47,0,109,0,115,0,95,0,119,0,101,0,108,0,99,0,111,0,109,0,101,0,46,0,104,0,116,0,109,
0,108,0,104,0,116,0,116,0,112,0,58,0,47,0,47,0,119,0,119,0,119,0,46,0,109,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,46,0,99,0,111,0,109,0,47,0,104,0,116,0,109,0,108,0,47,0,100,0,101,0,115,0,105,0,103,
0,110,0,101,0,114,0,47,0,100,0,101,0,115,0,95,0,105,0,110,0,100,0,101,0,120,0,46,0,104,0,116,0,109,0,108,0,78,0,79,0,84,0,73,0,70,0,73,0,67,0,65,0,84,0,73,0,79,0,78,0,32,0,79,0,70,0,32,0,76,0,73,0,67,
0,69,0,78,0,83,0,69,0,32,0,65,0,71,0,82,0,69,0,69,0,77,0,69,0,78,0,84,0,13,0,10,0,13,0,10,0,84,0,104,0,105,0,115,0,32,0,116,0,121,0,112,0,101,0,102,0,97,0,99,0,101,0,32,0,105,0,115,0,32,0,116,0,104,0,
101,0,32,0,112,0,114,0,111,0,112,0,101,0,114,0,116,0,121,0,32,0,111,0,102,0,32,0,77,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,32,0,84,0,121,0,112,0,111,0,103,0,114,0,97,0,112,0,104,0,121,0,32,0,97,0,
110,0,100,0,32,0,105,0,116,0,115,0,32,0,117,0,115,0,101,0,32,0,98,0,121,0,32,0,121,0,111,0,117,0,32,0,105,0,115,0,32,0,99,0,111,0,118,0,101,0,114,0,101,0,100,0,32,0,117,0,110,0,100,0,101,0,114,0,32,0,
116,0,104,0,101,0,32,0,116,0,101,0,114,0,109,0,115,0,32,0,111,0,102,0,32,0,97,0,32,0,108,0,105,0,99,0,101,0,110,0,115,0,101,0,32,0,97,0,103,0,114,0,101,0,101,0,109,0,101,0,110,0,116,0,46,0,32,0,89,0,111,
0,117,0,32,0,104,0,97,0,118,0,101,0,32,0,111,0,98,0,116,0,97,0,105,0,110,0,101,0,100,0,32,0,116,0,104,0,105,0,115,0,32,0,116,0,121,0,112,0,101,0,102,0,97,0,99,0,101,0,32,0,115,0,111,0,102,0,116,0,119,
0,97,0,114,0,101,0,32,0,101,0,105,0,116,0,104,0,101,0,114,0,32,0,100,0,105,0,114,0,101,0,99,0,116,0,108,0,121,0,32,0,102,0,114,0,111,0,109,0,32,0,77,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,32,0,111,
0,114,0,32,0,116,0,111,0,103,0,101,0,116,0,104,0,101,0,114,0,32,0,119,0,105,0,116,0,104,0,32,0,115,0,111,0,102,0,116,0,119,0,97,0,114,0,101,0,32,0,100,0,105,0,115,0,116,0,114,0,105,0,98,0,117,0,116,0,
101,0,100,0,32,0,98,0,121,0,32,0,111,0,110,0,101,0,32,0,111,0,102,0,32,0,77,0,111,0,110,0,111,0,116,0,121,0,112,0,101,32,25,0,115,0,32,0,108,0,105,0,99,0,101,0,110,0,115,0,101,0,101,0,115,0,46,0,13,0,
10,0,13,0,10,0,84,0,104,0,105,0,115,0,32,0,115,0,111,0,102,0,116,0,119,0,97,0,114,0,101,0,32,0,105,0,115,0,32,0,97,0,32,0,118,0,97,0,108,0,117,0,97,0,98,0,108,0,101,0,32,0,97,0,115,0,115,0,101,0,116,0,
32,0,111,0,102,0,32,0,77,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,46,0,32,0,85,0,110,0,108,0,101,0,115,0,115,0,32,0,121,0,111,0,117,0,32,0,104,0,97,0,118,0,101,0,32,0,101,0,110,0,116,0,101,0,114,0,
101,0,100,0,32,0,105,0,110,0,116,0,111,0,32,0,97,0,32,0,115,0,112,0,101,0,99,0,105,0,102,0,105,0,99,0,32,0,108,0,105,0,99,0,101,0,110,0,115,0,101,0,32,0,97,0,103,0,114,0,101,0,101,0,109,0,101,0,110,0,
116,0,32,0,103,0,114,0,97,0,110,0,116,0,105,0,110,0,103,0,32,0,121,0,111,0,117,0,32,0,97,0,100,0,100,0,105,0,116,0,105,0,111,0,110,0,97,0,108,0,32,0,114,0,105,0,103,0,104,0,116,0,115,0,44,0,32,0,121,0,
111,0,117,0,114,0,32,0,117,0,115,0,101,0,32,0,111,0,102,0,32,0,116,0,104,0,105,0,115,0,32,0,115,0,111,0,102,0,116,0,119,0,97,0,114,0,101,0,32,0,105,0,115,0,32,0,108,0,105,0,109,0,105,0,116,0,101,0,100,
0,32,0,116,0,111,0,32,0,121,0,111,0,117,0,114,0,32,0,119,0,111,0,114,0,107,0,115,0,116,0,97,0,116,0,105,0,111,0,110,0,32,0,102,0,111,0,114,0,32,0,121,0,111,0,117,0,114,0,32,0,111,0,119,0,110,0,32,0,112,
0,117,0,98,0,108,0,105,0,115,0,104,0,105,0,110,0,103,0,32,0,117,0,115,0,101,0,46,0,32,0,89,0,111,0,117,0,32,0,109,0,97,0,121,0,32,0,110,0,111,0,116,0,32,0,99,0,111,0,112,0,121,0,32,0,111,0,114,0,32,0,
100,0,105,0,115,0,116,0,114,0,105,0,98,0,117,0,116,0,101,0,32,0,116,0,104,0,105,0,115,0,32,0,115,0,111,0,102,0,116,0,119,0,97,0,114,0,101,0,46,0,13,0,10,0,13,0,10,0,73,0,102,0,32,0,121,0,111,0,117,0,32,
0,104,0,97,0,118,0,101,0,32,0,97,0,110,0,121,0,32,0,113,0,117,0,101,0,115,0,116,0,105,0,111,0,110,0,32,0,99,0,111,0,110,0,99,0,101,0,114,0,110,0,105,0,110,0,103,0,32,0,121,0,111,0,117,0,114,0,32,0,114,
0,105,0,103,0,104,0,116,0,115,0,32,0,121,0,111,0,117,0,32,0,115,0,104,0,111,0,117,0,108,0,100,0,32,0,114,0,101,0,118,0,105,0,101,0,119,0,32,0,116,0,104,0,101,0,32,0,108,0,105,0,99,0,101,0,110,0,115,0,
101,0,32,0,97,0,103,0,114,0,101,0,101,0,109,0,101,0,110,0,116,0,32,0,121,0,111,0,117,0,32,0,114,0,101,0,99,0,101,0,105,0,118,0,101,0,100,0,32,0,119,0,105,0,116,0,104,0,32,0,116,0,104,0,101,0,32,0,115,
0,111,0,102,0,116,0,119,0,97,0,114,0,101,0,32,0,111,0,114,0,32,0,99,0,111,0,110,0,116,0,97,0,99,0,116,0,32,0,77,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,32,0,102,0,111,0,114,0,32,0,97,0,32,0,99,0,111,
0,112,0,121,0,32,0,111,0,102,0,32,0,116,0,104,0,101,0,32,0,108,0,105,0,99,0,101,0,110,0,115,0,101,0,32,0,97,0,103,0,114,0,101,0,101,0,109,0,101,0,110,0,116,0,46,0,13,0,10,0,13,0,10,0,77,0,111,0,110,0,
111,0,116,0,121,0,112,0,101,0,32,0,99,0,97,0,110,0,32,0,98,0,101,0,32,0,99,0,111,0,110,0,116,0,97,0,99,0,116,0,101,0,100,0,32,0,97,0,116,0,58,0,13,0,10,0,13,0,10,0,85,0,83,0,65,0,32,0,56,0,52,0,55,0,45,
0,55,0,49,0,56,0,45,0,48,0,52,0,48,0,48,0,32,0,32,0,85,0,75,0,32,0,52,0,52,0,40,0,48,0,41,0,49,0,55,0,51,0,55,0,32,0,55,0,54,0,53,0,57,0,53,0,57,0,13,0,10,0,13,0,10,0,70,0,111,0,114,0,32,0,108,0,105,0,
99,0,101,0,110,0,115,0,101,0,32,0,116,0,101,0,114,0,109,0,115,0,32,0,97,0,110,0,100,0,32,0,117,0,115,0,97,0,103,0,101,0,32,0,114,0,105,0,103,0,104,0,116,0,115,0,44,0,32,0,112,0,108,0,101,0,97,0,115,0,
101,0,32,0,118,0,105,0,115,0,105,0,116,0,32,0,111,0,117,0,114,0,32,0,119,0,101,0,98,0,32,0,115,0,105,0,116,0,101,0,32,0,97,0,116,0,32,0,119,0,119,0,119,0,46,0,109,0,111,0,110,0,111,0,116,0,121,0,112,0,
101,0,46,0,99,0,111,0,109,0,47,0,104,0,116,0,109,0,108,0,47,0,116,0,121,0,112,0,101,0,47,0,108,0,105,0,99,0,101,0,110,0,115,0,101,0,46,0,104,0,116,0,109,0,108,0,13,0,10,0,32,0,13,0,10,0,76,0,105,0,122,
0,101,0,110,0,122,0,98,0,101,0,100,0,105,0,110,0,103,0,117,0,110,0,103,0,101,0,110,0,32,0,117,0,110,0,100,0,32,0,78,0,117,0,116,0,122,0,117,0,110,0,103,0,115,0,114,0,101,0,99,0,104,0,116,0,101,0,32,0,
102,0,105,0,110,0,100,0,101,0,110,0,32,0,83,0,105,0,101,0,32,0,97,0,117,0,102,0,32,0,117,0,110,0,115,0,101,0,114,0,101,0,114,0,32,0,87,0,101,0,98,0,115,0,101,0,105,0,116,0,101,0,32,0,119,0,119,0,119,0,
46,0,109,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,46,0,99,0,111,0,109,0,47,0,104,0,116,0,109,0,108,0,47,0,116,0,121,0,112,0,101,0,47,0,108,0,105,0,99,0,101,0,110,0,115,0,101,0,46,0,104,0,116,0,109,
0,108,0,13,0,10,0,13,0,10,0,80,0,111,0,117,0,114,0,32,0,112,0,108,0,117,0,115,0,32,0,100,0,39,0,105,0,110,0,102,0,111,0,114,0,109,0,97,0,116,0,105,0,111,0,110,0,115,0,32,0,99,0,111,0,110,0,99,0,101,0,
114,0,110,0,97,0,110,0,116,0,32,0,108,0,101,0,115,0,32,0,100,0,114,0,111,0,105,0,116,0,115,0,32,0,100,0,39,0,117,0,116,0,105,0,108,0,105,0,115,0,97,0,116,0,105,0,111,0,110,0,32,0,101,0,116,0,32,0,108,
0,101,0,115,0,32,0,113,0,117,0,101,0,115,0,116,0,105,0,111,0,110,0,115,0,32,0,99,0,111,0,110,0,116,0,114,0,97,0,99,0,116,0,117,0,101,0,108,0,108,0,101,0,115,0,44,0,32,0,118,0,101,0,117,0,105,0,108,0,108,
0,101,0,122,0,32,0,99,0,111,0,110,0,115,0,117,0,108,0,116,0,101,0,122,0,32,0,110,0,111,0,116,0,114,0,101,0,32,0,115,0,105,0,116,0,101,0,32,0,119,0,119,0,119,0,46,0,109,0,111,0,110,0,111,0,116,0,121,0,
112,0,101,0,46,0,99,0,111,0,109,0,47,0,104,0,116,0,109,0,108,0,47,0,116,0,121,0,112,0,101,0,47,0,108,0,105,0,99,0,101,0,110,0,115,0,101,0,46,0,104,0,116,0,109,0,108,0,13,0,10,0,13,0,10,0,80,0,97,0,114,
0,97,0,32,0,111,0,98,0,116,0,101,0,110,0,101,0,114,0,32,0,105,0,110,0,102,0,111,0,114,0,109,0,97,0,99,0,105,0,243,0,110,0,32,0,97,0,99,0,101,0,114,0,99,0,97,0,32,0,100,0,101,0,32,0,108,0,111,0,115,0,32,
0,116,0,233,0,114,0,109,0,105,0,110,0,111,0,115,0,32,0,100,0,101,0,32,0,108,0,105,0,99,0,101,0,110,0,99,0,105,0,97,0,32,0,121,0,32,0,108,0,111,0,115,0,32,0,100,0,101,0,114,0,101,0,99,0,104,0,111,0,115,
0,32,0,100,0,101,0,32,0,117,0,115,0,111,0,44,0,32,0,118,0,105,0,115,0,105,0,116,0,101,0,32,0,110,0,117,0,101,0,115,0,116,0,114,0,111,0,32,0,115,0,105,0,116,0,105,0,111,0,32,0,101,0,110,0,32,0,101,0,108,
0,32,0,87,0,101,0,98,0,32,0,101,0,110,0,32,0,119,0,119,0,119,0,46,0,109,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,46,0,99,0,111,0,109,0,47,0,104,0,116,0,109,0,108,0,47,0,116,0,121,0,112,0,101,0,47,0,
108,0,105,0,99,0,101,0,110,0,115,0,101,0,46,0,104,0,116,0,109,0,108,0,13,0,10,0,13,0,10,0,80,0,101,0,114,0,32,0,108,0,101,0,32,0,99,0,111,0,110,0,100,0,105,0,122,0,105,0,111,0,110,0,105,0,32,0,99,0,111,
0,110,0,116,0,114,0,97,0,116,0,116,0,117,0,97,0,108,0,105,0,32,0,101,0,100,0,32,0,105,0,32,0,100,0,105,0,114,0,105,0,116,0,116,0,105,0,32,0,100,0,39,0,117,0,115,0,111,0,44,0,32,0,118,0,105,0,115,0,105,
0,116,0,97,0,116,0,101,0,32,0,105,0,108,0,32,0,110,0,111,0,115,0,116,0,114,0,111,0,32,0,115,0,105,0,116,0,111,0,32,0,119,0,101,0,98,0,32,0,97,0,108,0,108,0,39,0,105,0,110,0,100,0,105,0,114,0,105,0,122,
0,122,0,111,0,32,0,119,0,119,0,119,0,46,0,109,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,46,0,99,0,111,0,109,0,47,0,104,0,116,0,109,0,108,0,47,0,116,0,121,0,112,0,101,0,47,0,108,0,105,0,99,0,101,0,110,
0,115,0,101,0,46,0,104,0,116,0,109,0,108,0,13,0,10,0,104,0,116,0,116,0,112,0,58,0,47,0,47,0,119,0,119,0,119,0,46,0,109,0,111,0,110,0,111,0,116,0,121,0,112,0,101,0,46,0,99,0,111,0,109,0,47,0,104,0,116,
0,109,0,108,0,47,0,116,0,121,0,112,0,101,0,47,0,108,0,105,0,99,0,101,0,110,0,115,0,101,0,46,0,104,0,116,0,109,0,108,0,78,0,111,0,114,0,109,0,97,0,108,0,78,0,111,0,114,0,109,0,97,0,97,0,108,0,105,0,78,
0,111,0,114,0,109,0,97,0,108,0,78,0,111,0,114,0,109,0,225,0,108,0,78,0,111,0,114,0,109,0,97,0,108,0,101,0,83,0,116,0,97,0,110,0,100,0,97,0,97,0,114,0,100,0,78,0,111,0,114,0,109,0,97,0,108,0,78,0,111,0,
114,0,109,0,97,0,108,0,110,0,121,0,78,0,111,0,114,0,109,0,97,0,108,4,30,4,49,4,75,4,71,4,61,4,75,4,57,0,78,0,111,0,114,0,109,0,225,0,108,0,110,0,101,0,78,0,111,0,114,0,109,0,97,0,108,0,78,0,111,0,114,
0,109,0,97,0,108,0,78,0,97,0,118,0,97,0,100,0,110,0,111,0,65,0,114,0,114,0,117,0,110,0,116,0,97,0,78,0,111,0,114,0,109,0,97,0,108,0,78,0,111,0,114,0,109,0,97,0,108,0,78,0,111,0,114,0,109,0,97,0,108,0,
78,0,111,0,114,0,109,0,97,0,108,86,101,114,115,105,111,110,32,50,46,51,53,0,86,0,101,0,114,0,115,0,105,0,111,0,110,0,32,0,50,0,46,0,51,0,53,0,0,0,0,0,0,2,0,1,0,0,0,0,0,20,0,3,0,1,0,0,1,26,0,0,1,6,0,0,
1,0,0,0,0,0,0,0,1,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,
51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,0,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,
113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,
163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,0,211,212,213,
214,215,216,217,218,219,220,221,222,223,224,225,0,4,5,36,0,0,0,190,0,128,0,6,0,62,0,126,1,127,1,146,1,255,2,199,2,201,2,221,3,126,3,138,3,140,3,161,3,206,4,12,4,79,4,92,4,95,4,145,30,133,30,243,32,21,
32,30,32,34,32,38,32,48,32,51,32,58,32,60,32,62,32,68,32,127,32,164,32,167,32,172,33,5,33,19,33,22,33,34,33,38,33,46,33,94,33,149,33,168,34,2,34,6,34,15,34,18,34,21,34,26,34,31,34,41,34,43,34,72,34,97,
34,101,35,2,35,16,35,33,37,0,37,2,37,12,37,16,37,20,37,24,37,28,37,36,37,44,37,52,37,60,37,108,37,128,37,132,37,136,37,140,37,147,37,161,37,172,37,178,37,186,37,188,37,196,37,203,37,207,37,217,37,230,
38,60,38,64,38,66,38,96,38,99,38,102,38,107,240,6,241,8,251,2,255,255,0,0,0,32,0,160,1,146,1,250,2,198,2,201,2,216,3,126,3,132,3,140,3,142,3,163,4,1,4,14,4,81,4,94,4,144,30,128,30,242,32,19,32,23,32,32,
32,38,32,48,32,50,32,57,32,60,32,62,32,68,32,127,32,163,32,167,32,172,33,5,33,19,33,22,33,34,33,38,33,46,33,91,33,144,33,168,34,2,34,6,34,15,34,17,34,21,34,25,34,30,34,41,34,43,34,72,34,96,34,100,35,2,
35,16,35,32,37,0,37,2,37,12,37,16,37,20,37,24,37,28,37,36,37,44,37,52,37,60,37,80,37,128,37,132,37,136,37,140,37,144,37,160,37,170,37,178,37,186,37,188,37,196,37,202,37,207,37,216,37,230,38,58,38,64,38,
66,38,96,38,99,38,101,38,106,240,0,241,0,251,1,255,255,255,227,0,0,255,20,255,152,0,0,254,17,0,0,252,160,254,20,254,19,254,18,254,17,253,223,253,222,253,221,253,220,253,172,227,190,227,82,0,0,0,0,0,0,
224,133,224,150,225,9,224,133,225,1,226,10,224,120,224,191,0,0,224,152,224,17,224,59,224,46,225,52,223,106,223,121,225,29,224,241,223,178,223,160,222,150,222,162,222,139,0,0,222,167,0,0,0,0,223,33,222,
113,222,95,0,0,222,48,223,78,223,65,223,50,221,84,221,83,221,74,221,71,221,68,221,65,221,62,221,55,221,48,221,41,221,34,221,15,220,252,220,249,220,246,220,243,220,240,0,0,0,0,220,212,220,205,220,204,220,
197,0,0,219,128,220,179,219,106,220,83,220,80,220,79,220,50,220,48,220,47,220,44,0,0,16,49,5,191,0,1,0,0,0,188,0,0,0,0,2,118,0,0,2,118,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,104,2,108,2,122,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,110,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,84,0,0,2,84,2,86,0,0,0,0,0,0,2,82,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,2,42,2,44,0,0,0,0,0,0,0,0,2,40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,22,0,0,0,0,0,0,0,172,0,163,0,132,0,133,2,153,0,150,0,232,0,134,0,142,0,139,0,157,0,169,0,164,0,16,0,138,1,2,0,131,
0,147,0,242,0,243,0,141,0,151,0,136,1,3,0,222,0,241,0,158,0,170,0,245,0,244,0,246,0,162,0,173,0,201,0,199,0,174,0,98,0,99,0,144,0,100,0,203,0,101,0,200,0,202,0,207,0,204,0,205,0,206,0,233,0,102,0,211,
0,208,0,209,0,175,0,103,0,240,0,145,0,214,0,212,0,213,0,104,0,235,0,237,0,137,0,106,0,105,0,107,0,109,0,108,0,110,0,160,0,111,0,113,0,112,0,114,0,115,0,117,0,116,0,118,0,119,0,234,0,120,0,122,0,121,0,
123,0,125,0,124,0,184,0,161,0,127,0,126,0,128,0,129,0,236,0,238,0,186,1,82,1,83,1,5,1,6,1,7,1,8,0,253,0,254,1,84,1,85,1,86,1,87,0,255,1,0,1,9,1,10,1,11,1,1,1,88,1,89,1,90,1,91,1,92,1,93,1,12,1,13,1,14,
1,15,1,94,1,95,0,248,0,249,1,96,1,97,1,98,1,99,1,100,1,101,1,102,1,103,1,104,1,105,1,106,1,107,1,108,1,109,1,110,1,111,0,250,0,215,1,16,1,17,1,112,1,113,1,114,1,115,1,116,1,18,1,19,1,117,1,118,1,20,1,
21,1,22,1,23,0,226,0,227,1,24,1,25,1,119,1,120,1,26,1,27,1,28,1,121,1,122,1,123,1,124,1,125,1,126,1,29,1,30,0,176,0,177,1,31,1,32,1,127,1,128,1,33,1,34,1,35,1,36,1,129,1,130,0,251,0,252,0,228,0,229,1,
37,1,38,1,39,1,40,1,131,1,132,1,133,1,134,1,135,1,136,1,137,1,138,1,41,1,42,1,43,1,44,1,139,1,140,1,141,1,142,1,143,1,144,0,187,1,45,1,46,1,47,1,48,0,230,0,231,1,145,0,216,0,225,0,219,0,220,0,221,0,224,
0,217,0,223,0,178,0,179,2,70,1,58,0,182,0,183,0,196,2,71,0,180,0,181,0,197,0,130,0,194,0,135,0,247,2,73,0,153,0,239,0,195,0,165,0,146,1,73,0,143,1,75,2,132,1,76,1,77,1,78,2,133,0,185,2,138,0,210,0,192,
0,193,1,4,1,81,2,152,0,155,0,0,0,0,0,59,0,59,0,59,0,59,0,134,0,198,1,140,2,144,3,108,4,131,4,158,4,214,5,16,5,110,5,178,5,218,5,253,6,41,6,89,6,208,6,252,7,123,8,30,8,112,8,248,9,133,9,190,10,118,10,251,
11,66,11,133,11,208,12,7,12,84,13,23,14,92,14,201,15,113,15,248,16,99,16,176,16,240,17,141,17,225,18,4,18,87,18,197,18,236,19,185,20,13,20,125,20,237,21,172,22,67,23,21,23,75,23,183,24,7,24,192,25,67,
25,151,25,240,26,38,26,89,26,145,26,220,26,251,27,31,27,178,28,66,28,184,29,72,29,253,30,107,31,44,31,171,32,16,32,162,33,28,33,61,33,228,34,103,34,206,35,94,35,237,36,66,36,249,37,66,37,164,37,251,38,
180,39,43,39,154,39,240,40,88,40,120,40,225,41,52,41,76,41,100,41,119,41,141,41,163,41,187,41,211,41,233,41,255,42,21,42,45,42,67,42,96,42,115,42,137,42,159,42,181,42,205,42,227,42,249,43,15,43,39,43,
61,43,83,43,105,43,127,43,151,43,173,43,195,43,217,43,238,44,6,44,82,44,171,45,116,46,65,46,252,47,39,47,127,48,34,49,34,49,247,50,118,50,149,50,213,51,97,51,213,52,200,53,89,53,179,54,14,54,105,55,7,
55,127,56,3,56,100,56,159,56,239,57,130,57,214,58,51,58,208,60,15,60,246,61,195,62,16,62,58,62,143,63,24,63,164,63,242,64,112,64,238,65,70,65,70,65,92,65,114,65,136,66,87,67,122,67,153,67,184,68,18,68,
109,68,156,68,204,69,28,69,150,69,174,69,198,69,251,70,182,70,254,71,66,71,210,72,103,72,230,73,14,73,62,73,152,74,193,74,215,74,237,75,5,75,29,75,51,75,73,75,95,75,119,75,141,75,163,75,185,75,185,75,
207,75,229,75,251,76,17,76,50,76,139,76,213,76,246,77,42,77,76,77,173,78,18,78,85,78,145,78,229,79,72,79,159,79,181,79,202,79,224,79,245,80,54,80,203,81,115,81,137,81,159,82,28,82,173,82,208,83,76,83,
113,83,222,84,112,84,157,84,202,84,229,85,84,85,106,85,128,85,150,85,168,85,186,85,208,85,230,85,252,86,18,86,202,86,236,87,16,87,89,87,111,87,133,87,152,87,174,87,200,88,95,88,244,89,10,89,32,89,54,89,
76,89,166,90,55,90,77,90,99,90,121,90,199,90,217,90,229,90,251,91,17,91,39,91,61,91,93,91,117,91,141,91,167,91,188,91,210,91,222,91,244,92,9,92,111,92,229,92,251,93,107,93,131,93,155,93,179,93,202,93,
224,93,245,94,12,94,34,94,70,94,198,95,49,95,175,96,55,96,142,96,253,97,43,97,180,97,229,98,16,98,73,98,160,98,228,99,237,100,171,101,45,101,122,101,202,102,24,102,104,102,216,103,81,103,222,104,2,104,
92,104,147,104,190,104,230,105,31,105,86,105,174,105,206,105,224,105,246,106,12,106,34,106,56,106,78,106,96,106,117,106,139,106,163,106,185,106,209,106,231,106,253,107,19,107,41,107,53,107,75,107,97,107,
119,107,208,108,60,108,82,108,104,108,122,108,140,108,162,108,184,108,201,108,219,108,241,109,105,109,123,109,141,110,3,110,24,110,35,110,53,110,71,110,171,111,14,111,32,111,50,111,72,111,94,111,106,111,
123,111,145,111,166,111,230,112,55,112,77,112,99,112,117,112,134,112,156,112,178,112,190,112,202,112,224,112,246,113,12,113,33,113,79,113,115,113,155,113,177,113,199,113,221,113,243,114,33,114,137,114,
161,114,196,114,227,115,3,115,38,115,64,115,101,115,127,115,148,115,156,115,164,115,199,116,28,116,36,116,44,116,52,116,170,116,178,116,186,116,218,116,226,116,234,117,27,117,35,117,73,117,81,117,183,
117,191,117,199,118,108,118,116,118,233,119,132,119,156,119,180,119,198,119,215,119,233,119,251,120,16,120,24,120,169,121,7,121,169,122,76,122,232,123,64,123,181,123,189,124,50,124,154,124,232,124,240,
125,158,125,166,125,229,126,75,126,222,127,83,127,128,127,229,128,110,129,19,129,126,130,54,130,78,130,97,130,115,130,133,130,151,130,175,131,33,131,50,131,61,131,69,131,77,131,101,131,109,132,11,132,
124,132,205,132,222,132,244,133,39,133,47,133,135,133,143,133,175,134,41,134,49,134,195,135,99,135,154,135,176,135,184,135,216,135,224,135,232,135,240,136,23,136,31,136,39,136,47,136,173,137,57,137,65,
137,119,137,187,137,239,138,57,138,155,138,252,139,79,139,218,140,98,140,109,140,117,141,15,141,128,141,167,142,42,142,50,142,215,143,116,143,183,143,205,144,48,144,139,145,96,145,154,145,162,145,204,
145,212,145,220,146,8,146,16,146,204,146,212,147,18,147,81,147,138,147,222,148,52,148,140,148,213,148,232,149,106,149,212,149,236,150,135,150,151,151,22,151,30,151,38,151,62,151,70,151,220,152,62,152,
186,152,203,152,224,153,27,153,66,153,114,153,136,153,158,153,180,153,202,153,226,153,250,154,16,154,38,154,69,154,113,154,141,155,102,156,7,156,95,157,11,157,243,158,240,159,177,159,204,159,237,160,14,
160,47,160,61,160,75,160,91,160,107,160,123,160,139,160,158,160,177,160,196,160,215,160,239,161,3,161,23,161,45,161,67,161,93,161,114,161,136,161,163,161,184,161,206,161,233,161,254,162,19,162,45,162,
69,162,95,162,129,162,153,162,178,162,211,162,237,163,5,163,38,163,64,163,88,163,121,163,155,163,190,163,236,163,250,164,8,164,22,164,36,164,50,164,233,166,62,167,118,167,132,167,145,167,159,167,173,167,
187,167,201,167,243,168,16,168,64,168,162,168,239,169,78,169,136,169,204,169,252,170,59,170,97,170,123,170,167,170,215,171,18,171,222,0,0,0,0,2,154,1,1,1,1,255,1,1,1,1,1,1,246,255,229,229,211,1,254,1,
1,1,1,1,1,1,1,1,1,1,254,211,1,1,1,1,1,187,1,13,1,1,1,1,9,218,1,10,1,158,1,1,1,1,1,13,228,225,213,248,17,250,12,208,1,208,255,1,1,1,1,1,1,1,1,1,1,243,244,12,213,102,1,1,1,1,1,25,200,1,232,151,12,185,1,
250,1,249,1,187,187,13,1,1,1,225,1,1,1,1,1,1,1,1,1,1,1,213,213,213,213,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,154,255,1,1,1,1,1,1,1,1,1,1,173,1,1,165,1,1,1,1,9,254,10,10,1,9,1,1,255,1,1,157,1,1,240,240,130,1,187,
187,1,1,1,1,1,1,1,1,1,115,10,185,250,1,47,48,249,10,10,170,246,1,1,118,187,1,187,1,1,218,218,218,218,1,1,1,1,225,225,225,213,189,1,1,1,1,1,252,1,1,189,1,166,13,25,12,1,1,1,1,250,185,1,1,1,164,1,1,11,1,
1,1,1,1,1,219,13,25,13,1,13,1,1,1,1,16,187,1,187,1,1,1,1,1,1,1,1,1,1,1,243,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,13,25,228,200,228,200,225,1,225,1,12,1,12,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,187,1,13,1,13,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,9,1,219,243,219,243,219,243,219,248,1,251,10,12,12,1,243,1,1,1,1,1,1,1,1,1,1,13,25,1,1,225,1,225,1,225,1,225,1,248,151,250,185,243,187,1,1,9,1,
1,1,1,187,1,1,1,16,1,29,1,243,187,1,1,1,1,12,9,1,219,10,26,158,1,1,1,1,1,1,228,250,25,17,23,1,219,250,1,1,1,243,1,1,1,25,1,1,1,1,1,243,12,1,1,232,1,1,1,1,1,1,15,1,1,17,17,17,243,1,1,1,17,1,1,1,1,13,219,
219,1,1,1,1,10,1,1,187,1,1,1,1,1,1,1,1,1,10,26,158,9,1,1,1,13,228,1,1,17,1,1,1,1,1,1,1,1,1,1,1,1,1,1,17,1,19,1,1,1,1,20,11,1,1,1,1,1,10,185,24,12,1,1,10,1,1,1,1,1,1,13,71,23,1,1,25,248,243,244,1,1,23,
1,185,1,1,1,248,151,248,151,1,151,250,185,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,0,0,0,0,0,1,0,1,1,0,0,0,0,12,0,239,8,255,0,8,0,10,255,254,0,9,0,10,255,253,0,10,0,11,255,252,0,11,0,12,255,252,0,12,0,13,255,252,0,13,0,13,255,252,0,14,0,15,255,252,0,15,0,16,255,252,0,16,0,
17,255,252,0,20,0,19,255,252,0,21,0,20,255,252,0,22,0,21,255,252,0,23,0,23,255,252,0,24,0,25,255,251,0,25,0,26,255,251,0,26,0,27,255,251,0,27,0,28,255,251,0,28,0,29,255,251,0,29,0,30,255,250,0,30,0,31,
255,250,0,31,0,31,255,250,0,32,0,33,255,250,0,33,0,34,255,250,0,38,0,37,255,248,0,39,0,38,255,248,0,40,0,41,255,248,0,41,0,42,255,248,0,42,0,43,255,248,0,43,0,44,255,248,0,44,0,46,255,247,0,45,0,46,255,
247,0,46,0,47,255,247,0,47,0,48,255,247,0,48,0,48,255,246,0,49,0,49,255,246,0,50,0,51,255,246,0,51,0,52,255,246,0,52,0,52,255,246,0,53,0,53,255,246,0,54,0,54,255,245,0,56,0,57,255,244,0,57,0,58,255,244,
0,58,0,59,255,244,0,59,0,60,255,244,0,60,0,61,255,243,0,61,0,62,255,243,0,62,0,64,255,243,0,63,0,64,255,243,0,64,0,65,255,243,0,65,0,66,255,242,0,66,0,66,255,242,0,67,0,67,255,242,0,68,0,69,255,242,0,
69,0,70,255,242,0,71,0,71,255,241,0,72,0,72,255,241,0,73,0,72,255,241,0,74,0,73,255,241,0,75,0,74,255,240,0,76,0,75,255,240,0,77,0,76,255,240,0,78,0,77,255,240,0,79,0,78,255,240,0,80,0,79,255,239,0,81,
0,80,255,239,0,82,0,81,255,239,0,83,0,82,255,239,0,84,0,82,255,239,0,85,0,83,255,238,0,86,0,87,255,238,0,87,0,87,255,238,0,88,0,88,255,238,0,89,0,89,255,238,0,90,0,90,255,238,0,91,0,90,255,237,0,92,0,
91,255,237,0,93,0,92,255,237,0,94,0,93,255,237,0,95,0,94,255,237,0,96,0,95,255,236,0,97,0,97,255,236,0,98,0,97,255,236,0,99,0,98,255,236,0,100,0,99,255,236,0,101,0,100,255,235,0,102,0,100,255,235,0,103,
0,101,255,235,0,104,0,103,255,235,0,105,0,103,255,234,0,106,0,106,255,234,0,107,0,107,255,234,0,108,0,108,255,234,0,109,0,108,255,234,0,110,0,109,255,234,0,111,0,110,255,233,0,112,0,110,255,233,0,113,
0,112,255,233,0,114,0,113,255,233,0,115,0,115,255,233,0,116,0,115,255,232,0,117,0,116,255,232,0,118,0,117,255,232,0,119,0,117,255,232,0,120,0,118,255,232,0,121,0,119,255,231,0,122,0,121,255,231,0,123,
0,121,255,231,0,124,0,122,255,231,0,125,0,125,255,231,0,126,0,126,255,228,0,127,0,126,255,230,0,128,0,127,255,229,0,129,0,128,255,229,0,130,0,128,255,229,0,131,0,130,255,229,0,132,0,131,255,228,0,133,
0,130,255,228,0,134,0,133,255,228,0,135,0,134,255,228,0,136,0,135,255,228,0,137,0,135,255,227,0,138,0,136,255,227,0,139,0,137,255,227,0,140,0,136,255,227,0,141,0,139,255,227,0,142,0,140,255,226,0,143,
0,141,255,226,0,144,0,143,255,226,0,145,0,144,255,226,0,146,0,145,255,226,0,147,0,146,255,225,0,148,0,146,255,225,0,149,0,148,255,225,0,150,0,150,255,225,0,151,0,148,255,223,0,152,0,149,255,223,0,153,
0,149,255,222,0,154,0,150,255,222,0,155,0,153,255,222,0,156,0,152,255,222,0,157,0,153,255,221,0,158,0,156,255,221,0,159,0,155,255,221,0,160,0,156,255,221,0,161,0,156,255,221,0,162,0,159,255,220,0,163,
0,162,255,220,0,164,0,161,255,220,0,165,0,162,255,220,0,166,0,162,255,219,0,167,0,164,255,219,0,168,0,165,255,219,0,169,0,166,255,219,0,170,0,167,255,219,0,171,0,168,255,218,0,172,0,168,255,218,0,173,
0,169,255,218,0,174,0,169,255,218,0,175,0,170,255,217,0,176,0,174,255,217,0,177,0,173,255,217,0,178,0,174,255,217,0,179,0,174,255,217,0,180,0,175,255,216,0,181,0,176,255,216,0,182,0,178,255,216,0,183,
0,181,255,216,0,184,0,182,255,215,0,185,0,182,255,215,0,186,0,183,255,215,0,187,0,183,255,215,0,188,0,184,255,215,0,189,0,186,255,214,0,190,0,186,255,214,0,191,0,187,255,214,0,192,0,188,255,214,0,193,
0,188,255,213,0,194,0,190,255,213,0,195,0,190,255,213,0,196,0,192,255,213,0,197,0,193,255,213,0,198,0,193,255,212,0,199,0,194,255,212,0,200,0,194,255,212,0,201,0,197,255,212,0,202,0,198,255,212,0,203,
0,200,255,211,0,204,0,201,255,211,0,205,0,202,255,211,0,206,0,202,255,211,0,207,0,203,255,210,0,208,0,203,255,210,0,209,0,204,255,210,0,210,0,206,255,210,0,211,0,206,255,210,0,212,0,208,255,209,0,213,
0,208,255,209,0,214,0,209,255,209,0,215,0,210,255,209,0,216,0,210,255,208,0,217,0,212,255,208,0,218,0,213,255,208,0,219,0,213,255,208,0,220,0,216,255,208,0,221,0,217,255,207,0,222,0,218,255,207,0,223,
0,219,255,207,0,224,0,220,255,207,0,225,0,221,255,206,0,226,0,221,255,206,0,227,0,222,255,206,0,228,0,223,255,206,0,229,0,223,255,206,0,230,0,225,255,205,0,231,0,227,255,205,0,232,0,227,255,205,0,233,
0,228,255,205,0,234,0,228,255,204,0,235,0,229,255,204,0,236,0,230,255,204,0,237,0,230,255,204,0,238,0,232,255,204,0,239,0,233,255,203,0,240,0,236,255,203,0,241,0,237,255,203,0,242,0,237,255,203,0,243,
0,238,255,202,0,244,0,240,255,202,0,245,0,240,255,202,0,246,0,241,255,202,0,247,0,241,255,202,0,248,0,242,255,201,0,249,0,244,255,201,0,250,0,244,255,201,0,251,0,246,255,201,0,252,0,247,255,200,0,253,
0,247,255,200,0,254,0,248,255,200,0,255,0,248,255,200,0,0,184,2,114,178,112,55,31,184,2,113,179,93,55,31,221,65,9,2,103,0,38,0,31,2,105,2,103,0,38,0,31,2,104,2,103,178,38,31,55,184,2,111,180,181,200,31,
55,79,65,23,2,107,0,95,2,107,0,111,2,107,0,127,2,107,0,143,2,107,0,159,2,107,0,175,2,107,0,7,2,107,2,103,0,38,0,31,2,106,2,103,0,60,0,31,2,103,179,94,22,31,64,65,53,2,97,0,80,2,97,0,96,2,97,0,112,2,97,
0,4,0,0,2,97,0,16,2,97,0,32,2,97,0,48,2,97,0,4,0,208,2,97,0,224,2,97,0,240,2,97,0,3,0,0,2,97,0,16,2,97,0,32,2,97,0,48,2,97,0,4,0,192,2,97,0,208,2,97,0,224,2,97,0,240,2,97,0,4,0,176,2,87,0,240,2,87,0,2,
0,0,2,87,0,64,2,87,0,112,2,87,64,84,3,16,24,16,25,32,24,32,25,64,24,64,25,6,9,0,24,0,25,2,8,0,20,0,21,16,20,16,21,4,9,0,20,0,21,2,8,63,0,63,1,2,207,0,207,1,255,0,255,1,4,95,0,95,1,143,0,143,1,4,32,0,32,
1,79,0,79,1,4,0,0,0,1,240,0,240,1,4,113,173,10,31,113,173,65,9,255,182,0,10,0,22,1,87,1,118,0,3,0,31,1,87,1,118,180,6,3,22,149,142,184,1,48,179,34,22,149,142,184,1,48,179,34,22,139,123,184,1,51,179,64,
22,139,123,184,1,51,179,64,22,139,123,184,1,51,179,64,22,139,123,184,1,51,64,12,64,22,0,70,70,0,0,0,18,21,8,64,189,1,242,1,130,1,131,0,13,0,219,1,131,178,13,0,9,184,1,142,178,112,48,31,65,9,1,133,0,112,
2,154,0,31,1,132,0,101,2,154,0,31,1,127,179,111,246,58,22,184,1,48,178,112,37,31,184,1,47,178,112,39,31,65,10,1,41,0,249,11,218,2,154,0,22,1,40,0,105,2,154,0,31,1,35,179,111,194,46,22,184,1,34,64,10,111,
194,46,22,252,112,46,31,217,92,184,2,154,182,31,197,112,89,31,182,105,184,5,52,64,12,31,181,111,211,50,22,141,112,46,31,140,111,184,5,52,183,31,130,111,194,46,22,127,105,184,5,52,178,31,121,111,184,1,
218,179,111,22,99,249,184,2,154,183,31,93,111,177,42,22,91,111,185,5,152,1,77,178,22,86,249,185,11,218,2,154,178,22,85,111,187,11,52,2,154,0,22,1,138,178,94,45,31,184,1,136,178,94,71,31,184,1,135,178,
94,96,31,184,1,43,178,94,167,31,189,1,39,0,122,4,165,1,11,0,22,1,33,64,10,88,242,61,22,250,94,84,31,248,88,184,1,232,64,18,122,22,247,88,206,52,22,218,94,103,31,214,88,169,43,22,194,122,185,7,188,1,188,
183,22,192,88,177,45,22,171,122,185,11,156,2,154,182,22,148,94,191,31,144,88,184,2,157,179,167,22,126,122,185,5,204,1,77,183,22,106,88,242,61,22,98,122,184,3,220,179,222,22,97,88,184,2,154,64,13,31,70,
0,70,2,70,5,85,20,9,20,9,144,190,2,119,0,7,0,144,2,118,0,7,0,144,1,166,64,83,7,144,229,7,144,165,7,144,128,7,144,117,7,144,108,7,144,107,7,144,100,7,144,90,7,144,87,7,36,8,34,8,32,8,30,8,28,8,26,8,24,
8,22,8,20,8,18,8,16,8,14,8,12,8,10,8,8,8,6,8,4,8,2,8,0,8,0,15,31,47,31,63,31,111,31,191,31,239,31,240,31,7,192,185,1,242,0,1,1,176,19,3,75,2,75,83,66,1,75,176,192,99,0,75,98,32,176,246,83,35,184,1,10,
81,90,176,5,35,66,1,176,18,75,0,75,84,66,176,56,43,75,184,8,0,82,176,55,43,75,176,8,80,91,88,177,1,1,142,89,176,2,136,184,1,0,84,88,184,1,25,177,1,1,142,133,27,176,18,67,88,185,0,1,1,37,133,141,27,185,
0,1,1,255,133,141,89,89,1,116,0,115,22,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,24,1,43,43,43,43,43,43,43,43,43,43,43,43,1,75,80,121,188,0,31,1,80,0,7,0,31,1,50,179,7,31,104,7,43,43,43,
75,83,121,188,0,144,1,80,0,7,0,144,1,50,179,7,144,104,7,43,43,43,24,29,176,150,75,83,88,176,170,29,89,176,50,75,83,88,176,255,29,89,75,176,167,83,32,92,88,185,1,244,1,242,69,68,185,1,243,1,242,69,68,89,
88,185,2,219,1,244,69,82,88,185,1,244,2,219,68,89,89,75,184,1,11,83,32,92,88,185,0,101,1,243,69,68,185,0,112,1,243,69,68,89,88,185,4,206,0,101,69,82,88,185,0,101,4,206,68,89,89,75,184,2,154,83,32,92,88,
185,0,92,1,244,69,68,185,0,105,1,244,69,68,89,88,185,11,93,0,92,69,82,88,185,0,92,11,93,68,89,89,75,184,2,154,83,32,92,88,177,111,92,69,68,177,92,92,69,68,89,88,185,11,93,0,111,69,82,88,185,0,111,11,93,
68,89,89,75,184,5,52,83,32,92,88,177,249,101,69,68,177,101,101,69,68,89,88,185,23,226,0,249,69,82,88,185,0,249,23,226,68,89,89,0,75,176,89,83,32,92,88,177,88,88,69,68,177,94,88,69,68,89,88,185,1,99,0,
88,69,82,88,185,0,88,1,99,68,89,89,75,176,96,83,32,92,88,177,88,88,69,68,177,122,88,69,68,89,88,185,1,127,0,88,69,82,88,185,0,88,1,127,68,89,89,75,184,2,154,83,32,92,88,177,88,88,69,68,177,88,88,69,68,
89,88,185,10,121,0,88,69,82,88,185,0,88,10,121,68,89,89,1,112,75,184,1,243,83,88,178,70,33,70,69,139,68,89,75,184,3,231,83,88,178,70,97,70,69,139,68,89,178,112,101,70,69,104,35,69,96,68,112,75,184,1,243,
83,88,178,70,33,70,69,139,68,89,75,184,3,231,83,88,178,70,97,70,69,139,68,89,178,105,92,70,69,104,35,69,96,68,112,75,184,1,243,83,88,178,70,33,70,69,139,68,89,75,184,3,231,83,88,178,70,97,70,69,139,68,
89,178,111,249,70,69,104,35,69,96,68,0,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,1,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,101,66,43,43,179,102,174,
120,131,69,101,35,69,96,35,69,101,96,35,69,96,176,139,118,104,24,176,128,98,32,32,177,120,174,69,101,35,69,32,176,3,38,96,98,99,104,32,176,3,38,97,101,176,174,35,101,68,176,120,35,68,32,177,102,131,69,
101,35,69,32,176,3,38,96,98,99,104,32,176,3,38,97,101,176,131,35,101,68,176,102,35,68,177,0,131,69,84,88,177,131,64,101,68,178,102,64,102,69,35,97,68,89,179,123,118,96,133,69,101,35,69,96,35,69,101,96,
35,69,96,176,137,118,104,24,176,128,98,32,32,177,96,118,69,101,35,69,32,176,3,38,96,98,99,104,32,176,3,38,97,101,176,118,35,101,68,176,96,35,68,32,177,123,133,69,101,35,69,32,176,3,38,96,98,99,104,32,
176,3,38,97,101,176,133,35,101,68,176,123,35,68,177,0,133,69,84,88,177,133,64,101,68,178,123,64,123,69,35,97,68,89,1,69,105,83,66,1,75,80,88,177,8,0,66,89,67,92,88,177,8,0,66,89,179,2,11,10,18,67,88,96,
27,33,89,66,22,16,112,62,176,18,67,88,185,59,33,24,126,27,186,4,0,1,168,0,11,43,89,176,12,35,66,176,13,35,66,176,18,67,88,185,45,65,45,65,27,186,4,0,4,0,0,11,43,89,176,14,35,66,176,15,35,66,176,18,67,
88,185,24,126,59,33,27,186,1,168,4,0,0,11,43,89,176,16,35,66,176,17,35,66,1,1,43,43,43,43,43,43,43,43,43,43,0,115,116,116,116,117,94,115,94,115,94,115,94,115,115,115,115,116,116,117,117,0,43,43,43,117,
43,43,1,43,43,43,43,43,1,43,0,176,3,69,104,184,2,94,69,104,176,64,139,96,176,32,35,68,176,7,69,104,184,2,95,69,104,176,64,139,96,176,34,35,68,0,0,0,64,59,60,59,58,57,56,55,52,51,50,49,48,47,46,45,44,43,
42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,44,69,35,70,96,32,176,38,96,176,4,38,35,72,72,45,44,69,35,70,35,97,32,176,38,97,176,
4,38,35,72,72,45,44,69,35,70,96,176,32,97,32,176,70,96,176,4,38,35,72,72,45,44,69,35,70,35,97,176,32,96,32,176,38,97,176,32,97,176,4,38,35,72,72,45,44,69,35,70,96,176,64,97,32,176,102,96,176,4,38,35,72,
72,45,44,69,35,70,35,97,176,64,96,32,176,38,97,176,64,97,176,4,38,35,72,72,45,44,1,16,32,60,0,60,45,44,32,69,35,32,176,205,68,35,32,184,1,90,81,88,35,32,176,141,68,35,89,32,176,237,81,88,35,32,176,77,
68,35,89,32,176,4,38,81,88,35,32,176,13,68,35,89,33,33,45,44,32,32,69,24,104,68,32,176,1,96,32,69,176,70,118,104,138,69,96,68,45,44,1,177,11,10,67,35,67,101,10,45,44,0,177,10,11,67,35,67,11,45,44,0,176,
70,35,112,177,1,70,62,1,176,70,35,112,177,2,70,69,58,177,2,0,8,13,45,44,69,176,74,35,68,69,176,73,35,68,45,44,32,69,176,3,37,69,97,100,176,80,81,88,69,68,27,33,33,89,45,44,176,1,67,99,35,98,176,0,35,66,
176,15,43,45,44,32,69,176,0,67,96,68,45,44,1,176,6,67,176,7,67,101,10,45,44,32,105,176,64,97,176,0,139,32,177,44,192,138,140,184,16,0,98,96,43,12,100,35,100,97,92,88,176,3,97,89,45,44,69,176,17,43,176,
71,35,68,176,71,122,228,24,45,44,184,1,166,84,88,176,9,67,184,1,0,84,88,185,0,74,255,128,177,73,128,68,68,89,89,45,44,176,18,67,88,135,69,176,17,43,176,71,35,68,176,71,122,228,27,3,138,69,24,105,32,176,
71,35,68,138,138,135,32,176,160,81,88,176,17,43,176,71,35,68,176,71,122,228,27,33,176,71,122,228,89,89,24,45,44,45,44,75,82,88,33,69,68,27,35,69,140,32,176,3,37,69,82,88,68,27,33,33,89,89,45,44,1,24,47,
45,44,32,176,3,37,69,176,73,35,68,69,176,74,35,68,69,101,35,69,32,176,3,37,96,106,32,176,9,35,66,35,104,138,106,96,97,32,176,26,138,176,0,82,121,33,178,26,74,64,185,255,224,0,74,69,32,138,84,88,35,33,
176,63,27,35,89,97,68,28,177,20,0,138,82,121,179,73,64,32,73,69,32,138,84,88,35,33,176,63,27,35,89,97,68,45,44,177,16,17,67,35,67,11,45,44,177,14,15,67,35,67,11,45,44,177,12,13,67,35,67,11,45,44,177,12,
13,67,35,67,101,11,45,44,177,14,15,67,35,67,101,11,45,44,177,16,17,67,35,67,101,11,45,44,75,82,88,69,68,27,33,33,89,45,44,1,32,176,3,37,35,73,176,64,96,176,32,99,32,176,0,82,88,35,176,2,37,56,35,176,2,
37,101,56,0,138,99,56,27,33,33,33,33,33,89,1,45,44,69,105,176,9,67,96,138,16,58,45,44,1,176,5,37,16,35,32,138,245,0,176,1,96,35,237,236,45,44,1,176,5,37,16,35,32,138,245,0,176,1,97,35,237,236,45,44,1,
176,6,37,16,245,0,237,236,45,44,32,176,1,96,1,16,32,60,0,60,45,44,32,176,1,97,1,16,32,60,0,60,45,44,176,43,43,176,42,42,45,44,0,176,7,67,176,6,67,11,45,44,62,176,42,42,45,44,53,45,44,118,176,75,35,112,
16,32,176,75,69,32,176,0,80,88,176,1,97,89,58,47,24,45,44,33,33,12,100,35,100,139,184,64,0,98,45,44,33,176,128,81,88,12,100,35,100,139,184,32,0,98,27,178,0,64,47,43,89,176,2,96,45,44,33,176,192,81,88,
12,100,35,100,139,184,21,85,98,27,178,0,128,47,43,89,176,2,96,45,44,12,100,35,100,139,184,64,0,98,96,35,33,45,44,180,0,1,0,0,0,21,176,8,38,176,8,38,176,8,38,176,8,38,15,16,22,19,69,104,58,176,1,22,45,
44,180,0,1,0,0,0,21,176,8,38,176,8,38,176,8,38,176,8,38,15,16,22,19,69,104,101,58,176,1,22,45,44,69,35,32,69,32,177,4,5,37,138,80,88,38,97,138,139,27,38,96,138,140,89,68,45,44,70,35,70,96,138,138,70,35,
32,70,138,96,138,97,184,255,128,98,35,32,16,35,138,177,75,75,138,112,69,96,32,176,0,80,88,176,1,97,184,255,192,139,27,176,64,140,89,104,1,58,45,44,176,51,43,176,42,42,45,44,176,19,67,88,3,27,2,89,45,44,
176,19,67,88,2,27,3,89,45,44,75,83,35,75,81,90,88,56,27,33,33,89,45,44,1,176,4,37,176,4,37,73,100,35,69,100,105,97,32,176,128,98,106,176,2,37,176,2,37,97,140,176,73,35,68,33,138,16,176,73,246,33,45,44,
1,176,2,37,16,208,35,201,1,176,1,19,176,0,20,16,176,1,60,176,1,22,45,44,1,176,0,19,176,1,176,3,37,73,176,3,23,56,176,1,19,45,5,228,0,28,5,191,0,37,5,191,0,37,4,64,0,28,0,0,255,219,0,0,255,228,0,0,255,
219,254,114,255,228,5,228,0,28,254,114,255,228,3,42,255,240,5,211,0,16,2,221,255,238,5,210,0,18,255,247,255,238,2,236,0,18,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,0,0,2,126,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,0,142,0,0,0,142,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
136,0,144,0,219,0,129,0,56,1,173,0,134,0,140,0,106,0,144,0,115,0,104,0,131,0,137,0,146,2,112,0,147,0,177,0,181,1,179,0,142,0,107,0,110,1,53,0,53,0,152,0,138,0,152,255,132,255,197,0,12,0,246,1,33,255,112,
0,81,0,115,0,126,0,143,0,156,0,248,0,10,0,139,0,143,0,216,0,4,0,109,255,140,4,109,255,152,0,12,0,22,0,62,0,65,0,115,0,135,0,139,0,181,1,39,3,244,0,121,0,144,0,93,0,105,0,151,0,255,255,59,255,97,255,163,
255,211,0,16,0,43,1,19,0,0,0,53,0,58,0,84,0,109,0,202,0,218,0,246,2,165,255,186,0,6,0,23,0,33,0,88,0,141,0,184,254,247,255,78,255,171,0,13,0,23,0,49,0,73,0,89,0,111,0,143,4,9,255,188,0,8,0,10,0,12,0,13,
0,24,0,61,0,84,0,99,0,127,0,140,0,143,0,151,0,167,0,179,1,114,1,161,2,30,2,59,3,50,3,228,255,187,255,236,255,252,0,12,0,17,0,25,0,56,0,70,0,83,0,98,0,138,0,139,0,140,0,157,0,157,0,194,0,196,1,4,1,52,1,
72,1,80,1,101,1,170,1,181,1,199,2,96,2,104,2,124,2,210,3,148,3,181,254,223,255,202,255,229,0,1,0,3,0,20,0,26,0,28,0,77,0,78,0,84,0,103,0,118,0,146,0,160,0,165,0,181,0,201,0,228,1,18,1,47,1,71,1,97,1,105,
1,178,1,196,2,12,2,38,2,114,2,178,2,197,2,197,3,6,3,74,3,79,3,147,4,24,6,13,253,151,255,26,255,166,255,224,255,236,0,32,0,32,0,54,0,55,0,67,0,73,0,75,0,78,0,86,0,90,0,107,0,109,0,109,0,111,0,116,0,122,
0,138,0,142,0,144,0,148,0,152,0,157,0,167,0,178,0,187,0,188,0,205,0,211,0,212,0,227,0,231,0,231,1,31,1,35,1,47,1,56,1,66,1,71,1,77,1,80,1,92,1,114,1,131,1,145,1,181,1,201,1,202,1,208,1,219,1,230,1,245,
2,15,2,38,2,53,2,64,2,67,2,109,2,114,2,119,2,169,2,170,2,179,2,183,2,201,2,237,3,6,3,9,3,36,3,89,3,112,3,117,3,138,3,223,3,230,4,0,4,20,4,86,4,113,4,116,4,215,5,215,6,35,7,114,252,5,254,45,254,198,254,
229,255,127,255,219,255,231,0,4,0,61,0,69,0,78,0,79,0,88,0,90,0,90,0,93,0,93,0,103,0,103,0,105,0,108,0,115,0,129,0,138,0,141,0,142,0,147,0,152,0,155,0,158,0,163,0,166,0,174,0,178,0,179,0,179,0,180,0,191,
0,196,0,196,0,201,0,202,0,211,0,226,0,227,0,252,1,0,1,10,1,27,1,32,1,41,1,44,1,53,1,62,1,72,1,86,1,101,1,121,1,122,1,137,1,140,1,141,1,145,1,164,1,171,1,199,1,211,1,228,1,241,1,242,1,250,1,253,2,7,2,15,
2,16,2,33,2,90,2,94,2,103,2,114,2,122,2,138,2,148,2,151,2,225,3,34,3,39,3,39,3,66,3,70,3,94,3,101,3,113,3,165,3,169,3,173,3,194,3,242,3,251,4,0,4,4,4,62,4,82,4,82,4,83,4,109,4,131,4,176,4,206,5,0,5,23,
5,38,5,68,5,82,5,85,5,137,5,138,5,158,5,198,6,35,6,76,6,91,6,122,6,148,6,172,6,172,6,238,7,68,7,162,7,170,8,24,8,35,8,55,8,81,8,198,8,244,0,141,0,148,0,140,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,230,2,90,0,107,
1,57,0,205,0,81,0,154,1,183,0,205,1,246,1,25,1,46,0,231,1,64,0,49,0,235,1,14,1,156,0,151,0,176,0,79,0,121,0,172,0,228,0,70,0,213,255,49,0,164,0,119,0,254,0,108,0,136,0,117,0,195,0,144,2,30,1,8,4,36,0,
180,255,28,1,179,1,102,1,155,1,34,0,191,1,5,0,212,0,231,1,0,0,67,0,64,0,198,2,230,0,121,0,53,1,80,1,105,1,53,0,167,2,5,0,158,0,249,1,10,1,94,1,12,0,233,1,3,1,140,0,180,0,107,0,21,0,61,0,192,0,157,0,197,
0,204,0,89,0,55,0,17,1,50,0,174,1,82,0,198,0,32,255,63,3,142,0,167,1,23,0,81,1,75,252,164,2,64,0,225,0,236,0,253,254,165,0,139,1,228,0,116,0,150,1,133,0,246,0,178,1,84,0,172,0,27,2,168,0,174,0,194,0,208,
0,154,0,138,4,38,4,231,0,103,0,109,0,75,0,94,0,169,0,102,0,102,0,0,1,204,1,94,6,0,1,0,0,0,0,0,2,55,0,0,2,55,0,0,2,92,0,179,2,121,0,48,5,195,0,184,4,111,0,72,6,51,0,46,6,14,0,179,1,149,0,129,2,244,1,11,
2,244,0,124,3,102,0,88,4,217,0,115,2,55,0,128,2,168,0,65,2,55,0,187,3,127,0,72,4,111,0,65,4,111,1,35,4,111,0,61,4,111,0,72,4,111,0,52,4,111,0,83,4,111,0,138,4,111,0,147,4,111,0,69,4,111,0,100,2,55,0,187,
2,55,0,128,4,217,0,104,4,217,0,115,4,217,0,104,4,186,0,170,6,240,0,137,5,235,0,49,4,152,0,183,6,129,0,111,5,244,0,179,4,74,0,180,3,225,0,179,6,250,0,117,5,119,0,177,1,207,0,158,3,219,0,86,4,186,0,179,
3,178,0,179,7,90,0,112,5,235,0,180,6,244,0,115,4,188,0,178,6,248,0,117,4,219,0,187,3,252,0,27,3,104,0,33,5,61,0,184,5,158,0,67,7,174,0,96,4,223,0,69,4,188,0,63,3,215,0,56,2,207,1,34,4,215,0,66,2,207,0,
93,5,96,0,120,4,0,255,244,3,6,0,111,5,119,0,107,5,117,0,165,5,45,0,105,5,123,0,109,5,51,0,104,2,131,0,79,5,98,0,100,4,225,0,156,1,154,0,90,1,160,255,192,4,4,0,155,1,154,0,135,7,129,0,155,4,225,0,156,5,
61,0,104,5,117,0,158,5,117,0,106,2,104,0,103,3,27,0,54,2,182,0,87,4,221,0,138,4,111,0,53,6,166,0,9,3,215,255,249,4,74,0,39,3,102,0,9,2,207,0,75,5,96,2,104,2,207,0,65,4,217,0,112,5,235,0,49,5,235,0,49,
6,129,0,111,4,74,0,180,5,235,0,180,6,244,0,115,5,61,0,184,5,119,0,107,5,119,0,107,5,119,0,107,5,119,0,107,5,119,0,107,5,119,0,107,5,45,0,105,5,51,0,104,5,51,0,104,5,51,0,104,5,51,0,104,1,154,0,55,1,154,
255,185,1,154,255,98,1,154,255,141,4,225,0,156,5,61,0,104,5,61,0,104,5,61,0,104,5,61,0,104,5,61,0,104,4,221,0,138,4,221,0,138,4,221,0,138,4,221,0,138,4,109,0,157,3,51,0,65,4,111,0,103,4,111,0,57,4,235,
0,130,4,217,1,57,4,131,0,94,4,111,0,162,5,250,255,236,5,250,255,236,8,0,0,12,3,0,0,234,2,244,0,58,4,100,0,56,7,240,0,1,6,242,0,114,5,180,0,152,4,100,0,56,4,100,0,46,4,100,0,46,4,111,0,62,4,156,0,147,3,
244,0,56,5,180,0,122,6,149,0,162,4,100,0,0,2,49,0,0,2,244,0,57,2,244,0,55,6,37,0,127,9,66,0,120,5,57,0,102,4,186,0,183,2,92,0,179,4,217,0,115,4,100,0,81,4,111,0,32,4,100,0,54,4,229,0,26,3,102,0,21,3,102,
0,21,8,0,0,218,2,61,0,0,5,235,0,49,5,235,0,49,6,244,0,115,9,141,0,114,9,25,0,112,4,0,255,244,8,0,255,244,4,4,0,204,3,223,0,181,2,207,1,30,2,207,0,252,4,100,0,56,3,244,0,47,4,74,0,39,4,188,0,63,1,84,254,
165,4,111,0,47,2,2,0,75,2,2,0,70,3,229,0,84,3,225,0,92,4,109,0,159,2,55,0,161,2,213,0,255,4,4,0,198,9,100,0,49,5,235,0,49,4,74,0,180,5,235,0,49,4,74,0,180,4,74,0,180,1,207,0,81,1,207,255,124,1,207,255,
168,1,207,255,212,6,244,0,115,6,244,0,115,6,81,0,0,6,244,0,115,5,61,0,184,5,61,0,184,5,61,0,184,1,154,0,135,4,4,0,151,3,131,0,83,3,225,0,152,3,160,0,110,1,199,0,112,2,168,0,127,2,152,0,139,4,106,1,1,2,
106,0,190,4,4,0,151,4,35,0,89,2,102,0,53,3,252,0,27,3,27,0,34,3,215,0,56,3,102,0,9,5,96,2,104,6,82,0,34,5,61,0,105,4,188,0,63,4,74,0,39,4,188,0,178,5,117,0,158,4,217,0,115,4,217,0,197,2,168,0,151,2,168,
0,6,2,193,0,44,6,166,0,104,6,166,0,115,6,166,0,69,3,225,0,0,6,250,0,117,5,98,0,100,1,207,0,116,3,252,0,27,3,27,0,54,6,129,0,111,5,45,0,105,6,129,0,111,5,45,0,105,5,123,0,109,4,0,255,244,2,170,1,230,2,
193,0,19,5,235,0,49,5,119,0,107,5,235,0,49,5,119,0,107,5,244,0,179,5,123,0,109,6,82,0,34,4,74,0,180,5,51,0,104,4,74,0,180,5,51,0,104,5,170,0,158,3,57,0,90,3,178,0,179,1,154,0,79,3,178,0,179,1,166,0,134,
3,178,0,179,2,28,0,135,5,235,0,180,4,225,0,156,5,235,0,180,4,225,0,156,4,230,255,187,6,244,0,115,5,61,0,104,4,219,0,187,2,104,0,103,4,219,0,187,2,104,255,225,3,252,0,27,3,27,0,54,3,104,0,33,2,182,0,87,
3,104,0,33,2,182,0,87,5,61,0,184,4,221,0,138,5,61,0,184,4,221,0,138,3,215,0,56,3,102,0,9,3,215,0,56,3,102,0,9,4,87,0,177,5,250,0,115,6,177,0,115,5,7,0,104,4,246,0,104,4,23,0,104,5,118,0,104,3,213,0,41,
6,44,0,104,4,0,255,244,1,149,0,129,2,121,0,48,4,63,0,179,2,217,0,76,8,171,0,178,6,247,0,46,2,222,0,41,8,0,0,79,4,0,0,153,8,0,0,79,4,0,0,153,8,0,0,79,4,0,0,152,4,0,0,152,7,213,1,106,4,182,0,129,4,217,0,
115,4,213,0,146,2,214,0,131,2,214,0,131,4,213,0,178,2,214,0,112,2,170,0,176,5,235,0,49,5,119,0,107,6,129,0,111,5,45,0,105,6,129,0,111,5,45,0,105,4,74,0,180,5,51,0,104,4,74,0,180,5,51,0,104,4,74,0,180,
5,51,0,104,6,250,0,117,5,98,0,100,6,250,0,117,5,98,0,100,6,250,0,117,5,98,0,100,5,119,0,177,4,225,0,156,5,119,0,45,4,225,0,4,1,207,255,121,1,154,255,94,1,207,255,143,1,154,255,116,1,207,255,133,1,154,
255,107,1,207,0,77,1,154,0,48,3,219,0,86,1,160,255,101,4,186,0,179,4,4,0,155,4,4,0,155,3,178,0,179,1,154,255,239,5,235,0,180,4,225,0,156,6,55,0,178,4,225,0,156,6,244,0,115,5,61,0,104,6,244,0,115,5,61,
0,104,4,219,0,187,2,104,0,73,3,252,0,27,3,27,0,35,3,104,0,33,2,182,0,63,5,61,0,184,4,221,0,138,5,61,0,184,4,221,0,138,5,61,0,184,4,221,0,138,5,61,0,184,4,221,0,138,7,174,0,96,6,166,0,9,4,188,0,63,4,74,
0,39,1,154,0,135,5,235,0,49,5,119,0,107,7,240,0,1,9,66,0,120,6,242,0,114,5,57,0,102,3,6,1,43,3,6,0,52,5,235,0,49,2,55,0,187,4,164,255,156,5,209,255,156,2,41,255,156,6,244,255,156,5,42,255,156,6,177,255,
156,1,154,255,127,5,235,0,49,4,152,0,183,3,178,0,177,5,235,0,49,4,74,0,180,3,215,0,56,5,119,0,177,6,244,0,115,1,207,0,158,4,186,0,179,5,158,0,67,7,90,0,112,5,235,0,180,4,63,0,115,6,244,0,115,5,119,0,177,
4,188,0,178,4,3,0,66,3,104,0,33,4,188,0,63,6,224,0,100,4,223,0,69,6,84,0,140,6,177,0,130,1,207,255,168,4,188,0,63,5,119,0,107,3,98,0,103,4,225,0,156,1,154,0,117,4,195,0,135,5,119,0,107,4,197,0,156,4,111,
0,53,4,147,0,104,3,98,0,103,3,185,0,118,4,225,0,156,5,61,0,104,1,154,0,135,4,4,0,155,4,74,0,39,4,225,0,144,4,111,0,53,3,185,0,118,5,61,0,104,5,93,0,50,5,92,0,135,4,161,0,104,5,188,0,104,3,55,0,50,4,195,
0,135,6,32,0,104,3,215,255,249,5,227,0,135,6,220,0,104,1,154,255,141,4,195,0,135,5,61,0,104,4,195,0,135,6,220,0,104,4,74,0,180,5,94,0,32,3,178,0,177,6,129,0,116,3,252,0,27,1,207,0,158,1,207,255,168,3,
219,0,86,8,133,0,49,8,88,0,177,5,111,0,33,4,186,0,179,5,43,0,67,5,49,0,177,5,235,0,49,4,149,0,178,4,152,0,183,3,178,0,177,5,252,0,30,4,74,0,180,7,123,0,40,4,166,0,99,5,235,0,180,5,235,0,180,4,186,0,179,
5,158,0,67,7,90,0,112,5,119,0,177,6,244,0,115,5,119,0,177,4,188,0,178,6,129,0,111,3,104,0,33,5,43,0,67,6,248,0,115,4,223,0,69,5,170,0,178,4,80,0,32,8,16,0,177,8,135,0,177,5,121,0,32,6,88,0,178,4,217,0,
178,6,129,0,111,8,195,0,177,4,172,0,72,5,119,0,107,5,90,0,104,3,190,0,156,2,227,0,156,4,215,0,33,5,51,0,104,6,39,255,244,3,98,0,55,4,238,0,156,4,238,0,156,4,4,0,156,4,111,0,53,7,8,0,54,4,201,0,156,5,61,
0,104,4,201,0,156,5,117,0,158,5,45,0,105,3,16,0,34,4,74,0,39,8,168,0,104,3,215,255,249,5,57,0,156,3,170,0,69,7,145,0,156,8,2,0,156,4,39,0,55,5,94,0,156,3,197,0,156,5,35,0,104,6,176,0,157,3,143,0,54,5,
49,0,104,5,4,0,35,2,227,0,156,5,35,0,104,3,27,0,54,1,154,0,90,1,154,255,141,1,160,255,192,6,86,0,54,6,197,0,156,5,4,0,36,4,4,0,156,4,74,0,39,4,203,0,157,3,61,0,177,2,217,0,156,7,174,0,96,6,166,0,9,7,174,
0,96,6,166,0,9,7,174,0,96,6,166,0,9,4,188,0,63,4,74,0,39,6,0,255,244,2,207,1,30,4,111,255,214,4,111,0,57,8,201,0,180,4,205,0,90,6,166,0,152,6,166,0,33,6,166,0,42,6,166,0,81,4,205,0,153,4,217,0,115,4,205,
2,30,4,205,1,1,5,180,255,238,5,180,2,131,5,180,2,131,5,180,255,238,5,180,2,131,5,180,255,238,5,180,2,131,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,1,197,5,180,2,131,5,
180,1,197,5,180,1,197,5,180,255,238,5,180,255,238,5,180,255,238,5,180,2,131,5,180,1,197,5,180,1,197,5,180,255,238,5,180,255,238,5,180,255,238,5,180,2,131,5,180,1,197,5,180,1,197,5,180,255,238,5,180,255,
238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,5,180,255,238,
5,180,2,218,5,180,0,107,5,180,255,238,5,215,0,0,4,213,0,146,8,0,0,0,7,235,1,48,7,235,1,32,7,235,1,48,7,235,1,32,4,205,0,174,4,205,0,124,4,205,0,38,8,43,1,152,8,107,1,184,7,86,0,16,4,107,0,89,5,86,0,102,
4,68,0,60,5,74,0,60,4,186,0,60,4,14,0,60,6,43,0,26,8,0,1,48,2,152,0,110,4,111,0,41,0,0,0,31,0,0,2,156,9,11,7,0,2,2,3,3,6,5,7,7,2,4,4,4,6,3,3,3,4,5,5,5,5,5,5,5,5,5,5,3,2,5,5,5,5,8,7,5,7,7,5,4,8,6,3,4,6,
4,9,7,8,5,8,5,4,3,7,7,10,5,5,4,3,5,3,5,5,3,6,6,6,6,6,3,6,5,2,2,5,2,8,5,6,6,6,3,4,4,5,6,10,6,6,4,3,6,4,5,7,7,7,5,7,8,7,6,6,6,6,6,6,6,6,6,6,6,2,2,2,2,5,6,6,6,6,6,5,5,5,5,5,4,5,5,6,6,6,5,7,7,9,3,3,5,9,8,
6,6,5,5,6,5,4,6,7,5,3,4,4,7,10,6,5,3,5,5,5,5,6,4,4,9,3,7,7,8,11,10,5,9,5,4,3,3,6,5,6,5,2,5,3,3,5,5,4,2,3,5,9,7,5,7,5,5,3,3,3,3,8,8,7,8,7,7,7,2,4,4,4,4,2,3,4,5,3,4,5,3,4,4,4,4,6,7,6,5,6,5,6,5,5,3,3,4,7,
7,7,4,8,6,3,4,4,7,6,7,6,6,5,3,3,7,6,7,6,7,6,7,5,6,5,6,6,4,4,2,4,2,4,2,7,5,7,5,6,8,6,5,3,5,3,4,4,3,4,3,4,7,5,7,5,4,4,4,4,5,7,8,6,6,5,6,4,7,5,2,3,5,3,10,8,3,9,5,9,5,9,5,5,9,5,5,5,3,3,5,3,3,7,6,7,6,7,6,5,
6,5,6,5,6,8,6,8,6,8,6,6,5,6,5,3,2,3,2,3,2,3,2,4,2,6,5,5,4,2,7,5,7,5,8,6,8,6,5,3,4,4,4,3,7,5,7,5,7,5,7,5,10,10,5,6,2,7,6,9,10,8,6,3,3,7,2,5,7,3,8,6,8,2,7,5,4,7,5,4,6,8,3,6,7,9,7,5,8,6,5,5,3,5,7,5,7,8,3,
5,6,4,5,2,5,6,5,5,5,4,4,5,6,2,5,5,5,6,4,6,6,6,5,6,4,5,7,4,6,8,2,5,6,5,8,5,6,4,7,4,3,3,4,10,9,6,6,6,6,7,5,5,4,7,5,8,5,7,7,6,7,9,6,8,6,5,7,3,6,8,5,6,5,9,10,6,7,5,7,10,5,6,6,4,3,5,6,7,4,6,6,5,5,8,5,6,5,6,
6,4,6,10,6,6,4,8,9,5,6,4,6,8,4,6,5,3,6,4,2,2,2,7,8,5,5,6,5,4,3,10,10,10,10,9,10,5,6,7,3,5,5,10,5,7,7,7,7,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,7,5,9,9,9,9,9,5,5,5,9,9,8,5,6,5,6,5,5,7,9,3,5,10,12,8,0,3,3,3,3,7,6,8,8,2,4,4,4,6,2,3,3,4,6,6,6,6,6,6,6,6,6,6,3,2,6,6,6,6,9,7,6,8,7,5,5,9,7,3,5,6,5,11,7,9,6,9,6,5,5,7,7,10,6,5,5,3,6,4,6,5,4,7,7,
6,7,7,3,7,6,2,2,5,2,10,6,7,7,7,3,4,4,6,6,10,6,6,4,3,7,4,6,7,7,8,5,7,9,7,7,7,7,7,7,7,6,7,7,7,7,2,2,2,2,6,7,7,7,7,7,6,6,6,6,6,4,6,6,6,6,6,6,7,7,10,4,4,5,10,9,7,6,5,5,6,6,5,7,8,5,3,4,4,8,12,7,6,3,6,5,6,5,
6,4,4,9,3,7,7,9,12,11,5,10,5,5,4,4,6,5,6,5,2,6,3,3,5,5,7,3,4,5,11,7,5,7,5,5,3,3,3,3,9,9,8,9,7,7,7,2,5,4,5,5,2,3,4,6,3,5,5,3,5,4,5,4,7,8,7,5,6,6,7,6,5,3,3,4,8,8,8,5,9,7,3,5,4,8,6,8,6,7,5,3,3,7,7,7,7,7,
7,8,5,7,5,7,7,4,5,2,5,2,5,3,7,6,7,6,6,9,7,6,3,6,3,5,4,5,4,5,4,7,6,7,6,5,4,5,4,5,7,8,6,6,5,7,5,8,5,2,3,5,4,11,9,4,10,5,10,5,10,5,5,10,6,6,6,4,4,6,4,3,7,7,8,6,8,6,5,7,5,7,5,7,9,7,9,7,9,7,7,6,7,6,3,2,3,2,
3,2,3,2,5,2,6,5,5,5,2,7,6,8,6,9,7,9,7,6,3,5,4,4,3,7,6,7,6,7,6,7,6,10,10,5,6,2,7,7,10,12,9,7,4,4,7,3,6,7,3,9,6,8,2,7,6,5,7,5,5,7,9,3,6,7,11,7,5,9,7,6,5,5,5,9,6,7,8,3,5,7,4,6,2,6,7,6,6,6,4,5,6,7,2,5,5,6,
6,5,7,7,7,6,7,4,6,8,5,6,9,2,6,7,6,9,5,7,5,8,5,3,3,5,11,10,7,6,6,6,7,6,6,5,7,5,9,6,7,7,6,7,11,7,9,7,6,8,5,6,9,6,7,5,10,11,7,8,6,8,11,6,7,7,5,4,6,7,8,4,6,6,5,6,8,6,7,6,7,6,4,6,10,6,7,5,9,10,5,7,5,6,8,4,
7,6,4,6,4,2,2,2,8,8,6,5,6,6,4,4,10,10,10,10,10,10,5,6,8,4,6,6,11,6,8,8,8,8,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,10,10,10,10,10,6,6,
6,10,11,9,6,7,5,7,6,5,8,10,3,6,11,14,8,0,3,3,3,3,8,6,9,8,2,4,4,6,6,3,4,3,5,6,6,6,6,6,6,6,6,6,6,3,3,7,7,7,7,10,7,6,9,8,6,5,10,8,3,5,7,5,11,8,10,7,10,7,6,5,8,7,11,7,7,6,4,7,5,8,6,4,8,8,7,8,7,3,7,7,2,2,5,
2,10,7,7,8,8,3,4,4,7,8,10,6,6,5,3,7,4,7,7,7,9,6,8,10,8,8,8,8,8,8,8,7,7,7,7,7,2,2,2,2,7,7,7,7,7,7,7,7,7,7,6,4,6,6,7,6,6,6,8,8,11,4,4,6,11,10,8,6,6,6,6,6,5,8,9,6,3,4,4,8,13,7,7,3,7,6,7,6,7,4,4,9,3,7,7,10,
13,13,6,11,6,5,4,4,6,5,6,7,2,6,3,3,5,5,7,3,4,6,14,7,6,7,6,6,3,3,3,3,10,10,9,10,8,8,8,2,6,5,5,5,2,4,4,6,3,6,6,3,6,4,6,5,7,9,7,7,6,7,8,7,7,4,4,4,9,9,9,5,10,7,3,6,4,9,7,9,7,8,6,4,4,7,8,7,8,8,8,9,6,7,6,7,
8,4,5,2,5,2,5,3,8,7,8,7,7,10,7,7,3,7,3,6,4,5,4,5,4,8,7,8,7,6,5,6,5,6,8,9,7,7,6,8,5,8,6,2,3,6,4,12,10,4,11,6,11,6,11,6,6,11,6,7,7,4,4,7,4,4,7,8,9,7,9,7,6,7,6,7,6,7,10,7,10,7,10,7,8,7,8,7,3,2,3,2,3,2,3,
2,5,2,7,5,5,5,2,8,7,9,7,10,7,10,7,7,3,6,4,5,4,8,7,8,7,8,7,8,7,11,10,7,6,2,7,8,11,13,10,7,4,4,7,3,6,8,3,10,7,9,2,7,6,5,8,6,6,8,10,3,7,7,11,8,6,10,8,7,6,5,7,9,7,9,9,3,7,8,5,7,2,7,8,7,6,6,5,5,7,7,2,5,6,7,
8,5,7,7,7,6,8,4,7,8,5,8,9,2,7,7,7,9,6,7,5,9,6,3,3,5,12,11,7,7,7,7,7,6,6,5,8,6,10,6,8,8,7,7,11,8,10,8,7,9,5,7,10,7,8,6,11,12,8,9,7,9,12,6,8,7,5,4,7,7,8,5,7,7,6,6,10,7,7,7,8,7,4,6,12,6,7,5,10,11,6,7,5,7,
9,5,7,7,4,7,4,2,2,2,9,9,7,6,6,7,4,4,11,10,11,10,11,10,7,6,8,4,6,6,12,7,9,9,9,9,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,11,11,11,11,11,
7,7,7,11,12,10,6,7,6,7,7,6,8,11,4,6,12,14,9,0,3,3,3,4,9,7,9,9,2,5,4,6,8,3,4,3,5,7,7,7,7,7,7,7,7,7,7,3,3,7,7,7,7,10,9,7,9,9,6,6,10,8,3,6,7,6,11,9,10,7,10,7,7,5,8,9,13,7,7,6,5,7,5,8,6,5,8,8,8,8,8,4,8,7,
3,3,6,3,11,7,8,8,8,4,5,5,7,8,10,6,6,5,4,8,4,7,9,9,9,6,9,10,8,8,8,8,8,8,8,8,8,8,8,8,3,3,3,3,7,8,8,8,8,8,7,7,7,7,7,5,7,7,7,8,7,7,9,9,12,5,4,7,12,10,9,8,7,7,6,7,6,9,10,7,3,4,4,9,14,8,7,3,7,7,7,7,7,5,5,12,
3,9,9,10,14,14,6,12,6,6,4,4,6,6,6,7,2,7,3,3,6,6,7,3,4,6,14,9,6,9,6,6,3,3,3,3,10,10,9,10,8,8,8,3,6,5,6,5,3,4,4,7,4,6,6,4,7,5,6,5,8,9,8,7,6,7,8,7,8,4,4,4,10,10,10,6,10,8,3,7,5,9,8,9,8,8,6,4,4,9,8,9,8,9,
8,9,6,8,6,8,9,5,6,3,6,2,6,3,9,7,9,7,7,10,8,7,4,7,4,7,5,5,5,5,5,8,7,8,7,6,5,6,5,7,9,10,8,7,6,8,6,9,6,2,4,6,4,13,10,4,12,6,12,6,12,6,6,12,7,7,7,4,4,7,4,4,9,8,9,8,9,8,6,8,6,8,6,8,10,8,10,8,10,8,8,7,8,7,3,
3,3,3,3,3,3,3,6,3,7,6,6,6,3,9,7,9,7,10,8,10,8,7,4,7,5,5,4,8,7,8,7,8,7,8,7,13,10,7,6,3,9,8,12,14,10,8,5,5,9,3,7,9,3,10,8,10,3,9,7,6,9,6,6,8,10,3,7,9,11,9,6,10,8,7,6,5,7,11,7,9,10,3,7,8,5,7,3,7,8,7,7,7,
5,6,7,8,3,6,6,7,8,6,8,8,8,7,9,5,7,9,6,9,10,3,7,8,7,10,6,8,6,10,7,3,3,6,13,13,8,7,8,8,9,7,7,6,9,6,11,7,9,9,7,9,11,8,10,8,7,9,5,8,10,7,9,6,12,13,8,10,7,10,13,7,8,8,6,4,7,8,9,5,7,7,6,6,11,7,8,7,8,8,5,6,13,
6,8,6,11,12,6,8,6,8,10,6,8,7,4,8,5,3,3,3,10,10,7,6,6,7,5,4,13,10,13,10,12,10,7,6,9,4,7,7,13,7,10,10,10,10,7,7,7,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
9,9,9,9,9,7,12,12,12,12,12,7,7,7,12,13,11,7,8,6,8,7,6,9,12,4,7,13,16,10,0,4,4,3,4,9,7,10,10,3,5,4,6,9,4,4,4,6,7,7,7,7,7,7,7,7,7,7,4,4,8,8,8,8,11,9,7,11,10,7,6,11,9,3,6,8,6,11,10,11,8,11,8,6,5,8,9,13,8,
7,6,5,8,5,9,7,5,9,9,8,9,8,4,9,8,3,3,7,3,13,8,9,9,9,4,5,5,8,8,12,6,6,6,5,9,4,8,9,9,11,7,10,11,8,9,9,9,9,9,9,8,8,8,8,8,3,3,3,3,8,9,9,9,9,9,8,8,8,8,7,5,7,7,8,8,8,7,10,10,13,5,5,7,13,11,9,8,7,7,8,7,6,9,11,
7,3,5,5,10,15,8,8,3,8,7,7,7,8,5,5,15,4,9,9,11,16,15,7,13,7,6,5,5,8,6,6,7,2,7,3,3,6,6,7,4,5,7,14,9,7,9,7,7,3,3,3,3,11,11,10,11,8,8,8,3,7,6,6,6,3,4,5,7,4,7,7,4,6,5,6,6,9,10,9,7,6,8,9,8,8,4,4,4,11,11,11,
6,11,9,3,6,5,11,8,11,8,9,7,4,4,9,9,9,9,10,9,10,7,8,7,8,9,5,6,3,6,3,6,3,10,8,10,8,8,11,9,8,4,8,4,6,5,5,5,5,5,8,8,8,8,6,6,6,6,7,10,11,8,8,7,9,6,10,7,3,4,7,5,14,11,5,13,7,13,7,13,7,7,13,8,8,8,5,5,8,5,4,9,
9,11,8,11,8,7,8,7,8,7,8,11,9,11,9,11,9,9,8,9,8,3,3,3,3,3,3,3,3,6,3,8,7,7,6,3,10,8,10,8,11,9,11,9,8,4,6,5,6,4,8,8,8,8,8,8,8,8,13,12,7,6,3,9,9,13,15,11,8,5,5,9,4,8,9,4,11,8,11,3,9,7,6,10,7,6,9,11,3,8,9,
11,10,7,11,9,8,7,5,7,11,8,11,11,3,7,9,6,8,3,8,9,8,7,7,6,6,8,9,3,7,7,8,8,6,9,9,9,8,9,5,8,10,6,9,11,3,8,9,8,11,7,9,6,11,6,3,3,6,14,14,9,8,8,8,9,7,7,6,10,7,12,8,10,10,8,9,11,9,11,9,8,11,5,8,11,8,9,7,13,14,
9,10,8,11,14,8,9,9,6,5,8,8,9,6,8,8,7,7,11,8,9,8,9,8,5,6,14,6,8,6,12,13,7,9,6,8,11,6,8,8,5,8,5,3,3,3,10,11,8,7,6,8,5,5,13,12,13,12,12,12,7,6,10,5,7,7,14,8,11,11,11,11,8,8,8,8,9,9,9,9,9,9,9,9,9,9,9,9,9,
9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,8,13,13,13,13,13,8,8,8,13,14,12,7,9,7,9,8,7,10,13,4,7,14,17,11,0,4,4,4,4,10,8,11,11,3,5,5,6,9,4,5,4,6,8,8,8,8,8,8,8,8,8,8,4,4,8,8,
8,8,12,9,8,11,10,8,7,12,10,3,7,8,6,13,10,12,8,12,9,7,5,9,9,15,9,7,7,5,8,5,9,7,5,10,10,9,10,9,4,9,9,3,3,7,3,13,9,9,10,10,4,5,5,9,8,12,7,8,6,5,9,4,8,9,9,11,8,10,12,9,10,10,10,10,10,10,9,9,9,9,9,3,3,3,3,
9,9,9,9,9,9,9,9,9,9,8,6,8,8,9,8,9,8,10,10,14,5,5,8,14,12,10,8,8,8,8,8,7,10,12,8,5,5,5,11,16,9,8,4,8,8,8,8,9,5,5,15,4,9,9,12,17,16,7,14,7,7,5,5,8,7,8,7,2,8,4,4,7,7,7,4,5,7,17,9,8,9,8,8,3,3,3,3,12,12,11,
12,9,9,9,3,7,6,7,6,3,5,5,8,4,7,7,4,7,5,7,6,9,11,9,7,8,8,10,8,10,5,5,5,12,12,12,7,12,9,3,7,5,11,9,11,9,10,7,5,5,9,10,9,10,10,10,11,8,9,8,9,10,6,6,3,6,3,6,4,10,9,10,9,9,12,9,9,4,9,4,7,5,5,5,5,5,9,9,9,9,
7,6,7,6,8,10,12,9,9,7,10,7,11,7,3,4,7,5,15,12,5,14,7,14,7,14,7,7,14,8,8,8,5,5,8,5,5,9,10,11,9,11,9,8,9,8,9,8,9,12,9,12,9,12,9,10,9,10,9,3,3,3,3,3,3,3,3,7,3,8,7,7,6,3,10,9,11,9,12,9,12,9,9,4,7,5,6,5,9,
9,9,9,9,9,9,9,15,12,7,8,3,9,10,14,16,12,9,5,5,9,4,8,10,4,12,9,12,3,9,8,6,10,8,7,10,12,3,8,9,13,10,7,12,10,8,7,5,7,11,9,11,12,3,7,10,6,9,3,8,10,8,8,8,6,7,9,9,3,7,8,9,8,7,9,9,9,8,10,5,8,11,7,10,12,3,8,9,
8,12,8,9,6,11,7,3,3,7,15,15,10,8,9,9,9,8,8,6,10,8,13,8,10,10,8,9,13,10,12,10,8,11,5,9,12,9,10,8,14,15,10,11,8,11,15,8,10,9,7,5,8,9,11,6,9,9,7,8,12,8,9,8,10,9,5,8,15,7,9,6,13,14,7,9,7,9,12,6,9,9,5,9,5,
3,3,3,11,12,9,7,8,8,6,5,15,12,15,12,13,12,7,8,11,5,8,8,15,8,12,12,12,12,8,8,8,8,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,8,14,14,14,14,14,8,8,8,14,15,13,8,9,7,9,8,7,11,14,5,8,15,18,11,0,4,4,4,5,11,8,12,11,3,5,5,6,9,4,5,4,7,8,8,8,8,8,8,8,8,8,8,4,4,9,9,9,9,13,11,9,12,11,8,7,13,10,5,7,9,7,15,11,13,9,
13,9,7,5,11,11,15,9,7,7,5,9,5,11,8,6,10,10,10,10,10,5,10,9,3,3,8,3,13,9,10,10,10,5,6,5,9,10,14,7,8,6,5,10,4,9,11,11,12,8,11,13,11,10,10,10,10,10,10,10,10,10,10,10,3,3,3,3,9,10,10,10,10,10,9,9,9,9,8,6,
8,8,9,8,10,8,11,11,15,6,6,8,15,13,11,8,8,8,8,9,7,11,12,8,5,6,6,12,17,10,9,4,9,8,8,8,9,6,6,15,4,11,11,13,18,17,8,15,8,7,5,5,9,7,8,7,2,8,4,4,7,7,7,4,5,8,17,11,8,11,8,8,5,5,5,5,13,13,12,13,11,11,11,3,7,7,
7,7,3,5,5,8,5,7,8,4,7,6,7,6,10,12,10,7,8,9,10,9,10,5,5,5,12,12,12,7,13,10,5,7,6,12,10,12,10,10,8,5,6,11,10,11,10,11,10,12,8,10,8,10,11,6,7,3,7,3,7,4,11,9,11,9,9,13,10,9,5,9,5,7,6,5,5,5,5,11,9,11,9,7,6,
7,6,8,11,13,9,9,8,10,7,12,8,3,5,8,5,16,13,5,15,8,15,8,15,8,8,15,9,9,9,5,5,9,5,5,11,10,12,10,12,10,8,10,8,10,8,10,13,10,13,10,13,10,10,9,10,9,5,3,5,3,5,3,5,3,7,3,9,8,8,7,3,11,9,12,9,13,10,13,10,9,5,7,6,
6,5,11,9,11,9,11,9,11,9,15,14,7,8,3,11,10,15,17,13,10,6,6,11,4,9,11,5,13,10,13,3,11,9,7,11,8,7,10,13,5,9,11,15,11,8,13,10,9,8,5,7,13,9,12,13,5,7,10,6,9,3,9,10,9,8,9,6,7,9,10,3,8,8,9,10,7,10,10,10,9,11,
6,9,11,7,11,13,3,9,10,9,13,8,10,7,12,7,5,5,7,16,16,10,9,10,10,11,9,9,7,11,8,14,9,11,11,9,11,15,10,13,10,9,12,5,10,13,9,11,8,15,16,10,12,9,12,16,9,10,10,7,5,9,10,11,6,9,9,8,8,13,9,10,9,10,10,6,8,16,7,10,
7,14,15,8,10,7,10,13,7,10,9,5,10,6,3,3,3,12,13,9,8,8,9,6,5,15,14,15,14,14,14,7,8,11,5,8,8,16,9,12,12,12,12,9,9,9,9,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,9,15,15,15,15,15,9,9,9,15,16,14,8,10,8,10,9,8,12,15,5,8,16,19,12,0,4,4,4,5,12,9,12,12,3,7,5,6,9,4,5,4,7,9,9,9,9,9,9,9,9,9,9,4,4,10,10,10,9,14,13,
9,13,12,9,8,14,11,5,8,9,7,15,12,14,9,14,10,8,8,11,11,15,9,11,8,6,10,6,11,8,6,11,11,10,11,10,5,11,10,3,3,8,3,15,10,10,11,11,5,6,7,10,10,14,8,8,7,7,11,6,10,13,13,13,9,12,14,11,11,11,11,11,11,11,10,10,10,
10,10,3,3,3,3,10,10,10,10,10,10,10,10,10,10,9,6,9,9,10,10,10,9,12,12,16,6,6,9,16,14,11,8,9,9,8,9,8,11,13,9,5,6,6,12,19,10,9,4,10,9,9,9,10,7,7,16,4,13,13,14,19,18,8,16,8,8,6,6,9,8,8,11,3,9,4,4,8,8,9,4,
6,8,17,13,9,13,9,9,5,5,5,5,14,14,13,14,11,11,11,3,8,7,8,7,4,5,5,9,5,8,8,6,8,6,8,7,11,13,10,11,8,9,11,10,10,5,5,6,13,13,13,8,14,11,5,8,6,13,10,13,10,11,8,5,6,13,11,13,11,12,11,13,9,10,9,10,11,6,7,3,7,3,
7,4,12,10,12,10,10,14,10,10,5,10,5,8,6,8,7,8,7,11,10,11,10,8,7,8,7,9,12,13,10,10,8,11,8,12,8,3,5,9,6,17,14,6,16,8,16,8,16,8,8,16,9,10,10,6,6,10,6,5,13,11,13,10,13,10,9,10,9,10,9,10,14,11,14,11,14,11,11,
10,11,10,5,3,5,3,5,3,5,3,8,3,9,8,8,7,3,12,10,12,10,14,10,14,10,10,5,8,6,7,5,11,10,11,10,11,10,11,10,15,14,11,8,3,13,11,16,19,14,10,6,6,13,4,9,12,4,14,10,13,3,13,9,7,12,9,8,11,14,5,9,11,15,12,9,14,11,9,
8,8,11,13,9,13,13,5,11,11,7,10,3,10,11,10,9,9,7,7,10,10,3,8,9,10,10,7,10,11,11,9,11,6,10,12,7,11,13,3,10,10,10,13,9,11,7,13,8,5,5,8,17,17,11,9,10,10,13,9,9,7,12,9,15,9,12,12,9,11,15,11,14,11,9,13,8,10,
14,9,11,9,16,17,11,13,10,13,18,9,11,11,7,6,9,10,11,7,10,10,8,9,14,10,10,10,11,10,6,8,17,8,10,7,15,16,8,11,8,10,13,7,10,10,6,10,6,3,3,3,13,14,10,8,8,10,6,6,15,14,15,14,15,14,11,8,12,6,9,9,18,10,13,13,13,
13,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,12,10,16,16,16,16,16,10,10,10,16,17,15,9,11,
9,11,9,8,12,16,5,9,17,20,13,0,5,5,4,5,12,9,13,13,3,7,5,6,11,5,6,5,7,9,9,9,9,9,9,9,9,9,9,5,5,10,10,10,10,15,13,10,14,13,9,8,15,12,5,8,10,8,17,13,15,10,15,10,8,8,12,13,17,10,11,8,6,10,6,11,9,6,12,12,11,
12,11,5,11,10,3,3,9,3,15,10,11,12,12,5,7,7,10,11,14,8,8,7,7,11,6,10,13,13,14,9,13,15,12,12,12,12,12,12,12,11,11,11,11,11,3,3,3,3,10,11,11,11,11,11,10,10,10,10,9,7,9,9,10,10,10,9,13,13,17,6,6,9,17,15,12,
10,9,9,8,10,8,12,14,9,5,6,6,13,20,11,10,4,10,9,9,9,10,7,7,18,5,13,13,15,20,19,9,17,9,8,6,6,9,8,8,11,3,9,4,4,8,8,10,5,6,9,20,13,9,13,9,9,5,5,5,5,15,15,13,15,12,12,12,3,9,7,8,8,4,6,5,9,5,9,9,6,8,7,8,7,11,
13,11,11,8,10,12,10,9,6,6,6,14,14,14,8,15,11,5,8,7,14,11,14,11,12,9,6,6,13,12,13,12,13,12,13,9,11,9,11,12,7,8,3,8,4,8,4,13,10,13,10,10,15,11,10,5,10,5,8,7,8,7,8,7,12,10,12,10,8,7,8,7,9,13,14,11,11,9,12,
8,13,9,3,5,9,6,18,15,6,17,9,17,9,17,9,9,17,10,10,10,6,6,10,6,6,13,12,14,11,14,11,9,11,9,11,9,11,15,11,15,11,15,11,12,10,12,10,5,3,5,3,5,3,5,3,8,3,10,9,9,8,3,13,10,13,10,15,11,15,11,10,5,8,7,7,6,12,10,
12,10,12,10,12,10,17,14,11,8,3,13,12,17,20,15,11,6,6,13,5,10,12,5,15,11,14,3,13,10,8,13,9,8,12,15,5,10,11,17,13,9,15,12,10,9,8,11,15,10,13,14,5,11,12,7,10,3,10,12,10,9,10,7,8,10,11,3,9,9,10,11,8,11,11,
11,10,12,7,10,13,8,13,15,3,10,11,10,15,9,11,8,14,8,5,5,8,18,18,12,10,11,11,13,10,10,8,13,9,16,10,13,13,10,11,17,12,15,12,10,14,8,11,15,10,12,9,17,18,12,13,10,14,19,10,12,11,8,6,10,11,13,7,10,10,9,9,15,
10,11,10,12,11,7,8,18,8,11,8,16,17,9,11,8,11,14,8,11,10,6,11,7,3,3,3,13,14,10,9,8,10,7,6,17,14,17,14,16,14,11,8,13,6,9,9,19,10,14,14,14,14,10,10,10,10,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,10,17,17,17,17,17,10,10,10,17,18,16,9,11,9,11,10,9,13,17,6,9,18,21,14,0,5,5,4,6,13,10,14,14,4,7,5,7,11,5,6,
5,8,10,10,10,10,10,10,10,10,10,10,5,5,11,11,11,11,16,15,10,15,13,10,9,16,12,5,9,11,8,17,13,16,11,16,11,9,8,12,15,17,11,11,9,7,11,6,11,9,7,12,12,12,12,12,6,12,11,3,3,9,3,17,11,12,12,12,5,7,7,11,11,14,9,
11,8,6,12,6,11,15,15,15,10,13,16,12,12,12,12,12,12,12,12,12,12,12,12,3,3,3,3,11,12,12,12,12,12,11,11,11,11,10,7,10,10,11,10,11,10,13,13,18,7,7,10,18,16,13,10,10,10,10,10,9,13,15,10,5,7,7,14,21,12,11,4,
11,10,9,10,11,7,7,18,5,15,15,16,21,20,9,18,9,9,6,6,11,9,11,11,3,10,4,4,9,9,10,5,6,9,20,15,10,15,10,10,5,5,5,5,16,16,14,16,12,12,12,3,9,8,9,8,4,6,5,10,5,9,9,6,9,7,9,8,12,14,12,11,11,11,12,11,9,6,6,6,15,
15,15,9,16,12,5,9,7,15,12,15,12,12,9,6,6,15,12,15,12,13,12,14,10,12,10,12,13,7,8,3,8,4,8,5,13,11,13,11,11,16,12,11,5,11,5,9,7,8,7,8,7,12,11,12,11,9,8,9,8,10,13,15,11,11,9,12,9,14,9,4,6,10,6,20,16,6,18,
9,18,9,18,9,9,18,11,11,11,6,6,11,6,6,15,12,15,12,15,12,10,12,10,12,10,12,16,12,16,12,16,12,12,11,12,11,5,3,5,3,5,3,5,3,9,3,11,9,9,8,3,13,11,14,11,16,12,16,12,11,5,9,7,8,6,12,11,12,11,12,11,12,11,17,14,
11,11,3,15,12,18,21,16,12,7,7,15,5,10,13,5,16,12,15,3,15,10,8,13,10,9,12,16,5,11,13,17,13,10,16,12,11,9,8,11,15,11,14,15,5,11,12,8,11,3,11,12,11,10,10,8,8,11,12,3,9,10,11,11,8,12,12,12,10,13,7,11,14,9,
13,15,3,11,12,11,15,10,12,8,15,9,5,5,9,19,19,12,11,12,12,15,10,10,8,13,10,17,10,13,13,11,13,17,12,16,12,11,15,8,12,16,11,13,10,18,19,12,14,11,15,20,11,12,12,8,7,11,12,13,8,11,11,9,10,16,11,12,11,12,12,
7,11,19,9,12,8,17,18,9,12,8,12,15,8,12,11,7,12,7,3,3,3,14,15,11,9,11,11,7,6,17,14,17,14,17,14,11,11,14,6,10,10,20,11,15,15,15,15,11,11,11,11,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,11,18,18,18,18,18,11,11,11,18,19,17,10,12,10,12,11,9,14,18,6,10,19,23,14,0,5,5,5,6,14,11,15,14,4,7,7,9,11,5,6,5,8,11,
11,11,11,11,11,11,11,11,11,5,5,12,12,12,11,16,15,11,15,14,10,9,17,13,5,9,11,9,17,14,17,11,17,12,9,8,12,15,17,12,11,9,7,12,7,13,10,7,13,13,12,13,12,6,13,12,3,3,10,3,17,12,12,13,13,6,7,7,12,13,16,9,11,8,
6,13,6,12,15,15,15,10,14,17,12,13,13,13,13,13,13,12,12,12,12,12,3,3,3,3,12,12,12,12,12,12,12,12,12,12,11,8,11,11,12,12,11,11,14,14,19,7,7,10,19,17,14,10,10,10,10,11,9,14,16,10,5,7,7,15,22,12,11,5,12,10,
11,10,12,7,7,18,5,15,15,17,23,22,10,19,10,9,7,7,11,9,11,11,3,11,4,4,9,9,10,5,7,10,21,15,10,15,10,10,5,5,5,5,17,17,15,17,12,12,12,3,9,8,9,9,4,6,7,10,6,9,10,6,9,7,9,8,13,15,12,11,11,11,13,12,11,6,6,7,16,
16,16,9,17,13,5,9,7,15,12,15,12,13,10,6,7,15,13,15,13,14,13,15,10,12,10,12,13,8,9,3,9,4,9,5,14,12,14,12,12,17,12,12,6,12,6,9,7,8,7,8,7,12,12,12,12,9,8,9,8,10,14,16,12,12,10,13,9,15,10,4,6,10,7,21,17,7,
19,10,19,10,19,10,10,19,11,12,11,7,7,11,7,6,15,13,15,12,15,12,10,12,10,12,10,12,17,13,17,13,17,13,13,12,13,12,5,3,5,3,5,3,5,3,9,3,11,10,10,9,3,14,12,15,12,17,12,17,12,12,6,9,7,8,6,12,12,12,12,12,12,12,
12,17,16,11,11,3,15,13,19,22,17,12,7,7,15,5,11,14,5,17,12,16,3,15,11,9,14,10,9,13,17,5,11,13,17,14,10,17,13,11,10,8,11,15,12,15,16,5,11,13,8,12,3,11,13,11,11,11,8,9,12,12,3,10,10,12,13,9,12,13,13,11,14,
8,11,15,9,14,16,3,11,12,11,16,10,13,9,15,9,5,5,9,20,20,13,11,12,12,15,11,11,9,14,10,18,11,14,14,11,13,17,13,17,13,11,15,8,12,17,12,13,10,19,20,13,15,12,15,21,11,13,13,9,7,12,12,15,8,12,12,10,10,17,11,
12,11,13,12,7,11,21,9,12,9,18,19,10,13,9,12,16,8,12,12,7,12,7,3,3,3,15,16,12,10,11,11,8,7,17,16,17,16,18,16,11,11,14,7,11,11,21,11,16,16,16,16,11,12,11,11,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,11,19,19,19,19,19,11,11,11,19,20,17,11,13,10,13,11,10,15,19,6,11,20,24,15,0,6,6,5,6,14,11,16,15,4,7,7,
9,11,5,7,5,9,11,11,11,11,11,11,11,11,11,11,5,5,12,12,12,12,17,15,11,16,15,11,10,17,14,5,10,12,9,17,15,17,12,17,12,10,8,13,15,17,12,13,10,7,12,7,13,10,8,14,14,13,14,13,6,13,12,3,3,10,5,19,12,13,14,14,6,
8,7,12,13,18,10,11,9,6,13,6,12,15,15,16,11,15,17,13,14,14,14,14,14,14,13,13,13,13,13,5,5,5,5,12,13,13,13,13,13,12,12,12,12,11,8,11,11,12,12,11,11,15,15,20,8,7,11,20,17,14,10,11,11,10,12,10,14,16,11,5,
7,7,15,23,13,12,5,12,11,11,11,12,7,7,18,6,15,15,17,24,23,10,20,10,10,7,7,11,10,11,13,3,11,5,5,10,10,10,5,7,10,24,15,11,15,11,11,5,5,5,5,17,17,16,17,13,13,13,5,9,9,10,9,4,7,7,11,6,9,10,6,10,8,10,9,13,16,
13,13,11,12,14,12,11,7,7,7,17,17,17,10,17,13,5,10,8,16,13,16,13,14,10,7,7,15,14,15,14,15,14,16,11,13,11,13,14,8,9,5,9,4,9,5,15,12,15,12,12,17,13,12,6,12,6,10,8,8,7,8,7,13,12,13,12,10,9,10,9,11,15,17,13,
12,10,14,10,15,10,4,6,11,7,22,17,7,20,10,20,10,20,10,10,20,12,12,12,7,7,12,7,7,15,14,16,13,16,13,11,13,11,13,11,13,17,13,17,13,17,13,14,12,14,12,5,5,5,5,5,5,5,3,10,5,12,10,10,9,5,15,12,16,12,17,13,17,
13,12,6,10,8,9,7,13,12,13,12,13,12,13,12,17,18,13,11,5,15,14,20,23,17,13,8,8,15,6,12,15,5,17,13,17,5,15,11,9,15,11,10,14,17,5,12,13,17,15,11,17,14,12,10,8,13,17,12,15,17,5,13,14,8,12,5,12,14,12,11,11,
8,9,12,13,5,10,11,12,13,9,13,13,13,12,14,8,12,15,10,15,17,5,12,13,12,17,11,13,9,16,10,5,5,10,21,21,14,12,13,13,15,11,11,9,15,11,19,12,15,15,12,13,17,14,17,14,12,16,8,13,17,12,14,11,20,21,14,16,12,16,22,
12,14,13,9,7,12,13,15,8,12,12,10,11,18,12,13,12,14,13,8,11,22,10,13,9,19,20,10,13,9,13,17,9,13,12,7,13,8,3,5,3,16,17,12,10,11,12,8,7,17,18,17,18,19,18,13,11,15,7,11,11,22,12,17,17,17,17,12,12,12,12,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,15,12,20,20,20,20,20,12,12,12,20,21,18,11,13,11,13,12,10,15,20,
6,11,21,25,16,0,6,6,5,6,15,12,16,16,4,8,7,9,11,5,7,5,9,12,12,12,12,12,12,12,12,12,12,5,5,13,13,13,12,18,15,12,17,16,11,10,18,14,5,10,12,10,19,16,18,12,18,13,10,8,13,15,19,13,13,10,7,13,7,13,11,8,14,14,
14,14,14,7,14,13,3,3,11,5,21,13,14,14,14,6,8,7,13,13,18,10,11,9,6,14,6,13,15,15,17,11,16,18,13,14,14,14,14,14,14,14,14,14,14,14,5,5,5,5,13,14,14,14,14,14,13,13,13,13,12,8,12,12,13,12,11,12,16,16,21,8,
8,12,21,18,15,10,12,12,10,12,10,15,17,12,5,8,8,16,24,14,12,5,13,12,11,12,13,9,9,22,6,15,15,18,25,24,11,21,11,10,7,7,11,10,11,13,3,12,5,5,10,10,10,6,7,11,23,15,11,15,11,11,5,5,5,5,18,18,17,18,13,13,13,
5,9,9,10,10,5,7,7,12,6,9,11,6,10,8,10,9,14,17,14,13,11,12,14,13,13,7,7,7,17,17,17,10,18,14,5,10,8,17,14,17,14,14,11,7,7,15,14,15,14,16,14,17,11,14,11,14,15,8,10,5,10,4,10,6,16,13,16,13,13,18,14,13,6,13,
6,10,8,8,7,8,7,13,13,13,13,10,9,10,9,11,16,18,13,13,11,14,10,16,11,4,6,11,7,23,18,8,21,11,21,11,21,11,11,21,12,13,13,7,7,13,7,7,15,14,17,14,17,14,11,14,11,14,11,14,18,14,18,14,18,14,14,13,14,13,5,5,5,
5,5,5,5,3,10,5,12,11,11,10,5,16,13,16,13,18,14,18,14,13,6,10,8,9,7,13,13,13,13,13,13,13,13,19,18,13,11,5,15,14,21,24,18,14,8,8,15,6,12,15,6,18,14,18,5,15,12,10,16,11,10,14,18,5,12,15,19,16,11,18,14,12,
11,8,13,19,13,17,18,5,13,14,9,13,5,13,14,13,12,12,9,10,13,14,5,11,11,13,13,10,14,14,14,12,15,8,13,16,10,15,18,5,13,14,13,18,11,14,10,17,10,5,5,10,22,22,14,12,14,14,15,12,12,10,16,11,20,12,16,16,12,15,
19,14,18,14,12,17,8,14,18,13,15,11,21,22,14,17,13,17,23,12,14,14,10,8,13,14,16,9,13,13,11,12,18,13,14,13,14,14,8,11,23,10,14,10,20,21,11,14,10,13,18,9,14,13,8,13,8,3,5,3,17,18,13,11,11,13,9,7,19,18,19,
18,20,18,13,11,16,7,12,12,23,13,17,17,17,17,13,13,13,13,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
13,21,21,21,21,21,13,13,13,21,22,19,12,14,11,14,12,11,16,21,7,12,22,26,17,0,6,6,6,7,16,12,17,17,4,9,8,10,15,6,7,6,10,12,12,12,12,12,12,12,12,12,12,6,6,13,13,13,13,19,17,13,18,16,12,11,19,15,6,11,13,10,
23,16,19,13,19,13,11,11,15,17,23,13,14,11,8,13,8,14,11,8,15,15,14,15,14,7,15,13,4,4,11,6,22,13,14,15,15,7,9,8,13,13,20,11,13,9,8,15,7,13,17,17,18,12,16,19,15,15,15,15,15,15,15,14,14,14,14,14,6,6,6,6,13,
14,14,14,14,14,13,13,13,13,12,9,12,12,14,14,13,12,16,16,22,8,8,12,22,19,16,13,12,12,11,13,11,16,18,12,6,8,8,17,25,14,13,6,13,12,13,12,13,9,9,24,6,17,17,19,26,25,11,22,11,11,8,8,11,11,13,14,4,12,6,6,11,
11,13,6,8,11,24,17,12,17,12,12,6,6,6,6,19,19,17,19,15,15,15,6,11,10,11,10,5,7,8,12,7,11,11,7,11,9,11,9,15,17,14,14,13,13,15,13,13,7,7,8,18,18,18,11,19,15,6,11,9,18,14,18,14,15,11,7,8,17,15,17,15,16,15,
17,12,14,12,14,16,9,10,6,10,5,10,6,16,13,16,13,13,19,14,13,7,13,7,11,9,11,8,11,8,15,13,15,13,11,9,11,9,12,16,18,14,14,11,15,11,17,11,4,7,12,8,24,19,8,22,11,22,11,22,11,11,22,13,13,13,8,8,13,8,7,17,15,
18,14,18,14,12,14,12,14,12,14,19,15,19,15,19,15,15,13,15,13,6,6,6,6,6,6,6,4,11,6,13,11,11,10,6,16,13,17,13,19,14,19,14,13,7,11,9,9,7,15,13,15,13,15,13,15,13,23,20,14,13,6,17,15,22,25,19,14,8,8,17,6,13,
16,6,19,14,18,6,17,13,10,16,12,11,15,19,6,13,15,23,16,12,19,15,13,11,11,14,19,13,18,18,6,14,15,9,13,6,13,15,13,12,13,9,10,13,14,6,11,12,13,13,10,14,15,15,13,16,9,13,17,11,16,19,6,13,14,13,19,12,15,10,
18,11,6,6,11,23,23,15,13,14,14,17,13,13,10,16,12,21,13,16,16,13,15,23,15,19,15,13,18,11,14,19,13,16,12,22,23,15,17,13,18,24,13,15,15,10,8,13,14,17,9,14,14,11,12,19,13,14,13,15,14,8,13,24,11,14,10,21,22,
11,15,10,14,18,10,14,13,8,14,9,4,6,4,17,19,13,11,13,13,9,8,23,20,23,20,21,20,14,13,17,8,12,12,24,13,18,18,18,18,13,13,13,13,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,13,22,22,22,22,22,13,13,13,22,23,20,12,15,12,15,13,11,17,22,7,12,23,27,17,0,6,6,6,7,17,13,18,17,5,9,8,10,15,6,8,6,10,13,13,13,13,13,13,
13,13,13,13,6,6,14,14,14,14,20,17,13,19,17,12,11,20,16,6,11,14,11,23,17,20,14,20,14,11,11,16,17,23,14,14,11,8,14,8,16,12,9,16,16,15,16,15,7,15,14,6,5,12,6,22,14,15,16,16,7,9,8,14,15,20,11,13,10,8,15,7,
14,17,17,19,12,17,20,16,16,16,16,16,16,16,15,15,15,15,15,6,6,6,6,14,15,15,15,15,15,14,14,14,14,13,9,13,13,14,14,15,13,17,17,23,9,8,13,23,20,16,13,13,13,13,13,11,16,19,13,6,8,8,18,27,15,14,6,14,13,14,13,
14,9,9,24,6,17,17,20,27,26,12,23,12,11,8,8,13,11,13,14,4,13,6,6,11,11,13,6,8,12,26,17,12,17,12,12,6,6,6,6,20,20,18,20,16,16,16,6,11,10,11,10,5,8,8,13,7,11,12,7,11,9,11,10,15,18,15,14,13,14,16,14,15,8,
8,8,19,19,19,11,20,15,6,11,9,19,15,19,15,16,12,8,8,17,16,17,16,17,16,18,12,15,12,15,16,9,11,6,11,5,11,6,17,14,17,14,14,20,15,14,7,14,7,11,9,11,8,11,8,16,14,16,14,11,10,11,10,12,17,19,14,14,12,16,11,18,
12,5,7,12,8,25,20,8,23,12,23,12,23,12,12,23,14,14,14,8,8,14,8,8,17,16,19,15,19,15,12,15,12,15,12,15,20,15,20,15,20,15,16,14,16,14,6,6,6,6,6,6,6,6,11,6,14,12,12,11,6,17,14,18,14,20,15,20,15,14,7,11,9,10,
8,16,14,16,14,16,14,16,14,23,20,14,13,6,17,16,23,27,20,15,9,9,17,6,13,17,6,20,15,19,6,17,13,11,17,12,11,16,20,6,14,15,23,17,12,20,16,14,12,11,14,20,14,18,19,6,14,16,10,14,6,14,16,14,13,13,10,11,14,15,
6,12,12,14,15,11,15,15,15,13,16,9,14,18,11,17,20,6,14,15,14,20,12,15,11,19,11,6,6,11,25,24,16,14,15,15,17,13,13,11,17,12,22,13,17,17,14,15,23,16,20,16,14,19,11,15,20,14,16,12,23,25,16,18,14,19,25,13,16,
15,11,8,14,15,18,10,14,14,12,13,20,14,15,14,16,15,9,13,24,11,15,11,22,23,12,15,11,15,19,10,15,14,8,15,9,6,6,5,18,19,14,12,13,14,9,8,23,20,23,20,22,20,14,13,17,8,13,13,25,14,19,19,19,19,14,14,14,14,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,17,14,23,23,23,23,23,14,14,14,23,24,21,13,15,12,15,14,12,18,23,
7,13,24,29,18,0,7,7,8,7,17,13,19,18,5,8,9,10,15,7,8,7,10,13,13,13,13,13,13,13,13,13,13,7,7,15,15,15,14,21,17,14,20,18,13,12,21,16,6,12,14,11,23,18,21,14,21,15,12,11,16,17,23,15,16,12,8,15,8,16,12,9,16,
16,16,16,16,8,16,15,6,5,12,6,24,15,16,16,16,7,10,8,15,15,20,12,13,10,8,16,7,15,17,17,20,13,18,21,16,16,16,16,16,16,16,16,16,16,16,16,6,6,6,6,15,16,16,16,16,16,15,15,15,15,13,10,13,13,15,14,15,13,18,18,
24,9,9,13,24,21,17,13,13,13,14,14,12,17,20,13,6,9,9,18,28,16,14,8,15,13,14,13,15,9,9,24,7,17,17,21,29,27,12,24,12,12,8,8,13,12,13,16,4,13,6,6,12,12,14,7,9,12,28,17,13,17,13,13,6,6,6,6,21,21,19,21,16,16,
16,6,12,11,12,11,5,8,8,13,7,12,12,7,12,10,12,10,16,19,16,16,13,14,16,15,15,8,8,8,20,20,20,12,21,16,6,12,10,20,16,20,16,16,12,8,8,17,16,17,16,18,16,19,13,16,13,16,17,10,11,6,11,5,11,6,18,15,18,15,15,21,
16,15,7,15,7,12,10,11,8,11,8,16,15,16,15,12,10,12,10,13,18,20,15,15,12,16,12,19,12,5,7,13,9,26,21,9,24,12,24,12,24,12,12,24,14,15,15,9,9,15,9,8,17,16,20,16,20,16,13,16,13,16,13,16,21,16,21,16,21,16,16,
15,16,15,6,6,6,6,6,6,6,6,12,6,14,12,12,11,6,18,15,19,15,21,16,21,16,15,7,12,10,10,8,16,15,16,15,16,15,16,15,23,20,16,13,6,17,16,24,28,21,16,9,9,17,7,14,17,6,21,16,20,6,17,14,11,18,13,12,16,21,6,14,17,
23,18,13,21,16,14,12,11,16,20,15,19,20,6,16,16,10,15,6,14,16,14,12,14,10,11,15,16,6,12,13,15,15,11,16,16,16,14,17,10,14,18,12,18,21,6,14,16,14,21,13,16,11,20,12,6,6,12,26,25,16,14,16,16,17,14,14,11,18,
13,22,14,18,18,14,17,23,16,21,16,14,20,11,16,21,15,17,13,24,26,16,19,15,20,26,14,16,16,11,9,15,16,18,10,15,15,12,13,21,14,16,14,16,16,9,13,26,12,16,11,23,24,12,16,11,15,20,11,16,15,9,15,10,6,6,5,19,20,
15,12,13,14,10,9,23,20,23,20,23,20,16,13,18,8,13,13,26,14,20,20,20,20,14,15,14,14,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
17,17,17,17,17,17,17,18,15,24,24,24,24,24,14,14,14,25,25,22,13,16,13,16,14,12,19,24,8,13,27,32,20,0,7,7,9,8,19,15,21,20,5,10,10,12,17,7,9,7,12,15,15,15,15,15,15,15,15,15,15,7,7,16,16,16,16,23,19,16,22,
20,14,13,24,18,6,13,16,12,25,20,23,16,24,16,13,11,17,19,25,16,16,13,10,16,10,18,14,10,18,18,17,19,18,8,18,16,6,6,14,6,26,16,18,18,18,8,10,10,16,17,24,13,15,11,10,18,10,16,19,19,22,14,20,23,17,18,18,18,
18,18,18,17,18,18,18,18,6,6,6,6,16,18,18,18,18,18,16,16,16,16,15,11,15,15,17,16,16,15,20,20,27,10,10,15,27,23,19,16,15,15,16,16,13,19,22,15,8,10,10,21,31,18,16,9,16,15,15,15,17,12,12,27,8,19,19,23,32,
31,14,27,14,13,9,9,15,13,15,16,4,15,7,7,13,13,14,7,10,14,31,19,14,19,14,14,6,6,6,6,23,23,21,23,17,17,17,6,13,12,13,12,6,9,9,15,8,13,14,9,13,10,13,11,18,21,18,16,15,16,18,16,16,9,9,9,22,22,22,13,24,18,
6,13,10,22,17,22,17,19,14,9,9,19,18,19,18,20,19,21,14,18,14,18,19,11,12,6,12,6,12,7,20,16,20,16,17,23,18,16,8,16,8,13,10,11,10,11,10,17,16,17,16,13,11,13,11,15,20,23,17,17,14,18,13,21,14,5,8,14,10,29,
24,10,27,14,27,14,27,14,14,26,16,16,16,10,10,16,10,9,19,18,22,17,22,17,14,18,14,18,14,18,24,18,24,18,24,18,18,16,18,16,6,6,6,6,6,6,6,6,13,6,16,14,14,12,6,20,16,21,16,23,18,23,18,16,8,13,10,12,9,17,16,
17,16,17,16,17,16,25,24,16,15,6,19,18,27,31,23,18,10,10,19,7,16,20,7,23,17,23,6,19,16,12,20,14,13,18,23,6,16,19,25,20,14,23,18,16,14,11,16,23,16,21,23,6,16,18,11,16,6,16,18,16,15,15,11,13,16,18,6,14,14,
16,17,13,18,18,18,16,19,11,16,21,13,20,23,6,16,18,16,23,14,18,12,22,13,6,6,13,29,28,18,16,17,18,19,15,16,12,20,14,25,16,20,20,16,19,25,18,23,18,16,22,11,17,24,16,19,15,27,29,18,21,16,22,30,16,18,18,13,
10,16,18,21,11,17,17,14,15,24,16,18,16,18,17,10,15,29,13,18,12,26,27,14,18,13,17,23,12,18,17,10,17,10,6,6,6,21,23,17,14,15,16,11,10,25,24,25,24,26,24,16,15,20,9,15,15,30,16,22,22,22,22,16,16,16,16,19,
19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,20,16,27,27,27,27,27,16,16,16,28,28,25,15,18,14,18,16,14,21,27,
9,15,29,36,22,0,8,8,9,9,21,16,22,22,6,10,10,12,17,7,10,7,13,16,16,16,16,16,16,16,16,16,16,7,7,18,18,18,17,25,21,17,24,22,16,14,25,20,8,14,17,13,29,21,25,17,25,18,14,13,20,21,27,18,18,14,10,18,11,19,15,
11,20,20,19,20,19,9,20,18,7,7,15,6,28,18,19,20,20,9,11,10,18,17,24,14,15,12,10,19,10,18,21,21,24,16,21,25,20,20,20,20,20,20,20,19,19,19,19,19,6,6,6,6,18,19,19,19,19,19,18,18,18,18,16,12,16,16,18,18,17,
16,22,22,29,11,11,16,29,25,21,16,16,16,16,17,14,21,24,16,8,11,11,22,34,19,17,9,18,16,16,16,18,12,12,27,8,21,21,25,35,33,15,29,15,14,10,10,17,14,15,18,5,16,7,7,14,14,16,7,10,15,36,21,16,21,16,16,8,8,8,
8,25,25,23,25,20,20,20,6,14,13,14,13,6,10,9,16,9,14,15,9,14,11,14,12,19,23,19,18,15,17,20,18,16,10,10,10,24,24,24,14,25,20,8,14,11,24,19,24,19,20,15,10,10,21,20,21,20,22,20,23,16,19,16,19,21,12,13,6,13,
6,13,8,21,18,21,18,18,25,19,18,9,18,9,14,11,13,10,13,10,20,18,20,18,14,12,14,12,16,22,24,18,18,15,20,14,22,15,6,9,15,10,31,25,10,29,15,29,15,29,15,15,28,17,18,18,10,10,18,10,10,21,20,24,19,24,19,16,19,
16,19,16,19,25,20,25,20,25,20,20,18,20,18,8,6,8,6,8,6,8,7,14,6,17,15,15,13,6,21,18,23,18,25,19,25,19,18,9,14,11,12,10,20,18,20,18,20,18,20,18,27,24,18,15,6,21,20,29,34,25,19,11,11,21,8,17,21,8,25,19,24,
6,21,17,13,21,16,14,20,25,8,17,20,29,21,15,25,20,17,15,13,18,25,18,23,24,8,18,20,12,18,6,17,20,17,16,17,12,14,18,19,6,15,16,18,17,14,19,19,19,17,21,12,17,22,14,21,25,6,17,19,17,25,16,19,13,24,14,8,8,14,
31,30,20,17,19,19,21,17,17,13,22,16,27,17,21,21,17,20,29,20,25,20,17,24,13,19,25,18,21,16,29,31,20,23,18,24,32,17,20,19,14,10,18,19,22,12,18,18,15,16,25,17,19,17,20,19,11,15,31,14,19,13,27,29,15,19,14,
19,24,13,19,18,10,19,11,7,6,7,23,25,18,15,15,17,12,10,27,24,27,24,28,24,18,15,22,10,16,16,32,17,24,24,24,24,17,18,17,17,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,
21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,18,29,29,29,29,29,17,17,17,30,31,27,16,19,15,19,17,15,22,29,9,16,32,39,24,0,9,9,10,10,23,18,25,24,6,11,12,13,20,9,11,9,14,18,18,18,18,18,
18,18,18,18,18,9,9,19,19,19,19,28,23,18,26,24,17,16,28,22,8,15,19,15,29,24,28,19,28,19,16,13,21,23,30,19,18,15,11,19,11,22,16,12,22,22,21,22,21,10,22,20,7,7,16,6,30,20,21,22,22,10,12,10,19,19,28,15,17,
14,10,22,10,19,23,23,26,17,24,28,21,22,22,22,22,22,22,21,21,21,21,21,6,6,6,6,20,21,21,21,21,21,19,19,19,19,18,13,18,18,20,20,18,18,24,24,32,12,12,18,32,28,23,18,18,18,18,18,16,23,26,18,8,12,12,25,37,21,
19,10,19,18,18,18,20,14,14,33,9,23,23,28,38,36,16,32,16,15,11,11,17,16,17,18,5,18,8,8,16,16,17,9,11,16,39,23,17,23,17,17,8,8,8,8,28,28,25,28,21,21,21,6,16,14,16,15,7,11,10,18,10,16,17,9,16,12,15,14,22,
25,21,18,17,19,22,19,19,11,11,11,27,27,27,16,28,22,8,16,12,26,21,26,21,22,16,11,11,23,22,23,22,24,22,25,17,21,17,21,23,13,15,6,15,7,15,8,24,20,24,20,20,28,21,19,10,19,10,16,12,13,10,13,10,21,19,21,19,
15,14,15,14,17,24,27,20,20,16,22,15,25,16,6,10,17,11,35,28,11,32,16,32,16,32,16,16,31,19,19,19,11,11,19,11,11,23,22,26,21,26,21,17,21,17,21,17,21,28,22,28,22,28,22,22,20,22,20,8,6,8,6,8,6,8,7,15,6,19,
16,16,15,6,24,20,25,20,28,21,28,21,19,10,16,12,14,11,21,19,21,19,21,19,21,19,30,28,18,17,6,23,22,32,37,28,21,12,12,23,9,19,23,9,28,21,27,6,23,18,15,24,17,15,22,28,8,19,22,29,24,17,28,22,19,16,13,18,28,
19,25,27,8,18,22,14,20,6,19,22,19,18,18,14,15,20,21,6,16,17,20,19,15,21,21,21,19,23,13,19,25,15,24,27,6,19,21,19,27,17,21,15,26,16,8,8,15,34,33,22,19,21,21,23,18,18,15,24,17,30,19,24,24,19,22,29,22,28,
22,19,26,13,21,28,19,23,17,32,34,22,25,19,26,35,19,22,21,15,12,19,21,25,14,20,20,16,18,28,19,21,19,22,21,12,17,35,15,21,15,30,32,17,21,15,21,27,14,21,20,12,21,12,7,6,7,25,27,20,16,17,19,13,11,30,28,30,
28,31,28,18,17,24,11,18,18,35,19,27,27,27,27,19,19,19,19,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,
19,32,32,32,32,32,19,19,19,33,34,29,18,21,17,21,19,16,25,32,10,18,33,39,25,0,9,9,10,10,24,18,26,25,7,11,12,15,20,9,11,9,14,18,18,18,18,18,18,18,18,18,18,9,9,20,20,20,20,29,23,19,27,25,18,16,29,23,8,16,
20,15,31,24,29,20,29,20,16,13,21,23,30,20,20,16,11,20,12,22,17,12,23,23,21,23,21,10,22,20,7,7,17,6,30,20,22,23,23,10,13,10,20,19,28,16,17,14,10,22,10,20,23,23,27,18,24,29,21,23,23,23,23,23,23,21,21,21,
21,21,6,6,6,6,20,22,22,22,22,22,20,20,20,20,18,13,18,18,20,20,18,18,25,25,33,12,12,18,33,29,24,18,18,18,18,19,16,24,27,18,8,12,12,25,38,22,20,10,20,18,19,18,20,14,14,33,9,23,23,29,39,38,17,33,17,16,12,
12,17,16,17,20,5,18,8,8,16,16,17,9,12,17,39,23,18,23,18,18,8,8,8,8,29,29,26,29,21,21,21,6,16,14,16,15,7,11,11,18,10,16,17,9,16,13,16,14,22,26,22,20,17,20,23,20,20,11,11,11,27,27,27,16,29,22,8,16,13,27,
21,27,21,23,17,11,11,23,23,23,23,25,23,26,18,21,18,21,23,13,15,6,15,7,15,9,24,20,24,20,20,29,22,20,10,20,10,16,13,13,10,13,10,21,20,21,20,16,14,16,14,18,25,28,21,20,17,23,16,25,17,7,10,18,12,36,29,12,
33,17,33,17,33,17,17,32,19,20,20,12,12,20,12,11,23,23,27,21,27,21,18,21,18,21,18,21,29,22,29,22,29,22,23,20,23,20,8,6,8,6,8,6,8,7,16,6,20,17,17,15,6,24,20,26,20,29,22,29,22,20,10,16,13,14,11,21,20,21,
20,21,20,21,20,30,28,20,17,6,23,23,33,38,29,22,12,12,23,9,19,24,9,29,21,28,6,23,19,15,24,18,16,23,29,8,20,23,31,24,18,29,23,20,17,13,20,28,20,26,28,8,20,23,14,20,6,20,23,20,18,19,14,15,20,22,6,17,18,20,
19,15,22,22,22,19,24,13,20,25,16,24,28,6,20,22,20,28,18,22,15,27,16,8,8,16,35,34,22,20,21,21,23,19,19,15,25,18,31,19,24,24,20,23,31,23,29,23,20,27,13,21,29,20,23,18,33,35,23,26,20,27,36,19,23,22,15,12,
20,21,25,14,20,20,17,18,29,20,22,20,23,21,13,17,36,16,22,15,31,33,17,22,16,21,28,15,21,21,12,21,13,7,6,7,26,28,21,17,17,20,13,12,30,28,30,28,32,28,20,17,25,12,18,18,36,20,27,27,27,27,20,20,20,20,24,24,
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,20,33,33,33,33,33,20,20,20,34,35,30,18,22,18,22,20,17,25,33,11,
18,37,44,28,0,10,10,11,11,27,21,29,28,7,13,13,15,22,9,12,10,16,21,21,21,21,21,21,21,21,21,21,10,9,22,22,22,22,32,25,21,30,28,20,18,32,25,10,18,22,17,33,27,32,22,32,22,18,15,24,25,34,23,22,18,13,22,13,
24,19,14,25,25,24,25,24,12,25,23,8,7,19,8,34,23,24,25,25,11,14,11,23,21,32,18,19,16,13,25,12,22,25,25,30,20,27,32,24,25,25,25,25,25,25,24,24,24,24,24,8,8,8,8,23,24,24,24,24,24,23,23,23,23,20,15,21,21,
23,22,21,21,28,28,37,14,14,20,37,32,26,20,20,20,20,21,18,26,30,20,10,14,14,28,43,24,22,11,22,20,20,20,23,15,15,36,10,25,25,32,44,42,19,37,19,18,13,13,20,18,19,22,6,21,10,10,18,18,20,10,13,19,42,25,20,
25,20,20,10,10,10,10,32,32,29,32,24,24,24,8,19,16,18,17,8,12,12,20,11,19,19,10,18,14,18,16,25,29,24,22,19,22,25,22,22,12,12,13,31,31,31,18,32,25,10,18,14,30,24,30,24,25,19,12,13,25,25,25,25,28,25,29,20,
24,20,24,26,15,17,8,17,8,17,10,27,23,27,23,23,32,24,22,11,22,11,18,14,15,11,15,11,24,23,24,23,18,16,18,16,20,28,31,23,23,19,25,18,29,19,7,11,20,13,40,32,13,37,19,37,19,37,19,19,36,22,22,22,13,13,22,13,
12,25,25,30,24,30,24,20,24,20,24,20,24,32,25,32,25,32,25,25,23,25,23,10,8,10,8,10,8,10,8,18,8,22,19,19,17,8,27,23,29,23,32,24,32,24,22,11,18,14,16,13,24,23,24,23,24,23,24,23,34,32,22,19,8,25,25,37,43,
32,24,14,14,25,10,21,27,10,32,24,31,8,25,21,17,27,20,18,25,32,10,22,26,33,27,20,32,25,22,19,15,22,32,23,29,31,10,22,25,16,23,8,22,25,22,21,21,16,17,23,24,8,19,20,23,21,17,24,25,25,21,27,15,22,28,18,27,
32,8,22,24,22,32,20,25,17,30,18,10,10,18,39,39,25,22,24,24,25,21,21,17,28,20,35,22,27,27,22,26,33,25,32,25,22,30,15,24,32,23,26,20,37,39,25,29,22,30,41,22,25,25,17,13,22,24,28,16,23,23,19,21,33,22,24,
22,25,24,14,19,40,18,24,17,35,37,19,25,17,24,31,16,24,23,13,24,14,8,8,7,29,31,23,19,19,22,15,13,34,32,34,32,36,32,22,19,28,13,21,21,41,22,31,31,31,31,22,22,22,22,26,26,26,26,26,26,26,26,26,26,26,26,26,
26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,27,22,37,37,37,37,37,22,22,22,38,39,34,20,25,20,24,22,19,29,37,12,21,42,50,32,0,12,12,13,13,30,23,
33,32,8,15,15,19,26,11,14,11,18,23,23,23,23,23,23,23,23,23,23,11,11,25,25,25,25,36,29,24,34,31,23,20,37,29,11,20,25,19,37,31,37,25,37,25,21,18,28,29,41,26,25,20,15,25,15,27,21,16,29,29,27,29,27,13,28,
26,9,9,21,9,39,26,28,29,29,13,16,14,26,24,34,20,23,18,15,28,13,25,29,29,34,23,31,37,28,29,29,29,29,29,29,27,27,27,27,27,9,9,9,9,26,28,28,28,28,28,26,26,26,26,23,17,23,23,26,24,25,23,31,31,42,16,16,23,
42,36,30,23,23,23,24,24,21,30,35,23,11,16,16,32,49,27,25,13,25,23,24,23,26,17,17,42,12,29,29,37,50,48,21,42,21,20,15,15,22,21,23,25,7,23,11,11,20,20,23,11,15,21,48,29,23,29,23,23,11,11,11,11,37,37,33,
37,28,28,28,9,21,18,20,19,9,14,14,23,13,21,22,13,21,16,20,18,28,33,28,25,23,25,29,25,25,14,14,14,35,35,35,20,37,28,11,21,16,34,27,34,27,29,21,14,14,29,29,29,29,31,29,33,23,27,23,27,30,17,19,9,19,9,19,
11,31,26,31,26,26,37,28,25,13,25,13,21,16,18,14,18,14,28,26,28,26,20,18,20,18,23,31,35,26,26,21,29,20,32,21,8,13,22,15,46,37,15,42,21,42,21,42,21,21,41,25,25,25,15,15,25,15,14,29,29,34,27,34,27,23,27,
23,27,23,27,37,28,37,28,37,28,29,26,29,26,11,9,11,9,11,9,11,9,20,9,25,21,21,19,9,31,26,33,26,37,28,37,28,25,13,21,16,18,14,28,26,28,26,28,26,28,26,41,34,25,23,9,29,29,42,49,36,27,16,16,29,12,24,31,11,
37,27,35,9,29,24,19,31,23,20,29,37,11,25,29,37,31,22,37,29,25,21,18,25,36,26,33,35,11,25,29,18,26,9,25,29,25,23,24,18,20,26,28,9,21,23,26,24,20,28,28,28,24,30,17,25,32,20,31,36,9,25,28,25,36,23,28,19,
34,21,11,11,20,45,44,29,25,27,27,29,24,24,19,31,23,39,24,31,31,25,29,37,29,37,29,25,34,18,27,37,26,30,23,42,45,29,33,25,34,46,25,29,28,20,15,25,27,32,18,26,26,21,23,37,25,28,25,29,27,16,23,45,20,27,19,
40,42,22,28,20,27,35,19,27,26,15,27,16,9,9,9,33,36,26,21,23,25,17,15,41,34,41,34,40,34,25,23,32,15,23,23,46,25,35,35,35,35,25,25,25,25,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,31,25,42,42,42,42,42,25,25,25,43,44,39,23,28,22,28,25,21,32,42,14,23,46,56,35,0,13,13,13,14,33,26,36,35,9,16,17,19,28,12,15,13,
20,26,26,26,26,26,26,26,26,26,26,13,12,28,28,28,27,40,33,26,37,34,25,22,40,31,11,22,27,21,43,34,40,27,40,28,23,18,29,33,43,28,29,22,17,28,17,30,23,17,31,31,30,32,30,14,31,28,9,9,23,11,45,28,30,31,31,14,
18,15,28,26,38,22,25,20,17,31,16,28,33,33,37,25,34,40,29,31,31,31,31,31,31,30,30,30,30,30,11,11,11,11,28,30,30,30,30,30,28,28,28,28,25,18,26,26,28,28,27,26,34,34,46,17,17,25,46,40,33,26,25,25,24,27,23,
33,38,25,13,17,17,35,53,30,27,13,28,25,26,25,28,19,19,48,13,33,33,40,55,52,23,46,23,22,16,16,26,23,25,29,8,26,11,11,22,22,24,13,16,23,56,33,25,33,25,25,11,11,11,11,40,40,36,40,29,29,29,11,23,20,22,21,
10,15,15,25,14,23,24,13,23,18,22,20,31,36,30,29,25,27,31,28,28,15,15,16,38,38,38,22,40,31,11,23,18,37,30,37,30,32,23,15,16,33,31,33,31,34,32,36,25,30,25,30,33,19,21,11,21,9,21,12,34,28,34,28,28,40,30,
28,14,28,14,23,18,18,15,18,15,29,28,29,28,22,20,22,20,25,34,38,29,29,24,31,22,35,23,9,14,24,16,50,40,16,46,23,46,23,46,23,23,45,27,28,28,16,16,28,16,15,33,31,37,30,37,30,25,30,25,30,25,30,40,31,40,31,
40,31,31,28,31,28,11,11,11,11,11,11,11,9,22,11,27,23,23,21,11,34,28,36,28,40,30,40,30,28,14,23,18,20,16,29,28,29,28,29,28,29,28,43,38,29,25,11,33,31,46,53,40,30,17,17,33,13,27,33,12,40,30,38,11,33,26,
21,34,25,22,31,40,11,27,32,43,34,24,40,31,27,23,18,29,40,28,36,38,11,29,31,19,28,11,27,31,27,26,26,19,21,28,30,11,23,25,28,26,21,30,31,31,27,33,18,27,35,22,34,39,11,27,30,27,39,25,31,21,37,23,11,11,22,
49,48,31,27,30,30,33,26,26,21,34,25,43,27,34,34,27,32,43,31,40,31,27,37,18,30,40,28,33,25,46,49,31,36,28,37,50,27,31,31,22,17,28,30,35,19,28,28,23,26,40,28,30,28,31,30,18,25,50,22,30,21,44,46,24,31,22,
30,38,20,30,29,17,30,18,9,11,9,36,39,29,23,25,28,19,16,43,38,43,38,44,38,29,25,35,16,26,26,51,28,38,38,38,38,28,28,28,28,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,34,28,46,46,46,46,46,28,28,28,47,48,42,25,31,25,30,27,23,35,46,15,26,50,60,38,0,14,14,14,15,36,28,39,38,10,17,17,21,31,13,17,13,22,28,28,28,
28,28,28,28,28,28,28,13,13,30,30,30,30,43,35,29,41,37,27,24,44,34,13,24,30,23,45,37,43,30,44,30,25,21,33,35,47,30,31,24,17,30,18,33,25,19,34,34,32,34,33,16,34,31,9,9,25,11,47,31,33,34,34,15,19,17,30,28,
42,24,27,21,17,34,16,30,35,35,41,27,37,43,33,34,34,34,34,34,34,32,33,33,33,33,11,11,11,11,31,33,33,33,33,33,30,30,30,30,28,20,28,28,31,30,29,28,37,37,50,19,18,27,50,43,36,28,27,27,26,29,25,36,41,27,13,
18,18,38,58,33,30,14,30,27,28,27,31,21,21,51,14,35,35,43,60,57,25,50,25,24,18,18,28,25,27,31,8,28,12,12,24,24,27,14,18,25,59,35,27,35,27,27,13,13,13,13,43,43,39,43,33,33,33,11,25,22,24,23,11,17,16,28,
15,25,26,15,25,19,24,21,34,40,33,31,27,30,34,30,30,17,17,17,42,42,42,24,44,34,13,25,19,41,32,41,32,34,25,17,17,35,34,35,34,37,34,40,27,33,27,33,35,20,23,11,23,10,23,13,37,31,37,31,31,43,33,30,15,30,15,
25,19,21,17,21,17,33,30,33,30,24,21,24,21,27,37,42,31,31,26,34,24,39,25,10,15,27,18,54,44,18,50,25,50,25,50,25,25,49,29,30,30,18,18,30,18,17,35,34,41,32,41,32,27,33,27,33,27,33,44,34,44,34,44,34,34,31,
34,31,13,11,13,11,13,11,13,9,24,11,30,25,25,23,11,37,31,39,31,43,33,43,33,30,15,25,19,21,17,33,30,33,30,33,30,33,30,47,42,31,27,11,35,34,50,58,43,33,19,19,35,14,29,36,14,43,32,42,11,35,29,23,37,27,24,
34,43,13,30,35,45,37,27,43,34,30,25,21,31,43,30,40,42,13,31,34,21,31,11,30,34,30,28,29,21,23,31,33,11,25,27,31,28,23,33,34,34,29,36,20,30,38,24,37,43,11,30,33,30,43,27,34,23,41,25,13,13,24,53,52,34,30,
32,32,35,29,29,23,37,27,47,29,37,37,30,35,45,34,43,34,30,41,21,32,44,30,35,27,50,53,34,40,30,41,55,29,34,33,23,18,30,33,38,21,31,31,25,28,44,30,33,30,34,32,19,27,54,24,33,23,47,50,26,34,24,32,42,22,33,
31,18,32,19,9,11,9,40,42,31,25,27,30,20,18,47,42,47,42,48,42,31,27,38,18,28,28,55,30,42,42,42,42,30,30,30,30,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,
36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,37,30,50,49,49,49,49,30,30,30,51,53,46,28,33,27,33,30,25,39,50,16,28,54,64,41,0,15,15,16,17,39,30,42,41,11,19,19,23,34,14,18,14,24,30,30,30,30,30,30,30,
30,30,30,14,14,33,33,33,32,47,39,31,44,40,29,26,47,37,14,26,32,25,49,40,47,32,47,33,27,24,36,39,50,33,34,26,19,33,19,35,27,20,37,37,35,37,35,17,36,33,11,11,27,12,52,33,35,37,37,16,21,18,33,30,46,26,30,
23,18,36,17,33,39,39,44,29,40,47,36,37,37,37,37,37,37,35,35,35,35,35,12,12,12,12,33,35,35,35,35,35,33,33,33,33,30,22,30,30,33,32,30,30,40,40,54,20,20,30,54,47,39,31,30,30,29,31,27,39,44,30,14,20,20,41,
62,35,32,16,33,30,30,30,33,22,22,54,15,39,39,47,64,61,27,54,27,26,19,19,30,27,30,34,9,30,14,14,26,26,30,14,19,27,62,39,29,39,29,29,14,14,14,14,47,47,43,47,36,36,36,12,27,24,26,24,12,18,17,30,16,27,28,
16,27,21,26,23,36,43,35,34,30,32,37,33,32,18,18,19,45,45,45,26,47,36,14,27,21,44,35,44,35,37,27,18,19,39,37,39,37,40,37,43,29,35,29,35,38,22,25,12,25,11,25,14,40,33,40,33,33,47,35,33,16,33,16,27,21,24,
18,24,18,36,33,36,33,26,23,26,23,29,40,45,34,33,28,37,26,42,27,11,17,29,19,59,47,19,54,27,54,27,54,27,27,53,32,33,33,19,19,33,19,18,39,37,44,35,44,35,29,35,29,35,29,35,47,36,47,36,47,36,37,33,37,33,14,
12,14,12,14,12,14,11,26,12,32,27,27,25,12,40,33,42,33,47,35,47,35,33,16,27,21,23,18,36,33,36,33,36,33,36,33,50,46,34,30,12,39,37,54,62,47,35,20,20,39,15,31,39,15,47,35,45,12,39,31,25,40,29,26,37,47,14,
32,38,49,40,29,47,37,32,27,24,34,46,33,43,45,14,34,37,23,33,12,32,37,32,30,31,23,25,33,35,12,27,29,33,30,25,35,36,36,31,39,22,32,41,26,40,46,12,32,35,32,46,29,36,25,44,27,14,14,26,58,56,37,32,35,35,39,
31,31,25,40,29,51,31,40,40,32,38,49,37,47,37,32,44,24,35,47,33,38,29,54,58,37,43,33,44,59,32,37,36,25,19,33,35,42,23,33,33,27,30,47,32,35,32,37,35,21,30,58,26,35,25,51,54,28,36,25,35,45,24,35,34,19,35,
21,11,12,11,43,46,34,27,30,32,22,19,50,46,50,46,52,46,34,30,41,19,30,30,59,32,45,45,45,45,32,33,32,32,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,
39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,33,54,53,53,53,53,32,32,32,55,57,50,30,36,29,36,32,27,42,54,18,30,58,69,44,0,16,16,17,18,42,32,45,44,11,21,21,25,35,16,19,16,25,32,32,32,32,32,32,32,32,32,
32,16,16,35,35,35,34,50,41,33,47,43,31,28,51,40,14,28,34,27,55,43,50,34,51,35,29,24,37,41,54,35,34,28,20,35,21,38,29,22,40,40,38,40,38,18,39,35,11,11,29,12,54,35,38,40,40,17,23,19,35,32,48,28,32,25,20,
39,19,35,41,41,47,31,43,50,37,40,40,40,40,40,40,38,38,38,38,38,12,12,12,12,35,38,38,38,38,38,35,35,35,35,32,23,32,32,36,34,31,32,43,43,58,22,21,32,58,50,41,31,32,32,32,33,29,41,48,32,16,21,21,45,67,38,
34,17,35,32,33,32,35,24,24,58,16,41,41,50,69,66,29,58,29,28,20,20,31,29,32,34,10,32,14,14,28,28,31,16,21,29,69,41,31,41,31,31,14,14,14,14,50,50,46,50,37,37,37,12,29,25,28,26,13,19,20,32,18,29,30,17,29,
23,28,25,39,46,38,34,32,34,40,35,35,19,19,20,48,48,48,28,51,39,14,29,23,47,38,47,38,40,29,19,20,41,40,41,40,43,40,46,31,38,31,38,41,23,27,12,27,12,27,15,43,35,43,35,36,50,38,35,17,35,17,29,23,24,19,24,
19,37,35,37,35,28,25,28,25,31,43,49,36,36,30,40,28,45,29,11,18,31,21,63,51,21,58,29,58,29,58,29,29,57,34,35,35,21,21,35,21,19,41,40,47,38,47,38,31,38,31,38,31,38,51,39,51,39,51,39,40,35,40,35,14,12,14,
12,14,12,14,11,28,12,34,29,29,27,12,43,35,45,35,50,38,50,38,35,17,29,23,25,20,37,35,37,35,37,35,37,35,54,48,34,32,12,41,40,58,67,50,38,22,22,41,16,34,42,16,50,37,49,12,41,33,27,43,31,28,40,50,14,34,41,
55,43,31,50,40,34,29,24,34,50,35,46,49,14,34,40,25,35,12,35,40,35,32,33,25,27,35,38,12,29,31,35,32,27,38,39,39,34,42,23,35,44,28,43,50,12,35,38,35,50,31,39,27,47,29,14,14,28,62,61,39,34,37,38,41,33,33,
27,43,31,54,34,43,43,34,41,55,40,50,40,34,47,24,37,51,35,41,31,58,62,40,46,35,47,64,34,40,39,27,21,35,38,45,25,36,36,29,32,51,35,38,35,40,38,22,32,63,28,38,27,55,58,30,39,27,37,48,26,38,36,21,37,23,11,
12,11,46,49,36,29,32,35,23,21,54,48,54,48,56,48,34,32,44,20,32,32,64,35,48,48,48,48,35,35,35,35,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,
41,41,41,41,41,41,41,41,41,41,41,41,42,35,58,57,57,57,57,35,35,35,59,61,53,32,39,31,38,34,29,45,58,19,32,67,80,50,0,19,19,19,21,48,37,52,51,13,25,23,28,41,18,22,18,29,37,37,37,37,37,37,37,37,37,37,18,
18,41,41,41,40,58,47,38,54,50,36,32,58,46,17,32,40,31,63,50,58,40,58,41,33,29,44,47,63,41,41,32,24,41,25,44,34,25,46,46,43,46,44,21,45,41,15,14,34,15,63,41,44,46,46,20,26,22,41,37,58,32,36,28,25,45,23,
41,47,47,54,36,50,58,44,46,46,46,46,46,46,43,44,44,44,44,15,15,15,15,41,44,44,44,44,44,41,41,41,41,37,27,37,37,41,40,38,37,50,50,67,25,25,37,66,58,48,37,37,37,37,39,33,48,55,37,19,25,25,51,78,44,40,19,
41,37,37,37,41,28,28,67,19,47,47,58,80,76,34,67,34,32,24,24,37,33,36,41,11,37,17,17,33,32,37,18,24,34,80,47,36,47,36,36,17,17,17,17,58,58,53,58,44,44,44,15,33,29,32,30,15,22,22,37,20,33,35,20,33,26,32,
28,45,53,44,41,36,40,46,41,40,22,22,23,56,56,56,32,58,45,17,33,26,54,43,54,43,46,34,22,23,47,46,47,46,50,46,53,36,44,36,44,47,27,31,15,31,14,31,18,50,41,50,41,41,58,44,41,20,41,20,33,26,29,22,29,22,44,
41,44,41,32,28,32,28,36,50,56,42,42,34,46,32,52,34,13,21,36,24,73,58,24,67,34,67,34,67,34,34,66,39,41,40,24,24,40,24,22,47,46,54,43,54,43,36,44,36,44,36,44,58,45,58,45,58,45,46,41,46,41,17,15,17,15,17,
15,17,15,32,15,40,34,34,31,15,50,41,52,41,58,44,58,44,41,20,33,26,29,23,44,41,44,41,44,41,44,41,63,58,41,36,15,47,46,66,78,58,44,25,25,47,19,39,49,18,58,43,56,15,47,38,31,50,36,32,46,58,17,40,47,63,50,
36,58,46,40,34,29,41,58,41,53,56,17,41,46,28,41,15,40,46,40,37,38,28,31,41,44,15,34,36,41,37,31,44,45,45,39,48,27,40,51,32,49,57,15,40,44,40,57,36,45,31,54,33,17,17,32,71,70,46,40,43,43,47,38,38,31,50,
36,63,39,50,50,40,47,63,46,58,46,40,54,29,43,58,41,47,36,68,71,46,53,41,54,73,39,46,45,31,24,41,44,52,28,41,41,34,37,59,40,44,40,46,43,26,36,73,32,44,31,63,67,35,45,32,43,56,30,44,42,24,43,26,15,15,14,
53,57,42,34,36,40,27,24,63,58,63,58,64,58,41,36,50,24,37,37,74,40,56,56,56,56,40,41,40,40,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,
48,48,48,48,48,48,48,48,48,48,49,40,67,66,66,66,66,40,40,40,68,71,61,37,45,36,44,40,34,52,67,22,37,75,90,56,0,21,21,23,23,54,42,58,57,15,25,27,30,46,20,25,20,33,42,42,42,42,42,42,42,42,42,42,20,20,45,
45,45,44,65,51,43,61,56,40,36,65,51,19,36,44,35,69,55,65,44,65,46,37,31,49,51,69,46,43,36,26,45,26,49,38,28,51,51,49,51,49,24,50,46,16,16,38,15,69,46,49,51,51,23,29,25,46,41,62,36,40,32,25,50,23,45,51,
51,61,40,55,65,49,51,51,51,51,51,51,49,49,49,49,49,15,15,15,15,46,49,49,49,49,49,46,46,46,46,41,30,42,42,46,44,42,42,56,56,75,28,28,41,74,65,53,41,41,41,40,43,37,53,62,41,19,28,28,58,87,49,44,23,45,41,
41,41,46,31,31,75,21,51,51,65,90,85,38,75,38,36,26,26,42,37,40,43,12,42,19,19,37,36,40,20,27,38,87,51,40,51,40,40,19,19,19,19,65,65,59,65,49,49,49,15,37,33,36,34,17,25,24,41,23,37,39,22,37,29,36,32,50,
59,49,43,40,44,51,45,45,25,25,26,62,62,62,36,65,50,19,37,29,61,49,61,49,51,38,25,26,51,51,51,51,56,51,59,40,49,40,49,53,30,35,15,35,15,35,20,55,46,55,46,46,65,49,46,23,46,23,37,29,31,25,31,25,49,46,49,
46,36,32,36,32,41,56,63,47,47,38,51,36,58,38,15,23,40,27,81,65,27,75,38,75,38,75,38,38,73,44,45,45,27,27,45,27,25,51,51,61,49,61,49,40,49,40,49,40,49,65,50,65,50,65,50,51,46,51,46,19,15,19,15,19,15,19,
16,36,15,44,38,38,35,15,55,46,58,46,65,49,65,49,46,23,37,29,32,25,49,46,49,46,49,46,49,46,69,62,43,40,15,51,51,74,87,65,49,28,28,51,21,44,55,20,65,48,63,15,51,43,35,55,40,36,51,65,19,44,53,69,55,40,65,
51,44,38,31,43,64,46,59,63,19,43,51,32,46,15,45,51,45,42,43,32,35,46,49,15,38,40,46,41,35,49,50,50,43,54,30,45,57,36,55,64,15,45,49,45,64,40,50,35,61,37,19,19,36,80,78,51,44,48,49,51,43,43,35,56,40,70,
44,55,55,44,53,69,51,65,51,44,61,31,48,65,46,53,40,76,80,51,59,45,61,82,44,51,50,35,27,45,49,58,32,46,46,38,42,66,45,49,45,51,49,29,40,81,36,49,34,71,75,39,50,35,48,63,33,49,47,27,48,29,16,15,16,59,63,
47,38,40,45,30,27,69,62,69,62,72,62,43,40,56,26,42,42,82,45,62,62,62,62,45,45,45,45,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,55,45,75,74,74,74,74,45,45,45,77,79,69,41,50,40,50,44,38,58,75,24,42,83,99,62,0,23,23,25,26,60,46,64,63,16,29,30,34,52,22,28,22,36,46,46,46,46,46,46,46,46,46,46,22,22,50,50,50,
49,72,59,48,67,62,45,40,72,57,20,40,49,38,77,61,72,49,72,50,41,35,54,59,80,51,50,40,29,50,30,55,42,31,57,57,54,57,54,26,56,51,17,17,42,17,78,51,54,57,57,25,32,29,50,46,70,40,44,35,28,56,27,50,59,59,67,
45,61,72,54,57,57,57,57,57,57,54,54,54,54,54,17,17,17,17,51,54,54,54,54,54,50,50,50,50,46,33,46,46,51,50,46,46,62,62,83,31,31,46,82,72,59,47,46,46,45,48,41,59,68,46,22,31,31,64,96,54,49,25,50,46,47,46,
51,35,35,84,23,59,59,72,99,94,42,83,42,40,29,29,45,41,44,50,14,46,21,21,40,40,47,23,29,42,98,59,45,59,45,45,20,20,20,20,72,72,66,72,54,54,54,17,42,36,40,38,18,28,28,46,25,42,43,26,41,32,40,35,56,66,54,
50,44,49,57,50,49,28,28,29,69,69,69,40,72,56,20,41,32,67,54,67,54,57,42,28,29,59,57,59,57,62,57,66,45,54,45,54,59,33,38,17,38,17,38,22,61,51,61,51,51,72,54,50,25,50,25,41,32,35,29,35,29,54,50,54,50,40,
35,40,35,45,62,69,52,51,42,57,40,64,42,16,26,44,30,90,72,30,83,42,83,42,83,42,42,81,49,50,50,29,29,50,29,28,59,57,67,54,67,54,45,54,45,54,45,54,72,56,72,56,72,56,57,51,57,51,20,17,20,17,20,17,20,17,40,
17,49,42,42,38,17,61,51,64,51,72,54,72,54,50,25,41,32,35,28,54,50,54,50,54,50,54,50,80,70,50,44,17,59,57,82,96,72,54,31,31,59,23,48,60,22,72,54,69,17,59,48,38,61,45,40,57,72,20,49,58,77,61,44,72,57,49,
42,35,50,71,51,66,69,20,50,57,35,51,17,49,57,49,46,47,35,39,51,54,17,42,45,51,46,39,54,56,56,48,60,33,49,64,40,61,71,17,49,54,49,71,45,56,38,67,41,20,20,40,88,87,56,49,54,54,59,48,48,38,62,45,78,48,61,
61,49,58,77,57,72,57,49,67,35,54,72,51,59,45,84,88,57,66,50,67,91,48,57,56,39,30,50,54,64,35,51,51,42,46,73,50,54,50,57,54,32,44,90,40,54,38,79,83,43,56,39,53,69,37,54,52,30,53,32,17,17,17,66,70,52,42,
44,50,34,30,80,70,80,70,80,70,50,44,62,29,46,46,91,50,69,69,69,69,50,50,50,50,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,61,50,83,82,82,82,82,50,50,50,85,87,76,46,55,44,55,49,42,64,83,27,46,92,110,69,0,25,25,27,28,66,51,71,70,18,32,33,39,57,25,31,25,40,51,51,51,51,51,51,51,51,51,51,25,25,56,56,56,54,80,
66,53,75,68,49,45,80,63,23,44,54,43,84,68,80,54,80,56,46,39,60,63,87,56,54,44,32,56,33,62,46,35,63,63,60,63,60,29,62,56,19,19,46,19,86,56,60,63,63,28,36,31,56,52,76,44,49,39,31,62,29,56,66,66,75,49,68,
80,60,63,63,63,63,63,63,60,60,60,60,60,19,19,19,19,56,60,60,60,60,60,56,56,56,56,51,37,51,51,57,54,51,51,69,69,92,35,34,51,91,80,66,51,51,51,50,53,45,66,76,51,26,34,34,71,106,60,54,27,56,51,52,51,56,39,
39,93,26,66,66,80,110,105,46,92,46,45,32,32,50,45,49,54,15,51,23,23,45,45,50,25,33,46,107,66,49,66,49,49,23,23,23,23,80,80,73,80,60,60,60,19,46,40,45,42,20,31,31,51,28,46,48,28,46,36,44,39,62,73,60,54,
49,54,63,56,55,31,31,32,76,76,76,45,80,62,23,46,36,75,60,75,60,63,46,31,32,66,63,66,63,68,63,73,49,60,49,60,65,37,43,19,43,19,43,24,68,56,68,56,56,80,60,56,28,56,28,46,36,39,31,39,31,60,56,60,56,44,39,
44,39,50,69,77,58,57,47,63,44,71,46,18,28,49,33,100,80,33,92,46,92,46,92,46,46,90,54,56,56,33,33,56,33,31,66,63,75,60,75,60,49,60,49,60,49,60,80,62,80,62,80,62,63,56,63,56,23,19,23,19,23,19,23,19,44,19,
54,46,46,43,19,68,56,71,56,80,60,80,60,56,28,46,36,39,31,60,56,60,56,60,56,60,56,87,76,54,49,19,66,63,91,106,80,60,35,35,66,25,53,67,25,80,59,77,19,66,53,43,68,49,44,63,80,23,54,65,84,68,49,80,63,54,46,
39,54,79,56,73,77,23,54,63,39,56,19,55,63,55,51,53,39,43,56,60,19,46,49,56,52,43,60,62,62,53,66,37,55,70,44,68,79,19,55,60,55,79,49,62,43,75,46,23,23,44,98,96,62,54,59,60,66,53,53,43,69,49,86,53,68,68,
54,65,84,63,80,63,54,75,39,59,80,56,65,50,93,98,63,73,56,75,101,54,63,62,43,33,56,60,71,39,57,57,46,51,81,55,60,55,63,60,35,49,100,44,60,42,87,92,48,62,43,59,77,41,60,58,33,59,36,19,19,19,73,78,58,46,
49,55,37,33,87,76,87,76,88,76,54,49,69,32,51,51,101,55,76,76,76,76,55,56,55,55,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
66,66,66,66,66,66,67,56,92,91,91,91,91,55,55,55,94,97,84,51,61,49,61,54,47,71,92,30,51,100,119,75,0,28,28,29,31,72,55,77,76,20,35,36,43,61,27,33,27,44,55,55,55,55,55,55,55,55,55,55,27,27,61,61,61,59,87,
74,57,81,74,54,48,87,68,25,48,59,46,93,74,87,59,87,61,50,42,65,69,94,61,59,48,35,61,36,67,50,38,68,68,65,69,65,31,67,61,20,20,50,22,95,61,65,68,68,30,39,32,61,55,84,48,53,42,35,67,33,61,74,74,81,54,74,
87,65,68,68,68,68,68,68,65,65,65,65,65,22,22,22,22,61,65,65,65,65,65,61,61,61,61,55,40,55,55,61,60,55,55,75,75,100,38,37,55,99,87,71,55,55,55,53,58,49,71,82,55,28,37,37,77,116,65,59,29,61,55,56,55,61,
41,41,100,28,74,74,87,119,114,50,100,50,48,35,35,56,49,53,59,17,55,25,25,49,48,54,27,35,50,117,74,54,74,54,54,25,25,25,25,87,87,79,87,65,65,65,22,50,44,48,45,22,33,34,55,30,50,52,29,50,39,48,42,67,79,
65,59,53,59,68,61,58,33,33,34,83,83,83,48,87,67,25,50,39,81,65,81,65,69,50,33,34,74,68,74,68,74,69,79,54,65,54,65,71,40,46,22,46,21,46,26,74,61,74,61,61,87,65,61,30,61,30,50,39,42,32,42,32,65,61,65,61,
48,42,48,42,54,75,84,63,62,51,68,48,77,50,20,31,53,36,108,87,36,100,50,100,50,100,50,50,98,59,61,60,35,35,60,35,33,74,68,81,65,81,65,54,65,54,65,54,65,87,67,87,67,87,67,68,61,68,61,25,22,25,22,25,22,25,
20,48,22,59,50,50,46,22,74,61,78,61,87,65,87,65,61,30,50,39,43,34,65,61,65,61,65,61,65,61,94,84,59,53,22,74,68,99,116,87,65,38,38,74,28,58,73,27,87,65,84,22,74,57,46,74,54,48,68,87,25,59,70,93,74,53,87,
68,59,50,42,59,86,61,79,84,25,59,68,42,61,22,60,68,60,55,57,42,47,61,65,22,50,54,61,55,47,65,67,67,58,72,40,60,77,48,74,86,22,60,65,60,86,54,67,46,81,50,25,25,48,107,104,68,59,65,65,74,57,57,46,75,54,
94,58,74,74,59,70,93,68,87,68,59,81,42,65,87,61,71,54,101,107,68,79,61,81,110,58,68,67,47,36,61,65,77,42,62,62,50,55,88,60,65,60,68,65,38,53,108,48,65,46,95,100,52,67,47,64,84,44,65,63,36,64,39,20,22,
20,79,85,63,50,53,60,40,36,94,84,94,84,96,84,59,53,75,35,55,55,110,60,83,83,83,83,60,61,60,60,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,
71,71,71,71,71,71,71,71,71,71,71,73,60,100,99,99,99,99,60,60,60,102,105,92,55,67,53,66,59,51,77,100,32,55,0,2,1,0,0,0,5,0,5,0,0,3,0,7,0,77,177,5,4,184,1,24,178,0,6,7,187,1,24,0,2,0,1,1,215,181,3,3,0,10,
6,5,184,1,23,182,3,3,2,74,9,7,4,184,1,23,182,1,0,73,8,149,173,24,43,78,16,244,60,77,245,60,78,16,246,60,77,16,245,60,0,63,60,16,253,60,245,60,16,245,60,49,48,33,17,33,17,37,33,17,33,1,0,4,0,252,32,3,192,
252,64,5,0,251,0,32,4,192,0,2,0,179,255,228,1,169,5,228,0,3,0,15,0,90,185,0,2,1,42,64,28,4,124,10,11,3,0,0,3,1,2,17,71,71,74,5,7,155,1,127,5,2,155,13,73,16,103,150,24,43,78,16,244,77,244,67,88,183,0,2,
32,2,2,240,2,1,1,93,113,89,253,244,67,88,183,0,7,32,7,2,240,7,1,1,93,113,89,78,69,101,68,230,17,18,57,57,0,63,63,77,253,254,49,48,1,17,35,17,19,50,22,21,20,6,35,34,38,53,52,54,1,117,145,74,51,72,72,51,
51,72,72,5,228,251,140,4,116,250,248,72,52,51,73,73,51,52,72,0,0,2,0,48,4,21,2,73,5,228,0,3,0,7,0,86,64,9,1,4,0,5,2,7,3,0,5,184,1,5,64,12,3,6,0,0,1,3,2,4,5,7,6,2,184,1,133,64,9,31,3,47,3,2,3,74,9,7,184,
1,133,181,6,73,8,89,153,24,43,78,16,244,77,237,78,16,246,93,77,237,17,18,57,57,17,18,57,57,0,63,60,253,60,18,57,57,17,18,57,57,49,48,1,35,3,51,1,35,3,51,2,50,103,22,148,254,101,104,22,148,4,21,1,207,254,
49,1,207,0,2,0,184,0,0,5,10,5,233,0,27,0,31,1,26,64,118,23,27,23,30,2,31,11,0,21,4,30,11,0,18,7,29,14,25,18,7,28,14,25,21,4,27,11,0,22,3,26,14,25,22,3,23,15,24,22,3,20,15,24,21,4,19,15,24,18,7,16,15,24,
17,8,13,14,25,17,8,12,11,0,17,8,9,10,1,17,8,6,10,1,18,7,5,10,1,21,4,2,10,1,22,3,22,3,3,93,4,21,20,4,4,21,18,7,7,93,8,17,20,8,8,17,4,7,3,8,21,18,22,17,1,10,192,0,11,184,1,253,64,16,3,8,10,24,15,192,25,
15,14,1,14,202,22,17,0,4,190,1,252,0,21,1,127,0,3,1,252,0,22,1,45,64,14,0,155,15,25,1,9,15,25,1,8,25,74,33,18,190,1,252,0,7,1,127,0,17,1,252,0,8,1,45,64,13,15,155,0,10,16,10,2,10,73,32,103,150,24,43,78,
16,244,93,77,228,244,228,253,228,78,16,246,94,93,94,93,77,228,244,228,253,228,0,63,60,253,93,60,253,60,63,60,244,60,253,60,17,18,57,57,17,18,57,57,135,5,46,43,125,16,196,135,46,24,43,125,16,196,15,15,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,49,48,1,93,1,21,35,3,35,19,33,3,35,19,35,53,33,19,35,53,33,19,51,3,33,19,51,3,51,21,35,11,1,33,3,33,4,209,248,72,112,72,254,179,76,110,76,246,1,7,51,253,1,13,
70,107,68,1,76,68,112,69,224,240,48,62,254,178,49,1,76,2,90,108,254,18,1,238,254,18,1,238,108,1,78,109,1,212,254,44,1,212,254,44,109,254,178,1,78,254,178,0,0,3,0,72,254,163,4,46,6,38,0,38,0,47,0,54,1,
90,64,42,59,32,96,27,123,24,116,27,123,41,116,47,112,49,127,53,155,24,155,41,148,45,171,23,180,4,187,23,196,4,15,49,64,19,21,57,7,64,18,21,57,27,184,255,192,64,43,18,22,57,0,5,1,137,24,128,27,128,41,143,
49,4,68,11,79,32,79,49,96,27,4,52,11,63,49,80,27,95,49,4,5,11,15,32,10,36,111,49,4,9,184,255,224,179,17,21,57,47,184,255,224,64,51,17,21,57,2,8,54,48,18,19,38,39,29,28,21,20,8,7,40,3,39,2,3,37,3,38,48,
49,27,3,18,22,17,16,4,21,54,9,29,47,9,47,28,39,1,19,0,20,15,5,1,5,184,2,1,179,15,6,1,6,184,2,2,178,39,126,0,184,1,124,181,38,5,0,25,1,25,184,2,1,179,0,26,1,26,184,2,0,178,28,126,20,184,1,255,64,10,21,
13,19,20,0,249,1,1,43,6,184,1,254,179,47,5,1,5,184,1,122,64,15,51,111,13,74,56,43,111,32,34,48,34,64,34,3,34,186,1,122,0,26,1,254,181,25,73,55,137,166,24,43,78,16,244,77,237,244,93,237,78,16,246,77,237,
244,93,237,17,57,47,253,57,57,0,63,236,253,244,93,228,93,63,236,253,244,93,228,93,17,18,57,57,17,18,57,57,17,51,17,51,17,23,51,23,50,17,23,51,17,23,51,3,5,16,60,60,14,60,60,60,14,16,60,60,60,60,60,0,43,
43,49,48,1,93,93,93,93,93,43,43,43,0,93,1,51,21,30,1,23,7,38,39,17,4,23,22,21,20,6,7,6,7,17,35,17,46,2,39,55,22,23,17,38,39,46,1,53,52,62,1,55,21,14,2,21,20,23,22,23,19,62,1,53,52,38,39,2,19,131,98,139,
64,108,77,116,1,6,64,82,121,103,67,117,131,123,148,141,47,107,139,213,157,42,85,82,90,155,121,75,92,53,42,56,122,131,121,145,111,155,6,38,109,18,92,90,87,119,25,254,13,138,86,110,133,110,183,51,33,15,
254,199,1,57,10,58,117,77,81,184,21,2,107,77,28,58,142,93,90,154,96,12,139,6,55,93,56,72,50,68,55,252,253,17,142,88,86,146,83,0,0,4,0,46,255,154,6,5,6,0,0,25,0,37,0,49,0,61,1,1,64,28,24,2,1,101,8,3,2,
3,4,2,93,1,0,20,1,1,0,3,5,0,2,25,1,159,44,38,97,50,184,2,3,64,14,56,97,44,13,5,106,22,159,25,168,18,11,97,32,184,2,3,64,9,26,97,18,5,0,0,59,53,2,184,1,127,182,1,1,35,29,53,121,47,184,1,84,183,59,121,41,
74,63,35,121,8,184,1,84,183,29,121,14,73,62,89,153,24,43,78,16,244,77,237,253,237,78,16,246,77,237,253,237,17,18,57,47,237,17,18,57,47,0,63,253,246,237,16,228,244,237,63,253,246,237,16,244,17,57,57,18,
57,135,5,46,43,8,125,16,196,49,48,24,67,121,64,78,39,61,27,34,9,17,16,38,33,10,35,87,1,31,12,29,87,0,27,17,29,87,0,57,43,59,87,1,55,45,53,87,0,61,39,59,87,1,51,49,53,87,0,34,9,32,87,0,30,13,32,87,0,28,
15,26,87,1,58,42,56,87,0,54,46,56,87,0,60,40,50,87,1,52,48,50,87,1,0,43,43,43,43,43,43,43,1,43,43,43,43,43,43,43,43,129,129,129,1,93,9,1,35,1,6,35,39,22,21,20,6,35,34,38,53,52,62,1,51,50,23,22,51,50,54,
55,5,34,6,21,20,22,51,50,54,53,52,38,1,50,22,21,20,6,35,34,38,53,52,54,23,34,6,21,20,22,51,50,54,53,52,38,5,101,251,208,132,3,207,173,249,54,62,191,158,145,198,90,166,87,37,85,130,152,112,199,159,252,
153,91,128,128,91,91,129,129,2,200,143,203,203,143,143,203,203,143,91,128,128,91,91,129,129,6,0,249,154,5,212,42,1,86,96,137,216,201,144,96,157,96,18,28,29,45,155,129,91,91,128,128,91,91,129,253,36,203,
143,143,203,203,143,143,203,127,128,91,91,128,128,91,91,128,0,0,3,0,179,255,219,5,217,5,138,0,35,0,49,0,62,1,111,64,177,10,9,31,0,31,1,47,0,47,1,47,2,52,31,7,132,48,171,38,180,31,180,32,180,49,5,10,19,
32,0,32,2,59,37,75,31,79,37,100,32,111,37,127,18,112,31,10,59,8,130,18,130,36,146,18,146,36,162,18,162,36,178,18,178,36,194,18,194,36,10,239,29,239,40,2,0,7,62,50,18,3,61,36,32,33,62,50,18,3,61,36,32,
33,2,1,1,10,35,59,59,0,4,5,6,7,7,33,60,59,0,61,8,34,59,0,33,7,9,10,1,61,8,3,10,1,33,7,1,10,10,85,59,0,20,59,59,0,61,8,8,85,7,33,20,7,7,33,33,1,61,3,8,0,43,218,25,3,0,201,8,8,56,97,12,9,61,33,53,8,40,99,
9,15,29,1,8,29,188,2,5,0,1,1,125,0,8,2,4,181,7,74,64,46,99,21,184,1,45,183,53,99,15,73,63,103,114,24,43,78,16,244,77,237,244,237,78,16,246,77,237,228,244,94,93,94,237,17,18,57,57,0,63,237,63,237,63,237,
17,18,23,57,135,5,46,43,14,125,16,196,135,14,46,24,43,14,125,16,196,15,15,15,15,135,14,16,196,196,196,135,14,16,196,135,14,16,196,1,17,51,51,17,23,51,0,17,51,51,17,23,51,46,1,46,1,93,0,93,49,48,24,67,
121,64,42,54,55,41,45,22,28,13,14,27,37,23,38,55,13,53,87,0,42,26,40,107,1,44,24,46,107,0,54,14,56,87,0,41,28,43,107,1,45,22,43,107,1,0,43,43,43,1,43,43,43,43,43,129,129,129,129,1,93,93,0,93,1,23,6,7,
22,23,22,23,35,39,14,1,35,34,38,53,52,54,55,46,1,53,52,55,54,51,50,30,1,21,20,6,7,31,1,54,1,54,55,54,53,52,38,35,34,6,21,20,23,22,19,14,1,21,20,22,51,50,55,54,55,39,38,5,12,100,96,77,51,96,76,55,205,189,
190,230,128,170,206,139,214,121,69,85,98,146,92,152,80,104,153,223,153,110,253,191,107,54,38,99,82,78,98,20,49,71,187,116,142,103,78,75,118,161,240,60,2,32,106,85,62,54,97,76,64,197,144,90,195,146,110,
221,169,146,139,63,110,72,84,74,125,70,74,167,130,234,153,92,1,149,83,80,57,44,51,74,76,52,40,35,85,254,216,141,167,71,84,129,32,51,115,246,63,0,1,0,129,4,21,1,21,5,228,0,3,0,28,185,0,1,1,5,64,10,2,0,
3,182,2,73,4,95,113,24,43,78,16,244,77,237,0,63,237,49,48,19,35,3,51,254,103,22,148,4,21,1,207,0,1,1,11,254,86,2,120,6,0,0,13,0,52,64,27,7,1,0,8,19,0,17,15,71,71,74,8,99,7,155,0,197,1,162,4,99,11,73,14,
149,151,24,43,78,16,244,77,253,244,237,244,237,78,69,101,68,230,0,63,63,18,57,57,49,48,1,51,6,2,17,16,18,23,35,38,2,17,16,18,1,214,162,98,118,89,78,154,74,88,104,6,0,201,253,232,254,227,254,248,254,22,
186,178,1,226,1,5,1,25,2,21,0,1,0,124,254,86,1,233,6,0,0,13,0,56,64,14,7,1,0,8,17,0,19,15,71,71,74,11,99,4,184,1,45,64,12,8,99,7,155,0,197,1,73,14,95,173,24,43,78,16,244,77,237,244,237,244,253,78,69,101,
68,230,0,63,63,18,57,57,49,48,1,35,54,18,17,16,2,39,51,22,18,17,16,2,1,30,162,99,117,89,78,154,75,87,104,254,86,201,2,24,1,29,1,8,1,234,186,178,254,29,254,251,254,232,253,235,0,1,0,88,3,23,3,14,5,228,
0,17,0,112,64,19,9,8,7,6,11,12,13,7,10,15,16,1,2,3,4,5,7,0,10,186,1,2,0,14,1,2,64,28,0,0,3,4,5,7,4,6,11,17,0,1,2,8,6,9,12,14,15,16,4,10,13,19,71,71,74,6,188,2,6,0,9,1,127,0,10,2,6,181,13,73,18,119,152,
24,43,78,16,244,77,244,253,244,78,69,101,68,230,17,18,23,57,17,23,57,18,23,57,0,63,77,253,229,18,23,57,18,23,57,49,48,1,51,3,55,23,13,1,7,39,19,35,19,7,39,45,1,55,23,1,113,130,29,246,66,254,235,1,21,66,
246,29,130,31,246,66,1,25,254,231,66,246,5,228,254,215,176,112,125,123,113,174,254,215,1,41,174,113,123,125,112,176,0,0,1,0,115,0,233,4,103,4,214,0,11,0,88,64,53,9,10,5,1,8,6,10,5,2,7,3,11,4,2,7,0,11,
4,1,8,4,5,10,1,228,11,127,8,228,10,2,1,7,8,13,71,71,74,5,228,7,127,8,228,0,10,1,10,73,12,95,113,24,43,78,16,244,93,77,244,253,244,78,69,101,68,230,17,18,57,57,0,47,77,228,253,228,18,57,57,15,15,15,15,
49,48,1,17,51,17,33,21,33,17,35,17,33,53,2,40,137,1,182,254,74,137,254,75,3,36,1,178,254,78,137,254,78,1,178,137,0,1,0,128,255,84,1,174,1,14,0,3,0,50,178,3,1,2,184,1,5,64,9,0,0,2,3,5,71,71,74,1,184,2,
7,181,3,73,4,95,113,24,43,78,16,244,77,253,78,69,101,68,230,18,57,57,0,47,77,237,57,57,49,48,1,23,3,39,1,39,135,203,99,1,14,64,254,134,42,0,0,1,0,65,1,236,2,103,2,102,0,3,0,44,64,18,1,2,0,98,22,3,1,0,
3,2,74,5,3,73,4,89,114,24,43,78,16,228,16,238,17,57,57,0,47,75,81,88,176,128,26,89,77,237,57,57,49,48,19,33,21,33,65,2,38,253,218,2,102,122,0,1,0,187,255,228,1,177,0,220,0,11,0,43,64,22,192,0,1,0,124,
6,11,13,71,71,74,192,3,1,3,116,9,73,12,103,113,24,43,78,16,244,77,253,93,78,69,101,68,230,0,63,77,237,93,49,48,37,50,22,21,20,6,35,34,38,53,52,54,1,54,51,72,72,51,51,72,72,220,72,52,51,73,73,51,52,72,
0,0,1,0,72,255,56,3,68,5,228,0,3,0,64,64,18,3,0,1,1,85,2,3,20,2,2,3,2,3,0,1,0,0,3,184,1,133,179,0,74,5,1,184,1,133,181,2,73,4,119,114,24,43,78,16,244,77,237,78,16,246,77,237,0,63,47,18,57,57,135,5,46,
43,135,125,196,49,48,9,1,35,1,3,68,253,157,153,2,98,5,228,249,84,6,172,0,0,2,0,65,255,219,4,45,5,228,0,15,0,32,0,127,64,23,83,8,20,126,12,13,29,126,4,5,25,111,8,74,34,16,111,0,73,33,137,166,24,43,78,16,
244,77,237,78,16,246,77,237,0,63,237,63,237,49,48,67,121,64,62,1,32,10,38,23,24,22,24,2,6,18,38,14,37,6,37,27,38,31,37,2,38,21,11,25,229,1,19,13,16,229,0,28,5,25,229,1,30,3,16,229,0,24,9,20,229,0,17,15,
20,229,0,26,7,29,229,1,32,1,29,229,1,43,43,43,43,1,43,43,43,43,43,43,43,43,43,43,42,43,129,19,16,18,54,51,50,22,18,17,16,2,6,35,34,38,2,19,20,30,1,51,50,54,55,54,53,52,2,38,35,34,14,1,65,125,228,141,143,
232,135,133,234,143,141,226,127,139,89,174,97,98,170,44,55,98,173,96,98,172,90,2,223,1,35,1,62,164,165,254,182,254,234,254,235,254,184,167,162,1,65,1,30,249,255,132,129,129,157,221,222,1,27,131,131,255,
0,1,1,35,0,0,2,156,5,191,0,5,0,56,64,18,2,1,3,4,5,194,0,4,3,12,1,4,2,0,5,2,249,3,184,2,8,178,5,73,6,186,1,56,1,107,0,24,43,78,16,244,77,244,237,18,57,18,57,57,0,63,63,253,60,18,57,57,49,48,1,33,17,35,
17,35,1,123,1,33,146,231,5,191,250,65,5,47,0,1,0,61,0,0,4,36,5,228,0,23,0,169,64,56,88,2,153,17,201,3,198,9,4,57,3,73,2,73,3,3,23,22,39,22,56,2,3,23,8,0,48,18,20,57,1,64,18,20,57,10,11,11,140,14,15,20,
14,14,15,11,13,14,10,15,21,12,194,14,12,0,184,1,161,64,19,21,126,4,5,15,18,14,10,11,18,111,7,241,13,74,25,0,111,1,186,2,10,0,11,2,9,181,14,73,24,137,166,24,43,78,16,244,77,237,244,237,78,16,246,77,244,
237,18,57,17,18,57,0,63,253,228,63,237,17,57,57,17,57,57,135,5,46,43,14,125,16,196,1,43,43,49,48,24,67,121,64,14,19,20,5,6,20,5,18,108,1,19,6,21,108,1,0,43,1,43,129,129,1,93,93,93,19,35,54,0,51,50,18,
21,20,6,7,1,33,21,33,1,62,1,53,52,38,35,34,6,237,141,6,1,23,205,203,251,120,173,254,146,2,167,252,25,2,50,171,103,185,134,141,187,3,242,218,1,24,254,250,178,125,219,187,254,117,142,2,95,183,177,98,124,
179,188,0,0,1,0,72,255,219,4,32,5,228,0,43,0,197,64,20,93,31,91,36,107,3,107,36,4,31,64,18,21,57,36,64,16,21,57,24,184,255,192,64,30,11,21,57,185,35,207,32,2,169,31,169,35,185,31,3,46,8,10,33,126,15,34,
96,34,2,34,34,41,21,22,184,1,155,181,26,126,18,13,1,0,184,2,11,64,11,41,126,4,5,10,34,34,22,38,111,8,184,2,20,183,29,111,14,74,45,0,111,1,184,2,10,183,22,111,21,73,44,137,166,24,43,78,16,244,77,237,244,
237,78,16,246,77,237,244,237,17,57,47,57,0,63,253,244,60,63,253,244,60,18,57,47,93,237,57,49,48,67,121,64,32,39,40,27,28,15,17,5,7,16,38,6,37,27,17,29,108,1,40,5,38,108,1,28,15,26,108,0,39,7,41,108,1,
43,43,1,43,43,43,43,129,129,129,129,1,93,93,43,43,43,93,1,35,62,1,51,50,30,1,21,20,7,22,23,22,21,20,14,1,35,34,38,39,51,22,23,22,51,50,54,53,52,46,1,39,53,50,62,1,53,52,38,35,34,6,1,15,150,41,232,158,
115,199,109,189,106,68,96,132,228,141,190,254,39,144,38,71,91,141,160,194,97,163,171,101,166,75,153,117,95,138,4,106,182,196,105,178,97,190,111,43,83,117,145,125,227,124,219,212,143,64,81,192,129,86,150,
76,9,135,71,110,65,96,140,107,0,0,2,0,52,0,0,4,56,5,228,0,9,0,12,0,109,64,20,11,12,12,140,9,0,20,9,9,0,3,12,194,4,9,9,0,7,12,11,184,2,13,64,10,0,5,0,11,1,11,7,249,1,6,184,1,139,64,16,15,4,31,4,47,4,3,
9,15,4,1,8,4,74,14,12,184,2,12,181,9,73,13,137,166,24,43,78,16,244,77,237,78,16,246,94,93,94,93,77,252,60,253,60,17,18,57,0,63,237,63,18,57,47,60,253,60,135,5,46,43,4,125,16,196,49,48,1,51,17,51,21,35,
17,35,17,33,37,17,1,3,104,30,178,178,147,253,65,2,191,254,79,5,228,251,255,141,254,170,1,86,141,2,101,253,155,0,1,0,83,255,219,4,21,5,191,0,29,0,176,64,25,180,18,192,18,2,52,18,68,18,2,38,8,2,3,3,140,
28,29,20,28,28,29,3,5,28,184,2,16,64,13,26,126,5,5,20,2,2,1,194,29,0,4,16,184,1,152,180,20,126,12,13,0,184,2,10,181,23,111,8,74,31,2,190,1,122,0,3,2,15,0,29,2,14,0,28,2,14,181,16,111,15,73,30,213,185,
1,20,0,24,43,78,16,244,77,237,244,228,253,228,78,16,246,77,237,228,0,63,253,228,63,60,253,60,17,18,57,47,253,230,17,51,135,14,46,43,5,125,16,196,49,48,24,67,121,64,26,21,25,6,11,10,38,21,11,23,108,1,25,
6,23,108,1,22,9,20,108,0,24,7,26,108,1,0,43,43,1,43,43,43,129,129,1,93,93,1,21,33,3,54,51,50,0,21,20,14,1,35,34,38,39,51,30,2,51,50,54,53,52,38,35,34,7,19,3,239,253,244,73,96,77,201,1,5,134,229,150,179,
246,24,151,17,81,135,74,145,208,188,157,130,185,136,5,191,140,254,111,28,254,243,210,145,242,129,219,174,85,106,65,220,165,149,186,79,2,218,0,0,2,0,138,255,219,4,20,5,228,0,18,0,30,0,182,64,24,54,2,1,
143,21,1,52,8,18,3,20,2,1,1,140,0,18,20,0,0,18,19,126,2,184,2,101,64,14,4,4,0,5,25,126,11,13,2,1,22,18,15,1,184,2,17,64,24,0,0,15,28,111,0,7,16,7,2,7,74,32,22,111,0,15,16,15,2,15,73,31,215,185,1,20,0,
24,43,78,16,244,93,77,237,78,16,246,93,77,237,18,57,47,237,18,57,17,18,57,0,63,237,63,57,47,237,237,135,14,46,43,14,125,16,196,1,50,50,0,46,49,48,24,67,121,64,38,23,30,5,14,9,38,13,37,26,10,28,108,1,24,
12,22,108,0,30,5,28,108,1,27,8,25,108,0,23,14,25,108,0,29,6,19,108,1,43,43,43,1,43,43,43,43,43,129,129,0,93,1,93,1,23,1,54,51,50,22,21,20,14,1,35,34,46,1,53,52,54,55,5,34,6,21,20,22,51,50,54,53,52,38,
2,239,121,254,115,80,70,175,244,118,217,125,121,207,118,73,94,1,29,128,181,181,128,128,181,181,5,228,79,253,166,27,253,185,127,205,121,117,212,121,90,199,140,117,181,129,128,181,181,128,129,181,0,0,1,
0,147,255,219,4,56,5,191,0,5,0,76,64,21,3,4,4,140,1,2,20,1,1,2,4,1,5,194,0,4,2,13,0,5,4,184,2,19,181,1,74,7,5,241,2,184,2,17,178,3,73,6,184,2,18,177,166,24,43,78,16,244,77,237,228,78,16,246,77,237,17,
57,0,63,63,237,57,57,135,5,46,43,14,125,16,196,49,48,19,33,1,39,1,33,147,3,165,252,237,121,2,168,253,63,5,191,250,28,62,5,27,0,0,3,0,69,255,219,4,41,5,228,0,26,0,39,0,52,0,211,64,25,130,8,0,13,33,126,
16,40,96,40,2,40,40,47,27,126,20,5,47,126,7,13,37,111,24,184,2,20,183,50,111,3,74,54,30,111,16,184,2,20,183,43,111,10,73,53,137,166,24,43,78,16,244,77,237,244,237,78,16,246,77,237,244,237,0,63,237,63,
253,17,57,47,93,253,57,57,49,48,67,121,64,98,1,52,5,38,45,38,22,37,18,38,35,37,48,6,50,108,1,46,8,43,108,0,39,21,37,108,1,28,19,30,108,0,41,12,43,108,2,32,14,30,108,2,34,26,37,108,3,52,1,50,108,3,49,4,
47,108,0,44,9,47,108,0,38,23,27,108,1,29,17,27,108,1,42,11,40,108,1,12,31,15,33,108,0,14,13,36,25,33,108,0,26,51,2,40,108,1,1,0,16,60,43,60,43,16,60,43,60,43,43,43,43,43,1,43,43,43,43,43,43,43,43,43,43,
43,43,43,129,1,30,1,21,20,7,6,35,34,2,53,52,54,55,46,1,53,52,62,1,51,50,30,1,21,20,6,1,34,6,21,20,22,51,50,62,1,53,52,38,3,34,6,21,20,30,1,51,50,54,53,52,38,3,19,149,129,111,136,253,244,252,132,154,108,
108,115,203,118,115,196,111,105,254,188,121,159,171,114,73,130,73,144,130,152,206,88,158,104,161,190,201,3,39,74,190,121,170,130,159,1,23,168,123,197,77,56,166,95,96,183,105,106,182,100,100,156,1,245,
143,99,98,159,72,125,63,89,150,253,136,197,131,81,144,78,190,127,123,191,0,2,0,100,255,219,3,238,5,228,0,18,0,30,0,167,64,23,84,21,116,21,2,52,8,18,3,20,2,1,1,140,0,18,20,0,0,18,19,126,2,184,2,101,64,
14,4,4,0,13,25,126,11,5,2,1,22,18,15,1,184,2,17,64,14,0,0,7,22,111,15,74,32,28,111,7,73,31,213,185,1,110,0,24,43,78,16,244,77,237,78,16,246,77,237,18,57,47,237,18,57,17,18,57,0,63,237,63,57,47,237,237,
135,14,46,43,14,125,16,196,1,50,50,0,46,49,48,24,67,121,64,38,23,30,5,14,13,37,9,38,30,5,28,108,0,24,12,22,108,1,26,10,28,108,0,29,6,19,108,0,23,14,25,108,1,27,8,25,108,1,43,43,43,1,43,43,43,43,43,129,
129,0,93,5,39,1,6,35,34,38,53,52,62,1,51,50,30,1,21,20,6,7,37,50,54,53,52,38,35,34,6,21,20,22,1,137,121,1,141,80,70,175,244,118,217,124,122,207,118,73,94,254,226,129,181,181,129,128,181,181,37,78,2,90,
26,253,185,127,204,122,118,212,120,91,199,140,118,181,128,128,181,181,128,128,181,0,0,2,0,187,255,228,1,177,4,92,0,11,0,23,0,64,64,36,207,6,1,6,124,0,7,192,12,1,12,124,18,11,25,71,71,74,192,3,1,3,164,
9,9,192,15,1,15,164,21,73,24,103,113,24,43,78,16,244,77,237,93,60,16,253,93,78,69,101,68,230,0,63,77,237,93,63,237,93,49,48,1,50,22,21,20,6,35,34,38,53,52,54,19,50,22,21,20,6,35,34,38,53,52,54,1,54,51,
72,72,51,51,72,72,51,51,72,72,51,51,72,72,4,92,72,52,52,72,72,52,51,73,252,128,72,52,51,73,73,51,52,72,0,0,2,0,128,255,84,1,177,4,92,0,11,0,15,0,73,185,0,14,1,5,64,24,12,207,6,1,6,124,0,7,12,14,15,17,
71,71,74,13,207,9,1,9,164,3,129,13,184,2,7,64,9,0,15,1,15,73,16,95,113,24,43,78,16,244,93,77,253,244,237,93,78,16,69,101,68,230,18,57,57,0,63,77,237,93,47,237,49,48,1,50,22,21,20,6,35,34,38,53,52,54,19,
23,3,39,1,54,51,72,72,51,51,72,72,36,135,203,99,4,92,72,52,52,72,72,52,51,73,252,178,64,254,134,42,0,1,0,104,0,201,4,113,4,247,0,6,0,110,64,62,5,4,3,3,85,6,5,20,6,6,5,0,1,2,2,85,6,0,20,6,6,0,5,218,64,
4,201,6,32,0,218,64,1,201,32,6,6,3,2,5,0,4,4,0,1,16,1,2,1,74,8,0,2,16,2,2,2,73,7,95,152,24,43,78,16,228,93,16,246,93,60,17,57,57,17,51,51,0,25,47,26,77,253,26,24,237,26,25,16,253,26,24,237,135,46,43,135,
125,196,135,46,24,43,135,125,196,49,48,1,21,1,53,1,21,1,4,113,251,247,4,9,252,185,1,91,146,1,213,130,1,215,147,254,122,0,2,0,115,1,191,4,103,4,0,0,3,0,7,0,70,64,11,1,0,2,3,5,4,6,7,3,127,2,184,1,57,64,
21,6,127,7,7,2,6,3,4,1,0,0,5,74,9,3,6,73,8,95,113,24,43,78,16,244,60,16,246,60,17,57,57,17,18,57,57,0,47,77,237,254,237,17,18,57,57,17,18,57,57,49,48,1,21,33,53,1,21,33,53,4,103,252,12,3,244,252,12,4,
0,137,137,254,72,137,137,0,1,0,104,0,201,4,113,4,247,0,6,0,112,64,63,4,1,2,2,85,3,4,20,3,3,4,5,1,0,0,85,6,5,20,6,6,5,0,218,64,6,201,1,32,2,218,64,3,201,32,1,1,4,5,2,0,3,6,0,5,16,5,2,5,74,8,3,0,6,16,6,
2,6,73,7,95,152,24,43,78,16,244,93,60,16,230,93,17,18,57,57,17,51,51,0,25,47,26,77,253,26,24,237,26,25,16,253,26,24,237,135,46,43,135,125,196,135,46,24,43,135,125,196,49,48,19,9,1,53,1,21,1,104,3,71,252,
185,4,9,251,247,1,91,1,131,1,134,147,254,41,130,254,43,0,2,0,170,255,228,4,4,5,228,0,42,0,54,0,230,64,34,180,32,180,33,196,32,196,33,4,61,12,61,30,95,12,95,30,100,9,125,30,128,12,144,10,175,33,9,20,48,
17,21,57,41,184,255,208,64,24,12,17,57,40,8,11,32,39,48,21,1,0,21,16,21,32,21,3,9,0,21,1,8,21,184,1,146,178,18,97,25,184,1,126,64,20,192,43,1,43,124,49,11,15,0,31,0,47,0,3,9,15,0,1,8,0,184,1,156,64,36,
39,97,15,4,1,4,1,192,46,1,46,164,52,52,28,21,99,22,155,36,99,7,74,56,15,99,28,246,0,99,1,73,55,103,150,24,43,78,16,244,77,237,244,237,78,16,246,77,237,244,237,18,57,47,237,93,0,63,93,253,228,94,93,94,
93,63,253,93,254,253,228,94,93,94,93,93,18,57,57,49,48,67,121,64,28,37,38,26,27,16,17,5,6,17,26,15,87,0,38,5,36,87,1,16,27,18,87,0,37,6,39,87,1,43,43,1,43,43,129,129,129,129,1,43,43,93,0,93,1,35,62,1,
51,50,22,21,20,14,1,7,6,7,6,21,20,22,51,50,54,55,51,14,1,35,34,38,53,52,62,1,55,54,55,54,53,52,38,35,34,7,6,1,50,22,21,20,6,35,34,38,53,52,54,1,59,145,2,237,199,196,224,61,124,155,195,41,42,113,90,99,
106,12,146,7,193,163,162,192,53,97,134,216,61,60,147,123,150,83,58,1,32,51,72,72,51,51,72,72,4,47,202,235,198,147,70,119,95,61,78,38,39,55,58,92,101,111,167,185,168,123,60,107,72,55,88,44,44,82,87,120,
99,69,252,44,72,52,51,73,73,51,52,72,0,2,0,137,255,229,6,102,6,4,0,63,0,77,1,160,64,72,0,6,0,60,16,35,48,33,48,73,70,39,86,39,118,39,138,66,180,35,180,63,207,66,12,4,60,16,0,16,1,16,63,43,4,59,73,148,
63,7,190,8,37,69,25,38,38,25,25,85,41,39,20,41,41,39,39,34,38,25,45,37,72,64,106,28,186,45,170,21,188,1,184,1,160,64,39,5,72,106,34,186,38,53,170,13,1,0,38,1,38,7,61,170,5,11,63,64,12,27,57,0,64,12,27,
57,1,64,12,27,57,1,39,49,42,25,65,9,1,133,0,41,1,125,0,38,1,127,0,39,2,99,0,49,1,30,181,16,74,79,75,99,31,186,2,99,0,57,1,30,181,9,73,78,110,113,24,43,78,16,244,77,237,244,237,78,16,246,77,237,244,237,
244,237,17,18,57,57,43,43,43,0,63,237,63,93,63,237,16,244,237,16,253,246,237,244,253,17,57,17,57,17,18,57,135,14,46,43,5,125,16,196,135,14,196,196,49,48,24,67,121,64,33,70,77,43,63,29,36,2,24,3,38,59,
38,7,37,18,17,19,17,2,6,47,37,23,37,51,38,55,37,11,38,62,4,0,184,1,166,64,13,1,2,1,63,0,60,6,57,165,0,46,20,49,184,1,166,64,31,1,44,22,42,107,0,77,29,75,87,0,52,14,49,165,1,54,12,57,165,0,71,35,69,87,
1,36,37,73,33,75,184,1,166,179,0,63,2,61,184,1,166,64,9,0,58,8,61,165,0,48,17,45,184,1,166,64,29,0,43,24,45,107,0,76,30,64,87,0,50,15,53,165,1,56,10,53,165,1,70,36,72,87,1,74,32,72,185,1,166,0,1,0,43,
43,43,43,43,43,43,43,43,1,43,16,60,43,43,43,43,43,43,43,16,60,16,60,43,43,43,43,43,43,42,43,43,43,129,129,129,129,0,93,1,93,1,51,6,7,6,35,34,36,2,53,52,18,36,51,32,0,17,20,2,7,6,35,34,39,38,39,14,1,35,
34,38,53,52,18,51,50,22,23,55,51,3,6,21,20,22,51,50,62,1,53,52,39,38,33,34,4,2,21,20,18,4,51,50,54,1,50,54,55,54,53,52,38,35,34,6,21,20,22,5,164,106,134,114,162,207,219,254,142,207,209,1,104,214,1,46,
1,160,173,148,113,80,58,34,26,1,34,119,64,144,188,228,200,88,119,53,26,108,116,5,28,22,59,189,105,197,184,254,248,196,254,193,185,186,1,73,198,145,236,254,41,66,116,34,44,113,90,120,175,133,1,45,167,67,
94,207,1,102,212,215,1,114,205,254,125,254,255,187,254,241,75,58,31,23,57,43,58,199,164,177,1,36,66,82,138,253,114,32,9,23,26,137,215,131,254,167,155,179,254,187,189,191,254,189,184,104,1,7,83,83,109,
110,101,126,197,147,123,145,0,0,2,0,49,0,0,5,186,5,191,0,7,0,10,0,160,64,62,103,9,1,10,3,2,2,8,9,4,5,5,8,8,2,8,5,2,86,1,0,20,1,1,0,8,5,8,2,5,86,6,7,20,6,6,7,8,7,0,3,10,4,9,2,5,1,6,4,94,9,9,6,0,2,1,6,8,
8,0,7,12,188,1,27,0,2,2,23,0,1,1,81,178,0,189,7,65,9,1,81,0,5,2,23,0,6,1,27,0,11,2,21,2,22,0,24,43,16,246,237,244,254,244,237,230,17,18,57,0,63,60,63,17,57,47,237,17,18,57,57,17,18,57,57,18,57,57,135,
5,46,43,8,125,16,196,135,5,46,24,43,8,125,16,196,7,5,16,60,60,135,16,196,60,49,48,1,93,9,1,35,3,33,3,35,1,19,3,33,3,12,2,174,158,231,253,134,230,164,2,183,18,253,1,247,5,191,250,65,1,228,254,28,5,191,
254,200,253,235,0,0,3,0,183,0,0,4,40,5,191,0,16,0,26,0,38,0,213,64,57,81,8,27,18,17,8,27,19,38,18,28,15,29,16,17,1,26,0,38,94,15,18,1,9,15,18,1,8,18,18,0,29,94,16,8,26,94,0,2,36,8,21,3,23,0,17,18,27,4,
28,16,23,112,15,5,1,5,184,2,24,64,13,33,112,12,74,40,28,101,16,73,39,102,131,24,43,78,16,244,77,237,78,16,246,77,237,244,93,237,17,18,23,57,17,23,57,0,63,237,63,237,18,57,47,94,93,94,93,237,17,18,57,57,
17,18,57,57,17,18,57,57,57,3,5,16,60,60,49,48,67,121,64,59,2,37,21,37,3,37,31,37,10,37,35,34,36,34,2,6,20,7,23,117,3,25,2,23,117,1,30,14,33,117,1,37,9,33,117,3,22,6,19,117,0,7,24,4,26,117,1,32,13,29,117,
0,34,11,38,117,1,9,8,0,16,60,43,43,43,60,43,1,43,43,43,43,42,43,43,43,43,129,19,33,50,30,1,21,20,6,7,30,2,21,20,4,35,33,19,17,51,50,62,1,53,52,38,35,3,17,51,50,62,1,53,52,38,39,38,35,183,1,34,175,188,
109,96,93,115,124,69,254,253,218,254,108,144,84,153,144,84,141,154,170,182,161,150,91,128,112,75,186,5,191,83,172,105,98,161,50,39,105,149,87,177,245,5,47,254,41,57,123,75,101,115,253,149,253,204,63,134,
78,98,146,27,18,0,0,1,0,111,255,219,6,13,5,228,0,26,0,168,64,53,135,2,1,200,13,198,26,217,1,3,200,1,203,2,203,12,3,187,1,186,12,186,13,3,173,2,173,12,168,13,3,136,12,155,2,155,12,3,116,16,116,25,136,2,
132,25,4,40,8,14,0,1,13,184,2,25,180,11,122,17,9,1,184,2,25,64,22,4,122,24,3,1,0,13,0,14,74,28,48,28,1,8,112,21,73,27,120,131,24,43,78,16,244,77,237,93,78,16,246,60,50,17,51,0,63,77,253,228,63,253,228,
17,51,50,49,48,67,121,64,28,18,23,5,10,6,37,19,37,5,23,8,100,0,10,18,8,100,0,7,22,4,100,1,9,20,11,100,0,43,43,1,43,43,43,43,129,129,1,93,93,93,93,93,93,0,93,1,7,38,36,35,34,4,2,21,16,0,33,32,55,23,6,4,
35,32,3,38,17,16,0,33,50,4,6,13,116,96,254,243,161,176,254,212,165,1,113,1,25,1,53,208,116,110,254,183,203,254,126,223,187,1,197,1,85,206,1,76,4,174,89,125,129,169,254,227,178,254,243,254,152,242,88,140,
153,1,1,217,1,51,1,67,1,185,163,0,2,0,179,0,0,5,138,5,191,0,11,0,24,0,123,64,35,55,8,12,11,13,0,23,2,24,1,13,94,0,8,24,94,1,2,24,1,12,0,18,112,7,74,26,12,101,0,73,25,102,131,24,43,78,16,244,77,237,78,
16,246,77,237,17,18,57,57,0,63,237,63,237,17,18,57,57,17,18,57,57,49,48,67,121,64,42,3,22,9,38,16,17,15,17,2,6,5,6,4,6,2,6,20,19,21,19,2,6,14,10,18,100,1,22,3,18,100,1,17,8,13,100,0,19,6,23,100,1,43,43,
1,43,43,42,42,42,43,129,51,17,33,32,23,22,18,17,20,2,4,33,37,51,32,55,54,18,53,52,2,39,38,33,35,179,1,49,1,74,149,214,241,191,254,207,254,237,254,185,170,1,49,118,166,190,206,184,138,254,195,104,5,191,
53,75,254,142,255,0,221,254,176,160,139,38,54,1,25,203,213,1,46,56,42,0,1,0,180,0,0,3,255,5,191,0,11,0,105,64,54,7,4,3,10,9,11,8,6,5,7,4,2,1,3,0,7,94,4,4,11,3,94,0,2,8,94,11,8,5,9,13,10,3,0,8,11,5,167,
1,167,0,10,1,10,74,13,8,101,11,73,12,102,175,24,43,78,16,244,77,237,78,16,246,93,77,244,228,17,18,57,57,17,18,57,57,0,63,237,63,237,18,57,47,237,17,18,57,57,17,18,57,57,17,18,57,57,3,5,16,60,60,49,48,
19,33,21,33,17,33,21,33,17,33,21,33,180,3,75,253,72,2,178,253,78,2,178,252,187,5,191,145,254,52,144,253,191,145,0,0,1,0,179,0,0,3,148,5,191,0,9,0,86,64,42,4,7,8,6,5,7,4,2,1,3,0,7,94,4,4,9,3,94,0,2,9,8,
5,2,6,1,3,0,8,9,6,1,74,11,8,101,9,73,10,102,175,24,43,78,16,244,77,237,78,16,246,60,17,18,57,57,17,18,57,57,0,63,63,77,237,18,57,47,237,17,18,57,57,17,18,57,57,3,5,16,60,60,49,48,19,33,21,33,17,33,21,
33,17,35,179,2,225,253,177,2,79,253,177,146,5,191,145,254,52,145,253,47,0,1,0,117,255,219,6,149,5,228,0,31,0,197,64,72,169,19,185,19,199,0,201,19,4,203,3,202,13,2,182,20,201,1,202,2,3,166,20,189,1,189,
3,3,152,14,171,1,171,3,3,137,13,153,1,153,2,3,102,20,116,30,137,2,3,90,13,106,3,102,19,3,46,8,0,1,15,18,16,94,17,17,4,12,122,21,9,1,184,2,25,64,10,4,122,29,3,17,17,15,8,1,0,184,1,121,64,13,15,112,18,74,
33,8,112,25,73,32,120,131,24,43,78,16,244,77,237,78,16,246,77,237,244,50,17,18,57,47,0,63,253,228,63,253,17,57,47,237,57,57,17,51,49,48,67,121,64,32,22,28,5,11,6,37,27,38,10,38,23,37,5,28,8,100,0,11,22,
8,100,0,7,26,4,100,1,9,24,12,100,0,43,43,1,43,43,43,43,43,43,129,129,1,93,93,93,93,93,93,93,0,93,1,7,38,36,35,34,4,2,21,20,18,4,51,50,0,55,33,53,33,2,0,33,32,3,38,17,52,18,36,51,50,4,6,62,114,123,254,
219,139,173,254,199,172,178,1,58,187,227,1,58,29,254,43,2,122,2,254,111,254,176,254,104,238,183,210,1,110,231,187,1,74,4,200,108,121,125,170,254,221,162,166,254,213,171,1,0,204,142,254,171,254,111,1,22,
214,1,25,209,1,104,203,135,0,0,1,0,177,0,0,4,197,5,191,0,11,0,120,64,65,8,3,4,9,2,1,7,10,6,11,4,1,5,0,3,2,94,8,9,9,0,6,11,8,5,0,2,5,4,5,8,4,7,6,0,1,2,9,4,10,11,7,101,80,6,1,6,74,13,9,15,13,1,8,10,101,
95,11,1,11,73,12,102,174,24,43,78,16,244,93,77,237,94,93,94,78,16,246,93,77,237,17,18,23,57,17,18,23,57,0,63,60,63,60,18,57,47,60,253,60,17,18,57,57,17,18,57,57,3,5,16,60,60,16,60,60,49,48,19,51,17,33,
17,51,17,35,17,33,17,35,177,148,2,236,148,148,253,20,148,5,191,253,151,2,105,250,65,2,198,253,58,0,0,1,0,158,0,0,1,49,5,191,0,3,0,44,64,21,2,1,0,2,3,8,1,0,3,5,71,71,74,2,101,3,73,4,102,174,24,43,78,16,
244,77,253,78,69,101,68,230,18,57,57,0,63,63,57,57,49,48,19,51,17,35,158,147,147,5,191,250,65,0,0,1,0,86,255,219,3,40,5,191,0,18,0,99,185,0,11,255,192,64,9,18,21,57,9,8,1,28,8,9,186,2,28,0,10,2,27,64,
21,14,122,6,9,0,2,10,9,1,0,18,101,2,74,20,9,73,19,180,174,24,43,78,16,228,16,246,77,253,57,57,17,51,0,63,63,253,244,237,49,48,67,121,64,18,15,17,3,5,4,38,16,37,15,5,18,117,1,17,3,14,117,0,43,1,43,43,43,
129,129,0,93,1,43,1,51,17,20,14,1,35,34,38,39,55,22,23,22,51,50,62,1,53,2,148,148,71,166,118,89,173,105,78,115,76,50,48,63,103,41,5,191,252,31,229,179,107,69,87,117,81,33,22,76,126,181,0,0,1,0,179,0,0,
4,146,5,191,0,10,0,168,64,62,92,6,1,8,8,7,2,1,2,3,3,2,2,86,5,4,20,5,5,4,7,8,8,86,5,6,20,5,5,6,2,8,5,7,9,6,10,3,1,4,0,128,5,1,5,5,10,4,0,2,6,10,8,5,0,1,2,8,4,9,10,3,184,2,29,178,4,190,7,184,2,29,64,17,
6,74,12,15,12,1,9,15,12,1,8,9,101,10,73,11,102,185,1,21,0,24,43,78,16,244,77,237,94,93,94,93,25,78,16,246,24,77,237,244,237,17,18,23,57,50,0,63,60,63,60,18,57,47,93,17,18,57,57,17,18,57,57,17,51,51,135,
46,43,5,125,16,196,135,4,46,24,43,5,125,16,196,3,8,16,60,8,60,49,48,1,113,19,51,17,1,51,9,1,35,1,17,35,179,150,2,75,199,253,61,2,250,195,253,122,150,5,191,253,216,2,40,253,108,252,213,2,174,253,82,0,1,
0,179,0,0,3,124,5,191,0,5,0,47,64,23,4,3,2,94,5,8,0,2,1,0,2,5,4,74,7,2,101,5,73,6,102,237,24,43,78,16,244,77,237,78,16,230,17,18,57,57,0,63,63,77,253,57,57,49,48,19,51,17,33,21,33,179,148,2,53,253,55,
5,191,250,207,142,0,1,0,112,0,0,6,234,5,191,0,12,1,93,64,115,48,8,48,11,2,15,3,103,8,2,24,1,23,5,2,201,8,198,11,2,9,10,196,5,2,203,1,202,2,198,4,3,186,1,185,2,181,5,3,170,1,169,2,165,5,3,155,2,151,4,148,
5,3,133,5,136,8,155,1,3,121,2,117,5,138,1,3,105,2,102,5,122,1,3,89,2,86,5,105,1,3,54,5,55,11,90,1,3,40,1,57,1,57,2,3,3,24,1,1,4,9,8,1,1,8,168,11,1,2,32,168,8,4,5,32,184,255,153,64,62,3,10,9,32,7,6,5,5,
86,8,7,20,8,8,7,4,8,9,9,86,3,4,20,3,3,4,10,3,2,2,86,11,10,20,11,11,10,1,11,12,12,86,0,1,20,0,0,1,4,2,5,1,12,10,9,7,4,6,0,8,240,11,184,2,33,180,0,5,1,2,3,184,2,32,64,17,6,0,8,9,10,3,4,5,6,2,1,0,14,71,71,
74,6,65,11,1,40,0,7,2,30,0,8,2,31,0,3,2,31,0,11,2,30,0,12,1,40,181,0,73,13,120,131,24,43,78,16,244,77,253,25,244,24,253,253,25,244,24,253,78,69,101,68,230,17,51,51,17,51,51,17,51,51,0,63,60,77,237,63,
60,16,244,228,17,18,23,57,17,18,57,57,135,5,46,43,135,125,196,135,46,24,43,135,125,196,135,46,24,43,135,125,196,135,46,24,43,135,125,196,43,43,43,49,48,1,94,93,94,95,93,95,93,93,93,93,93,93,93,93,93,93,
93,113,93,0,93,113,51,19,51,9,1,51,19,35,3,1,35,1,3,112,209,24,2,86,2,80,24,211,145,144,253,248,37,253,241,143,5,191,251,73,4,183,250,65,4,28,251,228,4,36,251,220,0,0,1,0,180,0,0,5,55,5,191,0,9,0,123,
64,75,55,8,72,3,71,8,3,40,3,39,8,56,3,3,0,3,15,8,2,9,0,3,15,8,2,8,3,7,8,8,86,2,3,20,2,2,3,4,2,5,1,7,9,0,5,1,2,6,0,8,7,4,5,3,6,3,1,2,8,3,9,0,3,101,6,74,11,9,101,0,73,10,102,174,24,43,78,16,244,77,237,78,
16,246,77,237,17,18,23,57,17,18,23,57,0,63,60,63,60,17,57,57,17,18,57,57,135,46,43,135,125,196,49,48,0,94,93,94,93,113,113,51,17,51,1,17,51,17,35,1,17,180,32,3,210,145,33,252,54,5,191,251,154,4,102,250,
65,4,88,251,168,0,0,2,0,115,255,219,6,128,5,228,0,12,0,27,0,111,64,23,67,8,20,122,6,9,13,122,0,3,24,112,3,74,29,17,112,9,73,28,120,131,24,43,78,16,244,77,237,78,16,246,77,237,0,63,237,63,237,49,48,67,
121,64,50,1,27,22,37,26,38,15,37,11,38,21,5,24,100,1,19,7,17,100,0,27,1,24,100,1,14,12,17,100,0,23,4,20,100,0,18,8,20,100,0,25,2,13,100,1,16,10,13,100,1,43,43,43,43,1,43,43,43,43,43,43,43,43,129,1,32,
0,17,16,0,33,32,0,17,52,18,36,23,34,4,2,21,16,0,33,50,36,18,53,52,2,36,3,112,1,78,1,194,254,63,254,189,254,185,254,62,205,1,98,213,163,254,220,164,1,107,1,0,171,1,35,163,163,254,216,5,228,254,66,254,186,
254,189,254,62,1,192,1,62,212,1,106,205,144,170,254,224,177,254,250,254,151,166,1,32,176,175,1,27,170,0,0,2,0,178,0,0,4,73,5,191,0,14,0,25,0,137,64,44,52,8,16,12,13,11,17,12,16,25,1,15,0,12,94,16,16,14,
15,94,0,2,14,8,0,15,16,12,4,13,14,21,112,6,74,27,13,101,14,73,26,102,131,24,43,78,16,244,77,237,78,16,246,77,237,17,18,23,57,0,63,63,237,18,57,47,237,17,18,57,57,17,18,57,57,3,5,16,60,60,49,48,67,121,
64,38,2,24,8,7,9,7,2,6,19,37,4,5,3,5,2,6,23,38,18,10,21,117,1,24,2,21,117,1,20,7,17,117,0,22,5,25,117,1,0,43,43,1,43,43,43,42,43,42,129,19,33,50,23,30,1,21,20,6,7,6,33,35,17,35,19,17,23,50,62,1,53,52,
46,1,35,178,1,37,252,88,126,160,156,137,100,254,238,105,147,147,249,151,140,80,80,131,149,5,191,22,31,193,146,147,191,33,24,253,84,5,48,254,12,3,55,123,76,74,123,52,0,2,0,117,255,140,6,130,5,228,0,17,
0,35,0,251,64,70,43,19,36,34,36,35,57,18,68,0,5,6,3,8,33,2,25,1,111,32,137,18,150,17,231,0,250,32,6,56,8,0,18,35,35,1,3,33,34,2,34,2,2,86,1,35,20,1,1,35,32,33,18,19,4,31,4,3,0,17,4,5,1,35,2,34,34,24,31,
2,184,1,117,64,22,31,122,5,9,24,122,12,3,19,18,33,32,4,20,16,17,0,3,4,5,15,34,184,2,23,180,35,35,28,20,2,184,2,29,64,15,1,209,20,112,15,74,37,28,112,8,73,36,120,131,24,43,78,16,244,77,237,78,16,246,77,
237,244,237,17,18,57,47,237,17,23,51,17,23,51,0,63,237,63,237,228,17,18,57,47,18,57,57,17,23,51,17,23,51,135,5,46,43,125,16,196,7,14,60,60,7,14,16,60,60,49,48,24,67,121,64,40,21,30,6,14,22,38,26,37,10,
38,30,6,28,100,0,23,13,20,100,1,25,11,28,100,0,29,7,31,100,0,21,14,24,100,1,27,9,24,100,1,0,43,43,43,1,43,43,43,43,43,43,129,129,1,93,113,93,37,19,35,39,6,35,32,0,17,52,18,36,51,32,0,17,20,2,7,54,17,52,
2,36,35,34,4,2,21,16,0,33,50,55,1,51,5,133,218,181,150,180,226,254,185,254,62,206,1,99,212,1,71,1,193,123,221,192,163,254,216,164,165,254,220,164,1,106,1,0,175,145,254,184,179,160,254,236,190,111,1,192,
1,62,212,1,107,204,254,65,254,186,170,254,230,8,187,1,18,175,1,27,170,169,254,223,177,254,250,254,151,85,1,160,0,0,2,0,187,0,0,4,104,5,191,0,16,0,27,0,206,64,77,15,10,15,13,27,10,27,13,43,10,43,13,59,
10,59,13,8,48,8,18,14,15,13,14,13,12,13,12,12,86,11,10,20,11,11,10,12,15,11,16,19,10,13,3,14,18,27,1,17,0,14,94,18,18,0,11,16,8,17,94,0,2,10,13,11,0,17,18,14,4,15,16,23,112,6,209,12,184,2,29,64,11,11,
74,29,15,101,16,73,28,102,131,24,43,78,16,244,77,237,78,16,246,77,237,244,237,17,18,23,57,17,57,57,0,63,237,63,60,18,57,47,237,17,18,57,57,17,18,23,57,17,18,57,57,135,5,46,43,125,16,196,2,8,16,60,3,5,
16,60,60,49,48,24,67,121,64,34,2,26,8,38,21,37,4,5,3,5,2,6,25,38,20,9,23,117,1,26,2,23,117,1,22,7,19,117,0,24,5,27,117,1,0,43,43,1,43,43,43,42,43,43,129,1,93,19,33,50,23,30,1,21,20,14,1,7,1,35,1,35,17,
35,19,17,23,50,62,1,53,52,46,1,35,187,1,37,245,87,131,164,113,210,185,2,17,182,253,240,84,147,147,253,147,141,79,80,130,151,5,191,20,30,197,144,120,182,93,1,253,84,2,172,253,84,5,47,254,12,2,56,123,76,
74,121,52,0,1,0,27,255,219,3,120,5,228,0,42,1,36,64,116,0,0,0,1,4,42,169,12,166,35,5,15,21,15,22,15,23,121,10,138,9,141,10,6,10,10,10,12,57,10,90,12,88,13,176,31,176,34,7,68,35,107,41,204,42,3,57,10,57,
35,195,35,3,203,23,204,24,197,31,3,187,42,196,1,205,12,3,183,1,186,23,187,24,3,161,2,168,23,169,42,3,69,2,150,2,150,34,3,46,8,122,9,170,13,2,9,13,11,73,11,153,11,2,11,34,102,34,1,32,34,3,22,112,23,1,23,
184,2,34,64,11,26,122,19,3,0,175,1,191,1,2,1,184,2,25,64,34,3,122,40,9,23,1,0,22,209,7,112,223,37,239,37,2,37,74,44,47,44,63,44,2,29,112,32,15,48,15,64,15,3,15,184,1,121,64,11,47,0,63,0,2,0,73,43,169,
131,24,43,78,16,244,93,77,244,93,237,93,78,16,246,93,77,237,228,17,51,50,0,63,253,244,93,50,63,253,244,93,50,18,57,57,93,17,51,93,17,51,51,93,49,48,67,121,64,32,38,39,27,28,16,18,4,6,17,38,5,37,27,18,
29,117,0,4,39,7,117,1,28,16,26,117,1,6,38,3,117,0,43,43,1,43,43,43,43,129,129,129,129,1,93,93,93,93,93,93,93,0,93,93,93,19,55,22,51,50,62,1,53,52,39,38,39,38,39,38,53,52,62,1,51,50,22,23,7,46,1,35,34,
6,21,20,22,23,22,23,30,1,21,20,6,35,34,38,27,125,132,173,74,130,68,50,69,183,184,45,78,92,167,98,104,181,101,120,83,117,69,89,113,40,53,29,161,191,142,243,174,134,218,1,18,75,243,69,116,65,74,71,98,138,
139,62,104,121,96,158,91,103,138,91,110,70,108,79,48,90,53,28,119,141,220,111,160,236,143,0,1,0,33,0,0,3,72,5,191,0,7,0,71,64,32,4,7,0,3,2,0,94,1,2,6,8,4,7,5,6,2,1,0,9,71,71,74,3,224,5,101,6,224,0,73,
8,169,185,1,21,0,24,43,78,16,244,77,244,253,244,78,69,101,68,230,18,57,57,17,18,57,57,0,63,63,77,237,57,57,16,60,60,49,48,19,53,33,21,33,17,35,17,33,3,39,254,184,150,5,48,143,143,250,208,5,48,0,0,1,0,
184,255,219,4,134,5,191,0,26,0,131,64,27,57,8,15,1,16,16,0,2,8,122,21,9,16,15,17,14,1,0,2,26,28,71,71,74,17,101,14,184,2,102,183,2,101,26,73,27,102,174,24,43,78,16,244,77,253,246,253,78,69,101,68,230,
17,18,57,57,17,18,57,57,0,63,77,237,63,60,18,57,57,49,48,67,121,64,42,5,25,19,38,12,13,11,13,10,13,3,6,6,38,24,25,23,25,2,6,9,20,14,117,1,7,22,4,117,0,5,4,13,18,8,117,0,5,25,8,117,0,43,43,1,16,60,43,43,
42,43,42,43,129,19,51,17,20,23,30,2,51,50,62,1,55,54,53,17,51,17,20,14,1,35,34,38,39,38,53,184,147,6,11,80,166,84,73,134,90,21,15,147,77,231,164,178,254,43,27,5,191,252,136,158,39,87,117,79,62,110,78,
56,174,3,120,252,136,197,243,180,170,140,86,224,0,1,0,67,0,0,5,90,5,191,0,6,0,120,64,40,103,2,1,5,2,3,2,1,3,86,4,5,20,4,4,5,2,1,2,3,1,86,0,6,20,0,0,6,3,1,4,4,0,2,6,8,112,8,1,8,188,1,27,0,3,2,23,0,4,1,
81,178,5,189,6,186,1,81,0,1,2,23,179,112,0,1,0,188,1,27,0,7,2,21,2,35,0,24,43,16,246,93,237,244,254,244,237,230,93,0,63,63,60,18,57,57,135,5,46,43,8,125,16,196,135,5,46,24,43,8,125,16,196,0,46,49,48,93,
19,51,9,1,51,1,35,67,160,1,231,1,240,160,253,128,32,5,191,251,143,4,113,250,65,0,0,1,0,96,0,0,7,78,5,191,0,12,1,51,64,77,11,3,9,11,9,12,27,3,25,11,25,12,56,6,56,7,55,8,56,12,70,8,73,12,87,8,88,12,103,
8,135,8,136,12,151,4,151,8,152,12,167,4,168,9,168,12,183,4,184,9,184,12,198,1,201,6,28,0,10,20,2,16,10,90,2,90,5,85,10,183,5,7,128,10,3,4,32,184,255,106,179,5,9,8,32,184,255,106,64,61,2,12,11,32,6,7,8,
8,86,5,6,20,5,5,6,9,5,4,4,86,10,9,20,10,10,9,3,10,11,11,86,2,3,20,2,2,3,12,2,1,1,86,0,12,20,0,0,12,9,11,8,12,1,3,4,6,4,7,0,5,2,184,2,38,179,8,12,8,10,184,2,37,64,17,7,0,2,9,8,7,4,3,10,11,12,0,14,71,71,
74,7,65,11,1,40,0,6,1,157,0,5,2,36,0,10,2,36,0,2,1,157,0,1,1,40,183,64,0,73,13,11,180,175,24,43,75,82,88,176,0,26,89,78,16,252,26,77,253,25,244,24,253,253,25,244,24,253,78,69,101,68,230,17,51,51,17,51,
51,17,51,51,0,63,60,77,237,63,60,253,60,17,18,23,57,17,18,57,57,135,5,46,43,135,125,196,135,46,24,43,135,125,196,135,46,24,43,135,125,196,135,46,24,43,135,125,196,43,43,43,49,48,0,93,1,93,19,51,9,1,51,
9,1,51,1,35,9,1,35,96,151,1,43,1,166,30,1,161,1,49,150,254,90,28,254,76,254,67,28,5,191,251,220,4,36,251,220,4,36,250,65,4,89,251,167,0,1,0,69,0,0,4,155,5,191,0,11,0,200,64,80,75,5,79,8,200,0,203,5,207,
8,5,73,5,71,9,2,71,1,72,3,72,7,3,11,0,7,10,3,8,0,7,9,4,5,1,6,9,4,2,1,6,10,3,7,6,1,1,86,0,7,20,0,0,7,3,4,9,9,86,10,3,20,10,10,3,3,1,4,0,7,9,6,10,4,0,2,6,10,8,3,184,2,23,178,4,209,7,184,2,23,64,26,63,6,
79,6,95,6,3,15,6,31,6,47,6,3,9,15,6,1,8,6,74,13,112,13,1,1,184,2,23,178,0,209,9,184,2,23,181,10,73,12,136,184,24,43,25,78,16,244,24,77,237,244,237,93,25,78,16,246,94,93,94,93,93,24,77,237,244,237,0,63,
60,63,60,17,18,57,57,17,18,57,57,135,5,46,43,135,125,196,135,46,24,43,135,125,196,15,15,15,15,49,48,1,93,93,0,93,19,51,9,1,51,9,1,35,9,1,35,1,101,172,1,96,1,99,170,254,74,1,211,172,254,130,254,128,172,
1,213,5,191,253,194,2,62,253,55,253,10,2,105,253,151,2,246,0,0,1,0,63,0,0,4,125,5,191,0,8,0,122,64,42,5,8,2,3,2,1,3,86,4,5,20,4,4,5,2,1,2,3,1,86,0,8,20,0,0,8,3,1,4,0,7,8,4,0,2,8,2,5,3,6,7,10,188,1,27,
0,3,2,23,0,4,1,71,178,6,101,7,65,9,1,71,0,1,2,23,0,0,1,27,0,9,2,21,2,35,0,24,43,16,246,237,244,253,244,237,230,17,18,23,57,0,63,60,63,17,18,57,57,135,5,46,43,8,125,16,196,135,5,46,24,43,8,125,16,196,0,
46,46,49,48,19,51,9,1,51,1,17,35,17,63,170,1,120,1,114,170,254,46,145,5,191,253,162,2,94,253,0,253,65,2,191,0,0,1,0,56,0,0,3,130,5,191,0,7,0,136,64,87,26,2,26,7,2,7,2,8,3,6,7,3,9,7,2,8,3,6,7,3,8,7,2,3,
3,86,6,7,20,6,6,7,7,2,0,1,4,5,3,6,0,94,1,2,3,94,6,8,7,3,6,2,209,15,5,1,5,74,9,47,9,1,224,1,1,176,1,192,1,208,1,3,128,1,144,1,160,1,3,1,190,6,73,8,136,131,24,43,78,16,244,77,228,93,93,93,93,78,16,246,93,
77,228,17,51,50,0,63,237,63,237,17,18,57,57,17,18,57,57,135,5,46,43,135,125,196,49,48,94,93,94,93,1,93,19,53,33,1,33,21,33,1,122,3,8,253,153,2,72,252,213,2,107,5,49,142,250,208,143,5,49,0,0,1,1,34,254,
114,2,114,5,228,0,7,0,72,64,32,2,1,3,0,6,5,7,4,3,98,0,16,4,98,7,18,2,5,1,6,3,0,4,7,9,246,1,6,162,4,127,7,184,2,39,179,8,142,152,24,43,16,246,253,244,60,228,17,18,57,57,17,18,57,57,0,63,237,63,237,17,18,
57,57,17,18,57,57,49,48,1,33,21,35,17,51,21,33,1,34,1,80,196,196,254,176,5,228,142,249,165,137,0,1,0,66,255,56,4,148,5,228,0,3,0,71,64,23,5,0,5,3,2,2,1,0,0,85,3,2,20,3,3,2,1,0,3,2,3,0,2,184,1,133,179,
1,74,5,0,184,1,133,181,3,73,4,89,114,24,43,78,16,244,77,237,78,16,246,77,237,0,63,47,18,57,57,135,5,46,43,135,125,196,49,48,1,93,19,1,35,1,220,3,184,153,252,71,5,228,249,84,6,172,0,0,1,0,93,254,114,1,
173,5,228,0,7,0,75,64,25,5,6,4,7,2,1,3,0,4,98,7,16,3,98,0,18,7,4,0,3,5,2,6,1,9,184,2,6,181,0,127,3,162,6,1,184,1,36,179,8,119,236,24,43,16,246,60,244,253,228,17,18,57,57,17,18,57,57,0,63,237,63,237,17,
18,57,57,17,18,57,57,49,48,1,33,53,51,17,35,53,33,1,173,254,176,195,195,1,80,254,114,142,6,91,137,0,0,1,0,120,1,109,4,233,5,191,0,6,0,110,64,41,4,3,4,5,3,85,2,1,20,2,2,1,4,5,4,3,5,85,6,0,20,6,6,0,1,4,
0,3,5,2,2,6,4,218,0,2,8,71,71,74,2,188,2,5,0,1,1,36,0,0,2,5,64,9,0,6,1,6,73,7,95,113,24,43,78,16,244,93,77,244,246,244,78,69,101,68,230,0,63,77,237,47,60,18,57,57,17,18,57,135,5,46,43,8,125,16,196,135,
5,46,24,43,8,125,16,196,49,48,1,51,1,35,9,1,35,2,117,118,1,254,133,254,73,254,76,129,5,191,251,174,3,184,252,72,0,1,255,244,255,0,4,12,255,102,0,3,0,36,64,17,2,1,3,192,0,2,3,0,1,74,5,0,73,4,206,134,24,
43,78,16,228,16,230,17,57,57,0,47,77,237,57,57,49,48,7,33,21,33,12,4,24,251,232,154,102,0,0,1,0,111,5,10,2,32,6,62,0,3,0,41,64,17,0,1,3,223,128,2,0,2,1,227,0,3,1,3,73,4,95,185,1,19,0,24,43,78,16,244,93,
77,237,57,57,0,47,26,237,57,57,49,48,1,19,35,1,1,70,218,138,254,217,6,62,254,204,1,52,0,0,2,0,107,255,228,4,216,4,92,0,16,0,31,0,190,64,49,30,64,25,6,27,64,12,17,41,8,15,29,3,2,2,0,1,16,17,88,12,7,1,10,
16,6,25,88,6,11,0,16,15,29,3,5,2,92,1,74,33,21,105,9,73,32,96,118,24,43,78,16,244,77,237,78,16,246,77,237,23,57,0,63,237,63,63,63,237,17,18,57,57,3,14,16,60,125,196,60,49,48,24,67,121,64,28,18,24,7,11,
23,38,19,37,24,7,21,90,0,18,11,21,90,0,22,8,25,90,0,20,10,17,90,1,0,43,43,1,43,43,43,43,129,129,0,73,84,121,64,16,30,31,13,14,30,14,17,104,5,31,13,29,104,1,14,15,1,16,60,43,0,43,129,129,0,73,84,121,64,
18,26,28,4,5,27,37,28,4,25,104,4,26,5,29,104,1,4,3,1,16,60,43,0,43,43,129,129,1,17,35,53,14,1,35,34,0,53,52,0,51,50,22,23,53,5,34,14,1,21,20,30,1,51,50,62,1,53,52,38,4,216,138,88,219,130,231,254,185,1,
74,232,134,217,82,254,90,117,198,117,118,199,114,115,206,111,249,4,64,251,192,187,107,108,1,79,240,235,1,78,114,114,200,107,115,208,116,115,210,117,116,198,124,189,254,0,0,2,0,165,255,228,5,18,5,228,0,
16,0,31,0,186,64,47,27,64,17,12,30,64,6,25,41,8,15,29,3,2,25,88,6,7,1,0,17,88,12,11,0,10,1,2,3,29,15,5,16,0,21,105,9,74,33,16,92,0,73,32,123,133,24,43,78,16,244,77,237,78,16,246,77,237,17,18,23,57,0,63,
63,237,63,63,237,3,14,16,60,125,196,60,49,48,24,67,121,64,28,18,24,7,11,19,37,23,38,18,11,21,90,1,24,7,21,90,1,20,10,17,90,0,22,8,25,90,1,0,43,43,1,43,43,43,43,129,129,0,73,84,121,64,18,26,28,4,5,27,37,
28,4,25,104,5,26,5,29,104,0,4,3,1,16,60,43,0,43,43,129,129,0,73,84,121,64,16,30,31,13,14,30,14,17,104,4,31,13,29,104,0,14,15,1,16,60,43,0,43,129,129,51,17,51,17,62,1,51,50,0,21,20,0,35,34,38,39,21,37,
50,62,1,53,52,46,1,35,34,14,1,21,20,22,165,139,88,218,130,231,1,71,254,182,232,133,216,83,1,165,117,198,117,118,199,113,115,207,111,249,5,228,253,161,108,107,254,177,239,236,254,178,114,114,200,107,115,
208,116,116,210,117,117,198,124,189,254,0,0,1,0,105,255,228,4,188,4,92,0,26,0,142,64,24,196,25,1,11,64,15,22,57,2,64,15,22,57,40,8,0,1,13,9,0,12,1,8,12,184,2,40,64,10,10,88,16,11,9,15,1,1,8,1,184,2,40,
64,19,3,88,23,7,1,0,12,0,13,74,28,6,105,19,73,27,96,133,24,43,78,16,244,77,237,78,16,246,60,50,17,51,0,63,77,253,228,94,93,94,63,253,244,94,93,94,50,17,51,49,48,67,121,64,28,17,22,4,9,21,38,8,38,4,22,
6,90,0,9,17,6,90,0,5,20,3,90,1,7,18,10,90,0,43,43,1,43,43,43,43,129,129,1,43,43,93,1,7,38,35,34,0,21,20,30,1,51,50,55,23,6,4,35,32,0,53,52,18,36,51,50,30,1,4,188,111,144,249,199,254,249,121,211,131,240,
152,111,78,254,249,168,254,254,254,172,159,1,22,172,108,201,140,3,94,69,191,255,0,183,119,210,116,191,73,117,129,1,72,235,158,1,15,152,66,106,0,0,2,0,109,255,228,4,218,5,228,0,16,0,31,0,182,64,45,30,64,
25,6,27,64,12,17,41,8,15,29,3,2,25,88,6,11,2,10,17,88,12,7,0,0,0,16,15,29,3,5,2,92,1,74,33,21,105,9,73,32,96,118,24,43,78,16,244,77,237,78,16,246,77,237,23,57,0,63,63,237,63,63,237,3,14,16,60,125,196,
60,49,48,24,67,121,64,28,18,24,7,11,23,38,19,37,24,7,21,90,0,18,11,21,90,0,22,8,25,90,0,20,10,17,90,1,0,43,43,1,43,43,43,43,129,129,0,73,84,121,64,16,30,31,13,14,30,14,17,104,5,31,13,29,104,1,14,15,1,
16,60,43,0,43,129,129,0,73,84,121,64,18,26,28,4,5,27,37,28,4,25,104,4,26,5,29,104,1,4,3,1,16,60,43,0,43,43,129,129,1,17,35,53,14,1,35,34,0,53,52,0,51,50,22,23,17,1,34,14,1,21,20,30,1,51,50,62,1,53,52,
38,4,218,138,88,219,130,231,254,185,1,74,232,134,217,82,254,90,117,198,117,118,199,114,115,206,111,249,5,228,250,28,187,107,108,1,79,240,235,1,78,114,114,2,108,253,241,115,208,116,115,210,117,116,198,
124,189,254,0,0,2,0,104,255,228,4,202,4,92,0,23,0,32,0,251,64,87,42,0,42,4,2,26,4,26,6,23,7,3,8,2,25,0,25,2,3,70,13,234,22,248,2,248,3,4,182,14,233,2,235,3,239,4,4,216,2,216,3,221,4,3,197,2,197,3,201,
21,3,179,3,185,21,200,0,3,154,22,165,14,172,22,3,137,25,140,27,150,14,3,120,25,136,13,136,14,3,47,8,1,0,16,24,32,0,184,2,100,64,56,17,144,255,32,1,9,15,32,1,8,32,32,28,64,0,80,0,2,0,0,16,0,48,0,3,9,0,
0,1,8,20,88,5,11,28,88,12,7,0,32,17,1,178,24,105,16,74,34,17,105,8,73,33,96,133,24,43,78,16,244,77,237,78,16,246,77,237,228,17,51,50,0,63,237,63,237,94,93,94,93,93,17,57,47,94,93,94,113,253,230,18,57,
57,17,51,49,48,67,121,64,32,29,31,18,19,6,11,30,37,10,38,19,6,17,90,0,29,11,32,90,0,31,32,18,7,20,90,0,31,9,28,90,1,43,43,1,16,60,43,43,43,43,129,129,129,1,93,93,93,93,93,93,93,93,113,113,113,1,23,14,
2,35,32,0,53,52,55,54,33,32,23,22,23,33,30,1,51,50,62,1,19,46,2,35,34,7,6,7,4,48,118,58,152,190,120,254,246,254,212,127,161,1,14,1,22,166,118,2,252,46,4,234,172,83,157,110,64,28,107,176,97,160,115,84,
43,1,105,62,114,140,73,1,93,220,207,162,206,211,149,223,190,243,58,96,1,144,112,134,82,103,75,150,0,1,0,79,0,0,2,92,6,0,0,23,0,147,64,77,25,8,17,16,9,18,13,14,15,10,18,13,11,15,10,7,12,8,16,9,7,12,1,3,
0,22,10,9,15,144,16,6,3,88,15,22,1,22,1,13,10,14,17,18,7,8,11,6,12,13,9,125,15,0,47,0,2,0,74,25,12,92,13,195,16,15,48,15,64,15,80,15,4,15,73,24,160,185,1,111,0,24,43,78,16,244,93,77,252,237,78,16,246,
93,77,228,17,18,23,57,0,63,63,93,237,63,237,57,57,17,51,17,51,15,15,15,15,49,48,67,121,64,16,4,21,5,37,20,38,4,21,7,128,0,6,19,3,128,1,43,1,43,43,43,129,1,21,38,35,34,14,1,29,1,51,21,35,17,35,17,35,53,
51,53,52,62,1,51,50,2,92,77,55,41,54,14,227,228,140,143,143,43,103,73,68,5,228,137,33,33,43,93,147,120,252,56,3,200,120,170,117,100,61,0,0,2,0,100,254,86,4,210,4,92,0,34,0,48,0,237,185,0,13,255,192,64,
27,13,20,57,27,64,42,23,30,64,31,35,72,8,34,45,20,0,6,35,88,31,7,42,88,23,10,12,184,2,42,64,27,15,88,7,15,2,19,20,45,34,5,0,92,1,74,50,12,105,11,125,39,105,27,73,49,96,118,24,43,78,16,244,77,237,244,237,
78,16,246,77,237,23,57,0,63,253,228,63,237,63,237,63,3,14,60,125,196,60,49,48,24,67,121,64,52,36,41,24,30,16,18,3,6,4,3,5,3,2,6,17,37,25,37,37,37,29,38,16,6,19,90,1,41,24,39,90,0,36,30,39,90,0,18,3,15,
90,0,40,26,42,90,0,38,28,35,90,1,0,43,43,43,1,43,43,43,43,43,43,43,42,129,129,129,129,0,73,84,121,64,18,46,48,32,33,47,38,46,33,35,104,5,48,32,45,104,1,33,34,1,16,60,43,0,43,43,129,129,0,73,84,121,64,
16,43,44,21,22,44,21,42,104,4,43,22,45,104,1,21,20,1,16,60,43,0,43,129,129,1,43,1,51,17,20,7,6,4,35,34,46,1,39,51,30,1,51,50,62,1,61,1,14,1,35,34,36,38,53,52,18,36,51,50,22,23,37,34,14,1,21,20,22,51,50,
54,53,52,46,1,4,69,141,40,55,254,240,191,140,223,140,59,152,62,196,145,143,197,84,79,228,128,150,254,248,144,150,1,9,147,122,211,98,254,99,119,204,116,240,191,193,235,108,198,4,64,252,157,229,106,150,
162,79,133,128,108,104,107,162,180,56,100,107,149,252,151,151,1,5,152,101,116,82,115,203,118,179,234,232,189,123,193,112,0,0,1,0,156,0,0,4,81,5,228,0,24,0,173,64,63,59,3,1,34,64,5,17,30,8,2,22,23,11,23,
10,24,0,0,17,88,5,7,10,24,10,12,9,11,10,0,1,2,22,4,23,24,11,92,191,10,207,10,223,10,3,10,74,26,23,92,176,24,192,24,208,24,3,24,73,25,123,118,24,43,78,16,244,93,77,237,78,16,246,93,77,237,17,18,23,57,17,
18,57,57,0,63,60,63,237,63,17,18,57,57,3,14,16,60,60,49,48,67,121,64,20,6,16,7,37,14,13,15,13,2,6,16,6,12,90,1,13,8,17,90,1,0,43,1,43,42,43,129,0,73,84,121,64,22,18,21,3,4,20,21,19,21,2,6,21,3,17,104,
5,18,4,22,104,0,3,2,1,16,60,43,0,43,42,129,129,0,113,19,51,17,62,1,51,50,30,1,21,17,35,17,52,39,46,1,35,34,6,7,6,21,17,35,156,140,85,204,119,122,189,90,140,15,26,137,111,127,201,32,20,140,5,228,253,153,
112,111,124,209,223,253,208,2,7,188,63,108,109,168,124,80,216,254,113,0,0,2,0,90,0,0,1,65,6,0,0,11,0,15,0,144,177,5,6,184,1,54,64,42,15,0,1,5,0,1,13,6,15,10,13,12,14,15,17,71,71,74,192,3,208,3,2,5,3,178,
14,92,192,15,208,15,2,5,15,178,9,73,16,160,133,24,43,78,16,244,77,244,67,88,64,15,64,15,1,0,15,32,15,48,15,3,224,15,240,15,2,1,93,113,113,89,93,253,244,67,88,64,15,64,3,1,0,3,32,3,48,3,3,224,3,240,3,2,
1,93,113,113,89,93,78,69,101,68,230,17,18,57,57,0,63,63,63,67,88,178,159,0,1,0,93,89,93,77,237,67,88,178,95,6,1,0,93,89,49,48,19,50,22,21,20,6,35,34,38,53,52,54,3,51,17,35,205,48,68,68,48,47,68,68,23,
141,141,6,0,68,48,47,68,68,47,48,68,254,64,251,192,0,0,2,255,192,254,86,1,67,6,0,0,11,0,26,0,208,64,13,25,8,20,19,17,12,6,22,88,17,15,5,6,184,1,54,64,33,15,0,1,5,0,1,13,12,14,26,28,71,71,74,192,3,208,
3,2,5,3,178,14,92,207,9,223,9,2,5,9,178,26,184,1,143,64,13,0,19,16,19,32,19,3,9,0,19,1,8,19,186,2,46,0,27,2,44,177,133,24,43,16,245,94,93,94,93,252,228,67,88,64,15,79,9,1,15,9,47,9,63,9,3,239,9,255,9,
2,1,93,113,113,89,93,253,244,67,88,64,15,64,3,1,0,3,32,3,48,3,3,224,3,240,3,2,1,93,113,113,89,93,78,69,101,68,230,17,18,57,57,0,63,67,88,178,159,0,1,0,93,89,93,77,237,67,88,178,95,6,1,0,93,89,63,237,63,
17,51,50,49,48,67,121,64,16,23,25,15,16,24,37,23,16,26,128,1,25,15,22,128,0,43,1,43,43,129,129,19,50,22,21,20,6,35,34,38,53,52,54,3,51,17,20,6,35,34,39,53,22,51,50,55,54,53,208,48,67,67,48,48,67,67,21,
142,99,86,71,89,56,45,57,28,17,6,0,68,48,47,68,68,47,48,68,254,64,251,28,137,125,34,126,29,47,30,95,0,1,0,155,0,0,4,16,5,228,0,10,0,192,64,88,216,7,1,9,0,4,1,6,2,1,67,118,2,134,2,151,2,166,2,217,5,5,9,
4,5,1,96,6,5,1,54,8,8,7,2,1,2,3,3,2,2,91,5,4,20,5,5,4,7,8,8,91,5,6,20,5,5,6,2,8,5,7,9,6,10,3,1,4,0,5,5,10,4,6,0,0,6,10,10,5,0,1,2,8,4,9,10,3,184,2,47,178,4,178,7,184,2,47,64,14,6,74,12,32,12,1,9,92,10,
73,11,123,185,24,43,78,16,244,77,237,93,78,16,246,77,237,244,237,17,18,23,57,50,0,63,60,63,63,18,57,47,17,18,57,57,17,18,57,57,17,51,51,135,46,43,5,125,16,196,135,4,46,24,43,5,125,16,196,3,8,16,60,8,60,
49,48,1,94,93,94,93,94,0,93,94,93,1,93,94,93,19,51,17,1,51,9,1,35,1,17,35,155,141,1,247,206,253,171,2,120,198,253,222,141,5,228,252,166,1,182,253,249,253,199,1,233,254,23,0,1,0,135,0,0,1,19,5,228,0,3,
0,40,64,19,3,10,0,0,1,0,3,5,71,71,74,2,92,3,73,4,139,118,24,43,78,16,244,77,253,78,69,101,68,230,18,57,57,0,63,63,49,48,19,51,17,35,135,140,140,5,228,250,28,0,0,1,0,155,0,0,6,246,4,92,0,41,0,210,64,72,
6,8,6,15,107,33,116,8,116,9,116,15,132,8,132,9,132,15,9,33,64,6,35,30,8,2,39,40,40,30,29,19,4,18,41,24,88,13,13,35,88,6,7,0,6,18,41,10,17,20,18,19,31,10,28,3,29,30,0,1,2,39,4,40,41,43,71,71,74,18,92,19,
184,2,48,178,29,92,30,184,2,48,183,40,92,41,73,42,123,118,24,43,78,16,244,77,237,244,237,244,253,78,69,101,68,230,17,18,23,57,17,18,23,57,17,18,57,57,0,63,60,63,63,77,237,60,16,237,17,18,23,57,3,14,16,
60,60,49,48,67,121,64,18,25,27,11,12,26,37,25,12,28,90,0,11,10,27,11,24,90,3,0,43,1,16,60,43,43,129,129,0,73,84,121,64,20,36,38,3,5,37,37,4,38,38,3,35,104,5,36,5,39,104,0,3,2,1,16,60,43,0,43,43,43,129,
129,1,93,19,51,21,54,55,54,51,50,30,1,23,62,1,51,50,30,1,21,17,35,17,52,46,1,35,34,14,1,21,17,35,17,52,46,1,35,34,14,1,21,17,35,155,139,73,77,106,117,79,142,90,33,70,210,121,113,173,84,143,50,121,84,102,
169,78,139,49,122,84,97,169,81,139,4,64,188,104,48,64,62,103,96,128,133,114,204,204,253,174,2,82,175,131,80,120,200,234,254,86,2,45,197,141,85,117,198,204,254,51,0,0,1,0,156,0,0,4,81,4,92,0,24,0,182,184,
2,117,64,66,26,10,213,15,1,34,64,5,17,30,8,2,22,23,15,6,11,23,10,10,24,10,17,88,5,7,0,6,9,12,10,11,0,1,2,22,4,23,24,11,92,191,10,207,10,223,10,3,10,74,26,23,92,176,24,192,24,208,24,3,24,73,25,123,118,
24,43,78,16,244,93,77,237,78,16,246,93,77,237,17,18,23,57,17,18,57,57,0,63,63,237,63,60,18,57,57,1,56,14,16,60,60,49,48,67,121,64,20,6,16,7,37,14,13,15,13,2,6,16,6,12,90,1,13,8,17,90,1,0,43,1,43,42,43,
129,0,73,84,121,64,22,18,21,3,4,20,21,19,21,2,6,21,3,17,104,5,18,4,22,104,0,3,2,1,16,60,43,0,43,42,129,129,1,93,1,73,68,19,51,21,62,1,51,50,30,1,21,17,35,17,52,39,46,1,35,34,6,7,6,21,17,35,156,140,84,
204,120,122,189,90,139,16,25,138,111,127,201,32,20,140,4,64,195,112,111,124,210,222,253,208,2,7,188,63,108,109,168,124,81,215,254,113,0,0,2,0,104,255,228,4,213,4,92,0,13,0,27,0,111,64,23,67,8,14,88,0,
7,21,88,7,11,25,105,4,74,29,17,105,10,73,28,96,133,24,43,78,16,244,77,237,78,16,246,77,237,0,63,237,63,237,49,48,67,121,64,50,1,27,23,37,19,38,2,37,12,38,22,6,25,90,1,20,8,17,90,0,27,1,25,90,1,15,13,17,
90,0,24,5,21,90,0,18,9,21,90,0,26,3,14,90,1,16,11,14,90,1,43,43,43,43,1,43,43,43,43,43,43,43,43,129,1,50,23,22,21,20,0,35,34,0,53,52,55,54,23,34,2,21,20,30,1,51,50,62,1,53,52,2,2,159,251,165,150,254,195,
249,250,254,195,150,165,252,174,250,114,194,116,116,194,114,251,4,92,182,166,227,228,254,171,1,85,228,226,166,183,137,254,254,183,118,204,111,111,204,118,183,1,2,0,0,2,0,158,254,114,5,11,4,92,0,16,0,31,
0,185,64,46,30,64,24,11,27,64,5,17,41,8,2,20,14,15,0,6,17,88,5,7,24,88,11,11,16,14,0,1,20,14,4,15,16,28,105,8,74,33,15,92,16,73,32,123,133,24,43,78,16,244,77,237,78,16,246,77,237,17,18,23,57,0,63,63,237,
63,237,63,3,14,16,60,125,196,60,49,48,24,67,121,64,28,25,31,6,10,26,37,30,38,25,10,28,90,1,31,6,28,90,1,27,9,24,90,0,29,7,17,90,1,0,43,43,1,43,43,43,43,129,129,0,73,84,121,64,16,18,19,3,4,19,3,17,104,
5,18,4,20,104,0,3,2,1,16,60,43,0,43,129,129,0,73,84,121,64,18,21,23,12,13,22,38,21,13,24,104,4,23,12,20,104,0,13,14,1,16,60,43,0,43,43,129,129,19,51,21,62,1,51,50,0,21,20,0,35,34,38,39,17,35,1,34,6,21,
20,30,1,51,50,62,1,53,52,46,1,158,139,83,216,133,232,1,74,254,185,231,130,218,88,139,2,48,182,249,111,207,115,113,199,118,117,198,4,64,200,114,114,254,178,235,240,254,177,108,107,253,183,5,99,254,189,
124,198,116,117,210,115,116,208,115,0,2,0,106,254,114,4,215,4,92,0,16,0,31,0,182,64,45,30,64,25,6,27,64,12,17,41,8,15,29,3,2,0,6,17,88,12,7,25,88,6,11,2,14,0,16,15,29,3,5,2,92,1,74,33,21,105,9,73,32,96,
118,24,43,78,16,244,77,237,78,16,246,77,237,23,57,0,63,63,237,63,237,63,3,14,16,60,125,196,60,49,48,24,67,121,64,28,18,24,7,11,23,38,19,37,24,7,21,90,0,18,11,21,90,0,22,8,25,90,0,20,10,17,90,1,0,43,43,
1,43,43,43,43,129,129,0,73,84,121,64,16,30,31,13,14,30,14,17,104,5,31,13,29,104,1,14,15,1,16,60,43,0,43,129,129,0,73,84,121,64,18,26,28,4,5,27,37,28,4,25,104,4,26,5,29,104,1,4,3,1,16,60,43,0,43,43,129,
129,1,17,35,17,14,1,35,34,0,53,52,0,51,50,22,23,53,5,34,14,1,21,20,30,1,51,50,62,1,53,52,38,4,215,138,88,219,130,231,254,185,1,74,232,134,217,82,254,90,117,198,117,118,199,114,115,206,111,249,4,64,250,
50,2,73,107,108,1,79,240,235,1,78,114,114,200,107,115,208,116,115,210,117,116,198,124,189,254,0,1,0,103,0,0,2,141,4,92,0,17,0,108,64,38,34,64,5,10,2,15,16,8,7,5,0,6,10,88,5,7,17,10,8,7,0,1,2,15,4,16,17,
7,74,19,16,92,17,73,18,96,210,24,43,78,16,244,77,237,78,16,230,17,18,23,57,17,51,0,63,63,77,237,63,17,51,50,3,14,16,60,60,49,48,0,73,84,121,64,22,11,14,3,4,13,14,12,14,2,6,14,3,10,104,5,11,4,15,104,0,
3,2,1,16,60,43,0,43,42,129,129,19,51,21,62,1,51,50,23,7,38,35,34,6,7,6,25,1,35,103,143,64,142,77,58,66,73,44,30,70,130,34,26,143,4,64,159,94,93,37,118,19,115,121,93,254,229,254,144,0,1,0,54,255,228,2,
192,4,92,0,38,0,248,64,94,164,8,164,13,180,9,180,12,196,9,196,12,6,43,32,52,12,63,32,132,12,139,32,159,30,155,33,164,10,203,2,9,9,3,25,1,75,233,20,1,172,32,216,20,231,0,3,23,1,24,21,2,185,2,198,22,215,
28,3,155,31,156,32,170,2,3,121,29,121,32,153,2,3,40,8,30,10,0,1,20,21,9,10,11,3,23,15,1,31,1,47,1,3,1,184,2,49,64,10,3,88,37,7,0,21,16,21,2,21,184,2,49,64,35,23,88,17,11,1,21,20,0,125,26,105,14,74,40,
255,40,1,9,15,40,1,8,6,105,192,34,1,34,178,20,73,39,158,133,24,43,78,16,244,77,244,93,237,94,93,94,93,78,16,246,77,237,228,17,51,50,0,63,253,228,93,63,253,228,93,18,23,57,17,51,17,51,17,51,49,48,67,121,
64,28,35,36,24,25,15,16,4,5,4,36,6,128,0,24,16,26,128,1,5,35,3,128,1,25,15,23,128,0,43,43,1,43,43,129,129,129,129,1,93,93,93,113,0,93,93,94,93,94,1,93,0,93,1,7,38,35,34,6,21,20,23,22,23,22,23,22,21,20,
6,35,34,38,39,55,22,51,50,54,53,52,39,38,39,38,39,38,53,52,54,51,50,2,191,90,112,107,68,97,40,40,128,156,56,55,188,141,94,171,56,88,107,120,84,118,39,39,137,147,53,53,169,129,150,3,201,93,109,90,60,53,
48,49,66,81,75,76,95,134,186,82,72,100,121,108,73,60,47,46,70,76,74,74,95,124,164,0,0,1,0,87,0,0,2,129,5,212,0,11,0,101,64,50,11,0,7,10,3,8,0,7,9,4,5,1,6,9,4,2,1,6,10,3,11,2,3,4,5,8,6,10,0,0,9,144,10,
6,7,10,8,11,0,1,2,5,6,6,7,13,71,71,74,4,184,1,143,178,6,92,7,186,1,143,0,9,1,120,179,12,160,205,24,43,16,246,244,253,244,78,69,101,68,238,17,18,23,57,0,63,63,77,237,63,17,23,57,15,15,15,15,49,48,1,51,
17,51,21,35,17,35,17,35,53,51,1,22,141,222,222,141,191,191,5,212,254,108,120,252,56,3,200,120,0,0,1,0,138,255,228,4,66,4,64,0,23,0,118,64,34,51,8,13,1,14,0,7,88,19,11,14,0,6,14,13,15,12,1,0,2,23,12,92,
15,74,25,2,92,23,73,24,139,118,24,43,78,16,244,77,237,78,16,246,77,237,17,18,57,57,17,18,57,57,0,63,60,63,237,17,18,57,57,49,48,67,121,64,38,3,22,17,38,10,11,9,11,2,6,4,3,5,3,2,6,21,37,8,18,12,90,1,6,
20,2,90,0,11,16,7,90,0,3,22,7,90,0,43,43,1,43,43,43,42,42,43,129,19,51,17,20,23,30,1,51,50,54,55,54,53,17,51,17,20,14,1,35,34,46,1,53,138,141,20,30,169,117,117,163,31,21,143,105,211,159,159,213,105,4,
64,254,4,186,70,100,116,113,92,63,204,1,252,253,234,225,228,129,129,231,232,0,0,1,0,53,0,0,4,53,4,64,0,6,0,134,64,48,184,6,199,5,200,6,3,5,2,3,2,1,3,91,4,5,20,4,4,5,2,1,2,3,1,91,0,6,20,0,0,6,3,1,4,4,0,
6,6,10,2,5,6,8,71,71,74,3,186,1,41,0,4,1,73,178,5,242,6,186,1,73,0,1,1,41,183,64,0,73,7,17,158,205,24,43,75,82,88,176,0,26,89,78,16,252,26,77,237,244,254,244,237,78,69,101,68,230,17,18,57,0,63,63,60,18,
57,57,135,5,77,46,43,8,125,16,196,135,5,46,24,43,8,125,16,196,0,46,49,48,1,93,19,51,9,1,51,1,35,53,149,1,108,1,105,150,254,14,25,4,64,252,232,3,24,251,192,0,0,1,0,9,0,0,6,157,4,64,0,12,1,51,64,81,37,10,
57,2,57,5,68,10,86,10,120,2,136,2,200,2,200,5,9,54,8,57,12,89,11,119,8,120,12,134,4,136,9,137,12,8,150,4,152,9,152,12,168,8,184,11,198,8,201,9,201,12,8,39,2,40,3,39,5,39,8,41,12,5,25,10,25,11,120,6,3,
9,10,10,1,8,114,10,3,4,32,184,255,140,179,5,9,8,32,184,255,139,64,61,2,12,11,32,6,7,8,8,91,5,6,20,5,5,6,9,5,4,4,91,10,9,20,10,10,9,3,10,11,11,91,2,3,20,2,2,3,12,2,1,1,91,0,12,20,0,0,12,9,11,8,12,1,3,4,
6,4,7,0,5,2,184,2,53,179,8,12,10,10,184,2,53,64,17,7,0,6,9,8,7,4,3,10,11,12,0,14,71,71,74,7,65,11,1,41,0,6,2,51,0,5,2,52,0,10,2,52,0,2,2,51,0,1,1,41,181,0,73,13,157,207,24,43,78,16,244,77,253,25,244,24,
253,253,25,244,24,253,78,69,101,68,238,17,51,51,17,51,51,17,51,51,0,63,60,77,237,63,60,253,60,17,18,23,57,17,18,57,57,135,5,46,43,135,125,196,135,46,24,43,135,125,196,135,46,24,43,135,125,196,135,46,24,
43,135,125,196,43,43,43,49,48,1,94,93,94,93,93,93,93,0,93,19,51,9,1,51,9,1,51,1,35,9,1,35,9,144,1,77,1,93,25,1,92,1,83,146,254,40,27,254,166,254,163,26,4,64,252,234,3,22,252,234,3,22,251,192,3,11,252,
245,0,1,255,249,0,0,3,223,4,64,0,11,0,176,64,74,183,11,1,119,11,135,11,184,5,3,15,13,31,13,47,13,3,11,0,7,10,3,8,0,7,9,4,5,1,6,9,4,2,1,6,10,3,7,6,1,1,91,0,7,20,0,0,7,3,4,9,9,91,10,3,20,10,10,3,3,1,4,0,
7,9,6,10,4,0,6,6,10,10,3,184,2,54,178,4,178,7,184,2,54,183,6,74,13,15,13,1,5,1,184,2,54,178,0,178,9,184,2,54,181,10,73,12,157,185,24,43,78,16,244,77,237,244,237,67,88,180,160,13,192,13,2,1,93,89,93,78,
16,246,77,237,244,237,0,63,60,63,60,17,18,57,57,17,18,57,57,135,5,46,43,135,125,196,135,46,24,43,135,125,196,15,15,15,15,49,48,1,93,93,93,19,51,9,1,51,9,1,35,9,1,35,1,32,168,1,32,1,32,168,254,140,1,163,
170,254,179,254,184,167,1,156,4,64,254,109,1,147,253,251,253,197,1,201,254,55,2,59,0,0,1,0,39,254,114,4,49,4,64,0,7,0,179,64,71,119,2,1,4,3,4,4,20,3,20,4,36,3,36,4,104,2,7,2,2,1,7,6,7,0,6,3,7,7,6,2,1,
1,91,0,7,20,0,0,7,6,3,3,91,4,5,20,4,4,5,3,1,4,0,2,2,6,4,0,6,5,6,14,7,2,0,9,71,71,74,3,184,1,41,179,15,4,1,4,184,2,55,179,15,2,1,2,191,2,55,0,0,0,5,1,41,0,6,1,52,0,1,1,41,178,0,73,8,186,2,79,1,112,0,24,
43,78,16,244,77,237,244,237,16,253,93,253,93,237,78,69,101,68,230,17,18,57,0,63,60,63,60,18,57,47,17,18,57,57,135,5,77,46,43,125,16,196,135,46,24,43,135,8,125,196,135,8,16,60,8,196,49,48,1,93,0,93,19,
51,9,1,51,1,35,19,39,148,1,118,1,107,149,253,119,148,210,4,64,252,186,3,70,250,50,1,224,0,1,0,9,0,0,3,98,4,64,0,7,0,129,64,50,5,2,21,2,2,5,6,1,2,2,91,5,6,20,5,5,6,4,3,5,2,6,1,7,0,2,144,5,10,7,144,0,6,
6,1,2,5,4,125,1,74,9,7,178,5,73,8,157,207,24,43,78,16,244,77,228,78,16,246,77,228,17,51,17,51,0,63,237,63,237,17,18,57,57,17,18,57,57,135,5,46,43,135,125,196,49,48,67,88,64,28,199,2,199,5,200,6,3,183,
5,184,6,200,1,3,120,6,184,1,183,2,3,120,1,119,2,119,5,3,1,93,93,93,93,89,1,93,19,33,1,33,21,33,1,33,67,3,31,253,152,2,84,252,187,2,104,253,210,4,64,252,60,124,3,197,0,0,1,0,75,254,61,2,142,5,191,0,46,
0,64,64,22,23,0,148,46,46,33,14,148,13,17,33,148,34,19,48,246,13,13,34,162,18,26,184,1,133,64,10,5,129,42,162,46,73,47,119,114,24,43,78,16,244,77,252,228,253,60,252,60,16,228,0,63,237,63,237,17,57,47,
253,57,49,48,19,54,55,62,1,55,54,18,62,1,55,54,59,1,21,35,34,6,21,20,7,14,1,7,30,1,21,20,23,22,23,30,1,51,21,35,34,39,46,1,39,38,39,46,2,39,75,61,38,49,51,5,2,3,40,84,65,39,86,56,31,105,67,7,13,91,98,
110,99,4,6,19,14,61,99,56,100,46,67,81,12,9,1,1,39,94,73,2,79,2,22,29,102,93,46,1,74,142,84,19,11,157,77,129,233,64,123,131,47,47,189,215,192,35,54,29,20,23,157,17,25,111,93,66,180,184,130,71,2,0,0,1,
2,104,254,114,2,247,5,228,0,3,0,38,64,15,1,2,0,3,14,0,0,2,3,1,127,0,73,4,231,185,1,18,0,24,43,78,16,244,77,237,57,57,0,63,63,18,57,57,49,48,1,51,17,35,2,104,143,143,5,228,248,142,0,1,0,65,254,61,2,132,
5,191,0,45,0,71,64,23,24,0,148,1,1,33,15,148,14,19,33,148,34,17,47,71,71,74,1,162,6,129,42,184,1,133,64,11,27,27,19,162,34,14,73,46,89,114,24,43,78,16,244,60,77,252,60,16,253,244,252,78,69,101,68,230,
0,63,77,237,63,253,17,57,47,237,57,49,48,1,21,6,7,14,1,7,6,2,14,1,7,6,43,1,53,51,50,54,53,52,55,62,1,55,46,1,53,52,39,46,1,43,1,53,51,50,23,30,1,23,22,23,30,2,2,132,61,38,49,51,5,2,3,40,84,65,39,86,56,
31,105,67,8,14,99,88,117,92,9,11,63,89,31,56,100,46,67,81,12,9,1,1,39,94,2,79,163,1,22,29,102,93,46,254,181,141,85,18,11,157,76,129,239,65,121,136,38,56,183,211,221,38,51,44,157,18,24,112,92,66,180,184,
131,71,0,1,0,112,2,67,4,104,3,122,0,23,0,88,64,21,4,0,4,2,12,12,10,14,4,25,0,25,2,22,12,22,14,4,0,148,1,184,1,37,178,4,148,21,184,1,44,179,16,12,148,13,184,1,37,64,18,9,148,16,12,1,13,0,74,25,0,13,1,13,
73,24,95,113,24,43,78,16,228,93,16,246,17,57,57,0,47,77,237,244,237,16,244,253,244,237,49,48,0,93,1,93,1,21,14,1,35,34,39,46,1,35,34,6,7,53,62,1,51,50,23,30,1,51,50,54,4,104,112,97,43,95,170,132,73,32,
44,106,112,110,98,46,97,171,118,87,35,42,86,3,69,162,63,33,77,60,23,38,67,160,62,34,81,56,27,33,255,255,0,49,0,0,5,186,7,24,2,38,0,36,0,0,1,7,0,142,1,124,1,42,0,22,64,12,3,2,0,20,26,8,8,51,3,2,17,32,0,
63,53,53,1,43,53,53,255,255,0,49,0,0,5,186,7,197,2,38,0,36,0,0,1,7,0,221,1,161,1,42,0,22,64,12,3,2,0,20,14,8,8,51,3,2,17,32,0,63,53,53,1,43,53,53,255,255,0,111,254,132,6,13,5,228,2,38,0,38,0,0,1,7,0,222,
1,244,0,0,0,11,182,1,0,39,34,21,14,51,1,43,53,0,255,255,0,180,0,0,3,255,7,103,2,38,0,40,0,0,1,7,0,141,0,225,1,41,0,18,64,10,1,0,14,14,0,1,51,1,14,32,0,63,53,1,43,53,255,255,0,180,0,0,5,55,7,23,2,38,0,
49,0,0,1,7,0,217,1,52,1,41,0,18,64,10,1,0,24,11,1,5,51,1,14,32,0,63,53,1,43,53,255,255,0,115,255,219,6,128,7,24,2,38,0,50,0,0,1,7,0,142,2,0,1,42,0,22,64,12,3,2,0,37,43,9,3,51,3,2,34,32,0,63,53,53,1,43,
53,53,255,255,0,184,255,219,4,134,7,24,2,38,0,56,0,0,1,7,0,142,1,37,1,42,0,22,64,12,2,1,0,36,42,0,16,51,2,1,33,32,0,63,53,53,1,43,53,53,255,255,0,107,255,228,4,216,6,62,2,38,0,68,0,0,1,7,0,141,1,59,0,
0,0,18,64,10,2,0,34,34,9,0,51,2,35,34,0,63,53,1,43,53,255,255,0,107,255,228,4,216,6,62,2,38,0,68,0,0,1,7,0,67,1,57,0,0,0,18,64,10,2,0,34,34,9,0,51,2,34,34,0,63,53,1,43,53,255,255,0,107,255,228,4,216,6,
6,2,38,0,68,0,0,1,7,0,216,0,185,0,0,0,18,64,10,2,0,36,36,9,0,51,2,38,34,0,63,53,1,43,53,255,255,0,107,255,228,4,216,5,238,2,38,0,68,0,0,1,7,0,142,1,66,0,0,0,22,64,12,3,2,0,41,47,9,0,51,3,2,38,34,0,63,
53,53,1,43,53,53,255,255,0,107,255,228,4,216,5,238,2,38,0,68,0,0,1,7,0,217,0,250,0,0,0,18,64,10,2,0,46,33,9,0,51,2,36,34,0,63,53,1,43,53,255,255,0,107,255,228,4,216,6,155,2,38,0,68,0,0,1,7,0,221,1,103,
0,0,0,32,64,21,3,2,63,41,111,41,191,41,207,41,4,0,41,35,9,0,51,3,2,38,34,0,63,53,53,1,43,93,53,53,255,255,0,105,254,132,4,188,4,92,2,38,0,70,0,0,1,7,0,222,1,75,0,0,0,11,182,1,0,39,34,19,13,51,1,43,53,
0,255,255,0,104,255,228,4,202,6,62,2,38,0,72,0,0,1,7,0,141,1,26,0,0,0,18,64,10,2,0,35,35,8,16,51,2,35,34,0,63,53,1,43,53,255,255,0,104,255,228,4,202,6,62,2,38,0,72,0,0,1,7,0,67,1,23,0,0,0,18,64,10,2,0,
35,35,8,16,51,2,35,34,0,63,53,1,43,53,255,255,0,104,255,228,4,202,6,6,2,38,0,72,0,0,1,7,0,216,0,152,0,0,0,18,64,10,2,0,37,37,8,16,51,2,39,34,0,63,53,1,43,53,255,255,0,104,255,228,4,202,5,238,2,38,0,72,
0,0,1,7,0,142,1,32,0,0,0,22,64,12,3,2,0,42,48,8,16,51,3,2,39,34,0,63,53,53,1,43,53,53,255,255,0,55,0,0,1,232,6,62,2,38,0,215,0,0,1,7,0,141,255,77,0,0,0,18,64,10,1,0,7,6,0,1,51,1,7,34,0,63,53,1,43,53,255,
255,255,185,0,0,1,106,6,62,2,38,0,215,0,0,1,7,0,67,255,74,0,0,0,18,64,10,1,0,6,5,0,1,51,1,6,34,0,63,53,1,43,53,255,255,255,98,0,0,2,56,6,6,2,38,0,215,0,0,1,7,0,216,254,203,0,0,0,18,64,10,1,0,10,6,0,1,
51,1,10,34,0,63,53,1,43,53,255,255,255,141,0,0,2,13,5,238,2,38,0,215,0,0,1,7,0,142,255,83,0,0,0,22,64,12,2,1,0,13,19,0,1,51,2,1,10,34,0,63,53,53,1,43,53,53,255,255,0,156,0,0,4,81,5,238,2,38,0,81,0,0,1,
7,0,217,0,175,0,0,0,18,64,10,1,0,39,26,0,10,51,1,29,34,0,63,53,1,43,53,255,255,0,104,255,228,4,213,6,62,2,38,0,82,0,0,1,7,0,141,1,31,0,0,0,18,64,10,2,0,30,30,10,4,51,2,30,34,0,63,53,1,43,53,255,255,0,
104,255,228,4,213,6,62,2,38,0,82,0,0,1,7,0,67,1,28,0,0,0,18,64,10,2,0,30,30,10,4,51,2,30,34,0,63,53,1,43,53,255,255,0,104,255,228,4,213,6,6,2,38,0,82,0,0,1,7,0,216,0,157,0,0,0,18,64,10,2,0,32,32,10,4,
51,2,34,34,0,63,53,1,43,53,255,255,0,104,255,228,4,213,5,238,2,38,0,82,0,0,1,7,0,142,1,37,0,0,0,22,64,12,3,2,0,37,43,10,4,51,3,2,34,34,0,63,53,53,1,43,53,53,255,255,0,104,255,228,4,213,5,238,2,38,0,82,
0,0,1,7,0,217,0,221,0,0,0,18,64,10,2,0,42,29,10,4,51,2,32,34,0,63,53,1,43,53,255,255,0,138,255,228,4,66,6,62,2,38,0,88,0,0,1,7,0,141,0,238,0,0,0,18,64,10,1,0,26,26,0,14,51,1,26,34,0,63,53,1,43,53,255,
255,0,138,255,228,4,66,6,62,2,38,0,88,0,0,1,7,0,67,0,235,0,0,0,18,64,10,1,0,26,26,0,14,51,1,26,34,0,63,53,1,43,53,255,255,0,138,255,228,4,66,6,6,2,38,0,88,0,0,1,6,0,216,108,0,0,18,64,10,1,0,28,28,0,14,
51,1,30,34,0,63,53,1,43,53,255,255,0,138,255,228,4,66,5,238,2,38,0,88,0,0,1,7,0,142,0,244,0,0,0,22,64,12,2,1,0,33,39,0,14,51,2,1,30,34,0,63,53,53,1,43,53,53,0,1,0,157,254,198,3,207,5,228,0,11,0,97,64,
17,6,1,0,7,4,9,5,8,168,9,218,3,10,2,11,168,10,184,2,3,181,0,0,3,10,9,4,184,1,61,182,1,129,6,2,5,135,6,184,1,133,181,7,11,8,135,0,7,184,1,61,181,9,73,12,110,151,24,43,78,16,244,77,246,60,244,60,16,253,
244,60,16,228,230,17,57,57,0,63,246,244,60,16,60,253,244,60,16,60,47,18,57,57,49,48,1,51,3,37,21,37,19,35,19,5,53,5,1,233,149,23,1,104,254,152,27,153,29,254,151,1,105,5,228,254,55,21,149,26,251,17,4,239,
26,149,21,0,2,0,65,3,52,2,243,5,228,0,11,0,23,0,102,180,55,8,21,106,3,184,1,82,64,17,15,106,9,5,12,121,0,74,25,18,121,6,73,24,89,114,24,43,78,16,244,77,237,78,16,246,77,237,0,63,237,253,237,49,48,67,121,
64,42,1,23,22,2,12,87,1,20,4,18,87,0,14,10,12,87,1,16,8,18,87,0,23,1,21,87,0,19,5,21,87,0,13,11,15,87,1,17,7,15,87,1,43,43,43,43,1,43,43,43,43,129,1,20,6,35,34,38,53,52,54,51,50,22,7,52,38,35,34,6,21,
20,22,51,50,54,2,243,202,144,144,200,205,142,142,201,119,130,93,94,135,136,92,92,132,4,140,145,199,200,147,141,200,200,146,102,138,139,99,97,141,138,0,2,0,103,254,226,4,58,5,60,0,29,0,38,1,16,64,103,14,
32,19,21,57,171,6,203,31,196,37,3,11,64,16,21,57,36,2,68,2,91,21,118,8,134,8,148,37,173,21,180,3,192,3,192,4,10,23,8,2,7,8,18,19,19,1,29,30,38,21,20,0,0,1,19,19,91,20,0,20,20,20,0,22,21,18,17,4,16,37,
38,8,9,4,10,32,3,2,29,28,4,27,4,6,7,30,31,4,32,1,0,20,19,13,12,4,9,15,5,1,8,5,184,2,56,178,32,88,0,184,2,42,183,27,7,9,0,12,1,8,12,184,2,49,178,10,88,19,184,2,41,64,26,16,11,0,5,4,12,13,19,20,1,178,4,
178,13,74,40,20,178,35,105,24,73,39,96,133,24,43,78,16,244,77,237,228,78,16,246,77,228,228,17,51,17,51,17,51,50,0,63,236,253,228,94,93,94,63,236,253,244,94,93,94,50,17,51,17,51,17,51,17,23,57,17,18,23,
57,17,18,23,57,18,23,57,135,14,46,43,135,14,125,196,135,14,196,196,60,60,7,14,16,60,60,60,60,49,48,24,67,121,64,14,33,34,25,26,33,26,35,90,0,34,25,32,90,1,0,43,1,43,129,129,1,93,43,0,93,43,1,23,3,22,23,
7,38,39,1,22,51,50,55,23,14,1,35,34,39,3,39,19,46,1,53,52,0,51,50,23,7,38,35,34,6,21,20,22,23,3,193,121,132,72,44,85,46,49,254,118,75,69,146,160,91,78,212,106,96,112,152,117,151,108,100,1,45,243,90,91,
63,64,57,171,229,66,67,5,60,60,254,255,46,48,105,44,32,253,2,32,128,106,69,83,37,254,217,64,1,45,97,224,135,240,1,85,33,122,21,241,198,109,164,61,0,2,0,57,255,219,4,52,5,228,0,60,0,70,0,210,64,30,15,38,
1,15,64,16,20,57,22,8,24,25,0,98,60,60,16,53,97,63,255,69,97,47,47,41,0,36,1,36,184,2,57,183,34,148,41,13,15,13,1,13,184,2,57,64,51,16,97,8,5,29,30,45,3,56,55,61,3,57,20,21,22,23,26,27,6,28,19,4,3,2,1,
59,58,6,57,5,24,60,0,15,25,1,25,187,13,99,12,246,36,99,37,74,72,57,99,28,184,1,3,179,66,19,99,5,184,1,141,64,10,0,155,66,99,50,73,71,89,114,24,43,78,16,244,77,237,244,244,237,16,244,237,78,16,246,77,237,
244,253,230,93,17,57,57,17,18,23,57,17,18,23,57,17,23,51,23,50,0,63,253,228,93,63,253,228,93,16,60,16,237,244,253,17,57,47,237,57,57,49,48,67,121,64,14,17,18,6,7,17,7,19,87,0,18,6,16,87,1,43,1,43,129,
129,0,43,1,93,19,51,38,39,38,53,52,54,51,50,30,1,23,35,46,1,35,34,6,21,20,31,2,33,21,33,22,21,20,7,22,23,22,51,50,55,51,22,14,1,35,34,39,38,39,6,35,34,38,53,52,54,51,50,23,54,53,52,39,33,1,38,35,34,6,
21,20,22,51,50,99,254,54,6,11,208,153,100,143,92,11,136,4,110,92,101,124,29,7,45,1,64,254,226,37,22,61,105,60,50,95,11,141,1,69,100,62,67,78,108,89,83,154,96,113,132,90,67,77,7,45,254,226,1,30,68,46,33,
44,39,28,75,3,76,192,35,57,51,134,195,85,161,137,121,128,113,92,81,82,18,144,129,126,138,107,81,51,64,36,232,117,189,75,35,48,77,160,101,87,96,136,39,67,39,141,124,254,4,41,44,33,32,43,0,0,2,0,130,254,
86,3,231,6,0,0,57,0,71,0,165,64,25,13,12,2,40,5,64,10,70,25,18,25,50,6,40,8,49,58,65,19,4,33,15,1,1,1,184,1,146,183,4,97,55,1,0,29,1,29,184,1,44,64,40,33,97,25,15,58,65,49,19,162,36,99,22,155,1,99,0,155,
68,99,16,74,73,49,162,7,99,52,155,29,99,28,135,61,99,45,73,72,95,173,24,43,78,16,244,77,237,244,237,244,237,228,78,16,246,77,237,244,237,244,237,244,17,57,57,0,63,253,228,93,63,253,228,93,18,23,57,49,
48,67,121,64,28,53,54,34,35,23,24,5,6,5,54,7,87,0,34,24,36,87,1,6,53,4,87,1,35,23,33,87,0,43,43,1,43,43,129,129,129,129,0,93,1,35,46,1,35,34,6,21,20,23,30,1,23,30,2,21,20,6,7,30,1,21,20,6,35,34,38,39,
51,22,23,22,51,50,54,53,52,39,38,39,38,39,46,1,53,52,62,1,55,46,1,53,52,54,51,50,22,1,14,1,21,20,23,22,23,62,1,53,52,38,39,3,196,147,11,122,98,106,121,19,26,114,141,165,117,58,155,131,106,112,204,165,
163,216,21,148,23,44,72,104,105,125,50,50,180,172,38,84,79,62,113,85,99,79,201,171,166,196,254,73,110,121,53,69,198,122,135,94,238,4,170,94,107,104,76,44,37,50,97,84,99,104,122,58,101,170,25,66,178,92,
132,182,166,122,64,35,58,106,75,68,64,64,115,110,28,65,142,74,63,121,91,25,71,144,88,139,178,177,253,248,17,117,82,73,60,79,105,15,123,79,62,104,141,0,1,1,57,1,182,3,159,4,29,0,11,0,40,185,0,6,1,184,64,
11,0,13,71,71,74,3,230,9,73,12,142,185,1,108,0,24,43,78,16,244,77,253,78,69,101,68,230,0,47,77,237,49,48,1,50,22,21,20,6,35,34,38,53,52,54,2,108,127,180,180,127,127,180,180,4,29,180,127,128,180,180,128,
127,180,0,0,1,0,94,255,25,3,254,5,233,0,19,0,110,64,14,14,17,18,16,19,15,0,1,1,11,15,0,18,13,184,1,29,64,32,11,12,0,14,17,15,16,18,1,19,0,21,71,71,74,12,246,15,181,16,254,19,181,0,0,1,9,0,0,1,8,0,184,
1,168,181,7,73,20,119,113,24,43,78,16,244,77,244,94,93,94,93,253,254,253,244,78,69,101,68,230,17,18,57,57,17,18,57,57,0,63,60,77,253,60,47,60,18,57,47,17,18,57,57,16,60,60,49,48,5,17,34,39,46,2,53,52,
55,54,51,33,21,35,17,35,17,35,17,1,227,75,36,78,126,74,116,97,202,2,1,84,119,217,231,3,169,8,17,101,169,104,189,119,100,75,249,123,6,133,249,123,0,1,0,162,255,228,4,6,6,0,0,46,0,193,64,18,31,64,12,20,
57,85,8,24,26,23,21,13,176,33,192,33,2,33,184,2,69,64,27,32,32,26,40,88,5,1,26,88,21,11,0,10,45,1,46,0,37,105,8,178,29,105,18,74,48,32,186,2,68,0,23,1,120,183,46,92,0,73,47,123,133,24,43,78,16,244,77,
253,230,230,78,16,246,77,237,244,237,17,18,57,57,0,63,63,237,63,253,17,57,47,237,93,57,17,51,17,51,49,48,67,121,64,64,35,44,27,28,19,20,2,12,43,44,42,44,2,6,3,38,10,9,11,9,2,6,27,20,29,128,1,39,6,37,128,
1,41,4,45,128,0,35,12,37,128,3,28,19,26,128,0,38,7,40,128,1,44,2,40,128,1,36,9,34,128,0,12,13,16,60,43,43,43,43,1,43,43,43,43,42,43,42,129,129,129,129,1,43,51,17,52,62,1,51,50,22,21,20,6,7,6,7,22,23,30,
1,21,20,6,35,34,39,53,22,51,50,54,53,52,38,39,53,51,50,54,53,52,38,35,34,6,7,6,21,17,162,87,199,135,177,217,100,89,49,88,97,52,108,122,234,183,123,85,105,83,128,169,203,192,32,139,168,140,108,85,142,32,
24,3,227,226,192,123,206,156,99,154,46,25,12,15,27,57,200,131,192,244,49,133,49,171,136,151,190,6,157,147,105,99,134,93,78,61,187,252,42,0,0,4,255,236,255,229,6,15,6,8,0,15,0,31,0,59,0,69,1,35,64,35,4,
40,1,64,43,212,39,211,40,3,119,8,69,33,60,32,49,58,48,59,56,62,57,94,61,61,59,60,94,15,32,31,32,2,32,186,2,61,0,20,1,34,182,12,1,48,0,59,1,59,186,2,61,0,28,1,34,182,4,11,66,112,37,167,52,184,1,40,178,
44,190,49,188,2,23,0,48,2,60,0,16,1,34,64,15,0,74,71,60,58,101,32,0,59,16,59,208,59,3,59,186,2,59,0,24,1,34,178,8,73,70,184,1,22,177,208,24,43,78,16,244,77,253,246,93,60,253,60,78,16,246,77,253,246,237,
244,237,244,237,0,63,253,246,93,60,63,253,246,93,237,17,57,47,237,57,57,17,18,57,57,17,18,57,57,49,48,67,121,64,88,63,68,1,40,2,38,30,37,26,38,6,37,14,37,18,38,22,37,10,38,39,38,64,37,35,37,29,3,16,100,
1,27,5,24,100,0,19,13,16,100,1,21,11,24,100,0,63,40,66,117,3,68,34,66,117,1,31,1,28,100,0,25,7,28,100,0,17,15,20,100,1,23,9,20,100,1,65,38,62,117,0,40,41,67,36,69,117,1,43,16,60,43,43,43,43,43,1,43,43,
43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,129,129,1,93,113,1,20,2,4,35,34,36,2,53,52,18,36,51,50,4,18,7,52,2,36,35,34,4,2,21,20,18,4,51,50,36,18,1,33,50,30,1,21,20,7,6,7,30,1,29,1,20,31,1,35,38,47,
1,46,2,43,1,17,35,19,17,51,50,55,54,53,52,38,35,6,15,210,254,146,209,209,254,146,211,211,1,109,210,210,1,107,212,109,182,254,200,180,181,254,195,181,181,1,62,180,179,1,58,181,252,21,1,121,132,116,73,26,
20,67,61,42,32,15,160,15,6,7,4,31,57,85,227,143,143,222,101,36,53,76,105,2,248,212,254,149,212,211,1,108,208,210,1,112,210,209,254,144,208,180,1,61,182,182,254,195,182,181,254,198,182,183,1,57,2,129,53,
120,80,69,50,37,44,30,79,96,102,72,48,24,56,77,111,61,50,22,254,135,3,6,254,244,23,33,79,69,64,0,3,255,236,255,229,6,15,6,4,0,15,0,31,0,57,0,242,64,15,109,8,15,33,31,33,47,33,3,9,15,33,1,8,33,184,2,98,
64,24,36,97,15,55,1,55,253,20,130,12,1,0,45,16,45,32,45,3,9,0,45,1,8,45,184,2,97,64,15,42,106,49,253,28,130,4,11,33,99,32,32,45,99,46,184,2,39,181,16,130,0,74,59,39,186,1,133,0,52,2,58,183,24,130,8,73,
58,206,134,24,43,78,16,244,77,253,254,237,78,16,246,77,253,254,237,60,16,237,0,63,253,246,253,228,94,93,94,93,63,253,246,93,253,228,94,93,94,93,49,48,67,121,64,82,50,54,37,41,1,31,2,38,30,37,26,38,6,37,
14,37,18,38,22,37,10,38,29,3,16,165,1,27,5,24,165,0,19,13,16,165,1,21,11,24,165,0,37,54,39,87,0,41,50,39,87,0,31,1,28,165,0,25,7,28,165,0,17,15,20,165,1,23,9,20,165,1,38,53,36,87,1,40,51,42,87,0,43,43,
43,43,43,43,1,43,43,43,43,43,43,43,43,43,43,43,43,43,43,129,129,129,1,20,2,4,35,34,36,2,53,52,18,36,51,50,4,18,7,52,2,36,35,34,4,2,21,20,18,4,51,50,36,18,1,35,46,1,35,34,6,21,20,22,51,50,54,55,51,14,1,
35,34,38,53,52,54,51,50,22,6,15,210,254,147,210,210,254,146,210,210,1,109,211,210,1,109,210,109,181,254,198,182,181,254,198,181,181,1,59,181,181,1,58,181,254,220,136,21,117,97,127,154,148,119,100,131,
18,136,19,210,151,189,226,235,181,167,200,2,245,211,254,150,211,211,1,107,210,210,1,107,210,210,254,149,210,182,1,57,182,182,254,198,181,182,254,198,181,181,1,58,1,93,89,89,179,172,168,176,123,123,164,
194,243,215,226,252,167,0,2,0,12,2,139,7,174,5,233,0,12,0,20,0,171,64,36,1,2,19,17,12,3,4,4,85,11,12,20,11,11,12,10,6,5,5,85,11,10,20,11,11,10,11,6,5,4,3,5,19,17,17,8,184,1,196,64,25,9,14,19,98,20,20,
13,13,12,12,10,10,9,0,5,10,7,4,12,11,0,1,127,3,2,186,1,3,0,11,1,3,180,6,7,127,9,8,186,1,137,0,14,1,0,180,15,16,127,18,17,184,1,0,181,19,73,21,115,152,24,43,78,16,244,77,244,60,253,60,244,246,60,253,60,
25,244,244,60,24,253,60,18,57,57,17,57,57,0,63,60,16,60,16,60,16,60,16,253,60,16,253,60,17,18,23,57,135,5,46,43,135,125,196,135,46,24,43,135,125,196,0,17,18,57,57,49,48,1,17,35,17,1,35,1,17,35,17,51,9,
1,33,21,33,17,35,17,33,53,7,174,150,254,191,99,254,201,149,243,1,11,1,26,252,66,254,207,150,254,209,5,233,252,162,2,198,253,58,2,198,253,58,3,94,253,171,2,85,137,253,43,2,213,137,0,0,1,0,234,5,10,2,155,
6,62,0,3,0,34,64,16,1,2,0,223,128,3,0,2,1,227,3,73,4,163,152,24,43,78,16,244,77,237,57,57,0,47,26,237,57,57,49,48,1,51,1,35,1,196,215,254,217,138,6,62,254,204,0,2,0,58,5,6,2,186,5,238,0,11,0,23,0,53,64,
20,192,3,192,15,2,192,0,192,12,2,12,124,18,18,0,124,6,15,164,21,184,1,137,183,3,164,9,73,24,89,114,24,43,78,16,244,77,253,246,237,0,47,237,60,16,237,93,1,93,49,48,19,50,22,21,20,6,35,34,38,53,52,54,33,
50,22,21,20,6,35,34,38,53,52,54,174,48,68,68,48,48,68,68,1,200,48,68,68,48,48,68,68,5,238,68,48,48,68,68,48,48,68,68,48,48,68,68,48,48,68,0,1,0,56,255,219,4,44,5,228,0,19,0,205,64,79,7,4,23,4,2,17,16,
1,18,9,14,15,2,18,9,13,12,5,18,9,10,11,6,18,9,7,11,6,19,8,4,12,5,19,8,3,15,2,19,8,0,16,1,19,8,18,19,8,8,85,9,18,20,9,9,18,19,8,18,9,17,0,1,2,3,14,6,15,16,10,7,6,5,4,13,6,12,11,18,184,2,93,178,16,127,15,
187,1,57,0,12,0,9,2,93,64,12,11,127,12,2,5,1,6,15,12,16,11,18,186,1,133,0,19,2,92,181,1,1,6,74,21,8,186,1,133,0,9,2,92,183,16,16,11,73,20,89,114,24,43,78,16,244,60,77,16,244,237,78,16,246,60,77,16,244,
237,17,18,57,57,17,18,57,57,0,47,253,230,16,254,253,230,17,18,23,57,17,18,23,57,17,18,57,57,135,5,46,43,135,125,196,15,15,15,15,15,15,15,15,49,48,1,93,1,33,21,33,3,33,21,33,3,35,19,33,53,33,19,33,53,33,
19,51,2,230,1,70,254,133,117,1,240,253,219,187,138,186,254,188,1,121,116,254,19,2,33,186,142,4,0,137,254,209,137,254,28,1,228,137,1,47,137,1,228,0,2,0,1,0,0,7,69,5,191,0,15,0,18,0,156,64,27,5,8,9,17,13,
12,16,14,15,1,18,15,15,86,0,1,20,0,0,1,18,4,14,13,94,16,17,184,2,25,64,45,5,7,8,94,6,5,5,12,3,4,94,2,1,2,10,9,94,11,12,12,15,0,8,10,7,6,3,2,5,20,11,4,9,101,18,12,12,0,6,2,2,11,74,20,15,184,2,23,181,0,
73,19,239,174,24,43,78,16,244,77,237,78,16,246,60,16,60,17,57,47,60,77,253,60,17,18,23,57,0,63,60,60,16,60,253,60,63,60,253,60,18,57,47,60,253,60,16,244,60,253,60,17,51,135,5,46,43,135,125,196,16,60,196,
3,16,60,60,16,60,60,49,48,51,1,33,21,33,17,33,21,33,17,33,21,33,17,33,9,1,33,17,1,3,182,3,142,253,75,2,181,253,75,2,181,252,182,253,233,254,200,1,150,1,185,5,191,151,254,60,145,253,189,144,1,226,254,30,
2,108,2,169,0,0,3,0,114,255,153,6,127,5,254,0,21,0,30,0,39,1,85,64,116,117,9,122,20,150,0,153,11,4,41,31,38,32,53,9,58,20,69,9,74,20,85,9,90,20,101,9,111,24,96,33,11,135,23,136,32,151,8,151,23,152,32,
168,9,200,9,7,25,9,22,20,40,23,38,30,48,30,63,39,111,39,171,39,8,50,8,0,31,32,8,9,9,21,19,23,22,11,10,20,20,21,9,9,86,10,20,20,10,10,20,24,23,31,39,4,25,18,19,0,1,2,5,17,33,32,22,30,4,34,7,8,11,12,4,6,
20,186,1,117,0,21,2,67,180,25,122,17,3,9,186,1,117,0,10,2,66,64,30,34,122,6,9,39,31,23,24,4,38,2,1,0,19,18,5,3,30,22,32,33,4,29,12,11,8,7,4,13,20,184,2,65,183,21,190,38,112,3,74,41,9,187,2,65,0,64,0,10,
1,28,64,9,32,29,112,13,73,40,120,131,24,43,78,16,244,77,253,26,25,253,26,24,237,78,16,246,77,237,25,244,24,237,17,23,51,17,23,51,17,23,51,17,23,51,0,63,237,25,245,24,228,63,237,25,245,24,228,17,23,51,
17,23,51,17,23,51,17,23,51,135,14,46,43,135,14,125,196,135,14,60,60,60,196,7,14,16,60,60,60,60,49,48,24,67,121,64,34,35,37,26,28,14,16,4,5,36,37,27,37,15,38,35,5,38,100,1,26,16,29,100,0,37,4,34,100,0,
28,14,25,100,1,0,43,43,1,43,43,43,43,43,129,129,129,129,0,93,93,1,93,93,1,22,18,21,16,0,33,34,39,7,39,55,38,17,52,18,36,51,32,23,55,23,9,1,38,35,34,4,2,21,20,9,1,22,51,50,36,18,53,52,5,174,100,109,254,
63,254,189,245,192,164,107,165,234,206,1,100,213,1,1,210,144,105,251,119,3,43,169,200,163,254,220,164,4,65,252,219,152,183,171,1,35,163,4,245,102,254,239,158,254,189,254,62,128,194,87,194,227,1,68,212,
1,107,204,148,174,87,251,124,3,186,119,170,254,224,178,255,2,168,252,75,98,166,1,32,176,244,0,3,0,152,1,132,5,28,4,20,0,21,0,34,0,45,0,155,64,14,64,8,0,12,22,3,35,26,106,9,159,14,106,44,186,1,42,0,35,
1,42,64,10,38,106,20,159,32,106,3,12,0,35,184,1,133,64,16,22,22,41,29,130,6,74,47,41,130,17,73,46,110,151,24,43,78,16,244,77,237,78,16,246,77,237,17,57,47,253,57,57,0,47,237,244,253,25,246,246,24,253,
244,237,17,23,51,49,48,67,121,64,48,39,43,27,31,15,19,4,8,27,8,29,87,1,43,15,41,107,0,31,4,29,87,1,39,19,41,107,0,28,7,26,87,0,42,16,44,107,0,30,5,32,87,1,40,18,38,107,1,43,43,43,43,1,43,43,43,43,129,
129,129,129,1,62,1,51,50,22,21,20,6,35,34,38,39,6,35,34,38,53,52,54,51,50,19,22,23,22,51,50,54,53,52,38,35,34,6,7,46,1,35,34,6,21,20,22,51,50,2,175,117,138,78,110,178,168,120,87,139,107,136,153,102,144,
144,102,153,205,83,69,50,60,77,102,104,79,53,101,242,77,97,46,59,76,79,58,101,3,44,146,86,156,165,168,167,98,134,171,155,112,112,155,254,246,128,52,38,113,101,105,113,73,142,97,60,83,71,70,86,0,2,0,56,
0,24,4,44,5,67,0,11,0,15,0,118,64,65,9,10,5,1,8,6,10,5,2,7,3,11,4,2,7,0,11,4,1,8,4,5,11,10,13,12,14,98,22,15,251,8,1,228,11,127,8,228,10,14,13,15,12,2,1,7,8,17,71,71,74,12,5,228,7,127,8,228,15,10,73,16,
89,114,24,43,78,16,244,60,77,244,253,244,60,78,69,101,68,230,17,18,57,57,17,18,57,57,0,47,77,228,253,228,16,246,75,81,88,176,128,26,89,237,57,57,17,18,57,57,15,15,15,15,49,48,1,17,51,17,33,21,33,17,35,
17,33,53,1,21,33,53,1,237,137,1,182,254,74,137,254,75,3,244,252,12,3,145,1,178,254,78,137,254,78,1,178,137,253,16,137,137,0,2,0,46,0,94,4,55,5,125,0,6,0,10,0,128,64,27,5,4,3,3,85,6,5,20,6,6,5,0,1,2,2,
85,6,0,20,6,6,0,10,9,8,98,7,184,1,126,64,38,1,5,218,64,4,201,6,32,0,218,64,1,201,32,6,6,3,2,5,0,4,1,9,8,10,7,7,4,1,74,12,10,2,73,11,89,153,24,43,78,16,244,60,16,246,60,60,17,18,57,57,17,18,57,57,17,51,
51,0,25,47,26,77,253,26,24,237,26,25,16,253,26,24,237,16,246,237,57,57,135,46,43,135,125,196,135,46,24,43,135,125,196,49,48,1,21,1,53,1,21,9,1,21,33,53,4,55,251,247,4,9,252,185,3,71,251,247,1,225,146,
1,213,130,1,215,147,254,122,253,131,137,137,0,2,0,46,0,94,4,55,5,125,0,6,0,10,0,126,64,27,4,1,2,2,85,3,4,20,3,3,4,5,1,0,0,85,6,5,20,6,6,5,8,7,9,98,10,184,1,126,64,37,0,218,64,6,201,1,32,2,218,64,3,201,
32,1,1,4,5,2,0,3,6,9,8,10,7,7,5,74,12,3,10,6,73,11,89,153,24,43,78,16,244,60,60,16,246,60,17,18,57,57,17,18,57,57,17,51,51,0,25,47,26,77,253,26,24,237,26,25,16,253,26,24,237,246,237,57,57,135,46,43,135,
125,196,135,46,24,43,135,125,196,49,48,19,9,1,53,1,21,1,5,21,33,53,46,3,71,252,185,4,9,251,247,4,9,251,247,1,225,1,131,1,134,147,254,41,130,254,43,104,137,137,0,0,1,0,62,0,0,4,48,5,191,0,22,0,233,64,79,
2,2,1,19,18,19,20,5,16,17,15,14,7,16,11,12,13,8,16,11,9,13,8,5,10,6,14,7,5,10,22,0,22,21,0,86,1,2,20,1,1,2,22,21,22,0,21,86,20,19,20,20,20,19,15,6,7,8,9,12,6,13,14,19,2,3,4,5,16,6,17,18,0,21,1,20,13,247,
14,184,1,134,64,39,17,247,18,18,20,11,8,1,20,2,2,19,22,17,14,13,8,7,4,6,3,18,12,15,16,5,6,9,22,7,10,11,24,71,71,74,3,190,0,184,2,23,64,9,1,200,10,101,11,200,18,190,21,184,2,23,181,20,73,23,136,184,24,
43,78,16,244,77,237,228,244,253,244,237,228,78,69,101,68,230,17,18,23,57,17,18,23,57,17,51,51,0,63,60,63,18,57,47,77,253,254,237,17,18,57,57,17,18,23,57,17,18,23,57,135,5,46,43,8,125,16,196,135,5,46,24,
43,8,125,16,196,15,15,15,15,2,4,16,60,60,8,16,60,8,60,49,48,1,51,1,33,21,33,21,33,21,33,17,35,17,33,53,33,53,33,53,33,1,51,1,3,138,166,254,95,1,100,254,138,1,118,254,138,144,254,142,1,114,254,142,1,97,
254,98,167,1,81,5,191,253,33,117,155,117,254,165,1,91,117,155,117,2,223,253,166,0,0,1,0,147,254,114,4,9,4,64,0,23,0,162,64,30,27,64,7,19,30,64,7,19,11,10,16,15,3,4,22,23,12,2,13,1,23,14,0,15,13,1,6,15,
10,7,184,1,43,64,20,19,11,0,12,15,92,13,14,74,25,2,23,92,1,0,73,24,123,118,24,43,78,16,244,60,77,253,60,78,16,246,60,77,253,60,0,47,63,237,63,63,60,17,18,57,57,17,18,57,57,3,14,16,60,60,60,16,60,60,60,
49,48,0,73,84,121,64,18,20,21,4,6,5,38,4,21,7,104,4,6,20,3,104,0,21,22,1,16,60,43,0,43,43,129,129,0,73,84,121,64,16,8,18,9,37,10,17,7,104,4,8,18,11,104,1,17,16,1,16,60,43,0,43,43,129,19,17,51,17,20,30,
1,51,50,62,1,53,17,51,17,35,53,14,1,35,34,38,39,17,147,141,67,150,87,87,139,75,140,140,59,149,94,94,151,58,254,114,5,206,253,168,136,134,91,87,153,134,2,75,251,192,118,74,69,69,71,253,255,0,0,2,0,56,255,
231,3,205,5,211,0,24,0,35,0,147,64,17,65,8,1,0,25,97,19,19,23,32,97,12,11,15,0,1,0,184,2,88,64,13,23,97,4,1,25,0,1,19,130,8,74,37,1,186,1,252,0,29,1,142,181,15,73,36,89,153,24,43,78,16,244,77,237,228,
78,16,246,77,237,17,51,50,0,63,253,228,93,63,253,17,57,47,237,17,51,49,48,67,121,64,46,30,35,20,22,5,14,10,38,34,37,6,37,21,38,33,11,25,165,1,35,25,31,13,29,87,0,22,5,19,87,1,35,9,32,165,0,30,14,32,87,
0,20,7,23,87,1,43,43,43,1,43,43,16,60,43,43,43,43,43,129,129,129,1,39,62,1,51,50,30,1,21,16,2,4,35,34,38,53,52,55,54,37,46,2,35,34,1,14,2,21,20,22,51,50,54,18,1,170,135,67,193,100,88,148,86,175,254,224,
146,138,170,164,199,1,183,4,51,93,57,143,1,88,248,222,148,102,68,87,198,139,4,114,60,149,144,112,251,202,254,217,254,73,217,184,163,236,162,196,8,191,171,77,253,201,15,108,242,128,83,108,146,1,46,0,1,
0,122,254,86,5,106,6,0,0,11,0,138,64,38,55,9,56,11,2,3,4,4,221,10,11,20,10,4,5,10,11,4,5,4,3,5,221,9,10,20,9,9,10,9,5,4,11,3,10,10,8,3,184,2,106,179,0,1,6,5,184,2,106,182,7,8,15,5,3,11,10,184,2,90,64,
17,4,4,6,9,7,167,2,74,13,9,209,11,73,12,216,175,24,43,78,16,244,77,228,78,16,246,77,228,17,18,57,47,237,18,57,57,0,63,60,253,60,63,237,25,18,57,47,18,57,57,18,57,135,5,46,24,43,8,125,16,196,135,8,46,24,
43,5,125,16,196,49,48,0,93,19,33,21,33,9,1,33,21,33,53,9,1,139,4,213,252,36,2,95,253,122,4,13,251,16,2,108,253,165,6,0,164,252,228,252,183,161,187,3,40,3,23,0,1,0,162,254,86,5,244,6,0,0,7,0,80,64,11,4,
1,5,0,3,6,2,2,7,15,5,184,2,103,64,11,0,0,1,4,2,3,5,0,6,7,3,184,2,104,179,2,74,9,6,184,2,104,181,7,73,8,110,151,24,43,78,16,244,77,237,78,16,246,77,237,17,18,57,57,17,18,57,57,0,63,237,63,60,18,57,57,17,
18,57,57,49,48,19,33,17,35,17,33,17,35,162,5,82,191,252,46,193,6,0,248,86,6,252,249,4,0,0,1,0,0,0,0,4,100,4,39,0,11,0,114,64,21,3,6,7,10,11,5,8,4,9,1,2,3,6,7,10,6,0,4,9,10,11,184,2,106,64,11,0,6,3,6,4,
5,7,10,8,9,5,186,2,104,0,4,2,82,64,9,2,74,13,9,15,13,1,8,8,186,2,104,0,9,2,82,181,11,73,12,157,207,24,43,78,16,244,77,244,237,94,93,94,78,16,246,77,244,237,17,18,57,57,17,18,57,57,0,63,237,63,60,17,23,
57,17,18,57,57,16,60,60,60,60,49,48,17,33,21,35,17,35,17,33,17,35,17,35,4,100,162,189,254,86,188,159,4,39,158,252,119,3,137,252,119,3,137,0,0,1,0,0,255,36,2,48,7,71,0,46,0,155,64,39,50,8,13,159,17,148,
7,30,148,64,40,159,36,10,48,71,71,74,10,162,14,20,155,22,24,197,64,43,155,22,0,162,14,33,73,47,115,134,24,43,78,16,244,75,81,88,176,128,26,89,77,252,75,82,88,176,0,26,27,176,64,26,89,236,26,253,75,82,
88,176,0,26,89,236,75,82,88,176,64,26,27,176,128,26,89,252,78,69,101,68,230,0,63,77,244,26,237,47,253,228,49,48,67,121,64,36,41,42,27,29,18,19,3,6,4,3,5,3,2,6,28,38,18,6,20,107,0,41,29,43,107,1,19,3,17,
107,1,42,27,40,107,0,43,43,1,43,43,43,42,129,129,129,129,19,52,19,54,55,62,1,51,50,22,21,20,6,35,34,39,38,35,34,6,21,20,23,18,21,20,3,2,7,6,35,34,38,53,52,54,51,50,23,22,51,50,54,53,52,39,2,201,16,10,
44,25,93,46,49,76,53,39,35,41,23,17,18,22,9,37,15,9,75,55,86,52,66,51,39,40,30,28,20,17,22,9,37,3,180,209,1,34,184,108,60,64,66,41,46,58,36,20,29,35,42,103,254,102,255,67,254,12,254,207,105,77,68,53,44,
55,33,31,29,32,42,78,1,60,0,0,2,0,57,3,26,2,152,5,228,0,16,0,28,0,79,179,15,3,2,23,184,2,111,182,6,21,1,20,16,22,17,184,2,111,64,26,12,23,16,26,129,2,181,1,74,30,15,30,1,9,15,30,1,8,20,181,9,73,29,89,
152,24,43,78,16,244,77,237,94,93,94,93,78,16,246,77,253,228,60,0,63,237,63,63,63,237,3,14,16,60,60,49,48,0,1,17,35,53,14,1,35,34,38,53,52,54,51,50,22,23,53,7,34,6,21,20,22,51,50,54,53,52,38,2,152,114,
42,103,62,114,172,174,114,61,103,41,185,77,115,116,75,77,115,114,5,211,253,87,94,55,55,203,155,153,203,58,58,99,92,140,109,110,142,136,114,112,139,0,2,0,55,3,26,2,188,5,228,0,11,0,23,0,109,178,55,8,18,
184,2,111,178,6,21,12,184,2,111,64,18,0,23,21,181,3,74,25,15,25,1,15,181,9,73,24,89,114,24,43,78,16,244,77,237,93,78,16,246,77,237,0,63,237,63,237,49,48,67,121,64,42,1,23,19,5,21,87,1,17,7,15,87,0,23,
1,21,87,1,13,11,15,87,0,20,4,18,87,0,16,8,18,87,0,22,2,12,87,1,14,10,12,87,1,43,43,43,43,1,43,43,43,43,129,1,50,22,21,20,6,35,34,38,53,52,54,23,34,6,21,20,22,51,50,54,53,52,38,1,121,133,190,189,134,133,
189,190,132,81,124,121,84,85,121,124,5,228,206,153,152,203,203,152,154,205,110,144,107,107,139,139,107,107,144,0,0,1,0,127,0,0,5,195,5,223,0,38,0,188,64,36,8,34,138,1,133,15,154,1,150,15,170,1,166,15,
185,1,182,15,200,22,200,23,11,43,8,20,16,17,35,0,38,19,36,18,37,29,184,2,106,180,8,3,17,240,38,184,2,103,64,16,18,37,8,20,16,17,3,18,19,37,0,35,3,36,37,25,184,2,105,178,12,209,19,184,2,87,179,18,74,40,
32,184,2,105,178,4,209,36,184,2,87,181,37,73,39,120,175,24,43,78,16,244,77,237,244,237,78,16,246,77,237,244,237,17,18,23,57,17,18,23,57,0,63,60,253,228,63,237,17,18,57,57,17,51,51,17,51,51,49,48,67,121,
64,30,26,31,5,11,10,37,27,38,6,38,28,9,25,100,1,30,7,32,100,0,26,11,29,100,1,31,5,29,100,1,43,43,1,43,43,43,43,43,129,129,1,93,37,46,2,53,52,18,36,51,32,23,22,17,20,14,1,7,37,21,33,53,54,55,54,18,53,52,
2,38,35,34,2,17,20,18,23,21,33,53,1,240,126,141,79,169,1,38,195,1,67,179,145,79,144,121,1,108,253,193,90,54,92,111,121,190,132,195,247,184,158,253,191,160,79,177,242,144,210,1,65,170,236,190,254,236,138,
237,186,80,6,166,177,45,50,88,1,7,154,171,1,13,123,254,218,254,246,220,254,203,71,180,168,0,0,3,0,120,255,228,8,201,4,92,0,42,0,51,0,65,1,180,64,116,123,6,180,17,2,45,64,16,21,57,14,64,17,21,57,10,11,
12,20,12,22,3,3,2,3,3,5,49,3,3,38,3,40,5,63,3,12,28,12,29,10,60,3,33,64,12,19,34,64,4,47,30,64,59,30,33,64,37,52,41,8,1,23,24,41,62,26,25,16,15,7,43,8,144,255,51,1,9,15,51,1,8,51,51,19,4,42,6,25,10,47,
88,4,4,52,88,37,7,64,15,80,15,2,0,15,16,15,48,15,3,9,0,15,1,8,15,184,2,41,64,48,12,88,19,19,59,88,30,11,51,8,15,16,26,62,41,42,0,1,23,7,25,8,125,24,92,25,25,33,16,178,43,105,7,74,67,9,0,67,1,8,56,105,
33,73,66,139,133,24,43,78,16,244,77,237,94,93,94,78,16,246,77,237,228,18,57,47,253,228,18,23,57,17,51,17,51,0,63,237,60,16,253,228,94,93,94,93,93,63,237,60,16,237,63,63,17,18,57,47,94,93,94,113,237,57,
57,17,51,3,14,16,60,125,196,60,16,60,60,49,48,24,67,121,64,28,53,58,31,36,54,37,35,38,58,31,56,90,0,53,36,56,90,0,57,32,59,90,0,55,34,52,90,1,0,43,43,1,43,43,43,43,129,129,0,73,84,121,64,20,63,65,38,40,
64,38,39,37,63,40,52,104,5,65,38,62,104,1,40,41,1,16,60,43,0,43,43,43,129,129,0,73,84,121,64,18,60,61,27,29,28,38,61,27,59,104,4,60,29,62,104,1,27,26,1,16,60,43,0,43,43,129,129,0,73,84,121,64,20,48,50,
2,3,49,37,50,2,47,104,5,48,3,51,104,0,50,51,2,1,1,16,60,16,60,43,0,43,43,129,129,0,73,84,121,64,20,20,22,9,11,10,38,21,37,9,22,12,104,4,11,20,8,104,0,22,23,1,16,60,43,0,43,43,43,129,129,0,93,93,93,93,
1,43,43,93,1,21,62,1,51,50,0,3,33,30,2,51,50,54,55,23,6,4,35,34,39,38,39,21,35,53,6,7,6,35,34,0,53,52,18,36,51,50,23,22,23,53,1,46,2,35,34,14,1,7,1,34,14,1,21,20,22,51,50,54,53,52,46,1,4,221,106,198,133,
246,1,65,1,252,45,4,116,191,116,125,198,74,120,74,254,234,175,154,121,87,79,128,89,84,120,143,231,254,182,148,1,6,147,141,123,87,89,3,208,28,106,176,93,95,179,114,25,253,178,114,199,111,248,181,181,247,
107,205,4,64,197,127,98,254,183,254,255,116,206,108,123,134,60,155,170,69,49,104,194,201,111,48,70,1,79,241,156,1,3,153,69,50,107,198,254,75,114,134,83,85,141,105,1,74,114,201,122,188,251,249,188,131,
194,114,0,3,0,102,255,173,4,211,4,109,0,19,0,29,0,38,1,73,64,120,47,6,32,17,182,9,185,19,4,31,6,16,17,166,9,169,19,198,9,201,19,6,15,6,0,17,139,11,167,20,168,30,183,20,184,30,199,20,200,30,9,32,1,47,11,
105,30,102,31,4,16,1,31,11,121,21,3,0,1,15,11,63,11,121,30,118,31,5,47,8,0,30,31,7,8,8,19,17,21,20,10,9,18,18,19,8,8,91,9,18,20,9,9,18,22,21,30,38,4,23,16,17,0,1,4,15,32,31,20,29,28,5,33,6,7,10,11,4,5,
19,186,2,73,0,18,2,74,180,23,88,15,7,9,186,2,73,0,8,2,73,64,30,33,88,5,11,38,30,21,22,4,37,1,0,17,16,4,2,28,29,20,31,32,5,27,11,10,7,6,4,12,18,184,2,72,183,19,125,37,105,2,74,40,8,184,2,72,64,10,9,178,
27,105,12,73,39,96,133,24,43,78,16,244,77,237,244,237,78,16,246,77,237,244,237,17,23,51,17,23,51,17,23,51,17,23,51,0,63,237,244,228,63,237,244,228,17,23,51,17,23,51,17,23,51,17,23,51,135,14,46,43,135,
14,125,196,7,14,60,60,60,60,7,14,16,60,60,60,60,49,48,24,67,121,64,32,34,36,24,26,13,14,3,4,35,37,25,37,34,4,37,90,1,24,14,27,90,0,36,3,33,90,0,26,13,23,90,1,0,43,43,1,43,43,43,43,129,129,129,129,1,93,
93,93,0,93,93,93,1,22,21,20,0,35,34,39,7,39,55,38,53,52,0,51,50,23,55,23,9,1,38,35,34,14,1,21,20,22,9,1,22,51,50,62,1,53,52,4,78,133,254,195,249,164,135,116,89,114,177,1,60,250,201,150,116,92,252,164,
2,48,118,140,111,197,116,65,2,185,253,220,103,106,116,195,114,3,145,161,211,228,254,171,82,137,74,134,171,245,228,1,91,120,137,74,252,194,2,146,92,117,207,117,86,165,2,3,253,124,53,111,204,117,144,0,2,
0,183,254,86,4,17,4,86,0,11,0,54,0,249,64,54,43,21,43,46,59,21,59,46,57,53,68,42,84,42,107,21,116,42,132,44,154,21,155,22,156,23,155,25,174,23,175,25,163,45,164,46,191,21,188,22,176,43,187,46,207,21,207,
22,192,43,201,46,26,31,184,255,192,64,29,17,21,57,53,64,13,21,57,40,8,44,23,51,63,33,1,15,33,31,33,47,33,3,9,15,33,1,8,33,184,1,146,178,30,97,37,184,1,126,64,20,207,6,1,6,124,0,7,0,12,16,12,32,12,3,9,
0,12,1,8,12,184,1,156,64,33,51,97,16,15,207,9,1,9,164,3,3,3,27,99,40,246,12,99,13,74,56,33,99,34,155,48,99,19,73,55,103,151,24,43,78,16,244,77,237,244,237,78,16,246,77,237,244,253,17,57,47,237,93,0,63,
253,228,94,93,94,93,63,253,93,254,253,228,94,93,94,93,93,18,57,57,49,48,67,121,64,28,49,50,38,39,28,29,17,18,50,17,48,87,0,29,38,27,87,1,49,18,51,87,0,28,39,30,87,1,43,43,1,43,43,129,129,129,129,1,43,
43,93,1,50,22,21,20,6,35,34,38,53,52,54,1,51,14,1,35,34,38,53,52,62,1,55,54,55,54,53,52,38,35,34,6,7,35,62,1,51,50,22,21,20,14,1,7,6,7,6,21,20,22,51,50,55,54,2,92,51,72,72,51,51,72,72,1,87,145,2,237,199,
196,224,62,123,155,195,42,41,113,90,99,106,12,146,7,193,163,162,192,53,97,134,216,60,61,147,123,151,83,58,4,86,72,52,52,72,72,52,51,73,251,181,202,235,198,147,70,119,95,61,78,39,39,54,58,92,101,111,167,
186,168,124,60,107,72,55,88,44,44,81,87,121,99,69,0,0,2,0,179,254,86,1,169,4,86,0,11,0,15,0,94,180,15,14,12,15,13,184,1,42,64,26,6,124,0,7,15,12,14,13,17,71,71,74,5,3,155,14,127,5,13,155,9,73,16,103,150,
24,43,78,16,244,77,244,67,88,183,0,13,32,13,2,240,13,1,1,93,113,89,253,244,67,88,183,0,3,32,3,2,240,3,1,1,93,113,89,78,69,101,68,230,17,18,57,57,0,63,77,253,238,63,57,57,49,48,1,50,22,21,20,6,35,34,38,
53,52,54,3,17,51,17,1,46,51,72,72,51,51,72,72,20,145,4,86,72,52,52,72,72,52,51,73,250,0,4,116,251,140,0,0,1,0,115,1,191,4,103,4,0,0,5,0,50,181,1,2,3,0,5,2,184,1,4,64,17,4,127,5,2,129,3,127,1,0,74,7,4,
73,6,95,113,24,43,78,16,228,16,246,60,77,253,228,0,47,253,228,18,57,57,18,57,49,48,1,17,35,3,33,53,4,103,137,1,252,150,4,0,253,191,1,184,137,0,0,1,0,81,255,178,4,97,7,77,0,7,0,124,64,43,0,7,7,179,2,1,
20,2,7,6,2,1,3,4,4,179,5,6,20,5,5,6,3,6,7,7,85,2,3,20,2,7,0,2,3,7,5,4,3,2,5,0,1,184,1,191,64,22,6,6,3,4,8,7,2,0,3,1,6,6,8,1,74,9,5,73,8,119,134,24,43,78,16,228,16,230,25,18,57,47,18,23,57,18,57,57,0,24,
63,77,244,50,23,51,135,8,46,43,135,14,125,196,135,14,46,24,43,14,125,16,196,135,8,46,24,43,5,125,16,196,49,48,1,51,9,1,7,39,37,1,4,23,74,254,200,254,16,198,34,1,45,1,149,7,77,248,101,3,253,91,64,151,252,
201,0,1,0,32,254,86,3,174,6,0,0,33,0,166,64,63,21,20,19,1,21,16,17,18,2,21,16,3,18,2,33,4,0,19,1,33,4,33,4,4,91,16,21,20,16,16,21,11,13,10,8,28,30,27,25,2,1,18,144,19,19,25,13,88,8,15,30,88,25,1,2,19,
1,18,35,71,71,74,27,65,9,2,83,0,1,1,143,0,33,2,82,0,4,1,41,0,21,2,82,183,0,18,16,18,2,18,178,16,184,2,51,178,10,73,34,186,2,79,2,80,0,24,43,78,16,244,77,252,228,93,228,253,244,228,252,78,69,101,68,230,
17,18,57,57,0,63,77,237,63,237,18,57,47,237,57,57,17,51,17,51,17,51,17,51,135,14,46,43,14,125,16,196,15,15,15,15,0,46,49,48,1,51,7,35,3,14,2,35,34,39,55,22,51,50,54,55,19,35,55,51,19,54,55,54,51,50,23,
7,38,35,34,6,7,2,109,231,17,233,107,29,90,131,71,68,74,18,55,56,71,103,32,101,141,17,141,49,28,37,66,100,83,94,18,77,62,49,53,20,3,114,122,253,58,196,190,90,49,124,45,146,223,2,177,122,1,63,184,55,96,
65,133,73,91,144,0,2,0,54,1,137,4,46,4,52,0,23,0,47,0,136,183,8,6,8,30,2,24,148,25,184,2,84,178,28,148,45,184,1,44,179,40,36,148,37,184,2,84,179,33,148,64,40,184,1,114,180,4,14,0,148,1,184,2,84,178,4,
148,21,184,1,44,179,16,12,148,13,184,2,84,64,25,9,148,16,12,1,13,0,24,37,25,36,25,0,74,49,36,0,13,1,13,73,48,89,114,24,43,78,16,244,93,60,16,246,60,17,18,57,57,17,18,57,57,0,47,77,237,244,237,16,244,253,
244,237,75,82,88,176,0,26,89,16,254,26,237,244,237,16,244,253,244,237,49,48,0,93,1,21,14,1,35,34,39,46,1,35,34,6,7,53,62,1,51,50,23,30,1,51,50,54,19,21,14,1,35,34,39,46,1,35,34,6,7,53,62,1,51,50,23,30,
1,51,50,54,4,46,112,97,43,95,170,132,73,32,44,106,112,110,98,46,97,171,118,87,35,42,86,126,112,97,43,95,170,132,73,32,44,106,112,110,98,46,97,171,118,87,35,42,86,3,255,162,63,33,77,60,23,38,67,160,63,
33,81,56,27,33,254,218,162,63,33,77,60,23,39,66,160,62,34,81,56,27,33,0,0,2,0,26,0,0,4,202,5,107,0,2,0,5,0,116,178,3,4,4,184,1,47,64,25,2,0,20,2,4,5,2,0,4,5,4,3,5,179,1,2,20,1,1,2,0,3,1,5,4,187,1,160,
0,2,0,5,1,29,183,1,10,4,5,2,2,5,3,184,2,89,179,0,74,7,5,184,1,127,181,1,73,6,115,238,24,43,78,16,244,77,237,78,16,246,77,237,25,17,57,47,18,57,0,24,63,237,47,237,17,18,57,57,135,5,46,43,8,125,16,196,135,
8,46,24,43,5,125,16,196,49,48,41,1,9,3,4,202,251,80,2,116,1,80,254,113,254,72,5,107,250,231,3,199,252,57,0,2,0,21,0,0,3,81,4,64,0,5,0,11,0,192,64,95,5,0,1,1,85,4,5,20,4,1,2,4,5,1,1,0,4,3,3,85,2,1,20,2,
2,1,11,6,7,7,85,10,11,20,10,7,8,10,11,7,7,6,10,9,9,85,8,7,20,8,8,7,1,7,0,10,10,4,201,2,32,11,6,6,5,5,0,6,9,8,8,3,3,2,10,5,3,2,1,4,0,4,11,9,8,7,4,10,13,71,71,74,6,226,10,184,1,69,64,9,0,226,128,4,73,12,
115,238,24,43,78,16,244,26,77,237,244,253,78,69,101,68,230,18,23,57,17,18,23,57,0,63,60,16,60,16,60,63,60,16,60,16,60,26,25,77,16,253,60,17,18,57,57,135,5,46,24,43,135,8,125,196,135,8,46,24,43,135,5,125,
196,135,46,24,43,135,8,125,196,135,8,46,24,43,135,5,125,196,49,48,1,3,19,35,3,19,33,3,19,35,3,19,1,135,223,223,148,222,222,2,94,224,224,148,222,222,4,64,253,222,253,226,2,30,2,34,253,222,253,226,2,30,
2,34,0,2,0,21,0,0,3,81,4,64,0,5,0,11,0,194,64,96,5,0,1,1,85,4,5,20,4,1,2,4,5,1,1,0,4,3,3,85,2,1,20,2,2,1,11,6,7,7,85,10,11,20,10,7,8,10,11,7,7,6,10,9,9,85,8,7,20,8,8,7,1,7,0,10,10,4,201,2,32,11,6,6,5,
5,0,10,9,8,8,3,3,2,6,5,3,2,1,4,0,4,11,9,8,7,4,6,10,13,71,71,74,0,226,4,184,1,69,64,9,10,226,128,6,73,12,115,238,24,43,78,16,244,26,77,253,244,237,78,69,101,68,230,17,18,23,57,17,18,23,57,0,63,60,16,60,
16,60,63,60,16,60,16,60,26,25,77,16,253,60,17,18,57,57,135,5,46,24,43,135,8,125,196,135,8,46,24,43,135,5,125,196,135,46,24,43,135,8,125,196,135,8,46,24,43,135,5,125,196,49,48,33,19,3,51,19,3,33,19,3,51,
19,3,1,223,223,223,147,223,223,253,163,223,223,148,222,222,2,33,2,31,253,225,253,223,2,33,2,31,253,225,253,223,0,3,0,218,255,228,7,38,0,220,0,11,0,23,0,35,0,70,64,19,24,124,30,30,0,124,6,6,12,124,18,11,
37,71,71,74,27,164,33,184,1,67,178,3,164,9,184,1,67,181,15,164,21,73,36,163,185,1,19,0,24,43,78,16,244,77,253,246,253,246,253,78,69,101,68,230,0,63,77,237,60,16,237,60,16,237,49,48,37,50,22,21,20,6,35,
34,38,53,52,54,33,50,22,21,20,6,35,34,38,53,52,54,33,50,22,21,20,6,35,34,38,53,52,54,4,0,51,72,72,51,51,72,72,253,136,51,72,72,51,51,72,72,5,137,50,73,73,50,51,72,72,220,72,52,51,73,73,51,52,72,72,52,
51,73,73,51,52,72,72,52,51,73,73,51,52,72,255,255,0,49,0,0,5,186,7,103,2,38,0,36,0,0,1,7,0,67,1,115,1,41,0,18,64,10,2,0,13,13,8,8,51,2,13,32,0,63,53,1,43,53,255,255,0,49,0,0,5,186,7,23,2,38,0,36,0,0,1,
7,0,217,1,52,1,41,0,18,64,10,2,0,25,12,8,8,51,2,15,32,0,63,53,1,43,53,255,255,0,115,255,219,6,128,7,23,2,38,0,50,0,0,1,7,0,217,1,184,1,41,0,18,64,10,2,0,42,29,9,3,51,2,32,32,0,63,53,1,43,53,0,2,0,114,
255,219,9,56,5,228,0,28,0,41,1,13,64,79,36,64,35,16,39,64,24,29,41,8,4,7,8,28,38,12,11,10,9,11,8,6,5,7,4,2,1,3,0,7,94,4,4,11,3,94,0,2,8,94,11,8,35,122,16,9,29,122,24,3,38,12,28,12,0,11,9,2,10,1,8,101,
11,11,32,5,1,1,10,74,43,32,112,20,73,42,120,175,24,43,78,16,244,77,237,78,16,254,60,16,60,17,57,47,77,237,17,18,57,57,17,18,57,57,17,51,0,63,237,63,237,63,237,63,237,18,57,47,237,17,18,57,57,17,18,57,
57,17,18,57,57,3,14,16,60,125,196,60,16,60,60,49,48,24,67,121,64,28,30,34,17,23,18,37,22,38,34,17,32,100,0,30,23,32,100,0,33,19,35,100,0,31,21,29,100,1,0,43,43,1,43,43,43,43,129,129,0,73,84,121,64,11,
39,41,25,27,40,38,26,37,39,27,29,184,1,80,179,5,41,25,38,184,1,80,178,1,27,28,1,16,60,43,0,43,43,43,129,129,0,73,84,121,64,9,36,37,13,15,14,38,37,13,35,184,1,80,179,4,36,15,38,184,1,80,178,1,13,12,1,16,
60,43,0,43,43,129,129,1,33,21,33,17,33,21,33,17,33,21,33,17,14,2,35,32,3,38,17,52,18,36,51,50,23,22,23,37,34,0,21,16,0,33,50,0,17,52,2,36,5,242,3,70,253,79,2,177,253,79,2,177,252,186,99,178,220,131,254,
143,229,182,205,1,114,207,198,180,143,105,253,137,247,254,141,1,110,1,8,255,1,106,166,254,212,5,191,145,254,55,145,253,189,145,1,29,126,128,68,1,17,217,1,19,208,1,108,208,103,82,137,180,254,138,252,254,
247,254,143,1,113,1,6,171,1,30,172,0,0,3,0,112,255,228,8,167,4,92,0,36,0,51,0,59,1,138,64,115,36,3,52,3,75,12,68,31,91,12,84,31,107,12,100,31,123,12,139,12,128,35,144,35,164,6,187,9,196,6,203,9,16,175,
13,175,31,191,13,191,31,207,13,207,31,6,32,3,48,3,123,53,159,13,159,31,5,15,13,15,14,0,16,0,27,0,28,15,30,15,31,7,34,64,4,11,37,64,33,55,81,8,0,52,1,144,255,59,1,9,15,59,1,8,59,59,55,64,7,80,7,2,0,7,16,
7,48,7,3,9,0,7,1,8,7,184,2,41,64,43,4,88,11,11,45,88,18,11,55,88,33,33,37,88,25,7,16,1,16,5,16,29,16,49,16,59,5,59,7,8,15,29,1,105,49,49,52,41,8,178,52,105,0,184,1,38,64,9,61,41,105,21,73,60,96,133,24,
43,78,16,244,77,237,16,254,237,228,17,18,57,47,237,57,57,17,51,50,93,0,63,237,60,16,237,63,237,60,16,253,228,94,93,94,93,93,18,57,47,94,93,94,113,237,57,57,49,48,67,121,64,58,38,51,16,28,47,37,43,38,27,
37,39,37,23,38,46,17,49,90,1,16,15,44,19,41,90,0,51,26,49,90,1,28,29,38,24,41,90,0,48,16,45,90,2,42,20,45,90,0,50,28,37,90,3,40,22,37,90,1,43,43,43,43,1,43,16,60,43,43,16,60,43,43,43,43,43,43,129,129,
0,73,84,121,64,22,56,58,30,32,57,37,31,38,58,30,55,104,5,56,32,59,104,0,58,59,30,29,1,16,60,16,60,43,0,43,43,43,129,129,0,73,84,121,64,20,12,14,2,3,13,37,2,14,4,104,4,3,12,1,104,0,2,1,14,15,1,16,60,16,
60,43,0,43,43,129,129,1,93,93,93,0,93,1,33,30,1,51,50,54,55,23,14,1,35,34,46,1,39,14,1,35,34,0,53,16,55,54,51,50,23,22,23,54,55,54,51,50,0,21,1,34,14,1,21,20,30,1,51,50,62,1,53,52,2,1,46,1,35,34,7,6,7,
8,166,252,48,14,251,160,130,209,59,119,94,255,177,98,181,128,81,91,245,153,235,254,182,206,159,201,163,136,99,90,84,94,136,177,233,1,69,249,249,111,196,114,113,206,111,110,200,108,248,4,186,41,216,146,
157,118,91,41,2,19,223,207,134,126,61,173,155,61,100,114,137,138,1,80,242,1,14,167,129,88,63,137,133,63,92,254,189,226,1,158,115,208,116,118,204,119,117,197,122,188,1,0,254,182,158,171,100,77,152,0,1,
255,244,1,252,4,12,2,125,0,3,0,36,64,17,2,1,0,98,3,1,0,3,2,74,5,3,73,4,206,134,24,43,78,16,228,16,230,17,57,57,0,47,77,253,57,57,49,48,3,33,21,33,12,4,24,251,232,2,125,129,0,1,255,244,1,252,8,12,2,125,
0,3,0,36,64,17,2,1,0,98,3,1,0,3,2,74,5,3,73,4,206,134,24,43,78,16,228,16,230,17,57,57,0,47,77,253,57,57,49,48,3,33,21,33,12,8,24,247,232,2,125,129,0,2,0,204,3,191,3,62,5,228,0,10,0,21,0,102,64,44,12,11,
1,0,18,15,17,16,7,4,6,5,17,156,16,255,11,11,0,6,156,64,5,255,0,0,8,0,1,4,5,5,6,7,19,11,12,15,16,5,17,252,128,18,184,2,58,64,10,64,6,252,128,7,73,22,163,150,24,43,78,16,252,26,77,253,26,254,26,237,23,57,
17,18,23,57,0,63,244,26,237,16,60,16,244,237,17,18,57,57,17,18,57,57,17,51,17,51,49,48,1,23,14,1,7,51,17,35,53,52,54,37,23,14,1,7,51,17,35,53,52,54,1,33,78,38,26,7,89,181,35,1,239,78,38,26,7,89,181,34,
5,228,44,76,86,68,254,237,172,129,147,101,44,76,86,68,254,237,172,129,147,0,0,2,0,181,3,191,3,39,5,228,0,10,0,21,0,104,64,45,12,11,1,0,18,15,17,16,7,4,6,0,255,5,156,6,6,17,11,255,16,156,64,17,0,8,0,1,
4,5,5,6,7,19,11,12,15,16,5,17,18,7,252,128,6,184,2,58,64,10,64,18,252,128,17,73,22,103,150,24,43,78,16,252,26,77,253,26,254,26,237,17,18,23,57,17,18,23,57,0,63,26,253,228,16,60,16,253,228,18,57,57,17,
18,57,57,17,51,17,51,49,48,1,39,62,1,55,35,17,51,21,20,6,5,39,62,1,55,35,17,51,21,20,6,2,209,77,38,26,6,88,181,35,254,16,77,38,26,6,88,181,35,3,191,44,76,86,68,1,19,172,129,147,101,44,76,86,68,1,19,172,
129,147,0,0,1,1,30,3,191,1,211,5,228,0,10,0,48,64,26,1,0,7,4,6,156,64,5,255,0,0,8,0,1,4,5,5,6,252,128,7,73,11,142,173,24,43,78,16,252,26,77,237,23,57,0,63,244,26,237,57,57,17,51,49,48,1,23,14,1,7,51,17,
35,53,52,54,1,115,78,38,26,7,89,181,35,5,228,44,76,86,68,254,237,172,129,147,0,0,1,0,252,3,191,1,177,5,228,0,10,0,50,64,27,1,0,7,4,6,0,255,5,156,64,6,0,8,0,1,4,5,5,7,252,128,6,73,11,149,236,24,43,78,16,
252,26,77,253,23,57,0,63,26,253,228,18,57,57,17,51,49,48,1,39,62,1,55,35,17,51,21,20,6,1,91,77,38,26,6,88,181,35,3,191,44,76,86,68,1,19,172,129,147,0,0,3,0,56,1,5,4,44,4,183,0,3,0,7,0,11,0,109,64,13,10,
9,11,8,2,1,3,0,6,5,7,4,3,186,2,71,0,0,1,168,179,4,127,7,8,186,2,71,0,11,1,168,64,15,7,8,3,0,1,2,9,6,10,11,13,71,71,74,6,188,1,168,0,10,2,4,0,11,1,168,181,7,73,12,89,114,24,43,78,16,244,77,244,253,244,
78,69,101,68,230,17,18,23,57,0,47,77,244,237,16,253,244,237,17,18,57,57,17,18,57,57,17,18,57,57,49,48,1,51,21,35,5,33,21,33,5,51,21,35,1,205,201,201,254,107,3,244,252,12,1,149,201,201,4,183,202,201,137,
201,205,0,2,0,47,0,0,3,199,5,142,0,5,0,9,0,185,64,61,0,6,9,9,93,1,0,20,1,9,8,1,0,9,9,6,1,2,2,93,8,9,20,8,8,9,5,6,7,7,93,4,5,20,4,7,8,4,5,7,7,6,4,3,3,93,8,7,20,8,8,7,8,4,3,7,6,1,3,0,5,184,1,11,178,9,9,
4,184,1,11,64,35,32,3,2,10,7,5,3,3,6,4,9,2,0,3,1,8,8,6,6,10,29,1,1,1,74,15,11,1,11,4,73,10,89,153,24,43,78,16,228,16,93,230,93,25,18,57,47,60,17,18,23,57,17,18,23,57,0,24,63,60,26,25,77,253,60,16,253,
50,23,57,17,18,57,135,5,46,24,43,135,8,125,196,135,8,46,24,43,135,5,125,196,135,46,24,43,135,8,125,196,135,8,46,24,43,135,5,125,196,49,48,9,2,35,9,1,23,9,2,2,37,1,162,254,94,111,254,121,1,135,57,254,172,
1,84,1,103,5,142,253,55,253,59,2,197,2,201,97,253,152,253,153,2,103,255,255,0,39,254,114,4,49,5,238,2,38,0,92,0,0,1,7,0,142,0,181,0,0,0,22,64,12,2,1,0,17,23,0,4,51,2,1,14,34,0,63,53,53,1,43,53,53,255,
255,0,63,0,0,4,125,7,24,2,38,0,60,0,0,1,7,0,142,0,228,1,42,0,22,64,12,2,1,0,18,24,0,4,51,2,1,15,32,0,63,53,53,1,43,53,53,0,1,254,165,255,219,2,176,5,228,0,3,0,76,64,27,8,1,24,1,2,1,2,3,3,93,0,1,20,0,0,
1,2,3,1,0,11,15,1,1,1,1,2,184,1,127,179,1,254,5,0,184,1,127,178,3,254,4,186,2,91,1,63,0,24,43,16,246,237,16,246,237,0,63,93,63,18,57,57,135,5,46,43,135,125,196,49,48,1,93,5,1,51,1,254,165,3,155,112,252,
99,37,6,9,249,247,0,1,0,47,255,221,4,94,5,227,0,41,0,239,64,168,247,30,1,120,30,1,2,103,30,1,1,101,23,1,2,23,23,135,23,151,23,3,1,165,9,181,9,197,9,3,2,103,9,1,1,103,2,1,2,32,21,194,35,168,18,1,9,18,25,
18,2,8,18,14,0,11,194,39,40,14,200,14,248,14,3,0,14,14,24,8,5,126,6,8,126,3,5,27,126,26,24,126,29,13,87,21,119,21,135,21,151,21,167,21,183,21,199,21,7,1,23,21,1,23,11,39,11,87,11,119,11,135,11,151,11,
167,11,183,11,199,11,215,11,231,11,11,21,18,11,14,4,16,87,32,119,32,135,32,151,32,167,32,183,32,199,32,7,2,32,35,0,39,4,37,27,19,12,12,16,5,27,43,16,111,37,40,33,37,47,220,60,16,237,16,222,198,18,57,47,
196,17,18,23,57,95,93,18,23,57,93,93,95,93,0,63,253,214,237,63,253,214,237,17,18,57,47,95,93,60,253,60,16,222,94,93,93,60,253,60,49,48,1,95,93,95,93,95,93,95,93,95,93,95,93,95,93,93,19,54,0,33,50,23,7,
38,35,34,4,7,33,7,33,6,21,20,23,33,7,33,22,4,51,50,55,21,6,35,32,0,3,35,55,51,38,53,52,55,35,55,197,77,1,159,1,13,65,95,37,58,62,199,254,185,75,2,127,36,253,131,7,5,2,79,36,253,243,69,1,77,213,65,74,64,
86,254,231,254,103,73,148,35,88,4,4,123,37,3,197,251,1,35,14,141,12,212,187,138,46,50,30,48,137,195,221,17,140,12,1,36,1,3,137,56,34,32,52,138,0,0,1,0,75,0,0,1,189,4,64,0,5,0,106,64,57,5,0,1,1,85,4,5,
20,4,1,2,4,5,1,1,0,4,3,3,85,2,1,20,2,2,1,1,0,4,201,2,32,5,0,6,3,2,10,5,3,2,1,4,4,7,71,71,74,0,199,128,4,73,6,119,114,24,43,78,16,244,26,77,253,78,69,101,68,230,18,23,57,0,63,60,63,60,26,61,77,16,253,17,
57,135,5,46,24,43,135,8,125,196,135,8,46,24,43,135,5,125,196,49,48,1,3,19,35,3,19,1,189,223,223,148,222,222,4,64,253,222,253,226,2,30,2,34,0,0,1,0,70,0,0,1,184,4,64,0,5,0,102,64,55,5,0,1,1,85,4,5,20,4,
1,2,4,5,1,1,0,4,3,3,85,2,1,20,2,2,1,1,4,201,32,5,0,10,3,2,6,5,3,2,1,4,0,7,71,71,74,4,199,128,0,73,6,119,114,24,43,78,16,244,26,77,253,78,69,101,68,230,18,23,57,0,63,60,63,60,26,61,77,253,57,135,5,46,24,
43,135,8,125,196,135,8,46,24,43,135,5,125,196,49,48,51,19,3,51,19,3,70,223,223,148,222,222,2,33,2,31,253,225,253,223,0,2,0,84,0,0,3,90,6,0,0,24,0,28,0,200,64,42,25,8,17,16,9,18,13,14,15,10,18,13,11,15,
10,7,12,8,16,9,7,12,17,8,9,10,11,14,6,15,16,25,6,10,144,9,15,144,9,16,6,1,184,2,49,64,43,3,88,15,22,1,22,1,27,13,10,10,15,9,16,25,1,0,26,4,27,28,14,17,18,11,8,7,6,12,13,63,9,79,9,2,15,9,31,9,47,9,3,9,
184,1,38,64,23,28,92,27,74,30,15,30,1,9,15,30,1,8,12,92,13,195,16,73,29,160,118,24,43,78,16,244,77,252,237,94,93,94,93,78,16,246,77,253,230,93,93,17,18,23,57,17,18,23,57,17,18,57,57,0,63,60,63,93,253,
228,63,60,237,16,237,63,17,18,23,57,15,15,15,15,49,48,67,121,64,16,4,21,5,37,20,38,4,21,7,128,0,6,19,3,128,1,43,1,43,43,43,129,1,35,38,35,34,14,1,29,1,51,21,35,17,35,17,35,53,51,53,52,62,1,51,50,22,3,
51,17,35,3,90,142,29,138,62,83,36,226,226,142,142,142,71,149,105,132,167,134,142,142,4,240,138,55,91,120,48,123,252,59,3,197,123,48,157,151,92,152,254,216,251,192,0,1,0,92,0,0,3,97,6,0,0,29,0,207,64,77,
47,8,29,7,0,29,3,8,7,0,9,4,5,6,1,9,4,2,6,1,29,3,8,29,0,1,2,5,6,6,7,19,3,18,4,6,144,7,6,24,88,15,13,1,13,1,18,4,10,17,20,18,19,5,8,9,29,2,5,3,4,0,7,6,63,1,79,1,2,15,1,31,1,47,1,3,1,184,1,38,64,23,19,92,
18,74,31,15,31,1,9,15,31,1,8,3,92,4,195,6,73,30,160,118,24,43,78,16,244,77,252,237,94,93,94,93,78,16,246,77,253,230,93,93,17,57,57,17,18,23,57,17,18,57,57,0,63,60,63,93,237,63,237,17,18,57,57,17,18,23,
57,15,15,15,15,49,48,67,121,64,34,10,28,15,37,22,38,27,28,26,28,2,6,11,38,23,14,20,128,1,25,12,29,128,0,21,16,24,128,1,28,10,24,128,1,43,43,1,43,43,43,42,43,43,129,1,21,35,17,35,17,35,53,51,53,52,62,1,
51,50,30,1,21,17,35,17,52,46,1,35,34,6,7,6,21,2,91,224,144,143,143,67,151,99,100,151,62,143,31,85,56,56,85,18,12,4,64,124,252,60,3,196,124,36,169,148,95,98,146,185,251,173,4,91,138,95,58,61,55,40,162,
0,0,1,0,159,254,198,3,206,5,228,0,21,0,162,64,17,11,1,12,0,8,15,7,16,168,15,218,9,14,10,13,168,14,184,2,85,64,14,12,4,19,5,18,168,19,218,3,20,2,21,168,20,184,2,85,64,23,0,0,5,7,2,10,18,16,21,13,20,3,4,
14,15,8,6,19,23,71,71,74,9,184,1,61,182,1,11,2,10,135,6,11,184,1,133,182,17,0,12,21,13,135,12,184,1,61,181,19,73,22,110,151,24,43,78,16,244,77,246,244,60,16,60,60,253,60,244,60,16,60,246,78,69,101,68,
230,18,23,57,17,18,57,57,17,18,57,57,0,63,77,246,244,60,16,60,253,244,60,16,60,47,246,244,60,16,60,253,244,60,16,60,17,18,57,57,49,48,1,51,3,37,21,37,19,3,37,21,37,19,35,19,5,53,5,3,19,5,53,5,1,236,147,
23,1,102,254,154,23,23,1,102,254,154,23,147,24,254,155,1,101,24,24,254,155,1,101,5,228,254,158,23,148,27,254,53,254,60,20,148,28,254,153,1,103,28,148,20,1,196,1,203,27,148,23,0,0,1,0,161,2,99,1,151,3,
91,0,11,0,34,64,15,6,124,0,13,71,71,74,3,116,9,73,12,110,151,24,43,78,16,244,77,253,78,69,101,68,230,0,47,77,237,49,48,1,50,22,21,20,6,35,34,38,53,52,54,1,28,51,72,72,51,51,72,72,3,91,72,52,51,73,73,51,
52,72,0,0,1,0,255,254,238,1,180,1,19,0,10,0,50,64,27,1,0,7,4,6,0,255,6,156,64,5,10,8,0,1,4,5,5,7,252,128,6,73,11,149,236,24,43,78,16,252,26,77,253,23,57,0,63,26,237,228,18,57,57,17,51,49,48,1,39,62,1,
55,35,17,51,21,20,6,1,94,77,38,26,6,88,181,35,254,238,43,76,87,68,1,19,172,129,147,0,0,2,0,198,254,238,3,56,1,19,0,10,0,21,0,102,64,44,12,11,1,0,18,15,17,16,7,4,6,0,255,6,156,5,5,11,255,17,156,64,16,10,
8,0,1,4,5,5,6,7,19,11,12,15,16,5,17,18,7,252,128,6,184,2,58,64,10,64,18,252,128,17,73,22,103,150,24,43,78,16,252,26,77,253,26,254,26,237,17,18,23,57,17,18,23,57,0,63,26,237,228,60,16,237,228,18,57,57,
17,18,57,57,17,51,17,51,49,48,1,39,62,1,55,35,17,51,21,20,6,5,39,62,1,55,35,17,51,21,20,6,2,226,77,38,26,6,88,181,35,254,16,77,38,26,6,88,181,35,254,238,44,76,86,68,1,19,172,129,147,101,44,76,86,68,1,
19,172,129,147,0,0,6,0,49,255,154,9,37,6,0,0,25,0,37,0,49,0,61,0,73,0,85,1,92,64,26,24,2,1,149,8,3,2,3,4,2,93,1,0,20,1,1,0,3,5,0,2,25,1,62,97,74,184,2,3,64,10,80,97,68,68,1,159,44,38,97,50,184,2,3,64,
14,56,97,44,13,5,106,22,159,25,168,18,11,97,32,184,2,3,64,9,26,97,18,5,0,0,59,53,2,184,1,127,64,9,1,1,35,29,87,155,83,121,65,184,1,84,178,77,121,71,184,1,36,178,59,121,41,184,1,84,178,53,121,47,184,1,
36,178,35,121,8,184,1,84,181,29,121,14,73,86,89,185,2,86,0,24,43,78,16,244,77,237,253,237,246,237,253,237,246,237,253,237,228,17,18,57,47,237,17,18,57,47,0,63,253,246,237,16,228,244,237,63,253,246,237,
16,228,60,16,253,246,237,17,18,57,57,17,57,135,5,46,43,8,125,16,196,49,48,24,67,121,64,118,39,85,27,34,9,17,16,38,33,10,35,87,1,31,12,29,87,0,27,17,29,87,0,57,43,59,87,1,55,45,53,87,0,61,39,59,87,1,51,
49,53,87,0,81,67,83,87,1,79,69,77,87,0,85,63,83,87,1,75,73,77,87,0,34,9,32,87,0,30,13,32,87,0,28,15,26,87,1,58,42,56,87,0,54,46,56,87,0,60,40,50,87,1,52,48,50,87,1,82,66,80,87,0,78,70,80,87,0,84,64,74,
87,1,76,72,74,87,1,0,43,43,43,43,43,43,43,43,43,43,43,1,43,43,43,43,43,43,43,43,43,43,43,43,129,129,129,1,93,9,1,35,1,6,35,39,22,21,20,6,35,34,38,53,52,62,1,51,50,23,22,51,50,54,55,5,34,6,21,20,22,51,
50,54,53,52,38,1,50,22,21,20,6,35,34,38,53,52,54,23,34,6,21,20,22,51,50,54,53,52,38,37,50,22,21,20,6,35,34,38,53,52,54,23,34,6,21,20,22,51,50,54,53,52,38,5,104,251,208,132,3,207,173,249,54,62,191,158,
145,198,90,166,87,37,85,130,152,112,199,159,252,153,91,128,128,91,91,129,129,2,200,143,203,203,143,143,203,203,143,91,128,128,91,91,129,129,2,195,143,202,202,143,144,202,202,144,91,129,129,91,91,128,128,
6,0,249,154,5,212,42,1,86,96,137,216,201,144,96,157,96,18,28,29,45,155,129,91,91,128,128,91,91,129,253,36,203,143,143,203,203,143,143,203,127,128,91,91,128,128,91,91,128,127,203,143,143,203,203,143,143,
203,127,128,91,91,128,128,91,91,128,0,255,255,0,49,0,0,5,186,7,48,2,38,0,36,0,0,1,7,0,216,0,243,1,42,0,18,64,10,2,0,15,15,8,8,51,2,17,32,0,63,53,1,43,53,255,255,0,180,0,0,3,255,7,48,2,38,0,40,0,0,1,7,
0,216,0,95,1,42,0,18,64,10,1,0,16,16,0,1,51,1,18,32,0,63,53,1,43,53,255,255,0,49,0,0,5,186,7,103,2,38,0,36,0,0,1,7,0,141,1,117,1,41,0,22,64,13,2,127,13,1,0,13,13,8,8,51,2,14,32,0,63,53,1,43,93,53,255,
255,0,180,0,0,3,255,7,24,2,38,0,40,0,0,1,7,0,142,0,232,1,42,0,22,64,12,2,1,0,21,27,0,1,51,2,1,18,32,0,63,53,53,1,43,53,53,255,255,0,180,0,0,3,255,7,103,2,38,0,40,0,0,1,7,0,67,0,223,1,41,0,18,64,10,1,0,
14,14,0,1,51,1,14,32,0,63,53,1,43,53,255,255,0,81,0,0,2,2,7,103,2,38,0,44,0,0,1,7,0,141,255,103,1,41,0,18,64,10,1,0,7,6,0,1,51,1,7,32,0,63,53,1,43,53,255,255,255,124,0,0,2,82,7,48,2,38,0,44,0,0,1,7,0,
216,254,229,1,42,0,18,64,10,1,0,9,7,0,1,51,1,10,32,0,63,53,1,43,53,255,255,255,168,0,0,2,40,7,24,2,38,0,44,0,0,1,7,0,142,255,110,1,42,0,22,64,12,2,1,0,13,19,0,1,51,2,1,10,32,0,63,53,53,1,43,53,53,255,
255,255,212,0,0,1,133,7,103,2,38,0,44,0,0,1,7,0,67,255,101,1,41,0,18,64,10,1,0,6,5,0,1,51,1,6,32,0,63,53,1,43,53,255,255,0,115,255,219,6,128,7,103,2,38,0,50,0,0,1,7,0,141,1,250,1,41,0,18,64,10,2,0,30,
30,9,3,51,2,31,32,0,63,53,1,43,53,255,255,0,115,255,219,6,128,7,48,2,38,0,50,0,0,1,7,0,216,1,120,1,42,0,18,64,10,2,0,32,32,9,3,51,2,34,32,0,63,53,1,43,53,255,255,0,115,255,219,6,128,7,103,2,38,0,50,0,
0,1,7,0,67,1,247,1,41,0,18,64,10,2,0,30,30,9,3,51,2,30,32,0,63,53,1,43,53,255,255,0,184,255,219,4,134,7,103,2,38,0,56,0,0,1,7,0,141,1,31,1,41,0,18,64,10,1,0,29,29,0,16,51,1,29,32,0,63,53,1,43,53,255,255,
0,184,255,219,4,134,7,48,2,38,0,56,0,0,1,7,0,216,0,157,1,42,0,18,64,10,1,0,31,31,0,16,51,1,33,32,0,63,53,1,43,53,255,255,0,184,255,219,4,134,7,103,2,38,0,56,0,0,1,7,0,67,1,28,1,41,0,18,64,10,1,0,29,29,
0,16,51,1,29,32,0,63,53,1,43,53,0,1,0,135,0,0,1,20,4,64,0,3,0,40,64,19,3,10,0,6,1,0,3,5,71,71,74,2,92,3,73,4,139,118,24,43,78,16,244,77,253,78,69,101,68,230,18,57,57,0,63,63,49,48,19,51,17,35,135,141,
141,4,64,251,192,0,0,1,0,151,5,5,3,109,6,6,0,6,0,141,64,34,55,5,1,3,4,4,85,1,2,20,1,1,2,5,4,4,85,0,6,20,0,0,6,1,4,0,3,5,2,6,0,214,64,4,184,1,44,64,14,13,2,6,0,4,1,3,3,5,8,71,71,74,3,184,2,64,183,160,2,
176,2,192,2,3,2,186,1,10,0,5,2,64,181,6,73,7,110,151,24,43,78,16,244,77,237,253,93,237,78,69,101,68,230,17,18,23,57,0,47,60,75,81,88,176,128,26,89,77,252,26,237,17,18,57,57,17,18,57,135,14,46,43,5,125,
16,196,135,14,46,24,43,5,125,16,196,49,48,1,113,1,51,1,35,39,7,35,1,192,139,1,34,180,176,184,186,6,6,254,255,152,152,0,0,1,0,83,5,27,3,48,5,238,0,21,0,74,64,26,20,0,27,13,32,15,59,2,52,15,5,1,14,13,0,
168,16,97,31,10,47,10,63,10,3,10,184,2,84,64,17,20,97,13,186,4,0,13,14,1,74,23,14,73,22,119,152,24,43,78,16,228,16,230,17,51,50,0,47,77,228,237,244,93,253,228,17,51,50,49,48,93,1,23,14,1,35,34,39,38,39,
38,35,34,6,7,39,54,51,50,23,22,51,50,2,234,70,72,99,55,72,76,65,18,24,28,35,63,60,66,91,134,64,89,85,49,55,5,212,97,52,36,37,32,5,7,25,44,102,97,40,39,0,1,0,152,5,80,3,74,5,199,0,3,0,40,64,20,1,2,0,98,
239,3,1,3,2,3,0,1,74,5,0,73,4,110,151,24,43,78,16,228,16,230,17,57,57,0,47,93,77,237,57,57,49,48,19,33,21,33,152,2,178,253,78,5,199,119,0,1,0,110,5,34,3,51,5,245,0,13,0,52,180,7,1,8,8,0,184,1,37,64,19,
4,106,11,7,121,8,74,15,1,121,0,0,1,0,73,14,95,113,24,43,78,16,244,93,77,237,78,16,246,77,237,0,47,253,252,60,17,57,57,49,48,19,51,30,1,51,50,54,55,51,14,1,35,34,38,110,132,34,114,79,80,98,44,128,22,181,
148,147,186,5,245,52,52,46,58,90,121,119,0,0,1,0,112,5,6,1,88,5,238,0,11,0,24,64,11,0,124,6,3,116,9,73,12,95,113,24,43,78,16,244,77,237,0,47,237,49,48,19,50,22,21,20,6,35,34,38,53,52,54,228,48,68,68,48,
48,68,68,5,238,68,48,48,68,68,48,48,68,0,2,0,127,4,240,2,41,6,155,0,11,0,23,0,118,185,0,4,255,192,179,9,16,57,2,184,255,192,64,14,9,16,57,8,64,9,16,57,10,64,9,16,57,18,187,2,116,0,6,0,12,2,116,64,14,0,
0,6,16,6,32,6,48,6,4,6,6,0,21,187,2,115,0,3,0,15,2,115,64,24,9,15,3,31,3,47,3,63,3,4,3,3,0,9,16,9,2,9,9,25,24,95,113,24,43,17,18,57,47,93,51,47,93,16,237,16,237,0,47,51,47,93,16,237,16,237,49,48,1,43,
43,43,43,1,50,22,21,20,6,35,34,38,53,52,54,23,34,6,21,20,22,51,50,54,53,52,38,1,84,88,125,124,89,88,125,125,87,46,64,64,46,45,64,64,6,155,125,89,88,125,125,88,89,125,101,65,45,45,65,65,45,45,65,0,1,0,
139,254,132,2,23,0,0,0,23,0,129,185,0,5,255,208,64,23,12,15,57,9,64,9,18,57,13,15,12,23,21,2,4,10,170,31,15,47,15,2,15,184,1,126,178,21,170,4,184,1,37,183,0,64,9,15,57,0,10,7,184,255,192,64,14,9,11,57,
25,71,71,74,7,121,18,187,1,146,0,184,1,45,64,16,0,12,48,12,2,9,0,12,1,8,12,73,24,110,113,24,43,78,16,244,94,93,94,93,77,244,253,246,253,78,69,101,68,230,43,0,63,43,77,244,253,246,93,237,17,51,17,51,50,
17,51,49,48,0,43,43,33,51,7,54,51,50,22,21,20,6,35,34,39,55,22,51,50,54,53,52,38,35,34,7,1,55,88,17,23,15,49,66,120,109,89,78,22,64,56,75,60,33,29,24,46,118,3,61,46,66,92,30,69,20,37,28,17,26,9,0,2,1,
1,5,10,3,238,6,62,0,3,0,7,0,90,64,30,4,1,5,0,7,2,6,5,0,223,128,6,3,4,6,5,7,0,2,1,3,5,227,64,223,7,239,7,2,7,184,1,0,64,9,12,1,227,3,73,8,149,113,24,43,78,16,244,77,237,75,82,88,176,128,26,27,176,192,26,
89,252,93,26,237,17,18,57,57,17,18,57,57,0,47,60,26,253,60,18,57,57,17,18,57,57,49,48,1,51,1,35,1,51,1,35,1,219,215,254,217,138,2,22,215,254,217,138,6,62,254,204,1,52,254,204,0,1,0,190,254,119,2,0,0,0,
0,15,0,66,64,11,13,64,11,17,57,11,170,47,6,1,6,184,1,156,64,24,0,10,1,3,0,14,8,254,3,130,47,14,1,9,0,14,1,8,14,73,16,103,152,24,43,78,16,244,94,93,94,93,77,253,230,17,51,17,51,0,63,244,93,237,49,48,1,
43,33,51,6,21,20,22,51,50,55,7,6,35,34,38,53,52,1,53,109,121,75,71,29,40,9,42,43,111,117,103,90,46,64,5,85,10,106,74,130,0,0,1,0,151,5,5,3,109,6,6,0,6,0,132,64,28,5,4,4,85,0,6,20,0,0,6,3,4,4,85,1,2,20,
1,1,2,1,4,0,3,5,2,2,6,184,1,44,64,15,13,4,214,0,0,4,1,3,3,5,8,71,71,74,5,184,2,64,183,160,6,176,6,192,6,3,6,186,1,10,0,3,2,64,181,2,73,7,110,151,24,43,78,16,244,77,237,253,93,237,78,69,101,68,230,17,18,
23,57,0,47,77,253,75,81,88,176,128,26,89,252,60,17,57,57,17,18,57,135,14,46,43,5,125,16,196,135,14,46,24,43,5,125,16,196,49,48,1,35,1,51,23,55,51,2,68,139,254,222,180,177,183,186,5,5,1,1,152,152,0,1,0,
89,0,0,3,236,5,191,0,13,0,141,64,36,11,12,7,10,1,8,12,7,9,2,3,13,4,9,2,0,13,4,10,1,2,1,10,10,86,9,2,20,9,9,2,6,5,7,4,11,188,2,34,0,10,2,77,0,2,2,76,64,22,1,6,4,94,7,8,12,2,2,10,1,9,8,11,12,13,0,3,6,4,
7,1,184,1,157,181,6,74,15,4,101,7,184,1,144,181,9,73,14,180,237,24,43,78,16,244,77,254,237,78,16,246,77,228,17,18,23,57,17,18,57,57,0,63,63,237,25,63,24,253,246,25,228,17,18,57,57,135,46,24,43,135,125,
196,15,15,15,15,49,48,1,37,21,5,17,33,21,33,17,7,53,55,17,51,1,182,1,10,254,246,2,54,253,55,202,202,147,3,89,221,174,222,253,228,142,2,47,168,175,168,2,225,0,0,1,0,53,0,0,2,65,5,228,0,11,0,125,64,32,9,
8,1,10,5,6,7,2,10,5,3,7,2,11,4,0,8,1,11,4,2,1,8,8,91,7,2,20,7,7,2,7,188,2,69,0,8,2,78,0,2,2,69,64,18,1,6,5,10,10,0,11,10,4,5,1,8,7,13,71,71,74,2,184,1,143,178,4,92,5,184,2,68,179,7,73,12,158,185,1,111,
0,24,43,78,16,244,77,254,253,252,78,69,101,68,230,18,57,57,17,18,57,57,0,63,63,63,77,253,246,237,135,46,43,135,125,196,15,15,15,15,49,48,1,55,21,7,17,35,17,7,53,55,17,51,1,121,200,200,140,184,184,140,
3,203,129,140,129,252,193,2,229,119,140,119,2,115,0,255,255,0,27,255,219,3,120,7,48,2,38,0,54,0,0,1,7,0,225,255,252,1,42,0,18,64,10,1,0,47,47,0,37,51,1,44,32,0,63,53,1,43,53,255,255,0,34,255,228,2,248,
6,6,2,38,0,86,0,0,1,6,0,225,139,0,0,18,64,10,1,0,43,43,20,14,51,1,40,34,0,63,53,1,43,53,255,255,0,56,0,0,3,130,7,48,2,38,0,61,0,0,1,7,0,225,255,234,1,42,0,18,64,10,1,0,12,12,6,5,51,1,9,32,0,63,53,1,43,
53,255,255,0,9,0,0,3,98,6,6,2,38,0,93,0,0,1,6,0,225,177,0,0,18,64,10,1,0,12,12,5,4,51,1,9,34,0,63,53,1,43,53,0,2,2,104,254,114,2,247,5,228,0,3,0,7,0,87,64,9,6,3,2,0,5,4,0,159,3,184,1,42,64,25,18,5,159,
6,6,1,4,14,1,0,6,3,7,2,0,5,1,2,7,127,1,4,73,8,231,185,1,18,0,24,43,78,16,244,60,77,253,60,18,57,57,17,18,57,57,0,63,63,18,57,47,228,75,81,88,176,128,26,89,254,228,3,14,16,60,60,16,60,60,49,48,1,17,51,
17,3,17,55,17,2,104,143,143,143,2,174,3,54,253,1,251,141,3,189,54,252,13,0,0,2,0,34,0,0,5,232,5,191,0,15,0,32,0,185,64,65,55,8,30,29,17,2,31,16,29,17,1,32,3,4,15,2,31,0,4,15,1,32,31,32,2,1,18,14,17,15,
28,5,29,4,2,94,1,1,4,17,94,15,8,29,94,4,2,29,4,17,15,31,2,1,32,32,17,23,112,10,74,34,17,101,1,184,1,140,178,15,73,33,184,2,21,177,131,24,43,78,16,244,77,236,237,78,16,246,77,237,17,57,47,18,57,57,17,18,
57,57,0,63,237,63,237,18,57,47,237,17,18,57,57,17,18,57,57,17,18,57,57,15,15,15,15,49,48,67,121,64,42,6,27,12,38,21,22,20,22,2,6,8,9,7,9,2,6,25,24,26,24,2,6,19,13,23,100,1,27,6,23,100,1,22,11,18,100,0,
24,9,28,100,1,43,43,1,43,43,42,42,42,43,129,19,35,53,51,17,33,32,23,22,18,17,20,2,4,41,1,19,17,51,32,55,54,18,53,52,2,39,38,33,35,17,33,21,213,179,179,1,110,1,73,150,213,241,191,254,207,254,238,253,239,
141,230,1,49,118,166,191,207,184,138,254,195,164,1,131,2,155,137,2,155,53,75,254,142,255,0,221,254,176,160,2,155,253,240,38,54,1,25,203,213,1,46,56,42,253,244,137,0,2,0,105,255,228,4,215,5,228,0,27,0,
42,0,196,64,54,56,8,6,6,7,23,24,24,5,3,26,25,4,4,25,25,91,24,5,20,24,24,5,4,5,25,24,4,19,0,35,88,13,11,28,88,19,7,0,0,21,41,39,7,9,24,4,26,3,23,6,6,25,5,186,2,51,0,1,2,70,64,18,25,125,0,0,16,39,105,9,
74,44,32,105,16,73,43,96,133,24,43,78,16,244,77,237,78,16,246,77,237,18,57,47,228,253,228,17,23,57,17,51,17,51,51,0,63,63,237,63,237,17,18,23,57,135,14,46,43,14,125,16,196,7,14,60,60,7,14,16,60,8,60,49,
48,24,67,121,64,40,29,38,10,18,11,38,37,37,30,37,36,12,39,90,1,34,14,32,90,0,29,18,32,90,0,38,10,35,90,0,33,15,35,90,0,31,17,28,90,1,0,43,43,43,1,43,43,43,43,43,43,129,129,1,51,22,23,55,23,7,22,18,21,
20,2,4,35,34,0,53,52,0,51,50,23,38,39,7,39,55,38,19,34,7,6,21,20,22,51,50,62,1,53,52,46,1,1,174,197,52,50,164,52,117,217,194,149,254,248,160,232,254,183,1,69,223,116,135,94,119,218,52,175,96,180,156,125,
153,249,176,114,199,111,107,193,5,228,37,41,68,107,47,209,254,117,173,166,254,236,153,1,78,241,238,1,75,65,127,108,90,106,73,80,254,39,98,121,213,189,255,115,202,125,125,200,109,0,255,255,0,63,0,0,4,125,
7,103,2,38,0,60,0,0,1,7,0,141,0,222,1,41,0,18,64,10,1,0,11,11,0,4,51,1,12,32,0,63,53,1,43,53,255,255,0,39,254,114,4,49,6,62,2,38,0,92,0,0,1,7,0,141,0,165,0,0,0,18,64,10,1,0,10,10,0,4,51,1,11,34,0,63,53,
1,43,53,0,2,0,178,0,0,4,73,5,191,0,16,0,27,0,158,64,18,52,8,2,17,18,14,15,19,13,18,14,27,3,17,2,18,94,14,184,1,1,183,16,8,17,94,31,2,1,2,184,1,1,64,12,0,2,0,1,2,17,18,14,6,15,16,23,184,1,40,64,11,8,74,
29,15,101,16,73,28,102,131,24,43,78,16,244,77,237,78,16,246,77,237,17,18,23,57,0,63,244,93,237,63,244,237,17,18,57,57,17,18,57,57,3,5,16,60,60,60,60,49,48,67,121,64,38,4,26,10,9,11,9,2,6,21,37,6,7,5,7,
2,6,25,38,20,12,23,117,1,26,4,23,117,1,22,9,19,117,0,24,7,27,117,1,0,43,43,1,43,43,43,42,43,42,129,19,51,17,51,50,23,30,1,21,20,6,7,6,33,35,17,35,19,17,23,50,62,1,53,52,46,1,35,178,147,146,251,88,126,
161,156,137,100,254,238,105,147,147,249,151,140,80,80,131,149,5,191,254,168,22,31,193,146,146,191,34,24,254,172,3,216,254,12,3,56,122,76,75,122,52,0,0,2,0,158,254,114,5,11,5,228,0,16,0,31,0,186,64,47,
30,64,24,11,27,64,5,17,41,8,2,20,14,15,17,88,5,7,0,0,24,88,11,11,16,14,0,1,2,20,14,5,15,16,28,105,8,74,33,15,92,16,73,32,123,133,24,43,78,16,244,77,237,78,16,246,77,237,17,18,23,57,0,63,63,237,63,63,237,
3,14,16,60,125,196,60,49,48,24,67,121,64,28,25,31,6,10,26,37,30,38,25,10,28,90,1,31,6,28,90,1,27,9,24,90,0,29,7,17,90,1,0,43,43,1,43,43,43,43,129,129,0,73,84,121,64,16,18,19,3,4,19,3,17,104,5,18,4,20,
104,0,3,2,1,16,60,43,0,43,129,129,0,73,84,121,64,18,21,23,12,13,22,38,21,13,24,104,4,23,12,20,104,0,13,14,1,16,60,43,0,43,43,129,129,19,51,17,62,1,51,50,0,21,20,0,35,34,38,39,17,35,1,34,6,21,20,30,1,51,
50,62,1,53,52,46,1,158,139,83,216,133,232,1,74,254,185,231,130,218,88,139,2,48,182,249,111,207,115,113,199,118,117,198,5,228,253,148,114,114,254,178,235,240,254,177,108,107,253,183,5,99,254,189,124,198,
116,117,210,115,116,208,115,0,1,0,115,2,155,4,103,3,36,0,3,0,44,64,18,2,1,0,98,22,3,1,0,3,2,74,5,3,73,4,95,113,24,43,78,16,228,16,230,17,57,57,0,47,75,81,88,176,128,26,89,77,253,57,57,49,48,19,33,21,33,
115,3,244,252,12,3,36,137,0,1,0,197,1,56,4,20,4,135,0,11,0,181,64,83,216,11,1,216,4,216,8,216,9,3,216,0,216,1,216,3,3,200,5,200,7,200,8,3,9,8,1,5,10,6,7,2,5,10,3,7,2,4,11,0,8,1,4,11,10,11,4,4,85,5,10,
20,5,5,10,2,1,8,8,85,7,2,20,7,7,2,10,7,11,6,0,9,3,5,1,2,10,9,0,4,1,8,4,184,1,14,64,23,8,7,4,8,6,3,0,9,10,2,11,10,5,13,71,71,74,9,15,1,1,8,1,184,1,14,181,5,73,12,103,150,24,43,25,78,16,244,24,77,253,94,
93,94,25,78,69,101,68,230,18,23,57,0,47,24,77,237,94,93,94,23,57,135,14,46,43,135,14,125,196,135,14,46,24,43,135,14,125,196,15,15,15,15,49,48,1,93,93,93,93,9,1,7,9,1,39,9,1,55,9,1,23,2,200,1,76,92,254,
181,254,180,92,1,75,254,181,92,1,76,1,75,92,2,223,254,181,92,1,75,254,181,92,1,75,1,76,92,254,180,1,76,92,0,0,1,0,151,2,221,1,155,5,209,0,5,0,43,64,10,3,24,5,214,0,27,2,181,4,3,184,1,45,64,11,0,5,16,5,
2,5,73,6,110,173,24,43,78,16,244,93,77,244,60,237,0,63,237,63,49,48,19,51,17,35,17,35,224,187,110,150,5,209,253,12,2,146,0,0,1,0,6,2,221,2,130,5,228,0,23,0,139,64,23,23,8,10,11,11,93,14,15,20,14,14,15,
11,13,14,10,15,21,12,192,14,24,0,184,1,46,64,31,21,130,4,27,15,18,14,10,11,18,130,7,129,128,13,1,80,13,96,13,112,13,3,13,74,25,0,130,1,155,11,184,2,62,181,14,73,24,115,153,24,43,78,16,244,77,237,244,237,
78,16,246,93,93,77,244,237,18,57,17,18,57,0,63,253,228,63,237,17,57,57,17,57,57,135,5,46,43,14,125,16,196,49,48,24,67,121,64,14,19,20,5,6,20,5,18,107,1,19,6,21,107,1,0,43,1,43,129,129,19,35,62,1,51,50,
22,21,20,6,15,1,33,21,33,1,62,1,53,52,38,35,34,6,155,106,2,167,133,124,156,66,110,190,1,121,253,132,1,102,106,52,99,76,85,100,4,210,119,155,137,95,60,112,100,172,99,1,69,96,81,39,54,82,92,0,1,0,44,2,203,
2,140,5,228,0,37,0,183,64,29,40,8,9,15,28,31,28,2,9,15,28,1,8,28,170,29,29,35,0,19,16,19,2,9,0,19,1,8,19,184,1,44,64,10,22,106,15,25,15,0,31,0,2,0,184,1,37,64,45,35,106,4,27,9,7,28,28,19,32,130,255,7,
1,7,155,25,130,47,12,63,12,79,12,3,12,74,39,15,39,31,39,2,0,130,1,135,19,130,18,73,38,89,114,24,43,78,16,244,77,237,244,237,93,78,16,246,93,77,237,244,93,237,17,57,47,17,57,0,63,253,228,93,63,253,228,
94,93,94,93,18,57,47,237,94,93,94,93,57,49,48,67,121,64,28,33,34,23,24,13,14,5,6,23,14,25,107,1,34,5,32,107,1,24,13,22,107,0,33,6,35,107,1,43,43,1,43,43,129,129,129,129,19,35,62,1,51,50,22,21,20,7,30,
1,21,20,6,35,34,38,39,51,30,1,51,50,54,53,52,38,39,53,50,54,53,52,38,35,34,6,184,112,27,140,103,116,147,91,67,71,169,138,125,153,23,109,20,95,77,90,107,120,134,102,100,81,67,55,74,5,13,106,109,121,82,
87,59,32,104,58,101,149,123,118,73,69,87,58,66,74,5,94,65,43,40,63,52,255,255,0,104,255,219,6,39,5,228,0,38,0,241,209,0,0,39,0,188,2,112,0,0,1,7,0,242,3,165,253,26,0,55,64,34,2,24,1,0,6,32,6,48,6,3,6,
0,0,2,16,2,32,2,3,9,0,2,1,8,2,2,24,28,1,6,11,0,3,24,0,63,53,63,53,63,53,1,47,94,93,94,93,53,47,93,53,47,53,0,255,255,0,115,255,219,6,123,5,228,0,38,0,241,220,0,0,39,0,188,2,223,0,0,1,7,1,4,3,224,253,26,
0,55,64,31,3,2,0,18,1,18,1,0,6,1,6,0,0,2,1,9,0,2,1,8,2,3,2,16,28,1,6,11,0,3,24,0,63,53,63,53,63,53,53,1,47,94,93,94,93,53,47,93,53,47,93,53,53,0,255,255,0,69,255,219,6,116,5,228,0,38,0,243,25,0,0,39,0,
188,3,10,0,0,1,7,1,4,3,217,253,26,0,20,64,10,3,2,48,28,1,38,11,0,15,25,0,63,53,63,53,63,53,53,0,1,0,0,0,0,3,148,5,191,0,17,0,158,64,85,14,17,4,9,8,1,10,5,6,7,2,10,5,3,7,2,13,4,0,8,1,13,4,6,3,2,1,0,9,6,
8,7,16,15,17,14,12,11,13,10,17,98,14,14,5,10,8,98,7,255,5,8,13,98,10,2,2,8,1,7,15,12,16,11,6,9,10,13,14,17,0,3,8,4,5,1,1,4,16,11,74,19,4,127,5,184,1,141,181,7,73,18,115,152,24,43,78,16,244,77,252,237,
78,16,246,60,17,57,47,17,18,23,57,17,18,57,57,17,18,57,57,0,63,77,237,63,252,237,17,18,57,47,237,17,18,57,57,17,18,57,57,17,18,23,57,15,15,15,15,3,5,16,60,60,49,48,1,33,21,33,17,35,17,35,53,51,17,33,21,
33,17,33,21,33,1,69,1,25,254,231,146,179,179,2,225,253,177,2,79,253,177,1,159,138,254,235,1,21,138,4,32,145,254,52,145,0,255,255,0,117,255,219,6,149,7,26,2,38,0,42,0,0,1,7,0,219,1,172,1,37,0,18,64,10,
1,0,32,40,25,18,51,1,43,32,0,63,53,1,43,53,255,255,0,100,254,86,4,210,5,245,2,38,0,74,0,0,1,7,0,219,0,225,0,0,0,18,64,10,2,0,49,57,27,1,51,2,60,34,0,63,53,1,43,53,255,255,0,116,0,0,1,92,7,19,2,38,0,44,
0,0,1,7,0,220,0,4,1,37,0,18,64,10,1,0,13,7,0,1,51,1,10,32,0,63,53,1,43,53,255,255,0,27,254,132,3,120,5,228,2,38,0,54,0,0,1,6,0,222,118,0,0,11,182,1,0,55,50,0,37,51,1,43,53,0,255,255,0,54,254,132,2,192,
4,92,2,38,0,86,0,0,1,6,0,222,29,0,0,11,182,1,0,51,46,20,14,51,1,43,53,0,255,255,0,111,255,219,6,13,7,99,2,38,0,38,0,0,1,7,0,141,2,21,1,37,0,18,64,10,1,0,29,29,21,14,51,1,30,32,0,63,53,1,43,53,255,255,
0,105,255,228,4,188,6,62,2,38,0,70,0,0,1,7,0,141,1,59,0,0,0,18,64,10,1,0,29,29,19,13,51,1,30,34,0,63,53,1,43,53,255,255,0,111,255,219,6,13,7,43,2,38,0,38,0,0,1,7,0,225,1,135,1,37,0,18,64,10,1,0,31,31,
21,14,51,1,28,32,0,63,53,1,43,53,255,255,0,105,255,228,4,188,6,6,2,38,0,70,0,0,1,7,0,225,0,197,0,0,0,18,64,10,1,0,31,31,19,13,51,1,28,34,0,63,53,1,43,53,0,2,0,109,255,228,5,122,5,228,0,24,0,39,0,245,64,
49,30,64,33,9,27,64,15,25,41,8,6,37,18,22,21,1,23,5,19,20,2,23,5,3,20,2,24,4,0,21,1,24,4,22,0,1,2,3,19,6,20,23,0,21,144,0,20,1,20,184,1,31,64,22,25,88,15,7,33,88,9,11,5,10,3,0,24,23,22,19,18,37,6,9,4,
20,184,2,75,64,15,5,92,1,195,4,74,41,29,105,12,73,40,96,118,24,43,78,16,244,77,237,78,16,246,77,236,253,236,18,23,57,0,63,63,237,63,237,254,93,237,63,17,23,57,15,15,15,15,3,14,60,125,196,60,49,48,24,67,
121,64,28,26,32,10,14,31,38,27,37,32,10,29,90,0,26,14,29,90,0,30,11,33,90,0,28,13,25,90,1,0,43,43,1,43,43,43,43,129,129,0,73,84,121,64,16,38,39,16,17,38,17,25,104,5,39,16,37,104,1,17,18,1,16,60,43,0,43,
129,129,0,73,84,121,64,18,34,36,7,8,35,37,36,7,33,104,4,34,8,37,104,1,7,6,1,16,60,43,0,43,43,129,129,1,51,21,35,17,35,53,14,1,35,34,0,53,52,0,51,50,22,23,17,33,53,33,53,51,1,34,14,1,21,20,30,1,51,50,62,
1,53,52,38,4,218,160,160,138,88,219,130,231,254,185,1,74,232,134,217,82,254,206,1,50,138,253,208,117,198,117,118,199,114,115,206,111,249,5,51,115,251,64,187,107,108,1,79,240,235,1,78,114,114,1,72,115,
177,253,241,115,208,116,115,210,117,116,198,124,189,254,0,1,255,244,6,88,4,12,6,191,0,3,0,42,177,1,0,184,2,110,64,11,2,3,2,3,0,1,74,5,0,73,4,184,1,22,177,208,24,43,78,16,236,16,238,17,57,57,0,47,60,77,
253,60,49,48,3,33,21,33,12,4,24,251,232,6,191,103,0,1,1,230,2,126,2,206,3,102,0,11,0,26,183,6,124,0,9,164,3,74,13,184,1,72,177,109,24,43,78,16,246,77,237,0,47,237,49,48,1,50,22,21,20,6,35,34,38,53,52,
54,2,90,48,68,68,48,48,68,68,3,102,68,48,48,68,68,48,48,68,0,0,2,0,19,2,221,2,155,5,248,0,8,0,11,0,98,64,38,10,11,11,93,8,0,20,8,8,0,2,11,192,3,8,8,0,6,24,10,156,0,27,10,6,181,0,79,5,1,31,5,47,5,63,5,
3,5,184,1,125,182,3,74,13,111,13,1,11,184,2,4,181,8,73,12,115,153,24,43,78,16,244,77,237,93,78,16,246,77,244,93,93,60,253,60,0,63,237,63,18,57,47,60,253,60,135,5,46,43,4,125,16,196,49,48,1,17,51,21,35,
21,35,53,33,37,53,7,2,50,105,105,111,254,80,1,176,214,5,248,253,240,97,170,170,97,248,248,255,255,0,49,0,0,5,186,7,30,2,38,0,36,0,0,1,7,0,219,1,44,1,41,0,18,64,10,2,0,22,22,8,8,51,2,22,32,0,63,53,1,43,
53,255,255,0,107,255,228,4,216,5,245,2,38,0,68,0,0,1,7,0,219,0,200,0,0,0,18,64,10,2,0,43,43,12,12,51,2,43,34,0,63,53,1,43,53,255,255,0,49,254,119,5,239,5,191,2,38,0,36,0,0,1,7,0,224,3,239,0,0,0,11,182,
2,0,11,12,2,1,51,1,43,53,0,255,255,0,107,254,119,5,38,4,92,2,38,0,68,0,0,1,7,0,224,3,38,0,0,0,18,64,10,2,0,32,33,2,1,51,2,32,52,0,63,53,1,43,53,255,255,0,179,0,0,5,138,7,43,2,38,0,39,0,0,1,7,0,225,0,151,
1,37,0,26,181,2,95,29,127,29,2,184,255,116,183,29,29,24,18,51,2,25,32,0,63,53,1,43,93,53,0,3,0,109,255,228,5,191,5,228,0,14,0,26,0,36,0,177,64,120,27,3,20,13,24,17,21,19,42,7,35,9,63,7,50,9,54,13,120,
12,123,17,116,19,115,23,123,25,143,3,132,13,155,3,170,3,165,13,185,3,183,19,200,3,198,13,23,199,19,1,13,13,12,24,3,2,3,4,28,27,27,31,31,32,0,21,88,5,11,2,10,15,88,11,7,0,0,27,28,30,33,32,28,28,32,33,33,
15,32,31,32,47,32,63,32,79,32,5,32,32,0,0,14,13,24,3,5,2,92,1,74,38,18,105,8,73,37,96,118,24,43,78,16,244,77,237,78,16,246,77,237,23,57,17,51,47,93,51,47,17,51,47,17,18,57,17,51,0,63,63,237,63,63,237,
63,51,47,51,47,51,3,8,16,60,14,125,196,8,60,49,48,1,93,0,93,1,17,35,53,6,33,34,0,53,52,0,51,32,23,17,1,34,2,21,20,18,51,50,36,53,52,36,37,39,54,55,35,53,51,21,20,6,4,218,138,177,254,252,244,254,198,1,
71,235,1,12,165,254,90,186,246,251,180,167,1,9,254,255,2,30,65,53,6,75,154,28,5,228,250,28,187,215,1,92,227,230,1,83,228,2,108,253,241,254,249,176,178,254,248,234,204,199,244,60,38,104,91,234,146,106,
126,0,0,2,0,34,0,0,5,232,5,191,0,15,0,32,0,185,64,65,55,8,30,29,17,2,31,16,29,17,1,32,3,4,15,2,31,0,4,15,1,32,31,32,2,1,18,14,17,15,28,5,29,4,2,94,1,1,4,17,94,15,8,29,94,4,2,29,4,17,15,31,2,1,32,32,17,
23,112,10,74,34,17,101,1,184,1,140,178,15,73,33,184,2,21,177,131,24,43,78,16,244,77,236,237,78,16,246,77,237,17,57,47,18,57,57,17,18,57,57,0,63,237,63,237,18,57,47,237,17,18,57,57,17,18,57,57,17,18,57,
57,15,15,15,15,49,48,67,121,64,42,6,27,12,38,21,22,20,22,2,6,8,9,7,9,2,6,25,24,26,24,2,6,19,13,23,100,1,27,6,23,100,1,22,11,18,100,0,24,9,28,100,1,43,43,1,43,43,42,42,42,43,129,19,35,53,51,17,33,32,23,
22,18,17,20,2,4,41,1,19,17,51,32,55,54,18,53,52,2,39,38,33,35,17,33,21,213,179,179,1,110,1,73,150,213,241,191,254,207,254,238,253,239,141,230,1,49,118,166,191,207,184,138,254,195,164,1,131,2,155,137,2,
155,53,75,254,142,255,0,221,254,176,160,2,155,253,240,38,54,1,25,203,213,1,46,56,42,253,244,137,255,255,0,180,254,119,3,255,5,191,2,38,0,40,0,0,1,7,0,224,1,251,0,0,0,18,64,10,1,0,12,13,11,10,51,1,12,52,
0,63,53,1,43,53,255,255,0,104,254,119,4,202,4,92,2,38,0,72,0,0,1,7,0,224,1,124,0,0,0,18,64,10,2,0,33,33,5,5,51,2,33,52,0,63,53,1,43,53,255,255,0,180,0,0,3,255,7,48,2,38,0,40,0,0,1,7,0,225,0,95,1,42,0,
18,64,10,1,0,16,16,0,1,51,1,12,32,0,63,53,1,43,53,255,255,0,104,255,228,4,202,6,6,2,38,0,72,0,0,1,7,0,225,0,152,0,0,0,18,64,10,2,0,37,37,12,12,51,2,33,34,0,63,53,1,43,53,0,2,0,158,255,219,4,247,5,191,
0,3,0,19,0,109,178,28,8,12,186,2,28,0,13,2,27,64,24,15,122,10,9,4,2,0,3,8,13,175,12,1,63,12,79,12,111,12,3,12,12,18,4,184,1,40,64,11,6,74,21,2,101,3,73,20,102,174,24,43,78,16,244,77,237,78,16,246,77,237,
17,51,47,93,113,51,0,63,47,63,63,253,244,237,49,48,67,121,64,18,16,18,7,9,8,38,17,37,16,9,19,117,1,18,7,15,117,0,43,1,43,43,43,129,129,19,51,17,35,1,51,17,20,14,1,35,34,39,55,22,51,50,62,1,53,158,147,
147,3,198,147,51,176,128,183,184,79,189,99,73,108,27,5,191,250,65,5,191,252,31,196,193,126,156,117,136,96,135,152,0,0,4,0,90,254,86,2,221,6,0,0,11,0,23,0,27,0,41,0,161,64,14,117,31,134,31,2,35,34,37,88,
32,15,28,6,18,184,1,54,181,15,12,1,12,1,6,184,1,54,64,10,15,0,1,0,1,25,6,27,10,34,184,1,143,64,73,207,21,223,21,2,21,178,41,92,207,30,223,30,2,30,178,15,15,31,15,63,15,79,15,95,15,111,15,223,15,7,239,
15,255,15,2,15,74,43,192,3,208,3,2,3,178,26,92,192,27,208,27,2,27,178,0,9,16,9,208,9,3,224,9,240,9,2,9,73,42,160,133,24,43,78,16,244,93,113,77,244,93,253,228,93,78,16,246,93,113,77,244,93,253,228,93,228,
0,63,63,63,93,237,63,93,237,63,63,237,51,50,49,48,1,93,19,50,22,21,20,6,35,34,38,53,52,54,33,50,22,21,20,6,35,34,38,53,52,54,1,51,17,35,1,51,17,16,35,34,39,53,22,51,50,62,1,53,205,48,68,68,48,47,68,69,
1,203,47,68,68,47,47,68,68,254,76,141,141,1,158,142,185,74,86,54,47,39,49,14,6,0,68,47,48,68,68,48,49,66,66,49,48,68,68,48,49,66,254,64,251,192,4,64,251,28,254,250,34,126,29,42,55,75,0,255,255,0,179,0,
0,3,124,7,104,2,38,0,47,0,0,1,7,0,141,0,95,1,42,0,18,64,10,1,0,9,9,1,1,51,1,8,32,0,63,53,1,43,53,255,255,0,79,0,0,2,0,7,103,2,38,0,79,0,0,1,7,0,141,255,101,1,41,0,18,64,10,1,0,6,7,0,0,51,1,6,32,0,63,53,
1,43,53,255,255,0,179,0,0,3,124,5,191,2,34,0,47,0,0,1,7,0,183,0,211,255,219,0,18,64,10,1,136,12,12,1,1,51,1,12,2,0,63,53,1,43,53,0,2,0,134,0,0,1,246,5,228,0,3,0,13,0,101,64,67,5,4,4,8,8,9,3,10,0,0,9,0,
7,10,9,4,5,5,9,10,10,15,9,31,9,47,9,63,9,79,9,5,9,9,2,92,208,3,224,3,240,3,3,0,3,16,3,2,0,3,16,3,32,3,48,3,208,3,224,3,240,3,7,3,3,15,14,17,18,57,47,93,113,113,253,50,47,93,51,47,17,51,47,51,17,18,57,
0,63,63,63,17,51,47,51,47,51,49,48,19,51,17,35,1,39,54,55,35,53,51,21,20,6,134,140,140,1,40,66,53,7,75,153,27,5,228,250,28,4,17,38,104,91,234,146,106,126,0,255,255,0,179,0,0,3,124,5,191,2,38,0,47,0,0,
1,6,1,3,10,0,0,11,182,1,171,15,15,1,1,51,1,43,53,0,255,255,0,135,0,0,2,76,5,228,0,38,0,79,0,0,0,7,1,3,255,126,0,0,255,255,0,180,0,0,5,55,7,103,2,38,0,49,0,0,1,7,0,141,1,152,1,41,0,18,64,10,1,0,13,11,1,
5,51,1,12,32,0,63,53,1,43,53,255,255,0,156,0,0,4,81,6,62,2,38,0,81,0,0,1,7,0,141,0,215,0,0,0,18,64,10,1,0,28,26,0,10,51,1,27,34,0,63,53,1,43,53,255,255,0,180,0,0,5,55,7,47,2,38,0,49,0,0,1,7,0,225,0,250,
1,41,0,18,64,10,1,0,14,14,1,5,51,1,10,32,0,63,53,1,43,53,255,255,0,156,0,0,4,81,6,6,2,38,0,81,0,0,1,7,0,225,0,175,0,0,0,18,64,10,1,0,29,29,0,10,51,1,25,34,0,63,53,1,43,53,255,255,255,187,0,0,4,86,5,228,
0,38,0,81,5,0,1,7,0,183,254,191,0,0,0,38,179,1,160,32,1,184,255,207,64,11,32,32,0,0,51,1,31,0,0,10,10,185,2,117,0,37,1,16,226,17,53,0,63,53,1,43,93,53,255,255,0,115,255,219,6,128,7,104,2,38,0,50,0,0,1,
7,0,223,1,119,1,42,0,22,64,12,3,2,0,30,34,12,1,51,3,2,34,32,0,63,53,53,1,43,53,53,255,255,0,104,255,228,4,213,6,62,2,38,0,82,0,0,1,7,0,223,0,173,0,0,0,22,64,12,3,2,0,30,34,0,0,51,3,2,34,34,0,63,53,53,
1,43,53,53,255,255,0,187,0,0,4,104,7,103,2,38,0,53,0,0,1,7,0,141,1,17,1,41,0,26,181,2,79,31,111,31,2,184,255,236,183,31,29,17,23,51,2,30,32,0,63,53,1,43,93,53,255,255,0,103,0,0,2,141,6,62,2,38,0,85,0,
0,1,6,0,141,226,0,0,18,64,10,1,0,21,19,0,7,51,1,20,34,0,63,53,1,43,53,255,255,0,187,0,0,4,104,7,47,2,38,0,53,0,0,1,7,0,225,0,73,1,41,0,18,64,10,2,20,32,32,0,23,51,2,28,32,0,63,53,1,43,53,255,255,255,225,
0,0,2,183,6,6,2,38,0,85,0,0,0,7,0,225,255,74,0,0,255,255,0,27,255,219,3,120,7,103,2,38,0,54,0,0,1,7,0,141,0,100,1,41,0,18,64,10,1,0,45,45,19,19,51,1,45,32,0,63,53,1,43,53,255,255,0,54,255,228,2,192,6,
62,2,38,0,86,0,0,1,6,0,141,206,0,0,18,64,10,1,0,42,1,34,37,51,1,41,34,0,63,53,1,43,53,0,2,0,33,254,85,3,72,5,191,0,7,0,16,0,143,64,82,3,10,1,4,7,0,9,8,8,12,12,15,13,31,13,47,13,3,13,13,6,3,2,0,94,1,2,
6,8,11,14,8,0,9,16,9,32,9,48,9,4,208,9,224,9,240,9,3,9,9,13,101,0,14,16,14,32,14,3,14,14,4,7,5,6,2,1,0,18,71,71,74,3,224,5,101,6,224,0,73,17,169,185,1,21,0,24,43,78,16,244,77,244,253,244,78,69,101,68,
230,18,57,57,17,18,57,57,50,47,93,77,237,51,47,93,113,51,17,57,0,63,63,237,57,57,17,51,47,93,51,47,51,47,51,16,60,60,49,48,1,93,19,53,33,21,33,17,35,17,19,39,54,55,35,53,51,21,20,33,3,39,254,184,150,109,
65,32,3,83,157,5,48,143,143,250,208,5,48,249,37,27,72,53,154,51,167,0,2,0,87,254,85,2,129,5,212,0,11,0,20,0,166,64,96,11,0,7,10,3,8,0,7,9,4,5,1,6,9,4,2,1,6,10,3,13,12,12,16,16,15,17,31,17,47,17,3,17,17,
7,11,2,3,4,5,8,6,10,0,0,9,144,10,6,7,10,12,0,13,16,13,32,13,48,13,4,208,13,224,13,240,13,3,13,13,15,17,92,0,18,16,18,32,18,3,18,18,8,11,0,1,2,5,6,6,7,22,71,71,74,4,184,1,143,178,6,92,7,186,1,143,0,9,1,
120,179,21,160,205,24,43,16,246,244,253,244,78,69,101,68,238,17,18,23,57,50,47,93,77,253,57,51,47,93,113,51,0,63,63,237,63,17,23,57,17,51,47,93,51,47,51,47,51,15,15,15,15,49,48,1,51,17,51,21,35,17,35,
17,35,53,51,19,39,54,55,35,53,51,21,20,1,22,141,222,222,141,191,191,104,65,32,2,82,156,5,212,254,108,120,252,56,3,200,120,250,21,27,72,53,154,51,167,0,255,255,0,33,0,0,3,72,7,43,2,38,0,55,0,0,1,7,0,225,
255,196,1,37,0,18,64,10,1,0,12,12,1,2,51,1,8,32,0,63,53,1,43,53,0,2,0,87,0,0,2,147,5,228,0,9,0,21,0,151,64,84,21,10,17,20,13,18,10,17,19,14,15,11,16,19,14,12,11,16,20,13,1,0,0,4,4,5,1,21,12,13,14,15,18,
6,20,10,0,19,144,20,6,17,10,0,0,1,16,1,32,1,48,1,4,208,1,224,1,240,1,3,1,1,3,6,92,15,5,1,5,5,18,21,10,11,12,15,6,16,17,23,71,71,74,14,184,1,143,178,16,92,17,186,1,143,0,19,1,120,179,22,160,205,24,43,16,
246,244,253,244,78,69,101,68,238,17,18,23,57,50,47,93,77,237,57,50,47,93,113,51,0,63,63,237,63,17,23,57,63,51,47,51,47,51,15,15,15,15,49,48,1,39,54,55,35,53,51,21,20,6,1,51,17,51,21,35,17,35,17,35,53,
51,2,80,59,53,3,68,138,22,254,153,141,222,222,141,191,191,4,139,26,83,72,164,103,85,89,1,5,254,108,120,252,56,3,200,120,255,255,0,184,255,219,4,134,7,197,2,38,0,56,0,0,1,7,0,221,1,37,1,42,0,22,64,12,2,
1,0,36,30,0,16,51,2,1,33,32,0,63,53,53,1,43,53,53,255,255,0,138,255,228,4,66,6,155,2,38,0,88,0,0,1,7,0,221,0,244,0,0,0,22,64,12,2,1,0,33,27,0,14,51,2,1,30,34,0,63,53,53,1,43,53,53,255,255,0,184,255,219,
4,155,7,104,2,38,0,56,0,0,1,7,0,223,0,173,1,42,0,22,64,12,2,1,0,30,32,1,16,51,2,1,34,32,0,63,53,53,1,43,53,53,255,255,0,138,255,228,4,106,6,62,2,38,0,88,0,0,1,6,0,223,124,0,0,22,64,12,2,1,0,27,29,1,14,
51,2,1,31,34,0,63,53,53,1,43,53,53,255,255,0,56,0,0,3,130,7,103,2,38,0,61,0,0,1,7,0,141,0,75,1,41,0,18,64,10,1,0,11,9,1,5,51,1,10,32,0,63,53,1,43,53,255,255,0,9,0,0,3,98,6,62,2,38,0,93,0,0,1,6,0,141,80,
0,0,18,64,10,1,0,11,9,0,13,51,1,10,34,0,63,53,1,43,53,255,255,0,56,0,0,3,130,7,23,2,38,0,61,0,0,1,7,0,220,0,225,1,41,0,20,185,0,1,255,206,183,17,11,1,2,51,1,14,32,0,63,53,1,43,53,255,255,0,9,0,0,3,98,
5,238,2,38,0,93,0,0,1,7,0,220,0,175,0,0,0,18,64,10,1,0,14,14,0,1,51,1,14,34,0,63,53,1,43,53,0,1,0,177,0,0,4,42,5,187,0,5,0,41,185,0,2,2,103,180,0,2,5,8,4,184,2,104,64,10,5,1,74,7,5,73,6,102,237,24,43,
78,16,228,16,230,77,16,237,0,63,63,237,49,48,19,33,21,33,17,35,177,3,121,253,73,194,5,187,174,250,243,0,3,0,115,255,216,5,135,5,223,0,13,0,26,0,30,0,137,64,32,104,15,103,22,104,26,3,42,1,42,5,37,9,37,
13,37,15,37,19,42,22,42,26,166,15,169,22,169,26,11,19,23,184,255,240,181,2,16,25,16,2,28,184,2,106,64,11,127,30,143,30,175,30,3,30,30,0,21,184,2,106,178,7,9,14,184,2,106,64,9,0,3,29,29,24,30,30,24,17,
187,2,105,0,11,0,24,2,105,64,9,3,74,32,11,73,31,120,131,24,43,78,16,228,16,246,77,237,16,253,17,57,47,17,57,47,0,63,237,63,237,18,57,47,93,237,49,48,23,56,23,56,1,93,0,93,1,32,0,17,20,2,4,35,34,36,2,53,
16,0,5,34,2,17,20,18,22,51,50,18,17,16,2,1,33,21,33,3,5,1,43,1,87,147,254,216,196,211,254,229,167,1,79,1,67,214,238,108,192,140,211,238,231,254,25,2,35,253,221,5,223,254,105,254,147,225,254,154,188,173,
1,93,252,1,92,1,165,158,254,212,254,204,222,254,253,138,1,43,1,72,1,27,1,61,253,252,167,0,3,0,115,255,81,6,62,5,223,0,14,0,19,0,24,0,112,177,18,22,184,255,238,183,2,16,24,16,2,15,2,20,184,2,106,179,14,
6,19,21,184,2,106,64,10,9,9,8,14,14,0,8,0,3,23,187,2,105,0,4,0,17,2,105,64,14,11,47,4,1,4,4,11,11,1,21,7,0,19,7,184,2,104,179,8,8,26,25,17,18,57,47,237,60,60,16,60,60,51,47,50,47,113,16,237,16,237,0,63,
47,17,51,47,17,51,47,253,50,51,16,237,51,50,49,48,23,56,23,56,1,51,21,4,17,16,5,17,35,17,36,17,16,0,37,21,4,17,16,5,19,17,36,17,16,2,249,194,2,131,253,125,194,253,122,1,45,1,89,254,76,1,180,194,1,179,
5,223,194,23,253,206,253,203,22,254,200,1,56,23,2,52,1,8,1,51,14,154,4,254,84,254,103,25,3,98,252,158,8,1,171,1,167,0,0,2,0,104,255,228,4,175,4,56,0,18,0,30,0,149,64,20,9,11,9,17,25,11,25,17,102,3,102,
7,102,20,102,24,168,29,9,23,186,255,224,0,27,255,240,64,10,30,16,21,26,10,0,11,17,10,25,184,2,107,178,2,11,19,184,2,107,183,8,11,11,8,6,0,10,28,184,2,104,64,17,0,14,16,14,32,14,48,14,64,14,80,14,6,14,
14,12,17,187,2,104,0,16,0,11,2,104,181,12,125,16,74,32,22,184,2,105,181,5,73,31,96,133,24,43,78,16,244,77,237,78,16,246,77,244,237,16,237,17,51,47,93,253,50,50,0,63,51,47,16,237,63,237,63,18,57,57,49,
48,56,56,56,56,1,93,37,6,35,34,2,53,16,0,51,50,23,55,51,2,21,16,19,35,38,1,34,6,21,20,22,51,50,54,53,52,38,3,184,137,235,227,249,1,4,222,244,117,44,195,71,84,202,31,254,166,146,160,158,148,146,161,149,
192,220,1,52,227,1,7,1,54,197,180,254,252,254,254,223,254,252,113,3,61,218,203,185,226,209,212,186,225,0,0,2,0,104,255,228,4,142,6,20,0,31,0,43,0,140,64,14,87,27,101,18,103,28,3,57,1,59,17,2,36,40,184,
255,240,64,21,2,34,42,16,2,117,18,197,18,2,18,0,189,0,203,0,2,0,41,3,32,184,2,107,181,30,30,23,9,8,11,187,2,107,0,6,0,38,2,107,178,23,11,14,184,2,105,181,3,3,26,8,8,41,184,2,105,179,20,74,45,35,184,2,
105,181,26,73,44,96,133,24,43,78,16,244,77,237,78,16,246,77,237,51,47,17,51,47,237,0,63,237,47,237,51,50,18,57,47,237,1,17,18,57,93,0,17,51,93,49,48,23,56,23,56,1,93,0,93,1,46,1,53,52,54,51,50,23,21,38,
35,34,6,21,20,22,23,22,18,21,20,0,35,34,0,53,52,62,1,51,50,23,34,6,21,20,22,51,50,54,53,52,38,2,140,159,99,198,174,124,107,123,64,99,112,62,84,244,177,254,231,253,238,254,222,134,200,123,36,44,158,171,
175,150,138,181,155,3,174,123,158,84,116,133,31,132,20,71,55,43,82,67,191,254,244,156,215,254,219,1,32,225,151,201,113,109,196,168,171,198,187,180,154,212,0,0,1,0,104,255,228,3,175,4,56,0,24,0,86,64,10,
35,20,52,20,134,6,134,21,4,17,184,2,106,64,9,159,19,175,19,2,19,19,8,22,184,2,106,178,2,11,14,184,2,106,179,8,6,16,19,184,2,105,64,14,5,10,242,17,242,24,74,26,5,73,25,96,133,24,43,78,16,228,16,246,77,
230,230,16,253,50,0,63,237,63,237,18,57,47,93,237,49,48,0,93,5,6,35,32,0,17,52,0,33,50,23,21,39,38,35,32,3,33,21,33,30,1,51,50,55,3,175,102,95,254,212,254,170,1,51,1,47,100,116,26,129,51,254,146,41,2,
93,253,161,3,222,233,96,74,12,16,1,29,1,10,242,1,59,14,147,2,9,254,192,141,152,195,16,0,0,2,0,104,255,228,5,79,4,56,0,17,0,28,0,122,64,19,161,0,177,0,195,0,3,7,10,1,71,10,151,9,246,10,3,21,25,184,255,
240,181,2,19,27,16,2,23,190,2,107,0,5,0,18,2,107,0,12,0,17,2,106,182,15,15,12,6,5,11,26,184,2,105,64,10,32,2,1,2,2,8,16,74,30,20,184,2,105,182,15,8,1,8,73,29,96,185,1,111,0,24,43,78,16,244,113,77,237,
78,16,230,17,57,47,93,77,237,0,63,63,51,47,237,16,237,16,237,49,48,23,56,23,56,0,93,113,1,93,1,22,21,20,0,35,34,0,17,16,0,51,50,23,22,23,33,21,37,32,17,20,22,51,50,54,53,52,38,3,251,142,254,236,250,246,
254,227,1,27,221,42,114,44,88,1,207,253,49,254,182,162,158,165,159,151,3,144,136,247,253,254,208,1,41,1,3,1,2,1,38,8,4,4,152,43,254,69,180,224,226,203,181,237,0,1,0,41,0,0,3,173,4,39,0,7,0,55,177,2,7,
184,2,106,64,10,0,5,10,0,6,1,1,0,0,4,184,2,104,182,0,5,1,5,5,9,8,186,2,79,1,111,0,24,43,17,18,57,47,93,237,51,47,50,47,0,63,63,16,253,60,49,48,19,33,21,33,17,35,17,33,41,3,132,254,159,194,254,159,4,39,
160,252,121,3,135,0,3,0,104,254,125,5,196,5,52,0,18,0,25,0,30,0,153,64,20,151,4,151,7,152,16,167,4,167,7,168,16,6,120,17,136,17,2,24,28,184,255,240,183,2,21,30,16,2,25,9,27,184,2,107,179,12,19,2,26,184,
2,107,64,20,18,0,0,18,11,12,11,18,6,0,125,25,125,11,1,125,27,125,10,23,187,2,105,0,15,0,29,2,105,64,14,0,5,1,5,5,16,15,1,15,15,1,15,15,10,184,2,104,64,9,16,11,32,11,2,11,11,32,31,17,18,57,47,93,237,51,
47,93,113,50,47,93,237,16,237,16,230,228,16,228,228,0,63,63,47,17,51,47,16,237,51,50,16,237,51,50,49,48,23,56,23,56,0,93,1,93,1,51,17,4,0,17,20,6,4,7,17,35,17,38,0,17,16,0,37,7,14,2,21,16,5,19,17,36,17,
16,2,186,188,1,13,1,65,110,254,231,201,190,246,254,168,1,64,1,18,2,132,164,85,1,125,190,1,124,5,52,254,255,4,254,246,254,252,174,228,154,4,254,140,1,117,2,1,1,1,36,1,14,1,4,10,136,5,88,183,131,254,102,
2,3,51,252,205,3,1,155,1,144,0,0,2,255,244,254,86,4,12,255,110,0,3,0,7,0,60,185,0,7,2,110,64,14,0,5,16,5,32,5,48,5,64,5,5,5,5,1,184,2,110,64,14,3,5,1,4,0,1,74,9,0,73,8,206,134,24,43,78,16,236,16,238,16,
60,16,60,0,47,77,237,51,47,93,237,49,48,7,33,21,33,21,33,21,33,12,4,24,251,232,4,24,251,232,146,103,74,103,0,0,1,0,129,4,21,1,64,5,228,0,3,0,59,185,0,0,1,5,64,34,2,0,0,1,2,182,15,3,31,3,2,239,3,255,3,
2,3,3,0,1,16,1,32,1,3,224,1,240,1,2,1,1,5,4,17,18,57,47,93,113,51,47,93,113,237,17,51,0,63,253,49,48,19,35,19,51,232,103,43,148,4,21,1,207,0,0,2,0,48,4,21,2,116,5,228,0,3,0,7,0,72,179,1,5,2,5,184,1,5,
64,34,6,0,4,5,0,1,2,182,112,3,1,3,3,1,1,5,6,182,7,7,32,5,80,5,240,5,3,240,5,1,5,5,9,8,17,18,57,47,93,113,51,47,237,17,51,47,51,47,114,237,17,51,17,51,0,63,237,60,16,60,49,48,1,35,19,51,1,35,19,51,2,28,
104,44,148,254,36,104,43,148,4,21,1,207,254,49,1,207,0,4,0,179,255,228,3,140,5,228,0,3,0,7,0,19,0,31,0,69,188,0,6,1,42,0,20,0,2,1,42,64,31,8,20,124,26,8,124,14,7,0,3,0,26,11,14,11,23,155,5,127,6,155,29,
29,11,17,155,2,127,1,155,11,47,244,253,228,17,51,47,244,253,228,0,63,63,63,63,16,237,16,237,16,238,16,238,49,48,1,17,35,17,33,17,35,17,1,50,22,21,20,6,35,34,38,53,52,54,33,50,22,21,20,6,35,34,38,53,52,
54,1,117,145,2,115,144,254,103,49,74,73,50,50,73,74,2,20,50,73,73,50,51,72,72,5,228,251,140,4,116,251,140,4,116,250,248,70,54,52,72,73,51,54,70,72,52,52,72,73,51,52,72,0,0,1,0,76,2,63,2,141,4,249,0,21,
0,66,180,135,2,1,2,15,184,2,111,64,29,4,10,21,21,4,1,1,4,1,20,10,181,64,9,112,9,176,9,192,9,4,9,9,20,181,21,21,23,22,17,18,57,47,237,51,47,93,237,16,60,0,47,51,47,17,51,47,60,16,237,51,49,48,0,93,19,51,
21,54,51,50,30,1,21,17,35,17,52,46,1,35,34,14,1,29,1,35,76,115,93,129,82,118,40,115,20,72,57,66,105,27,115,4,232,97,114,96,133,119,254,162,1,70,106,99,61,95,118,126,253,0,0,2,0,178,255,228,8,80,5,212,
0,58,0,70,1,73,64,98,25,40,41,40,56,40,72,40,4,5,22,21,22,2,41,23,40,35,54,20,71,17,87,17,122,38,138,37,149,32,165,32,185,14,181,32,201,14,197,32,244,34,14,4,16,22,37,116,37,3,41,26,35,19,17,17,85,37,
35,20,37,37,35,220,37,236,37,2,35,37,30,7,180,19,196,19,2,19,17,24,12,35,37,33,39,19,17,21,15,9,10,27,0,28,16,28,2,28,184,2,49,64,9,30,15,10,31,10,47,10,3,10,184,2,49,64,56,12,60,94,51,51,53,54,42,46,
4,46,144,0,6,59,94,54,2,2,0,12,88,7,7,30,88,24,11,44,10,53,10,66,112,64,46,15,0,31,0,47,0,63,0,79,0,95,0,111,0,127,0,143,0,9,0,184,2,112,178,128,2,44,184,1,133,64,38,3,128,43,1,43,43,52,27,15,105,41,39,
178,28,27,27,21,10,9,9,125,33,105,21,74,72,60,52,101,47,53,1,53,73,71,103,152,24,43,78,16,244,93,77,253,60,78,16,246,77,237,244,47,51,17,51,47,51,244,50,237,17,18,57,47,93,60,253,60,26,254,93,50,26,237,
0,63,63,63,237,63,237,63,63,237,63,237,60,16,60,17,18,57,47,237,16,228,93,16,244,93,50,17,51,1,17,18,57,57,17,18,57,57,0,17,18,57,57,93,17,18,57,57,93,135,14,46,43,135,14,125,196,49,48,1,56,0,113,93,1,
93,113,1,51,17,51,17,33,54,51,50,23,7,38,35,34,6,21,20,22,23,30,1,21,20,6,35,34,38,39,55,22,51,50,54,53,52,38,39,46,1,53,52,55,35,17,35,17,35,14,2,43,1,17,35,17,33,50,30,1,37,17,22,51,50,62,1,53,52,46,
1,35,4,73,75,141,1,124,62,70,154,148,90,108,111,61,104,76,132,141,126,180,150,100,168,52,88,107,120,77,124,84,130,134,119,34,248,141,90,33,150,221,248,105,147,1,37,242,217,165,252,254,220,25,168,141,66,
80,136,144,4,64,1,148,254,108,28,147,93,109,84,66,51,97,68,73,145,109,126,194,87,67,100,121,102,79,64,92,67,70,141,108,75,65,252,56,3,200,116,127,41,253,84,5,191,49,190,96,254,12,3,66,124,64,72,127,50,
0,4,0,46,255,219,6,201,5,228,0,21,0,25,0,37,0,49,0,227,64,58,124,5,117,7,121,40,118,42,118,46,121,48,139,5,133,7,139,40,132,42,132,46,139,48,155,5,148,7,154,40,148,42,148,46,154,48,18,6,30,9,36,22,30,
25,36,168,15,184,15,203,2,203,10,8,23,24,25,25,184,2,113,64,15,22,23,20,22,22,23,12,11,11,14,0,1,1,20,38,184,2,111,178,26,26,44,184,2,111,181,32,11,25,22,11,9,184,2,111,178,14,14,3,184,2,111,64,49,20,
24,23,1,20,1,24,23,29,35,25,22,12,17,41,181,160,35,176,35,2,35,35,29,1,0,11,12,0,0,12,12,6,181,17,47,181,16,29,32,29,2,29,29,50,17,17,51,50,17,18,57,47,17,57,47,93,237,16,237,51,47,51,47,17,51,17,51,17,
51,47,93,237,17,18,57,57,17,18,57,57,0,63,63,60,16,237,51,47,237,63,60,63,237,51,47,237,17,51,47,51,17,51,47,51,135,5,46,43,135,125,196,49,48,1,93,0,93,1,7,38,35,34,6,21,20,22,51,50,55,23,6,35,34,38,53,
52,54,51,50,3,1,51,9,1,50,22,21,20,6,35,34,38,53,52,54,23,34,6,21,20,22,51,50,54,53,52,38,2,178,94,72,132,105,125,129,101,127,78,93,101,200,166,177,198,152,198,221,3,156,111,252,99,3,163,140,183,181,142,
138,184,183,139,83,122,118,87,88,118,122,5,56,53,118,153,96,104,150,118,56,166,222,129,152,211,249,247,6,9,249,247,2,223,215,144,143,213,210,146,145,214,111,147,103,103,143,143,103,103,147,0,0,2,0,41,
255,232,2,160,5,211,0,25,0,35,0,150,64,38,40,10,88,10,105,10,105,27,137,27,153,27,6,100,26,115,26,130,26,3,152,24,168,24,185,24,181,28,198,1,200,24,194,27,232,24,8,26,184,255,192,64,47,0,24,1,11,26,5,
187,25,203,25,2,123,25,139,25,2,25,25,5,17,18,14,88,20,11,32,32,5,1,25,0,207,29,1,31,29,1,29,29,31,8,1,8,0,0,35,12,184,2,114,64,11,2,0,23,1,23,17,17,80,8,1,8,47,93,51,47,47,113,60,253,60,51,47,17,93,51,
47,93,113,17,51,0,63,51,47,63,237,51,50,18,57,47,93,113,23,51,49,48,56,0,93,114,1,93,19,55,17,52,54,51,50,22,21,20,2,7,17,20,22,51,50,55,21,6,35,34,38,61,1,7,19,62,1,53,52,38,35,34,6,21,41,177,120,111,
107,116,122,163,26,30,52,147,104,121,97,102,79,248,91,54,45,31,42,27,1,166,235,1,199,222,157,140,95,96,254,244,227,254,97,83,49,107,162,87,118,123,225,98,2,43,157,133,62,60,60,101,144,0,0,1,0,79,0,157,
7,176,3,108,0,13,0,99,64,56,56,3,72,3,170,3,185,3,4,119,13,1,12,11,4,6,16,1,1,1,1,4,31,8,1,8,8,6,15,4,31,4,2,4,4,6,9,8,0,1,6,6,3,3,1,8,8,1,1,11,5,5,31,11,1,11,47,93,51,47,18,57,47,51,47,17,57,47,51,47,
17,51,17,51,0,47,51,47,93,17,51,47,93,17,51,47,93,17,18,57,57,49,48,0,93,1,113,1,51,6,7,33,21,33,22,23,35,38,39,53,54,1,236,76,81,114,6,59,249,197,102,96,78,223,191,177,3,108,170,139,101,102,207,253,88,
45,71,0,0,1,0,153,254,83,3,104,5,183,0,13,0,104,64,59,55,11,182,11,2,103,1,119,1,2,8,8,11,11,13,5,6,0,13,6,6,13,13,2,10,10,2,3,2,9,10,6,13,16,6,1,6,9,13,10,15,9,1,9,9,128,10,144,10,192,10,3,32,10,1,10,
10,15,14,17,18,57,47,93,113,51,47,93,17,51,17,51,93,47,47,17,18,57,57,0,47,51,47,18,57,47,51,47,17,51,17,51,17,57,47,51,47,49,48,0,93,113,19,36,55,51,22,23,21,38,39,17,35,17,6,7,153,1,6,71,46,87,253,207,
102,101,139,170,4,26,236,177,192,223,77,96,101,249,195,6,61,114,81,0,0,1,0,79,0,157,7,176,3,108,0,13,0,100,64,57,54,11,69,11,182,11,3,103,1,119,1,2,2,3,10,8,16,13,1,13,13,10,31,6,1,6,6,8,15,10,31,10,2,
10,10,8,5,6,0,13,11,11,8,8,3,6,13,13,6,6,9,3,3,31,9,1,9,47,93,51,47,18,57,47,51,47,17,18,57,47,51,47,17,51,17,51,0,47,51,47,93,17,51,47,93,17,51,47,93,17,18,57,57,49,48,1,93,113,1,18,23,21,6,7,35,54,55,
33,53,33,38,39,6,19,237,176,191,223,77,95,102,249,197,6,59,114,81,3,108,254,250,71,45,88,253,207,102,101,139,170,0,1,0,153,254,83,3,104,5,183,0,13,0,108,64,62,56,3,72,3,185,3,3,104,13,120,13,2,6,6,3,3,
12,1,9,8,0,1,8,8,1,1,4,12,12,4,11,12,5,4,8,1,16,8,1,8,5,1,4,15,5,1,5,5,128,4,144,4,192,4,3,32,4,1,4,4,15,14,17,18,57,47,93,113,51,47,93,17,51,17,51,93,47,47,17,18,57,57,0,47,51,47,18,57,47,51,47,17,51,
17,51,17,18,57,47,51,47,49,48,0,93,113,23,53,22,23,17,51,17,54,55,21,6,7,35,38,153,170,139,101,102,207,253,87,46,71,16,76,81,114,6,62,249,194,102,95,77,223,191,176,0,1,0,79,0,158,7,176,3,110,0,23,0,137,
64,78,54,6,54,19,70,6,70,19,4,118,2,118,23,2,0,1,12,13,4,18,6,21,16,16,1,16,16,18,9,31,4,1,4,4,6,15,18,31,18,2,18,18,6,10,9,15,16,18,18,7,7,12,9,9,16,16,12,3,4,22,21,19,19,6,6,1,4,21,21,4,4,12,1,1,31,
12,1,12,47,93,51,47,18,57,47,51,47,17,18,57,47,51,47,17,51,17,51,17,57,47,51,47,18,57,47,51,47,17,51,17,51,0,47,51,47,93,17,51,47,93,60,17,51,47,93,60,17,18,23,57,49,48,1,93,113,1,21,6,3,35,54,55,33,22,
23,35,2,39,53,54,19,51,6,7,33,38,39,51,18,7,176,181,225,80,69,125,250,231,125,69,80,224,182,182,224,80,69,125,5,25,125,69,80,225,2,28,45,79,254,254,172,139,139,172,1,2,79,45,79,1,3,172,139,139,172,254,
253,0,0,1,0,152,254,85,3,103,5,183,0,23,0,155,64,90,54,6,54,19,70,6,70,19,4,119,2,119,23,2,22,21,3,19,19,6,6,4,0,21,21,4,4,0,18,18,7,7,13,10,9,15,16,16,9,9,0,13,13,0,21,21,16,4,4,9,13,12,0,1,4,7,18,31,
16,1,16,9,16,9,1,9,7,16,18,15,7,31,7,2,7,7,128,18,144,18,192,18,3,32,18,1,18,18,25,24,17,18,57,47,93,113,51,47,93,17,51,17,51,93,47,47,93,17,18,23,57,17,51,47,17,51,47,0,47,51,47,18,57,47,51,47,51,17,
51,18,57,47,51,47,17,57,47,51,47,17,18,57,47,51,47,50,17,51,49,48,0,93,113,1,51,22,5,21,38,39,17,54,55,21,4,7,35,38,37,53,22,23,17,6,7,53,36,1,233,45,79,1,2,171,140,140,171,254,254,79,45,79,254,254,171,
140,140,171,1,2,5,183,182,225,80,69,126,250,230,126,68,79,225,182,182,225,79,68,126,5,26,126,69,80,225,0,0,2,0,152,253,148,3,103,5,183,0,23,0,27,0,181,64,105,54,6,54,19,70,6,70,19,4,119,2,119,23,2,22,
21,3,19,19,6,6,4,0,21,21,4,4,0,18,18,7,7,10,9,15,16,16,9,9,13,0,0,26,16,26,2,26,26,24,24,13,13,0,25,25,9,24,24,16,21,21,16,4,4,9,13,12,0,1,4,7,18,31,16,1,16,9,16,9,1,9,7,16,18,15,7,31,7,2,7,7,128,18,144,
18,192,18,3,32,18,1,18,18,29,28,17,18,57,47,93,113,51,47,93,17,51,17,51,93,47,47,93,17,18,23,57,17,51,47,17,51,47,17,51,47,17,51,47,0,47,51,47,51,47,51,47,93,17,18,57,47,51,47,51,17,51,57,47,51,47,17,
57,47,51,47,17,18,57,47,51,47,50,17,51,49,48,0,93,113,1,51,22,5,21,38,39,17,54,55,21,4,7,35,38,37,53,22,23,17,6,7,53,36,1,33,21,33,1,233,45,79,1,2,171,140,140,171,254,254,79,45,79,254,254,171,140,140,
171,1,2,255,0,2,205,253,51,5,183,182,225,80,69,126,250,230,126,68,79,225,182,182,225,79,68,126,5,26,126,69,80,225,248,245,98,0,1,1,106,0,0,6,107,4,255,0,5,0,39,64,22,15,2,31,2,2,2,2,5,0,15,2,31,2,2,2,
2,5,4,95,5,1,5,47,93,47,17,51,47,93,0,47,47,51,47,93,49,48,1,51,17,33,21,33,1,106,100,4,157,250,255,4,255,251,101,100,0,0,1,0,129,0,0,4,54,5,212,0,27,0,97,64,67,40,20,40,24,57,20,57,24,70,7,70,11,137,
19,137,25,215,7,215,11,10,16,10,1,10,15,22,31,22,47,22,3,255,22,1,22,22,9,3,48,16,1,0,16,1,16,16,15,15,28,15,0,1,0,0,240,1,1,224,1,240,1,2,1,1,29,28,17,18,57,47,93,114,51,47,93,17,57,47,51,47,93,113,0,
63,51,47,93,113,63,63,49,48,0,93,51,35,17,55,62,4,51,50,30,2,25,1,35,17,52,46,2,35,34,14,2,21,239,110,2,1,35,82,130,149,75,118,214,116,27,110,20,84,171,90,90,169,83,22,2,109,238,116,186,152,119,60,137,
211,237,254,226,253,147,2,116,243,211,169,110,110,164,215,244,0,3,0,115,1,10,4,103,4,181,0,3,0,7,0,11,0,56,178,10,127,8,184,1,57,179,6,0,127,2,184,1,57,64,17,6,127,4,10,7,2,9,6,1,74,13,2,73,12,95,113,
24,43,78,16,228,16,246,60,60,16,60,60,0,47,77,237,254,237,16,254,237,49,48,1,21,33,53,17,33,21,33,1,21,33,53,4,103,252,12,3,244,252,12,3,244,252,12,4,181,137,137,254,111,137,254,248,137,137,0,0,2,0,146,
0,0,4,66,3,176,0,3,0,7,0,43,64,19,7,7,0,5,5,3,6,6,2,5,5,3,2,2,8,3,3,9,8,17,18,57,47,17,57,47,17,51,47,17,51,47,0,47,51,47,47,51,47,49,48,19,33,17,33,19,17,33,17,146,3,176,252,80,76,3,24,3,176,252,80,3,
100,252,232,3,24,0,0,1,0,131,1,189,2,82,3,141,0,3,0,51,64,33,47,0,175,0,223,0,239,0,4,143,0,191,0,207,0,3,0,0,2,1,1,4,0,2,32,2,48,2,3,2,2,5,4,17,18,57,47,93,17,57,47,0,47,51,47,113,93,49,48,1,17,33,17,
2,82,254,49,3,141,254,48,1,207,0,0,2,0,131,1,189,2,82,3,141,0,3,0,7,0,69,64,42,5,5,47,3,175,3,223,3,239,3,4,143,3,191,3,207,3,3,3,3,2,6,6,2,7,7,1,1,8,6,6,0,2,32,2,48,2,3,2,2,9,8,17,18,57,47,93,51,47,17,
57,47,51,47,0,47,51,47,17,51,47,113,93,51,47,49,48,1,17,33,17,13,1,17,33,2,82,254,49,1,131,254,201,1,55,3,141,254,48,1,207,75,1,254,201,0,0,1,0,178,0,137,4,35,3,250,0,11,0,57,64,39,143,0,175,0,191,0,3,
31,0,63,0,191,0,223,0,239,0,255,0,6,111,0,127,0,143,0,255,0,4,0,0,6,3,3,12,9,9,13,12,17,18,57,47,17,57,47,0,47,51,47,93,113,114,49,48,1,50,0,21,20,0,35,34,0,53,52,36,2,107,181,1,3,254,254,182,182,254,
253,1,7,3,250,254,254,182,182,254,253,1,3,182,189,251,0,0,2,0,112,1,170,2,102,3,160,0,11,0,23,0,99,64,65,12,12,0,18,18,6,15,0,31,0,63,0,79,0,95,0,239,0,6,15,0,31,0,2,223,0,255,0,2,9,15,0,31,0,2,58,0,0,
6,21,21,0,3,1,3,3,24,15,15,32,9,48,9,64,9,3,32,9,48,9,2,9,9,25,24,17,18,57,47,93,113,51,47,17,57,47,93,51,47,0,47,51,47,94,93,94,93,113,114,17,51,47,17,51,47,49,48,1,50,22,21,20,6,35,34,38,53,52,54,23,
34,6,21,20,22,51,50,54,53,52,38,1,107,101,150,147,104,104,147,148,103,71,104,103,72,72,103,104,3,160,144,107,104,147,147,104,104,147,76,100,75,73,102,102,73,74,101,0,0,1,0,176,253,250,1,192,255,135,0,
3,0,35,178,3,1,2,184,1,165,64,10,0,0,2,3,1,1,3,3,5,4,17,18,57,47,51,47,18,57,57,0,47,237,57,57,49,48,5,23,3,39,1,70,122,183,89,121,57,254,172,38,0,255,255,0,49,0,0,5,186,6,240,2,54,0,36,0,0,1,23,0,218,
1,4,1,41,0,10,182,2,0,14,13,7,0,51,43,53,255,255,0,107,255,228,4,216,5,199,2,54,0,68,0,0,1,23,0,218,0,203,0,0,0,17,64,10,2,34,34,2,0,35,34,0,0,51,43,53,0,63,53,0,255,255,0,111,255,219,6,13,7,48,2,54,0,
38,0,0,1,23,0,216,1,102,1,42,0,17,64,10,1,32,32,1,0,33,29,24,24,51,43,53,0,63,53,0,255,255,0,105,255,228,4,188,6,6,2,54,0,70,0,0,1,23,0,216,0,150,0,0,0,17,64,10,1,32,34,1,0,31,31,3,3,51,43,53,0,63,53,
0,255,255,0,111,255,219,6,13,7,24,2,54,0,38,0,0,1,23,0,220,2,138,1,42,0,17,64,10,1,32,32,1,0,36,30,21,0,51,43,53,0,63,53,0,255,255,0,105,255,228,4,188,5,238,2,54,0,70,0,0,1,23,0,220,1,199,0,0,0,17,64,
10,1,32,34,1,0,36,30,19,0,51,43,53,0,63,53,0,255,255,0,180,0,0,3,255,6,240,2,54,0,40,0,0,1,23,0,218,0,100,1,41,0,10,182,1,0,15,14,0,1,51,43,53,255,255,0,104,255,228,4,202,5,199,2,54,0,72,0,0,1,23,0,218,
0,168,0,0,0,15,64,10,2,47,36,1,0,36,35,8,16,51,43,93,53,0,255,255,0,180,0,0,3,255,7,31,2,54,0,40,0,0,1,23,0,219,0,85,1,42,0,17,64,10,1,23,32,1,0,12,20,0,1,51,43,53,0,63,53,0,255,255,0,104,255,228,4,202,
5,245,2,54,0,72,0,0,1,23,0,219,0,201,0,0,0,21,64,13,2,44,34,2,47,33,1,0,33,41,8,16,51,43,93,53,0,63,53,0,255,255,0,180,0,0,3,255,7,24,2,54,0,40,0,0,1,23,0,220,1,118,1,42,0,17,64,10,1,18,32,1,0,21,15,0,
1,51,43,53,0,63,53,0,255,255,0,104,255,228,4,202,5,238,2,54,0,72,0,0,1,23,0,220,1,181,0,0,0,21,64,13,2,39,34,2,47,42,1,0,42,36,8,16,51,43,93,53,0,63,53,0,255,255,0,117,255,219,6,149,7,48,2,54,0,42,0,0,
1,23,0,216,1,131,1,42,0,17,64,10,1,37,32,1,0,38,34,25,18,51,43,53,0,63,53,0,255,255,0,100,254,86,4,210,6,6,2,54,0,74,0,0,1,23,0,216,0,152,0,0,0,17,64,10,2,54,34,2,0,55,51,27,1,51,43,53,0,63,53,0,255,255,
0,117,255,219,6,149,7,24,2,54,0,42,0,0,1,23,0,220,2,173,1,42,0,17,64,10,1,38,32,1,0,41,35,25,18,51,43,53,0,63,53,0,255,255,0,100,254,86,4,210,5,238,2,54,0,74,0,0,1,23,0,220,1,208,0,0,0,17,64,10,2,55,34,
2,0,58,52,27,1,51,43,53,0,63,53,0,255,255,0,117,254,132,6,149,5,228,2,54,0,42,0,0,0,23,0,222,2,49,0,0,255,255,0,100,254,86,4,210,7,26,2,54,0,74,0,0,1,23,0,182,1,52,1,54,0,17,64,10,2,55,34,2,0,56,55,27,
1,51,43,53,0,63,53,0,255,255,0,177,0,0,4,197,7,48,2,54,0,43,0,0,1,23,0,216,0,185,1,42,0,17,64,10,1,15,32,1,0,18,14,0,5,51,43,53,0,63,53,0,255,255,0,156,0,0,4,81,7,48,2,54,0,75,0,0,1,23,0,216,0,110,1,42,
0,17,64,10,1,31,32,1,0,31,27,0,10,51,43,53,0,63,53,0,0,2,0,45,0,0,5,74,5,191,0,19,0,23,0,103,64,57,4,17,0,94,6,15,20,20,18,21,21,94,11,11,18,9,13,8,2,18,2,22,4,1,3,8,9,18,19,21,3,12,13,9,101,80,8,1,8,
74,25,9,15,25,1,8,12,101,95,13,1,13,73,24,102,174,24,43,78,16,244,93,77,237,94,93,94,78,16,246,93,77,237,17,18,23,57,17,18,23,57,0,63,60,63,60,18,57,47,253,17,18,57,47,60,60,253,60,60,49,48,1,33,53,51,
21,51,21,35,17,35,17,33,17,35,17,35,53,51,53,51,17,21,33,53,1,70,2,235,148,133,133,148,253,21,148,133,133,148,2,235,4,215,232,232,138,251,179,2,198,253,58,4,77,138,232,254,142,247,247,0,1,0,4,0,0,4,81,
5,228,0,30,0,122,64,81,147,4,1,80,8,96,8,193,7,192,8,195,19,5,124,4,124,20,2,140,4,140,20,2,27,0,88,25,3,3,6,30,30,0,17,88,0,6,16,6,32,6,3,6,7,12,24,10,0,4,28,3,23,24,12,92,191,10,207,10,223,10,3,10,74,
32,23,92,176,24,192,24,208,24,3,24,73,31,123,118,24,43,78,16,244,93,77,237,78,16,246,93,77,237,17,18,23,57,0,63,60,63,93,237,63,17,18,57,47,60,253,60,93,93,49,48,1,93,0,93,1,33,21,33,17,54,51,50,30,1,
21,17,35,17,52,46,1,35,34,14,2,21,17,35,17,35,53,51,53,51,1,40,1,118,254,138,169,238,142,198,62,140,41,137,111,96,152,101,31,140,152,152,140,5,76,116,254,165,223,157,211,188,253,208,2,7,189,170,109,88,
148,157,195,254,113,4,216,116,152,0,255,255,255,121,0,0,2,86,7,24,2,54,0,44,0,0,1,23,0,217,255,38,1,42,0,17,64,10,1,8,32,1,0,18,5,0,1,51,43,53,0,63,53,0,255,255,255,94,0,0,2,59,5,238,2,54,0,215,0,0,1,
23,0,217,255,11,0,0,0,17,64,10,1,8,34,1,0,18,5,0,1,51,43,53,0,63,53,0,255,255,255,143,0,0,2,65,6,240,2,54,0,44,0,0,1,23,0,218,254,247,1,41,0,10,182,1,0,7,5,0,1,51,43,53,255,255,255,116,0,0,2,38,5,199,
2,54,0,215,0,0,1,23,0,218,254,220,0,0,0,10,182,1,0,4,5,0,1,51,43,53,255,255,255,133,0,0,2,74,7,31,2,54,0,44,0,0,1,23,0,219,255,23,1,42,0,17,64,10,1,15,32,1,0,4,12,0,1,51,43,53,0,63,53,0,255,255,255,107,
0,0,2,48,5,245,2,54,0,215,0,0,1,23,0,219,254,253,0,0,0,17,64,10,1,15,34,1,0,4,12,0,1,51,43,53,0,63,53,0,255,255,0,77,254,119,1,143,5,191,2,54,0,44,0,0,1,22,0,224,143,0,0,10,182,1,0,5,5,2,2,51,43,53,255,
255,0,48,254,119,1,114,6,0,2,54,0,76,0,0,1,23,0,224,255,114,0,0,0,10,182,2,0,17,17,14,14,51,43,53,255,255,0,86,255,219,3,220,7,48,2,54,0,45,0,0,1,23,0,216,0,111,1,42,0,17,64,10,1,22,32,1,0,22,22,1,1,51,
43,53,0,63,53,0,0,2,255,101,254,86,2,59,6,6,0,6,0,20,0,166,64,34,55,5,1,3,4,4,85,1,2,20,1,1,2,5,4,4,85,0,6,20,0,0,6,1,4,0,3,5,2,6,0,214,64,4,184,1,44,64,10,13,2,6,0,4,1,3,3,5,3,184,2,64,183,160,2,176,
2,192,2,3,2,186,1,10,0,5,2,64,64,27,47,6,63,6,159,6,175,6,4,6,6,7,6,16,88,11,15,14,14,7,22,118,8,92,7,139,21,16,246,253,230,17,51,47,0,63,237,63,1,51,47,93,49,48,237,253,93,237,17,18,23,57,0,47,60,75,
81,88,176,128,26,89,77,252,26,237,17,18,57,57,17,18,57,135,14,46,43,5,125,16,196,135,14,46,24,43,5,125,16,196,49,48,1,113,19,51,1,35,39,7,35,5,51,17,16,35,34,39,53,22,51,50,62,1,53,142,139,1,34,180,176,
184,186,1,38,142,185,74,86,54,48,38,49,14,6,6,254,255,152,152,197,251,28,254,250,34,126,29,42,55,75,0,255,255,0,179,254,132,4,146,5,191,2,54,0,46,0,0,1,23,2,152,1,5,0,0,0,10,182,1,0,25,25,10,7,51,43,53,
255,255,0,155,254,132,4,16,5,228,2,54,0,78,0,0,1,23,2,152,0,186,0,0,0,10,182,1,0,25,25,10,7,51,43,53,0,1,0,155,0,0,4,16,4,64,0,10,0,184,64,80,216,7,1,9,0,4,1,6,2,1,67,217,5,1,9,4,5,1,96,6,5,1,54,8,8,7,
2,1,2,3,3,2,2,91,5,4,20,5,5,4,7,8,8,91,5,6,20,5,5,6,2,8,5,7,9,6,10,3,1,4,0,5,5,10,4,6,0,6,6,10,10,5,0,1,2,8,4,9,10,3,184,2,47,178,4,178,7,184,2,47,64,14,6,74,12,32,12,1,9,92,10,73,11,123,185,24,43,78,
16,244,77,237,93,78,16,246,77,237,244,237,17,18,23,57,50,0,63,60,63,63,18,57,47,17,18,57,57,17,18,57,57,17,51,51,135,46,43,5,125,16,196,135,4,46,24,43,5,125,16,196,3,8,16,60,8,60,49,48,1,94,93,94,93,94,
0,93,94,93,1,93,94,93,19,51,17,1,51,9,1,35,1,17,35,155,141,1,247,206,253,171,2,120,198,253,222,141,4,64,254,74,1,182,253,249,253,199,1,233,254,23,255,255,0,179,254,132,3,124,5,191,2,54,0,47,0,0,1,23,2,
152,0,175,0,0,0,15,64,10,1,15,24,1,0,24,10,5,4,51,43,93,53,0,255,255,255,239,254,132,1,102,5,228,2,54,0,79,0,0,0,22,2,152,129,0,255,255,0,180,254,132,5,55,5,191,2,54,0,49,0,0,1,23,2,152,1,169,0,0,0,10,
182,1,0,28,14,0,6,51,43,53,255,255,0,156,254,132,4,81,4,92,2,54,0,81,0,0,1,23,2,152,1,37,0,0,0,10,182,1,0,43,29,24,10,51,43,53,0,1,0,178,255,219,5,196,5,228,0,26,0,106,64,29,18,20,77,8,82,24,96,20,99,
24,117,20,135,4,140,7,129,24,156,2,156,8,11,150,2,147,5,2,17,184,255,240,64,36,12,9,122,17,19,3,15,2,13,10,1,1,3,122,25,0,0,25,11,1,1,0,0,13,6,112,22,131,28,17,17,13,101,14,102,27,16,244,253,50,47,16,
246,237,17,51,47,51,47,0,63,51,47,16,253,50,47,63,63,63,51,253,50,56,49,48,0,93,1,93,37,55,22,51,50,18,17,16,0,35,34,6,7,17,35,17,51,21,54,33,32,0,17,16,0,35,34,2,17,105,103,159,185,241,254,201,227,136,
243,79,148,148,197,1,26,1,40,1,119,254,178,251,219,151,91,140,1,112,1,13,1,18,1,100,141,109,251,161,5,191,178,215,254,62,254,181,254,176,254,84,0,1,0,156,254,86,4,81,4,92,0,32,0,99,185,0,2,255,192,64,
34,9,17,57,2,20,2,31,83,20,83,31,99,20,99,31,6,75,15,127,19,125,20,125,27,139,19,142,27,6,20,18,17,88,27,184,255,240,64,25,27,29,7,26,6,8,88,3,15,24,10,6,6,12,92,1,118,34,27,27,23,92,24,123,33,16,246,
253,50,47,16,246,253,50,47,0,63,63,237,63,63,51,56,237,17,51,49,48,0,93,1,93,43,1,17,16,35,34,39,53,22,51,50,62,1,53,17,52,46,1,35,34,14,2,21,17,35,17,51,21,54,51,50,30,1,4,81,187,72,85,53,48,40,49,15,
42,137,111,96,152,101,31,140,140,168,239,141,197,64,2,48,253,44,254,250,34,126,29,42,55,75,2,130,189,170,109,88,148,157,195,254,113,4,64,195,223,155,212,255,255,0,115,255,219,6,128,6,241,2,54,0,50,0,0,
1,23,0,218,1,137,1,42,0,10,182,2,0,31,30,9,3,51,43,53,255,255,0,104,255,228,4,213,5,199,2,54,0,82,0,0,1,23,0,218,0,174,0,0,0,10,182,2,0,31,30,10,4,51,43,53,255,255,0,115,255,219,6,128,7,31,2,54,0,50,0,
0,1,23,0,219,1,169,1,42,0,17,64,10,2,39,32,2,0,28,36,9,3,51,43,53,0,63,53,0,255,255,0,104,255,228,4,213,5,245,2,54,0,82,0,0,1,23,0,219,0,206,0,0,0,17,64,10,2,39,34,2,0,28,36,10,4,51,43,53,0,63,53,0,255,
255,0,187,254,132,4,104,5,191,2,54,0,53,0,0,0,23,2,152,1,15,0,0,255,255,0,73,254,132,2,141,4,92,2,54,0,85,0,0,1,22,2,152,219,0,0,10,182,1,0,36,36,17,16,51,43,53,255,255,0,27,255,219,3,120,7,48,2,54,0,
54,0,0,1,23,0,216,255,252,1,42,0,17,64,10,1,48,32,1,0,49,45,15,22,51,43,53,0,63,53,0,255,255,0,35,255,228,2,249,6,6,2,54,0,86,0,0,1,22,0,216,140,0,0,17,64,10,1,44,34,1,0,45,41,34,14,51,43,53,0,63,53,0,
0,1,0,33,0,0,3,72,5,191,0,15,0,68,64,37,0,0,9,94,6,3,3,6,5,8,15,15,11,94,12,2,2,2,14,224,0,4,101,5,8,8,11,224,5,9,9,5,16,17,5,101,58,43,47,51,47,16,244,57,47,16,253,60,228,57,47,0,63,253,50,47,63,47,51,
47,16,253,50,47,49,48,1,33,21,33,17,35,17,33,53,33,17,33,53,33,21,33,2,0,1,24,254,232,150,254,231,1,25,254,183,3,39,254,184,3,9,138,253,129,2,127,138,2,39,143,143,0,0,1,0,63,0,0,2,153,5,212,0,19,0,99,
64,24,3,6,144,9,0,0,9,9,5,18,10,144,13,16,16,13,6,14,0,5,10,1,1,18,184,1,143,64,11,4,16,16,0,0,4,92,5,8,8,11,184,1,143,64,12,5,9,9,5,13,13,5,20,21,5,192,58,43,47,51,47,17,51,47,16,244,50,47,16,253,50,
47,50,47,16,244,50,47,0,63,63,63,51,47,16,253,60,17,57,47,51,47,16,253,60,49,48,1,51,21,35,17,35,17,35,53,51,17,35,53,51,17,51,17,51,21,35,1,163,246,246,140,216,216,192,192,140,222,222,2,95,116,254,21,
1,235,116,1,105,120,1,148,254,108,120,0,255,255,0,184,255,219,4,134,7,23,2,54,0,56,0,0,1,23,0,217,0,229,1,41,0,17,64,10,1,40,32,1,0,41,28,0,16,51,43,53,0,63,53,0,255,255,0,138,255,228,4,66,5,238,2,54,
0,88,0,0,1,23,0,217,0,173,0,0,0,17,64,10,1,37,34,1,0,38,25,0,14,51,43,53,0,63,53,0,255,255,0,184,255,219,4,134,6,241,2,54,0,56,0,0,1,23,0,218,0,173,1,42,0,10,182,1,0,27,28,0,16,51,43,53,255,255,0,138,
255,228,4,66,5,199,2,54,0,88,0,0,1,22,0,218,125,0,0,10,182,1,0,24,25,0,14,51,43,53,255,255,0,184,255,219,4,134,7,31,2,54,0,56,0,0,1,23,0,219,0,206,1,42,0,17,64,10,1,38,32,1,0,27,35,0,16,51,43,53,0,63,
53,0,255,255,0,138,255,228,4,66,5,245,2,54,0,88,0,0,1,23,0,219,0,158,0,0,0,17,64,10,1,35,34,1,0,24,32,0,14,51,43,53,0,63,53,0,255,255,0,184,254,119,4,134,5,191,2,54,0,56,0,0,0,23,0,224,1,115,0,0,255,255,
0,138,254,119,4,66,4,64,2,54,0,88,0,0,0,23,0,224,1,36,0,0,255,255,0,96,0,0,7,78,7,48,2,54,0,58,0,0,1,23,0,216,1,213,1,42,0,17,64,10,1,19,32,1,0,19,15,1,6,51,43,53,0,63,53,0,255,255,0,9,0,0,6,157,6,6,2,
54,0,90,0,0,1,23,0,216,1,81,0,0,0,17,64,10,1,19,34,1,0,19,15,0,7,51,43,53,0,63,53,0,255,255,0,63,0,0,4,125,7,48,2,54,0,60,0,0,1,23,0,216,0,92,1,42,0,17,64,10,1,14,32,1,0,15,11,8,5,51,43,53,0,63,53,0,255,
255,0,39,254,114,4,49,6,6,2,54,0,92,0,0,1,22,0,216,35,0,0,17,64,10,1,14,34,1,0,14,10,1,3,51,43,53,0,63,53,0,0,1,0,135,0,0,2,5,6,0,0,15,0,36,64,20,12,64,9,19,57,9,8,3,88,14,1,1,1,17,118,8,92,9,139,16,16,
246,253,228,51,47,0,63,237,63,49,48,1,43,1,21,38,35,34,14,1,21,17,35,17,52,62,1,51,50,2,5,74,58,44,59,7,140,27,107,85,72,5,228,137,33,40,61,68,251,45,4,174,151,107,80,255,255,0,49,0,0,5,186,8,122,2,54,
0,36,0,0,0,55,0,221,1,166,0,131,1,23,0,141,1,92,2,60,0,38,64,23,4,37,37,11,3,2,29,0,4,0,37,35,7,0,51,3,2,0,26,32,7,0,51,43,53,53,43,53,0,63,53,53,16,222,47,53,255,255,0,107,255,228,4,216,7,206,2,54,0,
68,0,0,0,55,0,221,1,105,255,215,1,23,0,141,1,37,1,144,0,45,64,27,4,58,58,32,3,2,15,38,1,38,38,12,4,0,59,57,9,0,51,3,2,0,41,35,9,0,51,43,53,53,43,53,0,16,222,47,93,53,53,16,222,47,53,0,255,255,0,1,0,0,
7,69,7,103,2,54,0,144,0,0,1,23,0,141,3,79,1,41,0,17,64,10,2,22,32,2,0,22,21,4,4,51,43,53,0,63,53,0,255,255,0,120,255,228,8,201,6,62,2,54,0,160,0,0,1,23,0,141,3,32,0,0,0,17,64,10,3,68,34,3,0,68,66,42,0,
51,43,53,0,63,53,0,255,255,0,114,255,153,6,127,7,104,2,54,0,145,0,0,1,23,0,141,1,249,1,42,0,17,64,10,3,42,32,3,0,42,40,17,17,51,43,53,0,63,53,0,255,255,0,102,255,173,4,211,6,62,2,54,0,161,0,0,1,23,0,141,
1,22,0,0,0,17,64,10,3,42,34,3,0,41,39,15,15,51,43,53,0,63,53,0,0,1,1,43,4,236,1,218,6,62,0,3,0,63,64,12,15,3,1,2,2,127,3,223,3,2,3,1,184,255,192,179,30,37,57,1,184,255,192,179,18,21,57,2,184,255,192,64,
10,35,40,57,1,1,2,0,2,0,3,47,51,51,47,47,50,47,43,43,43,0,47,93,51,47,93,49,48,1,3,35,3,1,218,28,118,29,6,62,254,174,1,82,0,3,0,52,4,236,2,209,6,62,0,3,0,15,0,27,0,115,177,10,22,184,1,141,64,13,4,16,16,
15,3,1,2,2,127,3,1,3,13,184,1,141,181,63,7,79,7,2,7,187,2,112,0,0,0,19,1,141,181,48,25,64,25,2,25,187,2,112,0,3,0,1,255,192,179,30,37,57,1,184,255,192,179,18,21,57,2,184,255,192,64,10,35,40,57,1,1,2,0,
2,0,3,47,51,51,47,47,50,47,43,43,43,16,246,93,237,16,246,93,237,0,47,93,51,47,93,51,47,51,253,50,49,48,1,3,35,3,1,34,38,53,52,54,51,50,22,21,20,6,33,34,38,53,52,54,51,50,22,21,20,6,1,218,28,118,29,1,78,
37,52,52,37,37,51,51,253,239,37,52,52,37,37,52,52,6,62,254,174,1,82,254,205,52,37,38,51,52,37,37,52,52,37,37,52,51,38,37,52,255,255,0,49,0,0,5,186,5,228,2,54,0,36,0,0,1,22,1,152,206,166,0,23,64,15,2,11,
0,2,32,12,112,12,2,0,12,12,6,7,51,43,93,53,0,63,53,0,0,1,0,187,3,100,1,177,4,92,0,11,0,24,64,13,207,3,1,3,124,9,7,192,0,1,0,164,6,47,237,93,0,63,237,93,49,48,1,20,6,35,34,38,53,52,54,51,50,22,1,177,71,
52,52,71,71,52,52,71,3,224,52,72,72,52,52,72,72,0,255,255,255,156,0,0,4,89,5,228,0,54,0,40,90,0,1,23,1,152,254,113,255,166,0,35,64,23,1,12,0,1,15,15,31,15,32,15,79,15,111,15,144,15,6,15,0,10,10,175,17,
16,246,47,53,47,93,53,0,63,53,0,255,255,255,156,0,0,5,31,5,228,0,54,0,43,90,0,1,23,1,152,254,113,255,166,0,37,64,24,1,12,0,1,15,15,32,15,111,15,127,15,144,15,5,15,0,80,6,1,6,6,174,17,16,246,47,93,53,47,
93,53,0,63,53,0,255,255,255,156,0,0,1,139,5,228,0,54,0,44,90,0,1,23,1,152,254,113,255,166,0,43,64,29,1,4,0,1,208,4,1,32,4,48,4,79,4,111,4,144,4,5,4,0,2,2,174,9,15,9,111,9,2,93,16,246,47,53,47,93,113,53,
0,63,53,0,255,255,255,156,255,219,6,128,5,228,0,38,0,50,0,0,1,7,1,152,254,113,255,166,0,26,64,18,2,28,0,2,15,28,31,28,32,28,79,28,111,28,144,28,6,28,47,93,53,0,63,53,255,255,255,156,0,0,4,235,5,228,0,
54,0,60,110,0,1,23,1,152,254,113,255,166,0,47,64,33,1,9,0,1,79,9,1,15,9,31,9,32,9,111,9,144,9,5,9,0,15,4,32,4,111,4,112,4,4,4,63,14,1,113,46,93,53,77,47,93,113,53,0,63,53,0,255,255,255,156,0,0,6,47,5,
228,0,54,1,186,0,0,1,23,1,152,254,113,255,166,0,26,64,18,1,32,0,1,15,32,31,32,32,32,79,32,111,32,144,32,6,32,47,93,53,0,63,53,255,255,255,127,0,0,2,28,6,62,2,54,0,215,0,0,1,23,1,153,255,75,0,0,0,15,64,
9,3,2,1,0,6,5,0,1,51,43,53,53,53,0,255,255,0,49,0,0,5,186,5,191,2,6,0,36,0,0,255,255,0,183,0,0,4,40,5,191,2,6,0,37,0,0,0,1,0,177,0,0,3,146,5,191,0,5,0,36,183,1,94,4,2,3,8,0,0,184,1,21,64,9,7,2,101,95,
3,1,3,102,6,16,246,93,237,16,246,47,0,63,63,237,49,48,1,33,17,35,17,33,3,146,253,177,146,2,225,5,46,250,210,5,191,0,0,2,0,49,0,0,5,186,5,191,0,3,0,6,0,127,64,47,119,6,1,3,5,2,60,5,4,5,6,4,86,0,3,20,0,
0,3,5,6,5,4,6,86,1,2,20,1,1,2,3,5,2,59,4,6,101,0,1,8,5,3,2,3,6,1,184,255,240,64,29,1,1,5,4,79,0,239,0,2,0,16,0,0,36,5,75,5,84,5,123,5,203,5,212,5,251,5,7,5,25,47,93,51,24,47,56,93,51,17,51,47,56,51,0,
63,51,51,63,51,253,50,43,135,5,46,43,8,125,16,196,135,5,46,24,43,8,125,16,196,43,93,49,48,41,1,1,51,9,2,5,186,250,119,2,183,36,1,203,254,35,254,31,5,191,250,210,3,246,252,10,255,255,0,180,0,0,3,255,5,
191,2,6,0,40,0,0,255,255,0,56,0,0,3,130,5,191,2,6,0,61,0,0,255,255,0,177,0,0,4,197,5,191,2,6,0,43,0,0,0,3,0,115,255,219,6,128,5,228,0,11,0,23,0,27,0,116,64,34,55,8,26,101,208,25,1,25,25,0,12,122,6,3,18,
122,0,9,24,24,15,25,25,15,21,112,9,131,29,15,112,3,120,28,16,246,237,16,244,237,17,57,47,17,57,47,0,63,237,63,237,17,57,47,93,237,49,48,67,121,64,42,1,23,19,11,21,100,1,17,1,15,100,0,23,7,21,100,1,13,
5,15,100,0,20,10,18,100,0,16,2,18,100,0,22,8,12,100,1,14,4,12,100,1,43,43,43,43,1,43,43,43,43,129,5,32,0,17,16,0,33,32,0,17,16,0,1,34,0,17,16,0,33,32,0,17,16,0,19,33,53,33,3,124,254,186,254,61,1,190,1,
63,1,77,1,195,254,65,254,182,248,254,141,1,102,1,5,1,5,1,108,254,123,135,253,31,2,225,37,1,187,1,67,1,70,1,197,254,71,254,181,254,187,254,64,5,121,254,151,254,238,254,251,254,150,1,102,1,16,1,35,1,81,
253,76,144,255,255,0,158,0,0,1,49,5,191,2,6,0,44,0,0,255,255,0,179,0,0,4,146,5,191,2,6,0,46,0,0,255,255,0,67,0,0,5,90,5,191,1,31,0,57,5,157,5,191,192,0,0,42,64,35,0,15,0,32,0,63,0,80,0,159,0,175,0,223,
0,7,0,0,8,1,15,8,32,8,63,8,80,8,128,8,176,8,224,8,7,93,113,46,93,53,255,255,0,112,0,0,6,234,5,191,2,6,0,48,0,0,255,255,0,180,0,0,5,55,5,191,2,6,0,49,0,0,0,3,0,115,0,0,3,204,5,191,0,3,0,7,0,11,0,44,64,
23,6,101,5,5,9,1,101,2,2,10,101,9,10,4,0,8,131,13,6,2,9,120,12,16,246,50,50,16,246,50,50,0,63,237,63,237,18,57,47,237,49,48,1,33,53,33,17,33,53,33,17,33,53,33,3,204,252,167,3,89,252,167,3,89,252,167,3,
89,5,46,145,253,19,144,252,158,145,0,255,255,0,115,255,219,6,128,5,228,2,6,0,50,0,0,0,1,0,177,0,0,4,197,5,191,0,7,0,40,64,23,3,94,6,2,1,4,8,1,101,80,0,1,0,174,9,4,101,94,5,1,5,102,8,16,246,93,237,16,246,
93,237,0,63,51,63,237,49,48,33,35,17,33,17,35,17,33,4,197,148,253,20,148,4,20,5,51,250,205,5,191,255,255,0,178,0,0,4,73,5,191,2,6,0,51,0,0,0,1,0,66,0,0,3,159,5,191,0,9,0,153,64,61,53,8,70,6,199,6,3,6,
3,2,2,86,7,6,20,7,2,1,7,6,2,2,3,7,8,8,94,1,2,20,1,1,2,2,2,31,7,1,7,7,8,5,5,6,94,4,3,2,8,8,9,101,1,0,8,2,7,7,0,6,3,184,255,240,182,43,3,1,3,3,8,1,184,255,240,179,43,1,1,1,184,1,27,179,10,5,5,0,185,1,121,
0,11,16,254,50,47,16,238,93,56,50,50,47,93,56,51,17,57,47,51,0,63,51,253,50,47,63,51,253,50,47,61,17,57,47,93,51,47,24,135,5,46,43,135,8,125,196,135,8,46,24,43,135,5,125,196,49,48,1,93,41,1,9,1,33,21,
33,9,1,33,3,159,252,163,1,155,254,107,3,72,253,168,1,74,254,179,2,106,2,222,2,225,142,253,172,253,178,255,255,0,33,0,0,3,72,5,191,2,6,0,55,0,0,255,255,0,63,0,0,4,125,5,191,2,6,0,60,0,0,0,3,0,100,0,0,6,
124,5,191,0,17,0,24,0,31,0,205,64,60,110,8,19,25,122,0,3,3,2,8,26,18,122,9,12,12,11,2,18,12,0,101,26,9,3,3,6,22,112,192,15,223,15,2,15,131,33,29,112,207,6,1,6,121,32,0,33,63,33,80,33,112,33,160,33,207,
33,240,33,7,93,16,246,93,237,16,246,93,237,18,57,47,51,51,253,50,50,0,63,51,47,51,253,50,63,51,47,51,253,50,49,48,67,121,180,4,31,20,17,22,184,2,118,179,1,24,13,22,184,2,118,179,1,31,4,29,184,2,118,179,
0,27,8,29,184,2,118,179,0,21,16,19,184,2,118,183,0,17,0,20,19,23,14,18,184,2,118,183,1,13,12,24,18,30,5,25,184,2,118,183,0,31,25,4,3,28,7,26,184,2,118,180,1,27,26,8,9,16,60,16,60,43,16,60,16,60,43,16,
60,16,60,43,16,60,16,60,43,1,43,43,43,43,129,37,21,35,53,36,0,17,16,0,37,53,51,21,4,0,17,16,0,1,17,54,36,53,52,36,1,17,6,4,21,20,4,3,186,148,254,188,254,130,1,130,1,64,148,1,68,1,126,254,126,254,192,237,
1,61,254,219,254,103,237,254,195,1,37,145,145,145,21,1,61,1,5,1,4,1,66,19,126,126,21,254,195,254,251,254,252,254,190,4,21,252,97,15,219,230,205,241,252,114,3,159,15,219,230,205,241,0,255,255,0,69,0,0,
4,155,5,191,2,6,0,59,0,0,0,1,0,140,0,0,5,200,5,191,0,27,0,140,64,25,61,8,21,18,94,4,7,7,6,27,20,12,2,6,8,21,5,101,18,6,6,11,25,101,0,184,1,40,179,29,14,101,11,184,1,40,64,12,28,16,29,48,29,79,29,176,29,
223,29,5,93,16,246,237,16,246,237,17,57,47,51,253,50,0,63,63,51,51,18,57,47,51,253,50,49,48,67,121,64,13,1,24,2,38,23,37,16,38,9,37,22,3,25,184,2,118,179,1,17,8,14,184,2,118,179,0,24,1,21,184,2,118,181,
0,22,21,15,10,18,184,2,118,177,0,17,60,43,16,60,43,1,43,43,43,43,43,43,129,1,20,6,4,7,17,35,17,38,36,38,53,17,51,17,20,30,1,23,17,51,17,62,2,53,17,51,5,200,119,254,234,199,148,185,254,254,153,151,57,214,
174,148,182,209,54,151,3,196,206,239,150,10,254,153,1,103,10,122,234,250,1,240,254,64,182,191,135,14,3,202,252,54,14,140,181,187,1,192,0,0,1,0,130,0,0,6,47,5,227,0,31,0,193,64,41,87,6,109,21,109,31,135,
6,151,15,5,85,4,85,16,85,31,178,5,178,15,194,6,194,14,7,69,4,69,16,69,31,3,34,8,10,122,26,3,16,4,184,255,240,64,12,2,0,4,16,3,20,101,3,17,8,0,4,184,255,240,64,52,15,4,31,4,111,4,127,4,4,4,4,23,20,16,16,
0,16,16,16,96,16,112,16,4,16,16,29,23,1,7,112,1,176,29,192,29,2,29,131,33,19,13,112,19,191,23,207,23,2,23,120,32,16,246,93,50,237,47,16,246,93,50,237,47,17,18,57,47,93,56,51,17,57,47,93,56,51,0,63,51,
253,23,50,23,56,63,237,49,48,67,121,64,24,24,28,8,12,9,27,7,100,1,11,25,13,100,0,8,28,10,100,1,12,24,10,100,1,43,43,1,43,43,129,129,0,93,93,93,37,33,21,33,53,36,18,53,52,0,33,32,0,21,20,18,5,21,33,53,
33,36,2,53,16,0,33,32,0,17,20,2,4,79,1,177,253,207,1,42,158,254,194,255,0,255,0,254,193,150,1,50,253,207,1,177,254,221,189,1,154,1,61,1,61,1,153,189,138,138,196,194,1,22,153,248,1,38,254,217,247,152,254,
239,200,196,138,181,1,58,190,1,49,1,123,254,133,254,207,190,254,198,0,255,255,255,168,0,0,2,40,7,24,2,38,0,44,0,0,1,7,0,142,255,110,1,42,0,22,64,12,2,1,0,13,19,0,1,51,2,1,10,32,0,63,53,53,1,43,53,53,255,
255,0,63,0,0,4,125,7,24,2,38,0,60,0,0,1,7,0,142,0,228,1,42,0,22,64,12,2,1,0,18,24,0,4,51,2,1,15,32,0,63,53,53,1,43,53,53,255,255,0,107,255,228,4,216,6,62,2,54,0,68,0,0,1,23,1,152,1,57,0,0,0,10,182,2,0,
34,33,9,0,51,43,53,255,255,0,103,255,227,3,59,6,62,2,54,1,198,0,0,1,22,1,152,46,0,0,10,182,1,0,37,36,5,0,51,43,53,255,255,0,156,254,114,4,81,6,62,2,54,1,200,0,0,1,23,1,152,0,238,0,0,0,10,182,1,0,24,23,
13,21,51,43,53,255,255,0,117,0,0,1,36,6,62,2,54,0,215,0,0,1,23,1,152,255,74,0,0,0,10,182,1,0,6,5,0,1,51,43,53,255,255,0,135,255,228,4,91,6,62,2,54,1,214,0,0,1,23,1,153,0,223,0,0,0,15,64,9,3,2,1,0,40,34,
20,14,51,43,53,53,53,0,255,255,0,107,255,228,4,216,4,92,2,6,0,68,0,0,0,2,0,156,254,114,4,94,6,0,0,18,0,38,0,170,179,111,21,1,31,184,255,192,64,54,9,21,57,68,8,11,20,88,16,19,1,19,19,25,29,32,88,0,17,11,
2,14,25,88,6,1,11,22,20,20,14,29,9,105,15,22,31,22,2,22,22,29,35,105,14,133,40,29,125,1,92,2,139,39,16,246,253,228,16,246,237,17,57,47,93,237,17,18,57,47,17,51,0,63,237,63,63,51,253,50,17,57,47,93,237,
57,49,48,67,121,64,50,33,37,23,27,12,16,4,8,37,12,35,90,1,33,16,35,90,1,24,7,22,128,1,26,5,28,128,0,36,13,38,90,1,12,11,34,15,32,90,0,23,8,25,128,1,27,4,25,128,1,43,43,43,16,60,43,1,43,43,43,43,129,129,
129,129,1,43,93,37,17,35,17,52,54,51,50,22,21,20,7,30,1,21,20,0,35,34,19,53,36,17,52,38,35,34,6,21,19,20,22,51,50,54,53,52,38,33,1,41,141,238,162,166,195,219,192,228,254,234,205,214,14,1,83,113,94,131,
139,1,196,139,145,197,199,254,241,164,253,206,5,225,230,199,177,148,231,80,19,236,183,209,254,231,3,65,117,9,1,10,92,115,144,186,253,155,162,194,201,147,145,207,0,0,1,0,53,254,114,4,53,4,64,0,8,0,138,
64,45,24,7,154,1,183,6,3,8,0,1,1,91,7,8,20,7,7,8,6,5,4,4,91,7,6,20,7,7,6,0,6,8,3,5,1,4,7,3,9,5,6,3,14,6,5,184,255,240,64,35,11,5,27,5,63,5,3,5,3,5,4,8,0,16,4,0,48,0,2,0,2,0,7,7,1,92,4,9,10,4,92,58,240,
10,1,93,43,47,237,61,57,47,24,50,50,47,93,56,51,17,51,51,47,93,56,51,0,63,63,17,23,51,17,23,51,135,14,46,43,135,5,125,196,135,14,46,24,43,135,5,125,196,49,48,0,93,9,1,17,35,17,1,51,9,1,4,53,254,70,138,
254,68,149,1,108,1,105,4,64,252,58,253,248,2,10,3,196,252,232,3,24,0,0,3,0,104,255,228,4,43,6,0,0,25,0,37,0,38,0,199,64,36,132,15,150,15,2,175,28,175,36,191,28,191,36,196,17,198,25,6,63,28,63,36,79,28,
79,36,95,1,80,17,80,25,111,1,8,15,184,255,192,179,19,21,57,3,184,255,192,64,59,16,21,57,45,8,0,16,18,24,4,21,38,88,175,26,207,26,2,26,26,5,21,8,105,7,7,10,105,5,1,32,88,21,11,0,16,38,3,18,24,8,8,7,7,13,
88,2,2,24,35,105,18,133,40,29,105,24,96,39,16,246,237,16,246,237,18,57,47,237,51,47,51,47,17,18,23,57,0,63,237,63,237,51,47,237,17,18,57,47,93,253,17,23,57,49,48,67,121,182,30,34,19,23,31,22,29,184,2,
119,179,0,33,20,35,184,2,119,179,1,30,23,32,184,2,119,179,0,34,19,32,185,2,119,0,0,43,43,1,43,43,129,129,0,43,43,93,93,93,1,38,53,52,54,51,50,23,7,38,35,34,6,21,20,22,23,4,17,20,0,35,34,0,53,16,37,34,
6,21,20,22,51,50,54,53,52,38,39,1,189,165,233,172,126,112,36,84,107,126,147,98,209,1,81,254,235,204,204,254,234,1,226,142,197,195,144,144,195,197,142,3,138,111,179,151,189,28,125,22,113,92,80,114,84,135,
254,181,204,254,232,1,23,205,1,74,20,208,145,146,202,202,146,145,208,133,0,0,1,0,103,255,227,3,59,4,94,0,34,0,227,181,104,15,215,21,2,28,184,255,192,179,18,21,57,21,184,255,192,179,18,21,57,13,184,255,
222,179,16,17,57,33,184,255,192,64,11,21,23,57,1,64,13,20,57,40,8,34,184,255,192,64,79,9,12,57,0,2,34,32,59,15,1,15,17,14,12,7,24,144,16,25,32,25,2,25,25,12,32,88,2,11,17,88,12,7,14,0,34,15,16,4,24,64,
9,12,57,24,24,14,7,20,15,255,14,1,14,14,34,223,0,239,0,2,0,0,178,36,20,105,214,9,230,9,2,9,9,29,105,5,96,35,16,246,237,57,47,93,237,16,254,47,93,51,51,47,93,51,17,51,18,57,47,43,23,56,0,63,237,63,237,
18,57,47,113,253,57,17,51,17,51,93,17,51,17,51,43,49,48,67,121,64,28,30,31,18,19,10,11,3,4,31,3,29,128,0,18,11,20,128,0,30,4,32,128,0,19,10,17,128,1,43,43,1,43,43,129,129,129,129,0,43,43,43,1,43,43,93,
37,6,35,34,38,53,52,55,38,53,52,54,51,50,23,7,38,35,34,6,21,20,22,59,1,21,35,34,6,21,20,22,51,50,55,3,59,136,223,160,205,196,150,183,137,165,147,79,114,113,88,103,106,81,73,86,88,117,124,103,158,101,116,
145,186,153,205,82,61,170,129,161,123,97,88,95,83,78,100,120,114,87,96,111,114,0,1,0,118,254,86,3,165,5,228,0,30,0,207,185,0,22,255,192,179,10,18,57,24,184,255,192,179,8,12,57,27,184,255,192,64,12,8,12,
57,169,6,185,6,2,164,21,1,24,184,255,224,179,22,28,57,12,184,255,224,179,17,19,57,4,184,255,192,64,55,18,20,57,22,23,23,91,7,8,20,7,7,8,17,13,92,16,0,23,22,7,8,7,31,3,88,29,15,16,14,32,14,2,14,14,17,8,
7,5,10,23,22,20,1,1,0,0,26,10,13,32,17,21,57,17,184,255,240,64,27,16,13,4,17,16,17,32,17,3,17,17,5,88,197,26,1,26,242,32,20,105,47,10,1,10,96,31,16,244,113,237,16,246,93,237,51,47,93,51,51,56,43,17,18,
57,47,51,47,17,57,57,17,18,57,57,18,57,47,93,0,63,237,17,51,51,17,51,51,63,253,50,135,14,46,43,14,125,16,196,49,48,0,43,43,43,93,1,93,43,43,43,1,55,22,51,50,53,52,38,39,36,17,52,0,37,33,53,33,21,8,1,21,
20,22,23,30,1,7,20,6,35,34,1,132,36,63,56,247,110,152,254,102,1,36,1,70,254,9,2,163,254,152,254,225,143,189,229,111,1,211,168,87,254,106,126,16,158,59,70,29,79,1,150,211,1,160,253,123,123,254,209,254,
127,182,156,179,39,47,131,95,138,156,0,1,0,156,254,114,4,81,4,92,0,21,0,105,64,41,139,15,148,15,203,7,3,127,8,143,8,2,28,8,8,6,88,15,17,7,13,6,1,14,11,10,1,92,0,64,20,22,57,0,118,23,15,15,11,92,12,184,
255,192,181,20,22,57,12,139,22,16,246,43,237,57,47,16,244,43,237,0,63,63,63,63,51,253,50,49,48,67,121,64,18,18,20,3,5,19,37,4,38,5,18,2,90,1,3,20,6,90,1,43,1,43,43,43,129,129,0,93,93,1,35,17,52,46,1,35,
34,14,1,21,17,35,17,51,21,54,51,50,30,1,21,4,81,139,32,139,119,130,197,53,140,140,167,241,117,188,96,254,114,3,149,163,182,123,167,199,222,254,113,4,64,195,223,117,210,229,0,3,0,104,255,228,4,213,6,0,
0,11,0,18,0,25,0,124,64,30,71,8,18,144,175,20,1,20,20,0,15,88,6,1,23,88,0,11,12,19,105,9,133,27,18,20,105,3,96,26,16,246,253,50,16,244,253,50,0,63,237,63,237,18,57,47,93,237,49,48,67,121,64,50,1,25,24,
11,19,90,1,25,19,22,1,20,90,0,21,20,14,7,12,90,1,13,12,16,5,18,90,0,17,18,25,10,23,90,0,21,2,23,90,0,13,8,15,90,1,17,4,15,90,1,43,43,43,43,1,16,60,43,16,60,43,16,60,43,16,60,43,129,5,32,0,17,16,0,33,32,
0,17,16,0,19,10,1,35,34,2,3,5,33,26,1,51,50,18,2,159,254,243,254,214,1,43,1,12,1,12,1,42,254,215,153,13,220,189,189,220,14,3,78,252,178,11,218,194,194,218,28,1,163,1,103,1,104,1,170,254,86,254,152,254,
154,254,92,3,76,1,18,1,62,254,196,254,236,123,254,232,254,199,1,55,255,255,0,135,0,0,1,20,4,64,2,22,0,215,0,0,0,1,0,155,0,0,4,16,4,65,0,10,0,184,64,80,216,1,1,9,0,9,1,6,7,1,67,217,10,1,9,4,10,1,96,6,10,
1,54,2,2,1,7,6,7,8,8,7,7,91,10,9,20,10,10,9,1,2,2,91,10,0,20,10,10,0,2,7,10,1,3,0,4,8,6,9,5,10,10,4,9,6,5,6,0,4,10,10,5,6,7,2,4,3,4,8,184,2,47,178,9,178,1,184,2,47,64,14,0,74,12,32,12,1,3,92,4,73,11,123,
185,24,43,78,16,244,77,237,93,78,16,246,77,237,244,237,17,18,23,57,50,0,63,60,63,63,18,57,47,17,18,57,57,17,18,57,57,17,51,51,135,46,43,5,125,16,196,135,4,46,24,43,5,125,16,196,3,8,16,60,8,60,49,48,1,
94,93,94,93,94,0,93,94,93,1,93,94,93,33,35,1,17,35,17,51,17,1,51,1,4,16,198,253,222,141,141,1,247,206,253,171,1,233,254,23,4,65,254,73,1,182,253,249,0,0,1,0,39,0,0,4,49,5,228,0,7,0,166,64,65,22,4,89,5,
2,22,2,1,6,0,1,2,2,3,5,6,5,4,6,1,2,3,2,1,3,91,4,5,20,4,4,5,7,6,1,1,91,0,7,20,0,0,7,2,5,1,6,2,5,16,5,1,5,4,7,6,0,3,1,0,3,4,10,7,6,184,255,240,64,21,2,6,191,6,207,6,3,6,6,4,1,0,16,4,0,16,0,32,0,3,0,184,
1,112,178,9,3,4,187,255,240,0,4,2,79,0,8,16,230,56,50,16,230,93,56,50,17,57,47,93,56,51,0,63,23,51,63,51,18,57,93,17,51,1,17,18,57,57,135,46,43,135,125,196,135,46,24,43,8,125,16,196,135,8,16,60,8,196,
49,48,1,93,93,93,33,35,9,1,35,1,3,51,4,49,149,254,149,254,138,148,1,191,220,148,3,70,252,186,3,238,1,246,0,1,0,144,254,114,4,69,4,65,0,21,0,85,183,71,13,155,2,196,13,3,17,184,255,208,64,36,16,17,57,5,
64,14,17,57,20,9,6,17,15,88,2,4,11,0,10,7,14,1,19,92,0,64,20,22,57,0,118,23,11,7,92,8,184,255,192,181,20,22,57,8,139,22,16,246,43,253,50,16,246,43,253,50,0,63,63,63,51,253,50,63,51,49,48,0,43,43,93,37,
35,53,6,35,34,39,17,35,17,51,17,20,30,1,51,50,62,1,53,17,51,4,69,140,168,240,174,87,140,140,32,139,118,130,197,53,140,1,195,223,116,254,25,5,207,253,249,163,182,123,167,199,222,1,143,0,255,255,0,53,0,
0,4,53,4,64,2,22,0,89,0,0,0,1,0,118,254,86,3,164,6,0,0,45,0,216,185,0,37,255,208,64,43,12,13,57,11,9,11,16,4,39,3,91,9,164,36,182,4,180,36,203,9,5,63,34,79,34,84,12,207,6,196,12,5,43,48,9,11,57,25,48,
16,18,57,27,184,255,208,64,77,13,22,57,37,38,38,91,7,8,20,7,7,8,8,7,10,5,88,41,197,41,1,38,37,41,35,41,64,9,11,57,26,105,48,15,64,15,2,15,15,41,10,13,29,88,16,32,1,32,32,18,8,7,8,37,38,4,46,3,88,44,15,
21,23,105,20,18,1,13,26,31,31,21,21,20,20,41,184,255,192,64,11,9,11,57,41,242,47,35,105,10,96,46,16,244,237,16,246,43,50,47,51,47,50,47,17,51,0,63,51,253,50,63,237,17,23,51,17,18,57,47,93,253,57,1,17,
18,57,47,93,237,43,17,18,57,57,93,16,237,17,57,57,49,48,135,14,46,43,14,125,16,196,0,43,43,43,93,93,1,93,43,1,55,22,51,50,53,52,38,39,36,17,52,54,55,38,53,52,54,51,50,23,7,38,35,34,6,21,20,22,59,1,21,
35,34,6,21,20,22,23,30,1,21,20,6,35,34,1,132,36,63,56,247,89,192,254,121,167,144,229,243,192,154,125,33,115,150,124,149,227,151,119,202,147,230,137,173,207,154,211,168,87,254,106,126,16,158,51,71,36,74,
1,125,145,220,45,113,198,159,181,37,134,40,127,102,112,134,122,158,165,140,163,38,46,103,127,138,156,0,255,255,0,104,255,228,4,213,4,92,2,22,0,82,0,0,0,1,0,50,0,0,5,43,4,64,0,11,0,79,64,19,3,7,10,5,1,
9,88,10,6,4,92,95,1,111,1,239,1,3,1,186,1,52,0,0,255,192,64,16,9,19,57,0,158,13,5,92,80,8,96,8,224,8,3,8,184,1,52,183,9,64,12,19,57,9,158,12,16,246,43,244,93,237,16,246,43,244,93,237,0,63,253,50,50,63,
51,49,48,1,35,17,35,17,33,17,35,17,35,53,33,5,43,221,141,253,219,141,221,4,249,3,197,252,59,3,197,252,59,3,197,123,0,2,0,135,254,114,4,244,4,92,0,13,0,25,0,110,64,35,112,19,128,19,2,49,8,0,16,1,15,3,18,
0,20,88,12,11,14,88,6,7,23,105,9,9,133,27,0,0,17,92,3,139,26,16,246,253,50,47,16,246,47,237,0,63,237,63,237,51,50,50,63,56,49,48,67,121,64,36,21,25,15,16,4,11,21,11,23,90,1,25,7,23,90,1,15,5,17,90,0,22,
10,20,90,0,24,8,14,90,1,16,4,14,90,1,43,43,43,1,43,43,43,129,129,129,1,93,37,17,35,17,16,0,51,50,0,21,20,0,35,32,1,34,2,21,20,22,51,50,18,53,52,2,1,19,140,1,69,242,243,1,67,254,186,240,254,244,1,12,178,
246,241,183,192,232,247,205,253,165,3,141,1,10,1,83,254,173,236,240,254,183,3,239,254,252,181,179,254,1,2,175,181,1,4,0,0,1,0,104,254,86,4,107,4,92,0,31,0,192,64,35,36,7,52,7,132,7,148,7,171,26,5,123,
2,203,2,203,13,203,14,4,4,31,171,21,187,21,208,8,4,2,32,14,21,57,11,184,255,224,179,9,12,57,13,184,255,224,64,50,9,12,57,23,8,9,10,10,91,24,25,20,24,24,25,9,10,24,25,4,32,20,88,15,15,1,3,88,0,30,7,25,
24,22,27,10,9,12,6,18,18,17,17,27,22,88,12,12,1,0,184,255,192,64,11,9,13,57,0,205,33,6,105,27,96,32,16,246,237,16,246,43,50,50,47,237,18,57,47,51,47,17,18,57,57,17,18,57,57,0,63,51,253,50,63,237,17,23,
51,135,14,46,43,14,125,16,196,49,48,24,67,121,64,14,28,29,4,5,4,29,6,90,0,5,28,3,90,1,0,43,1,43,129,129,1,43,43,43,93,0,93,93,1,7,38,35,34,6,21,20,22,23,30,1,21,20,6,35,34,39,55,22,51,50,53,52,38,39,36,
17,52,0,51,32,4,107,111,144,219,177,235,184,233,225,169,211,168,87,78,36,63,56,247,108,183,253,249,1,64,239,1,60,3,94,69,191,247,192,163,189,44,42,106,133,138,156,20,126,16,158,59,70,29,83,1,176,253,1,
72,0,0,2,0,104,255,228,5,148,4,92,0,15,0,27,0,136,185,0,1,255,224,64,23,18,21,57,127,26,143,26,2,46,8,0,88,15,6,16,88,12,7,22,88,6,11,1,184,255,240,64,26,1,12,14,3,9,25,105,159,3,191,3,2,3,3,9,79,0,1,
0,205,29,19,105,9,96,28,16,246,237,16,252,93,17,57,47,93,237,18,23,57,56,0,63,237,63,237,63,237,49,48,67,121,64,34,17,24,4,11,23,5,25,90,1,21,7,19,90,0,17,11,19,90,0,24,4,22,90,0,20,8,22,90,0,18,10,16,
90,1,43,43,43,1,43,43,43,129,129,0,93,0,43,1,33,22,21,20,0,35,34,0,53,52,0,51,50,23,33,5,34,2,21,20,22,51,50,18,53,52,2,5,148,254,141,180,254,186,240,241,254,186,1,68,243,98,86,2,61,253,11,175,249,241,
183,197,227,247,3,197,175,249,240,254,183,1,72,241,235,1,84,28,109,254,255,184,179,254,1,9,168,181,1,4,0,0,1,0,50,0,0,3,5,4,64,0,7,0,51,64,11,1,5,144,6,6,3,10,0,178,9,5,184,255,192,64,17,9,11,57,5,178,
8,2,92,3,8,9,3,92,58,80,9,1,93,43,47,237,16,238,43,16,238,0,63,63,253,50,49,48,1,33,17,35,17,33,53,33,3,5,254,221,141,254,221,2,211,3,197,252,59,3,197,123,0,0,1,0,135,255,228,4,91,4,93,0,20,0,127,185,
0,13,255,208,64,14,20,21,57,10,48,18,21,57,11,32,18,21,57,13,184,255,208,64,28,15,21,57,37,8,11,12,16,12,7,1,6,6,88,17,9,12,11,11,2,9,105,14,133,22,2,92,20,184,255,192,181,20,22,57,20,139,21,16,246,43,
237,16,246,237,17,57,47,51,0,63,237,63,63,56,51,49,48,67,121,64,26,15,19,3,8,4,38,7,16,9,90,1,5,18,2,90,0,8,15,6,90,0,3,19,6,90,0,43,43,1,43,43,43,129,129,0,43,43,43,43,19,51,17,20,30,1,51,50,54,53,16,
39,55,4,17,20,0,35,34,36,17,135,141,36,170,130,177,183,254,77,1,64,254,240,231,214,254,249,4,64,254,4,163,175,134,236,200,1,17,172,128,188,254,101,240,254,206,250,1,86,0,0,2,0,104,254,114,5,184,4,92,0,
22,0,28,0,163,64,14,121,11,133,25,153,11,185,4,185,11,201,11,6,11,184,255,224,179,11,13,57,13,184,255,208,64,74,11,13,57,4,8,43,25,59,25,127,22,127,25,151,11,152,25,167,13,168,25,183,11,199,11,11,22,8,
14,24,88,3,0,11,1,14,10,23,88,9,17,7,9,9,10,0,24,92,10,3,0,14,1,14,29,30,14,92,58,26,105,20,133,30,12,105,133,6,153,6,2,6,96,29,16,246,93,237,16,246,237,43,47,93,51,51,253,50,47,51,25,47,0,24,63,51,253,
50,63,63,51,253,50,49,48,67,121,64,14,27,28,18,19,28,18,26,90,1,27,19,23,90,1,43,1,43,129,129,1,93,43,43,0,93,5,17,35,17,36,0,53,52,18,55,23,4,17,16,5,17,54,51,32,0,17,20,0,1,17,36,17,52,38,3,86,141,254,
232,254,183,227,196,45,254,187,1,210,39,32,1,59,1,109,254,183,254,231,1,210,251,26,254,140,1,117,18,1,43,249,195,1,30,67,133,116,254,210,254,126,39,3,232,3,254,205,254,244,248,254,212,3,218,252,158,43,
1,126,201,234,0,1,255,249,254,114,3,223,4,64,0,11,1,10,64,35,25,1,45,1,41,3,38,5,34,7,38,9,41,11,73,1,137,1,9,20,10,47,4,32,10,74,4,69,10,137,4,6,4,16,10,184,255,240,64,88,1,1,2,4,5,4,3,5,0,10,10,9,7,
6,7,8,6,11,1,1,0,10,9,10,11,9,2,4,4,5,7,8,7,6,8,3,11,0,5,5,91,6,11,20,6,6,11,9,8,3,3,91,2,9,20,2,2,9,1,4,10,3,7,7,8,2,3,5,3,6,14,0,9,11,3,8,6,7,4,3,8,10,1,9,3,2,16,2,184,255,192,64,9,11,20,57,2,2,11,0,
16,0,184,255,192,183,9,11,57,0,178,13,5,6,184,255,240,64,9,6,64,13,20,57,6,6,9,8,184,255,240,181,8,178,12,112,13,1,93,16,230,56,50,50,47,43,56,51,16,230,43,56,50,50,47,43,56,51,18,57,57,17,18,57,57,0,
63,23,51,63,23,51,18,57,47,23,51,135,5,46,43,135,125,196,135,46,24,43,135,125,196,7,8,16,60,8,60,7,8,16,60,8,60,7,8,16,60,8,60,7,8,16,60,8,60,0,56,56,49,48,0,93,1,93,9,2,35,9,1,35,9,1,51,9,1,3,176,254,
135,1,168,160,254,169,254,168,151,1,163,254,132,158,1,45,1,44,4,64,253,68,252,238,2,126,253,130,3,12,2,194,253,209,2,47,0,1,0,135,254,114,5,92,4,64,0,26,0,124,64,22,132,15,133,22,150,2,148,15,146,22,164,
1,165,15,164,22,182,16,198,16,10,22,184,255,208,179,11,14,57,15,184,255,208,64,38,11,14,57,20,17,88,3,6,11,25,18,11,6,5,14,3,20,92,6,17,27,28,17,92,58,25,92,26,64,20,22,57,26,118,28,12,92,11,184,255,192,
64,15,20,22,57,11,139,27,0,28,16,28,64,28,112,28,4,93,16,246,43,237,16,246,43,237,43,47,51,253,50,0,63,63,51,51,63,51,253,50,43,43,49,48,0,93,1,16,4,7,17,35,17,46,2,53,17,51,17,20,30,1,23,17,51,17,62,
2,53,17,51,5,92,254,180,216,140,170,237,142,139,53,197,160,140,165,193,50,140,2,42,254,186,247,7,254,140,1,116,10,116,224,240,2,12,254,34,174,183,129,13,3,209,252,46,13,133,172,182,1,222,0,0,1,0,104,255,
228,6,116,4,92,0,40,0,238,183,184,12,200,12,198,23,3,23,184,255,224,179,14,17,57,18,184,255,224,179,14,17,57,1,184,255,192,64,9,16,17,57,40,64,16,17,57,11,184,255,224,64,86,9,22,57,30,32,9,22,57,52,8,
84,0,100,0,2,23,18,16,0,3,20,20,16,31,10,88,32,9,7,25,88,38,11,16,88,3,11,32,32,31,31,1,31,31,9,9,47,10,63,10,2,10,10,19,0,0,22,92,16,19,32,19,95,10,175,10,4,19,41,42,19,92,58,28,105,35,133,42,13,105,
6,96,41,112,42,1,93,16,246,237,16,246,237,43,47,93,237,61,57,47,24,17,51,47,93,51,47,50,47,93,51,47,0,63,237,63,237,63,51,253,50,17,57,47,17,51,17,51,51,93,49,48,67,121,64,11,36,37,26,27,14,15,4,5,26,
37,28,184,2,119,179,1,15,4,13,184,2,119,179,0,27,36,25,184,2,119,179,0,14,5,16,185,2,119,0,0,43,43,1,43,43,129,129,129,129,1,43,43,43,43,0,43,43,93,37,14,1,35,34,2,53,16,0,37,23,6,2,21,20,22,51,50,54,
61,1,51,21,20,22,51,50,54,53,52,2,39,55,4,0,17,20,2,35,34,38,3,110,29,169,112,216,248,1,78,1,5,11,212,251,165,145,116,134,142,134,116,140,170,251,212,11,1,4,1,79,248,216,112,169,199,103,124,1,23,246,1,
4,1,89,14,135,16,254,244,205,187,205,200,188,134,134,188,200,200,192,208,1,10,15,135,13,254,165,254,253,246,254,233,124,0,255,255,255,141,0,0,2,13,5,238,2,38,0,215,0,0,1,7,0,142,255,83,0,0,0,22,64,12,
2,1,0,13,19,0,1,51,2,1,10,34,0,63,53,53,1,43,53,53,255,255,0,135,255,228,4,91,5,238,2,54,1,214,0,0,1,23,0,142,0,232,0,0,0,12,183,1,2,0,30,36,20,14,51,43,53,53,255,255,0,104,255,228,4,213,6,62,2,54,0,82,
0,0,1,23,1,152,1,28,0,0,0,10,182,2,0,30,29,17,25,51,43,53,255,255,0,135,255,228,4,91,6,62,2,54,1,214,0,0,1,23,1,152,0,223,0,0,0,10,182,1,0,24,21,2,9,51,43,53,255,255,0,104,255,228,6,116,6,62,2,54,1,218,
0,0,1,23,1,152,1,235,0,0,0,10,182,1,0,43,42,10,31,51,43,53,255,255,0,180,0,0,3,255,7,24,2,38,0,40,0,0,1,7,0,142,0,232,1,42,0,22,64,12,2,1,0,21,27,0,1,51,2,1,18,32,0,63,53,53,1,43,53,53,0,1,0,32,255,222,
4,235,5,191,0,29,0,137,64,33,40,8,12,64,24,29,57,10,64,17,20,57,11,11,9,1,94,22,22,24,25,29,94,28,2,14,122,9,9,24,8,12,11,184,255,240,64,23,11,64,13,19,57,11,11,22,17,112,6,131,31,22,29,224,0,101,25,224,
26,169,30,16,246,244,253,228,60,16,246,237,17,51,47,43,56,51,0,63,63,237,63,253,50,18,57,47,237,17,51,47,49,48,43,43,67,121,64,28,15,20,3,8,4,37,19,38,15,8,17,117,1,20,3,17,117,1,16,7,14,117,0,18,5,21,
117,1,43,43,1,43,43,43,43,129,129,1,17,51,50,30,1,21,20,6,35,34,39,55,22,51,50,54,53,52,46,1,43,1,17,35,17,33,53,33,21,1,255,135,236,236,141,179,166,145,99,91,65,76,98,107,88,162,167,179,150,254,183,3,
39,5,48,254,38,71,222,167,205,223,98,102,61,155,134,134,135,48,253,57,5,48,143,143,255,255,0,177,0,0,3,156,7,103,2,54,1,241,0,0,1,23,0,141,1,1,1,41,0,7,178,1,8,32,0,63,53,0,255,255,0,116,255,219,6,18,
5,228,0,87,2,11,6,129,0,0,192,0,64,0,255,255,0,27,255,219,3,120,5,228,2,6,0,54,0,0,255,255,0,158,0,0,1,49,5,191,2,6,0,44,0,0,255,255,255,168,0,0,2,40,7,24,2,38,0,44,0,0,1,7,0,142,255,110,1,42,0,22,64,
12,2,1,0,13,19,0,1,51,2,1,10,32,0,63,53,53,1,43,53,53,255,255,0,86,255,219,3,40,5,191,2,6,0,45,0,0,0,2,0,49,0,0,8,19,5,191,0,15,0,26,0,217,64,93,232,12,1,44,8,26,1,0,0,16,6,0,12,15,60,12,11,12,13,11,86,
16,0,20,16,16,0,12,13,12,11,13,86,14,15,20,14,14,15,1,2,94,26,25,25,11,12,0,15,2,16,94,11,11,13,8,0,12,15,59,15,0,12,12,11,13,11,16,0,10,48,10,2,10,16,10,10,14,21,112,6,131,28,13,16,14,1,14,64,9,13,57,
14,184,255,240,178,14,169,27,16,230,56,43,93,50,16,246,237,18,57,47,56,93,51,51,61,17,18,57,47,24,51,51,43,0,63,51,16,237,63,51,51,18,57,47,51,253,50,135,5,46,43,8,125,16,196,135,5,46,24,43,8,125,16,196,
43,1,24,47,135,125,16,196,60,49,48,24,67,121,64,30,3,24,8,38,19,37,4,37,23,38,18,9,21,117,1,24,3,21,117,1,20,7,17,117,0,22,5,25,117,1,0,43,43,1,43,43,43,43,43,43,129,0,93,9,1,33,50,4,22,21,20,14,1,43,
1,9,1,35,9,1,51,50,62,1,53,52,46,1,35,33,3,12,1,51,1,79,238,1,5,146,151,235,215,158,253,222,253,217,162,2,183,2,144,73,185,161,91,97,163,209,254,211,5,191,253,137,73,201,148,152,202,64,4,135,251,121,5,
191,250,207,42,135,98,102,136,41,0,2,0,177,0,0,7,230,5,191,0,21,0,32,0,120,64,41,47,8,4,0,94,32,17,17,18,2,21,2,22,94,15,18,8,1,15,101,4,80,22,1,22,22,19,27,112,10,131,34,0,18,101,95,19,1,19,102,33,16,
246,93,253,50,16,246,237,18,57,47,93,51,253,50,0,63,51,237,63,51,18,57,47,51,253,50,49,48,67,121,64,34,6,30,12,38,25,37,8,9,7,9,2,6,29,38,24,13,27,117,1,30,6,27,117,1,26,11,23,117,0,28,9,31,117,1,43,43,
1,43,43,43,42,43,43,129,1,33,17,51,17,51,50,30,2,21,20,14,1,41,1,17,33,17,35,17,51,1,51,50,62,1,53,52,46,1,43,1,1,69,2,236,148,105,213,211,177,95,143,236,254,235,254,219,253,20,148,148,3,128,156,212,176,
101,106,172,243,124,3,87,2,104,253,152,20,96,176,123,169,204,67,2,199,253,57,5,191,250,207,33,136,120,111,135,34,0,0,1,0,33,0,0,4,236,5,191,0,21,0,89,64,23,25,8,8,94,21,21,1,2,6,94,5,2,14,1,8,16,101,176,
14,192,14,2,14,184,1,40,64,11,23,6,224,21,7,101,2,224,3,169,22,16,246,244,253,50,228,16,246,93,237,0,63,51,63,253,50,18,57,47,237,49,48,67,121,64,16,10,19,11,37,18,38,19,10,16,117,1,17,12,20,117,1,43,
1,43,43,43,129,33,35,17,33,53,33,21,33,17,33,50,30,1,21,17,35,17,52,46,1,35,33,2,0,150,254,183,3,39,254,184,1,51,164,192,85,150,50,124,113,254,201,5,48,143,143,254,38,91,186,208,254,143,1,121,157,119,
58,0,255,255,0,179,0,0,4,146,7,103,2,54,0,46,0,0,1,23,0,141,1,64,1,41,0,7,178,1,13,32,0,63,53,0,255,255,0,67,255,219,4,222,7,31,2,54,2,1,0,0,1,23,0,219,0,197,1,42,0,17,64,10,1,29,32,1,0,18,26,0,4,51,43,
53,0,63,53,0,0,1,0,177,255,36,4,128,5,191,0,11,0,56,185,0,11,255,192,64,28,9,13,57,11,11,4,94,9,0,8,6,2,2,9,101,0,0,1,5,101,8,174,13,4,101,1,102,12,16,246,237,16,246,237,18,57,47,237,0,63,51,63,51,237,
51,47,43,49,48,41,1,17,51,17,33,17,51,17,33,21,35,2,86,254,91,148,2,167,148,254,95,137,5,191,250,204,5,52,250,65,220,255,255,0,49,0,0,5,186,5,191,2,22,0,36,0,0,0,2,0,178,0,0,4,35,5,191,0,13,0,24,0,93,
64,29,40,8,5,94,14,14,13,4,94,1,2,16,94,13,8,3,3,0,20,112,10,131,26,4,15,101,0,102,25,16,246,253,50,16,246,237,18,57,47,0,63,237,63,237,18,57,47,237,49,48,67,121,64,28,7,23,18,37,8,37,22,38,17,12,20,117,
1,23,7,20,117,1,19,11,16,117,0,21,9,24,117,1,43,43,1,43,43,43,43,43,129,51,17,33,21,33,17,51,32,30,1,21,20,6,35,1,17,51,50,62,1,53,52,46,1,35,178,2,225,253,176,69,1,19,249,143,252,225,254,253,181,161,
150,89,126,188,185,5,191,145,254,42,97,209,128,168,254,2,196,253,204,63,131,81,102,142,45,0,255,255,0,183,0,0,4,40,5,191,2,22,0,37,0,0,0,1,0,177,0,0,3,146,5,191,0,5,0,34,182,4,94,2,2,1,8,3,184,1,21,64,
9,7,0,101,95,1,1,1,102,6,16,246,93,237,16,230,0,63,63,237,49,48,33,35,17,33,21,33,1,67,146,2,225,253,177,5,191,145,0,2,0,30,255,36,5,222,5,191,0,11,0,14,0,182,64,15,41,4,41,5,41,14,3,4,14,5,60,9,9,0,0,
184,255,192,64,55,12,13,57,0,11,14,13,14,12,13,86,6,5,20,6,6,5,14,12,14,13,12,86,3,4,20,3,3,4,14,5,4,3,2,3,6,7,13,5,12,94,11,8,4,14,5,59,11,101,2,10,101,7,13,6,184,255,192,64,16,17,26,57,6,32,6,6,7,14,
12,3,64,17,23,57,3,184,255,224,182,3,3,2,14,14,2,7,184,1,21,179,16,2,169,15,16,230,16,228,61,17,57,47,24,18,57,47,56,43,51,17,18,57,47,56,43,51,16,237,16,253,43,0,63,253,23,50,63,51,51,135,5,46,43,8,125,
16,196,135,5,46,24,43,8,125,16,196,0,17,51,43,24,47,51,47,43,49,48,0,93,23,35,17,51,1,51,1,51,17,35,53,33,55,33,1,175,145,120,2,65,51,2,97,115,145,251,98,141,3,129,254,52,220,1,101,5,54,250,202,254,155,
220,137,4,6,0,255,255,0,180,0,0,3,255,5,191,2,22,0,40,0,0,0,1,0,40,0,0,7,82,5,191,0,19,0,205,64,80,14,13,13,86,16,15,20,16,16,15,16,16,15,19,18,18,86,17,16,20,17,17,16,9,10,10,86,3,8,20,3,3,8,7,7,8,4,
5,5,86,6,7,20,6,6,7,4,7,10,13,16,19,6,3,3,0,2,8,9,14,15,4,11,2,5,6,17,18,4,2,8,7,4,3,8,19,16,0,14,15,184,255,224,178,15,18,17,187,255,224,0,15,0,17,1,195,64,10,1,9,8,32,8,5,6,32,8,6,184,1,195,64,12,13,
0,10,3,1,101,2,20,21,2,101,58,43,47,237,51,51,50,50,244,50,56,50,47,56,51,16,244,50,56,50,47,56,51,18,57,57,17,18,57,57,0,63,23,51,63,23,51,18,57,57,17,23,51,135,5,46,43,135,8,125,196,135,4,46,24,43,5,
125,16,196,135,46,24,43,135,8,125,196,135,4,46,24,43,5,125,16,196,49,48,1,17,35,17,39,1,35,9,1,51,1,17,51,17,1,51,9,1,35,1,4,7,149,45,253,166,195,2,190,253,122,198,2,76,149,2,77,199,253,122,2,189,195,
253,165,2,171,253,85,2,171,41,253,44,3,47,2,144,253,146,2,110,253,146,2,110,253,112,252,209,2,212,0,0,1,0,99,255,218,4,55,5,228,0,37,0,208,64,23,16,16,32,1,48,1,95,24,111,24,118,7,112,8,7,73,24,73,31,
89,31,3,36,184,255,192,179,19,21,57,17,184,255,192,64,25,15,23,57,40,8,7,29,94,28,28,12,37,35,122,0,2,3,16,19,122,15,12,9,37,0,186,255,240,0,0,255,192,64,31,13,16,57,0,0,15,7,5,28,28,9,15,32,112,111,5,
127,5,2,5,5,22,112,96,9,1,9,131,39,16,15,187,255,240,0,0,0,15,255,192,181,22,34,57,15,120,38,16,246,43,50,56,50,16,246,93,237,51,47,93,237,17,18,57,47,18,57,17,57,47,43,56,51,0,63,51,253,50,63,51,253,
50,18,57,47,237,57,49,48,67,121,64,28,33,34,20,21,10,11,3,4,20,11,22,117,1,34,3,32,117,1,21,10,19,117,0,33,4,35,117,1,43,43,1,43,43,129,129,129,129,1,43,43,93,0,93,19,54,51,50,22,21,20,7,4,17,20,4,35,
34,38,39,55,30,1,51,50,54,53,52,46,2,43,1,53,51,32,17,52,38,35,34,7,209,155,228,181,236,221,1,35,254,252,226,158,233,103,114,102,178,96,140,196,67,122,110,126,25,49,1,71,149,114,148,130,5,48,180,209,166,
235,102,90,254,212,200,244,131,164,67,150,85,162,157,83,123,76,20,129,1,9,123,145,134,0,1,0,180,0,0,5,55,5,191,0,9,0,65,64,36,15,2,1,2,8,7,7,86,3,2,20,3,3,2,7,3,2,8,6,2,3,1,8,2,101,8,9,174,11,7,3,6,101,
5,102,10,16,246,237,51,50,16,246,50,237,0,63,51,63,51,51,17,51,135,46,43,135,125,196,49,48,0,93,33,35,17,1,35,17,51,17,1,51,5,55,153,252,55,33,147,3,207,33,4,103,251,153,5,191,251,133,4,123,0,255,255,
0,180,0,0,5,55,7,31,2,54,1,246,0,0,1,23,0,219,1,37,1,42,0,17,64,10,1,21,32,1,0,10,18,5,0,51,43,53,0,63,53,0,255,255,0,179,0,0,4,146,5,191,2,22,0,46,0,0,255,255,0,67,0,0,5,90,5,191,1,31,0,57,5,157,5,191,
192,0,0,42,64,35,0,15,0,32,0,63,0,80,0,159,0,175,0,223,0,7,0,0,8,1,15,8,32,8,63,8,80,8,128,8,176,8,224,8,7,93,113,46,93,53,255,255,0,112,0,0,6,234,5,191,2,22,0,48,0,0,255,255,0,177,0,0,4,197,5,191,2,22,
0,43,0,0,255,255,0,115,255,219,6,128,5,228,2,22,0,50,0,0,0,1,0,177,0,0,4,197,5,191,0,7,0,40,64,23,5,94,0,2,3,7,8,3,101,80,2,1,2,174,9,6,101,94,7,1,7,102,8,16,246,93,237,16,246,93,237,0,63,51,63,237,49,
48,19,33,17,35,17,33,17,35,177,4,20,148,253,20,148,5,191,250,65,5,51,250,205,0,255,255,0,178,0,0,4,73,5,191,2,22,0,51,0,0,255,255,0,111,255,219,6,13,5,228,2,22,0,38,0,0,255,255,0,33,0,0,3,72,5,191,2,22,
0,55,0,0,0,1,0,67,255,219,4,222,5,191,0,17,0,182,179,182,2,1,12,184,255,192,179,17,21,57,6,184,255,192,64,82,9,17,57,9,5,27,5,2,17,2,5,60,2,2,1,17,3,3,4,5,5,86,17,3,20,17,17,3,1,0,17,17,86,2,1,20,2,17,
3,2,1,2,5,17,3,1,3,4,3,0,2,11,14,122,10,7,9,17,2,5,59,171,2,203,2,2,11,10,10,0,2,2,0,3,4,32,80,4,127,4,2,4,184,1,27,178,19,1,0,184,255,224,181,0,64,9,15,57,0,185,1,27,0,18,16,230,43,56,50,16,230,93,56,
50,61,17,57,47,24,18,57,47,51,93,43,0,63,51,253,50,63,23,51,23,50,135,8,46,43,135,5,125,196,135,14,46,24,43,135,5,125,196,7,8,60,43,49,48,1,93,43,43,0,93,19,51,9,1,51,1,6,35,34,38,39,55,30,1,51,50,54,
55,67,166,1,189,1,151,161,253,210,78,199,80,142,109,107,111,74,38,58,85,51,5,187,252,25,3,235,250,214,186,65,121,88,109,30,62,124,0,0,3,0,115,0,0,6,132,5,191,0,22,0,32,0,42,0,149,64,55,58,8,24,42,94,10,
13,13,0,12,23,33,94,2,22,22,12,0,2,12,8,10,2,24,101,22,13,42,43,44,42,101,58,29,112,223,6,239,6,2,6,131,44,37,112,0,18,208,18,224,18,3,18,120,43,16,246,93,237,16,246,93,237,43,47,51,51,253,50,50,0,63,
63,18,57,47,51,253,50,17,18,57,47,51,253,50,49,48,67,121,64,44,4,39,16,37,39,15,37,117,0,35,20,37,117,0,27,8,29,117,1,31,4,29,117,1,38,17,40,117,0,36,19,34,117,1,28,7,26,117,0,30,5,32,117,1,43,43,43,43,
1,43,43,43,43,43,129,1,51,21,51,32,0,21,20,2,33,35,17,35,17,35,34,46,1,53,52,0,33,51,23,17,51,23,50,54,53,52,38,35,33,35,34,6,21,20,22,51,55,51,3,50,147,113,1,76,1,2,227,254,195,159,147,158,168,220,157,
1,0,1,79,112,147,155,79,154,163,192,194,254,200,165,181,205,162,161,74,154,5,191,188,254,253,181,165,254,255,254,91,1,165,65,213,144,180,1,4,142,253,190,1,161,122,135,161,153,142,122,162,1,255,255,0,69,
0,0,4,155,5,191,2,22,0,59,0,0,0,1,0,178,255,36,5,125,5,191,0,11,0,61,185,0,11,255,192,64,22,9,13,57,6,3,2,5,8,94,0,11,11,0,8,5,101,8,8,4,0,101,9,184,1,21,181,13,4,101,1,102,12,16,246,237,16,246,237,17,
57,47,237,0,63,51,47,16,253,50,63,51,43,49,48,41,1,17,51,17,33,17,51,17,51,17,35,4,244,251,190,148,2,167,148,252,137,5,191,250,203,5,53,250,203,254,154,0,0,1,0,32,0,0,3,159,5,191,0,19,0,69,64,23,26,8,
0,94,5,5,1,4,8,1,13,2,0,4,101,3,174,21,13,101,12,169,20,16,246,237,16,246,253,50,0,63,51,63,17,57,47,253,49,48,67,121,64,18,7,16,9,10,8,10,2,6,16,7,14,117,0,15,10,17,117,0,43,1,43,42,129,1,17,51,17,35,
17,35,34,46,2,53,17,51,17,20,22,51,55,23,3,12,147,147,106,220,203,160,59,144,149,174,104,45,3,68,2,123,250,65,2,181,36,121,175,154,1,36,254,211,185,149,1,1,0,1,0,177,0,0,7,95,5,191,0,11,0,55,64,33,6,3,
11,2,4,0,94,9,8,4,101,1,12,13,1,101,58,5,101,80,8,1,8,174,13,0,101,95,9,1,9,102,12,16,246,93,237,16,246,93,237,43,47,237,0,63,253,50,63,51,51,49,48,37,33,17,51,17,33,17,51,17,33,17,51,1,69,2,116,148,2,
126,148,249,82,148,139,5,52,250,204,5,52,250,65,5,191,0,0,2,0,177,255,36,8,91,5,191,0,15,0,16,0,84,185,0,3,255,192,64,19,9,13,57,15,11,7,2,12,8,0,94,4,3,3,4,8,4,101,1,184,1,21,64,25,18,12,101,9,17,16,
9,101,58,13,101,0,174,80,16,1,16,8,101,95,5,1,5,102,17,16,246,93,237,47,93,246,237,43,47,237,16,246,253,0,63,51,47,16,253,50,50,63,51,51,43,49,48,37,51,17,35,53,33,17,51,17,33,17,51,17,33,17,51,19,7,95,
252,138,248,224,148,2,116,148,2,126,148,177,139,254,153,220,5,191,250,204,5,52,250,204,5,52,251,209,0,0,2,0,32,0,0,5,6,5,191,0,14,0,25,0,110,64,37,43,8,4,94,25,25,14,0,94,3,2,14,8,25,4,101,0,15,94,14,
31,0,1,0,0,1,20,112,223,9,1,9,131,27,1,169,26,16,230,16,246,93,237,18,57,47,93,0,16,237,1,16,253,60,0,63,63,237,18,57,47,237,49,48,67,121,64,30,6,23,11,38,18,37,7,37,22,38,17,12,20,117,1,23,6,20,117,1,
19,10,16,117,0,21,8,24,117,1,43,43,1,43,43,43,43,43,43,129,1,33,53,33,17,51,32,30,1,21,20,14,1,41,1,55,51,50,62,1,53,52,46,1,43,1,1,82,254,206,1,197,105,1,34,252,154,150,233,254,240,254,219,147,157,248,
151,89,112,173,236,124,5,53,138,253,137,56,201,159,157,204,63,142,47,128,100,110,138,31,0,3,0,178,0,0,5,166,5,191,0,12,0,23,0,27,0,100,64,31,43,8,2,94,23,23,12,24,1,2,13,94,27,12,8,18,112,7,7,13,27,101,
26,174,29,2,13,101,12,102,28,16,244,253,50,16,246,237,17,57,47,237,0,63,51,237,63,51,18,57,47,237,49,48,67,121,64,30,4,21,9,38,16,37,5,37,20,38,15,10,18,117,1,21,4,18,117,1,17,8,14,117,0,19,6,22,117,1,
43,43,1,43,43,43,43,43,43,129,19,51,17,51,32,30,1,21,20,14,1,41,1,55,51,50,62,1,53,52,46,1,43,1,1,51,17,35,178,147,106,1,33,252,154,150,232,254,239,254,219,147,157,248,151,89,112,173,236,124,3,206,147,
147,5,191,253,137,56,201,159,156,205,63,142,47,128,100,110,138,31,3,7,250,65,0,0,2,0,178,0,0,4,102,5,191,0,12,0,23,0,87,64,24,43,8,2,94,23,23,11,1,2,14,94,11,8,18,112,7,131,25,2,13,101,12,102,24,16,246,
253,50,16,246,237,0,63,237,63,18,57,47,237,49,48,67,121,64,30,4,21,9,38,16,37,5,37,20,38,15,10,18,117,1,21,4,18,117,1,17,8,14,117,0,19,6,22,117,1,43,43,1,43,43,43,43,43,43,129,19,51,17,51,32,30,1,21,20,
14,1,41,1,55,51,50,62,1,53,52,46,1,43,1,178,147,106,1,33,252,154,150,232,254,239,254,219,147,157,248,151,89,112,173,236,124,5,191,253,137,56,201,159,156,205,63,142,47,128,100,110,138,31,0,1,0,111,255,
219,6,13,5,228,0,25,0,178,64,17,11,5,0,16,13,19,0,25,4,15,5,15,13,15,24,3,22,184,255,192,179,12,21,57,7,184,255,192,64,44,12,21,57,45,8,8,6,9,12,21,23,20,18,1,94,15,2,47,2,255,2,3,2,2,18,6,122,12,3,23,
122,18,9,1,1,20,3,0,112,15,131,27,8,9,184,255,240,178,9,21,20,184,255,240,179,9,20,120,26,16,246,50,56,50,47,56,51,16,246,253,50,18,57,47,0,63,237,63,237,18,57,47,93,237,17,51,17,51,17,51,17,51,49,48,
67,121,64,30,24,25,13,17,4,5,24,17,0,100,1,25,0,5,13,3,100,1,4,3,25,16,23,100,0,4,14,6,100,1,43,43,1,16,60,43,16,60,43,129,129,129,1,43,43,93,0,93,1,33,53,33,38,0,35,32,7,39,54,36,51,32,0,17,16,0,33,32,
3,55,22,33,50,0,5,108,253,73,2,177,19,254,133,230,254,180,194,117,100,1,83,206,1,82,1,199,254,81,254,148,254,100,231,117,206,1,54,237,1,111,2,157,145,252,1,41,254,89,144,166,254,72,254,188,254,185,254,
58,1,37,88,242,1,21,0,2,0,177,255,219,8,80,5,228,0,18,0,30,0,145,64,52,61,8,13,94,15,1,47,1,255,1,3,1,1,18,15,28,122,10,9,22,122,4,3,18,2,15,8,25,112,13,47,1,1,63,1,175,1,2,1,1,0,19,112,7,131,32,0,15,
101,16,102,31,16,246,253,50,16,246,237,18,57,47,93,113,51,237,0,63,63,63,237,63,237,17,18,57,47,93,237,67,121,64,45,2,30,29,9,19,100,1,21,5,19,100,1,27,11,25,100,0,12,13,23,3,25,100,0,2,30,8,28,100,0,
20,6,22,100,1,26,12,28,100,0,24,2,22,100,1,43,43,43,43,1,60,43,16,60,43,43,43,129,49,48,1,33,18,0,33,32,0,17,16,0,33,32,0,3,33,17,35,17,51,1,16,0,35,34,0,17,16,0,51,32,0,1,68,1,2,56,1,193,1,0,1,77,1,196,
254,64,254,187,254,214,254,70,33,254,254,147,147,6,116,254,135,248,247,254,140,1,113,250,1,3,1,110,3,46,1,98,1,84,254,66,254,186,254,190,254,61,1,127,1,75,253,91,5,191,253,33,1,17,1,100,254,151,254,237,
254,244,254,157,1,102,0,255,255,0,72,0,0,3,245,5,191,0,71,0,53,4,176,0,0,192,0,64,0,255,255,0,107,255,228,4,216,4,92,2,22,0,68,0,0,0,2,0,104,255,228,4,242,5,251,0,27,0,39,0,172,64,83,9,7,45,7,41,24,73,
7,89,7,96,23,107,33,116,23,148,23,202,33,217,6,217,24,233,6,233,24,14,49,8,3,88,26,0,26,0,1,88,0,1,33,31,88,9,0,12,1,12,7,37,88,18,11,1,1,28,105,15,133,41,15,34,1,9,34,223,34,239,34,255,34,4,176,34,192,
34,249,34,3,34,34,9,184,1,38,178,21,96,40,16,246,253,50,47,93,113,114,16,246,237,51,47,0,63,237,63,93,51,253,50,63,237,63,63,237,67,121,64,36,35,39,29,30,13,20,38,17,28,90,1,36,19,34,90,0,30,13,28,90,
1,39,16,37,90,0,35,20,37,90,0,29,14,31,90,1,43,43,43,1,43,43,43,129,129,129,0,93,49,48,1,21,6,7,14,3,15,1,54,36,51,50,0,21,20,0,35,34,0,17,16,18,54,36,37,54,19,52,2,35,34,2,21,20,22,51,50,54,4,173,100,
243,176,191,142,97,12,14,57,1,5,159,242,1,69,254,188,243,249,254,166,127,164,1,4,1,101,110,2,252,173,172,252,243,181,182,243,5,251,134,17,7,6,35,99,201,124,153,187,174,254,172,235,233,254,176,1,116,1,
144,1,23,1,31,126,72,9,3,252,42,181,1,4,254,252,181,180,253,253,0,0,3,0,156,0,0,3,100,4,64,0,11,0,22,0,32,0,119,64,53,11,11,25,11,148,9,150,28,164,9,164,28,180,17,196,17,8,25,8,8,13,88,23,23,0,22,88,3,
6,25,88,0,10,8,29,18,105,6,6,30,105,182,10,198,10,2,10,133,34,13,24,92,1,184,255,192,181,20,22,57,1,139,33,16,246,43,253,50,16,246,93,237,51,47,253,17,57,0,63,237,63,237,18,57,47,253,57,49,48,67,121,64,
16,19,21,4,5,20,38,21,4,18,128,1,19,5,22,128,1,43,1,43,43,129,129,0,93,41,1,17,33,50,22,21,20,7,22,21,16,1,17,51,50,62,1,53,52,46,1,35,3,17,51,50,62,1,53,52,38,35,1,216,254,196,1,55,178,157,146,212,253,
197,91,124,76,67,70,77,120,91,150,106,91,65,112,92,4,64,164,110,166,59,75,214,254,212,3,199,254,172,20,79,65,68,92,16,254,44,254,131,27,90,69,89,106,0,0,1,0,156,0,0,2,194,4,64,0,5,0,45,182,0,88,3,6,1,
10,5,184,255,192,64,9,9,11,57,5,242,7,1,92,2,184,255,192,181,20,22,57,2,139,6,16,246,43,237,16,230,43,0,63,63,237,49,48,1,17,35,17,33,21,1,39,139,2,38,3,197,252,59,4,64,123,0,0,2,0,33,255,111,4,182,4,
64,0,11,0,14,0,198,64,51,43,12,1,36,1,43,2,2,2,12,1,60,12,16,12,14,12,13,14,91,3,2,20,3,3,2,12,13,12,14,13,91,0,1,20,0,0,1,12,2,1,6,3,13,14,3,0,88,8,6,9,184,255,192,64,18,12,21,57,9,9,8,10,2,12,1,59,13,
0,14,105,3,1,3,184,255,192,64,18,15,22,57,3,16,3,3,4,12,102,0,1,0,64,15,22,57,0,184,255,240,183,0,0,12,12,11,7,92,4,184,255,192,64,14,9,11,57,4,242,16,8,92,11,242,15,112,16,1,93,16,246,237,16,246,43,237,
61,18,57,47,24,57,47,56,43,93,17,18,57,47,56,43,93,51,17,51,43,0,63,51,47,43,51,16,253,23,50,63,51,51,135,5,46,43,8,125,16,196,135,5,46,24,43,8,125,16,196,0,56,43,49,48,1,93,0,93,55,1,51,1,51,17,35,53,
33,21,35,17,9,1,33,165,1,164,73,1,161,131,135,252,124,138,2,74,254,194,2,111,119,3,201,252,55,254,254,139,145,1,8,2,241,253,15,0,255,255,0,104,255,228,4,202,4,92,2,22,0,72,0,0,0,1,255,244,0,0,6,50,4,64,
0,19,0,243,177,19,2,184,255,240,64,94,2,5,8,7,7,91,6,5,20,6,6,5,2,9,4,4,91,3,2,20,3,3,2,16,13,14,14,91,15,16,20,15,15,16,19,12,17,17,91,18,19,20,18,18,19,2,5,8,9,13,16,19,7,12,12,11,3,4,17,18,4,0,6,6,
7,14,15,4,11,10,2,5,8,9,4,10,3,4,16,48,4,80,4,96,4,159,4,4,4,4,7,6,16,6,184,2,48,64,11,10,92,11,12,13,16,19,4,11,18,17,184,255,240,64,13,63,17,95,17,111,17,144,17,4,17,17,14,15,186,255,240,0,15,2,48,64,
15,11,20,21,11,92,58,64,21,96,21,112,21,144,21,4,93,43,47,125,228,24,56,50,50,47,93,56,51,18,23,57,16,253,125,228,24,56,50,50,47,93,56,51,18,23,57,0,63,23,51,63,23,51,18,57,17,23,51,135,5,46,43,135,4,
125,196,135,5,46,24,43,135,14,125,196,135,5,46,24,43,135,4,125,196,135,5,46,24,43,135,14,125,196,0,23,56,49,48,1,51,17,1,51,9,1,35,1,7,17,35,17,39,1,35,9,1,51,1,2,202,142,2,8,171,253,254,2,41,179,254,
41,80,142,78,254,43,179,2,35,254,6,171,2,2,4,64,254,31,1,225,254,27,253,165,2,14,67,254,53,1,203,67,253,242,2,91,1,229,254,31,0,0,1,0,55,255,227,3,11,4,94,0,34,0,212,64,25,196,8,196,26,219,13,235,13,4,
17,32,16,29,57,59,9,68,11,2,31,64,16,21,57,3,184,255,192,179,16,21,57,25,184,255,224,64,29,9,12,57,40,8,17,17,0,144,34,34,22,9,7,88,10,12,7,25,27,88,24,22,11,25,9,17,15,34,184,255,220,64,30,9,12,57,34,
34,19,24,4,105,208,15,1,15,15,30,105,63,19,1,19,133,36,9,10,10,25,63,24,1,24,184,255,192,179,20,27,57,24,185,2,50,0,35,16,244,43,93,50,50,47,51,16,244,113,237,51,47,93,237,17,18,57,47,43,18,57,25,47,47,
0,24,63,51,253,50,63,51,253,50,18,57,47,237,61,57,47,24,49,48,67,121,64,28,28,29,20,21,13,14,5,6,28,21,30,128,1,6,13,4,128,1,29,20,27,128,0,5,14,7,128,1,43,43,1,43,43,129,129,129,129,0,43,43,43,93,1,43,
93,1,51,50,54,53,52,38,35,34,7,39,54,51,50,22,21,20,7,22,21,20,6,35,34,39,55,22,51,50,54,53,52,38,43,1,1,82,73,70,117,94,97,113,114,79,147,165,136,184,150,196,183,182,223,136,88,101,158,106,121,122,83,
86,2,118,92,86,73,105,88,97,123,162,128,170,61,82,205,130,209,145,100,114,114,93,91,110,0,0,1,0,156,0,0,4,82,4,64,0,9,0,86,64,9,229,1,234,6,2,6,2,1,1,184,2,113,64,31,7,6,20,7,7,6,3,2,0,6,8,7,5,10,6,92,
2,2,3,64,20,22,57,3,118,11,1,92,7,7,8,184,255,192,181,20,22,57,8,139,10,16,246,43,50,201,237,16,246,43,50,201,237,0,63,51,51,63,51,51,135,46,43,135,125,196,49,48,0,93,1,17,1,51,17,35,17,1,35,17,1,40,3,
31,11,140,252,231,17,4,64,252,219,3,37,251,192,3,30,252,226,4,64,0,255,255,0,156,0,0,4,82,5,245,2,54,2,22,0,0,1,23,0,219,0,167,0,0,0,18,64,10,1,0,10,18,9,3,51,1,21,34,0,63,53,1,43,53,0,1,0,156,0,0,4,15,
4,64,0,11,0,143,179,196,7,1,2,184,255,240,64,48,5,8,7,7,91,6,5,20,6,6,5,3,2,2,91,9,4,20,9,9,4,2,5,8,3,9,9,10,4,3,1,6,6,7,10,3,11,10,5,8,3,9,4,1,4,4,7,6,184,255,224,64,9,9,16,57,41,6,1,6,32,6,184,2,48,
182,2,8,9,3,10,92,11,184,255,192,181,20,22,57,11,139,12,16,246,43,253,23,50,228,56,93,43,50,50,47,93,51,17,51,0,63,23,51,63,51,51,18,57,17,23,51,135,46,43,5,125,16,196,135,46,24,43,135,14,125,196,49,48,
0,56,1,113,19,51,17,1,51,9,1,35,1,7,17,35,156,141,1,247,195,253,217,2,83,198,254,12,44,141,4,64,254,54,1,202,254,14,253,178,1,247,39,254,48,0,1,0,53,0,0,4,53,4,64,0,6,0,143,64,61,13,2,1,4,5,13,6,2,2,16,
6,2,5,60,2,1,2,3,1,91,0,6,20,0,0,6,2,3,2,1,3,91,4,5,20,4,4,5,6,2,5,6,0,1,3,3,4,10,6,5,6,2,5,59,2,2,4,1,0,16,0,184,255,192,179,9,11,57,0,184,2,50,178,8,3,4,186,255,240,0,4,2,50,181,7,48,8,160,8,2,93,16,
230,56,50,16,230,43,56,50,61,17,57,47,24,43,51,51,0,63,23,51,63,51,51,135,5,46,43,8,125,16,196,135,5,46,24,43,8,125,16,196,43,0,56,49,48,1,93,0,93,33,35,9,1,35,1,51,4,53,149,254,148,254,151,150,1,242,
25,3,24,252,232,4,64,0,0,1,0,54,0,0,6,210,4,64,0,12,1,105,64,207,86,4,86,7,80,12,3,4,1,6,4,6,7,16,1,20,4,20,7,70,7,7,121,5,137,6,136,11,3,86,1,90,5,88,12,3,57,6,57,11,70,1,73,6,4,25,0,21,11,41,6,41,11,
4,1,4,0,60,4,3,4,5,3,91,2,1,20,2,2,1,4,4,3,0,12,12,91,5,4,20,5,12,11,5,4,1,4,0,59,4,4,12,2,11,7,10,60,7,7,8,11,12,12,91,6,7,20,6,12,0,6,7,7,8,7,6,8,91,9,10,20,9,9,10,11,7,10,59,7,7,12,9,6,12,5,60,4,4,
3,0,12,12,91,5,4,20,5,12,11,5,4,7,7,8,11,12,12,91,6,7,20,6,12,0,6,7,0,1,4,7,11,5,10,6,12,2,3,5,6,8,5,9,10,6,12,5,59,1,0,4,4,2,12,11,10,7,7,9,6,5,12,12,9,3,2,16,2,184,255,192,179,9,19,57,2,184,2,50,178,
14,8,9,184,255,240,181,9,64,12,19,57,9,184,2,50,179,13,16,14,1,93,16,230,43,56,50,16,228,43,56,50,61,17,57,47,51,51,25,18,57,47,51,51,17,18,57,47,51,51,24,43,0,24,63,23,51,51,63,23,51,135,8,46,43,135,
8,125,196,135,8,46,24,43,135,8,125,196,43,1,25,17,18,57,47,43,135,46,24,43,8,125,16,196,135,8,46,24,43,135,8,125,196,43,1,25,17,18,57,47,43,135,8,46,24,43,135,8,125,196,135,5,46,24,43,8,125,16,196,43,
49,48,1,93,93,93,93,0,93,93,1,51,1,35,9,1,35,9,1,35,1,51,1,5,57,40,1,113,146,254,243,254,94,26,254,93,254,244,146,1,115,38,1,182,4,64,251,192,3,33,252,223,3,33,252,223,4,64,252,173,0,0,1,0,156,0,0,4,45,
4,64,0,11,0,67,64,32,1,144,176,6,192,6,2,6,6,2,8,5,6,11,2,10,6,2,7,11,92,10,64,20,22,57,10,118,13,2,92,3,184,255,192,181,20,22,57,3,139,12,16,246,43,237,16,244,43,253,50,17,51,0,63,51,63,51,18,57,47,93,
253,49,48,1,33,17,35,17,51,17,33,17,51,17,35,3,161,253,136,141,141,2,120,140,140,2,12,253,244,4,64,254,80,1,176,251,192,0,255,255,0,104,255,228,4,213,4,92,2,22,0,82,0,0,0,1,0,156,0,0,4,45,4,64,0,7,0,47,
64,20,5,144,0,6,3,6,10,3,92,2,64,20,22,57,2,118,9,6,92,7,184,255,192,181,20,22,57,7,139,8,16,246,43,237,16,246,43,237,0,63,51,63,237,49,48,19,33,17,35,17,33,17,35,156,3,145,140,253,135,140,4,64,251,192,
3,188,252,68,255,255,0,158,254,114,5,11,4,92,2,22,0,83,0,0,255,255,0,105,255,228,4,188,4,92,2,22,0,70,0,0,0,1,0,34,0,0,2,238,4,64,0,7,0,51,64,11,5,10,3,7,144,0,6,2,242,9,7,184,255,192,64,17,9,11,57,7,
242,8,4,92,5,8,9,5,92,58,15,9,1,93,43,47,237,16,238,43,16,238,0,63,253,50,63,49,48,19,33,21,33,17,35,17,33,34,2,204,254,224,141,254,225,4,64,121,252,57,3,199,255,255,0,39,254,114,4,49,4,64,2,22,0,92,0,
0,0,3,0,104,254,114,8,65,5,228,0,25,0,37,0,51,0,215,64,39,146,2,155,12,155,15,146,25,4,164,2,169,12,169,15,164,25,4,132,27,137,37,182,2,185,15,182,25,198,25,6,67,8,15,12,16,2,25,2,184,255,240,64,59,2,
35,37,47,3,49,88,2,4,25,3,23,7,0,0,27,29,44,3,41,88,10,12,15,3,17,11,14,14,32,105,7,133,53,38,105,20,96,52,26,26,14,46,46,2,13,92,25,14,52,53,14,92,58,16,53,224,53,2,93,43,47,51,253,50,57,47,17,57,47,
16,246,237,16,246,237,0,63,63,23,51,253,23,50,63,63,23,51,253,23,50,23,56,23,56,49,48,67,121,64,50,50,51,39,40,30,34,18,22,5,9,30,9,32,90,1,40,18,38,90,0,34,5,32,90,1,50,22,38,90,0,31,8,29,90,0,39,19,
41,90,0,33,6,35,90,1,51,21,49,90,1,43,43,43,43,1,43,43,43,43,129,129,129,129,129,0,93,93,93,1,51,17,54,51,50,0,21,20,0,35,34,39,17,35,17,6,33,34,0,53,52,0,51,50,23,19,20,22,51,50,18,53,52,38,35,34,6,5,
20,18,51,50,62,2,53,52,38,35,34,6,4,15,139,131,246,237,1,65,254,188,230,252,129,139,127,254,255,226,254,187,1,65,237,251,126,135,222,144,196,236,249,174,157,218,252,95,235,197,68,156,95,48,220,156,175,
248,5,228,253,184,186,254,190,252,249,254,192,196,253,207,2,49,197,1,64,250,252,1,66,186,254,106,195,222,1,4,183,189,250,223,217,182,254,252,69,105,138,133,212,225,250,0,255,255,255,249,0,0,3,223,4,64,
2,18,0,91,0,0,0,1,0,156,255,84,5,25,4,64,0,11,0,77,179,6,3,6,11,184,255,192,64,19,12,17,57,5,8,144,0,11,11,0,10,8,92,5,5,1,0,92,9,184,255,192,64,9,9,12,57,9,242,13,4,92,1,184,255,192,181,20,22,57,1,139,
12,16,246,43,237,16,246,43,237,18,57,47,237,0,63,51,47,16,253,50,43,63,51,49,48,41,1,17,51,17,33,17,51,17,51,17,35,4,149,252,7,141,2,120,141,235,132,4,64,252,68,3,188,252,68,254,208,0,0,1,0,69,0,0,3,14,
4,64,0,15,0,71,64,26,19,8,0,144,11,11,14,6,12,6,14,10,11,0,92,14,64,20,22,57,14,118,17,7,92,4,185,2,46,0,16,16,246,237,16,246,43,253,50,0,63,63,51,18,57,47,253,49,48,67,121,64,12,2,9,9,2,7,128,0,8,3,10,
128,0,43,1,43,129,1,35,34,38,53,17,51,21,20,22,59,1,17,51,17,35,2,131,246,167,161,137,108,124,205,139,139,1,235,172,153,1,16,197,190,91,1,222,251,192,0,0,1,0,156,0,0,6,246,4,64,0,11,0,67,64,30,10,6,3,
6,8,4,144,1,10,8,92,5,12,13,5,92,58,9,92,0,64,20,22,57,0,118,13,4,92,1,184,255,192,64,9,20,22,57,1,139,12,0,13,1,93,16,246,43,237,16,244,43,237,43,47,237,0,63,253,50,63,51,51,49,48,41,1,17,51,17,33,17,
51,17,33,17,51,6,246,249,166,141,2,87,143,2,88,143,4,64,252,68,3,188,252,68,3,188,0,2,0,156,255,84,7,226,4,64,0,15,0,16,0,104,185,0,15,255,192,64,27,12,17,57,10,3,6,6,8,5,12,144,0,15,15,0,10,8,92,5,17,
16,5,92,58,0,92,13,184,255,192,64,19,9,12,57,13,242,18,9,92,12,64,20,22,57,12,118,16,4,92,1,184,255,192,64,10,20,22,57,1,139,17,0,16,1,16,47,93,16,246,43,237,16,246,43,237,16,246,43,237,43,47,237,0,63,
51,47,16,253,50,50,63,51,51,43,49,48,41,1,17,51,17,33,17,51,17,33,17,51,17,51,17,35,19,7,93,249,63,141,2,88,142,2,88,143,236,133,52,4,64,252,68,3,188,252,68,3,188,252,68,254,208,1,216,0,0,2,0,55,0,0,3,
228,4,64,0,13,0,22,0,95,64,46,166,4,164,6,2,17,32,15,18,57,20,32,15,18,57,0,3,15,7,16,3,31,7,4,14,144,0,0,9,10,144,13,6,15,144,9,10,14,13,92,10,10,11,18,105,5,187,2,46,0,24,0,11,255,192,179,20,22,57,11,
185,2,50,0,23,16,230,43,16,254,237,18,57,47,253,50,0,63,237,63,237,18,57,47,237,49,48,0,93,1,43,43,93,1,51,50,30,1,21,20,6,35,33,17,35,53,33,25,1,51,32,53,52,46,1,35,1,137,134,159,180,130,189,190,254,
150,200,1,82,161,1,32,77,125,128,2,145,50,171,111,134,191,3,192,128,253,219,254,91,208,71,107,35,0,0,3,0,156,0,0,4,207,4,64,0,11,0,20,0,24,0,89,64,47,4,3,11,7,20,3,27,7,4,164,6,1,12,144,0,0,8,21,11,6,
14,144,24,8,10,16,105,154,5,1,5,5,13,24,92,23,64,20,22,57,23,118,26,0,13,92,9,184,255,192,181,20,22,57,9,139,25,16,246,43,253,50,16,246,43,237,17,57,47,93,237,0,63,51,237,63,51,18,57,47,237,49,48,1,93,
0,93,1,51,50,30,1,21,20,6,35,33,17,51,19,17,51,32,53,52,46,1,35,1,51,17,35,1,39,133,159,180,130,188,191,254,150,139,5,161,1,28,61,117,148,2,159,141,141,2,145,50,171,111,134,191,4,64,253,209,254,101,200,
57,110,44,2,47,251,192,0,0,2,0,156,0,0,3,129,4,64,0,11,0,20,0,73,64,21,4,3,11,7,20,3,27,7,4,12,144,0,0,9,10,6,13,144,9,10,16,184,1,41,181,153,5,166,5,2,5,184,2,46,180,22,0,13,92,9,184,255,192,181,20,22,
57,9,139,21,16,246,43,253,50,16,252,93,237,0,63,237,63,18,57,47,237,49,48,0,93,1,51,50,30,1,21,20,6,35,33,17,51,19,17,51,32,53,52,46,1,35,1,39,133,159,180,130,188,191,254,150,139,5,161,1,28,61,117,148,
2,145,50,171,111,134,191,4,64,253,209,254,101,200,57,110,44,0,255,255,0,104,255,228,4,187,4,92,1,87,2,49,5,35,0,0,192,0,64,0,0,14,64,9,0,0,12,16,12,32,12,3,12,47,93,53,0,2,0,157,255,228,6,72,4,92,0,18,
0,30,0,156,64,52,63,8,18,144,4,4,2,0,10,28,88,14,11,22,88,8,7,2,6,25,105,5,63,17,79,17,143,17,3,95,17,111,17,127,17,175,17,191,17,5,17,17,1,19,105,11,133,32,4,18,92,1,184,255,192,181,20,22,57,1,139,31,
16,246,43,253,50,16,246,237,18,57,47,93,113,51,237,0,63,63,237,63,237,63,18,57,47,237,49,48,67,121,64,46,6,30,29,13,19,90,1,27,15,25,90,0,16,17,21,9,19,90,1,23,7,25,90,0,6,5,30,12,28,90,0,26,16,28,90,
0,20,10,22,90,1,24,6,22,90,1,43,43,43,43,1,16,60,43,43,16,60,43,43,129,33,35,17,51,17,51,54,0,51,50,0,21,20,0,35,34,0,39,35,37,52,2,35,34,2,21,20,22,51,50,54,1,42,141,141,182,37,1,59,209,242,1,69,254,
188,242,216,254,189,23,182,4,144,252,172,173,252,241,184,181,243,4,64,254,55,218,1,11,254,172,235,233,254,176,1,27,238,45,181,1,4,254,252,181,180,253,253,0,0,2,0,54,0,0,2,243,4,64,0,13,0,24,0,127,64,62,
15,5,31,5,2,4,9,20,9,2,4,1,2,2,91,3,4,20,3,3,4,4,1,144,24,24,11,3,2,12,10,14,144,11,6,4,1,16,0,1,16,1,2,1,1,24,13,92,12,64,20,22,57,12,118,26,2,3,19,105,7,3,184,255,240,64,13,186,7,202,7,2,3,3,7,96,25,
63,26,1,93,16,230,57,47,93,56,16,237,17,51,16,246,43,253,50,50,47,93,56,51,0,63,237,63,51,51,18,57,47,253,50,135,5,46,43,135,125,196,49,48,0,93,1,93,1,35,1,35,1,46,1,53,52,54,51,33,17,35,17,35,34,14,1,
21,20,30,1,59,1,2,103,100,254,202,151,1,71,122,152,175,142,1,75,140,92,134,92,54,70,86,124,92,1,231,254,25,1,245,15,155,115,144,158,251,192,3,199,34,83,70,67,87,20,255,255,0,104,255,228,4,202,5,238,2,
38,0,72,0,0,1,7,0,142,1,32,0,0,0,22,64,12,3,2,0,42,48,8,16,51,3,2,39,34,0,63,53,53,1,43,53,53,0,1,0,35,254,86,4,117,5,228,0,41,0,188,185,0,14,255,192,64,26,9,19,57,4,6,4,13,116,6,114,31,194,6,194,31,194,
32,7,28,8,141,5,141,32,2,5,184,255,240,64,52,40,2,144,37,3,3,0,32,29,88,5,0,7,1,7,7,18,20,144,17,15,15,35,10,0,0,3,3,12,5,18,18,24,92,12,64,20,22,57,12,118,43,5,1,35,92,36,39,39,40,40,36,184,255,192,64,
17,20,22,57,36,139,42,0,43,48,43,128,43,176,43,208,43,5,93,16,246,43,50,17,51,47,16,253,50,50,16,246,43,253,50,47,17,18,57,47,0,63,63,63,51,253,50,63,93,51,253,50,18,57,47,51,253,50,56,93,49,48,67,121,
64,18,26,28,8,10,9,37,27,38,28,8,25,90,1,26,10,29,90,1,43,1,43,43,43,129,129,1,93,43,1,21,33,21,33,17,54,51,50,30,1,21,17,23,16,35,34,39,53,22,51,50,62,1,53,17,52,46,1,35,34,14,2,21,17,35,17,35,53,51,
53,1,73,1,224,254,32,170,238,142,198,62,2,186,73,86,54,47,49,50,3,41,137,111,97,151,101,32,139,155,155,5,228,136,120,254,153,223,157,211,188,253,208,164,254,250,34,126,29,64,82,149,2,7,189,170,109,88,
148,158,194,254,113,4,228,120,136,0,255,255,0,156,0,0,2,226,6,62,2,54,2,17,0,0,1,22,0,141,71,0,0,7,178,1,9,34,0,63,53,0,0,1,0,104,255,228,4,187,4,92,0,26,0,159,181,137,4,137,7,2,7,184,255,192,179,18,21,
57,17,184,255,192,64,18,18,21,57,20,64,15,21,57,4,64,15,21,57,45,8,25,144,26,184,255,192,64,36,26,27,57,26,26,9,21,88,15,7,3,88,9,11,26,26,12,19,18,16,18,18,5,6,16,6,133,28,24,0,8,0,105,12,96,27,16,246,
237,56,50,16,230,56,50,50,47,56,51,17,57,47,0,63,237,63,237,18,57,47,43,237,49,48,67,121,64,30,22,23,10,14,1,2,2,10,0,90,0,1,0,22,14,24,90,0,23,24,1,11,3,90,0,23,13,21,90,1,43,43,1,16,60,43,16,60,43,129,
129,129,1,43,43,43,43,93,19,22,4,51,50,55,23,6,4,35,32,0,53,52,0,33,50,4,23,7,38,35,34,6,7,33,21,247,20,1,4,181,240,152,111,78,254,234,153,254,249,254,177,1,89,1,8,153,1,21,68,111,144,249,174,251,35,1,
228,1,247,183,220,191,73,124,122,1,77,230,243,1,82,133,121,69,191,202,159,120,0,255,255,0,54,255,228,2,192,4,92,2,22,0,86,0,0,255,255,0,90,0,0,1,65,6,0,2,6,0,76,0,0,255,255,255,141,0,0,2,13,5,238,2,38,
0,215,0,0,1,7,0,142,255,83,0,0,0,22,64,12,2,1,0,13,19,0,1,51,2,1,10,34,0,63,53,53,1,43,53,53,255,255,255,192,254,86,1,67,6,0,2,22,0,77,0,0,0,3,0,54,0,0,6,20,4,64,0,14,0,23,0,24,0,202,64,103,4,4,11,8,15,
11,16,4,27,8,69,0,155,8,166,1,8,16,15,1,0,0,24,4,14,1,25,11,0,2,0,11,14,60,11,10,11,12,10,91,24,0,20,24,24,0,11,12,11,10,12,91,13,14,20,13,13,14,15,144,1,1,0,10,16,144,24,12,13,24,3,10,10,11,0,14,6,0,
11,14,59,14,0,11,11,192,24,1,16,10,24,16,24,24,13,19,105,154,6,166,6,2,6,184,2,46,178,26,12,13,184,255,240,64,10,63,13,79,13,127,13,143,13,4,13,185,2,50,0,25,16,228,93,56,50,16,254,93,237,18,57,47,56,
51,51,93,61,57,47,24,51,51,43,0,63,51,51,63,23,51,16,237,17,18,57,47,237,135,5,46,43,8,125,16,196,135,5,46,24,43,8,125,16,196,43,0,23,56,1,93,135,5,16,196,60,60,49,48,0,93,1,19,33,50,30,1,21,20,6,7,33,
9,1,35,9,1,19,51,32,53,52,46,1,35,3,2,65,200,1,54,160,181,128,140,172,254,197,254,143,254,146,140,1,242,1,25,185,102,1,28,75,119,132,6,4,64,254,81,51,172,111,105,191,27,3,60,252,196,4,64,253,209,254,101,
200,71,105,35,253,239,0,2,0,156,0,0,6,129,4,64,0,19,0,28,0,103,64,47,11,7,27,7,2,4,3,20,3,2,20,10,144,0,17,17,18,21,144,9,18,15,6,9,12,10,0,17,21,92,16,9,1,9,9,5,13,16,12,24,105,153,5,166,5,2,5,184,2,
46,179,30,12,92,13,184,255,192,181,20,22,57,13,139,29,16,246,43,237,16,254,93,237,17,51,17,18,57,47,93,237,51,50,0,63,51,63,51,16,237,18,57,47,51,253,50,49,48,0,93,93,1,51,50,30,1,21,20,6,35,33,17,33,
17,35,17,51,17,33,17,51,25,1,51,32,53,52,46,1,35,4,45,128,158,181,129,188,190,254,154,253,137,142,142,2,119,140,160,1,28,61,118,147,2,144,51,171,110,133,191,2,12,253,244,4,64,254,80,1,176,253,204,254,
106,197,56,109,44,0,1,0,36,0,0,4,116,5,228,0,30,0,156,64,19,4,11,116,11,112,25,196,11,196,25,5,25,8,143,10,143,26,2,10,184,255,240,64,43,3,7,144,0,8,8,4,26,23,88,10,0,12,1,12,7,18,29,10,4,0,8,8,30,18,
92,17,64,20,22,57,17,118,32,10,6,29,92,30,3,1,1,30,184,255,192,64,17,20,22,57,30,139,31,0,32,48,32,128,32,176,32,208,32,5,93,16,246,43,50,47,50,16,253,50,50,16,246,43,237,18,57,47,0,63,63,51,63,93,51,
253,50,18,57,47,51,253,50,56,93,49,48,67,121,64,16,13,22,14,37,21,38,22,13,19,90,1,20,15,23,90,1,43,1,43,43,43,129,1,93,19,35,53,51,53,51,21,33,21,33,17,54,51,50,30,1,21,17,35,17,52,46,1,35,34,14,2,21,
17,35,191,155,155,139,1,224,254,32,170,238,142,198,62,140,41,137,111,97,151,101,32,139,4,228,120,136,136,120,254,153,223,157,211,188,253,208,2,7,189,170,109,88,148,158,194,254,113,0,255,255,0,156,0,0,
4,15,6,62,2,54,2,24,0,0,1,23,0,141,0,199,0,0,0,7,178,1,15,34,0,63,53,0,255,255,0,39,254,114,4,49,5,245,2,54,0,92,0,0,1,22,0,219,84,0,0,18,64,10,1,0,8,16,0,4,51,1,19,34,0,63,53,1,43,53,0,1,0,157,255,84,
4,47,4,64,0,11,0,71,185,0,11,255,192,64,31,12,17,57,11,11,9,4,144,0,10,6,3,6,9,92,0,0,1,5,92,8,64,20,22,57,8,118,13,4,92,1,184,255,192,181,20,22,57,1,139,12,16,244,43,237,16,246,43,237,18,57,47,237,0,
63,51,63,237,51,51,47,43,49,48,41,1,17,51,17,33,17,51,17,33,21,35,2,29,254,128,141,2,120,141,254,114,132,4,64,252,68,3,188,251,192,172,0,0,1,0,177,0,0,3,29,6,149,0,7,0,43,64,16,4,64,9,14,57,4,4,6,94,3,
2,0,8,3,101,6,184,1,21,181,9,0,101,1,102,8,16,246,237,16,246,237,0,63,63,237,51,47,43,49,48,33,35,17,33,53,51,17,33,1,67,146,1,219,145,254,38,5,191,214,254,153,0,1,0,156,0,0,2,163,4,199,0,7,0,58,64,20,
2,10,7,144,4,5,64,12,22,57,5,5,4,6,4,92,63,7,1,7,184,2,50,179,9,1,92,2,184,255,192,181,20,22,57,2,139,8,16,246,43,237,16,252,93,253,0,63,51,47,43,16,237,63,49,48,1,17,35,17,33,53,51,17,1,39,139,1,126,
137,3,197,252,59,4,64,135,254,254,0,255,255,0,96,0,0,7,78,7,103,2,54,0,58,0,0,1,23,0,67,2,84,1,41,0,17,64,10,1,15,32,1,0,15,15,4,4,51,43,53,0,63,53,0,255,255,0,9,0,0,6,157,6,62,2,54,0,90,0,0,1,23,0,67,
1,208,0,0,0,17,64,10,1,15,34,1,0,15,15,3,4,51,43,53,0,63,53,0,255,255,0,96,0,0,7,78,7,103,2,54,0,58,0,0,1,23,0,141,2,87,1,41,0,17,64,10,1,15,32,1,0,15,15,3,5,51,43,53,0,63,53,0,255,255,0,9,0,0,6,157,6,
62,2,54,0,90,0,0,1,23,0,141,1,211,0,0,0,17,64,10,1,15,34,1,0,15,15,3,4,51,43,53,0,63,53,0,255,255,0,96,0,0,7,78,7,24,0,38,0,58,0,0,1,7,0,142,2,94,1,42,0,21,64,12,2,1,31,32,2,1,0,22,28,0,7,51,43,53,53,
0,63,53,53,0,255,255,0,9,0,0,6,157,5,238,2,54,0,90,0,0,1,23,0,142,1,219,0,0,0,21,64,12,2,1,31,34,2,1,0,22,28,0,7,51,43,53,53,0,63,53,53,0,255,255,0,63,0,0,4,125,7,103,2,54,0,60,0,0,1,23,0,67,0,220,1,41,
0,17,64,10,1,11,32,1,0,11,11,8,5,51,43,53,0,63,53,0,255,255,0,39,254,114,4,49,6,62,2,54,0,92,0,0,1,23,0,67,0,162,0,0,0,17,64,10,1,10,34,1,0,10,10,0,4,51,43,53,0,63,53,0,0,1,255,244,1,252,6,12,2,125,0,
3,0,36,64,17,2,1,0,98,3,1,0,3,2,74,5,3,73,4,206,134,24,43,78,16,228,16,230,17,57,57,0,47,77,253,57,57,49,48,3,33,21,33,12,6,24,249,232,2,125,129,0,1,1,30,3,191,1,211,5,228,0,9,0,46,64,25,1,0,6,0,255,6,
156,64,4,0,6,0,9,3,7,5,5,252,128,4,73,10,149,236,24,43,78,16,252,26,77,253,23,57,0,63,26,253,228,18,17,51,49,48,1,46,1,61,1,51,17,35,22,23,1,115,53,32,181,89,8,63,3,191,105,148,124,172,254,237,107,123,
0,2,255,214,4,43,4,153,7,77,0,3,0,4,0,22,178,3,179,0,184,1,191,180,4,6,2,6,3,47,17,51,0,63,244,237,49,48,3,33,21,33,1,42,4,195,251,61,1,168,7,77,74,253,40,0,0,2,0,57,255,219,4,51,5,228,0,57,0,67,0,246,
64,46,22,8,0,41,98,3,40,40,7,36,98,4,63,37,79,37,2,37,37,53,23,31,11,13,29,58,21,19,29,97,0,60,16,60,2,60,255,66,97,23,0,15,16,15,2,15,184,2,57,64,19,13,148,19,23,23,19,13,15,51,31,51,47,51,79,51,95,51,
5,51,184,2,57,64,51,53,97,47,5,5,48,2,64,2,2,2,187,51,99,63,50,79,50,2,50,246,15,99,16,74,69,0,3,4,7,4,9,56,35,38,39,42,4,44,21,11,9,99,58,31,0,33,16,33,2,33,184,2,47,179,63,56,99,44,184,1,141,64,11,40,
36,155,63,99,26,73,68,89,114,24,43,16,246,237,244,50,244,237,16,246,93,50,50,253,50,50,18,23,57,17,18,23,57,16,246,237,244,93,253,246,93,50,0,63,253,228,93,63,51,47,16,253,228,93,16,237,244,93,237,18,
57,57,17,18,57,57,17,18,57,47,93,51,253,50,51,47,51,253,50,49,48,67,121,64,14,54,55,45,46,54,46,56,87,0,55,45,53,87,1,43,1,43,129,129,1,33,21,33,23,33,21,33,22,21,20,7,22,51,50,55,51,20,6,35,34,39,6,35,
34,38,53,52,54,51,50,23,54,53,52,39,33,53,33,39,33,53,51,38,53,52,54,51,50,22,23,35,38,35,34,6,21,20,3,38,35,34,6,21,20,22,51,50,1,209,1,102,254,194,31,1,31,254,253,10,22,191,82,98,11,141,121,109,152,
190,83,157,81,125,134,88,71,73,7,14,254,195,1,30,30,255,0,220,37,214,146,152,185,10,136,12,194,109,116,37,65,49,34,43,39,29,77,3,197,129,112,129,68,69,125,70,151,232,166,215,160,160,91,97,98,134,39,64,
44,75,68,129,112,129,128,78,146,191,205,178,249,119,84,79,252,139,41,45,32,32,43,0,0,4,0,180,0,0,8,146,5,191,0,9,0,21,0,33,0,37,0,198,64,17,0,3,1,56,8,3,7,8,8,86,2,3,20,2,2,3,25,184,2,24,178,19,19,31,
184,2,24,178,13,13,34,184,2,24,64,24,37,8,1,2,8,3,4,2,6,7,3,3,0,8,3,101,7,6,6,16,0,34,34,28,184,2,24,182,16,16,10,0,35,35,22,184,2,24,64,13,16,10,1,10,190,39,8,101,2,1,0,102,38,16,246,50,50,237,16,246,
93,237,51,47,17,18,57,47,237,51,47,17,18,57,47,51,237,0,63,23,51,63,23,51,63,253,50,47,237,51,47,237,135,46,43,135,125,196,24,67,121,64,42,11,33,32,12,22,117,1,24,20,22,117,1,30,14,28,117,0,26,18,28,117,
0,33,11,31,117,0,23,21,25,117,1,29,15,31,117,0,27,17,25,117,1,0,43,43,43,43,1,43,43,43,43,129,0,93,49,48,51,17,51,1,17,51,17,35,1,17,1,20,6,35,34,38,53,52,54,51,50,22,7,52,38,35,34,6,21,20,22,51,50,54,
1,33,21,33,180,32,3,210,145,33,252,54,7,70,203,142,144,202,203,143,142,203,126,128,91,91,129,129,91,90,129,253,203,2,179,253,77,5,191,251,154,4,102,250,65,4,88,251,168,2,121,142,204,203,143,143,203,203,
143,91,129,129,91,91,128,129,254,71,102,0,0,2,0,90,255,222,4,124,4,72,0,18,0,25,0,82,64,41,1,5,3,6,9,25,0,0,15,9,22,22,15,15,1,15,3,9,5,6,16,143,6,1,6,6,18,19,19,18,32,18,1,18,27,25,0,0,12,12,26,17,51,
47,51,47,51,17,51,93,47,51,47,17,51,47,93,56,51,0,47,205,124,47,93,24,205,47,17,18,57,47,205,17,51,17,51,51,49,48,1,17,22,51,50,55,23,14,1,35,34,0,53,52,0,51,50,0,19,39,17,38,35,34,7,17,1,65,120,178,254,
141,72,118,227,122,232,254,215,1,43,230,214,1,48,11,231,124,176,175,121,2,19,254,141,121,246,43,170,106,1,61,248,252,1,57,254,228,254,231,74,1,41,121,122,254,216,0,0,5,0,152,255,219,6,119,5,228,0,3,0,
9,0,29,0,41,0,53,0,180,64,38,187,43,187,47,203,43,203,47,4,20,10,39,214,240,45,1,16,45,33,45,49,45,3,45,45,15,33,106,25,31,51,106,15,29,20,36,130,22,184,255,192,64,34,24,29,57,22,22,48,130,18,18,12,10,
30,130,28,64,26,29,57,28,28,42,130,12,12,55,6,24,8,214,5,26,6,181,9,184,1,46,64,25,7,1,2,3,3,93,0,1,20,0,0,1,0,3,11,2,1,1,1,2,16,2,2,55,0,184,255,240,177,3,0,47,51,56,17,51,47,56,51,0,63,51,63,51,135,
5,46,43,135,125,196,1,24,47,228,237,0,63,237,63,1,17,51,47,237,51,47,43,253,50,17,51,47,237,51,47,43,253,50,0,63,237,63,237,18,57,47,113,93,253,57,57,49,48,0,93,5,1,51,1,3,51,17,35,17,35,1,22,21,20,6,
35,34,38,53,52,55,38,53,52,54,51,50,22,21,20,39,52,38,35,34,6,21,20,22,51,50,54,19,52,38,35,34,6,21,20,22,51,50,54,1,28,3,155,112,252,99,169,187,110,150,5,77,146,156,139,144,149,151,109,150,107,109,140,
111,77,65,58,84,89,55,57,83,40,103,75,74,113,108,75,78,104,37,6,9,249,247,5,246,253,12,2,146,252,47,68,126,95,143,146,86,130,70,56,104,81,120,123,82,100,104,45,57,58,46,48,67,68,254,206,61,83,82,69,67,
65,78,0,0,5,0,33,255,219,6,119,5,228,0,32,0,36,0,56,0,68,0,80,0,236,64,41,180,20,1,187,70,187,74,203,70,203,74,4,37,47,66,214,240,72,1,16,72,33,72,49,72,3,72,72,42,60,106,52,31,78,106,42,29,47,63,130,
49,184,255,192,64,94,24,29,57,49,49,75,130,45,45,39,37,57,130,55,64,26,29,57,55,55,69,130,39,39,82,8,24,214,15,25,1,15,25,31,25,2,25,25,31,15,15,18,106,13,24,0,0,31,106,3,27,24,24,16,8,28,130,6,155,21,
130,10,0,130,1,135,16,130,10,15,34,35,36,36,93,33,34,20,33,33,34,36,33,11,35,34,1,34,35,16,35,35,82,0,184,255,240,177,36,33,47,51,56,17,51,47,56,51,0,63,51,63,51,135,5,46,43,135,125,196,1,24,47,51,237,
244,237,47,237,244,253,50,17,57,47,0,63,237,51,47,63,237,51,47,17,57,47,93,113,253,57,1,17,51,47,237,51,47,43,253,50,17,51,47,237,51,47,43,253,50,0,63,237,63,237,18,57,47,113,93,253,57,57,49,48,0,93,93,
19,35,54,51,50,22,21,20,7,22,21,20,6,35,34,39,51,22,51,50,54,53,52,38,39,53,50,54,53,52,38,35,34,19,1,51,9,1,22,21,20,6,35,34,38,53,52,55,38,53,52,54,51,50,22,21,20,39,52,38,35,34,6,21,20,22,51,50,54,
19,52,38,35,34,6,21,20,22,51,50,54,173,112,54,217,109,153,91,138,170,137,255,46,109,34,159,90,106,105,149,88,114,84,62,113,113,3,156,111,252,100,4,41,146,156,139,138,155,150,108,150,106,109,140,111,76,
66,58,83,89,55,57,82,41,103,75,74,114,109,74,79,104,5,13,215,118,86,86,59,66,126,102,150,241,142,88,57,54,88,3,94,58,50,41,62,250,90,6,9,249,247,1,195,68,126,95,143,141,91,130,70,56,104,81,120,123,82,
100,104,45,57,58,46,48,67,68,254,206,61,83,82,69,67,65,78,0,0,5,0,42,255,219,6,118,5,228,0,3,0,30,0,50,0,62,0,74,1,34,185,0,13,255,192,64,58,9,12,57,0,11,15,30,2,16,11,31,30,2,123,16,180,23,196,23,3,187,
64,187,68,203,64,203,68,4,31,41,60,214,240,66,1,16,66,33,66,49,66,3,66,66,36,54,106,46,31,72,106,36,29,41,57,130,43,184,255,192,64,26,24,29,57,43,43,69,130,39,39,33,31,51,130,49,64,26,29,57,49,49,63,130,
33,33,76,7,184,255,240,64,51,6,7,7,93,29,30,20,29,29,30,19,19,21,29,29,7,27,106,15,9,31,9,2,9,9,6,21,106,15,25,6,214,30,26,5,24,130,15,12,1,12,6,30,30,7,29,12,29,19,130,18,184,255,240,64,25,18,1,2,3,3,
93,0,1,20,0,0,1,0,3,11,2,1,1,1,2,16,2,2,55,0,184,255,240,177,3,0,47,51,56,17,51,47,56,51,0,63,51,63,51,135,5,46,43,135,125,196,1,24,47,56,237,51,51,47,51,51,47,51,47,93,237,51,0,63,237,63,237,17,57,47,
93,237,51,50,47,17,57,47,135,5,46,43,125,16,196,1,56,17,51,24,47,237,51,47,43,253,50,17,51,47,237,51,47,43,253,50,0,63,237,63,237,18,57,47,113,93,237,57,57,49,48,0,93,93,1,93,93,43,5,1,51,1,19,21,33,7,
54,51,50,22,21,20,6,35,34,38,39,51,22,51,50,54,53,52,38,35,34,7,19,1,22,21,20,6,35,34,38,53,52,55,38,53,52,54,51,50,22,21,20,39,52,38,35,34,6,21,20,22,51,50,54,19,52,38,35,34,6,21,20,22,51,50,54,1,77,
3,156,111,252,100,169,254,199,38,43,45,129,156,170,144,122,148,9,113,28,142,81,116,104,88,80,121,85,5,15,145,155,139,145,148,150,108,150,106,105,144,111,76,66,58,83,89,55,57,82,41,103,75,74,114,109,74,
79,104,37,6,9,249,247,5,246,97,172,10,145,103,109,158,127,84,113,99,73,66,81,30,1,131,251,205,68,126,95,143,146,86,130,70,56,104,81,120,121,84,100,104,45,57,58,46,48,67,68,254,206,61,83,82,69,67,65,78,
0,5,0,81,255,219,6,119,5,228,0,3,0,9,0,29,0,41,0,53,0,214,64,38,187,43,187,47,203,43,203,47,4,20,10,39,214,240,45,1,16,45,33,45,49,45,3,45,45,15,33,106,25,31,51,106,15,29,20,36,130,22,184,255,192,64,45,
24,29,57,22,22,48,130,18,18,12,10,30,130,28,64,26,29,57,28,28,42,130,12,12,55,8,5,6,6,93,7,8,20,7,7,8,7,6,25,8,214,5,26,6,7,184,255,240,64,32,7,8,5,16,5,7,5,4,1,2,3,3,93,0,1,20,0,0,1,0,3,11,2,1,1,1,2,
16,2,2,55,0,184,255,240,177,3,0,47,51,56,17,51,47,56,51,0,63,51,63,51,135,5,46,43,135,125,196,1,24,47,51,51,47,56,51,47,56,51,0,63,237,63,51,135,14,46,43,135,5,125,196,1,17,51,24,47,237,51,47,43,253,50,
17,51,47,237,51,47,43,253,50,0,63,237,63,237,18,57,47,113,93,253,57,57,49,48,0,93,5,1,51,9,1,33,1,39,1,33,1,22,21,20,6,35,34,38,53,52,55,38,53,52,54,51,50,22,21,20,39,52,38,35,34,6,21,20,22,51,50,54,19,
52,38,35,34,6,21,20,22,51,50,54,1,3,3,155,111,252,100,254,224,2,67,254,37,91,1,132,254,111,5,148,146,156,139,144,149,151,109,150,107,105,144,111,77,65,58,84,89,55,57,83,40,104,74,74,114,109,75,78,104,
37,6,9,249,247,5,246,252,250,40,2,125,252,46,68,126,95,143,146,86,130,70,56,104,81,120,121,84,100,104,45,57,58,46,48,67,68,254,206,61,83,82,69,67,65,78,0,0,2,0,153,0,0,4,52,4,129,0,4,0,9,0,0,51,17,9,1,
17,37,33,17,9,1,153,1,205,1,206,252,182,2,249,254,131,254,132,2,122,2,7,253,249,253,134,81,2,7,1,171,254,85,0,1,0,115,1,191,4,103,4,0,0,5,0,35,185,0,4,1,4,64,14,3,127,0,3,127,0,73,6,1,74,7,95,113,24,43,
78,16,230,16,244,77,253,0,47,253,228,49,48,19,33,21,33,17,35,115,3,244,252,149,137,4,0,137,254,72,0,1,2,30,253,253,3,204,6,201,0,19,0,0,1,35,17,52,54,51,50,22,21,20,6,35,34,38,39,38,35,34,6,21,2,175,145,
172,120,74,64,53,35,34,43,21,24,23,29,23,253,253,7,19,207,234,69,40,41,51,27,34,37,49,129,0,0,1,1,1,253,253,2,175,6,201,0,19,0,0,1,51,17,20,6,35,34,38,53,52,54,51,50,22,23,22,51,50,54,53,2,30,145,172,
120,59,79,53,34,35,43,21,24,23,29,23,6,201,248,237,207,234,56,53,41,51,28,33,37,48,130,0,0,1,255,238,2,22,5,198,2,197,0,3,0,0,1,33,53,33,5,198,250,40,5,216,2,22,175,0,0,1,2,131,253,147,3,50,7,72,0,3,0,
0,1,17,51,17,2,131,175,253,147,9,181,246,75,0,0,1,2,131,253,147,5,199,2,197,0,5,0,0,1,21,33,17,35,17,5,199,253,107,175,2,197,175,251,125,5,50,0,1,255,238,253,147,3,49,2,197,0,5,0,0,1,33,53,33,17,35,2,
130,253,108,3,67,175,2,22,175,250,206,0,1,2,131,2,22,5,199,7,72,0,5,0,0,1,17,51,17,33,21,2,131,175,2,149,2,22,5,50,251,125,175,0,1,255,238,2,22,3,49,7,72,0,5,0,0,1,33,53,33,17,51,3,49,252,189,2,148,175,
2,22,175,4,131,0,1,2,131,253,147,5,199,7,72,0,7,0,0,1,17,51,17,33,21,33,17,2,131,175,2,149,253,107,253,147,9,181,251,125,175,251,125,0,1,255,238,253,147,3,49,7,72,0,7,0,0,1,17,33,53,33,17,51,17,2,130,
253,108,2,148,175,253,147,4,131,175,4,131,246,75,0,1,255,238,253,147,5,198,2,197,0,7,0,0,1,33,53,33,21,33,17,35,2,130,253,108,5,216,253,107,175,2,22,175,175,251,125,0,0,1,255,238,2,22,5,198,7,72,0,7,0,
0,1,33,53,33,17,51,17,33,5,198,250,40,2,148,175,2,149,2,22,175,4,131,251,125,0,1,255,238,253,147,5,198,7,72,0,11,0,0,1,33,53,33,17,51,17,33,21,33,17,35,2,130,253,108,2,148,175,2,149,253,107,175,2,22,175,
4,131,251,125,175,251,125,0,2,255,238,1,88,5,198,3,131,0,3,0,7,0,0,1,33,53,33,17,33,53,33,5,198,250,40,5,216,250,40,5,216,2,212,175,253,213,175,0,2,1,197,253,147,3,240,7,72,0,3,0,7,0,0,1,17,51,17,33,17,
51,17,3,65,175,253,213,175,253,147,9,181,246,75,9,181,246,75,0,1,2,131,253,147,5,199,3,131,0,9,0,0,1,17,33,21,33,21,33,21,33,17,2,131,3,68,253,107,2,149,253,107,253,147,5,240,175,205,175,252,59,0,0,1,
1,197,253,147,5,199,2,197,0,9,0,0,1,17,33,21,33,17,35,17,35,17,1,197,4,2,254,41,175,205,253,147,5,50,175,251,125,4,116,251,140,0,0,2,1,197,253,147,5,198,3,131,0,5,0,11,0,0,1,35,17,33,21,33,1,17,35,17,
33,21,2,116,175,4,1,252,174,1,124,175,2,133,253,147,5,240,175,254,132,252,59,4,116,175,0,1,255,238,253,147,3,49,3,131,0,9,0,0,1,33,53,33,53,33,53,33,17,35,2,130,253,108,2,148,253,108,3,67,175,1,88,175,
205,175,250,16,0,1,255,238,253,147,3,239,2,197,0,9,0,0,1,17,33,53,33,17,35,17,35,17,1,196,254,42,4,1,175,205,253,147,4,131,175,250,206,4,131,251,125,0,0,2,255,238,253,147,3,239,3,131,0,5,0,11,0,0,1,17,
33,53,33,17,1,33,53,33,17,35,3,64,252,174,4,1,253,213,254,42,2,133,175,253,147,5,65,175,250,16,3,197,175,251,140,0,0,1,2,131,1,88,5,199,7,72,0,9,0,0,1,17,51,17,33,21,33,21,33,21,2,131,175,2,149,253,107,
2,149,1,88,5,240,252,59,175,205,175,0,1,1,197,2,22,5,198,7,72,0,9,0,0,1,33,17,51,17,51,17,51,17,33,5,198,251,255,175,205,175,1,214,2,22,5,50,251,125,4,131,251,125,0,0,2,1,197,1,88,5,198,7,72,0,5,0,11,
0,0,1,17,33,21,33,17,1,33,21,33,17,51,2,116,3,82,251,255,2,43,1,214,253,123,175,7,72,250,191,175,5,240,252,59,175,4,116,0,0,1,255,238,1,88,3,49,7,72,0,9,0,0,1,33,53,33,53,33,53,33,17,51,3,49,252,189,2,
148,253,108,2,148,175,1,88,175,205,175,3,197,0,1,255,238,2,22,3,239,7,72,0,9,0,0,1,33,53,33,17,51,17,51,17,51,3,239,251,255,1,214,175,205,175,2,22,175,4,131,251,125,4,131,0,2,255,238,1,88,3,239,7,72,0,
5,0,11,0,0,1,51,17,33,53,33,1,17,51,17,33,53,3,64,175,251,255,3,82,254,132,175,253,123,7,72,250,16,175,1,124,3,197,251,140,175,0,1,2,131,253,147,5,199,7,72,0,11,0,0,1,17,51,17,33,21,33,21,33,21,33,17,
2,131,175,2,149,253,107,2,149,253,107,253,147,9,181,252,59,175,205,175,252,59,0,2,1,197,253,147,5,199,7,72,0,7,0,11,0,0,1,17,51,17,33,21,33,17,33,17,51,17,3,65,175,1,215,254,41,253,213,175,253,147,9,181,
251,125,175,251,125,9,181,246,75,0,0,3,1,197,253,147,5,199,7,72,0,3,0,9,0,15,0,0,1,17,51,17,19,17,51,17,33,21,1,17,33,21,33,17,1,197,175,205,175,1,215,253,122,2,134,254,41,253,147,9,181,246,75,5,65,4,
116,252,59,175,250,191,4,116,175,252,59,0,0,1,255,238,253,147,3,49,7,72,0,11,0,0,1,33,53,33,53,33,53,33,17,51,17,35,2,130,253,108,2,148,253,108,2,148,175,175,1,88,175,205,175,3,197,246,75,0,0,2,255,238,
253,147,3,239,7,72,0,7,0,11,0,0,1,17,33,53,33,17,51,17,51,17,51,17,1,196,254,42,1,214,175,205,175,253,147,4,131,175,4,131,246,75,9,181,246,75,0,3,255,238,253,147,3,239,7,72,0,3,0,9,0,15,0,0,1,17,51,17,
1,17,33,53,33,25,1,33,53,33,17,35,3,64,175,254,132,253,123,1,214,254,42,2,133,175,253,147,9,181,246,75,9,181,251,140,175,3,197,250,16,175,251,140,0,2,255,238,253,147,5,198,3,131,0,3,0,11,0,0,1,33,53,33,
1,33,53,33,21,33,17,35,5,198,250,40,5,216,252,188,253,108,5,216,253,107,175,2,212,175,253,213,175,175,252,59,0,1,255,238,253,147,5,198,2,197,0,11,0,0,1,17,33,53,33,21,33,17,35,17,35,17,1,196,254,42,5,
216,254,41,175,205,253,147,4,131,175,175,251,125,4,116,251,140,0,3,255,238,253,147,5,198,3,131,0,3,0,9,0,15,0,0,1,33,53,33,1,33,53,33,17,35,33,17,33,21,33,17,5,198,250,40,5,216,251,254,254,42,2,133,175,
1,124,2,134,254,41,2,212,175,253,213,175,251,140,4,116,175,252,59,0,2,255,238,1,88,5,198,7,72,0,7,0,11,0,0,1,33,53,33,17,51,17,33,17,33,53,33,5,198,250,40,2,148,175,2,149,250,40,5,216,2,212,175,3,197,
252,59,253,213,175,0,0,1,255,238,2,22,5,198,7,72,0,11,0,0,1,33,53,33,17,51,17,51,17,51,17,33,5,198,250,40,1,214,175,205,175,1,215,2,22,175,4,131,251,125,4,131,251,125,0,3,255,238,1,88,5,198,7,72,0,5,0,
11,0,15,0,0,1,33,53,33,17,51,1,33,17,51,17,33,17,33,53,33,2,115,253,123,1,214,175,3,83,253,122,175,1,215,250,40,5,216,2,212,175,3,197,251,140,4,116,252,59,253,213,175,0,1,255,238,253,147,5,198,7,72,0,
19,0,0,1,33,53,33,53,33,53,33,17,51,17,33,21,33,21,33,21,33,17,35,2,130,253,108,2,148,253,108,2,148,175,2,149,253,107,2,149,253,107,175,1,88,175,205,175,3,197,252,59,175,205,175,252,59,0,1,255,238,253,
147,5,198,7,72,0,19,0,0,1,17,33,53,33,17,51,17,51,17,51,17,33,21,33,17,35,17,35,17,1,196,254,42,1,214,175,205,175,1,215,254,41,175,205,253,147,4,131,175,4,131,251,125,4,131,251,125,175,251,125,4,131,251,
125,0,0,4,255,238,253,147,5,198,7,72,0,5,0,11,0,17,0,23,0,0,1,33,21,33,17,51,1,17,51,17,33,53,1,33,53,33,17,35,1,17,35,17,33,21,3,240,1,214,253,123,175,253,212,175,253,123,1,214,254,42,2,133,175,2,44,
175,2,133,3,131,175,4,116,252,59,3,197,251,140,175,253,213,175,251,140,3,197,252,59,4,116,175,0,1,255,238,2,109,5,198,7,72,0,3,0,0,1,33,17,33,5,198,250,40,5,216,2,109,4,219,0,1,255,238,253,147,5,198,2,
109,0,3,0,0,1,33,17,33,5,198,250,40,5,216,253,147,4,218,0,1,255,238,253,147,5,198,7,72,0,3,0,0,3,17,33,17,18,5,216,253,147,9,181,246,75,0,0,1,255,238,253,147,2,218,7,72,0,3,0,0,3,17,33,17,18,2,236,253,
147,9,181,246,75,0,0,1,2,218,253,147,5,198,7,72,0,3,0,0,1,17,33,17,2,218,2,236,253,147,9,181,246,75,0,30,0,107,254,8,5,198,7,72,0,3,0,7,0,11,0,15,0,19,0,23,0,27,0,31,0,35,0,39,0,43,0,47,0,51,0,55,0,59,
0,63,0,67,0,71,0,75,0,79,0,83,0,87,0,91,0,95,0,99,0,103,0,107,0,111,0,115,0,119,0,0,19,51,21,35,37,51,21,35,37,51,21,35,5,51,21,35,37,51,21,35,37,51,21,35,7,51,21,35,37,51,21,35,37,51,21,35,5,51,21,35,
37,51,21,35,37,51,21,35,7,51,21,35,37,51,21,35,37,51,21,35,23,51,21,35,37,51,21,35,37,51,21,35,7,51,21,35,37,51,21,35,37,51,21,35,5,51,21,35,37,51,21,35,37,51,21,35,7,51,21,35,37,51,21,35,37,51,21,35,
23,51,21,35,37,51,21,35,37,51,21,35,107,125,125,1,242,125,125,1,243,125,125,253,20,125,125,1,243,124,124,1,242,125,125,249,125,125,254,13,125,125,254,14,125,125,4,222,125,125,254,14,124,124,254,13,125,
125,249,125,125,1,242,125,125,1,243,125,125,249,125,125,254,14,124,124,254,13,125,125,249,125,125,1,242,125,125,1,243,125,125,253,20,125,125,1,243,124,124,1,242,125,125,249,125,125,254,13,125,125,254,
14,125,125,249,125,125,1,243,124,124,1,242,125,125,7,72,125,125,125,125,125,124,125,125,125,125,125,124,125,125,125,125,125,125,124,124,124,124,124,125,125,125,125,125,125,124,125,125,125,125,125,124,
125,125,125,125,125,125,124,124,124,124,124,125,125,125,125,125,125,124,125,125,125,125,125,0,60,255,238,254,8,5,197,7,72,0,3,0,7,0,11,0,15,0,19,0,23,0,27,0,31,0,35,0,39,0,43,0,47,0,51,0,55,0,59,0,63,
0,67,0,71,0,75,0,79,0,83,0,87,0,91,0,95,0,99,0,103,0,107,0,111,0,115,0,119,0,123,0,127,0,131,0,135,0,139,0,143,0,147,0,151,0,155,0,159,0,163,0,167,0,171,0,175,0,179,0,183,0,187,0,191,0,195,0,199,0,203,
0,207,0,211,0,215,0,219,0,223,0,227,0,231,0,235,0,239,0,0,19,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,5,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,
5,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,5,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,5,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,
55,51,21,35,5,51,21,35,37,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,37,51,21,35,5,51,21,35,39,51,21,35,39,51,21,35,39,51,21,35,39,51,21,35,39,51,21,35,7,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,
55,51,21,35,55,51,21,35,23,51,21,35,39,51,21,35,39,51,21,35,39,51,21,35,39,51,21,35,39,51,21,35,7,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,55,51,21,35,107,124,124,249,124,124,249,125,125,
249,125,125,250,124,124,249,124,124,250,165,125,125,249,125,125,249,125,125,250,124,124,249,125,125,249,125,125,251,159,124,124,249,124,124,249,125,125,249,125,125,250,124,124,249,124,124,250,165,125,
125,249,125,125,249,125,125,250,124,124,249,125,125,249,125,125,251,159,124,124,249,124,124,249,125,125,249,125,125,250,124,124,249,124,124,250,165,125,125,1,242,125,125,250,124,124,249,125,125,249,125,
125,252,27,125,125,4,98,124,124,249,124,124,250,125,125,249,125,125,249,124,124,249,124,124,125,125,125,249,125,125,249,125,125,250,124,124,249,125,125,249,125,125,125,124,124,249,124,124,250,125,125,
249,125,125,249,124,124,249,124,124,125,125,125,249,125,125,249,125,125,250,124,124,249,125,125,249,125,125,7,72,125,125,125,125,125,125,125,125,125,125,125,124,125,125,125,125,125,125,125,125,125,125,
125,124,125,125,125,125,125,125,125,125,125,125,125,125,124,124,124,124,124,124,124,124,124,124,124,125,125,125,125,125,125,125,125,125,125,125,125,124,125,125,125,125,125,125,125,125,125,125,125,124,
125,125,125,125,125,125,125,125,125,125,125,125,124,124,124,124,124,124,124,124,124,124,124,125,125,125,125,125,125,125,125,125,125,125,125,124,125,125,125,125,125,125,125,125,125,125,125,0,0,46,0,0,253,
140,5,215,7,72,0,61,0,65,0,69,0,73,0,77,0,81,0,85,0,89,0,93,0,97,0,101,0,105,0,109,0,113,0,117,0,121,0,125,0,129,0,133,0,137,0,141,0,145,0,149,0,153,0,157,0,161,0,165,0,169,0,173,0,177,0,181,0,185,0,189,
0,193,0,197,0,201,0,205,0,209,0,213,0,217,0,221,0,225,0,229,0,233,0,237,0,241,0,0,1,17,35,21,51,17,35,21,51,17,35,21,51,17,35,21,51,21,33,17,51,53,35,17,51,53,35,17,51,53,35,17,51,53,35,17,51,53,51,21,
51,53,51,21,51,53,51,21,51,53,51,21,51,53,51,21,51,53,51,21,35,21,37,21,51,53,51,21,51,53,51,21,51,53,51,21,51,53,51,21,51,53,23,35,21,51,39,35,21,51,39,35,21,51,39,35,21,51,39,35,21,51,7,21,51,53,51,
21,51,53,51,21,51,53,51,21,51,53,51,21,51,53,5,35,21,51,55,21,51,53,51,21,51,53,51,21,51,53,51,21,51,53,5,21,51,53,33,21,51,53,7,53,35,21,37,21,51,53,51,21,51,53,19,53,35,21,35,53,35,21,35,53,35,21,35,
53,35,21,35,53,35,21,7,21,51,53,51,21,51,53,51,21,51,53,51,21,51,53,51,21,51,53,19,53,35,21,35,53,35,21,35,53,35,21,35,53,35,21,35,53,35,21,7,21,51,53,51,21,51,53,51,21,51,53,51,21,51,53,51,21,51,53,5,
215,124,124,124,124,124,124,124,124,250,41,125,125,125,125,125,125,125,125,125,124,125,124,125,125,124,125,125,124,125,124,124,251,34,124,125,124,125,125,124,125,125,124,125,125,125,249,125,125,250,124,
124,249,125,125,249,125,125,249,124,125,124,125,125,124,125,125,124,252,152,125,125,124,125,125,124,125,125,124,125,251,34,124,1,118,125,250,124,1,242,125,125,124,125,125,124,125,125,124,125,125,124,125,
124,124,125,124,125,125,124,125,125,124,125,125,124,125,125,124,125,125,124,125,124,124,125,124,125,125,124,125,125,124,5,210,254,138,124,254,138,125,254,138,124,254,138,125,124,1,117,125,1,118,125,1,
117,125,1,118,125,1,117,125,125,125,125,125,125,125,125,125,125,125,249,125,125,125,125,125,125,125,125,125,125,125,125,249,125,125,125,125,125,125,125,125,125,125,124,124,124,124,124,124,124,124,124,
124,249,125,125,125,125,125,125,125,125,125,125,249,125,125,125,125,125,125,125,125,125,125,125,125,254,138,125,125,125,125,125,125,125,125,125,125,125,124,124,124,124,124,124,124,124,124,124,254,138,
125,125,125,125,125,125,125,125,125,125,124,125,125,125,125,125,125,125,125,125,125,0,1,0,146,0,0,4,66,3,176,0,3,0,0,19,33,17,33,146,3,176,252,80,3,176,252,80,0,0,1,0,0,1,61,7,255,2,191,0,3,0,0,17,33,
17,33,7,255,248,1,2,191,254,126,0,1,1,48,0,0,6,188,5,139,0,2,0,0,33,9,1,1,48,2,198,2,198,5,139,250,117,0,0,1,1,32,255,225,6,203,5,137,0,2,0,0,9,2,1,32,5,171,250,85,5,137,253,44,253,44,0,1,1,48,255,225,
6,188,5,108,0,2,0,0,9,2,6,188,253,58,253,58,5,108,250,117,5,139,0,1,1,32,255,225,6,203,5,137,0,2,0,0,1,17,1,6,203,250,85,5,137,250,88,2,212,0,0,2,0,174,0,137,4,31,3,250,0,11,0,23,0,0,1,20,0,35,34,0,53,
52,0,51,50,0,7,52,38,35,34,6,21,20,22,51,50,54,4,31,254,253,181,183,254,254,1,3,181,183,1,2,76,214,150,151,214,214,151,150,214,2,66,182,254,253,1,2,183,182,1,2,254,254,182,150,214,215,149,149,216,215,
0,2,0,124,0,0,4,80,3,212,0,3,0,15,0,0,51,17,33,17,1,52,38,35,34,6,21,20,22,51,50,54,124,3,212,254,224,118,84,82,120,119,83,84,118,3,212,252,44,1,234,83,119,118,84,83,119,120,0,3,0,38,0,0,4,169,4,131,0,
3,0,15,0,27,0,0,51,17,33,17,3,52,0,35,34,0,21,20,0,51,50,0,39,20,6,35,34,38,53,52,54,51,50,22,38,4,131,137,254,253,181,183,254,254,1,2,183,181,1,3,76,214,150,151,214,215,150,150,214,4,131,251,125,2,65,
181,1,4,254,252,181,181,254,253,1,3,181,150,214,214,150,151,214,213,0,5,1,152,255,137,6,147,4,132,0,11,0,23,0,35,0,47,0,57,0,0,1,16,0,33,32,0,17,16,0,33,32,0,3,52,0,35,34,0,21,20,0,51,50,0,1,20,6,35,34,
38,53,52,54,51,50,22,5,20,6,35,34,38,53,52,54,51,50,22,1,55,22,51,50,55,23,6,35,34,6,147,254,138,254,249,254,248,254,138,1,119,1,7,1,8,1,117,92,254,191,224,225,254,192,1,64,225,224,1,65,253,59,47,34,33,
48,48,33,34,47,1,233,48,33,33,48,48,33,33,48,253,149,62,79,153,153,78,63,104,190,191,2,6,254,250,254,137,1,117,1,8,1,7,1,119,254,139,254,247,225,1,64,254,192,225,224,254,192,1,64,1,100,33,48,48,33,34,
47,47,34,33,48,48,33,34,47,47,254,141,36,144,144,36,195,0,0,4,1,184,255,137,6,179,4,132,0,11,0,23,0,35,0,45,0,0,1,16,0,33,32,0,17,16,0,33,32,0,5,52,38,35,34,6,21,20,22,51,50,54,37,52,38,35,34,6,21,20,
22,51,50,54,1,22,51,50,55,39,6,35,34,39,6,179,254,138,254,249,254,248,254,138,1,119,1,7,1,8,1,117,252,223,47,34,33,48,48,33,34,47,1,233,48,33,33,48,48,33,33,48,253,149,103,191,190,104,63,78,153,153,79,
2,6,254,250,254,137,1,117,1,8,1,7,1,119,254,139,133,34,47,47,34,33,48,48,33,34,47,47,34,33,48,48,254,208,195,195,36,144,144,0,2,0,16,255,33,7,70,6,85,0,39,0,51,0,0,1,51,17,22,23,1,23,1,22,23,33,21,33,
6,7,1,7,1,6,7,17,35,17,38,39,1,39,1,38,39,33,53,33,54,55,1,55,1,54,55,1,52,0,35,34,0,21,20,0,51,50,0,3,134,76,191,159,1,33,52,254,226,140,3,1,80,254,176,14,129,1,30,57,254,228,167,183,76,203,142,254,216,
49,1,28,125,19,254,176,1,80,14,130,254,228,49,1,35,180,170,2,36,254,211,212,211,254,211,1,45,211,211,1,46,6,85,254,175,7,133,1,27,53,254,226,175,183,69,190,158,254,223,51,1,24,125,14,254,175,1,81,25,114,
254,232,51,1,33,153,199,69,197,152,1,31,57,254,229,130,10,253,183,212,1,44,254,211,211,211,254,210,1,46,0,0,2,0,89,254,175,4,17,5,152,0,23,0,35,0,0,1,17,33,21,33,17,35,17,33,53,33,17,34,46,1,53,52,0,51,
50,0,21,20,2,19,52,38,35,34,6,21,20,22,51,50,54,2,79,1,161,254,95,54,254,94,1,162,81,217,150,1,23,197,196,1,24,255,206,250,177,176,251,251,176,176,251,1,225,254,147,54,254,113,1,143,54,1,109,103,232,140,
196,1,24,254,232,196,185,254,235,1,205,176,250,251,175,176,251,251,0,0,2,0,102,254,173,5,17,5,92,0,27,0,39,0,0,1,23,18,19,7,38,39,1,30,1,21,20,4,35,34,0,53,52,0,51,50,23,1,6,7,53,62,1,1,34,6,21,20,22,
51,50,54,53,52,38,4,83,29,35,126,25,149,73,254,217,110,182,254,246,193,205,254,231,1,5,176,76,94,1,37,214,243,165,181,254,152,158,228,233,158,162,223,237,5,92,10,254,153,255,0,16,188,227,253,133,42,240,
148,188,232,1,13,188,188,1,0,33,2,124,90,14,27,51,93,253,52,227,155,172,221,227,154,169,225,0,0,1,0,60,0,0,4,8,4,207,0,29,0,0,1,30,1,23,30,1,21,20,6,35,34,39,20,22,31,1,33,55,50,54,61,1,6,35,34,38,53,
52,55,36,2,35,18,93,157,122,95,129,91,154,100,202,176,7,252,231,8,182,201,90,172,92,127,188,1,6,4,207,82,174,143,111,140,82,96,128,190,230,191,7,37,37,210,177,41,190,132,89,150,155,215,0,0,1,0,60,0,0,
5,13,4,207,0,43,0,0,41,1,55,62,2,53,39,14,1,35,34,38,53,52,54,51,50,23,38,53,52,54,51,50,22,21,20,7,54,51,50,22,21,20,6,35,34,38,39,30,2,23,4,79,252,176,8,153,133,117,1,55,177,95,115,163,145,97,64,99,
67,158,118,118,161,69,106,56,105,142,162,112,78,178,76,4,88,157,159,34,33,71,206,125,42,117,121,162,118,111,164,51,106,76,113,159,159,108,94,93,53,164,109,120,163,99,138,157,187,102,31,0,0,1,0,60,255,
232,4,126,4,207,0,21,0,0,5,46,1,3,46,1,53,52,54,51,50,23,62,1,51,50,22,21,20,6,7,0,2,95,32,121,215,101,78,148,109,206,84,34,159,92,109,149,80,134,254,228,24,122,213,1,27,133,158,84,110,151,251,129,123,
150,102,84,190,169,254,152,0,1,0,60,255,232,3,210,4,207,0,8,0,0,1,18,1,6,0,7,38,1,0,2,5,193,1,12,52,254,188,85,101,254,156,1,68,4,207,254,189,254,208,52,254,86,150,190,1,182,1,127,0,1,0,26,254,43,6,18,
5,255,0,25,0,0,1,51,22,0,21,20,6,35,34,39,38,36,39,19,20,6,4,35,34,38,53,52,36,51,50,23,3,158,60,164,1,148,40,19,28,35,55,254,232,102,26,143,254,221,146,197,218,1,69,210,192,204,5,255,100,254,94,76,16,
57,44,66,248,64,250,162,122,142,121,198,129,159,240,94,0,1,1,48,254,63,6,230,5,206,0,29,0,0,9,1,17,20,14,1,35,34,38,53,52,54,51,50,23,17,5,17,20,14,1,35,34,38,53,52,54,51,50,23,3,64,3,166,75,175,113,145,
135,180,144,84,116,253,69,59,183,125,121,156,186,137,95,110,4,171,1,35,250,235,148,146,96,154,109,117,170,50,3,82,217,252,43,123,160,113,138,123,129,163,54,0,0,1,0,110,254,132,1,229,255,144,0,18,0,59,
64,13,6,64,9,19,57,7,170,31,12,47,12,2,12,184,1,126,64,19,16,170,2,64,10,19,57,2,0,0,9,14,121,4,4,9,10,10,9,47,51,47,17,51,47,237,18,57,47,0,47,43,253,246,93,237,49,48,43,23,54,51,50,21,20,6,35,34,39,
55,22,51,50,53,52,35,34,7,233,46,49,157,125,105,62,83,22,68,36,130,73,27,45,127,15,110,69,89,22,71,14,65,43,13,0,2,0,41,0,102,4,71,4,109,0,36,0,48,1,2,64,101,10,1,10,8,6,29,10,38,26,1,22,29,25,34,26,38,
8,1,17,18,18,0,11,26,27,27,10,8,29,28,28,9,20,35,36,36,19,9,8,8,85,11,10,20,11,11,10,19,20,20,85,17,18,20,17,17,18,29,28,28,85,27,26,20,27,27,26,1,0,0,85,36,35,20,36,36,35,36,35,29,28,27,0,6,32,26,20,
8,1,4,40,19,17,11,9,4,14,46,40,97,32,184,1,205,64,47,14,18,10,7,46,97,14,7,0,9,36,10,8,1,4,4,35,29,17,11,4,37,28,26,20,18,4,43,19,27,43,99,23,129,27,74,50,37,99,4,129,9,73,49,89,153,24,43,78,16,244,77,
244,237,78,16,246,77,244,237,18,57,18,23,57,17,23,57,18,23,57,17,57,0,63,237,63,60,16,253,237,17,18,23,57,18,23,57,17,23,57,135,14,46,43,14,125,16,196,135,14,46,24,43,14,125,16,196,135,14,46,24,43,14,
125,16,196,135,14,46,24,43,14,125,16,196,7,14,16,60,60,7,14,16,60,60,7,14,16,60,60,7,14,16,60,60,49,48,1,93,63,1,46,1,53,52,55,54,55,39,55,23,62,1,51,50,22,23,55,23,7,30,1,21,20,6,7,23,7,39,14,1,35,34,
38,39,7,19,20,22,51,50,54,53,52,38,35,34,6,42,116,61,47,28,21,62,120,90,120,76,161,84,81,150,81,117,88,116,64,51,49,60,116,89,116,79,155,87,86,153,82,117,62,221,155,156,220,219,156,156,221,192,114,82,
143,83,89,82,63,77,117,91,119,59,53,48,58,113,91,112,79,148,88,86,145,78,114,90,115,62,53,52,63,115,1,254,154,218,220,155,155,219,221,0,0,2,0,0,0,0,0,0,255,59,0,119,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,2,154,0,0,0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10,0,11,0,12,0,13,0,14,0,15,0,16,0,17,0,18,0,19,0,20,0,21,0,22,0,23,0,24,0,25,0,26,0,27,0,28,0,29,0,30,0,31,0,32,0,33,0,34,0,35,0,36,0,37,0,38,0,39,
0,40,0,41,0,42,0,43,0,44,0,45,0,46,0,47,0,48,0,49,0,50,0,51,0,52,0,53,0,54,0,55,0,56,0,57,0,58,0,59,0,60,0,61,0,62,0,63,0,64,0,65,0,66,0,67,0,68,0,69,0,70,0,71,0,72,0,73,0,74,0,75,0,76,0,77,0,78,0,79,
0,80,0,81,0,82,0,83,0,84,0,85,0,86,0,87,0,88,0,89,0,90,0,91,0,92,0,93,0,94,0,95,0,96,0,97,0,98,0,99,0,100,0,101,0,102,0,103,0,104,0,105,0,106,0,107,0,108,0,109,0,110,0,111,0,112,0,113,0,114,0,115,0,116,
0,117,0,118,0,119,0,120,0,121,0,122,0,123,0,124,0,125,0,126,0,127,0,128,0,129,0,130,0,131,0,132,0,133,0,134,0,135,0,136,0,137,0,138,0,139,0,140,0,141,0,142,0,143,0,144,0,145,0,146,0,147,0,148,0,149,0,
150,1,2,0,152,0,153,0,154,0,155,0,156,0,157,0,158,1,3,0,160,0,161,0,162,0,163,0,164,0,165,0,166,0,167,0,168,0,169,0,170,0,171,0,172,0,173,0,174,0,175,0,176,0,177,0,178,0,179,0,180,0,181,0,182,0,183,0,
184,0,185,0,186,0,187,0,188,2,153,0,190,0,191,0,192,0,193,0,194,0,195,0,196,0,197,0,198,0,199,0,200,0,201,0,202,0,203,0,204,0,205,0,206,0,207,0,208,0,209,0,210,0,211,0,212,0,213,0,214,0,215,0,216,0,217,
0,218,0,219,0,220,0,221,0,222,0,223,0,224,0,225,0,226,0,227,0,228,0,229,0,230,0,231,0,232,0,233,0,234,0,235,0,236,0,237,0,238,0,239,0,240,0,241,0,242,0,243,0,244,0,245,0,246,0,247,0,248,0,249,0,250,0,
251,0,252,0,253,0,254,0,255,1,0,1,4,1,5,1,6,1,7,1,8,1,9,1,10,1,11,1,12,1,13,1,14,1,15,1,16,1,17,1,18,1,19,1,20,1,21,1,22,1,23,1,24,1,25,1,26,1,27,1,28,1,29,1,30,1,31,1,32,1,33,1,34,1,35,1,36,1,37,1,38,
1,39,1,40,1,41,1,42,1,43,1,44,1,45,1,46,1,47,1,48,1,49,1,50,1,51,1,52,1,53,1,54,1,55,1,56,1,57,1,58,1,59,1,60,1,61,1,62,1,63,1,64,1,65,1,66,1,67,1,68,1,69,1,70,1,71,1,72,1,73,1,74,1,75,1,76,1,77,1,78,
1,79,1,80,1,81,1,82,1,83,1,84,1,85,1,86,1,87,1,88,1,89,1,90,1,91,1,92,1,93,1,94,1,95,1,96,1,97,1,98,1,99,1,100,1,101,1,102,1,103,1,104,1,105,1,106,1,107,1,108,1,109,1,110,1,111,1,112,1,113,1,114,1,115,
1,116,1,117,1,118,1,119,1,120,1,121,1,122,1,123,1,124,1,125,1,126,1,127,1,128,1,129,1,130,1,131,1,132,1,133,1,134,1,135,1,136,1,137,1,138,1,139,1,140,1,141,1,142,1,143,1,144,1,145,1,146,1,147,1,148,1,
149,1,150,1,151,1,152,1,153,1,154,1,155,1,156,1,157,1,158,1,159,1,160,1,161,1,162,1,163,1,164,1,165,1,166,1,167,1,168,1,169,1,170,1,171,1,172,1,173,1,174,1,175,1,176,1,177,1,178,1,179,1,180,1,181,1,182,
1,183,1,184,1,185,1,186,1,187,1,188,0,159,1,189,1,190,1,191,1,192,1,193,1,194,1,195,1,196,1,197,1,198,1,199,1,200,1,201,1,202,1,203,1,204,1,205,1,206,0,151,1,207,1,208,1,209,0,155,1,210,1,211,1,212,1,
213,1,214,1,215,1,216,1,217,1,218,1,219,1,220,1,221,1,222,1,223,1,224,1,225,1,226,1,227,1,228,1,229,1,230,1,231,1,232,1,233,1,234,1,235,1,236,1,237,1,238,1,239,1,240,1,241,1,242,1,243,1,244,1,245,1,246,
1,247,1,248,1,249,1,250,1,251,1,252,1,253,1,254,1,255,2,0,2,1,2,2,2,3,2,4,2,5,2,6,2,7,2,8,2,9,2,10,2,11,2,12,2,13,2,14,2,15,2,16,2,17,2,18,2,19,2,20,2,21,2,22,2,23,2,24,2,25,2,26,2,27,2,28,2,29,2,30,2,
31,2,32,2,33,2,34,2,35,2,36,2,37,2,38,2,39,2,40,2,41,2,42,2,43,2,44,2,45,2,46,2,47,2,48,2,49,2,50,2,51,2,52,2,53,2,54,2,55,2,56,2,57,2,58,2,59,2,60,2,61,2,62,2,63,2,64,2,65,2,66,2,67,2,68,2,69,2,70,2,
71,2,72,2,73,2,74,2,75,2,76,2,77,2,78,2,79,2,80,2,81,2,82,2,83,2,84,2,85,2,86,2,87,2,88,2,89,2,90,2,91,2,92,2,93,2,94,2,95,2,96,2,97,2,98,2,99,2,100,2,101,2,102,2,103,2,104,2,105,2,106,2,107,2,108,2,109,
2,110,2,111,2,112,2,113,2,114,2,115,2,116,2,117,2,118,2,119,2,120,2,121,2,122,2,123,2,124,2,125,2,126,2,127,2,128,2,129,2,130,2,131,2,132,2,133,2,134,2,135,2,136,2,137,2,138,2,139,2,140,2,141,2,142,2,
143,2,144,2,145,2,146,2,147,2,148,2,149,2,150,2,151,2,152,0,189,3,109,117,49,3,79,104,109,7,100,109,97,99,114,111,110,9,111,118,101,114,115,99,111,114,101,6,109,105,100,100,111,116,12,102,111,117,114,
115,117,112,101,114,105,111,114,6,65,98,114,101,118,101,6,97,98,114,101,118,101,7,65,111,103,111,110,101,107,7,97,111,103,111,110,101,107,6,68,99,97,114,111,110,6,100,99,97,114,111,110,6,68,115,108,97,
115,104,7,69,111,103,111,110,101,107,7,101,111,103,111,110,101,107,6,69,99,97,114,111,110,6,101,99,97,114,111,110,2,73,74,2,105,106,6,76,97,99,117,116,101,6,108,97,99,117,116,101,6,76,99,97,114,111,110,
6,108,99,97,114,111,110,4,76,100,111,116,4,108,100,111,116,6,78,97,99,117,116,101,6,110,97,99,117,116,101,6,78,99,97,114,111,110,6,110,99,97,114,111,110,11,110,97,112,111,115,116,114,111,112,104,101,9,
79,100,98,108,97,99,117,116,101,9,111,100,98,108,97,99,117,116,101,6,82,97,99,117,116,101,6,114,97,99,117,116,101,6,82,99,97,114,111,110,6,114,99,97,114,111,110,6,83,97,99,117,116,101,6,115,97,99,117,
116,101,8,84,99,101,100,105,108,108,97,8,116,99,101,100,105,108,108,97,6,84,99,97,114,111,110,6,116,99,97,114,111,110,5,85,114,105,110,103,5,117,114,105,110,103,9,85,100,98,108,97,99,117,116,101,9,117,
100,98,108,97,99,117,116,101,6,90,97,99,117,116,101,6,122,97,99,117,116,101,4,90,100,111,116,4,122,100,111,116,7,110,111,71,97,109,109,97,7,110,111,84,104,101,116,97,5,110,111,80,104,105,7,110,111,97,
108,112,104,97,7,110,111,100,101,108,116,97,9,110,111,101,112,115,105,108,111,110,7,110,111,115,105,103,109,97,5,110,111,116,97,117,5,110,111,112,104,105,13,117,110,100,101,114,115,99,111,114,101,100,
98,108,6,109,105,110,117,116,101,6,115,101,99,111,110,100,9,101,120,99,108,97,109,100,98,108,9,110,115,117,112,101,114,105,111,114,6,112,101,115,101,116,97,9,97,102,105,105,54,49,50,52,56,9,97,102,105,
105,54,49,50,56,57,9,97,114,114,111,119,108,101,102,116,7,97,114,114,111,119,117,112,10,97,114,114,111,119,114,105,103,104,116,9,97,114,114,111,119,100,111,119,110,9,97,114,114,111,119,98,111,116,104,
9,97,114,114,111,119,117,112,100,110,12,97,114,114,111,119,117,112,100,110,98,115,101,10,111,114,116,104,111,103,111,110,97,108,12,105,110,116,101,114,115,101,99,116,105,111,110,11,101,113,117,105,118,
97,108,101,110,99,101,6,72,50,50,48,55,51,6,72,49,56,53,52,51,6,72,49,56,53,53,49,6,72,49,56,53,51,51,10,111,112,101,110,98,117,108,108,101,116,11,99,111,109,109,97,97,99,99,101,110,116,7,65,109,97,99,
114,111,110,7,97,109,97,99,114,111,110,11,67,99,105,114,99,117,109,102,108,101,120,11,99,99,105,114,99,117,109,102,108,101,120,4,67,100,111,116,4,99,100,111,116,7,69,109,97,99,114,111,110,7,101,109,97,
99,114,111,110,6,69,98,114,101,118,101,6,101,98,114,101,118,101,4,69,100,111,116,4,101,100,111,116,11,71,99,105,114,99,117,109,102,108,101,120,11,103,99,105,114,99,117,109,102,108,101,120,4,71,100,111,
116,4,103,100,111,116,8,71,99,101,100,105,108,108,97,8,103,99,101,100,105,108,108,97,11,72,99,105,114,99,117,109,102,108,101,120,11,104,99,105,114,99,117,109,102,108,101,120,4,72,98,97,114,4,104,98,97,
114,6,73,116,105,108,100,101,6,105,116,105,108,100,101,7,73,109,97,99,114,111,110,7,105,109,97,99,114,111,110,6,73,98,114,101,118,101,6,105,98,114,101,118,101,7,73,111,103,111,110,101,107,7,105,111,103,
111,110,101,107,11,74,99,105,114,99,117,109,102,108,101,120,11,106,99,105,114,99,117,109,102,108,101,120,8,75,99,101,100,105,108,108,97,8,107,99,101,100,105,108,108,97,12,107,103,114,101,101,110,108,97,
110,100,105,99,8,76,99,101,100,105,108,108,97,8,108,99,101,100,105,108,108,97,8,78,99,101,100,105,108,108,97,8,110,99,101,100,105,108,108,97,3,69,110,103,3,101,110,103,7,79,109,97,99,114,111,110,7,111,
109,97,99,114,111,110,6,79,98,114,101,118,101,6,111,98,114,101,118,101,8,82,99,101,100,105,108,108,97,8,114,99,101,100,105,108,108,97,11,83,99,105,114,99,117,109,102,108,101,120,11,115,99,105,114,99,117,
109,102,108,101,120,4,84,98,97,114,4,116,98,97,114,6,85,116,105,108,100,101,6,117,116,105,108,100,101,7,85,109,97,99,114,111,110,7,117,109,97,99,114,111,110,6,85,98,114,101,118,101,6,117,98,114,101,118,
101,7,85,111,103,111,110,101,107,7,117,111,103,111,110,101,107,11,87,99,105,114,99,117,109,102,108,101,120,11,119,99,105,114,99,117,109,102,108,101,120,11,89,99,105,114,99,117,109,102,108,101,120,11,121,
99,105,114,99,117,109,102,108,101,120,5,108,111,110,103,115,10,65,114,105,110,103,97,99,117,116,101,10,97,114,105,110,103,97,99,117,116,101,7,65,69,97,99,117,116,101,7,97,101,97,99,117,116,101,11,79,115,
108,97,115,104,97,99,117,116,101,11,111,115,108,97,115,104,97,99,117,116,101,5,116,111,110,111,115,13,100,105,101,114,101,115,105,115,116,111,110,111,115,10,65,108,112,104,97,116,111,110,111,115,9,97,
110,111,116,101,108,101,105,97,12,69,112,115,105,108,111,110,116,111,110,111,115,8,69,116,97,116,111,110,111,115,9,73,111,116,97,116,111,110,111,115,12,79,109,105,99,114,111,110,116,111,110,111,115,12,
85,112,115,105,108,111,110,116,111,110,111,115,10,79,109,101,103,97,116,111,110,111,115,17,105,111,116,97,100,105,101,114,101,115,105,115,116,111,110,111,115,5,65,108,112,104,97,4,66,101,116,97,5,71,97,
109,109,97,5,68,101,108,116,97,7,69,112,115,105,108,111,110,4,90,101,116,97,3,69,116,97,5,84,104,101,116,97,4,73,111,116,97,5,75,97,112,112,97,6,76,97,109,98,100,97,2,77,117,2,78,117,2,88,105,7,79,109,
105,99,114,111,110,2,80,105,3,82,104,111,5,83,105,103,109,97,3,84,97,117,7,85,112,115,105,108,111,110,3,80,104,105,3,67,104,105,3,80,115,105,12,73,111,116,97,100,105,101,114,101,115,105,115,15,85,112,
115,105,108,111,110,100,105,101,114,101,115,105,115,10,97,108,112,104,97,116,111,110,111,115,12,101,112,115,105,108,111,110,116,111,110,111,115,8,101,116,97,116,111,110,111,115,9,105,111,116,97,116,111,
110,111,115,20,117,112,115,105,108,111,110,100,105,101,114,101,115,105,115,116,111,110,111,115,5,97,108,112,104,97,4,98,101,116,97,5,103,97,109,109,97,5,100,101,108,116,97,7,101,112,115,105,108,111,110,
4,122,101,116,97,3,101,116,97,5,116,104,101,116,97,4,105,111,116,97,5,107,97,112,112,97,6,108,97,109,98,100,97,2,110,117,2,120,105,7,111,109,105,99,114,111,110,3,114,104,111,6,115,105,103,109,97,49,5,
115,105,103,109,97,3,116,97,117,7,117,112,115,105,108,111,110,3,112,104,105,3,99,104,105,3,112,115,105,5,111,109,101,103,97,12,105,111,116,97,100,105,101,114,101,115,105,115,15,117,112,115,105,108,111,
110,100,105,101,114,101,115,105,115,12,111,109,105,99,114,111,110,116,111,110,111,115,12,117,112,115,105,108,111,110,116,111,110,111,115,10,111,109,101,103,97,116,111,110,111,115,9,97,102,105,105,49,48,
48,50,51,9,97,102,105,105,49,48,48,53,49,9,97,102,105,105,49,48,48,53,50,9,97,102,105,105,49,48,48,53,51,9,97,102,105,105,49,48,48,53,52,9,97,102,105,105,49,48,48,53,53,9,97,102,105,105,49,48,48,53,54,
9,97,102,105,105,49,48,48,53,55,9,97,102,105,105,49,48,48,53,56,9,97,102,105,105,49,48,48,53,57,9,97,102,105,105,49,48,48,54,48,9,97,102,105,105,49,48,48,54,49,9,97,102,105,105,49,48,48,54,50,9,97,102,
105,105,49,48,49,52,53,9,97,102,105,105,49,48,48,49,55,9,97,102,105,105,49,48,48,49,56,9,97,102,105,105,49,48,48,49,57,9,97,102,105,105,49,48,48,50,48,9,97,102,105,105,49,48,48,50,49,9,97,102,105,105,
49,48,48,50,50,9,97,102,105,105,49,48,48,50,52,9,97,102,105,105,49,48,48,50,53,9,97,102,105,105,49,48,48,50,54,9,97,102,105,105,49,48,48,50,55,9,97,102,105,105,49,48,48,50,56,9,97,102,105,105,49,48,48,
50,57,9,97,102,105,105,49,48,48,51,48,9,97,102,105,105,49,48,48,51,49,9,97,102,105,105,49,48,48,51,50,9,97,102,105,105,49,48,48,51,51,9,97,102,105,105,49,48,48,51,52,9,97,102,105,105,49,48,48,51,53,9,
97,102,105,105,49,48,48,51,54,9,97,102,105,105,49,48,48,51,55,9,97,102,105,105,49,48,48,51,56,9,97,102,105,105,49,48,48,51,57,9,97,102,105,105,49,48,48,52,48,9,97,102,105,105,49,48,48,52,49,9,97,102,105,
105,49,48,48,52,50,9,97,102,105,105,49,48,48,52,51,9,97,102,105,105,49,48,48,52,52,9,97,102,105,105,49,48,48,52,53,9,97,102,105,105,49,48,48,52,54,9,97,102,105,105,49,48,48,52,55,9,97,102,105,105,49,48,
48,52,56,9,97,102,105,105,49,48,48,52,57,9,97,102,105,105,49,48,48,54,53,9,97,102,105,105,49,48,48,54,54,9,97,102,105,105,49,48,48,54,55,9,97,102,105,105,49,48,48,54,56,9,97,102,105,105,49,48,48,54,57,
9,97,102,105,105,49,48,48,55,48,9,97,102,105,105,49,48,48,55,50,9,97,102,105,105,49,48,48,55,51,9,97,102,105,105,49,48,48,55,52,9,97,102,105,105,49,48,48,55,53,9,97,102,105,105,49,48,48,55,54,9,97,102,
105,105,49,48,48,55,55,9,97,102,105,105,49,48,48,55,56,9,97,102,105,105,49,48,48,55,57,9,97,102,105,105,49,48,48,56,48,9,97,102,105,105,49,48,48,56,49,9,97,102,105,105,49,48,48,56,50,9,97,102,105,105,
49,48,48,56,51,9,97,102,105,105,49,48,48,56,52,9,97,102,105,105,49,48,48,56,53,9,97,102,105,105,49,48,48,56,54,9,97,102,105,105,49,48,48,56,55,9,97,102,105,105,49,48,48,56,56,9,97,102,105,105,49,48,48,
56,57,9,97,102,105,105,49,48,48,57,48,9,97,102,105,105,49,48,48,57,49,9,97,102,105,105,49,48,48,57,50,9,97,102,105,105,49,48,48,57,51,9,97,102,105,105,49,48,48,57,52,9,97,102,105,105,49,48,48,57,53,9,
97,102,105,105,49,48,48,57,54,9,97,102,105,105,49,48,48,57,55,9,97,102,105,105,49,48,48,55,49,9,97,102,105,105,49,48,48,57,57,9,97,102,105,105,49,48,49,48,48,9,97,102,105,105,49,48,49,48,49,9,97,102,105,
105,49,48,49,48,50,9,97,102,105,105,49,48,49,48,51,9,97,102,105,105,49,48,49,48,52,9,97,102,105,105,49,48,49,48,53,9,97,102,105,105,49,48,49,48,54,9,97,102,105,105,49,48,49,48,55,9,97,102,105,105,49,48,
49,48,56,9,97,102,105,105,49,48,49,48,57,9,97,102,105,105,49,48,49,49,48,9,97,102,105,105,49,48,49,57,51,9,97,102,105,105,49,48,48,53,48,9,97,102,105,105,49,48,48,57,56,6,87,103,114,97,118,101,6,119,103,
114,97,118,101,6,87,97,99,117,116,101,6,119,97,99,117,116,101,9,87,100,105,101,114,101,115,105,115,9,119,100,105,101,114,101,115,105,115,6,89,103,114,97,118,101,6,121,103,114,97,118,101,9,97,102,105,105,
48,48,50,48,56,13,113,117,111,116,101,114,101,118,101,114,115,101,100,9,114,97,100,105,99,97,108,101,120,9,97,102,105,105,48,56,57,52,49,9,97,102,105,105,54,49,51,53,50,9,101,115,116,105,109,97,116,101,
100,9,111,110,101,101,105,103,104,116,104,12,116,104,114,101,101,101,105,103,104,116,104,115,11,102,105,118,101,101,105,103,104,116,104,115,12,115,101,118,101,110,101,105,103,104,116,104,115,5,104,111,
117,115,101,13,114,101,118,108,111,103,105,99,97,108,110,111,116,10,105,110,116,101,103,114,97,108,116,112,10,105,110,116,101,103,114,97,108,98,116,8,83,70,49,48,48,48,48,48,8,83,70,49,49,48,48,48,48,
8,83,70,48,49,48,48,48,48,8,83,70,48,51,48,48,48,48,8,83,70,48,50,48,48,48,48,8,83,70,48,52,48,48,48,48,8,83,70,48,56,48,48,48,48,8,83,70,48,57,48,48,48,48,8,83,70,48,54,48,48,48,48,8,83,70,48,55,48,48,
48,48,8,83,70,48,53,48,48,48,48,8,83,70,52,51,48,48,48,48,8,83,70,50,52,48,48,48,48,8,83,70,53,49,48,48,48,48,8,83,70,53,50,48,48,48,48,8,83,70,51,57,48,48,48,48,8,83,70,50,50,48,48,48,48,8,83,70,50,49,
48,48,48,48,8,83,70,50,53,48,48,48,48,8,83,70,53,48,48,48,48,48,8,83,70,52,57,48,48,48,48,8,83,70,51,56,48,48,48,48,8,83,70,50,56,48,48,48,48,8,83,70,50,55,48,48,48,48,8,83,70,50,54,48,48,48,48,8,83,70,
51,54,48,48,48,48,8,83,70,51,55,48,48,48,48,8,83,70,52,50,48,48,48,48,8,83,70,49,57,48,48,48,48,8,83,70,50,48,48,48,48,48,8,83,70,50,51,48,48,48,48,8,83,70,52,55,48,48,48,48,8,83,70,52,56,48,48,48,48,
8,83,70,52,49,48,48,48,48,8,83,70,52,53,48,48,48,48,8,83,70,52,54,48,48,48,48,8,83,70,52,48,48,48,48,48,8,83,70,53,52,48,48,48,48,8,83,70,53,51,48,48,48,48,8,83,70,52,52,48,48,48,48,7,117,112,98,108,111,
99,107,7,100,110,98,108,111,99,107,5,98,108,111,99,107,7,108,102,98,108,111,99,107,7,114,116,98,108,111,99,107,7,108,116,115,104,97,100,101,5,115,104,97,100,101,7,100,107,115,104,97,100,101,9,102,105,
108,108,101,100,98,111,120,10,102,105,108,108,101,100,114,101,99,116,7,116,114,105,97,103,117,112,7,116,114,105,97,103,114,116,7,116,114,105,97,103,100,110,7,116,114,105,97,103,108,102,6,99,105,114,99,
108,101,9,105,110,118,98,117,108,108,101,116,9,105,110,118,99,105,114,99,108,101,9,115,109,105,108,101,102,97,99,101,12,105,110,118,115,109,105,108,101,102,97,99,101,3,115,117,110,6,102,101,109,97,108,
101,4,109,97,108,101,5,115,112,97,100,101,4,99,108,117,98,5,104,101,97,114,116,7,100,105,97,109,111,110,100,11,109,117,115,105,99,97,108,110,111,116,101,14,109,117,115,105,99,97,108,110,111,116,101,100,
98,108,16,117,110,100,101,114,99,111,109,109,97,97,99,99,101,110,116,4,69,117,114,111,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,20,13,0,0,0,20,0,0,0,0,0,0,20,5,48,130,20,1,6,9,42,134,72,134,247,13,1,7,2,160,130,
19,242,48,130,19,238,2,1,1,49,14,48,12,6,8,42,134,72,134,247,13,2,5,5,0,48,96,6,10,43,6,1,4,1,130,55,2,1,4,160,82,48,80,48,44,6,10,43,6,1,4,1,130,55,2,1,28,162,30,128,28,0,60,0,60,0,60,0,79,0,98,0,115,
0,111,0,108,0,101,0,116,0,101,0,62,0,62,0,62,48,32,48,12,6,8,42,134,72,134,247,13,2,5,5,0,4,16,46,48,224,20,197,171,36,80,237,252,113,223,250,91,54,118,160,130,15,63,48,130,2,192,48,130,2,41,2,20,19,137,
180,209,138,232,167,196,189,53,199,155,141,136,202,31,202,83,86,145,48,13,6,9,42,134,72,134,247,13,1,1,4,5,0,48,129,158,49,31,48,29,6,3,85,4,10,19,22,86,101,114,105,83,105,103,110,32,84,114,117,115,116,
32,78,101,116,119,111,114,107,49,23,48,21,6,3,85,4,11,19,14,86,101,114,105,83,105,103,110,44,32,73,110,99,46,49,44,48,42,6,3,85,4,11,19,35,86,101,114,105,83,105,103,110,32,84,105,109,101,32,83,116,97,
109,112,105,110,103,32,83,101,114,118,105,99,101,32,82,111,111,116,49,52,48,50,6,3,85,4,11,19,43,78,79,32,76,73,65,66,73,76,73,84,89,32,65,67,67,69,80,84,69,68,44,32,40,99,41,57,55,32,86,101,114,105,83,
105,103,110,44,32,73,110,99,46,48,30,23,13,57,55,48,53,49,50,48,55,48,48,48,48,90,23,13,57,57,49,50,51,49,48,55,48,48,48,48,90,48,129,158,49,31,48,29,6,3,85,4,10,19,22,86,101,114,105,83,105,103,110,32,
84,114,117,115,116,32,78,101,116,119,111,114,107,49,23,48,21,6,3,85,4,11,19,14,86,101,114,105,83,105,103,110,44,32,73,110,99,46,49,44,48,42,6,3,85,4,11,19,35,86,101,114,105,83,105,103,110,32,84,105,109,
101,32,83,116,97,109,112,105,110,103,32,83,101,114,118,105,99,101,32,82,111,111,116,49,52,48,50,6,3,85,4,11,19,43,78,79,32,76,73,65,66,73,76,73,84,89,32,65,67,67,69,80,84,69,68,44,32,40,99,41,57,55,32,
86,101,114,105,83,105,103,110,44,32,73,110,99,46,48,129,159,48,13,6,9,42,134,72,134,247,13,1,1,1,5,0,3,129,141,0,48,129,137,2,129,129,0,211,46,32,240,104,124,44,45,46,129,28,177,6,178,167,11,183,17,13,
87,218,83,216,117,227,201,51,42,178,212,246,9,91,52,243,233,144,254,9,12,208,219,27,90,185,205,231,246,136,177,157,192,135,37,235,125,88,16,115,106,120,203,113,21,253,198,88,246,41,171,88,94,150,4,253,
45,98,17,88,129,28,202,113,148,213,34,88,47,213,204,20,5,132,54,186,148,170,180,77,74,233,238,59,34,173,86,153,126,33,156,108,134,192,74,71,151,106,180,166,54,213,252,9,45,211,180,57,155,2,3,1,0,1,48,
13,6,9,42,134,72,134,247,13,1,1,4,5,0,3,129,129,0,58,17,156,133,5,62,210,233,128,251,123,213,169,244,172,121,252,5,252,149,61,113,35,169,43,40,223,140,19,101,137,254,44,135,1,143,90,154,98,202,17,167,
128,244,183,190,20,183,209,86,153,107,8,98,69,198,162,165,218,53,127,5,34,222,114,45,4,134,5,167,124,9,22,147,20,67,240,247,22,77,214,7,142,155,16,108,88,254,10,53,151,202,137,159,223,4,112,156,42,125,
97,142,193,232,11,113,154,168,199,102,98,66,61,149,148,34,50,152,34,137,138,250,100,8,36,245,210,250,48,130,2,205,48,130,2,54,2,21,0,189,17,154,218,67,237,33,251,70,88,132,137,202,70,136,144,37,238,20,
96,48,13,6,9,42,134,72,134,247,13,1,1,4,5,0,48,129,158,49,31,48,29,6,3,85,4,10,19,22,86,101,114,105,83,105,103,110,32,84,114,117,115,116,32,78,101,116,119,111,114,107,49,23,48,21,6,3,85,4,11,19,14,86,
101,114,105,83,105,103,110,44,32,73,110,99,46,49,44,48,42,6,3,85,4,11,19,35,86,101,114,105,83,105,103,110,32,84,105,109,101,32,83,116,97,109,112,105,110,103,32,83,101,114,118,105,99,101,32,82,111,111,
116,49,52,48,50,6,3,85,4,11,19,43,78,79,32,76,73,65,66,73,76,73,84,89,32,65,67,67,69,80,84,69,68,44,32,40,99,41,57,55,32,86,101,114,105,83,105,103,110,44,32,73,110,99,46,48,30,23,13,57,55,48,53,49,50,
48,55,48,48,48,48,90,23,13,57,57,49,50,51,49,48,55,48,48,48,48,90,48,129,172,49,39,48,37,6,3,85,4,11,19,30,86,101,114,105,83,105,103,110,32,84,105,109,101,32,83,116,97,109,112,105,110,103,32,83,101,114,
118,105,99,101,49,31,48,29,6,3,85,4,11,19,22,86,101,114,105,83,105,103,110,32,84,114,117,115,116,32,78,101,116,119,111,114,107,49,52,48,50,6,3,85,4,11,19,43,78,79,32,76,73,65,66,73,76,73,84,89,32,65,67,
67,69,80,84,69,68,44,32,40,99,41,57,55,32,86,101,114,105,83,105,103,110,44,32,73,110,99,46,49,23,48,21,6,3,85,4,10,19,14,86,101,114,105,83,105,103,110,44,32,73,110,99,46,49,17,48,15,6,3,85,4,7,19,8,73,
110,116,101,114,110,101,116,48,129,157,48,13,6,9,42,134,72,134,247,13,1,1,1,5,0,3,129,139,0,48,129,135,2,129,129,0,171,97,237,180,173,141,144,71,144,220,180,17,94,105,220,10,127,98,144,6,49,205,206,255,
136,145,70,215,73,58,148,233,212,6,63,157,173,162,120,90,236,249,252,99,69,79,184,11,110,48,239,162,54,171,45,9,223,241,111,39,171,13,81,96,5,53,79,127,206,84,79,208,183,44,66,216,11,208,141,184,94,255,
182,128,208,227,150,180,127,34,73,66,16,108,211,152,176,1,86,163,195,207,46,159,58,244,127,168,88,166,215,34,101,229,140,171,120,156,188,217,71,66,104,91,45,125,253,181,2,1,3,48,13,6,9,42,134,72,134,247,
13,1,1,4,5,0,3,129,129,0,109,96,251,153,95,164,105,179,211,123,112,43,98,35,30,68,32,81,175,35,21,199,116,2,249,73,242,39,26,92,172,134,113,53,8,43,246,143,222,224,181,150,232,139,167,75,227,115,200,72,
9,157,176,218,139,218,21,146,202,3,229,9,37,86,6,231,78,164,71,165,209,87,70,212,56,86,245,33,205,195,38,59,45,37,50,206,155,226,191,64,71,234,216,109,71,118,229,192,48,163,15,128,206,127,216,59,126,160,
249,149,42,49,43,21,250,200,20,237,221,176,233,85,65,112,70,45,44,126,48,130,9,166,48,130,9,15,160,3,2,1,2,2,16,121,102,150,110,131,176,208,182,1,18,110,157,192,180,101,113,48,13,6,9,42,134,72,134,247,
13,1,1,2,5,0,48,97,49,17,48,15,6,3,85,4,7,19,8,73,110,116,101,114,110,101,116,49,23,48,21,6,3,85,4,10,19,14,86,101,114,105,83,105,103,110,44,32,73,110,99,46,49,51,48,49,6,3,85,4,11,19,42,86,101,114,105,
83,105,103,110,32,67,111,109,109,101,114,99,105,97,108,32,83,111,102,116,119,97,114,101,32,80,117,98,108,105,115,104,101,114,115,32,67,65,48,30,23,13,57,56,48,52,49,54,48,48,48,48,48,48,90,23,13,57,57,
48,52,49,54,50,51,53,57,53,57,90,48,130,1,93,49,17,48,15,6,3,85,4,7,19,8,73,110,116,101,114,110,101,116,49,23,48,21,6,3,85,4,10,19,14,86,101,114,105,83,105,103,110,44,32,73,110,99,46,49,51,48,49,6,3,85,
4,11,19,42,86,101,114,105,83,105,103,110,32,67,111,109,109,101,114,99,105,97,108,32,83,111,102,116,119,97,114,101,32,80,117,98,108,105,115,104,101,114,115,32,67,65,49,70,48,68,6,3,85,4,11,19,61,119,119,
119,46,118,101,114,105,115,105,103,110,46,99,111,109,47,114,101,112,111,115,105,116,111,114,121,47,67,80,83,32,73,110,99,111,114,112,46,32,98,121,32,82,101,102,46,44,76,73,65,66,46,76,84,68,40,99,41,57,
54,49,62,48,60,6,3,85,4,11,19,53,68,105,103,105,116,97,108,32,73,68,32,67,108,97,115,115,32,51,32,45,32,77,105,99,114,111,115,111,102,116,32,83,111,102,116,119,97,114,101,32,86,97,108,105,100,97,116,105,
111,110,32,118,50,49,11,48,9,6,3,85,4,6,19,2,85,83,49,19,48,17,6,3,85,4,8,19,10,87,97,115,104,105,110,103,116,111,110,49,16,48,14,6,3,85,4,7,19,7,82,101,100,109,111,110,100,49,30,48,28,6,3,85,4,3,20,21,
77,105,99,114,111,115,111,102,116,32,67,111,114,112,111,114,97,116,105,111,110,49,30,48,28,6,3,85,4,11,20,21,77,105,99,114,111,115,111,102,116,32,67,111,114,112,111,114,97,116,105,111,110,48,130,1,32,
48,13,6,9,42,134,72,134,247,13,1,1,1,5,0,3,130,1,13,0,48,130,1,8,2,130,1,1,0,180,144,210,38,168,100,230,235,21,195,255,109,123,65,79,10,249,111,42,113,206,46,24,83,166,50,54,224,212,104,225,53,253,73,
18,216,150,252,101,207,83,20,32,190,4,201,122,245,201,112,109,148,236,204,179,175,42,48,154,50,88,124,182,169,107,37,103,153,192,226,119,234,5,229,239,227,150,247,173,11,25,166,174,60,132,112,226,248,
111,92,79,125,111,15,82,69,138,21,215,101,220,59,32,5,227,61,161,108,151,58,14,11,37,19,237,33,203,32,142,57,122,98,131,5,201,35,26,252,82,157,172,157,76,150,215,60,78,88,61,130,123,238,9,53,86,181,104,
192,66,69,162,59,49,163,251,216,149,251,85,199,44,168,163,195,41,79,206,244,147,240,3,31,123,241,21,58,169,248,170,80,131,5,109,98,240,139,19,136,56,217,227,28,14,115,193,6,64,186,40,195,235,205,146,113,
199,190,102,178,161,84,34,214,11,103,124,248,135,121,137,172,102,10,170,81,250,253,114,33,252,134,93,198,244,74,14,236,88,97,35,77,208,177,58,100,224,19,158,94,200,133,109,76,22,175,61,7,2,1,3,163,130,
5,221,48,130,5,217,48,9,6,3,85,29,19,4,2,48,0,48,11,6,3,85,29,15,4,4,3,2,5,160,48,129,136,6,3,85,29,1,4,129,128,48,126,128,16,123,150,228,209,67,253,104,152,243,56,204,110,59,242,11,130,161,99,48,97,49,
17,48,15,6,3,85,4,7,19,8,73,110,116,101,114,110,101,116,49,23,48,21,6,3,85,4,10,19,14,86,101,114,105,83,105,103,110,44,32,73,110,99,46,49,51,48,49,6,3,85,4,11,19,42,86,101,114,105,83,105,103,110,32,67,
111,109,109,101,114,99,105,97,108,32,83,111,102,116,119,97,114,101,32,80,117,98,108,105,115,104,101,114,115,32,67,65,130,5,2,180,0,0,1,48,33,6,3,85,29,4,1,1,255,4,23,48,20,48,14,48,12,6,10,43,6,1,4,1,
130,55,2,1,22,3,2,7,128,0,48,13,6,3,85,29,10,4,6,48,4,3,2,6,64,48,130,4,54,6,10,43,6,1,4,1,130,55,2,1,10,1,1,255,4,130,4,35,48,130,4,31,160,41,128,39,104,116,116,112,115,58,47,47,119,119,119,46,118,101,
114,105,115,105,103,110,46,99,111,109,47,114,101,112,111,115,105,116,111,114,121,47,67,80,83,161,130,3,184,129,130,3,180,84,104,105,115,32,99,101,114,116,105,102,105,99,97,116,101,32,105,110,99,111,114,
112,111,114,97,116,101,115,32,98,121,32,114,101,102,101,114,101,110,99,101,44,32,97,110,100,32,105,116,115,32,117,115,101,32,105,115,32,115,116,114,105,99,116,108,121,10,115,117,98,106,101,99,116,32,116,
111,44,32,116,104,101,32,86,101,114,105,83,105,103,110,32,67,101,114,116,105,102,105,99,97,116,105,111,110,32,80,114,97,99,116,105,99,101,32,83,116,97,116,101,109,101,110,116,32,40,67,80,83,41,10,118,
101,114,115,105,111,110,32,49,46,48,44,32,97,118,97,105,108,97,98,108,101,32,105,110,32,116,104,101,32,86,101,114,105,83,105,103,110,32,114,101,112,111,115,105,116,111,114,121,32,97,116,58,10,104,116,
116,112,115,58,47,47,119,119,119,46,118,101,114,105,115,105,103,110,46,99,111,109,59,32,98,121,32,69,45,109,97,105,108,32,97,116,32,67,80,83,45,114,101,113,117,101,115,116,115,64,118,101,114,105,115,105,
103,110,46,99,111,109,59,32,111,114,10,98,121,32,109,97,105,108,32,97,116,32,86,101,114,105,83,105,103,110,44,32,73,110,99,46,44,32,50,53,57,51,32,67,111,97,115,116,32,65,118,101,46,44,32,77,111,117,110,
116,97,105,110,32,86,105,101,119,44,32,67,65,32,57,52,48,52,51,10,85,83,65,32,67,111,112,121,114,105,103,104,116,32,40,99,41,49,57,57,54,32,86,101,114,105,83,105,103,110,44,32,73,110,99,46,32,32,65,108,
108,32,82,105,103,104,116,115,32,82,101,115,101,114,118,101,100,46,32,67,69,82,84,65,73,78,10,87,65,82,82,65,78,84,73,69,83,32,68,73,83,67,76,65,73,77,69,68,32,65,78,68,32,76,73,65,66,73,76,73,84,89,32,
76,73,77,73,84,69,68,46,10,10,87,65,82,78,73,78,71,58,32,84,72,69,32,85,83,69,32,79,70,32,84,72,73,83,32,67,69,82,84,73,70,73,67,65,84,69,32,73,83,32,83,84,82,73,67,84,76,89,32,83,85,66,74,69,67,84,32,
84,79,32,84,72,69,10,86,69,82,73,83,73,71,78,32,67,69,82,84,73,70,73,67,65,84,73,79,78,32,80,82,65,67,84,73,67,69,32,83,84,65,84,69,77,69,78,84,46,32,32,84,72,69,32,73,83,83,85,73,78,71,32,65,85,84,72,
79,82,73,84,89,10,68,73,83,67,76,65,73,77,83,32,67,69,82,84,65,73,78,32,73,77,80,76,73,69,68,32,65,78,68,32,69,88,80,82,69,83,83,32,87,65,82,82,65,78,84,73,69,83,44,32,73,78,67,76,85,68,73,78,71,32,87,
65,82,82,65,78,84,73,69,83,10,79,70,32,77,69,82,67,72,65,78,84,65,66,73,76,73,84,89,32,79,82,32,70,73,84,78,69,83,83,32,70,79,82,32,65,32,80,65,82,84,73,67,85,76,65,82,32,80,85,82,80,79,83,69,44,32,65,
78,68,32,87,73,76,76,32,78,79,84,10,66,69,32,76,73,65,66,76,69,32,70,79,82,32,67,79,78,83,69,81,85,69,78,84,73,65,76,44,32,80,85,78,73,84,73,86,69,44,32,65,78,68,32,67,69,82,84,65,73,78,32,79,84,72,69,
82,32,68,65,77,65,71,69,83,46,32,83,69,69,10,84,72,69,32,67,80,83,32,70,79,82,32,68,69,84,65,73,76,83,46,10,10,67,111,110,116,101,110,116,115,32,111,102,32,116,104,101,32,86,101,114,105,83,105,103,110,
32,114,101,103,105,115,116,101,114,101,100,32,110,111,110,118,101,114,105,102,105,101,100,83,117,98,106,101,99,116,65,116,116,114,105,98,117,116,101,115,10,101,120,116,101,110,115,105,111,110,32,118,97,
108,117,101,32,115,104,97,108,108,32,110,111,116,32,98,101,32,99,111,110,115,105,100,101,114,101,100,32,97,115,32,97,99,99,117,114,97,116,101,32,105,110,102,111,114,109,97,116,105,111,110,10,118,97,108,
105,100,97,116,101,100,32,98,121,32,116,104,101,32,73,65,46,10,163,54,128,52,104,116,116,112,115,58,47,47,119,119,119,46,118,101,114,105,115,105,103,110,46,99,111,109,47,114,101,112,111,115,105,116,111,
114,121,47,118,101,114,105,115,105,103,110,108,111,103,111,46,103,105,102,48,129,175,6,3,85,29,32,4,129,167,48,128,48,128,6,11,96,134,72,1,134,248,69,1,7,1,1,48,128,48,40,6,8,43,6,1,5,5,7,2,1,22,28,104,
116,116,112,115,58,47,47,119,119,119,46,118,101,114,105,115,105,103,110,46,99,111,109,47,67,80,83,48,98,6,8,43,6,1,5,5,7,2,2,48,86,48,21,22,14,86,101,114,105,83,105,103,110,44,32,73,110,99,46,48,3,2,1,
1,26,61,86,101,114,105,83,105,103,110,39,115,32,67,80,83,32,105,110,99,111,114,112,46,32,98,121,32,114,101,102,101,114,101,110,99,101,32,108,105,97,98,46,32,108,116,100,46,32,40,99,41,57,55,32,86,101,
114,105,83,105,103,110,0,0,0,0,0,0,48,22,6,10,43,6,1,4,1,130,55,2,1,27,4,8,48,6,1,1,255,1,1,255,48,13,6,9,42,134,72,134,247,13,1,1,2,5,0,3,129,129,0,149,76,162,121,85,218,116,92,139,37,194,166,32,240,
108,184,179,123,70,123,158,159,122,186,113,6,72,21,18,101,204,93,41,248,81,59,137,113,177,244,20,56,120,218,143,174,11,128,54,144,93,72,151,197,0,56,10,83,191,64,55,255,138,19,39,109,0,71,52,247,72,76,
46,114,242,198,211,126,253,68,111,34,143,209,146,159,227,148,237,231,255,0,201,194,238,114,28,217,156,3,110,182,193,99,123,50,120,68,59,158,133,138,251,132,134,55,40,46,231,166,56,55,62,186,252,243,130,
35,49,130,4,50,48,130,4,46,2,1,1,48,117,48,97,49,17,48,15,6,3,85,4,7,19,8,73,110,116,101,114,110,101,116,49,23,48,21,6,3,85,4,10,19,14,86,101,114,105,83,105,103,110,44,32,73,110,99,46,49,51,48,49,6,3,
85,4,11,19,42,86,101,114,105,83,105,103,110,32,67,111,109,109,101,114,99,105,97,108,32,83,111,102,116,119,97,114,101,32,80,117,98,108,105,115,104,101,114,115,32,67,65,2,16,121,102,150,110,131,176,208,
182,1,18,110,157,192,180,101,113,48,12,6,8,42,134,72,134,247,13,2,5,5,0,160,129,188,48,25,6,9,42,134,72,134,247,13,1,9,3,49,12,6,10,43,6,1,4,1,130,55,2,1,4,48,28,6,10,43,6,1,4,1,130,55,2,1,11,49,14,48,
12,6,10,43,6,1,4,1,130,55,2,1,22,48,31,6,9,42,134,72,134,247,13,1,9,4,49,18,4,16,206,45,90,205,83,103,59,132,238,111,37,230,218,33,116,33,48,96,6,10,43,6,1,4,1,130,55,2,1,12,49,82,48,80,160,40,128,38,
0,67,0,101,0,110,0,116,0,117,0,114,0,121,0,32,0,71,0,111,0,116,0,104,0,105,0,99,0,32,0,102,0,111,0,110,0,116,161,36,128,34,104,116,116,112,58,47,47,119,119,119,46,109,105,99,114,111,115,111,102,116,46,
99,111,109,47,116,114,117,101,116,121,112,101,47,48,13,6,9,42,134,72,134,247,13,1,1,1,5,0,4,130,1,0,120,221,245,247,190,7,191,134,47,35,53,112,161,194,135,204,87,153,232,67,192,225,39,131,63,57,118,183,
237,228,235,8,103,106,18,199,68,228,38,185,10,67,216,124,56,200,224,45,28,23,102,75,124,179,232,243,190,50,155,23,166,71,124,5,49,120,156,45,216,99,3,71,155,112,109,198,48,140,101,1,162,33,4,48,101,115,
45,253,209,110,0,80,111,86,202,52,241,159,204,162,235,107,95,161,217,163,218,112,139,77,144,3,134,163,50,210,199,184,118,183,149,88,205,234,16,168,114,86,229,142,78,247,244,224,244,103,21,184,27,182,198,
146,168,210,31,248,112,54,51,208,236,152,106,141,77,227,222,39,74,242,232,191,8,228,210,131,31,102,200,40,21,157,57,5,104,36,59,211,150,196,20,7,62,158,221,15,30,31,132,36,31,144,100,167,43,5,102,170,
149,207,106,73,252,51,93,191,93,202,65,156,240,190,71,221,85,242,197,74,181,42,23,18,120,171,168,126,85,53,246,158,222,177,180,70,46,199,21,255,114,100,232,59,96,206,57,31,39,51,195,183,249,178,179,173,
207,226,161,130,1,208,48,130,1,204,6,9,42,134,72,134,247,13,1,9,6,49,130,1,189,48,130,1,185,2,1,1,48,129,184,48,129,158,49,31,48,29,6,3,85,4,10,19,22,86,101,114,105,83,105,103,110,32,84,114,117,115,116,
32,78,101,116,119,111,114,107,49,23,48,21,6,3,85,4,11,19,14,86,101,114,105,83,105,103,110,44,32,73,110,99,46,49,44,48,42,6,3,85,4,11,19,35,86,101,114,105,83,105,103,110,32,84,105,109,101,32,83,116,97,
109,112,105,110,103,32,83,101,114,118,105,99,101,32,82,111,111,116,49,52,48,50,6,3,85,4,11,19,43,78,79,32,76,73,65,66,73,76,73,84,89,32,65,67,67,69,80,84,69,68,44,32,40,99,41,57,55,32,86,101,114,105,83,
105,103,110,44,32,73,110,99,46,2,21,0,189,17,154,218,67,237,33,251,70,88,132,137,202,70,136,144,37,238,20,96,48,12,6,8,42,134,72,134,247,13,2,5,5,0,160,89,48,24,6,9,42,134,72,134,247,13,1,9,3,49,11,6,
9,42,134,72,134,247,13,1,7,1,48,28,6,9,42,134,72,134,247,13,1,9,5,49,15,23,13,57,56,49,49,49,50,50,51,51,57,49,55,90,48,31,6,9,42,134,72,134,247,13,1,9,4,49,18,4,16,110,207,93,174,99,19,251,18,129,89,
63,190,1,153,28,238,48,13,6,9,42,134,72,134,247,13,1,1,1,5,0,4,129,128,117,190,91,186,75,231,105,223,57,238,29,126,244,65,39,57,48,193,1,30,2,162,217,209,70,121,11,121,210,182,37,142,68,193,96,6,81,72,
130,49,109,195,157,90,81,173,220,68,107,82,247,176,32,151,201,212,238,64,199,154,74,16,55,106,19,82,30,5,143,209,206,26,33,39,141,86,225,106,120,229,31,163,5,6,206,126,132,105,188,197,36,255,51,85,68,
87,105,62,103,222,10,116,18,176,223,66,110,187,144,104,31,100,164,216,173,128,216,161,179,161,194,119,210,151,184,212,228,43,0,0,0,0,0};

const char* TomCartwrightCw3AudioProcessorEditor::gothic_ttf = (const char*) resource_TomCartwrightCw3AudioProcessorEditor_gothic_ttf;
const int TomCartwrightCw3AudioProcessorEditor::gothic_ttfSize = 137568;


//[EndFile] You can add extra defines here...
//[/EndFile]

