//
//  SynthComponent.cpp
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 12/27/14.
//
//

#include "SynthComponent.h"

SynthComponent::~SynthComponent() {}

int SynthComponent::getOutputCount() {return 0;}
int SynthComponent::getInputCount() {return 0;}
AudioSampleBuffer* SynthComponent::getInputBuffer(int index) {return nullptr;}
SynthComponent* SynthComponent::getOutput(int index) {return nullptr;}
void SynthComponent::renderNextBlock(int startSample, int numSamples) {}

void SynthComponent::setId(String componentId) {
    componentId = componentId;
}

String SynthComponent::getId() {
    return componentId;
}

// This function is set up so that the SoundChain has access to change
// the SynthComponent's sample rate.
void SynthComponent::setSampleRate(int rate) {
    sampleRate = rate;
}

int SynthComponent::getSampleRate() {
    return sampleRate;
}