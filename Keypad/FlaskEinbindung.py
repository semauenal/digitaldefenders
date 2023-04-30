def checkPassword():
    delay(500)
    lcd.clear()
    ser.write(password.encode())  # send the password over serial
    response = ser.readline().decode().strip()  # read the response from serial
    if response == "OK":
        lcd.print("Door opens!")
        delay(1000)
        while (ser.read() != b'#'):  # wait for '#' key to be pressed
            delay(10)
    else:
        lcd.print("Wrong Password!")
        delay(1500)
    lcd.clear()
    lcd.setCursor(0, 0)
    lcd.print("Enter Password:")
