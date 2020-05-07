#ifndef UI_H
#define UI_H 

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

#include "ui/menu.h"
#include "ui/loading.h"
#include "ui/result.h"
#include "ui/menu.h"
#include "ui/ui.h"

#include "lib/stack.h"
#include "lib/parser.h"

#include "arch/e24c.h"

class Ui
{
    private:
        LiquidCrystal_I2C *lcd;

    public:
        Stack<View> *views;
        int cursor;
        Ui();
        void render();
};

#endif