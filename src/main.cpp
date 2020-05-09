#include <Arduino.h>

#include "ui/ui.h"

#include "arch/e24c.h"

#define CMD_MAX_SIZE 64

Ui *ui;
char cmd[CMD_MAX_SIZE];
int current = 0;

void setup()
{
  Serial.begin(9600);
  while (!Serial);

  // char buf[8];
  // Parser::run(buf, "(r 24)");
  // Serial.print(buf);

  ui = new Ui();
}

void loop()
{
  
  ui->render();

  if (Serial.available())
  {
    char value = Serial.read();

    if (value == '#')
    {

      char buf[8];
      Parser::run(buf, cmd);
      Serial.print(buf);

      for (int i = 0; i < CMD_MAX_SIZE; i++)
        cmd[i] = 0;
      current = 0;
    }
    else
    {
      cmd[current] = value;
      current++;
    }
  }
}
