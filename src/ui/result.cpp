#include "result.h"

Result::Result(LiquidCrystal_I2C *lcd, char *value)
{
    pinMode(UP, INPUT);
    pinMode(DOWN, INPUT);
    pinMode(ENTER, INPUT);
    pinMode(BACK, INPUT);

    bouncer_up = new Bounce();
    bouncer_up->attach(UP);
    bouncer_up->interval(20);

    bouncer_down = new Bounce();
    bouncer_down->attach(DOWN);
    bouncer_down->interval(20);

    bouncer_enter = new Bounce();
    bouncer_enter->attach(ENTER);
    bouncer_enter->interval(20);

    bouncer_back = new Bounce();
    bouncer_back->attach(BACK);
    bouncer_back->interval(20);

    this->lcd = lcd;
    this->value = value;
    this->cursor = new int(1);
}

Result::~Result() {}

void Result::render() const
{
    lcd->createChar(0, Symbols::square);
    lcd->createChar(1, Symbols::enter);

    lcd->setCursor(1, 1);
    lcd->print("Codigo:");
    lcd->setCursor(1, 2);
    lcd->print(value);
    lcd->setCursor(19, 3);
    lcd->write(1);

    // bool blinking = true;
    //lcd->setCursor(*cursor, 2);
    //lcd->cursor_on();
    // lcd->sho();
    
    // while(1) {
    //     if (blinking) {
	// 		lcd->noBlink();
	// 		blinking = false;
	// 	} else {
	// 		lcd->blink();
	// 		blinking = true;
	// 	}
    //     delay(4000);
    // }
}

void Result::action(Stack<View> *views) const
{

    if (bouncer_up->update() && bouncer_up->rose())
    {
        *cursor += 1;
        
    }

    if (bouncer_down->update() && bouncer_down->rose())
    {
        *cursor -= 1;
    }

    if (bouncer_enter->update() && bouncer_enter->rose())
    {
        lcd->clear();
        views->pop();
    }

    if (bouncer_back->update() && bouncer_back->rose())
    {
        lcd->clear();
        views->pop();
    }
}
