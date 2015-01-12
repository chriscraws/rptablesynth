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
    
    Rectangle<int> desktopDimens = Desktop::getInstance().getDisplays().getMainDisplay().totalArea;
    setSize (desktopDimens.getWidth(), desktopDimens.getHeight());
    
    // initialize the MidiKeyboardComponent
    keyboard = new MidiKeyboardComponent(keyboardState, MidiKeyboardComponent::horizontalKeyboard);
    
    // define the size of the keyboard
    keyboard->setBounds(16, 50, getWidth() - 32, 64);
    
    addAndMakeVisible(keyboard);
    
    deviceManager->initialise(0, 2, 0, true);
    
    AudioDeviceManager::AudioDeviceSetup newSettings;
    deviceManager->getAudioDeviceSetup(newSettings);
    
    //newSettings.bufferSize = 4096; // larger buffer
    
    //deviceManager->setAudioDeviceSetup(newSettings, true);
    
    // connect the keyboard to the audio input
    audioSourcePlayer.setSource(&synth);
    deviceManager->addAudioCallback(&audioSourcePlayer);
    deviceManager->setMidiInputEnabled("MPK mini", true);
    deviceManager->addMidiInputCallback(String::empty, &(synth.midiCollector));
    
    // set the actual displayed text in the labels
    String filterStr1 = "Filter 1";
    String filterStr2 = "Filter 2";
    String mixerStr = "Mixer";
    String reverbStr = "Reverb";
    String delayStr = "Delay";
    String envelopeStr1 = "Envelope 1";
    String envelopeStr2 = "Envelope 2";
    String LFOStr1 = "LFO 1";
    String LFOStr2 = "LFO 2";
    
    NotificationType DontSendNotification = NotificationType(0);
    
    // set up the first row of labels and rotary encoders
    // set labels on the screen
    filterLabel1.setText(filterStr1, DontSendNotification);
    filterLabel2.setText(filterStr2, DontSendNotification);
    mixerLabel.setText(mixerStr, DontSendNotification);
    reverbLabel.setText(reverbStr, DontSendNotification);
    
    
    // sound the dimensions and placement of the labels
    filterLabel1.setBounds( 15,  125, 80, 25 );
    filterLabel2.setBounds(  140, 125, 80, 25 );
    mixerLabel.setBounds( 275, 125, 80, 25 );
    reverbLabel.setBounds(  410, 125, 80, 25 );
    
    // make the labels visible
    addAndMakeVisible(filterLabel1);
    addAndMakeVisible(filterLabel2);
    addAndMakeVisible(mixerLabel);
    addAndMakeVisible(reverbLabel);

    // now set the style of the rotary encoders
    filterSlider1.setSliderStyle(Slider::SliderStyle::Rotary);
    filterSlider2.setSliderStyle(Slider::SliderStyle::Rotary);
    mixerSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    reverbSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    
    // set the dimensions and placement of the rotary encoders
    filterSlider1.setBounds( 10,  155, 80, 50 );
    filterSlider2.setBounds(  135, 155, 80, 50 );
    mixerSlider.setBounds( 270, 155, 80, 50 );
    reverbSlider.setBounds(  405, 155, 80, 50 );
    
    // make the rotary encoders visible
    addAndMakeVisible(filterSlider1);
    addAndMakeVisible(filterSlider2);
    addAndMakeVisible(mixerSlider);
    addAndMakeVisible(reverbSlider);
    
    // start up the second row
    // set labels on the screen
    envelopeLabel1.setText(envelopeStr1, DontSendNotification);
    envelopeLabel2.setText(envelopeStr2, DontSendNotification);
    LFOLabel1.setText(LFOStr1, DontSendNotification);
    LFOLabel2.setText(LFOStr2, DontSendNotification);

    // sound the dimensions and placements of the labels
    envelopeLabel1.setBounds( 10,  205, 80, 25 );
    envelopeLabel2.setBounds(  135, 205, 80, 25 );
    LFOLabel1.setBounds(  275, 205, 80, 25 );
    LFOLabel2.setBounds(  410, 205, 80, 25 );

    // make the labels visible
    // addAndMakeVisible(envelopeLabel1);
    // addAndMakeVisible(envelopeLabel2);
    // addAndMakeVisible(LFOLabel1);
    // addAndMakeVisible(LFOLabel2);
    
    // now set the style of the rotary encoders
    envelopeSlider1.setSliderStyle(Slider::SliderStyle::Rotary);
    envelopeSlider2.setSliderStyle(Slider::SliderStyle::Rotary);
    LFOSlider1.setSliderStyle(Slider::SliderStyle::Rotary);
    LFOSlider2.setSliderStyle(Slider::SliderStyle::Rotary);

    // set the dimensions and placement of the rotary encoders
    envelopeSlider1.setBounds( 10,  205, 80, 50 );
    envelopeSlider2.setBounds(  135, 205, 80, 50 );
    LFOSlider1.setBounds(  270, 205, 80, 50 );
    LFOSlider2.setBounds(  405, 205, 80, 50 );
    
    // make the rotary encoders visible
    //addAndMakeVisible(envelopeSlider1);
    //addAndMakeVisible(envelopeSlider2);
    //addAndMakeVisible(LFOSlider1);
    //addAndMakeVisible(LFOSlider2);
    


    
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
