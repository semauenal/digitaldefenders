#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C address of the LCD display
#define LCD_ADDR 0x3F

// Password to be entered by the user
char password[] = "1234";

// Initialize the LCD display
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

void setup() {
  // Initialize the LCD display
  lcd.init();
  lcd.backlight();

  // Print the welcome message
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  // Initialize the serial connection
  Serial.begin(9600);
}

void checkPassword(char* input) {
  delay(500);
  lcd.clear();
  if (strcmp(input, password) == 0) {
    lcd.print("Door opens!");
    Serial.println("OK"); // send 'OK' to serial
    delay(1000);
    while (Serial.read() != '#') { // wait for '#' key to be pressed
      delay(10);
    }
  } else {
    lcd.print("Wrong Password!");
    Serial.println("FAIL"); // send 'FAIL' to serial
    delay(1500);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {
  if (Serial.available() > 0) { // check if data is available on serial
    char input[5]; // create a char array to store the input
    Serial.readBytesUntil('\n', input, sizeof(input)); // read the input until a newline character is received
    checkPassword(input); // check the password
  }
}
