#include "Image.h"
#include "Color.h"
#include <string>
#include <iostream>


using namespace std;
using namespace imaging;

Image::Image () {

}

//constructor
Image::Image (unsigned int w, unsigned int h) :width(w), height(h) {

}

//constructor with image data
Image::Image (unsigned int w, unsigned int h, const Color * data) :width(w), height(h), buffer(const_cast<Color*>(data)) { //convert from const to non const

}

// copy constructor
Image::Image (const Image &src) :width(src.width), height(src.height), buffer(const_cast<Color*>(src.buffer)) {

}

//deconstructor
Image::~Image() {

}

bool Image::load(const std::string & filename, const std::string & format) {
    //prepei na xrisimopoiisoume tin readPPM gia na fortwsoume tin eikona
    return true;
}

bool Image::save(const std::string &filename, const std::string &format) {
    //prepei na xrisimopoiisoume tin writePPM gia na exagoume tin eikona
    return true;
}

Color Image::getPixel(unsigned int x, unsigned int y) const {
    return buffer[x*width+y];
}

void Image::setPixel(unsigned int x, unsigned int y, imaging::Color &value) {
    buffer[x*width+y] = value;
}

