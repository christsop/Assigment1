#include "Array.h"
#include "Vec3.h"
#include "Image.h"
#include "Color.h"
#include <string>
#include <iostream>
#include "ppm/ppm.h"

using namespace std;
using namespace math;


template <class T>
Array<T>::Array() {
    width = 0;
    height = 0;
    std::vector<T> * buffer = nullptr;
}

//
//Array::Image () {
//    width = 0;
//    height = 0;
//    Color * buffer = nullptr;
//}
//
////constructor
//Image::Image (unsigned int w, unsigned int h) :width(w), height(h) {
//
//}
//
////constructor with image data
//Image::Image (unsigned int w, unsigned int h, const Color * data) :width(w), height(h), buffer(const_cast<Color*>(data)) { //convert from const to non const
//
//}
//
//// copy constructor
//Image::Image (const Image &src) :width(src.width), height(src.height), buffer(const_cast<Color*>(src.buffer)) {
//
//}
//
////deconstructor
//Image::~Image() {
//
//}
//
//bool Image::load(const std::string & filename, const std::string & format) {
//    int w, h;
//    float * imageData = ReadPPM(filename.c_str(), &w, &h);
//
//    buffer = new Color[width*height];
//
//    int pixel = -1;
//    for(int i=0; i<10; i++) {
//        for(int j=0; j<10; j++){
//
//            Color colorToSet;
//            colorToSet.r = imageData[pixel++];
//            colorToSet.g = imageData[pixel++];
//            colorToSet.b = imageData[pixel++];
//
//            setPixel(j, i, colorToSet);
//            cout << "set pixel no " << i << " x " << j << "with value" << colorToSet.r << " " << colorToSet.g << " " << colorToSet.b << "\n";
//
//        }
//    }
//    width = w;
//    height = h;
//
//    return true;
//}
//
//bool Image::save(const std::string &filename, const std::string &format) {
//    if(format != "P6") {
//        cerr << "Invalid image format"<< "\n" <<"....Exiting...\n";
//        exit(1);
//    }
//
//    return true;
//}
//
//Color Image::getPixel(unsigned int x, unsigned int y) const {
//    return buffer[x*width+y];
//}
//
//void Image::setPixel(unsigned int x, unsigned int y, imaging::Color &value) {
//    buffer[x*width+y] = value;
//}

