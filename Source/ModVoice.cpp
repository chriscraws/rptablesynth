/*
  ==============================================================================

    ModVoice.cpp
    Created: 11 Nov 2014 10:12:33pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#include "ModVoice.h"

bool ModVoice::canPlaySound(SynthesiserSound* sound)
{
    return true;
}

void ModVoice::startNote(int midiNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition)
{
    oscillator->startNote(midiNoteNumber, velocity, nullptr, currentPitchWheelPosition);
}

void ModVoice::stopNote(float velocity, bool allowTailOff)
{
    oscillator->stopNote(velocity, allowTailOff);
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