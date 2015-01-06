//
//  Envelope.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

/*#ifndef __StarterSynth__Envelope__
#define __StarterSynth__Envelope__
#include "SynthComponent.h"

class Envelope: public SynthComponent
{
public:
    
    // handle all of the virtal functions set aside in SynthComponent
    ~Envelope() override;
    int getOutputCount() override;
    SynthComponent getOutput(int index) override;
    void renderNextBlock(int startSample, int numSamples) override;
    
private:
};


#endif /* defined(__StarterSynth__Envelope__) */

