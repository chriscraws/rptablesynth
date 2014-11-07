//
//  Oscillator.cpp
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#include "Oscillator.h"

Oscillator::Oscillator()
{
    value = 0;
}

void Oscillator::setVal(double val) {
    value = val;
}

double Oscillator::getVal()
{
    return value;
}