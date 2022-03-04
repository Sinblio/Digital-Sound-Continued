#include "wave.h"
#include "SoundSamples.h"

#include <math.h>
#include <iostream>

using namespace std;

SoundSample* Wave::generateSamples(float freaquency, float sampleRate, float duration) {
    int numSamples = sampleRate * duration;
    float* samples = (float*) malloc(sizeof(float) * numSamples);
    for (int i = 0; i < numSamples; i++) {
        samples[i] = generateFunction(i * freaquency / sampleRate);
    }
    return new SoundSample(samples, numSamples, sampleRate);
}

string Wave::getName() {
    return this->name;
}

float SineWave::generateFunction(float time) {
    return sin(2 * M_PI * time);
}

float SquareWave::generateFunction(float time){
    float t = time - (int) time;
    if (t < 0.5)
        return -1.0;
    else
        return 1.0;
}

float TriangleWave::generateFunction(float time) {
    float t = time - (int) time;
    if (t < 0.5)
        return 4 * t -1;
    else
        return -4 * t + 3;
}

float SawtoothWave::generateFunction(float time){
    float t = time - (int)time;
    return 2 * t - 1;
}
