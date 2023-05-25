#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

#define LCD_ADDR 0x3F

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

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char password[] = "7936";

Servo myservo;
const int servoPin = 10;
const int openAngle = 90;
const int closedAngle = 0;

Servo servo1;
Servo servo2;
int achse1 = 90;
int achse2 = 90;

void setup() {
  lcd.init(); // Initialisiere das LCD-Display
  lcd.backlight(); // Aktiviere die Hintergrundbeleuchtung
  lcd.setCursor(0, 0);
  lcd.print("Gib das Passwort ein:");

  myservo.attach(servoPin); // Binde den Servomotor an den angegebenen Pin
  myservo.write(closedAngle); // Setze den Servomotor auf die geschlossene Position

  servo1.attach(13); // Binde Servo 1 an Pin 13
  servo2.attach(12); // Binde Servo 2 an Pin 12

  pinMode(A0, INPUT); // Setze den Joystick-Pin A0 als Eingang
  pinMode(A1, INPUT); // Setze den Joystick-Pin A1 als Eingang
}

void loop1() {
  // Überprüfe, ob der Joystick in eine bestimmte Richtung geneigt wurde und ob der Winkel noch nicht die maximale Position erreicht hat
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

void checkPassword() {
  delay(500);
  lcd.clear();

  if (strcmp(password, "7936") == 0) { // Überprüfe, ob das eingegebene Passwort korrekt ist
    lcd.print("Tür geöffnet!");
    delay(1000);
    myservo.write(openAngle); // Öffne die Tür
    loop1(); // Rufe die Schleife für die Servomotoren auf
  } else {
    lcd.print("Falsches Passwort!");
    delay(1500);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gib das Passwort ein:");
}

void loop() {
  char key = keypad.getKey(); // Lese den Tastendruck vom Keypad aus

  if (key != NO_KEY) {
    static int passwordIndex = 0;
    lcd.setCursor(passwordIndex, 1);
    lcd.print(key);
    password[passwordIndex] = key;
    passwordIndex++;

    if (passwordIndex == sizeof(password) - 1) {
      passwordIndex = 0;
      checkPassword(); // Überprüfe das eingegebene Passwort
    }
  }

  loop1(); // Rufe die Servomotor-Schleife auf
}
