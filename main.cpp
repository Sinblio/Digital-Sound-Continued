#include "wave.h"
#include "wave.cpp"
#include "soundio.h"
#include "soundio.cpp"
#include "SoundSamples.h"
#include "SoundSamples.cpp"

#include <iostream>

using namespace std;

int main() {
    int waveType;
    float sampleRate;
    float freaq;
    float duration;
    string filename;

    cin >> waveType >> sampleRate >> freaq >> duration >> filename;

    Wave* wave;

    if(waveType == 1)
        wave = new SineWave("wave");

    if(waveType == 2)
        wave = new SquareWave("wave");

    if(waveType == 3)
        wave = new SawtoothWave("wave");

    if(waveType == 4)
        wave = new TriangleWave("wave");

    SoundIO out;
    out.OutputSound(wave->generateSamples(freaq, sampleRate, duration), filename);

    return 0;
}
