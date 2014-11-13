//
//  ModSynth.h
//  StarterSynth
//
//  Created by Christopher Crawford on 11/5/14.
//
//

#ifndef __StarterSynth__ModSynth__
#define __StarterSynth__ModSynth__

#include "../JuceLibraryCode/JuceHeader.h"
#include "ModVoice.h"

class ModSynth : public AudioSource
{
public:
    ModSynth(MidiKeyboardState& keyState);
    
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    
    void releaseResources() override;
    
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
    
    MidiMessageCollector midiCollector;
    
private:
    Synthesiser synth;
    MidiKeyboardState& keyboardState;
    
};

#endif /* defined(__StarterSynth__ModSynth__) */
