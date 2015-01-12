/*
  ==============================================================================

    AnalogOscillator.cpp
    Created: 28 Dec 2014 6:19:38pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#include "AnalogOscillator.h"

AnalogOscillator::AnalogOscillator() : level("level", 0, 1, 1) {}

int AnalogOscillator::getOutputCount() {
    return 1;
}

int AnalogOscillator::getInputCount() {
    return 0;
}

SynthComponent* AnalogOscillator::getOutput(int index) {
    return output;
}

void AnalogOscillator::setOutput(SynthComponent *output) {
    this->output = output;
}

void AnalogOscillator::startNote(int miniNoteNumber, int currentPitchWheelPosition) {
    currentAngle = 0.0;
    
    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(miniNoteNumber);
    double cyclesPerSample = cyclesPerSecond / getSampleRate();
    
    angleDelta = cyclesPerSample * 2.0 * double_Pi;
}

void AnalogOscillator::stop() {
    angleDelta = 0;
}

void AnalogOscillator::pitchWheelMoved(int newValue) {
    
}

Controllable* AnalogOscillator::getControllable(String tag) {
    if (tag.equalsIgnoreCase("level")) {
        return &level;
    } else {
        return nullptr;
    }
}


void AnalogOscillator::renderNextBlock(int startSample, int numSamples)
{
    if (angleDelta != 0.0)
    {
        int s = 0;
        while (s < numSamples) {
            const float currentSample = (float) (sin (currentAngle) * level.getVal(s));
            
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