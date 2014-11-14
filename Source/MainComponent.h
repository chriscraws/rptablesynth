/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "ModSynth.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component
{
public:
    //==============================================================================
    MainContentComponent(AudioDeviceManager* manager);
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)

    AudioDeviceManager* deviceManager;
    AudioSourcePlayer audioSourcePlayer;
    
    // Declare the label objects
    Label filterLabel;
    Label mixerLabel;
    Label reverbLabel;
    Label delayLabel;
    Label envelopeLabel;
    
    Label rowTwoLabel1;
    Label rowTwoLabel2;
    Label rowTwoLabel3;
    
    // Declare the pieces of the keyboard
    MidiKeyboardState keyboardState;
    MidiKeyboardComponent* keyboard;
    
    ModSynth synth;
    
    // Sliders
    Slider filterSlider;
    Slider mixerSlider;
    Slider reverbSlider;
    Slider delaySlider;
    Slider envelopeSlider;
    
    Slider rowTwoSlider1;
    Slider rowTwoSlider2;
    Slider rowTwoSlider3;
};


#endif  // MAINCOMPONENT_H_INCLUDED
