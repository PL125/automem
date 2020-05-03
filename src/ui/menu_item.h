#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include "../utils/list.h"
#include "menu.h"

class MenuItem
{
    public:
        char *title;
        View *view;
        MenuItem(char *title, View *view);
};

#endif