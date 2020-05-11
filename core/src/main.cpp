#include <Arduino.h>

#include "ui/ui.h"

// #include "arch/e24c.h"

// #define CMD_MAX_SIZE 64

Ui *ui;
// char cmd[CMD_MAX_SIZE];
// int current = 0;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{

  // lcd.begin();
  // lcd.backlight();

  // initialize the LCD
  // lcd.begin();

  // // Turn on the blacklight and print a message.
  // lcd.backlight();
  // lcd.print("automem3!");

  // lcd.setCursor(0, 0);
  // lcd.println("aaa");

  Serial.begin(115200);
  while (!Serial);

  // Serial.println("aaaa");


  // char buf[8];
  // Parser::run(buf, "(r 24)");
  // Serial.print(buf);




  ui = new Ui();
}

void loop()
{
  
  ui->render();

  // if (Serial.available())
  // {
  //   char value = Serial.read();

  //   if (value == '#')
  //   {
  //     // Parser::run(cmd, cmd);
  //     Serial.println(cmd);

  //     for (int i = 0; i < CMD_MAX_SIZE; i++)
  //       cmd[i] = 0;
  //     current = 0;
  //   }
  //   else
  //   {
  //     cmd[current] = value;
  //     current++;
  //   }
  // }
}
