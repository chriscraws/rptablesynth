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
                                                    
    File fsA("A.txt");
    File fsB("B.txt");
    AudioSampleBuffer bufferA, bufferB;
    bufferA = AudioSampleBuffer();
    bufferB = AudioSampleBuffer();
    
    // traverse the entire first file
    StringArray destLines;
    fsA.readLines(destLines);
    int i = 0;
    for (; i < destLines.strings.size(); i++) {
        wavetable[0][i] = destLines.strings[i].getFloatValue();
    }
    
    
    // make sure that up to 401 is filed, continue where <i> left off from while loop
    for (; i < WAVEFORM_SAMPLESIZE; i++) {
        wavetable[0][i] = 0.0;
    }
    
    // for traversing each float of the waveform
    int j = 0;
    int wavetable_depth = wavetable.size()-1;
    
    // traverse the entire second file
    StringArray destLines2;
    fsA.readLines(destLines2);
    
    for (; j < destLines2.strings.size(); j++) {
        wavetable[wavetable_depth][j] = destLines2.strings[j].getFloatValue();
    }
    
    // make sure that up to 401 is filed, continue where <i> left off from while loop
    for (; j < WAVEFORM_SAMPLESIZE; j++) {
        wavetable[wavetable_depth][j] = 0.0;
    }
    
    std::cout << "We made it";
    
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