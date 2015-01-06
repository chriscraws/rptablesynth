/*
  ==============================================================================

    WavetableOscillator.cpp
    Created: 6 Jan 2015 2:06:17am
    Author:  Kevin Bruccoleri

  ==============================================================================
*/

#include "WavetableOscillator.h"

WavetableOscillator::WavetableOscillator() : level("level", 0, 1, 1) {}

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
    currentAngle = 0.0;
    
    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(miniNoteNumber);
    double cyclesPerSample = cyclesPerSecond / getSampleRate();
    
    angleDelta = cyclesPerSample * 2.0 * double_Pi;
}

void WavetableOscillator::stop() {
    angleDelta = 0;
}

void WavetableOscillator::pitchWheelMoved(int newValue) {
    
}

Controllable* WavetableOscillator::getControllable(String tag) {
    if (tag.equalsIgnoreCase("level")) {
        return &level;
    } else {
        return nullptr;
    }
}


void WavetableOscillator::renderNextBlock(int startSample, int numSamples)
{
    if (angleDelta != 0.0)
    {
        int s = 0;
        while (s < numSamples) {
            const float currentSample = (float) (sin (currentAngle) * level.getBaseVal());
            
            for (int i = (output->getInputBuffer(0))->getNumChannels(); --i >= 0;) {
                (output->getInputBuffer(0))->setSample (i, s + startSample, currentSample);
            }
            
            currentAngle += angleDelta;
            s++;
        }
        // start next items in chain
        output->setSampleRate(getSampleRate());
        output->renderNextBlock(startSample, numSamples);
    }
    
    
}