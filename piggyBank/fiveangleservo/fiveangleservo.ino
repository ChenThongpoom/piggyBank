#include <Servo.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

int prevred = 0;
int prevblue = 0;
int prevgreen = 0;
int pass = 0;
int rdif = 0;
int gdif = 0;
int bdif = 0;
int given = 0;

#define redpin 3
#define greenpin 5
#define bluepin 6
 
#define commonAnode true
 
 
byte gammatable[256];
 
 
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);


Servo myservo;


void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(redpin, OUTPUT);  
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  tcs.begin(); 
  
  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;
      
    if (commonAnode) {
      gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;      
    }
    //Serial.println(gammatable[i]);
  }
}

void loop() {
    //colorSensor();

    if (Serial.available())
  {
      int c = Serial.read() -48;  //gets one byte from serial buffer
//      //makes the string readString=
     
    if (c==9){
     servo90();
    }
    if (c==2){
     servo20();
    }
    if (c==5){
      servo50();
    }
    if (c==7){
      servo120();
    }
    if (c==8){
      servo150();
    }
    if (c==6){
      colorSensor();
    }
    if (c==0){
      reset();
    }

  }

  
}

void reset(){
  given = 0;
}  


void colorSensor(){
  //Serial.println("");
  uint16_t clear, red, green, blue;
 
  tcs.setInterrupt(false);      // turn on LED
 
  delay(10);  
  
  tcs.getRawData(&red, &green, &blue, &clear);
 
  tcs.setInterrupt(true);  
//  Serial.println("");
//  Serial.print(" C: "); Serial.print(clear);
//  Serial.print(" R: "); Serial.print(red);
//  Serial.print(" G: "); Serial.print(green);
//  Serial.print(" B: "); Serial.print(blue);
//  
 
  // Figure out some basic hex code for visualization
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
//  Serial.print("\t");
//  Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
//  Serial.println();
  rdif = (-1)*(prevred - r);
  gdif = (-1)*(prevgreen - g);
  bdif = (-1)*(prevblue -b);
  prevred = r;
  prevgreen = g;
  prevblue = b;
  
  if(rdif >= 5 or gdif >= 5 or bdif >= 5){
     pass += 1;
     given = (pass-1)/2;
  }
  //Serial.println(pass);
  Serial.println(given);
 
}  
  

void servo90(){
    myservo.write(90);
}

void servo20(){
    myservo.write(25);
      
}

void servo50(){
  myservo.write(50);

}

void servo120(){
  myservo.write(120);

}

void servo150(){
  myservo.write(150);

}
