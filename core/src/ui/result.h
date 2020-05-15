#ifndef RESULT_H
#define RESULT_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "symbols.h"
#include "controls.h"

#include "ui.h"
#include "view.h"
#include "arch/e.h"
#include "parser/parser.h"

enum ResultType { Show, Edit, Error };

class Result : public View
{
    private:        
        char* read;
        LinkedList<char*>* write;

        ResultType type;

    public:
        Result(LiquidCrystal_I2C *lcd, char* read);
        ~Result();

        LiquidCrystal_I2C *lcd;
        int *cursor;

        void setup();
        void draw();
        void update();
};

#endif