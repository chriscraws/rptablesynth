//
//  Envelope.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#ifndef __StarterSynth__Envelope__
#define __StarterSynth__Envelope__

class Envelope
{
public:
    Envelope();
    
    double getVal();
    
    void setVal(double val);
    
private:
    double value;
    
};


#endif /* defined(__StarterSynth__Envelope__) */
