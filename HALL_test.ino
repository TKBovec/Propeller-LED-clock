/*
  HALL senzor test

  Senzor na D9

Predelano po projektu:
 https://www.electricaltechnology.org/2022/02/usb-propeller-led-fan-clock-circuit.html

 1 notranja LED
 12 zunanja
*/

int LED12 = A5;

int sensorPin = 9;

int val = 0;

void setup() {
  Serial.begin(9600);  

  pinMode(LED12,OUTPUT);

  pinMode(sensorPin,INPUT_PULLUP);
}


void loop() {
  {
  val = digitalRead(sensorPin); // hall senzor odcitek
  Serial.println(val);
  if (val==0) 
    digitalWrite(LED12,HIGH);
  else
    digitalWrite(LED12,LOW);
 
  }
}