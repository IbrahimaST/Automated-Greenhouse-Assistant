#include <Servo.h>

Servo myServo;

const int potPin = A1;
const int potBright = A2;  // phototransistor
int redLed1 = 1;
int redLed2 = 2;
int buzzer = 8;
int servoAngle=0;
int potVal=0;
int threshold = 250;
int brightness = 0;
int threshold2 = 750;

void setup() {
myServo.attach(9);
pinMode(buzzer, OUTPUT);
pinMode(redLed1, OUTPUT);
pinMode(redLed2, OUTPUT);
Serial.begin(9600);
}
void fan() {
  myServo.write(179);
  delay(1000);
  myServo.write(0);
  delay(1000);
}

void loop() {
potVal = analogRead(potPin);
brightness = map(potVal, 0, 1023, 0, 255);
analogWrite(redLed1, brightness);
analogWrite(redLed2, brightness);
  while (analogRead(potBright) >= threshold2) {
  fan();
  }
  if(analogRead(potBright) >= threshold2) {        
     tone(buzzer, 440, 2500);
   }
   else if(analogRead(potBright) <= threshold2) {        
     tone(buzzer, 0, 1500);
   }
   if(analogRead(potBright) <= threshold) {        
     tone(buzzer, 440, 1500);
   }
   else if(analogRead(potBright) >= threshold) {        
     tone(buzzer, 0, 1500); // Act as alarms that get the attention of anybody nearby
   }
}
