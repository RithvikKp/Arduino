//Is the program to control the eyes of the robot using a set of servo motor 

//Eye test
#include <Servo.h>
Servo lid1;
Servo lid2;
Servo ball1;
Servo ball2;
int pos;
int r = 0;
void setup() {
  lid1.attach(8);
  lid2.attach(9);
  ball1.attach(10);
  ball2.attach(11);

  lid1.write(0);
  lid2.write(0);
  ball1.write(45);
  ball2.write(45);
  
}
void loop() {  
  if (r == 1) {
    //Look left
    for (pos = 45; pos <= 90; pos += 1) {
      ball1.write(pos);
      ball2.write(pos);
      delay(20);
    }
    for (pos =90; pos >= 45; pos -= 1) {
      ball1.write(pos);
      ball2.write(pos);
      delay(20);
    }
    delay(300);
    //Look right
    for (pos = 45; pos >= 8; pos -= 1) {
      ball1.write(pos);
      ball2.write(pos);
      delay(20);
    }
    for (pos = 8; pos <= 45; pos += 1) {
      ball1.write(pos);
      ball2.write(pos);
      delay(20);
    }
    r=0;
  }
  r+=1;
  
//Lid controlling
  lid1.write(0);
  lid2.write(0);
  delay(200);
  lid1.write(90);
  lid2.write(90);
  delay(500);
  
}
