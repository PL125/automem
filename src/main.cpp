#include <Arduino.h>
#include <SPI.h>

//#define SCK 13
#define CS 10
//#define OUT 11
//#define IN 12

#define WREN 6
//#define WRDI 4
//#define RDSR 5
//#define WRSR 1
#define READ 0x03
#define WRITE 0x02


byte read_address(int address)
{ 
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  
  digitalWrite(CS, LOW);
  
  //SPI.transfer(0);
  SPI.transfer(READ);
  //SPI.transfer(address >> 16);
  SPI.transfer(address >> 8);
  SPI.transfer(address);
  //byte data = highByte(address);
  //data = data << 3;
  //data = data | 0x03;
  
  //SPI.transfer(data);
  //SPI.transfer(lowByte(address));

  byte result = SPI.transfer(0);
   
  digitalWrite(CS, HIGH); 
  
  SPI.endTransaction();
  
  return result;
}

void write_address(int address, byte data)
{
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  
  digitalWrite(CS, LOW);
  SPI.transfer(WREN);
  digitalWrite(CS, HIGH);

  digitalWrite(CS, LOW);
  
  //SPI.transfer(0);
  SPI.transfer(WRITE);
  //SPI.transfer(address >> 16);
  SPI.transfer(address >> 8);
  SPI.transfer(address);
  //byte data = highByte(address);
  //data = data << 3;
  //data = data | 0x03;
  
  //SPI.transfer(data);
  //SPI.transfer(lowByte(address));

  SPI.transfer(data);
   
  digitalWrite(CS, HIGH); 
  
  SPI.endTransaction();
}

void debug_eeprom(int address) {
  byte data = read_address(address);
  char buf[128];
  sprintf(buf, " 0x%02X ", data);
  Serial.print(buf);
}

void print_eeprom() {
  char buf[128];

  read_address(0x0);

  for(int i=0; i<4096;i++) {
    if((i&15)==0) {
      sprintf(buf, "\n0x%03X: ", i);
      Serial.print(buf);
    }

    //byte data = read_address(i);
    
    sprintf(buf, " 0x%02X: ", read_address(i));
    Serial.print(buf);
  }

  delay(5000);
}

void setup() {
  Serial.begin(9600);

  //SPI.setBitOrder(MSBFIRST);
  //SPI.setDataMode(SPI_MODE0);
  //SPI.setClockDivider(SPI_CLOCK_DIV2);
  SPI.begin();


//  pinMode(OUT, OUTPUT);
//  pinMode(IN, INPUT);
//  pinMode(SCK, OUTPUT);
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);

  delay(1000);

  //debug_eeprom();
  //print_eeprom();
}

char state = 'W';
char option;
char address[8];
char data[8];
int current = 0;
void loop() {

  if (Serial.available()) {
    char value = Serial.read();

    if(state == 'W') {

      for(int i=0; i<8; i++) address[i] = 0;
      for(int i=0; i<8; i++) data[i] = 0;

      option = value;
      state = 'A';
    }

    if(value == '#') {
      switch(option) {
        case 'R':
          debug_eeprom((int)strtol(address, NULL, 16));
          break;
        case 'P':
          print_eeprom();
          break;
        case 'W':
          write_address((int)strtol(address, NULL, 16), (int)strtol(data, NULL, 16));
          break;
        default:
          Serial.println("Opção inválida");
      }

      current = 0;
      state = 'W';
    } else if (value == ',')  {
      state = 'D';
      current = 0;
    }
    else {
      if(current < 7) {
        switch(state) {
          case 'A':
            address[current] = value;
            break;
          case 'D':
            data[current] = value;
            break;
        }
        
        current++;
      }
    }
  }
}
