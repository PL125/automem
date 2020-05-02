#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include "../utils/list.h"
#include "menu.h"

class Menu;
class MenuItem
{
    public:
        char *title;
        Menu *menu;
        MenuItem(char *title, Menu *menu);
};

#endif