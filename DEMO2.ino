#include <SoftwareSerial.h>
#include <DFRobot_sim808.h>

#define PIN_TX 17
#define PIN_RX 16
SoftwareSerial mySerial(PIN_TX,PIN_RX);
DFRobot_SIM808 sim808(&mySerial);//Connect RX,TX,PWR,
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
  while(!sim808.init())
  {
      Serial.print("Sim808 init error\r\n");
      delay(1000);
  }
  delay(3000);
   Serial.println("SIM Init success");
  
}

void loop() {
  // put your main code here, to run repeatedly:
//Envíamos y recibimos datos
 if (Serial.available() > 0)
 mySerial.write(Serial.read());
 if (mySerial.available() > 0)
 Serial.write(mySerial.read());
}
