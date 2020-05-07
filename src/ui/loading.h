#ifndef LOADING_H
#define LOADING_H

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>
#include "math.h"
#include "symbols.h"

#include "view.h"

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

        void setup() const;
        void render() const;
        void action(Stack<View> *views) const;
};

#endif