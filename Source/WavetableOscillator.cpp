/*
  ==============================================================================

    WavetableOscillator.cpp
    Created: 6 Jan 2015 2:06:17am
    Author:  Kevin Bruccoleri

  ==============================================================================
*/

#include "WavetableOscillator.h"

WavetableOscillator::WavetableOscillator() :
        baseHz(110.0),
        wavetableSampleRate(44100),
        level("level", 0, 1, 1),
        position("position", 0, 127, 0),
        wavetable(128, std::vector<float>(401))
{
    
    const int MAX_CHARS_PER_LINE = 512;
    //const int MAX_TOKENS_PER_LINE = 20;
    //const char* const DELIMITER = " ";
                                                    
    std::ifstream fsA;
    std::ifstream fsB;
    fsA.open("A.txt");
    fsB.open("B.txt");
    AudioSampleBuffer bufferA;
    bufferA = AudioSampleBuffer();
    AudioSampleBuffer bufferB;
    bufferB = AudioSampleBuffer();
    
    // traverse the entire first file
    while (!fsA.eof()) {
        
        // read an entire line into memory
        char buf[MAX_CHARS_PER_LINE];
        fsA.getline(buf, MAX_CHARS_PER_LINE);
        
        String lineString = String(buf);
        lineString.getFloatValue();
    
    }
    
    // traverse the entire second file
    while (!fsB.eof()) {

        // read an entire line into memory
        char buf[MAX_CHARS_PER_LINE];
        fsB.getline(buf, MAX_CHARS_PER_LINE);

        String lineString = String(buf);
        lineString.getFloatValue();

    }

    fsA.close();
    fsB.close();
    
}

int WavetableOscillator::getOutputCount() {
    return 1;
}

int WavetableOscillator::getInputCount() {
    return 0;
}

SynthComponent* WavetableOscillator::getOutput(int index) {
    return output;
}

void WavetableOscillator::setOutput(SynthComponent *output) {
    this->output = output;
}

void WavetableOscillator::startNote(int miniNoteNumber, int currentPitchWheelPosition) {
    
}

void WavetableOscillator::stop() {
    
}

void WavetableOscillator::pitchWheelMoved(int newValue) {
    
}

Controllable* WavetableOscillator::getControllable(String tag) {
    if (tag.equalsIgnoreCase("level")) {
        return &level;
    } else if (tag.equalsIgnoreCase("position")) {
        return &position;
    } else{
        return nullptr;
    }
}


void WavetableOscillator::renderNextBlock(int startSample, int numSamples)
{
    
    
}