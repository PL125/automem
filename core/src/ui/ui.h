#ifndef UI_H
#define UI_H

#include <LiquidCrystal_I2C.h>
#include <LinkedList.h>

#include "view.h"
#include "arch/e.h"
#include "arch/e93c.h"
#include "arch/e24c.h"

#include "ui/menu.h"
#include "ui/result.h"

class MenuItem;

class Ui
{
private:
    LiquidCrystal_I2C* lcd;

    LinkedList<MenuItem>* getItems(int id);
    View* getView(int id);
    E getE(int id);
    char* getCmd(int id);

    Ui();

public:
    LinkedList<View*> *views;

    static Ui& getInstance();

    void update();

    void push(View* view);
    View* top();
    View* pop();
};

#endif