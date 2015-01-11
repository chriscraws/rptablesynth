/*
  ==============================================================================

    ADSREnvelope.cpp
    Created: 8 Jan 2015 9:34:14pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#include "ADSREnvelope.h"


int ADSREnvelope::getOutputCount() {return 0;}
int ADSREnvelope::getInputCount(){return 0;}
AudioSampleBuffer* ADSREnvelope::getInputBuffer(int index){return nullptr;}
SynthComponent* ADSREnvelope::getOutput(int index) {return nullptr;}

void ADSREnvelope::set(double attack, double decay, double sustain, double release) {
    this->attack = attack;
    this->decay = decay;
    this->sustain = sustain;
    this->release = release;
}

void ADSREnvelope::renderNextBlock(int startSample, int numSamples) {
    
    buffer.resize(numSamples);
    
    for (int i = 0; i < numSamples; i++) {
        if (state == ATTACK && attack > 0) {
            buffer.set(i, angle/attack);
            if (++angle > attack) {
                angle = 0;
                state = DECAY;
            }
        } else if (state == DECAY && decay > 0) {
            buffer.set(i, 1.0 - (angle/decay)*(1.0 - sustain));
            if (++angle > decay) {
                angle = 0;
                state = SUSTAIN;
            }
        } else if (state == SUSTAIN) {
            buffer.set(i, sustain);
            angle++;
        } else if (state == RELEASE) {
            buffer.set(i, sustain * (1.0 - angle/release));
            if (++angle > release) {
                angle = 0;
                state = OFF;
            }
        } else if (state == OFF) {
            buffer.set(i, 0);
        }
    }
    
    for (int i = 0; i < controllables.size(); i++) {
        controllables[i]->updateModifierBuffer(&buffer, numSamples);
    }
}

double ADSREnvelope::secondsToSamples(double seconds) {
    return getSampleRate() * seconds;
}


Controllable* ADSREnvelope::getControllable(String tag) {
    return nullptr;
}

void ADSREnvelope::startNote(int midiNoteNumber, int currentPitchWheelPosition) {
    angle = 0;
    state = ATTACK;
    
}

void ADSREnvelope::stop() {
    state = RELEASE;
    angle = 0;
}

void ADSREnvelope::pitchWheelMoved(int newValue) {
    
}

void ADSREnvelope::addControllable(Controllable* controllable) {
    controllables.add(controllable);
}