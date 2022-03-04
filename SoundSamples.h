#ifndef SOUNDSAMPLE_H
#define SOUNDSAMPLE_H

#include <vector>
using namespace std;

class SoundSample {
    private:
        int sampleRate;
        vector<float> samples;
        int numSamples;
    public:
        SoundSample();
        SoundSample(float * samples, int numSamples, float sampleRate);
        SoundSample(int numSamples, int sampleRate);
        SoundSample(const SoundSample& original);
        SoundSample& operator=(const SoundSample& objToCopy);
        SoundSample operator+(SoundSample toAdd);
        float& operator[](int index);
        void reverb2( float delay, float attenuation);
        void adsr(float atime, float alevel, float dtime, float slevel, float rtime);
        int GetSampleRate();
        int Length();
        float GetIndex(int index);
};

#endif
