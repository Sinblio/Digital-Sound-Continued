#ifndef WAVE_H
#define WAVE_H

#include "SoundSamples.h"

#include <string>

using namespace std;

class Wave {
    public:
        Wave(string name) { this->name = name; };
        SoundSample *generateSamples(float freaquency, float sampleRate, float duration);
        virtual float generateFunction(float time)=0;
        string getName();
    private:
        string name;

};

class SineWave : public Wave {
    public:
        SineWave(string name) : Wave(name){};
        float generateFunction(float time);
};

class SquareWave : public Wave {
    public:
        SquareWave(string name) : Wave(name){};
        float generateFunction(float time);
};

class TriangleWave : public Wave {
    public:
        TriangleWave(string name) : Wave(name){};
        float generateFunction(float time);
};

class SawtoothWave : public Wave {
    public:
        SawtoothWave(string name) : Wave(name){};
        float generateFunction(float time);
};

#endif
