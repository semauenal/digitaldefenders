#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

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
Adafruit_SSD1306 display(128, 64, &Wire, -1); // initialize the OLED display

int cursorColumn = 0;
char password[5] = {'1', '2', '3', '4', '\0'}; // Set your password here
char inputPassword[5] = {'\0'}; // Initialize input password

void setup(){
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize the OLED display
  display.clearDisplay();
  display.display();
  display.setTextSize(2); // set text size to 2
  display.setTextColor(WHITE); // set text color to white
  display.setCursor(0, 0); // move cursor to (0, 0)
  display.println("Enter your password:");
  display.display();
}

void loop(){
  char key = keypad.getKey();

  if (key) {
    display.setCursor(cursorColumn*16, 24); // move cursor to (cursorColumn*16, 24)
    display.print("*"); // print * instead of actual key
    inputPassword[cursorColumn] = key; // store key in inputPassword array

    cursorColumn++; // move cursor to next position
    if(cursorColumn == 4) { // if reaching limit, check the password
      if(strcmp(inputPassword, password) == 0) { // check if input password matches with the password
        display.clearDisplay();
        display.setCursor(0, 0); // move cursor to (0, 0)
        display.println("Door opens");
        display.display();
      } else {
        display.clearDisplay();
        display.setCursor(0, 0); // move cursor to (0, 0)
        display.println("Wrong password");
        display.display();
        delay(1000);
        display.clearDisplay();
        display.setCursor(0, 0); // move cursor to 

      }

    }
  }
}
