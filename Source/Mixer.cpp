//
//  Mixer.cpp
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#include "Mixer.h"

Mixer::Mixer()
{
    value = 0;
}

void Mixer::setVal(double val) {
    value = val;
}

double Mixer::getVal()
{
    return value;
}