#ifndef MENU_H
#define MENU_H 

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

#define ENTER 6
#define BACK 5
#define UP 7
#define DOWN 8

class Menu
{  
    public:
        char *title;
        Menu *submenus;
        int cursor;
        Menu(char *title);
        void render(LiquidCrystal_I2C *lcd);
};

#endif