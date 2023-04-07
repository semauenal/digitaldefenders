/*
 *    ExitGame 2022 - Gruppe 3
 *    
 *    Kurs: WWI2021B
 * 
 *    Teilnehmer: 
 *      - Marvin
 *      - Elvira
 *      - Arian
 *      - Natalie
 *      - Sofie
 *      - Max
 *
 */

//Bibliothek für die Servo steuerung hinzufügen
#include <Servo.h>

Servo myservo;  // ein neues Objekt vom Typ Servo erzeugen

//An welchem Arduino Pin ist welcher Schalter angeschlossen.
const int schalter1Pin = 13;
const int schalter2Pin = 12;
const int schalter3Pin = 11;
const int schalter4Pin = 10;
const int schalter5Pin = 9;
const int schalter6Pin = 8;
const int schalter7Pin = 22;
const int schalter8Pin = 24;

//Schalterstates werden zum Abfragen der Schalter benötigt.
int schalter1State = 0;
int schalter2State = 0;
int schalter3State = 0;
int schalter4State = 0;
int schalter5State = 0;
int schalter6State = 0;
int schalter7State = 0;
int schalter8State = 0;

//Led (rot) 
const int led1Pin = 42;
const int led2Pin = 44;
const int led3Pin = 46;
const int led4Pin = 48;

//Led (Grün) 
const int led5Pin = 40;
const int led6Pin = 30;
const int led7Pin = 28;
const int led8Pin = 26; // (rot)
const int led9Pin = 34;
const int led10Pin = 32;
const int led11Pin = 38;
const int led12Pin = 36;  // (rot)

//Servo
const int servoPin = 3;
int pos = 0;

//Piezo
int piezoPin = 2;
 
void setup() {
//Serielle Kommunikation
Serial.begin(9600);

//Outputs und Inputs werden definiert
pinMode(schalter1Pin, INPUT);
pinMode(schalter2Pin, INPUT);
pinMode(schalter3Pin, INPUT);
pinMode(schalter4Pin, INPUT);
pinMode(schalter5Pin, INPUT);
pinMode(schalter6Pin, INPUT);
pinMode(schalter7Pin, INPUT);
pinMode(schalter8Pin, INPUT);
pinMode(led1Pin, OUTPUT);
pinMode(led2Pin, OUTPUT);
pinMode(led3Pin, OUTPUT);
pinMode(led4Pin, OUTPUT);
pinMode(led5Pin, OUTPUT);
pinMode(led6Pin, OUTPUT);
pinMode(led7Pin, OUTPUT);
pinMode(led8Pin, OUTPUT);
pinMode(led9Pin, OUTPUT);
pinMode(led10Pin, OUTPUT);
pinMode(led11Pin, OUTPUT);
pinMode(led12Pin, OUTPUT);
pinMode(piezoPin, OUTPUT);

//Servo wird in die Ausgangsposition gestellt
myservo.attach(servoPin);
myservo.write(0);

//Startsequenz sodass geprüft werden kann ob alles funktioniert
for (int zaehler=1; zaehler<=3; zaehler = zaehler+1){
  digitalWrite(led1Pin, HIGH);
digitalWrite(led2Pin, HIGH);
digitalWrite(led3Pin, HIGH);
digitalWrite(led4Pin, HIGH);
digitalWrite(led5Pin, HIGH);
digitalWrite(led6Pin, HIGH);
digitalWrite(led7Pin, HIGH);
digitalWrite(led8Pin, HIGH);
digitalWrite(led9Pin, HIGH);
digitalWrite(led10Pin, HIGH);
digitalWrite(led11Pin, HIGH);
digitalWrite(led12Pin, HIGH);
digitalWrite(piezoPin, HIGH);
delay(300);
digitalWrite(led1Pin, LOW);
digitalWrite(led2Pin, LOW);
digitalWrite(led3Pin, LOW);
digitalWrite(led4Pin, LOW);
digitalWrite(led5Pin, LOW);
digitalWrite(led6Pin, LOW);
digitalWrite(led7Pin, LOW);
digitalWrite(led8Pin, LOW);
digitalWrite(led9Pin, LOW);
digitalWrite(led10Pin, LOW);
digitalWrite(led11Pin, LOW);
digitalWrite(led12Pin, LOW);
digitalWrite(piezoPin, LOW);
delay(300);
  }
}


void loop() {
  //Prüfe ob Schalter 1 auf HIGH ist und schalte die LED an/aus
  schalter1State = digitalRead(schalter1Pin);
  if (schalter1State == HIGH)  {
    digitalWrite(led5Pin, HIGH);
  } else  {
    Serial.println("Schalter 1  = LOW");
    digitalWrite(led5Pin, LOW);
  }
  schalter2State = digitalRead(schalter2Pin);
  if (schalter2State == HIGH)  {
    digitalWrite(led3Pin, HIGH);
    digitalWrite(led8Pin, HIGH);
  } else  {
    digitalWrite(led3Pin, LOW);
    digitalWrite(led8Pin, LOW);
  }
  schalter3State = digitalRead(schalter3Pin);
  if (schalter3State == HIGH)  {
    digitalWrite(led6Pin, HIGH);
  } else  {
    digitalWrite(led6Pin, LOW);
  }
  schalter4State = digitalRead(schalter4Pin);
  if (schalter4State == HIGH)  {
    digitalWrite(led1Pin,HIGH);
    digitalWrite(led2Pin, HIGH);
  } else  {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin,LOW);
  }
  schalter5State = digitalRead(schalter5Pin);
  if (schalter5State == HIGH)  {
   digitalWrite(led11Pin,HIGH);
  } else  {
    digitalWrite(led11Pin, LOW);
  }
  schalter6State = digitalRead(schalter6Pin);
  if (schalter6State == HIGH)  {
    digitalWrite(led7Pin, HIGH);
  } else  {
    digitalWrite(led7Pin,LOW);
  }
  schalter7State = digitalRead(schalter7Pin);
  if (schalter7State == HIGH)  {
    digitalWrite(led4Pin,HIGH);
    digitalWrite(led12Pin,HIGH);
    digitalWrite(led10Pin,HIGH);
  } else  {
    digitalWrite(led4Pin,LOW);
    digitalWrite(led12Pin,LOW);
    digitalWrite(led10Pin,LOW);
  }
  schalter8State = digitalRead(schalter8Pin);
  if (schalter8State == HIGH)  {
    digitalWrite(led9Pin, HIGH);
  } else  {
    digitalWrite(led9Pin, LOW);
  }
  delay(100);
  //Prüfung ob Code richtig ist
  if (schalter1State == HIGH)  {
    if (schalter2State == LOW)  {
      if (schalter3State == HIGH)  {
        if (schalter4State == LOW)  {
          if (schalter5State == HIGH)  {
            if (schalter6State == HIGH)  {
              if (schalter7State == LOW)  {
                if (schalter8State == HIGH)  { 
                  myservo.write(90);
                  delay(100);
                }
              }
            }
          }
        }
      }
    }
  }
}
