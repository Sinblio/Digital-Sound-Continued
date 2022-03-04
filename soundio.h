#ifndef SOUNDIO_H
#define SOUNDIO_H

#include "SoundSamples.h"

#include <string>

using namespace std;

class SoundIO {
    public:
        void OutputSound(SoundSample * samples, string filename);
};

#endif
