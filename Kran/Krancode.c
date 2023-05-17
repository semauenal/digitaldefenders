#include <Servo.h>  // Importiere die Servo-Bibliothek

Servo servo1;  // Deklariere die Servo-Objekte
Servo servo2; 

int achse1 = 90;  // Initialisiere die Winkel für beide Servomotoren auf 90 Grad
int achse2 = 90; 

void setup() {
  servo1.attach(13);  // Initialisiere die Servomotoren an den Pins 13 und 12
  servo2.attach(12);

  servo1.write(90);  // Stelle beide Servomotoren auf ihre Anfangswinkel ein
  servo2.write(90);
}

void loop() {
  // Überprüfe, ob der Joystick in eine bestimmte Richtung geneigt wurde, und ob der Winkel noch nicht die maximale Position erreicht hat
  // Servo 1
  if (analogRead(0) < 200 && achse1 < 180) { 
    achse1++;  // Erhöhe den Winkel um 1 Grad
    servo1.write(achse1);  // Bewege den Servomotor auf die neue Position
  } 
  
  // Überprüfe, ob der Joystick in die entgegengesetzte Richtung geneigt wurde und ob der Winkel noch nicht die minimale Position erreicht hat
  // Servo 1
  if (analogRead(0) > 700 && achse1 > 0) {
    achse1--;  // Verringere den Winkel um 1 Grad
    servo1.write(achse1);  // Bewege den Servomotor auf die neue Position
  } 
  
  // Überprüfe, ob der Joystick in eine bestimmte Richtung geneigt wurde und ob der Winkel noch nicht die maximale Position erreicht hat
  // Servo 2
  if (analogRead(1) < 200 && achse2 < 180) {
    achse2++;  // Erhöhe den Winkel um 1 Grad
    servo2.write(achse2);  // Bewege den Servomotor auf die neue Position
  } 
  
  // Überprüfe, ob der Joystick in die entgegengesetzte Richtung geneigt wurde und ob der Winkel noch nicht die minimale Position erreicht hat
  // Servo 2
  if (analogRead(1) > 700 && achse2 > 0) {
    achse2--;  // Verringere den Winkel um 1 Grad
    servo2.write(achse2);  // Bewege den Servomotor auf die neue Position
  } 
  
  delay(15);  // Warte für 15 Millisekunden, bevor die Schleife wiederholt wird
}
