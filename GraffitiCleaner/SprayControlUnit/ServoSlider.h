
  Rotate a servo using a slider!

  App project setup:
    Slider widget (0...90) on V2
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2c3b40c1b5e0497b8f575f41941585c5"

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "AndroidAP";
char pass[] = "abcdefgh";


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
