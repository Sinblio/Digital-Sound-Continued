#include "soundio.h"

#include <fstream>
#include <iostream>

using namespace std;

void SoundIO::OutputSound(SoundSample * samples, string filename) {
    ofstream myfile;
    myfile.open(filename, ios::out);
    float out;
    for (int i = 0; i < samples->Length(); i++) {
        out = (*samples)[i];
        if (out > -0.0001 && out < 0.0001)
            out = 0;
        myfile << out << "\n";
    }
    myfile.close();
}
