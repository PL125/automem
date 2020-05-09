#include "ui/controls.h"

Controls::Controls()
{
    pinMode(BACK, INPUT);
    pinMode(ENTER, INPUT);
    pinMode(LEFT, INPUT);
    pinMode(RIGHT, INPUT);
    pinMode(UP, INPUT);
    pinMode(DOWN, INPUT);

    back = new Bounce();
    back->attach(BACK);
    back->interval(50);

    enter = new Bounce();
    enter->attach(ENTER);
    enter->interval(50);

    left = new Bounce();
    left->attach(LEFT);
    left->interval(20);

    right = new Bounce();
    right->attach(RIGHT);
    right->interval(20);

    up = new Bounce();
    up->attach(UP);
    up->interval(20);

    down = new Bounce();
    down->attach(DOWN);
    down->interval(20);
}

Controls& Controls::getInstance()
{
    static Controls instance;

    return instance;
}
