//
//  Oscillator.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#ifndef __StarterSynth__Oscillator__
#define __StarterSynth__Oscillator__

#include "../JuceLibraryCode/JuceHeader.h"

class Oscillator
{
public:
    Oscillator();
    
    double getVal();

    void setVal(double val);
    
private:
    double value;

};


#endif /* defined(__StarterSynth__Oscillator__) */
