#include <SoftwareSerial.h>
#include <EEPROM.h>

char DATO = 0;
int FOCOS[] = {2,3,4,5};
uint8_t ESTADOS[] = {HIGH,LOW};
int ESTADO = 1;

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(38400);
  int i = 0;
  for(i = 0; i <= 4; i++){
    pinMode(FOCOS[i],OUTPUT);
  }
  digitalWrite(FOCOS[0],ESTADOS[EEPROM.get(1,ESTADO)]);
  digitalWrite(FOCOS[1],ESTADOS[EEPROM.get(3,ESTADO)]);
  digitalWrite(FOCOS[2],ESTADOS[EEPROM.get(5,ESTADO)]);
  digitalWrite(FOCOS[3],ESTADOS[EEPROM.get(7,ESTADO)]);
}

void loop() {
  if(mySerial.available()) {
    
    DATO = mySerial.read();
    int D = String(DATO).toInt();
    switch(D) {
      case 0:
      ESTADO = 0;
      EEPROM.put(1,ESTADO);
      digitalWrite(FOCOS[0],HIGH);
      break;
      case 1:
      ESTADO = 1;
      EEPROM.put(1,ESTADO);
      digitalWrite(FOCOS[0],LOW);
      break;
      case 2:
      ESTADO = 0;
      EEPROM.put(3,ESTADO);
      digitalWrite(FOCOS[1],HIGH);
      break;
      case 3:
      ESTADO = 1;
      EEPROM.put(3,ESTADO);
      digitalWrite(FOCOS[1],LOW);
      break;
      case 4:
      ESTADO = 0;
      EEPROM.put(5,ESTADO);
      digitalWrite(FOCOS[2],HIGH);
      break;
      case 5:
      ESTADO = 1;
      EEPROM.put(5,ESTADO);
      digitalWrite(FOCOS[2],LOW);
      break;
      case 6:
      ESTADO = 0;
      EEPROM.put(7,ESTADO);
      digitalWrite(FOCOS[3],HIGH);
      break;
      case 7:
      ESTADO = 1;
      EEPROM.put(7,ESTADO);
      digitalWrite(FOCOS[3],LOW);
      break;
    }
  }
}
