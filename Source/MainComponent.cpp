/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#include "MainComponent.h"
#include <iostream>


//==============================================================================
MainContentComponent::MainContentComponent(AudioDeviceManager* manager)
:   deviceManager(manager),
synth(keyboardState)
{
    setSize (500, 400);
    
    // initialize the MidiKeyboardComponent
    keyboard = new MidiKeyboardComponent(keyboardState, MidiKeyboardComponent::horizontalKeyboard);
    
    // define the size of the keyboard
    keyboard->setBounds(8, 10, getWidth() - 16, 64);
    
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
    
    // sound the dimensions and placement of the labels
    filterLabel.setBounds(15, 85, 50, 25);
    mixerLabel.setBounds(100, 85, 50, 25);
    reverbLabel.setBounds(195, 85, 50, 25);
    delayLabel.setBounds(280, 85, 50, 25);
    envelopeLabel.setBounds(365, 85, 50, 35);
    
    // make the labels visible
    addAndMakeVisible(filterLabel);
    addAndMakeVisible(mixerLabel);
    addAndMakeVisible(reverbLabel);
    addAndMakeVisible(delayLabel);
    addAndMakeVisible(envelopeLabel);
    
    // now set the style of the rotary encoders
    filterSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    mixerSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    reverbSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    delaySlider.setSliderStyle(Slider::SliderStyle::Rotary);
    envelopeSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    
    // set the dimensions and placement of the rotary encoders
    filterSlider.setBounds(15, 115, 50, 50);
    mixerSlider.setBounds(100, 115, 50, 50);
    reverbSlider.setBounds(195, 115, 50, 50);
    delayLabel.setBounds(280, 115, 50, 50);
    envelopeLabel.setBounds(365, 85, 50, 50);
    
    // make the rotary encoders visible
    addAndMakeVisible(filterSlider);
    addAndMakeVisible(mixerSlider);
    addAndMakeVisible(reverbSlider);
    addAndMakeVisible(delaySlider);
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
