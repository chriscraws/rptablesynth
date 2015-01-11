//
//  Controllable.cpp
//  StarterSynth
//
//  Created by Christopher Crawford on 11/4/14.
//
//

#include "Controllable.h"

Controllable::Controllable(String tag1, double min, double max, double val) : modifierBuffer()
{
    minimum = min;
    maximum = max;
    value = val;
    tag = tag;
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

String Controllable::getTag() {
    return tag;
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
double Controllable::getVal(int index)
{
    if (modifierBuffer.size() > 0) {
        return modifierBuffer[index] * maximum;
    } else {
        return value;
    }
}

// get the value of the knob
double Controllable::getBaseVal() {
    return value;
}


// ModifierBuffer is set from the envelopes. Double array <mod> serves as the buffer that
// is being inputted into the ModifierBuffer, and int <length> is the number of doubles
// read into the ModifierBuffer.
void Controllable::updateModifierBuffer(Array<double>* buff, int numSamples) {
    // no need to assure that modifierBuffer is of appropriate size because vectors
    // dynamically expand
    for (int i = 0; i < numSamples; i++) {
        modifierBuffer.set(i, buff->getUnchecked(i));
    }
    
}

// Clear the modifierBuffer instance variable of the Controllable
void Controllable::clearModifierBuffer() {
    modifierBuffer.clear();
}

