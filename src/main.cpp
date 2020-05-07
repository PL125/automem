#include <Arduino.h>

#include "ui/ui.h"

Ui *ui;

void setup()
{
  Serial.begin(9600);


  ui = new Ui();
}

void loop()
{
  ui->render();
}
