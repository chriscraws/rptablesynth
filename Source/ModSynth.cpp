//
//  ModSynth.cpp
//  StarterSynth
//
//  Created by Christopher Crawford on 11/5/14.
//
//

#include "ModSynth.h"
#include "AnalogOscillator.h"
#include "ADSREnvelope.h"

struct DefaultSound : public SynthesiserSound
{
    DefaultSound() {}
    
    bool appliesToNote (int /*midiNoteNumber*/) override    { return true; }
    bool appliesToChannel (int /*midiChannel*/) override    { return true; }
};

ModSynth::ModSynth(MidiKeyboardState& state) : keyboardState(state)
{
    // Construct chain
    //WavetableOscillator* oscillator = new WavetableOscillator();
    AnalogOscillator* oscillator = new AnalogOscillator();
    ADSREnvelope* env1 = new ADSREnvelope();
    env1->set(200, 30000, 0, 200);
    StereoOut* stereoOut = new StereoOut();
    ModVoice* mainVoice = new ModVoice();
    
    mainVoice->addOscillator(oscillator);
    mainVoice->addOscillator(env1);
    env1->addControllable(oscillator->getControllable("level"));
    //env1->addControllable(oscillator->getControllable("position"));
    mainVoice->setStereoOutput(stereoOut);
    
    oscillator->setOutput(stereoOut);
    
    
    // add voices
    synth.addVoice(mainVoice);
    
    synth.addSound(new DefaultSound());
}

void ModSynth::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    midiCollector.reset(sampleRate);
    synth.setCurrentPlaybackSampleRate(sampleRate);
}

void ModSynth::releaseResources(){}

void ModSynth::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
    // the synth always adds its output to the audio buffer, so we have to clear it
    // first..
    bufferToFill.clearActiveBufferRegion();
    
    // fill a midi buffer with incoming messages from the midi input.
    MidiBuffer incomingMidi;
    midiCollector.removeNextBlockOfMessages (incomingMidi, bufferToFill.numSamples);
    
    // pass these messages to the keyboard state so that it can update the component
    // to show on-screen which keys are being pressed on the physical midi keyboard.
    // This call will also add midi messages to the buffer which were generated by
    // the mouse-clicking on the on-screen keyboard.
    keyboardState.processNextMidiBuffer (incomingMidi, 0, bufferToFill.numSamples, true);
    
    // and now get the synth to process the midi events and generate its output.
    synth.renderNextBlock (*bufferToFill.buffer, incomingMidi, 0, bufferToFill.numSamples);
}