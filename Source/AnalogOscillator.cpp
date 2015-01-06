/*
  ==============================================================================

    AnalogOscillator.cpp
    Created: 28 Dec 2014 6:19:38pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#include "AnalogOscillator.h"

int AnalogOscillator::getOutputCount() {
    return 1;
}

int AnalogOscillator::getInputCount() {
    return 0;
}

SynthComponent* AnalogOscillator::getOutput(int index) {
    return output;
}

void AnalogOscillator::setOutput(SynthComponent *output, int index) {
    this->output = output;
    outputBuffer = output->getInputBuffer(index);
}

void AnalogOscillator::startNote(int miniNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition) {
    currentAngle = 0.0;
    level = velocity * 0.15;
    tailOff = 0.0;
    
    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(miniNoteNumber);
    double cyclesPerSample = cyclesPerSecond / getSampleRate();
    
    angleDelta = cyclesPerSample * 2.0 * double_Pi;
}

void AnalogOscillator::stopNote(float velocity, bool allowTailOff) {
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
        angleDelta = 0.0;
    }
}

void AnalogOscillator::pitchWheelMoved(int newValue) {
    
}


void AnalogOscillator::renderNextBlock(int startSample, int numSamples)
{
    if (angleDelta != 0.0)
    {
        if (tailOff > 0)
        {
            while (--numSamples >= 0)
            {
                const float currentSample = (float) (sin (currentAngle) * level * tailOff);
                
                for (int i = outputBuffer->getNumChannels(); --i >= 0;)
                    outputBuffer->addSample (i, startSample, currentSample);
                
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
                
                for (int i = outputBuffer->getNumChannels(); --i >= 0;)
                    outputBuffer->addSample (i, startSample, currentSample);
                
                currentAngle += angleDelta;
                ++startSample;
            }
        }
    }
    
    // start next items in chain
    output->setSampleRate(getSampleRate());
    output->renderNextBlock(startSample, numSamples);
}