//Libraries
#include <AFMotor.h>
#include <Servo.h>

//motor pins
int enA = 3;
int in1 = 8;
int in2 = 9;
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// create servo object to control a servo
Servo arm1;  
Servo arm2;

//variable created to store the incoming value
String Incoming_value = " ";

//speaker control & pins
int spk1 = 5;
int spk2 = 6;
bool speak = false;

//position of either arms
int pos;
int pos1;

void setup(){
  Serial.begin(9600);
  mouth();
  arm();
  leg();      
}

void loop() {
  //turning off the speaker
  if(speak == false){
    digitalWrite(spk1, HIGH);
    digitalWrite(spk2, HIGH);
  }

  //checking if the input is coming or not if input zero the program stops
  if(Serial.available()>0){
    Incoming_value = Serial.readString();//reading the incoming value from hc-05 module
    Serial.print(Incoming_value);
    Serial.print("\n");
    
    //checking each inputs and coordinate with code writen for the incoming comand
    //Motor control
    if(Incoming_value == "FORWARD")
      forward();
    else if(Incoming_value == "BACKWARD")
      backward();
    else if(Incoming_value =="RIGHT")
      right();
    else if(Incoming_value == "LEFT")
      left();
    else if(Incoming_value == "STOP")
      allstop();

    //Speaker controls
    else if(Incoming_value == "SPEAK1"){
      digitalWrite(spk1, LOW);
      delay(100); // is according to the time duration we are saving the audio here its 1min 
      speak = false;
    }
    else if(Incoming_value == "SPEAK2"){
      digitalWrite(spk2, LOW);
      delay(100); // is according to the time duration we are saving the audio here its 1min 
      speak = false;
    }
  
    //arms control
    else if(Incoming_value == "LIFT_R"){
      for (pos = 13; pos <= 100; pos += 1)  // goes from 13 degrees to 100 degree
        arm1.write(pos); 
    }
    else if(Incoming_value == "LIFT_L"){
      for (pos1 = 180; pos1 >= 0; pos1 -= 1)  // goes from 180 degrees to 0 degrees
        arm2.write(pos1); 
    }
    else if(Incoming_value == "LIFT_B"){
      for (pos = 13; pos <= 65; pos += 1) { // goes from 13 degrees to 65 degree
        arm1.write(pos);        // tell servo to go to position in variable 'pos'

        for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
          arm2.write(pos1);
          break;
        } 
      }
      for (pos1 = 180; pos1 >= 0; pos1 -= 1)  // goes from 180 degrees to 0 degrees
        arm2.write(pos1); 
    }
    else if(Incoming_value == "DOWN_R"){
      for (pos = 100; pos >= 13; pos -= 1) { // goes from 100 degrees to 13 degrees
       arm1.write(pos);
       delay(15);
      }   
    }
    else if(Incoming_value == "DOWN_L"){
      for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
        arm2.write(pos1);  
        delay(15);
      }
    }
    else if(Incoming_value == "DOWN_B"){
      for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
        arm2.write(pos1);  
        delay(15);
      }
      for (pos = 65; pos >= 13; pos -= 1) { // goes from 65 degrees to 13 degrees
       arm1.write(pos);
       delay(15); 
       }
      }
    }
  }

//Motion control functions
void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD) ;
  motor4.run(BACKWARD) ;
}

void left(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void right(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
void allstop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  motor2.run(RELEASE);
  motor3.run(RELEASE)  ;
  motor4.run(RELEASE)  ;
}
void arm(){
  //pin number attached
  arm1.attach(9) ;
  arm2.attach(10);  
  //mean position
  arm1.write(13); 
  arm2.write(180);
}
void leg(){
  pinMode(enA, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(enA, 255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE); 
}
void mouth(){
  pinMode(spk1, OUTPUT);
  pinMode(spk2, OUTPUT);
}

//******************* THE END *******************//
//************** 153 lines of code **************//