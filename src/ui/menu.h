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
    private:
        Bounce bouncer_up;
        Bounce bouncer_down;
        Bounce bouncer_enter;
        Bounce bouncer_back;
    public:
        char *title;
        Menu *submenus;
        int cursor;
        Menu(char *title, Menu *submenus);
        void render(LiquidCrystal_I2C *lcd);
        void up();
        void down();
        void enter();
        void back();
};

#endif