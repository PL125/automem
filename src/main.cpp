#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Bounce2.h>
#include "ui/menu.h"
#include "ui/ui.h"

#include "arch/e93xx.h"
#include <string.h>

E93xx e(512, 9, 8);
LiquidCrystal_I2C lcd(0x27, 20, 4);
Ui *ui;

uint8_t currentCursor = 0;
uint8_t offset = 0;

void debug_eeprom(int address)
{
  uint8_t data = e.read(address);
  char buf[128];
  sprintf(buf, " 0x%02X ", data);
  Serial.print(buf);
}

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  List<MenuItem> items3 = List<MenuItem>();
  items3.add(new MenuItem("Carro 1", nullptr));
  items3.add(new MenuItem("Carro 2", nullptr));
  items3.add(new MenuItem("Carro 3", nullptr));
  items3.add(new MenuItem("Carro 4", nullptr));

  List<MenuItem> items2 = List<MenuItem>();
  items2.add(new MenuItem("Chevrolet", new Menu(&lcd, &items3)));
  items2.add(new MenuItem("Volkswagen", nullptr));
  items2.add(new MenuItem("Test", nullptr));
  items2.add(new MenuItem("Test", nullptr));

  List<MenuItem> items = List<MenuItem>();
  items.add(new MenuItem("Imobilizador", new Menu(&lcd, &items2)));
  items.add(new MenuItem("Airbag", nullptr));
  items.add(new MenuItem("Odometro", nullptr));
  items.add(new MenuItem("Configuracoes", nullptr));
  
  Menu m = Menu(&lcd, &items);
  ui = new Ui(&m);
  e.setup();
}

char state = 'W';
char option;
char address[8];
char data[8];
int current = 0;
uint16_t code;
void loop()
{

  ui->render(&lcd);

  if (Serial.available())
  {
    char value = Serial.read();

    if (state == 'W')
    {

      for (int i = 0; i < 8; i++)
        address[i] = 0;
      for (int i = 0; i < 8; i++)
        data[i] = 0;
      current = 0;

      option = value;
      state = 'A';
    }
    else
    {

      if (value == '#')
      {
        switch (option)
        {
        case 'R':
          // e.read_all();
          debug_eeprom((int)strtol(address, NULL, 16));
          break;
        case 'P':
          e.print();
          break;
        case 'W':
          e.write((int)strtol(address, NULL, 16), (int)strtol(data, NULL, 16));
          break;
        default:
          Serial.println("Opção inválida");
        }

        state = 'W';
      }
      else if (value == '$')
      {
        current = 0;
        state = 'D';
      }
      else
      {
        switch (state)
        {
        case 'A':
          if (current < 7)
          {
            address[current] = value;
            current++;
          }
          break;
        case 'D':
          if (current < 7)
          {
            data[current] = value;
            current++;
          }
          break;
        }
      }
    }
  }
}
