//
//  Filter.cpp
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#include "Filter.h"

Filter::Filter()
{
    value = 0;
}

void Filter::setVal(double val) {
    value = val;
}

double Filter::getVal()
{
    return value;
}