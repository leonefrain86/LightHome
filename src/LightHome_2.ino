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

void prender(int numFoco){
  ESTADO = 0;
  EEPROM.put(numFoco*2+1,ESTADO);
  digitalWrite(FOCOS[numFoco],HIGH);
}

void apagar(int numFoco){
  ESTADO = 1;
  EEPROM.put(numFoco*2+1,ESTADO);
  digitalWrite(FOCOS[numFoco],LOW);
}

void loop() {
  if(mySerial.available()) {
    
    DATO = mySerial.read();
    int D = String(DATO).toInt();
    int numFoco = D / 2;
    if(D % 2 == 0){
      prender(numFoco);
    }else{
      apagar(numFoco);
    }
  }
}
