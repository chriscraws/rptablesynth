//
//  Mixer.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#ifndef __StarterSynth__Mixer__
#define __StarterSynth__Mixer__
#include "SynthComponent.h"

class Mixer : public SynthComponent
{
public:
   
    Mixer(String tag, double min, double max, String mixerId);
    
    String getFilterId();
    
private:
    String mixerIdentifier;
    
};


#endif /* defined(__StarterSynth__Mixer__) */
