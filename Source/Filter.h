//
//  Filter.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#ifndef __StarterSynth__Filter__
#define __StarterSynth__Filter__
#include "SynthComponent.h"

class Filter : public SynthComponent
{
public:
    
    Filter(String tag, double min, double max, String filId);
    
    String getFilterId();
    
private:
    String filterIdentifier;

};


#endif /* defined(__StarterSynth__Filter__) */
