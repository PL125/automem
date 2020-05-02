#include "ui.h"

Ui::Ui(Menu *main_menu)
{
    this->views = new Stack<Menu>();
    this->views->push(main_menu);
    this->cursor = 0;
};

void Ui::render(LiquidCrystal_I2C *lcd)
{
    
}