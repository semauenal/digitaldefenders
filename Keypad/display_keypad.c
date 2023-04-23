#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int ROW_NUM    = 4; // four rows
const int COLUMN_NUM = 4; // four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};      // connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

int cursorColumn = 0;
char password[5] = {'1', '2', '3', '4', '\0'}; // Set your password here
char inputPassword[5] = {'\0'}; // Initialize input password

void setup(){
  Wire.begin();
  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.print("Enter your password:");
}

void loop(){
  char key = keypad.getKey();

  if (key) {
    lcd.setCursor(cursorColumn, 1); // move cursor to   (cursorColumn, 1)
    lcd.print("*"); // print * instead of actual key
    inputPassword[cursorColumn] = key; // store key in inputPassword array

    cursorColumn++; // move cursor to next position
    if(cursorColumn == 4) { // if reaching limit, check the password
