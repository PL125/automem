#include <Arduino.h>

#include "ui/ui.h"

#define CMD_MAX_SIZE 64

Ui *ui;
char cmd[CMD_MAX_SIZE];
int current = 0;

void setup()
{
  Serial.begin(115200);

  delay(100);

  Serial.println("aaaa");


  // char buf[8];
  // Parser::run(buf, "(r 24)");
  // Serial.print(buf);

  ui = new Ui();
}

void loop()
{
  
  ui->render();

  delay(1);

  if (Serial.available())
  {
    char value = Serial.read();

    delay(1);

    if (value == '#')
    {
      Parser::run(cmd, cmd);
      Serial.println(cmd);

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
