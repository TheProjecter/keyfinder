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
#include <X11/extensions/XTest.h>
#include <iostream>

KeyPrinter::KeyPrinter()
{
}


void KeyPrinter::sendKey(int n, bool pressed){
    Display *display = XOpenDisplay(NULL);
    if(display == NULL){
        std::cerr << "Cannot access X, in some cases that may be caused by running this script with sudo, try kdesu, gksudo or gnome-sudo";
        return;
    }
    std::cout << n;

    XTestFakeKeyEvent(display, XKeysymToKeycode(display, XK_Num_Lock), pressed, 0);
    XTestFakeKeyEvent(display, XKeysymToKeycode(display, n + XK_KP_0), pressed, 0);
    XFlush(display);
    XCloseDisplay(display);
}
