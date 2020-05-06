#include <Arduino.h>

//#include <Wire.h>

// #include <LiquidCrystal_I2C.h>
// #include <Bounce2.h>

// #include "ui/loading.h"
// #include "ui/result.h"
// #include "ui/menu.h"
// #include "ui/ui.h"
#include "lib/parser.h"

#include <string.h>
#include "arch/e24c.h"

// LiquidCrystal_I2C *lcd;
// Ui *ui;

uint8_t currentCursor = 0;
uint8_t offset = 0;

// void debug_eeprom(int address)
// {
//   uint8_t data = e.read(address);
//   char buf[128];
//   sprintf(buf, " 0x%02X ", data);
//   Serial.print(buf);
// }

void setup()
{
  Serial.begin(9600);


  delay(10);

  char *result = Parser::run("(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))", E24c32);
  // char *result = Parser::run("(+ 1000 (+ 2000 (+ 50 (+ 4000 (+ 50 (+ 3000 (+ 40 (+ 500 1))))))))");
  // char *result = Parser::run("(+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 1))))))))))");
  // char *result = Parser::run("(+ 1 1 1 1 1 1 1 1 1 1 (+ 1 1 1 1 1 1 1 1 1 1 (+ 1 1 1 1 1 1 1 1 1 1 (+ 1 1 1 1 1 1 1 1 1 1))))");
  Serial.println(result);


  // lcd = new LiquidCrystal_I2C(0x27, 20, 4);
  // lcd->init();
  // lcd->backlight();
  
  // List<MenuItem> items3 = List<MenuItem>();
  // items3.add(MenuItem("Carro 1", new Loading(lcd)));
  // items3.add(MenuItem("Carro 2", nullptr));
  // items3.add(MenuItem("Carro 3", nullptr));
  // items3.add(MenuItem("Carro 4", nullptr));

  // List<MenuItem> items2 = List<MenuItem>();
  // items2.add(MenuItem("Chevrolet", new Menu(lcd, &items3)));
  // items2.add(MenuItem("Volkswagen", nullptr));
  // items2.add(MenuItem("Test", nullptr));
  // items2.add(MenuItem("Test", nullptr));

  // List<MenuItem> itemsRR = List<MenuItem>();
  // itemsRR.add(MenuItem("CD5404 (24c32)", new Result(lcd, result)));

  // List<MenuItem> itemsR = List<MenuItem>();
  // itemsR.add(MenuItem("Fiat", new Menu(lcd, &itemsRR)));

  // List<MenuItem> items = List<MenuItem>();
  // items.add(MenuItem("Imobilizador", new Loading(lcd)));
  // items.add(MenuItem("Airbag", new Menu(lcd, &items2)));
  // items.add(MenuItem("Odometro", nullptr));
  // items.add(MenuItem("Radio", new Menu(lcd, &itemsR)));
  // items.add(MenuItem("Teste 5", nullptr));
  // items.add(MenuItem("Teste 6", nullptr));
  // items.add(MenuItem("Teste 7", nullptr));
  // items.add(MenuItem("Teste 8", nullptr));
  // items.add(MenuItem("Teste 9", nullptr));
  // items.add(MenuItem("Teste 10", nullptr));
  // items.add(MenuItem("Teste 11", nullptr));
  // items.add(MenuItem("Teste 12", nullptr));
  
  // Menu m = Menu(lcd, &items);
  // ui = new Ui(&m);
  // ui->render(lcd);
  
  // e->setup();
}

// char buffer[512];
int current = 0;
uint16_t code;
void loop()
{
  
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
