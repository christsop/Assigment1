#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <string.h>
#include <algorithm>

#include "ppm.h"

using namespace std;


namespace imaging {

    float *ReadPPM(const char *filename, int *w, int *h) {
        ifstream file(filename);
        if (!file.is_open()) {
            printf("Could not open %s!\n", filename);
            return nullptr;
        }

        string type;
        int width;
        int height;
        int maxNum;
        file >> type >> width >> height >> maxNum;
        printf("Image of type: %s \nImage dimensions are %i X %i and maxnum is %i\n", type.c_str(), width, height,
               maxNum);
        file.clear();    //?
        file.close();


        fstream fileBin(filename, ios::in | ios::binary);
        if (!fileBin.is_open()) {
            printf("Could not open %s!\n", filename);
            return nullptr;
        }

        //Go to the start of file and read it
        fileBin.seekg(0, ios_base::beg);
        *w = width;
        *h = height;
        //  how many values we expect to read = *w * *h * 3 tosous float perimenw na diavasw mesa se kathe arxeio
        int floatArraySize = width * height * 3;
        cout << "Float array size: " << floatArraySize << endl;

        //mesa sto arxeio uparxoun h*w*3 floats, ara einai sizeof(float)*h*w*3 o pinakas pou tha tous periexei afou tous exagw apo to stream
        float *colorsArray = new float[floatArraySize];
        fileBin.read((char *) colorsArray, sizeof(float) * floatArraySize);
        int counter = 0;
        // now print ta float tou kathe pixel
//        for (int i = 0; i < (floatArraySize); i++) {
//            counter++;
//            cout << "Value of color is: " << colorsArray[i] << " Arithmos xrwmatos: " << i << endl;
//        }


        return colorsArray;
    }

    bool WritePPM(const float * data, int w, int h, const char * filename) {

        fstream file(filename, ios::out | ios::binary );

        if (!file.is_open()) {
            printf("Could not create %s!\n", filename);
            return false;
        }

        cout << "write ppm, a random value is " << (char)data[10];
       file.write((char *)data, h*w*3);

        return true;
    }
}


