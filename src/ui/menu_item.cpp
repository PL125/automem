#include "menu_item.h"

MenuItem::MenuItem(char *title, Menu *menu)
{
    this->title = title;
    this->menu = menu;
}