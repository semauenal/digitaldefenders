import RPi.GPIO as GPIO
import time

# Setze die Nummerierung der GPIO-Pins auf BCM-Modus
GPIO.setmode(GPIO.BCM)

# Definiere den Pin für den Summer/Buzzer
BUZZER_PIN = 12

# Initialisiere den Pin als Ausgang
GPIO.setup(BUZZER_PIN, GPIO.OUT)

# Frequenzen für die Noten
C = 5
D = 10
E = 1
F = 7
G = 4
A = 3
B = 8

# Noten und Dauer für "Alle meine Entchen"
notes = [C, C,C,C]
durations = [2,3,4,2]

# Spielen der Melodie
for i in range(len(notes)):
    # Aktiviere den Summer/Buzzer
    GPIO.output(BUZZER_PIN, GPIO.HIGH)

    # Erzeuge das Tonsignal
    p = GPIO.PWM(BUZZER_PIN, notes[i])
    p.start(50)

    # Warte für die Dauer der Note
    time.sleep(durations[i])

    # Stoppe das Tonsignal
    p.stop()

    # Deaktiviere den Summer/Buzzer
    GPIO.output(BUZZER_PIN, GPIO.LOW)

    # Warte eine kurze Pause zwischen den Noten
    time.sleep(0.1)

# Aufräumen und GPIO beenden
GPIO.cleanup()
