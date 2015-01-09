/*
  ==============================================================================

    ModVoice.cpp
    Created: 11 Nov 2014 10:12:33pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#include "ModVoice.h"


void ModVoice::addOscillator(Oscillator* oscillator) {
    this->oscillators.add(oscillator);
}

void ModVoice::setStereoOutput(StereoOut* stereoOut) {
    this->stereoOut = stereoOut;
}

bool ModVoice::canPlaySound(SynthesiserSound* sound)
{
    return true;
}

void ModVoice::startNote(int midiNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition)
{
    for (int i = 0; i < oscillators.size(); i++) {
        oscillators[i]->startNote(midiNoteNumber, currentPitchWheelPosition);
    }
}

void ModVoice::stopNote(float velocity, bool allowTailOff)
{
    for (int i = 0; i < oscillators.size(); i++) {
        oscillators[i]->stop();
    }
    clearCurrentNote();
}

void ModVoice::pitchWheelMoved(int newValue)
{
    //oscillator->pitchWheelMoved(newValue);
}

void ModVoice::controllerMoved(int controllerNumber, int newValue)
{
    // TODO
}

void ModVoice::renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    stereoOut->setOuputBuffer(&outputBuffer);
    for (int i = 0; i < oscillators.size(); i++) {
        oscillators[i]->renderNextBlock(startSample, numSamples);
    }
}

void ModVoice::setCurrentPlaybackSampleRate(double sampleRate) {
    SynthesiserVoice::setCurrentPlaybackSampleRate(sampleRate);
    for (int i = 0; i < oscillators.size(); i++) {
        oscillators[i]->setSampleRate(sampleRate);
    }
}