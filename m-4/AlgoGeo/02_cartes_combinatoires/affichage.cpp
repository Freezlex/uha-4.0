#include "affichage.h"
#include "point.h"
#include "carte.h"
#include "includes/graphics.h"

// trace un segment entre deux points a et b
void segment(const Point &a, const Point &b)
{
    line(a.x(), 1000- a.y(), b.x(), 1000 - b.y());
}

// trace la carte C dans une fenêtre graphique
void trace(const Carte &C)
{
    for (int i = 0; i < C.nbDemiCotes(); ++i) {
        if(C.demiCote(i)->index() < C.demiCote(i)->oppose()->index()){
            segment(C.demiCote(i)->coordonnees(), C.demiCote(i)->oppose()->coordonnees());
        }
    }
}


