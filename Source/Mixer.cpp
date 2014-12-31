//
//  Mixer.cpp
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#include "Mixer.h"

Mixer::Mixer(String tag, double min, double max, String mixerId):
Controllable(tag, min, max) {
    // calls the Controllable parent class with the tag, min and max
    // Envelope sets the identifier, which is some string that can be used to
    // differentiate envelopes
    mixerIdentifier = mixerId;
    
}

String Mixer::getFilterId() {
    return mixerIdentifier;
}