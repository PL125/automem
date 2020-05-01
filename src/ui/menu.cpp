#include "menu.h"

Menu::Menu(List<MenuItem> *items) {
    this->cursor = 0;
    this->items = items;
    // this->submenus = submenus;
}
