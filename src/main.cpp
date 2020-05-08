#include <Arduino.h>

#include "ui/ui.h"
// #include "lib/parser.h"

// #define COMMAND_MAX_SIZE 256

Ui *ui;

void setup()
{
  Serial.begin(9600);

  // Parser::e = &E24c32;
  // // Serial.print(Parser::run("(merge (last (write 24 2)) (first (write 25 16)) (last (write 26 0)) (first (write 27 144)))#"));
  // //Serial.print(Parser::run("(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))"));
  // delay(100);
  
    char *result;
    result = Parser::simplify("(+ 1 (+ 1 (+ 3 (+ 7 15))))");
    // Serial.print(result);
  // delete result;
  // result = Parser::run("(+ 1 1 1 1 1 1 1 1 1 1 1 1 (+ 2 2 2 2 2 2 2 2 2 2 (+ 3 3 3 3 3)))");
  // Serial.print(result);
  // // free(&result);
  // // result = Parser::run("(+ 1 1 1 1 1 1 1 1 1 1 1 1 (+ 2 2 2 2 2 2 2 2 2 2 (+ 3 3 3 3 3 (+ 4 4 4 4 4 4))))");
  // // Serial.print(Parser::run("(merge (last (write 24 105)) (first (write 25 105)) (last (write 26 105)) (first (write 27 105)))#"));

  // // delay(100);

 
  // ui = new Ui();
}

// char buffer[COMMAND_MAX_SIZE];
// int current = 0;
void loop()
{
  // ui->render();

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
