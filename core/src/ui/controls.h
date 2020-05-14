#ifndef CONTROLS_H
#define CONTROLS_H

#include "ui/button.h"

#define BACK 3
#define ENTER 4
#define LEFT 5
#define RIGHT 6
#define UP 7
#define DOWN 8

class Controls
{
private:
    Controls();

public:
    static Button bBack;
    static Button bEnter;
    static Button bLeft;
    static Button bRight;
    static Button bUp;
    static Button bDown;
};

#endif