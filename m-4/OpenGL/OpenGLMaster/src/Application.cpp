#include <iostream>
#include <vector>
#include <math.h>

#include <fstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "OpenGlDisplay/Fenetre.h"

int main() {


    Fenetre fenetre = Fenetre(1280, 720, "Algo Géo 2");
    fenetre.zMultiplier = 1;
    // std::cout << "Hello, World!" << std::endl;

    std::vector<Point>* points = new vector<Point>();

    ifstream file(R"(C:\Users\julie\Documents\Work\Bin\M_404\AlgoGeo\06_triangulation_delauney\file.txt)");
    if (file.is_open()) {
        float x;
        float y;
        float z;
        //file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (file >> x >> y >> z) {
            points->emplace_back(x, y, z);
        }
        file.close();
    }

    fenetre.scale(*points);

    Carte* ca = new Carte();

    ca->triangulation(*points);

    glRotatef(90.0, 0.0, 1.0, 0.0);
    glRotatef(90.0, -1.0, 0.0, 0.0);
    glRotatef(45.0, 0.0, 1.0, 0.0);

    glTranslatef(0.0, 0.0, 1.0);

    for (int i = 0; i < 100000; ++i) {

        glRotatef(0.1, 0.0, 0.0, 0.1);

        fenetre.drawAll(*points, *ca);
    }


    fenetre.listenToEvents();
    return 0;
}