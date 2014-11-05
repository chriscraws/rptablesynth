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
    Controllable(double min, double max);
    ~Controllable();
    
    double getMax();
    double getMin();
    double getVal();
    
    void setMax(double max);
    void setMin(double min);
    void setVal(double val);
    
private:
    double value;
    double minimum;
    double maximum;
};

#endif /* defined(__StarterSynth__Controllable__) */
