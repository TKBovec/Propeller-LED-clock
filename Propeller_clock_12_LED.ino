/*
  Propeller LED clock

  12 LED

Predelano po projektu:
 https://www.electricaltechnology.org/2022/02/usb-propeller-led-fan-clock-circuit.html

 1 notranja LED
 12 zunanja
*/
/*int LED1 = 2;   ni priklopljena, ker je kar na stalnem napajanju
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;           originalna konfiguracija
int LED6 = 7;
int LED7 = 8;
int LED8 = 9;
int LED9 = 10;
int LED10 = 11;
int LED11 = 12;
int LED12 = A1;

int sensorPin = A0;
*/

int LED2 = 10;       // Prestevilceno
int LED3 = 11;
int LED4 = 12;
int LED5 = 13;
int LED6 = A0;
int LED7 = A1;
int LED8 = A2;
int LED9 = A3;
int LED10 = A4;
int LED11 = A5;
int LED12 = 8;

int sensorPin = 9;

//int minuteSensor = A7;
//int hourSensor = A6;

unsigned int n,ADCvalue,propeller_posn=0;
unsigned long previousTime = 0;

byte hours = 12; // set hours
byte minutes = 00; // set minutes
byte seconds = 00; // set seconds

int val;

void setup() {
Serial.begin(9600);  
//pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);
pinMode(LED5,OUTPUT);
pinMode(LED6,OUTPUT);
pinMode(LED7,OUTPUT);
pinMode(LED8,OUTPUT);
pinMode(LED9,OUTPUT);
pinMode(LED10,OUTPUT);
pinMode(LED11,OUTPUT);
pinMode(LED12,OUTPUT);

pinMode(sensorPin,INPUT_PULLUP);

if(hours == 12)
hours = 0;

//****************************************
// Uncomment these lines for IR sensor testing
/*
Serial.begin(9600);

while(1)
{
ADCvalue = analogRead(minuteSensor);
Serial.print(“minuteSensor “);
Serial.println(ADCvalue);

ADCvalue = analogRead(hourSensor);
Serial.print(“hourSensor “);
Serial.println(ADCvalue);

Serial.println();
delay(1000);
*/
}



void loop() {
  {
  val = digitalRead(sensorPin); // hall senzor odcitek
  while (val == HIGH)
  {
  //Serial.println("HALL OFF");
  val = digitalRead(sensorPin);
  }
// ko gre hall na LOW, poveča za 1 sekundo
  //Serial.println("HALL ON");
  if (millis() >= (previousTime))
  {
  previousTime = previousTime + 1000;
  seconds = seconds+1;
  Serial.println(seconds);
  //Serial.println("Hall");
  if (seconds == 60)
  {
  seconds = 0;
  minutes = minutes+1;
  }
  if (minutes == 60)
  {
  minutes = 0;
  hours = hours+1;
  }
  if (hours == 12)
  {
  hours = 0;
  }
  }

/*
  propeller_posn=30;
  n=0;

  while(n < 60)
  {

  //ADCvalue = analogRead(minuteSensor);
  if(ADCvalue < 500)
  {
  minutes = propeller_posn;
  seconds = 0;
  }

  //ADCvalue = analogRead(hourSensor);
  if(ADCvalue < 500)
  {
  hours = propeller_posn/5;
  seconds = 0;
  }
  }
  */
  drawMinuteMarker();

  if ((propeller_posn==0) || (propeller_posn==5) || (propeller_posn==10) || (propeller_posn==15) || (propeller_posn==20) || (propeller_posn==25) || (propeller_posn==30) || (propeller_posn==35) || (propeller_posn==40) || (propeller_posn==45) || (propeller_posn==50) || (propeller_posn==55))
  drawHourMarker();

  if ((propeller_posn==0) || (propeller_posn==15) || (propeller_posn==30) || (propeller_posn==45))
  drawQuarterMarker();

  if((propeller_posn == hours*5) || (( propeller_posn == 0 ) && (hours == 0)))
  drawHoursHand();

  if(propeller_posn == minutes)
  drawMinutesHand();

  if(propeller_posn == seconds)
  drawSecondsHand();

  delayMicroseconds(100); // for LED pixel width (change the value according to motor speed. Increase for low speed, decrease for high speed motor)

  displayClear();

  drawInner_Circle();

  delayMicroseconds(450); // for the gap between LED pixels/minutes markers (change the value according to motor speed. Increase for low speed, decrease for high speed motor)

  n++;
  propeller_posn++;
  if(propeller_posn == 60)
  propeller_posn=0;
  }

  val = digitalRead(sensorPin);

  while (val == HIGH)
  {
  val = digitalRead(sensorPin);
  }
  }

  //======= PODPROGRAMI ============

  void displayClear()
  {
  //digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  digitalWrite(LED6,LOW);
  digitalWrite(LED7,LOW);
  digitalWrite(LED8,LOW);
  digitalWrite(LED9,LOW);
  digitalWrite(LED10,LOW);
  digitalWrite(LED11,LOW);
  digitalWrite(LED12,LOW);
  }

  void drawMinuteMarker()
  {
  digitalWrite(LED12,HIGH);
  }

  void drawHourMarker()
  {
  digitalWrite(LED10,HIGH);
  digitalWrite(LED11,HIGH);
  }

  void drawQuarterMarker()
  {
  digitalWrite(LED9,HIGH);

  }

  void drawHoursHand()
  {
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,HIGH);

  }

  void drawMinutesHand()
  {
  
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,HIGH);
  digitalWrite(LED6,HIGH);
  digitalWrite(LED7,HIGH);

  }

  void drawSecondsHand()
  {
 
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,HIGH);
  digitalWrite(LED6,HIGH);
  digitalWrite(LED7,HIGH);
  digitalWrite(LED8,HIGH);

  }

  void drawInner_Circle()
    {
    //digitalWrite(LED1,HIGH);
    delayMicroseconds(30);
    //digitalWrite(LED1,LOW);
    }  
    


