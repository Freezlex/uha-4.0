function ajaxGet(url, callback) {
    var req = new XMLHttpRequest();
    req.open("GET", url);
    req.addEventListener("load", function () {
        if (req.status >= 200 && req.status < 400) {
            // Appelle la fonction callback en lui passant la réponse de la requête
            callback(req.responseText);
        } else {
            // var errorSend = document.getElementById("SectionList");
            // var errorElt = document.createElement("h1");
            // errorElt.style.marginTop = "150px";
            // errorElt.style.textAlign = "center";
            // errorElt.style.fontSize = "100px";
            // errorElt.textContent = "404";
            // errorElt.style.color = "#a3a3a3";
            // var errorBisElt = document.createElement("p");
            // errorBisElt.style.marginBottom = "150px";
            // errorBisElt.style.textAlign = "center";
            // errorBisElt.style.fontSize = "50px";
            // errorBisElt.textContent = "Whoops ! Quelque chose s'est mal passé ...";
            // errorBisElt.style.color = "#a3a3a3";

            // errorSend.appendChild(errorElt);
            // errorSend.appendChild(errorBisElt);
            console.error(req.status + " " + req.statusText + " " + url);
        }
    });
    req.addEventListener("error", function () {
        console.error("Erreur réseau avec l'URL " + url);
    });
    req.send(null);
}