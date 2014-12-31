//
//  Mixer.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#ifndef __StarterSynth__Mixer__
#define __StarterSynth__Mixer__
#include "Controllable.h"

class Mixer : public Controllable
{
public:
   
    Mixer(String tag, double min, double max, String mixerId);
    
    String getFilterId();
    
private:
    String mixerIdentifier;
    
};


#endif /* defined(__StarterSynth__Mixer__) */
