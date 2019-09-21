#include <SoftwareSerial.h>
#include <EEPROM.h>

int DATO;
int FOCOS[] = {2,3,4,5};
uint8_t ESTADOS[] = {HIGH,LOW};
int Estado = 0;
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
    mySerial.begin(38400);
    mySerial.setTimeout(50);  
    for(int i = 0; i <= 4; i++){   
    pinMode(FOCOS[i],OUTPUT);
    digitalWrite(FOCOS[i],ESTADOS[EEPROM.get((i+1)*2,Estado)]);
  } 
}
void loop() { 
  if(mySerial.available()) {  
    
    DATO = String(mySerial.readString()).toInt();
    int F = DATO / 10;
    int E = DATO % 10;
    Estado = E;
    EEPROM.put((F+1)*2,Estado);
    digitalWrite(FOCOS[F],ESTADOS[E]);
  }
}
