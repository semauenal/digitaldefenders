#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// Pin Definitions
#define GREEN_LED_PIN 12
#define RED_LED_PIN 13
#define SERVO_PIN 11

// Set up servo object
Servo doorServo;

// Initialize keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Set password
const char password[] = "1234";

void setup() {
  // Initialize pins
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  doorServo.attach(SERVO_PIN);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Please enter");
  lcd.setCursor(0, 1);
  lcd.print("your password");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    static int index = 0;
    static char input[5];

    if (key == '#') {
      input[index] = '\0';
      index = 0;

      if (strcmp(input, password) == 0) {
        lcd.clear();
        lcd.print("Door opens");
        digitalWrite(GREEN_LED_PIN, HIGH);
        doorServo.write(90);
      } else {
        lcd.clear();
        lcd.print("Incorrect");
        digitalWrite(RED_LED_PIN, HIGH);
        delay(1000);
        digitalWrite(RED_LED_PIN, LOW);
        lcd.clear();
        lcd.print("Please enter");
        lcd.setCursor(0, 1);
        lcd.print("your password");
      }
    } else if (index < 4) {
      input[index] = key;
      index++;
      lcd.setCursor(index - 1, 1);
      lcd.print(key);
    }
  }
}
