/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (500, 400);
    
    //ModSynth* synth = new ModSynth();
    
    MidiKeyboardComponent* keyboard = new MidiKeyboardComponent(keyboardState, MidiKeyboardComponent::horizontalKeyboard);
    
    keyboard->setBounds(8, 96, getWidth() - 16, 64);
    
    addAndMakeVisible(keyboard);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
