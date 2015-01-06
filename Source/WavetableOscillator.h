/*
  ==============================================================================

    WavetableOscillator.h
    Created: 6 Jan 2015 2:06:17am
    Author:  Kevin Bruccoleri

  ==============================================================================
*/

#ifndef WAVETABLEOSCILLATOR_H_INCLUDED
#define WAVETABLEOSCILLATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"
#include <vector>

class WavetableOscillator : public Oscillator
{
public:
    WavetableOscillator();
    
    void startNote(int miniNoteNumber, int currentPitchWheelPosition) override;
    virtual void stop() override;
    
    void pitchWheelMoved(int newValue) override;
    
    void setOutput(SynthComponent* output);
    
    int getOutputCount() override;
    int getInputCount() override;
    SynthComponent* getOutput(int index) override;
    void renderNextBlock(int startSample, int numSamples) override;
    
    Controllable* getControllable(String tag) override;
    
private:
    double baseHz;
    double wavetableSampleRate;
    double tailOff;
    Controllable level;
    Controllable position;
    
    SynthComponent* output;
    
    std::vector<std::vector<float>> wavetable;
};


#endif  // WAVETABLEOSCILLATOR_H_INCLUDED
