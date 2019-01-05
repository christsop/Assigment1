#include <iostream>
#include <string>
#include "ppm/ppm.h"
#include "Image.h"

#include <iostream>
#include <fstream>

using namespace imaging;
using namespace std;


template <class myType, class myType1>
myType GetMax (myType a, myType1 b) {
    myType1 toReturn = a > b ? a : b;
    return toReturn;
}

template<class Wtype, class Htype, class INtype>
class myImage {
public:INtype iname;
public:Wtype iwidth;
public:Htype iheight;

public:
    myImage (Wtype width, Htype height, INtype name) {
        iwidth = width;
        iheight = height;
        iname = name;
    }
};

int main(int argc, char *argv[]) {

    string n = "sample";
    int h = 1080;
    int w = 1920;

    myImage<int, int, string> image (w, h, n);

    cout << image.iwidth << endl;




//
//    char *filename = new char[15];
//
//    if(argc == 1) {
//        cout << "File name of the image to load: ";
//        cin >> filename;
//    } else if (argc == 2) {
//        filename = argv[1];
//    } else {
//        return 0;
//    }
//
//
//    int width = 0;
//    int height = 0;
//
//    float * imageData = ReadPPM(filename, &width, &height);
//
//    Color * imageColorData = new Color[width*height];
//
//    int j = 0;
//    for(int i=0; i<width*height*3; i = i+3) {
//        imageColorData[j++] = Color(imageData[i], imageData[i+1], imageData[i+2]);
//    }
//
//    Image myImage(width, height, imageColorData);
//
//    bool status = WritePPM(imageData,width, height, "negoriginal.ppm");


//    system("pause");
    return 0;
}