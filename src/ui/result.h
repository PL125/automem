#ifndef RESULT_H
#define RESULT_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "symbols.h"
#include "controls.h"

#include "view.h"
#include "parser/parser.h"

enum ResultType { Show, Edit };

class Result : public View
{
    private:        
        E *e;

        char *script;
        // char *value;

        ResultType type;

    public:
        Result(LiquidCrystal_I2C *lcd, E *e, char* script);
        ~Result();

        LiquidCrystal_I2C *lcd;
        int *cursor;

        void setup();
        void render();
        void action(LinkedList<View*> *views);
};

#endif