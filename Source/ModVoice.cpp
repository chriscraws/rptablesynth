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

void ModVoice::startNote(int miniNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition)
{
    currentAngle = 0.0;
    level = velocity * 0.15;
    tailOff = 0.0;
    
    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(miniNoteNumber);
    double cyclesPerSample = cyclesPerSecond / getSampleRate();
    
    angleDelta = cyclesPerSample * 2.0 * double_Pi;
}

void ModVoice::stopNote(float velocity, bool allowTailOff)
{
    if (allowTailOff)
    {
        // start a tail-off by setting this flag. The render callback will pick up on
        // this and do a fade out, calling clearCurrentNote() when it's finished.
        
        if (tailOff == 0.0) // we only need to begin a tail-off if it's not already doing so - the
            // stopNote method could be called more than once.
            tailOff = 1.0;
    }
    else
    {
        // we're being told to stop playing immediately, so reset everything..
        
        clearCurrentNote();
        angleDelta = 0.0;
    }
}

void ModVoice::pitchWheelMoved(int newValue)
{
    // TODO
}

void ModVoice::controllerMoved(int controllerNumber, int newValue)
{
    // TODO
}

void ModVoice::renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (angleDelta != 0.0)
    {
        if (tailOff > 0)
        {
            while (--numSamples >= 0)
            {
                const float currentSample = (float) (sin (currentAngle) * level * tailOff);
                
                for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                    outputBuffer.addSample (i, startSample, currentSample);
                
                currentAngle += angleDelta;
                ++startSample;
                
                tailOff *= 0.99;
                
                if (tailOff <= 0.005)
                {
                    clearCurrentNote();
                    
                    angleDelta = 0.0;
                    break;
                }
            }
        }
        else
        {
            while (--numSamples >= 0)
            {
                const float currentSample = (float) (sin (currentAngle) * level);
                
                for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                    outputBuffer.addSample (i, startSample, currentSample);
                
                currentAngle += angleDelta;
                ++startSample;
            }
        }
    }
}