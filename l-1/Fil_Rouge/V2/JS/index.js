function createElts(lien) {

    const container = document.createElement("div");
    container.classList = "container";


    // const plusContainerElt = document.createElement("a");
    // const plusElt = document.createElement("img");

    const desBages = document.createElement("div");
    desBages.setAttribute("href", "www.google.com");
    desBages.style.textDecoration = "none";
    desBages.className = "Desc-Badge";
    container.appendChild(desBages);


    const ppImageElt = document.createElement("img");
    ppImageElt.setAttribute("src", "../data/Images/" + lien.nom.replace(/ /gi, "_") + ".jpg");
    ppImageElt.setAttribute("alt", lien.nom);
    ppImageElt.className = "Groupe";
    desBages.appendChild(ppImageElt);

    const h2Elt = document.createElement("h2");
    h2Elt.textContent = lien.nom;
    h2Elt.className = "group_name";
    desBages.appendChild(h2Elt);

    const pElt = document.createElement("p");
    pElt.textContent = "Cliquez sur la section pour plus d'informations.";
    pElt.className = "moreInfo";
    desBages.appendChild(pElt);


    //Div Container

    //plus image href
    // plusContainerElt.href = "SOAD.html";
    // plusElt.src = lien.couverture;


    return container;

}

const mainSect = document.getElementById("SectionList");

ajaxGet("http://145.239.32.254:8081/music/groupes", function (reponses) {
    var newApiElt = JSON.parse(reponses);
    newApiElt.forEach(function (reponse, index) {
        var nomGroupe = reponse.nom;
        //if(nomGroupe!="System Of A Down") {return}
        let imageElt = ""
        /*switch (nomGroupe){
            case "System Of A Down":
                imageElt = "../data/Images/SOAD_PP.jpg"
                break;
        }*/
        var newApiElt = createElts(reponse);
        mainSect.appendChild(newApiElt);
    })
});