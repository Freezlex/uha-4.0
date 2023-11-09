ajaxGet("http://145.239.32.254:8081/music/groupes", function (reponses) {
    var newApiElt = JSON.parse(reponses);
    newApiElt.forEach(function (reponse, index) {
        let groupName = reponse.nom.replace(/ /gi, "_");
        document.getElementById("Container_" + groupName).addEventListener("click", function (e) {
            let descriptionElt = document.getElementById(groupName);
            if (descriptionElt.style.display === "none") {
                descriptionElt.setAttribute("style", "display: true;");
            } else {
                descriptionElt.setAttribute("style", "display: none;");
            }
        });
    });
});