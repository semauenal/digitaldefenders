#include <Wire.h>

void setup() {
  Wire.begin(); // Initialisiere die I2C-Kommunikation

  Serial.begin(9600); // Initialisiere die serielle Kommunikation mit einer Baudrate von 9600
  while (!Serial); // Warte, bis die serielle Verbindung hergestellt ist

  Serial.println("\nI2C Scanner"); // Gebe eine Begrüßungsnachricht auf der seriellen Schnittstelle aus
}

void loop() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning..."); // Gebe eine Meldung aus, dass der Scan gestartet wird

  nDevices = 0; // Initialisiere den Zähler für gefundene Geräte mit 0
  for (address = 1; address < 127; address++) { // Iteriere über alle möglichen I2C-Adressen (von 1 bis 127)
    Wire.beginTransmission(address); // Starte die Kommunikation mit der aktuellen Adresse
    error = Wire.endTransmission(); // Beende die Kommunikation und überprüfe auf Fehler

    if (error == 0) { // Wenn kein Fehler aufgetreten ist
      Serial.print("I2C-Gerät gefunden an Adresse 0x");
      if (address < 16) {
        Serial.print("0"); // Führende Null hinzufügen, wenn die Adresse nur ein Zeichen hat
      }
      Serial.print(address, HEX); // Gebe die gefundene I2C-Adresse in hexadezimaler Form aus
      Serial.println("  !"); // Gebe ein Ausrufezeichen aus, um anzuzeigen, dass ein Gerät gefunden wurde

      nDevices++; // Inkrementiere den Zähler für gefundene Geräte
    } else if (error == 4) { // Wenn ein unbekannter Fehler aufgetreten ist
      Serial.print("Unbekannter Fehler an Adresse 0x");
      if (address < 16) {
        Serial.print("0"); // Führende Null hinzufügen, wenn die Adresse nur ein Zeichen hat
      }
      Serial.println(address, HEX); // Gebe die betroffene I2C-Adresse in hexadezimaler Form aus
    }
  }

  if (nDevices == 0) {
    Serial.println("Keine I2C-Geräte gefunden\n"); // Wenn keine Geräte gefunden wurden, gebe eine entsprechende Meldung aus
  } else {
    Serial.println("Fertig\n"); // Wenn Geräte gefunden wurden, gebe eine Abschlussmeldung aus
  }

  delay(5000); // Warte 5 Sekunden, bevor der nächste Scan durchgeführt wird
}
