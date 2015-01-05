//
//  SynthComponent.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 12/27/14.
//
//

#ifndef __StarterSynth__SynthComponent__
#define __StarterSynth__SynthComponent__

#include "../JuceLibraryCode/JuceHeader.h"

class SynthComponent
{
public:
    virtual ~SynthComponent();
    
    void setId(String id);
    void setSampleRate(int rate);
    int getSampleRate();

    String getId();
    
    virtual int getOutputCount();
    virtual SynthComponent getOutput(int index);
    virtual void renderNextBlock(int startSample, int numSamples);
    
private:
    String componentId;
    std::vector<double> outputBuffer;
    double sampleRate;
};



#endif /* defined(__StarterSynth__SynthComponent__) */
