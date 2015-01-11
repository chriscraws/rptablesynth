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
    Controllable(String tag1, double min, double max, double value);
    
    String getTag();
    
    double getMax();
    double getMin();
    double getVal(int bufferIndex);
    double getBaseVal();
    
    void setMax(double max);
    void setMin(double min);
    void setVal(double val);
    void setSampleRate(int rate);
    void updateModifierBuffer(Array<double>* buff, int length);
    void clearModifierBuffer();

    
private:
    String tag;
    double value;
    double minimum;
    double maximum;
    double baseVal;
    Array<double> modifierBuffer;
    Array<double> valueBuffer;
    int sampleRate;
    int bufferLength;
};

#endif /* defined(__StarterSynth__Controllable__) */
