#ifndef RESULT_H
#define RESULT_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "symbols.h"
#include "controls.h"

#include "view.h"
#include "parser/parser.h"

class Result : public View
{
    private:        
        E *e;
        char *script;
        // char *value;

    public:
        LiquidCrystal_I2C *lcd;
        int *cursor;
        Result(LiquidCrystal_I2C *lcd, E *e, char* script);
        ~Result();

        void setup() const;
        void render() const;
        void action(LinkedList<View*> *views) const;
};

#endif