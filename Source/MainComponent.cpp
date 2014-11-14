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
    
    // set the actual displayed text in the labels
    String filterStr = "Filter";
    String mixerStr = "Mixer";
    String reverbStr = "Reverb";
    String delayStr = "Delay";
    String envelopeStr = "Envelope";
    String labelStr = "Label";
    
    NotificationType DontSendNotification = NotificationType(0);
    
    // set up the first row of labels and rotary encoders
    // set labels on the screen
    filterLabel.setText(filterStr, DontSendNotification);
    mixerLabel.setText(mixerStr, DontSendNotification);
    reverbLabel.setText(reverbStr, DontSendNotification);
    delayLabel.setText(delayStr, DontSendNotification);
    
    
    // sound the dimensions and placement of the labels
    filterLabel.setBounds( 15,  85, 80, 25 );
    mixerLabel.setBounds(  140, 85, 80, 25 );
    reverbLabel.setBounds( 275, 85, 80, 25 );
    delayLabel.setBounds(  410, 85, 80, 25 );
    
    // make the labels visible
    addAndMakeVisible(filterLabel);
    addAndMakeVisible(mixerLabel);
    addAndMakeVisible(reverbLabel);
    addAndMakeVisible(delayLabel);
    
    // now set the style of the rotary encoders
    filterSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    mixerSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    reverbSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    delaySlider.setSliderStyle(Slider::SliderStyle::Rotary);
    
    // set the dimensions and placement of the rotary encoders
    filterSlider.setBounds( 10,  115, 80, 50 );
    mixerSlider.setBounds(  135, 115, 80, 50 );
    reverbSlider.setBounds( 270, 115, 80, 50 );
    delaySlider.setBounds(  405, 115, 80, 50 );
    
    // make the rotary encoders visible
    addAndMakeVisible(filterSlider);
    addAndMakeVisible(mixerSlider);
    addAndMakeVisible(reverbSlider);
    addAndMakeVisible(delaySlider);
    
    // start up the second row
    // set labels on the screen
    envelopeLabel.setText(envelopeStr, DontSendNotification);
    rowTwoLabel1.setText(labelStr, DontSendNotification);
    rowTwoLabel2.setText(labelStr, DontSendNotification);
    rowTwoLabel3.setText(labelStr, DontSendNotification);

    // sound the dimensions and placements of the labels
    envelopeLabel.setBounds( 15,  175, 80, 25);
    rowTwoLabel1.setBounds(  140, 175, 80, 25);
    rowTwoLabel2.setBounds(  275, 175, 80, 25);
    rowTwoLabel3.setBounds(  410, 175, 80, 25);

    // make the labels visible
    addAndMakeVisible(envelopeLabel);
    addAndMakeVisible(rowTwoLabel1);
    addAndMakeVisible(rowTwoLabel2);
    addAndMakeVisible(rowTwoLabel3);
    
    // now set the style of the rotary encoders
    envelopeSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    rowTwoSlider1.setSliderStyle(Slider::SliderStyle::Rotary);
    rowTwoSlider2.setSliderStyle(Slider::SliderStyle::Rotary);
    rowTwoSlider3.setSliderStyle(Slider::SliderStyle::Rotary);

    // set the dimensions and placement of the rotary encoders
    envelopeSlider.setBounds( 10,  205, 80, 50);
    rowTwoSlider1.setBounds(    135, 205, 80, 50 );
    rowTwoSlider2.setBounds(   270, 205, 80, 50 );
    rowTwoSlider3.setBounds(    405, 205, 80, 50 );
    
    // make the rotary encoders visible
    addAndMakeVisible(envelopeSlider);
    addAndMakeVisible(rowTwoSlider1);
    addAndMakeVisible(rowTwoSlider2);
    addAndMakeVisible(rowTwoSlider3);


    
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
