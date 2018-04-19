/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  Rotate a servo using a slider!

  App project setup:
    Slider widget (0...180) on V3
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2b31072f1ad647219135e638d90fa530";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "villa360";
char pass[] = "Deloitte29";


Servo servo;
BlynkTimer timer;

BLYNK_WRITE(V2)
{
  int btn = param.asInt();
  if(btn == 0){
    servo.detach();
  }else if(btn == 1){
    servo.attach(2);
    servo.write(90);
    delay(1000);
    servo.write(0);
    delay(1000);
  }
}


BLYNK_WRITE(V2) // Switch Widget
{
  int SrvoButtonState = param.asInt();
  if (SrvoButtonState == 1) {
    servo.attach(2);
    timer.setTimer(1000L, Servo1, 1);  // Run Servo1 loop every 800ms
  } else
    servo.detach();
} // END Blynk Function


void Servo1() {
  servo.write(90);
  timer.setTimer(1000L, Servo2, 1);  // Run Servo2 loop every 800ms
}

void Servo2() {
  servo.write(0);
  //Blynk.syncVirtual(V2);  // Check if switch still activated
}


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth,ssid,pass);
  //servo.attach(2);
  //servo.write(0);
//  delay(2000);
}

void loop(){
  Blynk.run();
}


