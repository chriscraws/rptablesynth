//
//  StereoOut.h
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#ifndef __StarterSynth__StereoOut__
#define __StarterSynth__StereoOut__
#include "SynthComponent.h"

class StereoOut : public SynthComponent
{
public:
    void setOuputBuffer(AudioSampleBuffer* outputBuffer);
    
    int getOutputCount() override;
    int getInputCount() override;
    AudioSampleBuffer* getInputBuffer(int index) override;
    SynthComponent* getOutput(int index) override;
    void renderNextBlock(int startSample, int numSamples) override;
    
    
private:
    AudioSampleBuffer* outputBuffer;
    AudioSampleBuffer inputBuffer;
};


#endif /* defined(__StarterSynth__StereoOut__) */
