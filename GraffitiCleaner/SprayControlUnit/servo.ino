#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(2);  //attaches the servo to pin2 i.e D4 on nodeMcu.
  servo.write(0);
  delay(2000);

}

void loop() {
  servo.write(90); //servo rotate 90 clockwise.
  delay(1000);      //wait for 1 second.
  servo.write(0);   //come back to 0 degree
  delay(1000);      //wait for 1 second.
}
