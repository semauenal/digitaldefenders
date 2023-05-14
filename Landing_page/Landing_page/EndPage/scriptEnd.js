function richtigeGPS() {
    // Eingabefeld für die GPS-Daten 
    //Erstellung von variablen 
    //Document = Objekt --> query Selector ist eine Methode des document und ermöglicht es, ein Element aus HTML zu finden 
      var input = document.querySelector('input[type="text"]');
      // Eingegebene GPS wird in Großbuchstaben umgewandelt und Leerzeichen am Anfang und Ende entfernt
      var gpsDaten = input.value.trim().toUpperCase();

      var errorBox = document.querySelector(".error-box");
      if (errorBox !== null) { //Falls Fehlermeldung vorhanden
        errorBox.remove();
      }
    
      // Wenn GPS Daten richtig, dann anzeigen der success Box 
      if (gpsDaten === "38 53") { //38° 53′ 21.37“ N, 77° 3′ 0.63“ W
        window.location.href = "http://127.0.0.1:3000/FinishPage/indexFinish.html"; 
       
      } else {
        // Wenn GPS-Daten falsch, dann wird error Box aufgerufen 
        errorBox = document.createElement("div");
        errorBox.classList.add("error-box");
        errorBox.textContent = "Die eingegebenen GPS-Daten sind falsch.";
        input.parentElement.appendChild(errorBox);
    }
}


