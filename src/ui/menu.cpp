#include "menu.h"

Menu::Menu(char *title, Menu *submenus) {
    this->title = title;
    this->submenus = submenus;
}


void render(LiquidCrystal_I2C *lcd) {

}