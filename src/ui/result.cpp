#include "result.h"

Result::Result(LiquidCrystal_I2C *lcd, E *e, char* script)
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
    this->script = script;
    this->cursor = new int(0);
}

Result::~Result() {}

void Result::setup() const
{
    // Parser::e = e;
    // Parser::e->setup();
    // Parser::e->read(0);

    // Serial.println("aaa");

    char buf[8];
    Parser::run(buf, "(m (l (r 24)) (f (r 25)) (l (r 26)) (f (r 27)))");

    Serial.println(buf);

    *result = buf;
    // *result = buf;
}

void Result::render() const
{
    lcd->createChar(0, Symbols::square);
    lcd->createChar(1, Symbols::enter);
    lcd->createChar(2, Symbols::arrow_up);

    lcd->setCursor(1, 1);
    lcd->print("Codigo:");
    lcd->setCursor(1, 2);
    if(result != nullptr) {
        lcd->print(*result);
    }
    lcd->setCursor(19, 3);
    lcd->write(1);

    // bool blinking = true;
    //lcd->setCursor(*cursor, 2);
    lcd->setCursor(*cursor+1, 3);
    lcd->write(2);
    
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

void Result::action(LinkedList<View*> *views) const
{

    if (bouncer_up->update() && bouncer_up->rose())
    {
        lcd->setCursor(*cursor+1, 3);
        lcd->print(" ");
        *cursor += 1;
        *cursor %= 4;
    }

    if (bouncer_down->update() && bouncer_down->rose())
    {
        lcd->setCursor(*cursor+1, 3);
        lcd->print(" ");
        *cursor -= 1;
        if(*cursor < 0)
        {
            *cursor %= 0;
        }
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
