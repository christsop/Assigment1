#include <iostream>
#include <string>
#include "ppm/ppm.h"
#include "Image.h"
#include "Array.h"

#include <iostream>
#include <fstream>

using namespace imaging;
using namespace std;
//using namespace math;

int main(int argc, char *argv[]) {


    string n = "sample";
    int h = 1080;
    int w = 1920;

    //myImage<int, int, string> image (w, h, n);

    char *filename = new char[15];

    if(argc == 1) {
        cout << "File name of the image to load: ";
        cin >> filename;
    } else if (argc == 2) {
        filename = argv[1];
    } else {
        return 0;
    }


    int width = 0;
    int height = 0;

    float * imageData = ReadPPM(filename, &width, &height);

    Color * imageColorData = new Color[width*height];

    int j = 0;
    for(int i=0; i<width*height*3; i = i+3) {
        imageColorData[j++] = Color(imageData[i], imageData[i+1], imageData[i+2]);
    }

    Array<Color> imageArray(width, height, imageColorData);


    Image myImage(width, height, imageColorData);

    cout << &imageArray(1,2) << endl;

    bool status = WritePPM(imageData,width, height, "negoriginal.ppm");


//    system("pause");
    return 0;
}