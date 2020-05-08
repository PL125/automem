#include <Arduino.h>

#include "ui/ui.h"
// #include "lib/parser.h"

// #define COMMAND_MAX_SIZE 256

Ui *ui;

void setup()
{
  Serial.begin(9600);
  while (!Serial);
    Parser::e = &E24c32;
  // // Serial.print(Parser::run("(m (l (w 24 2)) (f (w 25 16)) (l (w 26 0)) (f (w 27 144)))#"));
  // Serial.print(Parser::run("(m (l (r 24)) (f (r 25)) (l (r 26)) (f (r 27)))"));
  // delay(100);
  
    // char *query = "(+ 1 1)";
    char *query = "(r 0)";
    // char *query = "(l AB)";

    char buf[32];
    // char *query = "(+ 1 1)";

    Parser::run(buf, query);
    Serial.print(buf);

    // free(&query);

    // query = "(+ 2 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 (+ 1 1))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))";
    // result = Parser::simplify(query);
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
