/*
  ==============================================================================

    SynthChain.h
    Created: 4 Jan 2015 8:24:44pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#ifndef SYNTHCHAIN_H_INCLUDED
#define SYNTHCHAIN_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class SynthChain // more on this in development rn
{
public:
    void setSampleRate(int sampleRate); // set from ModSynth
    int getSampleRate();
    
private:
    double sampleRate;
    
};



#endif  // SYNTHCHAIN_H_INCLUDED
