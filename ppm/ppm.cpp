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
            cerr << "Could not open:"<< filename <<"....Exiting...\n";
            exit(1);
        }

        fileBin >> type >> width >> height >> maxNum;

        if(type != "P6") {
            cerr << "\n\n.......INVALID IMAGE TYPE\n....Exiting...\n";
            exit(1);
        }

        if(maxNum != 255) {
            cerr << "\n\n.......INVALID IMAGE MAX VALUE\n....Exiting...\n";
            exit(1);
        }

        *w = width;
        *h = height;

        int imageTotatlPixels = width * height;
        float * data = new float[imageTotatlPixels * 3];

        unsigned char pix[3];
        int j = 0;
        for (int i = 0; i < imageTotatlPixels; ++i) {
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
            ofs.open(filename, std::ios::binary);
            if (ofs.fail()) throw("Cannot open output file");
            ofs << "P6\n" << w << " " << h << "\n255\n";
            unsigned char p;

            for (int i = 0; i < w * h * 3; ++i) {
                p =  (min(1.f, (1-data[i])) * 255.f);
                ofs << p;
            }
            ofs.close();
        }
        catch (const char *err) {
            fprintf(stderr, "%s\n", err);
            ofs.close();
        }

        return true;
    }
}


