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
#ifndef __TYGRA_WINDOW_VIEW_DELEGATE__
#define __TYGRA_WINDOW_VIEW_DELEGATE__

namespace tygra {

class Window;

/**
 * A window object requires a delegate object to implement this interface
 * to define how the view (the window contents) should be rendered.
 */
class WindowViewDelegate
{
public:
    /**
     * Tells the delegate that it will start to be used.
     * Optional method.
     * @param window  The window object using the delegate.
     */
    virtual void windowViewWillStart(Window * window) {}

    /**
     * Tells the delegate that the view has been reset, usually following
     * a window resize event. Optional method.
     * @param window  The window object using the delegate.
     * @param width   The new width of the view in pixels.
     * @param height  The new height of the view in pixels.
     */
    virtual void windowViewDidReset(Window * window,
                                    int width,
                                    int height) {}

    /**
     * Tells the delegate that it is no longer being used.
     * Optional method.
     * @param window  The window object using the delegate.
     */
    virtual void windowViewDidStop(Window * window) {}

    /**
     * Tells the delegate to render the view. Required method.
     * @param window  The window object using the delegate.
     */
    virtual void windowViewRender(Window * window) = 0;
};

} // end namespace tygra

#endif // __TYGRA_WINDOW_VIEW_DELEGATE__
