

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <MPR121.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)
#define BUTTON_PIN 7

  // our servo # counter
  uint8_t servonum = 0;

  int turns = 200; // how fast the motor runs
  
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  randomSeed(analogRead(A0));
  pinMode(5, OUTPUT); // Milk pump

  
// CAPACITIVE
if(!MPR121.begin(0x5A)){ 
    Serial.println("error setting up MPR121");  
    switch(MPR121.getError()){
      case NO_ERROR:
        Serial.println("no error");
        break;  
      case ADDRESS_UNKNOWN:
        Serial.println("incorrect address");
        break;
      case READBACK_FAIL:
        Serial.println("readback failure");
        break;
      case OVERCURRENT_FLAG:
        Serial.println("overcurrent on REXT pin");
        break;      
      case OUT_OF_RANGE:
        Serial.println("electrode out of range");
        break;
      case NOT_INITED:
        Serial.println("not initialised");
        break;
      default:
        Serial.println("unknown error");
        break;      
    }
    while(1);
  }
  
  // pin 4 is the MPR121 interrupt on the Bare Touch Board
  MPR121.setInterruptPin(4);

  // this is the touch threshold - setting it low makes it more like a proximity trigger
  // default value is 40 for touch
  MPR121.setTouchThreshold(40);
  
  // this is the release threshold - must ALWAYS be smaller than the touch threshold
  // default value is 20 for touch
  MPR121.setReleaseThreshold(20);  

  // initial data update
  MPR121.updateTouchData();
}

void loop(){
  int random_1 = random(0,3); 
  int random_2 = random(3,6);
  int random_3 = random(6,9);

//  int button_state = digitalRead(BUTTON_PIN);
//  if (!button_state){
//      Serial.println("ON");

if(MPR121.touchStatusChanged()){
  MPR121.updateTouchData();
    
      if(MPR121.isNewTouch(4)){
        Serial.print("electrode ");
        Serial.print(4, DEC);
        Serial.println(" was just touched"); 
  
  
  //PICKLES
   if (random_1 == 0 ) {
      Serial.print(random_1);
      Serial.print(" ");  
      Serial.println("pickles"); 
  
      pwm.setPWM(0, 0, 350 );  
      delay(1500);
      pwm.setPWM(0, 0, 125 );
      delay(1500);
    }
    
  //OATMEAL_1
    else if((random_1 == 1) && (random_2 == 3) && (random_3 == 6) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("oatmeal");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("banana");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("chocolate chips");
      Serial.print(" ");
  
      pwm.setPWM(1, 0, 350 ); 
      pwm.setPWM(3, 0, 350 );
      pwm.setPWM(6, 0, 350 ); 
      delay(1500);
      pwm.setPWM(1, 0, 125 );
      pwm.setPWM(3, 0, 125 );
      pwm.setPWM(6, 0, 125 );
      delay(1500);
      analogWrite(5, turns); //Milk Milk Milk                       
    }
    
  //OATMEAL_2
    else if((random_1 == 1) && (random_2 == 3) && (random_3 == 7) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("oatmeal");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("banana");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("almonds");
      Serial.print(" ");
  
      pwm.setPWM(1, 0, 350 ); 
      pwm.setPWM(3, 0, 350 );
      pwm.setPWM(7, 0, 350 ); 
      delay(1500);
      pwm.setPWM(1, 0, 125 );
      pwm.setPWM(3, 0, 125 );
      pwm.setPWM(7, 0, 125 );
      delay(1500);
      analogWrite(5, turns); //Milk Milk Milk
                              
    }   
  
  //OATMEAL_3
    else if((random_1 == 1) && (random_2 == 3) && (random_3 == 8) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("oatmeal");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("banana");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("coconut");
      Serial.print(" ");
  
      pwm.setPWM(1, 0, 350 ); 
      pwm.setPWM(3, 0, 350 );
      pwm.setPWM(15, 0, 350 ); 
      delay(1500);
      pwm.setPWM(1, 0, 125 );
      pwm.setPWM(3, 0, 125 );
      pwm.setPWM(15, 0, 125 );
      delay(1500);
      analogWrite(5, turns); //Milk Milk Milk
                              
    } 
  
  //OATMEAL_4
  else if((random_1 == 1) && (random_2 == 4) && (random_3 == 6) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("oatmeal");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("apple");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("chocolate chips");
      Serial.print(" ");
  
      pwm.setPWM(1, 0, 350 ); 
      pwm.setPWM(4, 0, 350 );
      pwm.setPWM(6, 0, 350 ); 
    delay(1500);
      pwm.setPWM(1, 0, 125 );
      pwm.setPWM(4, 0, 125 );
      pwm.setPWM(6, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }   
  
  //OATMEAL_5
  else if((random_1 == 1) && (random_2 == 4) && (random_3 == 7) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("oatmeal");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("apple");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("almond");
      Serial.print(" ");
  
      pwm.setPWM(1, 0, 350 ); 
      pwm.setPWM(4, 0, 350 );
      pwm.setPWM(7, 0, 350 ); 
    delay(1500);
      pwm.setPWM(1, 0, 125 );
      pwm.setPWM(4, 0, 125);
      pwm.setPWM(7, 0, 125);
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }   
  
  //OATMEAL_6
  else if((random_1 == 1) && (random_2 == 4) && (random_3 == 8) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("oatmeal");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("apple");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("coconut");
      Serial.print(" ");
  
      pwm.setPWM(1, 0, 350 ); 
      pwm.setPWM(4, 0, 350 );
      pwm.setPWM(15, 0, 350 ); 
    delay(1500);
      pwm.setPWM(1, 0, 125 );
      pwm.setPWM(4, 0, 125 );
      pwm.setPWM(15, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    } 
  
  //OATMEAL_7
  else if((random_1 == 1) && (random_2 == 5) && (random_3 == 6) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("oatmeal");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("berries");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("chocolate chips");
      Serial.print(" ");
  
      pwm.setPWM(1, 0, 350 ); 
      pwm.setPWM(5, 0, 350 );
      pwm.setPWM(6, 0, 350 ); 
    delay(1500);
      pwm.setPWM(1, 0, 125 );
      pwm.setPWM(5, 0, 125 );
      pwm.setPWM(6, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }   
  
  //OATMEAL_8
  else if((random_1 == 1) && (random_2 == 5) && (random_3 == 7) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("oatmeal");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("berries");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("almond");
      Serial.print(" ");
  
      pwm.setPWM(1, 0, 350 ); 
      pwm.setPWM(5, 0, 350 );
      pwm.setPWM(7, 0, 350 ); 
    delay(1500);
      pwm.setPWM(1, 0, 125 );
      pwm.setPWM(5, 0, 125 );
      pwm.setPWM(7, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }   
  
  //OATMEAL_9
  else if((random_1 == 1) && (random_2 == 5) && (random_3 == 8) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("oatmeal");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("berries");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("coconut");
      Serial.print(" ");
  
      pwm.setPWM(1, 0, 350 ); 
      pwm.setPWM(5, 0, 350 );
      pwm.setPWM(15, 0, 350 ); 
    delay(1500);
      pwm.setPWM(1, 0, 125 );
      pwm.setPWM(5, 0, 125 );
      pwm.setPWM(15, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }   
    
  //CORNFLAKES_1
  else if((random_1 == 2) && (random_2 == 3) && (random_3 == 6) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("cornflakes");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("banana");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("chocolate chips");
      Serial.print(" ");
  
      pwm.setPWM(2, 0, 350 ); 
      pwm.setPWM(3, 0, 350 );
      pwm.setPWM(6, 0, 350 ); 
    delay(1500);
      pwm.setPWM(2, 0, 125 );
      pwm.setPWM(3, 0, 125 );
      pwm.setPWM(6, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }
  
   //CORNFLAKES_2
  else if((random_1 == 2) && (random_2 == 3) && (random_3 == 7) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("cornflakes");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("banana");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("almonds");
      Serial.print(" ");
  
      pwm.setPWM(2, 0, 350 ); 
      pwm.setPWM(3, 0, 350 );
      pwm.setPWM(7, 0, 350 ); 
    delay(1500);
      pwm.setPWM(2, 0, 125 );
      pwm.setPWM(3, 0, 125 );
      pwm.setPWM(7, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    } 
  
  //CORNFLAKES_3
  else if((random_1 == 2) && (random_2 == 3) && (random_3 == 8) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("cornflakes");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("banana");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("coconut");
      Serial.print(" ");
  
      pwm.setPWM(2, 0, 350 ); 
      pwm.setPWM(3, 0, 350 );
      pwm.setPWM(15, 0, 350 ); 
    delay(1500);
      pwm.setPWM(2, 0, 125 );
      pwm.setPWM(3, 0, 125 );
      pwm.setPWM(15, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    } 
  
  //CORNFLAKES_4
  else if((random_1 == 2) && (random_2 == 4) && (random_3 == 6) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("cornflakes");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("apple");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("chocolate chips");
      Serial.print(" ");
  
      pwm.setPWM(2, 0, 350 ); 
      pwm.setPWM(4, 0, 350 );
      pwm.setPWM(6, 0, 350 ); 
    delay(1500);
      pwm.setPWM(2, 0, 125 );
      pwm.setPWM(4, 0, 125 );
      pwm.setPWM(6, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }   
  
  //CORNFLAKES_5
  else if((random_1 == 2) && (random_2 == 4) && (random_3 == 7) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("cornflakes");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("apple");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("almond");
      Serial.print(" ");
  
      pwm.setPWM(2, 0, 350 ); 
      pwm.setPWM(4, 0, 350 );
      pwm.setPWM(7, 0, 350 ); 
    delay(1500);
      pwm.setPWM(2, 0, 125 );
      pwm.setPWM(4, 0, 125 );
      pwm.setPWM(7, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }   
  
  //CORNFLAKES_6
  else if((random_1 == 2) && (random_2 == 4) && (random_3 == 8) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("cornflakes");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("apple");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("coconut");
      Serial.print(" ");
  
      pwm.setPWM(2, 0, 350 ); 
      pwm.setPWM(4, 0, 350 );
      pwm.setPWM(15, 0, 350 ); 
    delay(1500);
      pwm.setPWM(2, 0, 125 );
      pwm.setPWM(4, 0, 125 );
      pwm.setPWM(15, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    } 
  
  //CORNFLAKES_7
  else if((random_1 == 2) && (random_2 == 5) && (random_3 == 6) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("cornflakes");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("berries");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("chocolate chips");
      Serial.print(" ");
  
      pwm.setPWM(2, 0, 350 ); 
      pwm.setPWM(5, 0, 350 );
      pwm.setPWM(6, 0, 350 ); 
    delay(1500);
      pwm.setPWM(2, 0, 125 );
      pwm.setPWM(5, 0, 125 );
      pwm.setPWM(6, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }   
  
  //CORNFLAKES_8
  else if((random_1 == 2) && (random_2 == 5) && (random_3 == 7) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("cornflakes");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("berries");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("almond");
      Serial.print(" ");
  
      pwm.setPWM(2, 0, 350 ); 
      pwm.setPWM(5, 0, 350 );
      pwm.setPWM(7, 0, 350 ); 
    delay(1500);
      pwm.setPWM(2, 0, 125 );
      pwm.setPWM(5, 0, 125 );
      pwm.setPWM(7, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }   
  
  //CORNFLAKES_9
  else if((random_1 == 2) && (random_2 == 5) && (random_3 == 8) )  {
  
      Serial.print(random_1);
      Serial.print(" ");
      Serial.print("cornflakes");
      Serial.print(" ");
      Serial.print(random_2);
      Serial.print(" ");
      Serial.println("berries");
      Serial.print(" ");
      Serial.print(random_3);
      Serial.print(" ");
      Serial.println("coconut");
      Serial.print(" ");
  
      pwm.setPWM(2, 0, 350 ); 
      pwm.setPWM(5, 0, 350 );
      pwm.setPWM(15, 0, 350 ); 
    delay(1500);
      pwm.setPWM(2, 0, 125 );
      pwm.setPWM(5, 0, 125 );
      pwm.setPWM(15, 0, 125 );
    delay(1500);
    analogWrite(5, turns); //Milk Milk Milk
                              
    }   
  
  }

  else {
    Serial.print("Not getting into the loop");
    }
  }
}
