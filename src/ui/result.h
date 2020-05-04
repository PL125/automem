#ifndef RESULT_H
#define RESULT_H

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>
#include "symbols.h"

#include "view.h"

#define ENTER 6
#define BACK 5
#define UP 7
#define DOWN 8

class Result : public View
{
    private:
        Bounce *bouncer_up;
        Bounce *bouncer_down;
        Bounce *bouncer_enter;
        Bounce *bouncer_back;
        char *value;
    public:
        LiquidCrystal_I2C *lcd;
        int *cursor;
        Result(LiquidCrystal_I2C *lcd, char *value);
        ~Result();
        void render() const;
        void action(Stack<View> *views) const;
};

#endif