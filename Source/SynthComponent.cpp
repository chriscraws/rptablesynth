//
//  SynthComponent.cpp
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 12/27/14.
//
//

#include "SynthComponent.h"

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

void SynthComponent::setOutputBuffer(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) {
    
}

void SynthComponent::processBuffer(AudioSampleBuffer* inputBuffer, int startSample, int numSamples) {
    
}