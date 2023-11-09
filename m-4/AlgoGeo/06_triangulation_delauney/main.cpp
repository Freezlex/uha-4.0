#include <iostream>
#include <vector>
#include "includes/graphics.h"
#include "point.h"
#include "carte.h"
#include "affichage.h"
#include <dos.h>
#include <fstream>
#include <sstream>

#define SCREEN_W 1280
#define SCREEN_H 720

int main() {
    opengraphsize(1920, 1080);

    srand(time(0));

    std::vector<Point> points = {};

    ifstream file(R"(C:\Users\julie\Documents\Work\Bin\M_404\AlgoGeo\06_triangulation_delauney\file.txt)");
    if (file.is_open()) {
        float x;
        float y;
        float z;
        //file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (file >> x >> y >> z) {
            points.emplace_back(x, y, z);
        }
        file.close();
    }

    /*for (int i = 0; i < 20; i++) {
        points.emplace_back(rand() % SCREEN_W, rand() % SCREEN_H, 0);
    }*/

    /*for (const auto &item: points){
        plot(item.x(), 720 - item.y());
    }*/

    Carte ca {};

    ca.triangulation(points);
    trace(ca);

    getch();
    return 0;
}
