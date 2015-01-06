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
    AnalogOscillator();
    
    void startNote(int miniNoteNumber, int currentPitchWheelPosition) override;
    void stop() override;
    
    void pitchWheelMoved(int newValue) override;
    
    void setOutput(SynthComponent* output);
    
    int getOutputCount() override;
    int getInputCount() override;
    SynthComponent* getOutput(int index) override;
    void renderNextBlock(int startSample, int numSamples) override;
    
    Controllable* getControllable(String tag) override;
    
private:
    double currentAngle;
    double angleDelta;
    Controllable level;
    double tailOff;
    SynthComponent* output;
    
};



#endif  // ANALOGOSCILLATOR_H_INCLUDED
