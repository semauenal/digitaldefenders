//Proyecto: Grua con servomotores 
 

 

#include <Servo.h> 
 

 

//Definicion de los servos 
 

Servo servo1; 
 

Servo servo2; 
 

 

int achse1=90; 
int achse2=90; 
void setup(){   
  servo1.attach(7); 
  servo2.attach(6); 
 
  servo1.write(90); 
  servo2.write(90); 
} 
void loop(){ 
  //SERVO 1 
  if (analogRead(0)<200 && achse1<180){ 
achse1++; 
    servo1.write(achse1); 
  } 
  if (analogRead(0)>700 && eje1>0){ 
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