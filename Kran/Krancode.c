#include <Servo.h> 

Servo servo1; 
Servo servo2; 
 
int achse1=90; 
int achse2=90; 
void setup(){   
  servo1.attach(7); //Servomotor an einen bestimmten Pin des Mikrocontrollers anschließen
  servo2.attach(6); //Winkel des Servomotors steuern - Winkel zwischen 0 und 180 Grad 
 
  servo1.write(90); 
  servo2.write(90); 
} 
void loop(){ 
  //die ersten if-Statements pro ServoMotor: 
      //ob Joystick in bestimmte Richtung geneigt wurde + ob  Winkel nicht bereits max. Position erreicht hat
  //2. if-Statemens:
      // Joystick in entgegengesetzte Richtung geneigt wurde + ob Winkel nicht bereits min. Position erreicht hat
  
  //SERVO 1 
  if (analogRead(0)<200 && achse1<180){  //Eingangssignal des Joysticks mit Hilfe von analogRead() und write() geändert
achse1++; 
    servo1.write(achse1); 
  } 
  if (analogRead(0)>700 && achse1>0){ 
achse1--; 
    servo1.write(achse1); 
  } 
  //SERVO 2 
  if (analogRead(1)<200 && achse2<180){ 
achse2++; 
    servo2.write(achse2); 
  } 
  if (analogRead(1)>700 && achse2>0){ 
achse2--; 
    servo2.write(achse2); 
  } 
  delay(15); 
} 