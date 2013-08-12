/*
  MILO
 */
 
#include <Servo.h>           // Library for servos

//  PINS
const int ledBoardPin =  13;      // the number of the LED pin
const int ledPin = 12;
const int PIRPin = 8;
const int servoPin = 7;
const int buttonPin = 6;

//  Global
int alarmOn = 0;             // variable for reading the pushbutton status
Servo servo;                 // create servo object to control a servo 


/*******************
 * Setup
*******************/
void setup() {
  //SETUP INPUT PINS
  //pinMode(PIRPin, INPUT);         //Input pin for PIR Sensor 
  //pinMode(buttonPin, INPUT);      //Input pin for PIR Sensor
  
  //SETUP OUTPUT PINS
  pinMode(ledBoardPin, OUTPUT);        //Output pin for LED
  pinMode(ledPin, OUTPUT);        //Output pin for LED
  servo.attach(servoPin);      //Output pin for Servo 
  
  servo.writeMicroseconds(1500);

  //SETUP SERIAL
  Serial.begin(9600);
}


/********************
 * Loop
********************/

void loop(){  
  
  
  
   digitalWrite(ledBoardPin, LOW);
   delay(1000);
   digitalWrite(ledBoardPin, HIGH);
   delay(1000);
   
     char c;
  while(Serial.available()>0) {
    c = Serial.read();
    if(c == 't'){
      digitalWrite(ledPin, HIGH);
      delay(5000);
      digitalWrite(ledPin, LOW);
    }
    else if( c == 'r'){
      servo.writeMicroseconds(1550);
      delay(5000);
      Serial.print("open");
      //servo.writeMicroseconds(1500);
    }
    else if( c == 'l'){
      servo.writeMicroseconds(1450);
      delay(5000);
      Serial.print("open");

      //servo.writeMicroseconds(1500);
    }
    else if( c == 'c'){
      servo.writeMicroseconds(1500);
      delay(5000);
      Serial.print("close");

      //servo.writeMicroseconds(1500);
    }

  }
 
 /* if(digitalRead(buttonPin) == HIGH){
    servo.writeMicroseconds(1550);
  }
  else
  {
    servo.writeMicroseconds(1500);
  }
  

 
 */
 
  
  /*if(alarmOn == 0)
  {
    int PIRVal = digitalRead(PIRPin);
    if(PIRVal == HIGH)
    {
      Serial.write("PIR SENSOR: HIGH\n");
      Serial.write("ALARM HAS BEEN TRIGGERED!\n");
      alarmOn = 1;
    }
    else
    {
      Serial.write("PIR SENSOR: LOW\n");
    }
  }
  else
  {
    Serial.write("Please disable alarm within 15 seconds!\n");
    alarmOn = alarmOn + 1;
    if(alarmOn > 15)
    {
      Serial.write("Intruder Detected!\n");
    }
  }*/
  
  //delay(1000);
  
  
  
  
  
  
  /*
  SERVO CODE
  
  
  servo.writeMicroseconds(1550);
  delay(3000);
  servo.writeMicroseconds(1500);
  delay(3000);
  servo.writeMicroseconds(1450);
  delay(3000);
  servo.writeMicroseconds(1500);
  delay(3000);*/
  

}
