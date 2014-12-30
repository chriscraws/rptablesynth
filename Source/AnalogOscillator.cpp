/*
  ==============================================================================

    AnalogOscillator.cpp
    Created: 28 Dec 2014 6:19:38pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#include "AnalogOscillator.h"

void AnalogOscillator::startNote(int miniNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition) {
    
}

void AnalogOscillator::stopNote(float velocity, bool allowTailOff) {
    
}

void AnalogOscillator::pitchWheelMoved(int newValue) {
    
}


// Incomplete
void AnalogOscillator::renderNextBlock(int startSample, int numSamples)
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