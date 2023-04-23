import RPi.GPIO as GPIO
import time

# Setze die Nummerierung der GPIO-Pins auf BCM-Modus
GPIO.setmode(GPIO.BCM)

# Definiere die verwendeten Pins für die LED-Leiste
LEDS = [20,13,6,5,4,17,27,22]

# Definiere den Pin für den Push-Button
BUTTON = 26

# Initialisiere den Pin des Push-Buttons als Eingang mit Pull-up-Widerstand
GPIO.setup(BUTTON, GPIO.IN, pull_up_down=GPIO.PUD_UP)

# Initialisiere die Pins als Ausgang und setze sie auf LOW
for pin in LEDS:
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, GPIO.LOW)

# Definiere die Dezimalzahlen, die angezeigt werden sollen
numbers = [7,9,3,6]

# Definiere die Dauer, für die die LEDs ausgeschaltet werden sollen
pause_time = 1

# Definiere die Dauer, für die alle LEDs blinken sollen
blink_time = 5

# Warte auf das Drücken des Push-Buttons, bevor die Schleife gestartet wird
while True:
    if not GPIO.input(BUTTON):
        break

# Schleife, die die Dezimalzahlen nacheinander in Binärform anzeigt
while True:
    for number in numbers:
        # Konvertiere die Dezimalzahl in Binärform
        binary = format(number, '08b')

        # Aktiviere die entsprechenden LEDs basierend auf der Binärform
        for i in range(8):
            if binary[i] == '1':
                GPIO.output(LEDS[i], GPIO.HIGH)
            else:
                GPIO.output(LEDS[i], GPIO.LOW)

        # Warte für eine bestimmte Zeit, bevor alle LEDs ausgeschaltet werden
        time.sleep(pause_time)
        for pin in LEDS:
            GPIO.output(pin, GPIO.LOW)

    # Blinken aller LEDs für eine bestimmte Zeit, bevor die Schleife wiederholt wird
    for i in range(blink_time * 2):
        for pin in LEDS:
            GPIO.output(pin, not GPIO.input(pin))
        time.sleep(0.5)

# Aufräumen und GPIO beenden
GPIO.cleanup()
