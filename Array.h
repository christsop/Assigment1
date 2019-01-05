#ifndef ASS1PROJECT_ARRAY_H
#define ASS1PROJECT_ARRAY_H

#include "Color.h"
#include <string>
#include "ppm/ppm.h"

/*! The imaging namespace contains every class or function associated with the image storage, compression and manipulation.
 */
namespace math
{


    template <class T>
    class Array
            {
    public:

    protected:
        std::vector<T> * buffer;                              //! Holds the image data. pointer buffer is pointing to array of Color's

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
        Array * getRawDataPtr();

        /*! Obtains the color of the image at location (x,y).
         *
         *  The method should do any necessary bounds checking.
         *
         *  \param x is the (zero-based) horizontal index of the pixel to get.
         *  \param y is the (zero-based) vertical index of the pixel to get.
         *
         *  \return The color of the (x,y) pixel as a Color object. Returns a black (0,0,0) color in case of an out-of-bounds x,y pair.
         */
        Array getPixel(unsigned int x, unsigned int y) const;

        // data mutators

        /*! Sets the RGB values for an (x,y) pixel.
         *
         *  The method should perform any necessary bounds checking.
         *
         *  \param x is the (zero-based) horizontal index of the pixel to set.
         *  \param y is the (zero-based) vertical index of the pixel to set.
         *  \param value is the new color for the (x,y) pixel.
         */
        void setPixel(unsigned int x, unsigned int y, Array & value);

        /*! Copies the image data from an external raw buffer to the internal image buffer.
         *
         *  The member function ASSUMES that the input buffer is of a size compatible with the internal storage of the
         *  Image object and that the data buffer has been already allocated. If the image buffer is not allocated or the
         *  width or height of the image are 0, the method should exit immediately.
         *
         *  \param data_ptr is the reference to the preallocated buffer from where to copy the data to the Image object.
         */
        void setData(const Array * & data_ptr);

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
        Array(unsigned int width, unsigned int height, const std::vector<T> * data_ptr);

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

    };

} //namespace imaging

#endif
