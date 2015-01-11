/*
  ==============================================================================

    WavetableOscillator.cpp
    Created: 6 Jan 2015 2:06:17am
    Author:  Kevin Bruccoleri

  ==============================================================================
*/

#include "WavetableOscillator.h"

WavetableOscillator::WavetableOscillator() :    baseHz(110.0),
                                                wavetableSampleRate(44100),
                                                level("level", 0, 1, 1),
                                                position("position", 0, 127, 0),
                                                phase("phase", 0, 1, 0),
                                                wavetable(128, std::vector<float>(401))
{
    /*
    for (int i = 0; i < wavetable[0].size(); i++) {
        wavetable[0][i] = sinf(2 * float_Pi * ((float)i / wavetable[0].size()));
    }*/
    
    const int WAVEFORM_SAMPLESIZE = 401;
    //const int MAX_TOKENS_PER_LINE = 20;
    //const char* const DELIMITER = " ";
    
    File fsA(File::getCurrentWorkingDirectory().getFullPathName() + "/A.txt");
    File fsB(File::getCurrentWorkingDirectory().getFullPathName() + "/B.txt");
    AudioSampleBuffer bufferA, bufferB;
    bufferA = AudioSampleBuffer();
    bufferB = AudioSampleBuffer();
    
    // traverse the entire first file
    StringArray destLines;
    fsA.readLines(destLines);
    int i = 0;
    for (; i < destLines.strings.size(); i++) {
        wavetable[0][i] = destLines.strings[i].getFloatValue();
    }
    
    
    // make sure that up to 401 is filed, continue where <i> left off from while loop
    for (; i < WAVEFORM_SAMPLESIZE; i++) {
        wavetable[0][i] = 0.0;
    }
    
    // for traversing each float of the waveform
    int j = 0;
    int wavetable_depth = wavetable.size()-1;
    
    // traverse the entire second file
    StringArray destLines2;
    fsB.readLines(destLines2);
    
    for (; j < destLines2.strings.size(); j++) {
        wavetable[wavetable_depth][j] = destLines2.strings[j].getFloatValue();
    }
    
    // make sure that up to 401 is filed, continue where <i> left off from while loop
    for (; j < WAVEFORM_SAMPLESIZE; j++) {
        wavetable[wavetable_depth][j] = 0.0;
    }
    
    // fill in rest of wavetable
    for (int i = 1; i < wavetable.size()-1; i++) {
        double weight = (double) i / (double) wavetable[i].size();
        for (int j = 0; j < wavetable[i].size(); j++) {
            wavetable[i][j] = (1.0 - weight) * wavetable[0][j] + weight * wavetable[wavetable_depth][j];
        }
    }
    
    std::cout << "We made it";
}

int WavetableOscillator::getOutputCount() {
    return 1;
}

int WavetableOscillator::getInputCount() {
    return 0;
}

SynthComponent* WavetableOscillator::getOutput(int index) {
    return output;
}

void WavetableOscillator::setOutput(SynthComponent *output) {
    this->output = output;
}

void WavetableOscillator::startNote(int miniNoteNumber, int currentPitchWheelPosition) {
    angle = phase.getBaseVal();
    double freq = MidiMessage::getMidiNoteInHertz(miniNoteNumber);
    
    delta = getSampleRate() / wavetableSampleRate;
    delta *= freq / baseHz;
}

void WavetableOscillator::stop() {
    //delta = 0.0;
}

void WavetableOscillator::pitchWheelMoved(int newValue) {
    
}

Controllable* WavetableOscillator::getControllable(String tag) {
    if (tag.equalsIgnoreCase("level")) {
        return &level;
    } else if (tag.equalsIgnoreCase("position")) {
        return &position;
    } else if (tag.equalsIgnoreCase("phase")) {
        return &phase;
    } else {
        return nullptr;
    }
}


void WavetableOscillator::renderNextBlock(int startSample, int numSamples)
{
    if (delta != 0.0) {
        
        int n = 0;
        float last, next, sample;
        int lastIndex, nextIndex;
        
        // Lanczos variables
        int a = 3; // variable between 1 and 3, higher value = more smooth sinc curve
        float sum, lanczosKernel;
        
        while (n < numSamples) {
            
            while (angle >= wavetable[0].size()) {
                angle -= wavetable[0].size();
            }
            
            // get last sample in wavetable
            lastIndex = (int) angle;
            last = wavetable[(int)position.getVal(n)][lastIndex];
            
            nextIndex = ceil(angle + delta);
            while (nextIndex >= wavetable[0].size()) {
                nextIndex -= wavetable[0].size();
            }
            next = wavetable[(int) position.getVal(n)][nextIndex];
            
            // Lanczos resampling
            // convolution of wavetable with Lanvzos kernel
            sum = 0;
            for (int i = angle - a + 1; i <= angle + a; i++) {
                int actual = i;
                if (actual >= wavetable[0].size()) {
                    actual = (wavetable[0].size() - 1) % actual;
                }
                if (actual < 0) {
                    actual += wavetable[0].size();
                }
                
                // lanczos kernel
                float lanczosArg = angle - i;
                if (lanczosArg == 0) {
                    lanczosKernel = 1;
                } else if (0 < fabsf(lanczosArg) && fabsf(lanczosArg) < a) {
                    lanczosKernel = (a * sinf(float_Pi * lanczosArg) * sinf(float_Pi * lanczosArg / a)) / (float_Pi * float_Pi * lanczosArg * lanczosArg);
                } else {
                    lanczosKernel = 0;
                }
                
                sum += wavetable[(int)position.getVal(n)][actual] * lanczosKernel;
            }
            
            sample = sum;
            
            
            sample *= level.getVal(n);
            
            for (int i = (output->getInputBuffer(0))->getNumChannels(); --i >= 0;) {
                (output->getInputBuffer(0))->setSample (i, n + startSample, sample);
            }
            
            angle += delta;
            n++;
        }
        
        // start next items in chain
        output->setSampleRate(getSampleRate());
        output->renderNextBlock(startSample, numSamples);
    }
}




