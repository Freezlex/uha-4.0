function ajouterElts(lien) {

    // Création du Titre de la DIV et formatage du style
    var titreElt = document.createElement("a");
    titreElt.href = lien.url;
    titreElt.style.color = "#428bca";
    titreElt.style.textDecoration = "none";
    titreElt.style.marginRight = "5px";
    titreElt.appendChild(document.createTextNode(lien.titre));

    //Création de l'objet URL
    var urlElt = document.createElement("span");
    urlElt.appendChild(document.createTextNode(lien.url));

    // Création de l'URL du lien
    var ligneTitreElt = document.createElement("h4");
    ligneTitreElt.style.margin = "0px";
    ligneTitreElt.appendChild(titreElt);
    ligneTitreElt.appendChild(urlElt);

    // Ajout de la ligne indiquant l'auteur
    var ligneDetailsElt = document.createElement("span");
    ligneDetailsElt.appendChild(document.createTextNode("Ajouté par " + lien.auteur));

    //Renvois de tout les éléments de la page
    var divLienElt = document.createElement("div");
    divLienElt.classList.add("lien");
    divLienElt.appendChild(ligneTitreElt);
    divLienElt.appendChild(ligneDetailsElt);

    return divLienElt;
}

function inputElts(insideText, size) {
    var inputElt = document.createElement("input");
    inputElt.type = "text"
    inputElt.placeholder = insideText;
    inputElt.style.width = size;
    inputElt.required = "true";
    inputElt.style.marginRight = "30px";
    return inputElt;
}

var listeLiens = [
    {
        titre: "So Foot",
        url: "http://sofoot.com",
        auteur: "yann.usaille"
    },
    {
        titre: "Guide d'autodéfense numérique",
        url: "http://guide.boum.org",
        auteur: "paulochon"
    },
    {
        titre: "L'encyclopédie en ligne Wikipedia",
        url: "http://Wikipedia.org",
        auteur: "annie.zette"
    }
];

var divPrincipaleElts = document.getElementById("contenu");
var buttonElts = document.getElementById("addBtn");
var topDivElts = document.getElementById("topSec");
var addButton = document.getElementById("addBtn");

buttonElts.addEventListener("click", function (e) {

    var ajoutElt = document.createElement("input");
    ajoutElt.type = "Submit";
    ajoutElt.value = "Ajouter";

    var auteurElt = inputElts("Entrez votre prénom", "150px");
    var titreElt = inputElts("Entrez le titre du lien", "250px");
    var urlElt = inputElts("Entrez l'URL du site", "250px");

    var formeElt = document.createElement("form");
    formeElt.appendChild(auteurElt);
    formeElt.appendChild(titreElt);
    formeElt.appendChild(urlElt);
    formeElt.appendChild(ajoutElt);

    topDivElts.replaceChild(formeElt, buttonElts);

    ajoutElt.addEventListener("click", function (e) {
        e.preventDefault();
        var url = urlElt.value;

        // Si l'URL ne commence ni par "http://" ni par "https://"
        if ((url.indexOf("http://") !== 0) && (url.indexOf("https://") !== 0)) {
            // On la préfixe par "http://"
            url = "http://" + url;
        }
        // Création de l'objet contenant les données du nouveau lien
        var lien = {
            titre: titreElt.value,
            url: url,
            auteur: auteurElt.value
        };

        var lienElt = ajouterElts(lien);
        // Ajoute le nouveau lien en haut de la liste
        divPrincipaleElts.insertBefore(lienElt, divPrincipaleElts.firstChild);

        // Création du message d'information
        var infoElt = document.createElement("div");
        infoElt.classList.add("info");
        infoElt.textContent = "Le lien \"" + lien.titre + "\" a bien été ajouté.";
        document.body.insertBefore(infoElt, contenu);
        // Suppresion du message après 2 secondes
        setTimeout(function () {
            document.body.removeChild(infoElt);
        }, 2000);

        // Remplace le formulaire d'ajout par le bouton d'ajout
        addButton.replaceChild(addButton, ajoutElt);

        ajouterElts();

    });

});

listeLiens.forEach(function (lien) {
    var elementLien = ajouterElts(lien);
    contenu.appendChild(elementLien);
});
