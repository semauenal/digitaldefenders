#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// I2C-Adresse des LCD-Displays, die man über Scannercoder und Serial Monitor herausfinden kann
#define LCD_ADDR 0x3F

// Matrix und Pins des Keypads
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,9};

// Initialisierung des LCD-Displays
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

// Initialisierung des Keypads
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Passwort, das vom Benutzer eingegeben werden soll
char password[] = "7936";

// Initialisiere den Servomotor
Servo myservo;
const int servoPin = 10;  // Pin, an dem der Servo angeschlossen ist
const int openAngle = 90; // Winkel, um den der Servo beim Öffnen gedreht wird
const int closedAngle = 0; // Winkel, um den Servo beim Schließen gedreht wird

Servo servo1;  // Deklariere die Servo-Objekte
Servo servo2; 

int achse1 = 90;  // Initialisiere die Winkel für beide Servomotoren auf 90 Grad
int achse2 = 90; 

boolean keypad_b = false;
boolean kran_b = false;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  keypad_b = false;
  kran_b = false;
  wait_for_command();
}

void wait_for_command() {
  // Warte, bis eine Nachricht über die serielle Schnittstelle verfügbar ist
  while (Serial.available() == 0) {
  }

  // Lese das empfangene Kommando
  char command = Serial.read();

  // Überprüfe das empfangene Kommando und führe entsprechende Aktionen aus
  if (command == 'a') 
  {
    Serial.print("ich habe die Nachricht verarbeitet");

    // Setze den Flag für das Keypad auf true
    keypad_b = true;

    // Führe das Setup für das Keypad aus
    setup1();

    // Starte die Hauptschleife für das Keypad
    while (true){
      loop1();
    }
  }

  if(command == 'b')
  {
    Serial.print("ich habe die Nachricht verarbeitet");

    // Setze den Flag für den Kran auf true
    kran_b = true;

    // Führe das Setup für den Kran aus
    setup2();

    // Starte die Hauptschleife für den Kran
    while (true){
      loop2();
    }
  }
}

void setup1() {
  // Initialisierung des LCD-Displays
  lcd.init();
  lcd.backlight();

  // Nachricht auf Display ausgeben
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  // Initialisierung des Servomotors
  myservo.attach(servoPin);
  myservo.write(closedAngle); // Servo auf den Ausgangswinkel (geschlossen) setzen

  Serial.begin(9600);
}

void checkPassword() {
  delay(500);
  lcd.clear();
  if (strcmp(password, "7936") == 0) {
    lcd.print("Door opens!");
    delay(1000);
    myservo.write(openAngle); // Servo um den Öffnungswinkel drehen
  } else {
    lcd.print("Wrong Password!");
    delay(1500);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop1() {
  // Einlesen der Tasteneingabe des Keypads
  char key = keypad.getKey();

  // Zum Passwort gedrückten Schlüssel hinzufügen, falls ein Schlüssel gedrückt wird
  if (key != NO_KEY) {
    static int passwordIndex = 0;
    lcd.setCursor(passwordIndex, 1);
    lcd.print(key);
    password[passwordIndex] = key;
    passwordIndex++;

    // Prüfe das Passwort, wenn es vollständig eingegeben ist
    if (passwordIndex == sizeof(password) - 1) {
      passwordIndex = 0;
      checkPassword();
    }
  }
}

void setup2() {
  // Initialisierung der Servomotoren
  servo1.attach(13);  // Initialisiere den Servomotor an Pin 13
  servo2.attach(12);  // Initialisiere den Servomotor an Pin 12

  Serial.begin(9600);
}

void loop2() {
  // Überprüfe, ob der Kran-Modus aktiviert ist
  if (kran_b == true) {
    // Überprüfe die Joystick-Position und bewege die Servomotoren entsprechend
    // Servo 1
    if (analogRead(0) < 200 && achse1 < 180) { 
      achse1++;  // Erhöhe den Winkel um 1 Grad
      servo1.write(achse1);  // Bewege den Servomotor auf die neue Position
    } 

    if (analogRead(0) > 700 && achse1 > 0) {
      achse1--;  // Verringere den Winkel um 1 Grad
      servo1.write(achse1);  // Bewege den Servomotor auf die neue Position
    } 

    // Servo 2
    if (analogRead(1) < 200 && achse2 < 180) {
      achse2++;  // Erhöhe den Winkel um 1 Grad
      servo2.write(achse2);  // Bewege den Servomotor auf die neue Position
    } 

    if (analogRead(1) > 700 && achse2 > 0) {
      achse2--;  // Verringere den Winkel um 1 Grad
      servo2.write(achse2);  // Bewege den Servomotor auf die neue Position
    } 

    delay(15);  // Warte für 15 Millisekunden, bevor die Schleife wiederholt wird
  }
}