function authenticate() {
	// Die Eingabe des Benutzernamens wird im Element mit der ID "username" gespeichert
	var username = document.getElementById("username").value;
	// Die Eingabe des Passworts wird im Element mit der ID "password" gespeichert
	var password = document.getElementById("password").value;
	// Das Element mit der ID "errorMessage" wird in der Variable errorMessage gespeichert
	var errorMessage = document.getElementById("errorMessage");
  
	// Wenn der eingegebene Benutzername "test" und das eingegebene Passwort "1234" ist
	if (username === "wade.smith" && password === "C4berLove") {
	  // Leite den Benutzer auf die EndPage weiter
	  window.location.href = "http://127.0.0.1:3000/HomePage/indexHome.html";
	} else {
	  // Andernfalls zeige eine Fehlermeldung an
	  errorMessage.innerHTML =
		"Falscher Benutzername oder Passwort. Bitte versuchen Sie es erneut.";
	}
  }

  //1. Funktion deklariert 3 Variablen 
  // Unsername: speichert den Wert der Benutzereingabe des Benutzernamens --> In HTML benannt als "username"
  //Password: speichert den Wert der Benutzereingabe - In HTML : "password"
  //ErrorMessage: speichert HTML Element "errorMessage", wird verwendet um die Fehlermeldung bei falscher PW-Eingabe anzuzeigen
  //2. Funktion überprüft
  //ob das eingegebene Passwort und Benutzername übereinstimmen 
  //wenn Übereinstimmung, dann Weiterleitung an die nächste HTML Seite (indexHome.html)
  //wenn keine Übereinstimmung --> Text der Fehlermeldung wird angezeigt "errorMssage"
  