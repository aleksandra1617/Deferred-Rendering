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
#ifndef __TYGRA_FILEHELPER__
#define __TYGRA_FILEHELPER__

#include "Image.hpp"

#include <string>

namespace tygra {

/**
 * Construct a new string object with the contents of a text file.
 * @param   A local uri to the text file to read.
 *          Scheme must be content or resource.
 * @return  A new string object, empty if an error occurred.
 */
std::string createStringFromFile(const std::string & uri);

/**
 * Construct a new image object with the contents of a PNG file.
 * @param   A local uri to the PNG file to read.
 *          Scheme must be content or resource.
 * @return  A new image object, may have no contents is an error occurred.
 */
Image createImageFromPngFile(const std::string & uri);

} // end namespace tygra

#endif // __TYGRA_FILEHELPER__
