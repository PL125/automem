#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include <Bounce2.h>

// #include "ui/loading.h"
#include "ui/result.h"
#include "ui/menu.h"
#include "ui/ui.h"

#include <string.h>
#include "arch/e24c.h"

LiquidCrystal_I2C *lcd;
Ui *ui;

void setup()
{
  Serial.begin(9600);

  // E24c e = E24c(4096, 0x50);
  // char *result = Parser::run("(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))", e);
  // Serial.println(result);


  lcd = new LiquidCrystal_I2C(0x27, 20, 4);
  lcd->init();
  lcd->backlight();
  
  // List<MenuItem> itemsRR = List<MenuItem>();
  // itemsRR.add(MenuItem("CD5404 (24c32)", new Result(lcd, result)));

  // List<MenuItem> itemsR = List<MenuItem>();
  // itemsR.add(MenuItem("Fiat", new Menu(lcd, &itemsRR)));

  
  E24c *ee = new E24c(4096, 0x50);

  Query *query = new Query(ee, "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))");

  MenuItem item = MenuItem {
    .title = "Radio",
    .view = new Result(lcd, query)
  };

  List<MenuItem> items = List<MenuItem>();
  items.add(item);
  // items.add(MenuItem());
  // items.add(MenuItem());
  // items.add(MenuItem());
  
  Menu m = Menu(lcd, &items);
  ui = new Ui(m);
  ui->render(*lcd);
  
}

void loop()
{
  ui->render(*lcd);
}
