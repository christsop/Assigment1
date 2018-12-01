#include <iostream>
#include <string>
#include "ppm/ppm.h"
#include "Image.h"

using namespace imaging;
using namespace std;


int main(int argc, char *argv[]) {

    char filename[50]= "Image01.ppm";
    char type[10];
    int width = 0;
    int height = 0;

    float * imageData = ReadPPM(filename, &width, &height);

    Color * imageColorData = new Color[width*height];

    int j = 0;
    for(int i=0; i<width*height*3; i = i+3) {
        imageColorData[j++] = Color(imageData[i], imageData[i+1], imageData[i+2]);
    }

    Image myImage(width, height, imageColorData);

    bool status = WritePPM(imageData,width, height, "papadopoulos.ppm");


    system("pause");
    return 0;
}