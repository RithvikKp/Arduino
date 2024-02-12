//motor test
#include <AFMotor.h>
int enA = 3;
int in1 = 8;
int in2 = 9;
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // turn on motor
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

void loop() { 
  forward();
  delay(3000);
  backward();
  delay(3000);
  right();
  delay(3000);
  left();
  delay(3000);
  allstop();
  delay(3000);
}
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
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void right(){
  digitalWrite(8, LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  
}
void left(){
  digitalWrite(8, HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
void allstop(){
  digitalWrite(8, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
