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
#ifndef __TYGRA_WINDOW_CONTROL_DELEGATE__
#define __TYGRA_WINDOW_CONTROL_DELEGATE__

namespace tygra {

class Window;

/**
* Enumeration of non-printable keyboard keys.
* Printable keys are represented by their capital ASCII value.
*/
enum WindowKeyIndex
{
    kWindowKeySpace = 32,
    //kWindowKeySpecial = 256,
    kWindowKeyEsc = 256,
    kWindowKeyEnter,
    kWindowKeyTab,
    kWindowKeyBackspace,
    kWindowKeyInsert,
    kWindowKeyDel,
    kWindowKeyRight,
    kWindowKeyLeft,
    kWindowKeyDown,
    kWindowKeyUp,
    kWindowKeyPageUp,
    kWindowKeyPageDown,
    kWindowKeyHome,
    kWindowKeyEnd,
    kWindowKeyCapsLock = 280,
    kWindowKeyScrollLock,
    kWindowKeyPadNumLock,
    kWindowKeyPrintScreen,
    kWindowKeyPause,
    kWindowKeyF1 = 290,
    kWindowKeyF2,
    kWindowKeyF3,
    kWindowKeyF4,
    kWindowKeyF5,
    kWindowKeyF6,
    kWindowKeyF7,
    kWindowKeyF8,
    kWindowKeyF9,
    kWindowKeyF10,
    kWindowKeyF11,
    kWindowKeyF12,
    kWindowKeyF13,
    kWindowKeyF14,
    kWindowKeyF15,
    kWindowKeyF16,
    kWindowKeyF17,
    kWindowKeyF18,
    kWindowKeyF19,
    kWindowKeyF20,
    kWindowKeyF21,
    kWindowKeyF22,
    kWindowKeyF23,
    kWindowKeyF24,
    kWindowKeyF25,
    kWindowKeyPad0 = 320,
    kWindowKeyPad1,
    kWindowKeyPad2,
    kWindowKeyPad3,
    kWindowKeyPad4,
    kWindowKeyPad5,
    kWindowKeyPad6,
    kWindowKeyPad7,
    kWindowKeyPad8,
    kWindowKeyPad9,
    kWindowKeyPadDecimal,
    kWindowKeyPadDivide,
    kWindowKeyPadMultiply,
    kWindowKeyPadSubtract,
    kWindowKeyPadAdd,
    kWindowKeyPadEnter,
    kWindowKeyPadEqual,
    kWindowKeyLShift = 340,
    kWindowKeyLCtrl,
    kWindowKeyLAlt,
    kWindowKeyLSuper,
    kWindowKeyRShift,
    kWindowKeyRCtrl,
    kWindowKeyRAlt,
    kWindowKeyRSuper,
};

/**
 * Enumeration of mouse button indices.
 */
enum WindowMouseButtonIndex
{
    kWindowMouseButtonLeft,
    kWindowMouseButtonRight,
    kWindowMouseButtonMiddle
};

/**
 * Enumeration of gamepad axis.
 */
enum WindowGamepadAxisIndex
{
    kWindowGamepadAxisLeftThumbX,
    kWindowGamepadAxisLeftThumbY,
    kWindowGamepadAxisRightThumbX,
    kWindowGamepadAxisRightThumbY,
    kWindowGamepadAxisLeftTrigger,
    kWindowGamepadAxisRightTrigger,
    kWindowGamepadAxisReserved0,
    kWindowGamepadAxisReserved1
};

/**
 * Enumeration of gamepad buttons.
 */
enum WindowGamepadButtonIndex
{
    kWindowGamepadButtonA,
    kWindowGamepadButtonB,
    kWindowGamepadButtonX,
    kWindowGamepadButtonY,
    kWindowGamepadButtonLeftShoulder,
    kWindowGamepadButtonRightShoulder,
    kWindowGamepadButtonBack,
    kWindowGamepadButtonStart,
    kWindowGamepadButtonLeftThumb,
    kWindowGamepadButtonRightThumb,
    kWindowGamepadButtonDpadUp,
    kWindowGamepadButtonDpadRight,
    kWindowGamepadButtonDpadDown,
    kWindowGamepadButtonDpadLeft
};

/**
* A window object can use a delegate object that implements this interface
* to define how the window should respond to user and operating system events.
*/
class WindowControlDelegate
{
public:
    /**
    * Tells the delegate that it will start to be used to control the window.
    * Optional method.
    * @param window  The window object using the delegate.
    */
    virtual void windowControlWillStart(Window * window) {}

    /**
    * Tell the delegate that it is no longer being used to control the window.
    * Optional method.
    * @param window  The window object using the delegate.
    */
    virtual void windowControlDidStop(Window * window) {}

    /**
    * Tells the delegate that the window's view delegate is about to draw.
    * Optional method.
    * @param window  The window object using the delegate.
    */
    virtual void windowControlViewWillRender(Window * window) {}

    /**
    * Tells the delegate that the mouse cursor has moved.
    * Optional method.
    * @param window  The window object using the delegate.
    * @param x       The new window-based x-coordinate of the cursor.
    * @param y       The new window-based y-coordinate of the cursor.
    * @remark        The y-axis for the window coordinate system is downwards.
    */
    virtual void windowControlMouseMoved(Window * window,
                                         int x,
                                         int y) {}

    /**
    * Tells the delegate that a mouse button has been pressed or released.
    * Optional method.
    * @param window        The window object using the delegate.
    * @param button_index  Zero-based index of button triggering the event.
    * @param down          Boolean true if the button is pressed down.
    */
    virtual void windowControlMouseButtonChanged(Window * window,
                                                 int button_index,
                                                 bool down) {}

    /**
    * Tells the delegate that the mouse wheel has moved.
    * Optional method.
    * @param window  The window object using the delegate.
    * @param pos     The integer position of the mouse wheel.
    */
    virtual void windowControlMouseWheelMoved(Window * window,
                                              int position) {}

    /**
    * Tells the delegate that a keyboard key has been pressed or released.
    * Optional method.
    * @param window      The window object using the delegate.
    * @param key_index   Zero-based index of the key triggering the event.
    * @param down        Boolean true if the key is pressed down.
    */
    virtual void windowControlKeyboardChanged(Window * window,
                                              int key_index,
                                              bool down) {}

    /**
    * Tells the delegate that an analogue input on a gamepad has moved.
    * Optional method.
    * @param window         The window object using the delegate.
    * @param gamepad_index  Zero-based index of gamepad triggering the event.
    * @param axis_index     Zero-based index of axis triggering the event.
    * @param pos            Normalized [-1,1] position of the axiz.
    */
    virtual void windowControlGamepadAxisMoved(Window * window,
                                               int gamepad_index,
                                               int axis_index,
                                               float pos) {}

    /**
    * Tell delegate that a button on a gamepad has been pressed or released.
    * Optional method.
    * @param window         The window object using the delegate.
    * @param gamepad_index  Zero-based index of gamepad triggering the event.
    * @param button_index   Zero-based index of button triggering the event.
    * @param down           Boolean true if the button is pressed down.
    */
    virtual void windowControlGamepadButtonChanged(Window * window,
                                                   int gamepad_index,
                                                   int button_index,
                                                   bool down) {}

    /**
    * Tells the delegate that a gamepad has been added or removed.
    * Optional method.
    * @param window         The window object using the delegate.
    * @param gamepad_index  Zero-based index of gamepad triggering the event.
    * @param present        Boolean true if the gamepad is now available.
    */
    virtual void windowControlGamepadPresenceChanged(Window * window,
                                                     int gamepad_index,
                                                     bool present) {}
};

} // end namespace tygra

#endif // __TYGRA_WINDOW_CONTROL_DELEGATE__
