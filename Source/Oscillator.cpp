/*
  ==============================================================================

    Oscillator.cpp
    Created: 5 Jan 2015 9:06:50pm
    Author:  Kevin Bruccoleri

  ==============================================================================
*/

#include "Oscillator.h"

// While the class is intended as an interface, or a base class for both the
// Analog and Wavetable Oscillator classes, there must be some basic default
// for the virtual functions

Oscillator::~Oscillator() {}

void Oscillator::startNote(int miniNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition) {}

void Oscillator::stopNote(float velocity, bool allowTailOff) {}

void Oscillator::pitchWheelMoved(int newValue) {}