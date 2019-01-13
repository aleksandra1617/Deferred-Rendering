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
#ifndef __TYGRA_WINDOW__
#define __TYGRA_WINDOW__

#include <string>
#include <memory>

 // forward declare GLFW type to avoid #include polution
typedef struct GLFWwindow GLFWwindow;

namespace tygra {

class WindowViewDelegate;
class WindowControlDelegate;

/**
 * Provides an OpenGL compatible rendering window for use with
 * WindowViewDelegate and WindowControlDelegate objects.
 * @remark    Currently it is only possible to have a single window. This
 *            single instance is accessible via the Window#mainWindow method.
 */
class Window
{
public:
    /**
     * Obtains the application's primary Window object.
     */
    static Window * mainWindow();

    /**
     * Obtains the window's current view delegate.
     */
    WindowViewDelegate * view() const;

    /**
     * Assigns a view delegate for use by the window.
     */
    void setView(WindowViewDelegate * view);

    /**
     * Obtains the window's current control delegate.
     */
    WindowControlDelegate * controller() const;

    /**
     * Assigns a control delegate for use by the window.
     */
    void setController(WindowControlDelegate * controller);

    /**
     * Creates and makes visible an operating system window for this object.
     * @param width        The preferred width of the window's usable area.
     * @param height       The preferred height of the window's usable area.
     * @param sample_count The preferred number of samples for OpenGL's MSAA.
     * @param windowed     Boolean indicating if the window should open on the
     *                     desktop or whether it should be fullscreen.
     * @return             Boolean indicating success of the operation.
     */
    bool open(int width,
              int height,
              int sample_count,
              bool windowed,
              int major_version = 3,
              int minor_version = 3);

    /**
     * Determines if the operating system window is open.
     */
    bool isVisible() const;

    /**
     * Performs a window redraw using the view delegate and dequeues any
     * operating system events sending them to the control delegate.
     * This method must be called regularly, usually within the runloop.
     * This call is only valid once the window is open.
     */
    void update();

    /**
     * Closes (hides and destroys) the operating system window.
     */
    void close();

    /**
     * Assign a title to the window (if not fullscreen).
     * This call is only valid once the window is open.
     */
    void setTitle(const std::string & newTitle);

    /**
     * Resize the window's usable area to the given dimensions.
     * This call is only valid once the window is open.
     */
    void resize(int width,
                int height);

    /**
     * Change the mode of the window to/from fullscreen.
     * Not currently implemented.
     * This call is only valid once the window is open.
     */
    void setFullscreen(bool yes);

private:

    static void fakeResizeCallback();

    static void onError(int error_code,
                        const char * description);

    static void onResize(GLFWwindow * handle,
                         int width,
                         int height);

    static void onClose(GLFWwindow * handle);

    static void onMouseMove(GLFWwindow * handle,
                            double x,
                            double y);

    static void onMouseWheel(GLFWwindow * handle,
                             double x,
                             double y);

    static void onMouseButton(GLFWwindow * handle,
                              int button,
                              int action,
                              int mods);

    static void onKeyEvent(GLFWwindow * handle,
                           int key,
                           int scancode,
                           int action,
                           int mods);

    static void pollGamepads();

    Window();
    ~Window();
    static void Free(Window *);

    static std::unique_ptr<Window, void(*)(Window*)> main_window_;
    static const int MAX_GAMEPADS = 2;
    static const int MAX_GAMEPAD_AXES = 8;
    static const int MAX_GAMEPAD_BUTTONS = 14;
    struct GamepadState
    {
        float axis[MAX_GAMEPAD_AXES];
        unsigned char button[MAX_GAMEPAD_BUTTONS];
        bool present;
        GamepadState();
    };
    static GamepadState gamepad_state_[MAX_GAMEPADS];

    WindowViewDelegate * view_{ nullptr };
    WindowControlDelegate * controller_{ nullptr };
    GLFWwindow * glfw_handle_{ nullptr };
};

} // end namespace tygra

#endif // __TYGRA_WINDOW__
