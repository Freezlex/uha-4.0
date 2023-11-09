//
// Created by julie on 14/11/2022.
//

#include "Polygon.h"
#include "../../includes/graphics.h"

using namespace Shape;

void Polygon::draw(Vertex* v, int color){
    setcolor(color);
    line(v->d_previous->coordinates().x()*10, v->d_previous->coordinates().y()*10, v->coordinates().x()*10, v->coordinates().y()*10);
    line(v->coordinates().x()*10, v->coordinates().y()*10, v->next()->coordinates().x()*10, v->next()->coordinates().y()*10);
}

Vertex* Polygon::addVertex(Point p, Vertex *previousVertex) {
    auto* v = new Vertex(p);
    if(this->first() == nullptr){ // Si pas encore de vertex
        v->d_previous = v;
        v->d_next = v;
        this->d_first = v;
    }else if(this->first() == this->first()->d_previous){ // Si qu'un seul vertex
        v = new Vertex(p);
        v->d_next = this->first();
        this->first()->d_next = v;
        v->d_previous = this->first();
        this->first()->d_previous = v;
    }else{ // Si y'a déjà au moins 2 vertex
        if(previousVertex == nullptr){ // Si pas de position spécifié
            v->d_next = this->first();
            v->d_previous = this->first()->previous();
            this->first()->previous()->d_next = v;
            this->first()->d_previous = v;
        }else{ // Si position spécifiée
            previousVertex->next()->d_previous = v;
            v->d_next = previousVertex->next();
            previousVertex->d_next = v;
            v->d_previous = previousVertex;
        }
    }
    this->draw(v, DARKGRAY);
    return v;
}

void Polygon::removeVertex(Vertex *v) {
    v->previous()->d_next = v->next();
    v->next()->d_previous = v->previous();
    delete(v);
}

Polygon::~Polygon() {
    delete(this);
}
