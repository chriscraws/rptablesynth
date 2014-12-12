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
}

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

double Controllable::getMax()
{
    return maximum;
}

double Controllable::getMin()
{
    return minimum;
}

double Controllable::getVal()
{
    return value;
}