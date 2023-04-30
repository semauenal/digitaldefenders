#include <Servo.h> 

// Definieren der Servo-Objekte
Servo servo1; 
Servo servo2; 

// Definieren der Minimal- und Maximalwinkel für die Servomotoren
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;

// Definieren der minimalen und maximalen Analogeingangspegel
const int MIN_JOYSTICK = 0;
const int MAX_JOYSTICK = 1023;

// Definieren der Wiederholrate des Servoupdates in Millisekunden
const int SERVO_UPDATE_RATE = 10;

void setup() {   
  // Anschließen der Servomotoren an die Pins 6 und 7
  servo1.attach(7); 
  servo2.attach(6); 
  
  // Setzen der Startpositionen der Servomotoren auf 90 Grad
  servo1.write(90); 
  servo2.write(90); 
}

void loop() {
  // Auslesen der Analogeingangssignale des Joysticks
  int joystick1 = analogRead(0);
  int joystick2 = analogRead(1);
  
  // Umwandeln des Analogeingangspegels in Servowinkelwerte
  int servo1Angle = map(joystick1, MIN_JOYSTICK, MAX_JOYSTICK, MIN_ANGLE, MAX_ANGLE);
  int servo2Angle = map(joystick2, MIN_JOYSTICK, MAX_JOYSTICK, MIN_ANGLE, MAX_ANGLE);
  
  // Aktualisieren der Servomotoren
  servo1.write(servo1Angle);
  servo2.write(servo2Angle);
  
  // Kurze Pause, um Überlastung des Systems zu vermeiden
  delay(SERVO_UPDATE_RATE); 
}
