#ifndef CONTROLS_H
#define CONTROLS_H

#include <Arduino.h>
#include <Bounce2.h>

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
    static Controls& getInstance();

    Bounce *back;
    Bounce *enter;
    Bounce *left;
    Bounce *right;
    Bounce *up;
    Bounce *down;
};

#endif