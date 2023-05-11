function authenticate() {
	// Die Eingabe des Benutzernamens wird im Element mit der ID "username" gespeichert
	var username = document.getElementById("username").value;
	// Die Eingabe des Passworts wird im Element mit der ID "password" gespeichert
	var password = document.getElementById("password").value;
	// Das Element mit der ID "errorMessage" wird in der Variable errorMessage gespeichert
	var errorMessage = document.getElementById("errorMessage");
  
	// Wenn der eingegebene Benutzername "test" und das eingegebene Passwort "1234" ist
	if (username === "test" && password === "1234") {
	  // Leite den Benutzer auf die EndPage weiter
	  window.location.href = "http://127.0.0.1:3000/HomePage/indexHome.html";
	} else {
	  // Andernfalls zeige eine Fehlermeldung an
	  errorMessage.innerHTML =
		"Falscher Benutzername oder Passwort. Bitte versuchen Sie es erneut.";
	}
  }
  