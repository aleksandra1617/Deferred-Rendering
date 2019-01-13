/**
 * @file
 * @author    Tyrone Davison <t.p.davison@tees.ac.uk>
 * @date      September 2016
 * @version   1.16.1
 *
 *
 * @section LICENSE
 *
 * Copyright (c) 2016 Tyrone Davison <t.p.davison@tees.ac.uk>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#pragma once
#ifndef __TYGRA_IMAGE__
#define __TYGRA_IMAGE__

#include <tdl/tdl.h>

namespace tygra {

/***
 * C++ wrapper class for a tdlImage object.
 */
class Image
{
public:

    Image(tdlImage * image) : _image(image)
    {
    }

    Image() = delete;
    Image(const Image&) = delete;

    Image(Image&& rhs)
    {
        _image = rhs._image;
        rhs._image = nullptr;
    }

    ~Image()
    {
        if (_image != nullptr) {
            tdlFreeImage(_image);
        }
    }

    bool doesContainData() const
    {
        return tdlGetImageData(_image) != nullptr;
    }

    size_t width() const
    {
        return tdlGetImageWidth(_image);
    }

    size_t height() const
    {
        return tdlGetImageHeight(_image);
    }

    size_t componentsPerPixel() const
    {
        return tdlGetImageComponentsPerPixel(_image);
    }

    size_t bytesPerComponent() const
    {
        return tdlGetImageBytesPerComponent(_image);
    }

    const void * pixelData() const
    {
        return tdlGetImageData(_image);
    }

    void * pixelData()
    {
        return tdlGetImageData(_image);
    }

    const void * pixel(size_t x, size_t y) const
    {
        return tdlGetImagePixel(_image, x, y);
    }

    void * pixel(size_t x, size_t y)
    {
        return tdlGetImagePixel(_image, x, y);
    }

private:

    tdlImage * _image{ nullptr };

};

} // end namespace tygra

#endif // __TYGRA_IMAGE__
