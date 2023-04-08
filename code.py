import RPi.GPIO as GPIO
import time

# Binärcode als String in umgekehrter Reihenfolge
binary_code = "10100101101101"

# GPIO-Pin-Nummern in umgekehrter Reihenfolge
gpio_pins = [22, 27, 17, 4, 3, 2, 14, 15]

# GPIO initialisieren
GPIO.setmode(GPIO.BCM)
for pin in gpio_pins:
    GPIO.setup(pin, GPIO.OUT)

# Alle GPIO-Pins 2x aufblinken lassen
for i in range(2):
    for pin in gpio_pins:
        GPIO.output(pin, GPIO.HIGH)
    time.sleep(0.2)
    for pin in gpio_pins:
        GPIO.output(pin, GPIO.LOW)
    time.sleep(0.2)

# Binärcode auf LED-Graph-Bar darstellen
for i in range(len(binary_code)):
    if binary_code[i] == "1":
        gpio_pin = gpio_pins[i]
        print(f"GPIO-Pin {gpio_pin} auf HIGH setzen")
        # Hier müsste der Code eingefügt werden, um den GPIO-Pin auf HIGH zu setzen
        GPIO.output(gpio_pin, GPIO.HIGH)
    else:
        gpio_pin = gpio_pins[i]
        print(f"GPIO-Pin {gpio_pin} auf LOW setzen")
        # Hier müsste der Code eingefügt werden, um den GPIO-Pin auf LOW zu setzen
        GPIO.output(gpio_pin, GPIO.LOW)
    time.sleep(0.5)

# GPIO freigeben
GPIO.cleanup()
