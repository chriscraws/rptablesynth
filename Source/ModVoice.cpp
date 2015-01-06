/*
  ==============================================================================

    ModVoice.cpp
    Created: 11 Nov 2014 10:12:33pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#include "ModVoice.h"

void ModVoice::setOscillator(Oscillator* oscillator) {
    this->oscillator = oscillator;
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
    oscillator->startNote(midiNoteNumber, currentPitchWheelPosition);
    oscillator->getControllable("level")->setVal(1.0);
}

void ModVoice::stopNote(float velocity, bool allowTailOff)
{
    oscillator->getControllable("level")->setVal(0.0);
    oscillator->stop();
    clearCurrentNote();
}

void ModVoice::pitchWheelMoved(int newValue)
{
    oscillator->pitchWheelMoved(newValue);
}

void ModVoice::controllerMoved(int controllerNumber, int newValue)
{
    // TODO
}

void ModVoice::renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    stereoOut->setOuputBuffer(&outputBuffer);
    oscillator->renderNextBlock(startSample, numSamples);
}

void ModVoice::setCurrentPlaybackSampleRate(double sampleRate) {
    SynthesiserVoice::setCurrentPlaybackSampleRate(sampleRate);
    oscillator->setSampleRate(sampleRate);
}