/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent(AudioDeviceManager* manager)
    :   deviceManager(manager),
        synth(keyboardState)
{
    setSize (500, 400);
    
    // initialize the MidiKeyboardComponent
    keyboard = new MidiKeyboardComponent(keyboardState, MidiKeyboardComponent::horizontalKeyboard);
    
    // define the size of the keyboard
    keyboard->setBounds(8, 96, getWidth() - 16, 64);
    
    addAndMakeVisible(keyboard);
    
    deviceManager->initialise(0, 2, 0, true);
    
    // connect the keyboard to the audio input
    audioSourcePlayer.setSource(&synth);
    deviceManager->addAudioCallback(&audioSourcePlayer);
    deviceManager->addMidiInputCallback(String::empty, &(synth.midiCollector));
    
    // set the component title strings
    String filterCompStr = "filterLabel";
    String mixerCompStr = "mixerLabel";
    String reverbCompStr = "reverbLabel";
    String delayCompStr = "delayLabel";
    String envelopeCompStr = "envelopeLabel";

    // set the actual displayed text in the labels
    String filterStr = "Filter";
    String mixerStr = "Mixer";
    String reverbStr = "Reverb";
    String delayStr = "Delay";
    String envelopeStr = "Envelope";
    
    NotificationType DontSendNotification = NotificationType(0);
    
    // set labels on the screen
    filterLabel.setText(filterStr, DontSendNotification);
    mixerLabel.setText(mixerStr, DontSendNotification);
    reverbLabel.setText(reverbStr, DontSendNotification);
    delayLabel.setText(delayStr, DontSendNotification);
    envelopeLabel.setText(envelopeStr, DontSendNotification);
    
    addAndMakeVisible(filterLabel);
    addAndMakeVisible(mixerLabel);
    addAndMakeVisible(reverbLabel);
    addAndMakeVisible(delayLabel);
    addAndMakeVisible(envelopeLabel);

    
}

MainContentComponent::~MainContentComponent()
{
    deleteAllChildren();
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
