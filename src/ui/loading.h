#ifndef LOADING_H
#define LOADING_H

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>
#include "math.h"

#include "view.h"
#include "menu_item.h"
#include "../utils/list.h"

#define ENTER 6
#define BACK 5

class Loading : public View
{
    private:
        Bounce *bouncer_enter;
        Bounce *bouncer_back;
    public:
        int *percentage;
        LiquidCrystal_I2C *lcd;
        Loading(LiquidCrystal_I2C *lcd);
        ~Loading();
        void render() const;
        void action(Stack<View> *views) const;
};

#endif