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

class ModVoice : public SynthesiserVoice
{
public:
    bool canPlaySound(SynthesiserSound* sound) override;
    
    void startNote(int miniNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition) override;
    
    void stopNote(float velocity, bool allowTailOff) override;
    
    void pitchWheelMoved(int newValue) override;
    
    void controllerMoved(int controllerNumber, int newValue) override;
    
    void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    
private:
    double currentAngle;
    double angleDelta;
    double level;
    double tailOff;
};



#endif  // MODVOICE_H_INCLUDED
