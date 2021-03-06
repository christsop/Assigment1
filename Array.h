#ifndef ASS1PROJECT_ARRAY_H
#define ASS1PROJECT_ARRAY_H


#include <string>
#include <iostream>

using namespace std;

template <typename T>

class Array
{
public:

protected:
    T * buffer;                              //! Holds the image data. pointer buffer is pointing to array of Color's

    unsigned int width, 						 //! The width of the image (in pixels)
            height;		                 //! The height of the image (in pixels)

public:
    // metric accessors

    /*! Returns the width of the image
     */
    const unsigned int getWidth() const {return width;}

    /*! Returns the height of the image
     */
    const unsigned int getHeight() const {return height;}

    // data accessors

    /*! Obtains a pointer to the internal data.
     *
     *  This is NOT a copy of the internal image data, but rather a pointer
     *  to the internally allocated space, so DO NOT attempt to delete the pointer.
     */
    T * getRawDataPtr();

    /*! Obtains the color of the image at location (x,y).
     *
     *  The method should do any necessary bounds checking.
     *
     *  \param x is the (zero-based) horizontal index of the pixel to get.
     *  \param y is the (zero-based) vertical index of the pixel to get.
     *
     *  \return The color of the (x,y) pixel as a Color object. Returns a black (0,0,0) color in case of an out-of-bounds x,y pair.
     */
    T getPixel(unsigned int x, unsigned int y) const;

    // data mutators

    /*! Sets the RGB values for an (x,y) pixel.
     *
     *  The method should perform any necessary bounds checking.
     *
     *  \param x is the (zero-based) horizontal index of the pixel to set.
     *  \param y is the (zero-based) vertical index of the pixel to set.
     *  \param value is the new color for the (x,y) pixel.
     */
    void setPixel(unsigned int x, unsigned int y, T & value);

    /*! Copies the image data from an external raw buffer to the internal image buffer.
     *
     *  The member function ASSUMES that the input buffer is of a size compatible with the internal storage of the
     *  Image object and that the data buffer has been already allocated. If the image buffer is not allocated or the
     *  width or height of the image are 0, the method should exit immediately.
     *
     *  \param data_ptr is the reference to the preallocated buffer from where to copy the data to the Image object.
     */
    void setData(const T * & data_ptr);

    // constructors and destructor

    /*! Default constructor.
     *
     * By default, the dimensions of the image should be zero and the buffer must be set to nullptr.
     */
    Array();

    /*! Constructor with width and height specification.
     *
     * \param width is the desired width of the new image.
     * \param height is the desired height of the new image.
     */
    Array(unsigned int width, unsigned int height);

    /*! Constructor with data initialization.
     *
     * \param width is the desired width of the new image.
     * \param height is the desired height of the new image.
     * \param data_ptr is the source of the data to copy to the internal image buffer.
     *
     * \see setData
     */
    Array(unsigned int width, unsigned int height, const T * data_ptr);

    /*! Copy constructor.
     *
     * \param src is the source image to replicate in this object.
     */
    Array(const Array &src);

    /*! The Image destructor.
     */
    ~Array();

    /*! Copy assignment operator.
     *
     * \param right is the source image.
     */
    Array & operator = (const Array & right);

    T & operator ()(int i, int j){

        return buffer[i*width+j];
    };

};

template <typename T>
Array<T>::Array() {
    width = 0;
    height = 0;
    std::vector<T> * buffer = nullptr;
}

template <typename T>
Array<T>::Array(unsigned int w, unsigned int h) :width(w), height(h) {

}

//constructor with image data
template <typename T>
Array<T>::Array(unsigned int w, unsigned int h, const T *data)  :width(w), height(h), buffer(const_cast<T*>(data)) {}

//// copy constructor
template <typename T>
Array<T>::Array(const Array &src) :width(src.width), height(src.height), buffer(const_cast<T*>(src.buffer)) {

}

////deconstructor
template <typename T>
Array<T>::~Array() {}


#endif
