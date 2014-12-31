//
//  Envelope.cpp
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#include "Envelope.h"

Envelope::Envelope(String tag, double min, double max, String envId):
Controllable(tag, min, max) {
    // calls the Controllable parent class with the tag, min and max
    // Envelope sets the identifier, which is some string that can be used to
    // differentiate envelopes
    envelopeIdentifier = envId;

}

String Envelope::getEnvelopeId() {
    return envelopeIdentifier;
}


