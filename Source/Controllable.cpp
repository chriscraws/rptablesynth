//
//  Controllable.cpp
//  StarterSynth
//
//  Created by Christopher Crawford on 11/4/14.
//
//

#include "Controllable.h"

Controllable::Controllable(String, double min, double max)
{
    minimum = min;
    maximum = max;
    value = 0;
}

Controllable::~Controllable()
{
    // delete the vectors upon deconstruction
    // the lines underneath instantiate blank vectors and swap them with
    // both valueBuffer and modifierBuffer, effectively freeing their memory.
    std::vector<double>().swap(valueBuffer);
    std::vector<double>().swap(modifierBuffer);

}

// Controllable setters
void Controllable::setMax(double max) {
    maximum = max;
}

void Controllable::setMin(double min)
{
    minimum = min;
}

void Controllable::setVal(double val) {
    if (val > maximum) {
        val = maximum;
    } else if (val < minimum) {
        val = minimum;
    } else {
        value = val;
    }
}
// The Sample Rate of the controllable is set from the SoundChain
void Controllable::setSampleRate(int rate) {
    sampleRate = rate;
}

// set the valueBuffer instance variable of the Controllable class by copying
// over <numSamples> entries in the <valueBuffer> argument passed through the function.
void Controllable::setValueBuffer(double buff[], int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        
        // for each value, ensure that each double in buff is between -1 and 1
        if (buff[i] < -1) {
            buff[i] = -1;
        }
        else if (buff[i] > 1) {
            buff[i] = 1;
        }
        
        valueBuffer[i] = buff[i];
    }
}


// Keep track of the buffer's length
void Controllable::setBufferLength(int length) {
    bufferLength = length;
}


// Controllable getters
double Controllable::getMax()
{
    return maximum;
}

double Controllable::getMin()
{
    return minimum;
}

// get the non-base value of the Controllable
double Controllable::getVal(int BufferIndex)
{
    return value;
}

// get the value of the knob
double Controllable::getBaseVal() {
    return baseVal;
}


// ModifierBuffer is set from the envelopes. Double array <mod> serves as the buffer that
// is being inputted into the ModifierBuffer, and int <length> is the number of doubles
// read into the ModifierBuffer.
void Controllable::updateModifierBuffer(double mod[], int length) {
    // no need to assure that modifierBuffer is of appropriate size because vectors
    // dynamically expand
    for (int i = 0; i < length; i++) {
        modifierBuffer[i] = mod[i];
    }
    
}

// Clear the modifierBuffer instance variable of the Controllable
void Controllable::clearModifierBuffer() {
    modifierBuffer.clear();
}

