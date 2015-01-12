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

    void paint (Graphics&);
    void resized();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)

    AudioDeviceManager* deviceManager;
    AudioSourcePlayer audioSourcePlayer;
    
    // Declare the label objects
    Label filterLabel1;
    Label filterLabel2;
    Label mixerLabel;
    Label reverbLabel;
    Label envelopeLabel1;
    Label envelopeLabel2;
    Label LFOLabel1;
    Label LFOLabel2;
    
    // Declare the pieces of the keyboard
    MidiKeyboardState keyboardState;
    MidiKeyboardComponent* keyboard;
    
    ModSynth synth;
    
    // Sliders
    Slider filterSlider1;
    Slider filterSlider2;
    Slider mixerSlider;
    Slider reverbSlider;
    Slider envelopeSlider1;
    Slider envelopeSlider2;
    Slider LFOSlider1;
    Slider LFOSlider2;
};


#endif  // MAINCOMPONENT_H_INCLUDED
