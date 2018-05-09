
/************************************************************  
Rotate a servo using a slider!
Author : Neville Mascarenhas

  App project setup:
    Slider widget (0...90) on V2

    Pin connections: 

    D4  : orange wire from servo
    GND : black wire from servo
    V3  : red wire from servo.
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2c3b40c1b5e0497b8f575f41941585c5";

// Your WiFi credentials.
char ssid[] = "iPhone777";
char pass[] = "84587811";


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
}

void loop()
{
  Blynk.run();
}
