#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <string.h>
#include <algorithm>

#include "ppm.h"

using namespace std;


namespace imaging {

    float * ReadPPM(const char * filename, int * w, int * h) {

        string type;
        int width;
        int height;
        int maxNum;

        fstream fileBin(filename, ios::in | ios::binary);

        if (!fileBin.is_open()) {
            printf("Could not open %s!\n", filename);
            return nullptr;
        }

        fileBin >> type >> width >> height >> maxNum;

        *w = width;
        *h = height;

        int intArraySize = width * height * 3;
        float * data = new float[intArraySize];

        unsigned char pix[3];
        int j = 0;
        for (int i = 0; i < width * height; ++i) {
            fileBin.read(reinterpret_cast<char *>(pix), 3);
            data[j++] = pix[0] / 255.f;
            data[j++] = pix[1] / 255.f;
            data[j++] = pix[2] / 255.f;
        }

        return data;
    }

    bool WritePPM(const float * data, int w, int h, const char * filename) {

        std::ofstream ofs;
        try {
            ofs.open(filename, std::ios::binary); // need to spec. binary mode for Windows users
            if (ofs.fail()) throw("Can't open output file");
            ofs << "P6\n" << w << " " << h << "\n255\n";
            unsigned char p;
            // loop over each pixel in the image, clamp and convert to byte format
            for (int i = 0; i < w * h * 3; ++i) {
                p = (min(1.f, (1-data[i])) * 255.f);
                ofs << p;
            }
            ofs.close();
        }
        catch (const char *err) {
            fprintf(stderr, "%s\n", err);
            ofs.close();
        }


//        for(int i=0; i<(w*h*3); i++) {
//            cout << i << " position has value " << data[i] << "\n";
//        }
//        cout << w << " x " << h;

//        fstream file(filename, ios::out | ios::binary );
//
//        if (!file.is_open()) {
//            printf("Could not create %s!\n", filename);
//            return false;
//        }
//
//        cout << "write ppm, a random value is " << (char)data[10] << "\n";
//        file.write((char *)data, h*w*3);

        return true;
    }
}


