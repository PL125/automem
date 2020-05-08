#ifndef UI_H
#define UI_H 

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>
#include <LinkedList.h>

#include "ui/menu.h"
#include "ui/loading.h"
#include "ui/result.h"
#include "ui/menu.h"
#include "ui/ui.h"

#include "lib/parser.h"

#include "arch/e24c.h"

class Ui
{
    private:
        LiquidCrystal_I2C *lcd;

    public:
        LinkedList<View> &views;
        Ui();
        void render();
};

#endif