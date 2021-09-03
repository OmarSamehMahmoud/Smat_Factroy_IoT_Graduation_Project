
#include <HX711.h>
#include <Servo.h>


// HX711.DOUT  - pin #A1

// HX711.PD_SCK - pin #A0

const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;  

int servoPin1 = 5;
int servoPin2 = 3;
int servoPin3 = 6;

Servo Servo1,Servo2,Servo3;

   
int red = 0;  
int green = 0;  
int blue = 0; 
 
int sensor = 4;
int val;


HX711 scale(A1, A0);
float read_ADC;
float read_load;
float read_average;

void setup() {
Serial.begin(38400);
 
  
 pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH); 

   
 
  scale.set_scale(400.f); // this value is obtained by calibrating the scale with known weights
 scale.tare();               // reset the scale to 0

  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
 Servo3.attach(servoPin3);
}



void loop() {

  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
 
  val = digitalRead(4);
  read_ADC   =   scale.read();
 read_load   =    scale.get_units();
  Servo1.write(0);
  Servo2.write(0);
  Servo3.write(0);
 if (green < red && green < blue)  
  {  
     Serial.println(" - (Green Color)"); 
   Servo2.write(50);
     delay(2000);
//     Make servo go to 100 degrees
    Servo2.write(0);
     delay(2000);
  } 

if (val != HIGH)
 {
    Serial.println("Water Detect");
  // Make servo go to 90 degrees
  Servo1.write(50);
  delay(2000);
    // Make servo go to 0 degrees
  Servo1.write(0);
  delay(2000);
}



if(scale.get_units()>125&&   scale.get_units()<200)
 {
  Serial.println("Weight detect");
  Servo3.write(50);
  delay(2000);
 //  Make servo go to 0 degrees
  Servo3.write(0);
   delay(2000);
  }
  
}
