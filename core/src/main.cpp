#include <Arduino.h>
#include <MemoryFree.h>

#include "ui/ui.h"
#include "parser/parser.h"
#include "arch/e93c.h"

#define CMD_MAX_SIZE 128

Ui *ui;
char cmd[CMD_MAX_SIZE];
int current = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("--> Reset");

  E93c e(512, 9, 8);
  e.setup();
  // e.write(0, 10);
  delay(10);
  Serial.println(e.read(0));
    
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
      Parser::run(cmd, cmd);
      Serial.println(cmd);

      Serial.print("freeMemory()=");
      Serial.println(freeMemory());

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
