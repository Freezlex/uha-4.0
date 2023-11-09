#include <iostream>
#include <vector>
#include "includes/graphics.h"
#include "point.h"
#include "carte.h"
#include "affichage.h"

#define SCREEN_W 1280
#define SCREEN_H 720

int main() {
    opengraphsize(1280, 720);

    srand(time(0));

    std::vector<Point> points = {
            /*{10, 100},
            {60, 200},
            {110, 100},
            {60, 10},
            {1,20},
            {67,53},
            {39,81},
            {59,26},
            {62,25},
            {92,84},
            {45,77},
            {87,83},
            {98,90},
            {34,72},
            {13,34},
            {9,53},
            {100,32},
            {48,64},
            {32,66},
            {49,81},
            {42,79},
            {26,41},
            {25,35},
            {75,64},
            {83,42},
            {35,39},
            {3,57}*/
    };

    for (int i = 0; i < 400; i++) {
        points.emplace_back(rand() % SCREEN_W, rand() % SCREEN_H);
    }
    std::sort(points.begin(), points.end());
    points.erase(std::unique(points.begin(), points.end()), points.end());

    for (const auto &item: points){
        plot(item.x(), 720 - item.y());
    }

    Carte ca {};

    ca.triangulation(points);
    ca.flip(ca.demiCoteParticulier()->precedent());
    trace(ca);

    getch();

    return 0;
}
