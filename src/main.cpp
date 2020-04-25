#include <Arduino.h>

#include "arch/e95xx.h"
#include "misc/i4gv.h"


E95xx e(4096);


void debug_eeprom(int address) {
  uint8_t data = e.read(address);
  char buf[128];
  sprintf(buf, " 0x%02X ", data);
  Serial.print(buf);
}


void setup() {
  Serial.begin(9600);

  e.setup();

}

char state = 'W';
char option;
char address[8];
char data[8];
int current = 0;
uint16_t code;
void loop() {

  if (Serial.available()) {
    char value = Serial.read();

    if(state == 'W') {

      for(int i=0; i<8; i++) address[i] = 0;
      for(int i=0; i<8; i++) data[i] = 0;
      current = 0;

      option = value;
      state = 'A';
    } else {

      if(value == '#') {
        switch(option) {
          case 'R':
            debug_eeprom((int)strtol(address, NULL, 16));
            //code = I4gv::getImmoCode(&e);
            //Serial.println(code);
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
      } else if (value == '$')  {
        current = 0;
        state = 'D';
      }
      else {
          switch(state) {
            case 'A':
              if(current < 7) {
                address[current] = value;
                current++;
              }
              break;
            case 'D':
              if(current < 7) {
                data[current] = value;
                current++;
              }
              break;
          }
      }
    }
  }
}
