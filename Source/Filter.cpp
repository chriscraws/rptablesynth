//
//  Filter.cpp
//  StarterSynth
//
//  Created by Kevin Bruccoleri on 11/7/14.
//
//

#include "Filter.h"

Filter::Filter(String tag, double min, double max, String filId):
Controllable(tag, min, max) {
    // calls the Controllable parent class with the tag, min and max
    // Envelope sets the identifier, which is some string that can be used to
    // differentiate envelopes
    filterIdentifier = filId;
    
}

String Filter::getFilterId() {
    return filterIdentifier;
}