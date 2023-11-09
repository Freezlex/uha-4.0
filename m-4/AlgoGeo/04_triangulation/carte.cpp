#include <vector>
#include <algorithm>
#include "affichage.h"

using namespace std;

#include "carte.h"
#include "point.h"


// Destructeur
Carte::~Carte()
{
}

// Ajoute dans la carte un nouveau côté composé de deux demi-côtés dc1 et dc2
// dont precedent1 et precedent2 seront les demi-côtés précédents respectifs.
// On suppose precedent1 et precedent2 déjà présents dans la carte.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(DemiCote* precedent1, DemiCote* precedent2)
{
    auto a = ajouteDemiCote(precedent1, nullptr);
    ajouteDemiCote(precedent2, a);
    traceDebug(a->coordonnees(), a->oppose()->coordonnees());
	return a;
}

// Ajoute dans la carte un nouveau côté composé de deux demi-côtés dc1 et dc2.
// precedent1 sera le demi-côté précédent de dc1. dc2 sera issu d’un
// nouveau sommet (à créer) dont les coordonnées sont celles du point p2.
// On suppose precedent1 déjà présent dans la carte.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(DemiCote* precedent1, const Point& p2)
{
    auto a = ajouteDemiCote(precedent1, nullptr);
    ajouteDemiCote(p2, a);
    traceDebug(a->coordonnees(), a->oppose()->coordonnees());
	return a;
}

// Ajoute dans la carte un nouveau côté composé de deux demi-côtés dc1 et dc2.
// precedent2 sera le demi-côté précédent de dc2. dc1 sera issu d’un
// nouveau sommet (à créer) dont les coordonnées sont celles du point p1.
// On suppose precedent2 déjà présent dans la carte.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(const Point& p1, DemiCote* precedent2)
{
    auto a = ajouteDemiCote(p1, nullptr);
    ajouteDemiCote(precedent2, a);
    traceDebug(a->coordonnees(), a->oppose()->coordonnees());
	return a;
}

// Ajoute dans la carte un nouveau côté composé de deux demi-côtés dc1 et dc2.
// dc1 et dc2 seront issus de deux nouveaux sommets (à créer) dont les
// coordonnées sont celles des points p1 et p2 respectivement.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(const Point& p1, const Point& p2)
{
    auto a = ajouteDemiCote(p1, nullptr);
    ajouteDemiCote(p2, a);
    traceDebug(a->coordonnees(), a->oppose()->coordonnees());
	return a;
}

// Ajoute un nouveau demi-côté dans la carte dont precedent sera le demi-côté
// 	précédent et oppose sera le demi-côté opposé.
// On suppose que le demi-côté precedent est déjà présent dans la carte.
// Le demi-côté oppose est soit déjà présent dans la carte, soit nul (valeur
// par défaut).
// Renvoie l’adresse du nouveau demi-côté.
DemiCote* Carte::ajouteDemiCote(DemiCote* precedent, DemiCote* oppose)
{
    auto i = new DemiCote(
            precedent->suivant(),
            precedent,
            oppose,
            precedent->sommet(),
            this->nbDemiCotes());

    precedent->suivant()->d_precedent = i;
    precedent->d_suivant = i;
    if(oppose != nullptr) oppose->d_oppose = i;

    this->d_tabDemiCotes.push_back(i);
    return i;
}

// Ajoute un nouveau demi-côté dans la carte qui sera issu d’un nouveau
// sommet (à créer) dont les coordonnées sont celles du point p.
// oppose sera le demi-côté opposé du nouveau demi-côté.
// oppose est soit déjà présent dans la carte, soit nul (valeur par défaut).
// Renvoie l’adresse du nouveau demi-côté.
DemiCote* Carte::ajouteDemiCote(const Point &p, DemiCote* oppose)
{
    auto i = new DemiCote(nullptr, nullptr, oppose, nullptr, this->nbDemiCotes());
    auto s = new Sommet(
            p,
            i,
            this->nbSommets()
            );

    i->d_suivant = i;
    i->d_precedent = i;
    i->d_sommet = s;
    if(oppose != nullptr)oppose->d_oppose = i;

    this->d_tabSommets.push_back(s);
    this->d_tabDemiCotes.push_back(i);
	return i;
}

void Carte::triangulation(std::vector<Point> &P) {
    std::sort(P.begin(), P.end());

    DemiCote* d = this->ajouteCote(P[1], P[0]);
    this->d_demiCoteParticulier = d;
    traceDebug(d->coordonnees(), d->oppose()->coordonnees());


    for(int i=2;i<P.size();i++){
        d = ajouteCote(P[i], d);

        DemiCote* temp = d;
       while(P[i].aGauche(d->oppose()->coordonnees(), d->oppose()->suivant()->oppose()->coordonnees())<0){
           d = ajouteCote(d->precedent(), d->oppose()->suivant()->oppose());

       }

       d = temp;
        while (P[i].aGauche(d->oppose()->precedent()->oppose()->coordonnees(), d->oppose()->coordonnees())<0){
            d = ajouteCote(d, d->oppose()->precedent()->oppose()->precedent());
        }
    }
}

void Carte::flip(DemiCote *d) {
    flipDemiCote(d);
    flipDemiCote(d->oppose());
}

void Carte::flipDemiCote(DemiCote *d){
    d->sommet()->d_demiCote = d->suivant();

    d->suivant()->d_precedent = d->precedent();
    d->precedent()->d_suivant = d-> suivant();

    d->suivant()->oppose()->suivant()->d_precedent = d;
    d->suivant()->oppose()->d_suivant = d;

    d->d_sommet = d->suivant()->oppose()->sommet();

    d->d_precedent = d->suivant()->oppose();
    d->d_suivant = d->suivant()->oppose()->suivant();
}
