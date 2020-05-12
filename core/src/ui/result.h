#ifndef RESULT_H
#define RESULT_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "symbols.h"
#include "controls.h"

#include "view.h"
#include "arch/e.h"
#include "parser/parser.h"

enum ResultType { Show, Edit, Error };

class Result : public View
{
    private:        
        char *script;
        // char *value;

        ResultType type;

    public:
        Result(LiquidCrystal_I2C *lcd, char* script);
        ~Result();

        LiquidCrystal_I2C *lcd;
        int *cursor;

        void setup();
        void render();
        void action(LinkedList<View*> *views);
};

#endif