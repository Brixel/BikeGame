#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 

const int foutPin = 12;
const int resetPin = 11;
const int fietsPin = 10;
int resetButtonState = 0;
int foutButtonState = 0;
int previousFoutButtonState = 0;
int fietsButtonState = 0;
int previousFietsButtonState = 0;

 
int pos = 0;    // variable to store the servo position 
int minVal= 90;
int maxVal= 180;
int beginVal = 180;
long previousMillis = 0;
long interval = 1000;


long previousDegrateMillis = 0;
long degrateInterval = 120;
 
void setup() 
{ 
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object 
  pos = beginVal;
  myservo.write(pos);  
} 
 
 
void loop() 
{ 
  resetButtonState = digitalRead(resetPin);
  foutButtonState = digitalRead(foutPin);
  fietsButtonState = digitalRead(fietsPin);
  
  if(resetButtonState){
    pos = beginVal;
  }
    
  if(previousFoutButtonState == 0){
    if(foutButtonState){
      previousFoutButtonState = 1;
      if(pos+10 <= maxVal){
        pos += 10;
      }
      
    }
  } else {
    if(foutButtonState == 0){
      previousFoutButtonState = 0;
    }
  }
  
  if(previousFietsButtonState == 0){
    if(fietsButtonState){
      previousFietsButtonState = 1;
      if(pos-10 >= minVal){
        pos -= 10;
      }
      
    }
  } else {
    if(fietsButtonState == 0){
      previousFietsButtonState = 0;
    }
  }
  
  
  unsigned long currentMillis = millis();
  
  
  if(currentMillis - previousDegrateMillis > degrateInterval){
    previousDegrateMillis = currentMillis;
    if(pos < maxVal){  
      pos++;
    }

  }
      
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
  }
  
  myservo.write(pos);
  
} 
