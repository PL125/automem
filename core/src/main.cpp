#include <Arduino.h>
#include <MemoryFree.h>

// #include "ui/ui.h"
#include "parser/parser.h"
#include "arch/e93c.h"

#define CMD_MAX_SIZE 512

// Ui *ui;
char cmd[CMD_MAX_SIZE];
int current = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("--> Reset");

  E93c e(512, 9, 8);
  e.setup();
  e.write(0, 10);
  delay(10);
  Serial.println(e.read(0));
    
  char buf[32];
  // Parser::run(buf, "(z (/ (i (m (r 3) (r 2) (r 1) (r 0))) 10) %06ld)");
  Parser::run(buf, "(+ 1 2 (+ 3 4))");
  Serial.println(buf);
  // ui = new Ui();
}

void loop()
{
  
  // ui->render();

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
