#include <Arduino.h>

#include "ui/ui.h"
// #include "lib/parser.h"

// #define COMMAND_MAX_SIZE 256

Ui *ui;

void setup()
{
  Serial.begin(9600);
  while (!Serial);

  ui = new Ui();
}

// char buffer[COMMAND_MAX_SIZE];
// int current = 0;
void loop()
{
  ui->render();

  // if (Serial.available())
  // {
  //   char value = Serial.read();

  //   if (value == '#')
  //   {
  //     // Serial.print(buffer);
  //     Serial.print(Parser::run(buffer));
  //     for (int i = 0; i < COMMAND_MAX_SIZE; i++)
  //       buffer[i] = 0;
  //     current = 0;
  //   }
  //   else
  //   {
  //     buffer[current] = value;
  //     current++;
  //   }
  // }
}
