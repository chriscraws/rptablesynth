/*
  ==============================================================================

    ModVoice.h
    Created: 11 Nov 2014 10:12:33pm
    Author:  Christopher Crawford

  ==============================================================================
*/

#ifndef MODVOICE_H_INCLUDED
#define MODVOICE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"
#include "StereoOut.h"

class ModVoice : public SynthesiserVoice
{
public:
    void setOscillator(Oscillator* oscillator);
    void setStereoOutput(StereoOut* stereoOut);
    
    bool canPlaySound(SynthesiserSound* sound) override;
    
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition) override;
    
    void stopNote(float velocity, bool allowTailOff) override;
    
    void pitchWheelMoved(int newValue) override;
    
    void controllerMoved(int controllerNumber, int newValue) override;
    
    void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    
    void setCurrentPlaybackSampleRate(double sampleRate) override;
    
private:
    bool noteOn;
    Oscillator* oscillator;
    StereoOut* stereoOut;
};



#endif  // MODVOICE_H_INCLUDED
