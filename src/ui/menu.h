#ifndef MENU_H
#define MENU_H

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

#include "menu_item.h"
#include "../utils/list.h"

#define ENTER 6
#define BACK 5
#define UP 7
#define DOWN 8

class MenuItem;
class Menu
{
public:
    int cursor;
    List<MenuItem> *items;
    Menu(List<MenuItem> *items);
    void render(LiquidCrystal_I2C *lcd);
};

#endif