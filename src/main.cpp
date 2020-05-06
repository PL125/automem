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

  char *result = Parser::run("(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))", E24c32);
  // char *result = Parser::run("(+ 1000 (+ 2000 (+ 50 (+ 4000 (+ 50 (+ 3000 (+ 40 (+ 500 1))))))))");
  // char *result = Parser::run("(+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 1))))))))))");
  // char *result = Parser::run("(+ 1 1 1 1 1 1 1 1 1 1 (+ 1 1 1 1 1 1 1 1 1 1 (+ 1 1 1 1 1 1 1 1 1 1 (+ 1 1 1 1 1 1 1 1 1 1))))");
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

// char buffer[512];
// int current = 0;
// uint16_t code;
void loop()
{
  ui->render(*lcd);
  // if (Serial.available()) 
  // {
  //   List<char *> t = Parser::tokenize("(+ 1 2))");
  //   Token x = Parser::read_from_tokens(t);
  //   Serial.println(Parser::eval(x).value);
  //   delay(1000);
  //   // free(&t);
  //   // free(&x);
  // }

  // if (Serial.available())
  // {    

  //   char value = Serial.read();

  //   if (value == '#') {      
  //     Serial.println(buffer);
  //     List<char *> t = Parser::tokenize(buffer);
  //     Token x = Parser::read_from_tokens(t);
  //     Serial.println(Parser::eval(x).value);
  //     for(int i=0; i<512; i++) buffer[i] = 0;
  //     current = 0;
  //   } else {
  //     buffer[current] = value;
  //     current++;
  //   }
  // }
}
