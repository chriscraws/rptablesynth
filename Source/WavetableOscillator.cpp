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
    const int WAVEFORM_SAMPLESIZE = 401;
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
    
    // for traversing each float of the first waveform
    int i = 0;
    // traverse the entire first file
    while (!fsA.eof()) {
        
        // read an entire line into memory
        char buf[MAX_CHARS_PER_LINE];
        fsA.getline(buf, MAX_CHARS_PER_LINE);
        
        String lineString = String(buf);
        wavetable[0][i++] = lineString.getFloatValue();
        
    }
    
    // make sure that up to 401 is filed, continue where <i> left off from while loop
    for (; i < WAVEFORM_SAMPLESIZE; i++) {
        wavetable[0][i] = 0.0;
    }
    
    // for traversing each float of the waveform
    int j = 0;
    int wavetable_depth = wavetable.size();
    // traverse the entire second file
    while (!fsB.eof()) {

        // read an entire line into memory
        char buf[MAX_CHARS_PER_LINE];
        fsB.getline(buf, MAX_CHARS_PER_LINE);

        String lineString = String(buf);
        wavetable[wavetable_depth][j++] = lineString.getFloatValue();

    }
    
    // make sure that up to 401 is filed, continue where <i> left off from while loop
    for (; j < WAVEFORM_SAMPLESIZE; j++) {
        wavetable[wavetable_depth][j] = 0.0;
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