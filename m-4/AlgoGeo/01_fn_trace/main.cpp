#include <iostream>
#include <vector>
#include "Shape/Polygon/Polygon.h"
#include "Shape/Envelope/Envelope.h"
#include "includes/graphics.h"

using namespace std;

int main() {
    Shape::Polygon p = Shape::Polygon();

    vector<Point> points = {{59,	90},
                            {35,	76},
                            {85,	91},
                            {89,	100},
                            /*{24,	57},
                            {98,	31},
                            {1,	20},
                            {67,	53},
                            {39,	81},
                            {59,	26},
                            {62,	25},
                            {92,	84},
                            {45,	77},
                            {87,	83},
                            {98,	90},
                            {34,	72},
                            {13,	34},
                            {9,	53},
                            {100,	32},
                            {48,	64},
                            {32,	66},
                            {49,	81},
                            {42,	79},
                            {26,	41},
                            {25,	35},
                            {75,	64},
                            {83,	42},
                            {35,	39},
                            {3,	57}*/};

    opengraphsize( 1000, 1000 );

    for (const auto &item: points){
        setcolor(YELLOW);
        plot(item.x()*10, item.y()*10);
    }

    envelope(points, p);

    auto c = p.first();
    do{
        p.draw(c, WHITE);
        c = c->next();
    }while(c != p.first());

    delay(500000);
    closegraph();
    return 0;
}