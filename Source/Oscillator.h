/*
  ==============================================================================

    Oscillator.h
    Created: 24 Nov 2014 2:02:12am
    Author:  Christopher Crawford
 
 Will be converted to an abstract class so wavetable oscillators can be
 easily implemented.

  ==============================================================================
*/

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthComponent.h"


class Oscillator : public SynthComponent {
public:
    virtual ~Oscillator();
    
    virtual void startNote(int midiNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition);
    
    virtual void stopNote(float velocity, bool allowTailOff);
    
    virtual void pitchWheelMoved(int newValue);
};


#endif  // OSCILLATOR_H_INCLUDED
