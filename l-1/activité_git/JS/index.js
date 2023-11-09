function createAlbum(album, index) {
    const albumCard = document.createElement("div");
    albumCard.className = "badge";

    const albumHElt = document.createElement("div");
    albumHElt.className = "badge-header";
    albumCard.appendChild(albumHElt);

    const iconAlbum = document.createElement("img");
    iconAlbum.setAttribute("src", album.couverture);
    iconAlbum.setAttribute("alt", album.nom);
    iconAlbum.setAttribute("class", "badge-avatar");
    iconAlbum.style.height = "100px";
    iconAlbum.style.width = "100px";
    albumCard.appendChild(iconAlbum);

    const albumBElt = document.createElement("div");
    albumBElt.className = "badge-body";
    albumCard.appendChild(albumBElt);

    const albumName = document.createElement("div");
    albumName.setAttribute("class", "badge-name");
    albumName.textContent = album.nom;
    albumBElt.appendChild(albumName);

    const releaseDate = document.createElement("div");
    releaseDate.setAttribute("class", "badge-role");
    releaseDate.textContent = "Date de sortie " + album.sortie;
    albumBElt.appendChild(releaseDate);

    const albumMusic = document.createElement("div");
    albumMusic.setAttribute("class", "badge-desc");
    albumMusic.textContent = album.pistes + " pistes sur l'album";
    albumBElt.appendChild(albumMusic);

    const albumFElt = document.createElement("div");
    albumFElt.className = "badge-foot";
    albumCard.appendChild(albumFElt);

    return albumCard;
}

function moreInfoElt(parent, groupe) {
    let groupeNameElt = groupe.nom.replace(/ /gi, "_");

    if (document.getElementById(groupeNameElt) != undefined) {
        parent.removeChild(document.getElementById(groupeNameElt));
    } else {
        const descriptionElt = document.createElement("section");
        descriptionElt.setAttribute("id", groupeNameElt);

        const origineElt = document.createElement("h2");
        origineElt.className = "bdg-title";
        origineElt.textContent = "Origine";
        descriptionElt.appendChild(origineElt);

        const origineDescElt = document.createElement("p");
        origineDescElt.className = "DescriptionGroupe";
        origineDescElt.textContent = "Le groupe est originaire de " + groupe.origin;
        descriptionElt.appendChild(origineDescElt);

        const titreCElt = document.createElement("h2");
        titreCElt.className = "bdg-title";
        titreCElt.textContent = "Chanteur du groupe";
        descriptionElt.appendChild(titreCElt);

        const chanteurElt = document.createElement("p");
        chanteurElt.className = "DescriptionGroupe";
        chanteurElt.textContent = groupe.chanteur;
        descriptionElt.appendChild(chanteurElt);

        const titreGElt = document.createElement("h2");
        titreGElt.className = "bdg-title";
        titreGElt.textContent = "Genres musicaux du groupe";
        descriptionElt.appendChild(titreGElt);

        groupe.genre.forEach(function (genre) {
            const genreElt = document.createElement("p");
            genreElt.className = "DescriptionGroupe"
            genreElt.textContent = genre;
            descriptionElt.appendChild(genreElt);
        });

        const divAlbums = document.createElement("div");
        divAlbums.className = "badges";

        ajaxGet("http://145.239.32.254:8081/music/albums", function (albums) {
            let albumElt = JSON.parse(albums);
            albumElt.forEach(function (album, index) {
                if (album.artiste === groupe.id) {


                    const albumCard = createAlbum(album, index);
                    divAlbums.appendChild(albumCard);
                }
            });
        });

        descriptionElt.append(divAlbums);

        parent.appendChild(descriptionElt);
    }


}

function createElts(groupe) {

    const container = document.createElement("div");
    container.classList = "container";

    const linkElt = document.createElement("a");
    container.appendChild(linkElt);

    const desBages = document.createElement("div");
    desBages.className = "Desc-Badge";
    linkElt.appendChild(desBages);


    const ppImageElt = document.createElement("img");
    ppImageElt.setAttribute("src", "../data/Images/" + groupe.nom.replace(/ /gi, "_") + ".jpg");
    ppImageElt.setAttribute("alt", groupe.nom);
    ppImageElt.className = "Groupe";
    desBages.appendChild(ppImageElt);

    const h2Elt = document.createElement("h2");
    h2Elt.textContent = groupe.nom;
    h2Elt.className = "group_name";
    desBages.appendChild(h2Elt);

    const pElt = document.createElement("p");
    pElt.textContent = "Cliquez sur la section pour plus d'informations.";
    pElt.className = "moreInfo";
    desBages.appendChild(pElt);

    desBages.addEventListener("click", function (e) {
        moreInfoElt(container, groupe);
    });
    return container;

}

const mainSect = document.getElementById("SectionList");

ajaxGet("http://145.239.32.254:8081/music/groupes", function (reponses) {
    var newApiElt = JSON.parse(reponses);
    newApiElt.forEach(function (reponse, index) {
        var newApiElt = createElts(reponse);
        mainSect.appendChild(newApiElt);
    })
});