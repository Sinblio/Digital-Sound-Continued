#include "SoundSamples.h"

#include <iostream>

using namespace std;

SoundSample::SoundSample() {
    this->sampleRate = 8000;
    this->samples.resize(0);
    this->numSamples = 0;
}

SoundSample::SoundSample(float * samples, int numSamples, float sampleRate) {
    this->sampleRate = sampleRate;
    this->numSamples = numSamples;
    this->samples.resize(numSamples);
    for (int i = 0; i < numSamples; i++) {
        this->samples[i] = samples[i];
    }
}

SoundSample::SoundSample(int numSamples, int sampleRate) {
    this->numSamples = numSamples;
    this->sampleRate = sampleRate;
    this->samples.resize(this->numSamples);
    for (int i = 0; i < this->numSamples; i++) {
        this->samples[i] = samples[i];
    }
}

SoundSample::SoundSample(const SoundSample& original) {
    this->numSamples = original.numSamples;
    this->sampleRate = original.sampleRate;
    this->samples.resize(numSamples);
    vector<float> originalSamples = original.samples;
    for(int i = 0; i < this->numSamples; i++) {
        this->samples[i] = original.samples[i];
    }
}

SoundSample& SoundSample::operator=(const SoundSample& objToCopy) {
    if(this != &objToCopy) {
        this->numSamples = objToCopy.numSamples;
        this->sampleRate = objToCopy.sampleRate;
        this->samples.resize(this->numSamples);
        vector<float> originalSamples = objToCopy.samples;
        for(int i = 0; i < this->numSamples; i++) {
            this->samples[i] = objToCopy.samples[i];
        }
    }
    return *this;
}

SoundSample SoundSample::operator+(SoundSample toAdd) {
    SoundSample total;
    total.numSamples = toAdd.Length() + this->numSamples;
    total.sampleRate = this->sampleRate;
    total.samples.resize(total.numSamples);
    for(int i = 0; i < numSamples; i++) {
        total[i] = samples[i];
    }
    for(int i = 0; i < toAdd.Length(); i++) {
        total[this->numSamples + i] = toAdd.samples[i];
    }
    return total;
}

float& SoundSample::operator[](int index) {
    return samples.at(index);
}

void SoundSample::reverb2( float delay, float attenuation) {
    int sDelay;
    for (int i = 0; i < numSamples; i++) {
        sDelay = i * (delay * sampleRate);
        if (i >= sDelay)
            samples[i] += samples[i - sDelay] * attenuation;
    }
}

void SoundSample::adsr(float atime, float alevel, float dtime, float slevel, float rtime) {
    float time = (float) numSamples / sampleRate;
    float maxTime = time;

    if (atime + dtime + rtime > time)
        cerr << "a time + b time + r time is greater than total time" << endl;

    for (int i; i < numSamples; i++) {
        time =  (float) i / sampleRate;
        if (time <= atime)
            samples[i] = samples[i] * (time / atime) * alevel;

        if (time > atime && time <= atime + dtime)
            samples[i] = samples[i] * (((1 - ((time - atime) / dtime)) * (alevel - slevel)) + slevel);

        if (time > atime + dtime && time <= maxTime - rtime);
            samples[i] = samples[i] * slevel;

        if (time <= maxTime && time > maxTime - rtime)
            samples[i] = samples[i] * ((1 - ((time - (maxTime - rtime)) / rtime)) * slevel);
    }
}

int SoundSample::GetSampleRate() {
    return sampleRate;
}

int SoundSample::Length(){
    return numSamples;
}

float SoundSample::GetIndex(int index) {
    return samples[index];
}
