    import RPi.GPIO as GPIO
    import time
    # GPIO-Pins für den Push-Button und die einzelnen LEDs
    button_pin = 17
    led_pins = [18, 19, 20, 21]
    # Dezimalzahlen im Binärcode
    binary_numbers = ['0111', '1001', '0011', '0110']
    # Initialisierung der GPIO-Pins
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
    for pin in led_pins:
        GPIO.setup(pin, GPIO.OUT)
    # Funktion zur Darstellung einer Dezimalzahl im Binärcode
    def display_binary_number(binary):
        for i in range(len(binary)):
            GPIO.output(led_pins[i], int(binary[i]))
    # Funktion zur Darstellung aller Dezimalzahlen im Binärcode nacheinander
    def display_numbers():
        for binary in binary_numbers:
            display_binary_number(binary)
            time.sleep(1)
    # Hauptprogramm
    try:
        button_pressed = False
        while True:
            # Warten auf den Tastendruck
            GPIO.wait_for_edge(button_pin, GPIO.FALLING)
            button_pressed = not button_pressed
            
            if button_pressed:
                display_numbers()
                time.sleep(3)
                for pin in led_pins:
                    GPIO.output(pin, GPIO.LOW)
            else:
                break
    finally:
        # Aufräumen
        GPIO.cleanup()
