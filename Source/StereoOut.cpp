//
//  StereoOut.cpp
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#include "StereoOut.h"

void StereoOut::setOuputBuffer(AudioSampleBuffer *outputBuffer) {
    this->outputBuffer = outputBuffer;
    inputBuffer = new AudioSampleBuffer(outputBuffer->getNumChannels(), outputBuffer->getNumSamples());
    inputBuffer->clear();
}

int StereoOut::getOutputCount() {
    return 1;
}

int StereoOut::getInputCount() {
    return 1;
}

AudioSampleBuffer* StereoOut::getInputBuffer(int index) {
    return inputBuffer;
}

SynthComponent* StereoOut::getOutput(int index) {
    return nullptr;
}

void StereoOut::renderNextBlock(int startSample, int numSamples) {
    for (int i = 0; i < outputBuffer->getNumChannels(); i++) {
        outputBuffer->copyFrom(i, startSample, *inputBuffer, i, startSample, numSamples);
    }
}