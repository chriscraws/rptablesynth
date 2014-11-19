//
//  Envelope.cpp
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#include "Envelope.h"

Envelope::Envelope()
{
    value = 0;
}

void Envelope::setVal(double val) {
    value = val;
}

double Envelope::getVal()
{
    return value;
}