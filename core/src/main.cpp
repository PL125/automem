#include <Arduino.h>
#include <MemoryFree.h>

// #include "ui/ui.h"
#include "parser/parser.h"
#include "arch/e93c.h"

#define CMD_MAX_SIZE 128

void setup()
{
  Serial.begin(9600);
  Serial.println("--> Reset");
}

char cmd[CMD_MAX_SIZE];
int current = 0;

void loop()
{
  Parser* p = Parser::getInstance();
  // Ui ui = Ui::getInstance();
  // ui.update();

  if (Serial.available())
  {
    char value = Serial.read();

    if (value == '#')
    {
      p->call(cmd, cmd);
      Serial.println(cmd);

      // Serial.print("freeMemory()=");
      // Serial.println(freeMemory());

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
