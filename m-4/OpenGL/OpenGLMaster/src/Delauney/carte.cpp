#include <vector>
#include <algorithm>
#include "affichage.h"
#include <stack>

using namespace std;

#include "carte.h"
#include "point.h"


// Destructeur
Carte::~Carte()
{
}

// Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2
// dont precedent1 et precedent2 seront les demi-c�t�s pr�c�dents respectifs.
// On suppose precedent1 et precedent2 d�j� pr�sents dans la carte.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(DemiCote* precedent1, DemiCote* precedent2)
{
    auto a = ajouteDemiCote(precedent1, nullptr);
    ajouteDemiCote(precedent2, a);
	return a;
}

// Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2.
// precedent1 sera le demi-c�t� pr�c�dent de dc1. dc2 sera issu d�un
// nouveau sommet (� cr�er) dont les coordonn�es sont celles du point p2.
// On suppose precedent1 d�j� pr�sent dans la carte.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(DemiCote* precedent1, const Point& p2)
{
    auto a = ajouteDemiCote(precedent1, nullptr);
    ajouteDemiCote(p2, a);
	return a;
}

// Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2.
// precedent2 sera le demi-c�t� pr�c�dent de dc2. dc1 sera issu d�un
// nouveau sommet (� cr�er) dont les coordonn�es sont celles du point p1.
// On suppose precedent2 d�j� pr�sent dans la carte.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(const Point& p1, DemiCote* precedent2)
{
    auto a = ajouteDemiCote(p1, nullptr);
    ajouteDemiCote(precedent2, a);
	return a;
}

// Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2.
// dc1 et dc2 seront issus de deux nouveaux sommets (� cr�er) dont les
// coordonn�es sont celles des points p1 et p2 respectivement.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(const Point& p1, const Point& p2)
{
    auto a = ajouteDemiCote(p1, nullptr);
    ajouteDemiCote(p2, a);
	return a;
}

// Ajoute un nouveau demi-c�t� dans la carte dont precedent sera le demi-c�t�
// 	pr�c�dent et oppose sera le demi-c�t� oppos�.
// On suppose que le demi-c�t� precedent est d�j� pr�sent dans la carte.
// Le demi-c�t� oppose est soit d�j� pr�sent dans la carte, soit nul (valeur
// par d�faut).
// Renvoie l�adresse du nouveau demi-c�t�.
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

// Ajoute un nouveau demi-c�t� dans la carte qui sera issu d�un nouveau
// sommet (� cr�er) dont les coordonn�es sont celles du point p.
// oppose sera le demi-c�t� oppos� du nouveau demi-c�t�.
// oppose est soit d�j� pr�sent dans la carte, soit nul (valeur par d�faut).
// Renvoie l�adresse du nouveau demi-c�t�.
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

    DemiCote* last = this->ajouteCote(P[1], P[0]);
    this->d_demiCoteParticulier = last;

    for(int i=2;i<P.size();i++){
        last = ajouteCote(P[i], last);

        DemiCote* temp = last;
       while(P[i].aGauche(last->oppose()->coordonnees(), last->oppose()->suivant()->oppose()->coordonnees()) < 0){
           last = ajouteCote(last->precedent(), last->oppose()->suivant()->oppose());
       }

        last = temp;
        while (P[i].aGauche(last->oppose()->precedent()->oppose()->coordonnees(), last->oppose()->coordonnees()) < 0){
            last = ajouteCote(last, last->oppose()->precedent()->oppose()->precedent());
        }
    }
    delaunay(P);
}

void Carte::delaunay(vector<Point>& T)
{
    // Cr�e une pile de c�t�s � traiter
    const int nbDemiCotes = this->nbDemiCotes();
    // Parcourt tous les c�t�s de la carte
    stack<DemiCote*> aTraiter;
    DemiCote* coteForloop = this->demiCoteParticulier();
    // Marque tout les demi c�t�s exterieurs
    do {
        coteForloop->changeMarque(1);
        coteForloop->oppose()->changeMarque(1);
        coteForloop = coteForloop->oppose()->suivant();
        //displayParticulier(C, coteForloop->coordonnees(), coteForloop->oppose()->coordonnees());
    } while (coteForloop != this->demiCoteParticulier());
    for (int i = 0; i < nbDemiCotes; i++) {
        DemiCote* toPush = this->demiCote(i);
        if (toPush->marque() != 1)
        {
            toPush->changeMarque(1);
            toPush->oppose()->changeMarque(1);
            aTraiter.push(this->demiCote(i));
        }
    }
    while (!aTraiter.empty()) {
        DemiCote* traitement = aTraiter.top();
        aTraiter.pop();
        traitement->changeMarque(0);
        traitement->oppose()->changeMarque(0);
        Sommet* firstPointToTest = traitement->precedent()->oppose()->sommet(); // -1
        float firstPointisInsideTheCircle;
        firstPointisInsideTheCircle = firstPointToTest->coordonnees().dansCercle(traitement->coordonnees(), traitement->suivant()->oppose()->coordonnees(), traitement->oppose()->coordonnees());
        if ((firstPointisInsideTheCircle < 0))
        {
            if (traitement->oppose()->precedent()->marque() == 0) {
                traitement->oppose()->precedent()->changeMarque(1);
                traitement->oppose()->precedent()->oppose()->changeMarque(1);
                aTraiter.push(traitement->oppose()->precedent());
            }
            if (traitement->oppose()->suivant()->marque() == 0) {
                traitement->oppose()->suivant()->changeMarque(1);
                traitement->oppose()->suivant()->oppose()->changeMarque(1);
                aTraiter.push(traitement->oppose()->suivant());
            }
            if (traitement->precedent()->marque() == 0) {
                traitement->precedent()->changeMarque(1);
                traitement->precedent()->oppose()->changeMarque(1);
                aTraiter.push(traitement->precedent());
            }
            if (traitement->suivant()->marque() == 0) {
                traitement->suivant()->changeMarque(1);
                traitement->suivant()->oppose()->changeMarque(1);
                aTraiter.push(traitement->suivant());
            }
            this->flip(traitement);
        }
    };
}

void Carte::flip(DemiCote* d) {
    flipDemiCote(d);
    flipDemiCote(d->oppose());
}
void Carte::flipDemiCote(DemiCote* d) {
    // Defini un marqueur de la ou va se trouver le demi cote
    auto demiCoteDepart = d->suivant()->oppose();
    // Changer le demi cote repr�sentant le sommet
    if (d->d_sommet->demiCote() == d) {
        d->d_sommet->d_demiCote = d->suivant();
    }
    // Changer les anciens voisins de d
    d->suivant()->d_precedent = d->precedent();
    d->precedent()->d_suivant = d->suivant();
    // Deplacer d
    d->d_precedent = demiCoteDepart;
    d->d_suivant = demiCoteDepart->suivant();
    // Changer les nouveaux voisins de d
    d->precedent()->d_suivant = d;
    d->suivant()->d_precedent = d;
    // Mettre � jour le sommet de d
    d->d_sommet = demiCoteDepart->sommet();
}
