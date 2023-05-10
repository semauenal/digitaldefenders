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
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Initialisierung des LCD-Displays
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

// Initialisierung des Keypads
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Passwort, das vom Benutzer eingegeben werden soll
char password[] = "1234";

// Initialisiere den Servomotor
Servo myservo;
const int servoPin = 10;  // Pin, an dem der Servo angeschlossen ist
const int openAngle = 90; // Winkel, um den der Servo beim Öffnen gedreht wird
const int closedAngle = 0; // Winkel, um den der Servo beim Schließen gedreht wird

void setup() {
  // Initialisierung des LCD-Displays
  lcd.init();
  lcd.backlight();

  //Nachricht auf Display ausgeben
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  
  // Initialisierung des Servomotors
  myservo.attach(servoPin);
  myservo.write(closedAngle); // Servo auf den Ausgangswinkel (geschlossen) setzen
}

void checkPassword() {
  delay(500);
  lcd.clear();
  if (strcmp(password, "1234") == 0) {
    lcd.print("Door opens!");
    delay(1000);
    myservo.write(openAngle); // Servo um den Öffnungswinkel drehen
    while(keypad.getKey() != '#') { // auf '#' Zeichen warten, um die Tür wieder zu schließen
      delay(10);
    }
    myservo.write(closedAngle); // Servo zurück zum Schließwinkel drehen
  } else {
    lcd.print("Wrong Password!");
    delay(1500);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {
  // Einlesen der Tasteneingabe des Keypads
  char key = keypad.getKey();
  
  // zum Passwort gedrückten Schlüssel hinzufügen, falls ein Schlüssel gedrückt wird
  if (key != NO_KEY) {
    static int passwordIndex = 0;
    lcd.setCursor(passwordIndex, 1);
    lcd.print(key);
    password[passwordIndex] = key;
    passwordIndex++;
    
    // prüfe das Passwort, wenn es vollständig eingegeben ist
    if (passwordIndex == sizeof(password) - 1) {
      passwordIndex = 0;
      checkPassword();
    }
  }
}
