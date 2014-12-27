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
    
    void setId(String id);
    void setOutputBuffer(AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
    void setSampleRate(int rate);

    String getId();
    
    void processBuffer(AudioSampleBuffer* inputBuffer, int startSample, int numSamples);
    
private:
    String componentId;
    std::vector<double> outputBuffer;
    double sampleRate;
};



#endif /* defined(__StarterSynth__SynthComponent__) */
