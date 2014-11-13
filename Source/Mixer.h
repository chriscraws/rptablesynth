//
//  Mixer.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#ifndef __StarterSynth__Mixer__
#define __StarterSynth__Mixer__

class Mixer
{
public:
    Mixer();
    
    double getVal();
    
    void setVal(double val);
    
private:
    double value;
    
};


#endif /* defined(__StarterSynth__Mixer__) */
