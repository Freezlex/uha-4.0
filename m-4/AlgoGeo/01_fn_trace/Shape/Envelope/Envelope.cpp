//
// Created by julie on 14/11/2022.
//

#include <iostream>
#include <algorithm>
#include "Envelope.h"
#include "../Polygon/Polygon.h"

Vertex* envelope(Point a, Point b, Point c, Polygon &P){
    P.addVertex(a);
    P.addVertex(b);
    if(c.aGauche(a, b) >= 0){
        P.addVertex(c);
    }else{
        P.addVertex(c, P.first());
    }
    return P.first();
}

// Construit dans le polygone P l’enveloppe convexe de l'ensemble de points donné dans T.
// On suppose P initialement vide.
void envelope(vector<Point>&T, Polygon &P) {
    std::sort(T.begin(), T.end());

    for(int i=0;i<=T.size() -1;i++){
        auto ref = P.first();
        switch(i){
            case 0:
            case 1:
                P.addVertex(T[i]);
                break;
            case 2:
                if(T[i].aGauche(ref->coordinates(), ref->next()->coordinates()) >= 0){
                    P.addVertex(T[i]);
                }else{
                    P.addVertex(T[i], P.first());
                }
                break;
            default:
                do{
                    if(T[i].aGauche(ref->coordinates(), ref->next()->coordinates()) < 0){ // Si à droite
                        ref = P.addVertex(T[i], ref);
                        if(ref->next()->coordinates().aGauche(ref->coordinates(), ref->next()->next()->coordinates()) > 0){
                            P.removeVertex(ref->next());
                        }
                    }else{ // Si à gauche
                        ref = ref->next();
                    }
                }while(ref != P.first());
                break;
        }
    }
}