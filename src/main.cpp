#include <Arduino.h>
#include <SPI.h>

//#define SCK 13
#define CS 10
//#define OUT 11
//#define IN 12

//#define WREN 6
//#define WRDI 4
//#define RDSR 5
//#define WRSR 1
#define READ 3
//#define WRITE 2


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

void debug_eeprom() {
  byte data = read_address(0x0);
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

void loop() {
  if (Serial.available()) {
    switch(Serial.read()) {
      case 'R':
        debug_eeprom();
        break;
      case 'P':
        print_eeprom();
        break;
    }
  }
}
