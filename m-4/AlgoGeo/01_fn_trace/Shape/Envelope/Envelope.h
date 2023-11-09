//
// Created by julie on 14/11/2022.
//

#ifndef ALGOGEO_ENVELOPE_H
#define ALGOGEO_ENVELOPE_H


#include "../Vertex/Vertex.h"
#include "../Polygon/Polygon.h"
#include <vector>
using namespace std;
using namespace Shape;

Vertex* envelope(const Point &a, const Point &b, const Point &c, Polygon &P);
void envelope(vector<Point>&T, Polygon &P);
int determine(vector<Point> &T, Point previous, int c);

#endif //ALGOGEO_ENVELOPE_H
