/*************************************************************

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
char auth[] = "dcc7a8af2a6c405aaf9e4c96e65c8f0a";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "villa360";
char pass[] = "Deloitte29";


Servo servo;

BLYNK_WRITE(V2)
{
  servo.write(param.asInt());
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth,ssid,pass);
  servo.attach(2);
  //servo.write(0);
//  delay(2000);
}

void loop()
{
  Blynk.run();
  //servo.write(90);
//  delay(1000);
//  servo.write(0);
//  delay(1000);
}
