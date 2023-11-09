#ifndef ALGO_GEO_FINAL_FENETRE_H
#define ALGO_GEO_FINAL_FENETRE_H

#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>
#include <iostream>
#include "../Delauney/point.h"
#include "../Delauney/carte.h"

class Fenetre {
public:
    Fenetre(int width, int height, const char* title);

    void listenToEvents() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }

        glfwTerminate();
    }

    void trace(const Carte& C);

    void scale(const std::vector<Point>& vector);

    void drawPoints(const std::vector<Point>& vector) const {
        for (const Point& point : vector) {
            glBegin(GL_POINTS);

            glColor3f(1.0, 1.0, 1.0);

            glVertex3d(GLFW_x(point), GLFW_y(point), GLFW_z(point));

            glEnd();
        }
    }

    static void clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void drawAll(const vector<Point>& vector1, const Carte& carte);

    int zMultiplier = 5;
private:
    void segment(const Point& a, const Point& b) const;

    [[nodiscard]] double GLFW_x(const Point& point) const {
        return ((margin_x + point.x() + offset_x) * global_k - 1);
        return (((margin_x + point.x() - offset_x) / (margin_x + width + margin_x)) * 2 - 1);
    }

    [[nodiscard]] double GLFW_y(const Point& point) const {
        return ((margin_y + point.y() + offset_y) * global_k - 1);
        return (((margin_y + point.y() - offset_y) / (margin_y + height + margin_y)) * 2 - 1);
    }

    [[nodiscard]] double GLFW_z(const Point& point) const {
        // return ((margin_z + point.z() + offset_z) * global_k - 1);
        return (((margin_z + point.z() - offset_z) / (margin_z + depth + margin_z)) * 0.2 - 1);
    }

    GLFWwindow* window;
    int width{}, height{}, depth{};
    double margin_x{}, margin_y{}, margin_z{};
    int offset_x{}, offset_y{}, offset_z{};
    double global_k{};

    void segment(const DemiCote& da, const DemiCote& db) const;

    void getColor(int z) const;
};


#endif //ALGO_GEO_FINAL_FENETRE_H