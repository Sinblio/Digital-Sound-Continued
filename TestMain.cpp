#include <iostream>
#include <math.h>
#include "wave.h"
#include "wave.cpp"
#include "SoundSamples.h"
#include "SoundSamples.cpp"
#include "soundio.h"
#include "soundio.cpp"

using namespace std;

int main() {
    cout << "Enter Wave Type(Sine, Triangle, Square, or Sawtooth): ";
    string waveType;
    cin >> waveType;

    while(waveType != "Sine" && waveType != "Triangle" && waveType != "Square" && waveType != "Sawtooth") {
        cout << "Error " << waveType << " is not a valid wave type." << endl;
        cout << "Enter Wave Type(Sine, Triangle, Square, or Sawtooth): ";
        cin >> waveType;
    }

    Wave* wave;

    if (waveType == "Sine")
        wave = new SineWave("sineWave");
    if (waveType == "Triangle")
        wave = new TriangleWave("triangleWave");
    if (waveType == "Square")
        wave = new SquareWave("squareWave");
    if (waveType == "Sawtooth")
        wave = new SawtoothWave("sawtoothWave");

    cout << endl << "Enter Sample Rate: ";
    int sampleRate;
    cin >> sampleRate;

    cout << endl << "Enter Reverb Parameters:" << endl << "Delay: ";
    float delay, attenuation;
    cin >> delay;
    cout << "Attenuation: ";
    cin >> attenuation;

    cout << endl << "Enter ASDR Parameters:" << endl << "ATime: ";
    float atime, alevel, dtime, slevel, rtime;
    cin >> atime;
    cout << "ALevel: ";
    cin >> alevel;
    cout << "DTime: ";
    cin >> dtime;
    cout << "SLevel: ";
    cin >> slevel;
    cout << "RTime: ";
    cin >> rtime;

    cout << endl << "Enter FileName: ";
    string filename;
    cin >> filename;

    int key;
    float freq;
    SoundSample* out = new SoundSample();
    int silenceSamples = sampleRate * .25;
    SoundSample* silence = new SoundSample(silenceSamples, sampleRate);

    cout << endl << "Enter Keys(enter -1 to exit):" << endl;
    cout << "Enter Key: ";
    cin >> key;

    while (key >= 0) {
        freq = pow(2.0, ((float) key - 49) / 12) * 440;
        SoundSample* toAdd = wave->generateSamples(freq, sampleRate, 1);
        toAdd->reverb2(delay, attenuation);
        toAdd->adsr(atime, alevel, dtime, slevel, rtime);
        SoundSample temp = *out + *toAdd;
        temp = temp + *silence;
        delete out;
        out = new SoundSample(temp);
        cout << "Enter Key: ";
        cin >> key;
    }

    SoundIO *io;
    io->OutputSound(out, filename);

    delete out;
    delete wave;
    delete silence;
}
