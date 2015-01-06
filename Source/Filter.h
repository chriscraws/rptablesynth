//
//  Filter.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

/*#ifndef __StarterSynth__Filter__
#define __StarterSynth__Filter__
#include "SynthComponent.h"

class Filter : public SynthComponent
{
public:

    // handle all of the virtal functions set aside in SynthComponent
    ~Filter() override;
    int getOutputCount() override;
    SynthComponent getOutput(int index) override;
    void renderNextBlock(int startSample, int numSamples) override;
    
private:
};


#endif /* defined(__StarterSynth__Filter__) */
