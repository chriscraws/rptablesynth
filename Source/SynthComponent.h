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
    void setSampleRate(double rate);
    double getSampleRate();

    String getId();
    
    virtual int getOutputCount();
    virtual int getInputCount();
    virtual AudioSampleBuffer* getInputBuffer(int index);
    virtual SynthComponent* getOutput(int index);
    virtual void renderNextBlock(int startSample, int numSamples);
    
private:
    String componentId;
    double sampleRate;
};



#endif /* defined(__StarterSynth__SynthComponent__) */
