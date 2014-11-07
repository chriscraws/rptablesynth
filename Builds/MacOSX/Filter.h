//
//  Filter.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#ifndef __StarterSynth__Filter__
#define __StarterSynth__Filter__

class Filter
{
public:
    Filter();
    
    double getVal();
    
    void setVal(double val);
    
private:
    double value;

};


#endif /* defined(__StarterSynth__Filter__) */
