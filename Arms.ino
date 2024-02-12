//Is the program to test the control of the arms of the robot using a servo motor and coordination with the Android app

#include <Servo.h>

Servo arm1;  // create servo object to control a servo
Servo arm2;

int pos ;
int pos1;

void setup() {
  arm1.attach(9);
  arm2.attach(10);  // attaches the servo on pin 9 to the servo object

  arm1.write(13);//mean position
  arm2.write(180);//mean position
}

void loop() {
  for (pos = 13; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degree
    // in steps of 1 degree
    arm1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(3000);
  for (pos = 180; pos >= 13; pos -= 1) { // goes from 180 degrees to 0 degrees
    arm1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(3000);
 
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    arm2.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(3000);
  for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 180 degrees to 0 degrees
    arm2.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  } 
  delay(3000);

}
