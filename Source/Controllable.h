//
//  Controllable.h
//  StarterSynth
//
//  Created by Christopher Crawford on 11/4/14.
//
//

#ifndef __StarterSynth__Controllable__
#define __StarterSynth__Controllable__

#include "../JuceLibraryCode/JuceHeader.h"

class Controllable
{
public:
    Controllable(String tag, double min, double max);
    ~Controllable();
    
    String getTag();
    
    double getMax();
    double getMin();
    double getVal();
    
    void setMax(double max);
    void setMin(double min);
    void setVal(double val);
    void setSampleRate(int rate);
    void setValueBuffer(double valueBuffer[], int numSamples);
    
private:
    double value;
    double minimum;
    double maximum;
    int sampleRate;
};

#endif /* defined(__StarterSynth__Controllable__) */
