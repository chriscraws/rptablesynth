/*
  ==============================================================================

    AnalogOscillator.h
    Created: 28 Dec 2014 6:19:38pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#ifndef ANALOGOSCILLATOR_H_INCLUDED
#define ANALOGOSCILLATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

class AnalogOscillator : public Oscillator
{
public:
    
    void startNote(int miniNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition) override;
    
    void stopNote(float velocity, bool allowTailOff) override;
    
    void pitchWheelMoved(int newValue) override;
    
    void setOutput(SynthComponent* output, int index);
    
    int getOutputCount() override;
    int getInputCount() override;
    SynthComponent* getOutput(int index) override;
    void renderNextBlock(int startSample, int numSamples) override;
    
private:
    double currentAngle;
    double angleDelta;
    double level;
    double tailOff;
    SynthComponent* output;
    AudioSampleBuffer* outputBuffer;
    
};



#endif  // ANALOGOSCILLATOR_H_INCLUDED
