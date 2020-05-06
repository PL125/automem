#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include <Bounce2.h>

#include "ui/loading.h"
#include "ui/result.h"
#include "ui/menu.h"
#include "ui/ui.h"
#include "lib/parser.h"

#include <string.h>
#include "arch/e24c.h"

LiquidCrystal_I2C *lcd;
Ui *ui;

uint8_t currentCursor = 0;
uint8_t offset = 0;

void setup()
{
  Serial.begin(9600);


  delay(10);

  // char *result = Parser::run("(+ 1000 (+ 2000 (+ 50 (+ 4000 (+ 50 (+ 3000 (+ 40 (+ 500 1))))))))");
  // char *result = Parser::run("(+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 1))))))))))");
  // char *result = Parser::run("(+ 1 1 1 1 1 1 1 1 1 1 (+ 1 1 1 1 1 1 1 1 1 1 (+ 1 1 1 1 1 1 1 1 1 1 (+ 1 1 1 1 1 1 1 1 1 1))))");
  E24c e = E24c(4096, 0x50);
  char *result = Parser::run("(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))", e);
  Serial.println(result);


  lcd = new LiquidCrystal_I2C(0x27, 20, 4);
  lcd->init();
  lcd->backlight();
  
  // List<MenuItem> itemsRR = List<MenuItem>();
  // itemsRR.add(MenuItem("CD5404 (24c32)", new Result(lcd, result)));

  // List<MenuItem> itemsR = List<MenuItem>();
  // itemsR.add(MenuItem("Fiat", new Menu(lcd, &itemsRR)));

  List<MenuItem> items;
  items.add(MenuItem());
  items.add(MenuItem());
  items.add(MenuItem());
  items.add(MenuItem());
  
  Menu m = Menu(lcd, &items);
  ui = new Ui(m);
  ui->render(*lcd);
  
}

void loop()
{
  ui->render(*lcd);
}
