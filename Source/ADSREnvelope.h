/*
  ==============================================================================

    ADSREnvelope.h
    Created: 8 Jan 2015 9:34:14pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#ifndef ADSRENVELOPE_H_INCLUDED
#define ADSRENVELOPE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

enum env_state {ATTACK, DECAY, SUSTAIN, RELEASE, OFF};

class ADSREnvelope : public Oscillator
{
public:
    void set(double attack, double decay, double sustain, double release);
    
    void addControllable(Controllable* controllable);
    
    // SynthComponent
    int getOutputCount() override;
    int getInputCount() override;
    AudioSampleBuffer* getInputBuffer(int index) override;
    SynthComponent* getOutput(int index) override;
    void renderNextBlock(int startSample, int numSamples) override;
    Controllable* getControllable(String tag) override;
    
    // Oscillator
    void startNote(int midiNoteNumber, int currentPitchWheelPosition) override;
    void stop() override;
    void pitchWheelMoved(int newValue) override;
    
private:
    Array<Controllable*> controllables;
    double attack;
    double sustain;
    double release;
    double decay;
    
    int angle;
    
    double secondsToSamples(double seconds);
    
    Array<double> buffer;
    
    enum env_state state;
};


#endif  // ADSRENVELOPE_H_INCLUDED
