function freischaltungKamera() {
    // Eingabefeld für die MAC-Adresse 
    //Erstellung von variablen 
    //Document = Objekt --> query Selector ist eine Methode des document und ermöglicht es, ein Element aus HTML zu finden 
      var input = document.querySelector('input[type="text"]');
      // Eingegebene MAC-Adresse wird in Großbuchstaben umgewandelt und Leerzeichen am Anfang und Ende entfernt
      var macAdresse = input.value.trim().toUpperCase();

      // Bei falscher Eingabe der MAC Adresse wird Fehlermeldung angezeigt, um zu vermeiden, dass diese Fehlermeldung bei erneuter 
      //Eingabe immernoch erscheint wird diese durch den unten stehenden Block entfernt (remove)
      var errorBox = document.querySelector(".error-box");
      if (errorBox !== null) { //Falls Fehlermeldung vorhanden
        errorBox.remove();
      }
      // gleiche wie oben gilt für die Erfolgsmeldung bei richtiger Eingabe
      var successBox = document.querySelector(".success-box");
      if (successBox !== null) {
        successBox.remove();
      }

      // Wenn MAC Adresse richtig, dann anzeigen der success Box 
      if (macAdresse === "400") { //MUT-FUCHS-HERZ-543210-SATURN-BACHELOR
       
        // Anzeigen des Netzwerkfehlers bei richtiger Eingabe
	    successBox = document.createElement("div");
        successBox.classList.add("success-box");
        var successHeader = document.createElement("h2");
        successHeader.textContent = "Netzwerkfehler";
        successBox.appendChild(successHeader); //Child success Header wird an Parent success Box angehängt
        var successText = document.createElement("p");
        successText.textContent = "Ihre Eingabe war richtig. Leider liegt ein Problem bei der Verbindung vor. Bitte beheben Sie dieses, damit Sie Zugriff auf die Kamera haben.";
        successBox.appendChild(successText);

        var networkErrorFixedContainer = document.createElement("div");
        networkErrorFixedContainer.classList.add("network-error-fixed");

        var networkErrorFixedLabel = document.createElement("label");
        networkErrorFixedLabel.textContent = "Netzwerkfehler behoben? ";
        networkErrorFixedContainer.appendChild(networkErrorFixedLabel);
        

        var networkErrorFixedButton = document.createElement("button");
        networkErrorFixedButton.textContent = "Ja";
        networkErrorFixedContainer.appendChild(networkErrorFixedButton);

        successBox.appendChild(networkErrorFixedContainer);
        input.parentElement.appendChild(successBox); //Einbindung gesamte success Box wie ein pop up Fenster
        
        networkErrorFixedButton.addEventListener("click", function() {
          window.location.href = "http://127.0.0.1:3000/VideoPage/indexVideo.html"; 
        });
    
      } else {
        // Wenn MAC Adresse falsch, dann wird error Box aufgerufen 
        errorBox = document.createElement("div");
        errorBox.classList.add("error-box");
        errorBox.textContent = "Die eingegebene MAC-Adresse ist falsch.";
        input.parentElement.appendChild(errorBox);
    }
}
