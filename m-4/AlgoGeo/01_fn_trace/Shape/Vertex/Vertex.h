//
// Created by julie on 14/11/2022.
//

#ifndef ALGOGEO_VERTEX_H
#define ALGOGEO_VERTEX_H

#include "../Point/Point.h"
namespace Shape {
    class Vertex {
        friend class Polygon;
    public:
        Point coordinates() const { return d_coordinates;}
        Vertex* next() const {return d_next;}
        Vertex* previous() const {return d_previous;}

    private:
        Vertex(Point p, Vertex *next=nullptr, Vertex *previous=nullptr)
                : d_coordinates{p}, d_next{next}, d_previous{previous} {}
        ~Vertex() = default;

        Point d_coordinates;
        Vertex *d_next, *d_previous;
    };
}

#endif //ALGOGEO_VERTEX_H
