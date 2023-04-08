function authenticate() {
	var username = document.getElementById("username").value;
	var password = document.getElementById("password").value;
  var errorMessage = document.getElementById("errorMessage");
	if (username === "test" && password === "1234") {
		window.location.href = "https://example.com/other-page.html";
	} else {
		errorMessage.innerHTML = "Falscher Benutzername oder Passwort. Bitte versuchen Sie es erneut.";
	}
}
