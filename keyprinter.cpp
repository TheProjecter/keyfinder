/**
 *This work is licensed under the
 *Creative Commons Attribuzione 3.0
 *Unported License. To view a copy
 *of this license, visit
 *http://creativecommons.org/licenses/by/3.0/
 *
 *@author Raffaele Pertile <raffarti@gmail.com>
 */
#include "keyprinter.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <iostream>

static XKeyEvent createKeyEvent(Display *display, Window &win,
                           Window &winRoot, bool press,
                           int keycode, int modifiers);
KeyPrinter::KeyPrinter()
{
}

static XKeyEvent createKeyEvent(Display *display, Window &win,
                           Window &winRoot, bool press,
                           int keycode, int modifiers)
{
   XKeyEvent event;

   event.display     = display;
   event.window      = win;
   event.root        = winRoot;
   event.subwindow   = None;
   event.time        = CurrentTime;
   event.x           = 1;
   event.y           = 1;
   event.x_root      = 1;
   event.y_root      = 1;
   event.same_screen = True;
   event.keycode     = XKeysymToKeycode(display, keycode);
   event.state       = modifiers;

   if(press)
      event.type = KeyPress;
   else
      event.type = KeyRelease;

   return event;
}

void KeyPrinter::sendKey(int n, bool pressed){
    Display *display = XOpenDisplay(NULL);
    if(display == NULL){
        std::cerr << "Cannot access X, in some cases that may be caused by running this script with sudo, try kdesu, gksudo or gnome-sudo";
        return;
    }

    Window winRoot = XDefaultRootWindow(display);

    Window winFocus;
    int    revert;
    XGetInputFocus(display, &winFocus, &revert);

    XKeyEvent event = createKeyEvent(display, winFocus, winRoot, pressed, n + XK_KP_0, 1);
    XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);
    XFlush(display);
    XCloseDisplay(display);
}
