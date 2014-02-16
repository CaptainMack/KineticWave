#include <Bridge.h>
#include <SpacebrewYun.h>
#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(10, 11);
 
// RF
int analogIn = 0;
int analogValue = 0;
int pinLed = 13;
int cnt;
double referenceVoltage = 0;
 
// Spacebrew
SpacebrewYun sb = SpacebrewYun("KINETICWAVE.io", "A shape-changing sculpture.");
 
void setup(){
  //delay(10000);
 
  Serial.begin(19200);
 
   mySerial.begin(19200);
   //mySerial.setTimeout(2000);
 
  pinMode(pinLed,OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
 
  Bridge.begin();
 
  sb.verbose(true);
  sb.addPublish("RF", "string");
  sb.addPublish("positions", "string");
 
  sb.addSubscribe("instruction", "range");
  sb.connect("kineticwave.io", 5000);
}
 
void loop(){
 
  mySerial.flush();
 
  sb.monitor();
  sb.onRangeMessage(receivedRange);
 
  analogValue=0;
  for (cnt=0;cnt< 100;cnt++) {
    digitalWrite(pinLed,1);
    analogIn=analogRead(2);
    digitalWrite(pinLed,0);
    if (analogIn > analogValue) analogValue=analogIn;
    delayMicroseconds(100);
 
  }
 
  double voltage = analogValue * (5.0 / 1023.0);
 
  if (voltage > referenceVoltage) {
    if (voltage-referenceVoltage > 0.05) {
      if (sb.connected()) {
        sb.send("RF", String(voltage));
      }
    }
  }
  else if (referenceVoltage > voltage) {
    if (referenceVoltage-voltage > 0.05) {
      if (sb.connected()) {
        sb.send("RF", String(voltage));
      }
    }
  }    
 
  referenceVoltage = voltage;
 
  String json;
 
  if (mySerial.available()) {
    json = mySerial.readStringUntil('\n');
    sb.send("positions", json);
    //Serial.println(json);
    //Serial.println(mySerial.overflow());
  }  
 
  //delay(500);
}
 
void receivedRange(String name, int value){
  if (name == "instruction") {
    mySerial.print(value);
  }
}
