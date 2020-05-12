#ifndef UI_H
#define UI_H

#include <LiquidCrystal_I2C.h>
#include <LinkedList.h>

#include "ui/menu.h"
#include "ui/result.h"

#include "view.h"
#include "arch/e.h"
#include "arch/e93c.h"
#include "arch/e24c.h"

class Ui
{
private:
    LiquidCrystal_I2C lcd;

    View getView(int id);
    E getE(int id);
    char *getCmd(int id);

    Ui();

public:
    LinkedList<View > views;

    static Controls& getInstance();
    
    void render();
};

#endif