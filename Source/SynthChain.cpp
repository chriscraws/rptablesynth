/*
  ==============================================================================

    SynthChain.cpp
    Created: 4 Jan 2015 8:24:44pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#include "SynthChain.h"


void SynthChain::setSampleRate(int sampleRate) {
    this->sampleRate = sampleRate;
}


int SynthChain::getSampleRate() {
    return this->sampleRate;
}