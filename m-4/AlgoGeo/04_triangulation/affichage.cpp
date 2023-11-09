#include "affichage.h"
#include "point.h"
#include "carte.h"
#include "includes/graphics.h"

// trace un segment entre deux points a et b
void segment(const Point &a, const Point &b)
{
    setcolor(WHITE);
    line(a.x(), 720 - (a.y()), b.x(), 720 - (b.y()));
}

void traceDebug(const Point &a, const Point&b){
    setcolor(RED);
    line(a.x(), 720 - (a.y()), b.x(), 720 - b.y());
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


