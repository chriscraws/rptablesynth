//
//  Envelope.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#ifndef __StarterSynth__Envelope__
#define __StarterSynth__Envelope__
#include "SynthComponent.h"

class Envelope: public SynthComponent
{
public:
    
    // as Envelope is a subclass of the Controllable superclass
    Envelope(String tag, double min, double max, String envId);
    
    String getEnvelopeId();

    
private:
    String envelopeIdentifier;
};


#endif /* defined(__StarterSynth__Envelope__) */
