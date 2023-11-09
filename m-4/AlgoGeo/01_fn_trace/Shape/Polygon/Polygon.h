//
// Created by julie on 14/11/2022.
//

#ifndef ALGOGEO_POLYGON_H
#define ALGOGEO_POLYGON_H

#include "../Vertex/Vertex.h"

namespace Shape {
    class Polygon {

    private:
        Vertex* d_first;

    public:
        Polygon() : d_first{nullptr} {}
        ~Polygon();
        Vertex* first() const {return d_first;}

        Vertex* addVertex(Point p, Vertex *previousVertex=nullptr);

        void removeVertex(Vertex *v);

        void draw(Vertex *v, int color);
    };
}

#endif //ALGOGEO_POLYGON_H
