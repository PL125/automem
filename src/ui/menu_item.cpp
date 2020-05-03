#include "menu_item.h"

MenuItem::MenuItem(char *title, View *view)
{
    this->title = title;
    this->view = view;
}