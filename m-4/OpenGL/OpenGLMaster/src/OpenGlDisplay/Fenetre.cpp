#include "glad/glad.h"
#include <algorithm>
#include "Fenetre.h"


Fenetre::Fenetre(int width, int height, const char* title) {
    if (!glfwInit()) throw std::invalid_argument("Initialisation");

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::invalid_argument("Creation");
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height){glViewport(0, 0, width, height); });

    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(4);
}

void Fenetre::scale(const std::vector<Point>& vector) {
    const Point& firstPoint = vector[0];
    int min_x = firstPoint.x(), max_x = firstPoint.x();
    int min_y = firstPoint.y(), max_y = firstPoint.y();
    int min_z = firstPoint.z(), max_z = firstPoint.z();

    for (const Point& point : vector) {
        if (point.x() < min_x) min_x = point.x();
        if (max_x < point.x()) max_x = point.x();

        if (point.y() < min_y) min_y = point.y();
        if (max_y < point.y()) max_y = point.y();

        if (point.z() < min_z) min_z = point.z();
        if (max_z < point.z()) max_z = point.z();
    }

    width = max_x - min_x;
    height = max_y - min_y;
    depth = max_z - min_z;


    std::cout << global_k << std::endl;

    margin_x = (width * 0.10) / 2;
    margin_y = (height * 0.10) / 2;
    margin_z = (depth * 0.10) / 2;

    std::vector<double> global_k_vector{
            2.0 / (width + margin_x * 2),
            2.0 / (height + margin_y * 2),
            2.0 / (depth + margin_z * 2)
    };

    auto it = min_element(std::begin(global_k_vector), std::end(global_k_vector)); // C++11
    global_k = *it;

    offset_x = min_x;
    offset_y = min_y;
    offset_z = min_z;
}

void Fenetre::getColor(int z) const {
    if (z < 20 * zMultiplier) {
        glColor3f(0.3, 0.7, 1.0);
    }
    else if (z < 350 * zMultiplier) {
        glColor3f(0.0, 0.8, 0.3);
    }
    else if (z < 650 * zMultiplier) {
        glColor3f(0.6, 0.4, 0.1);
    }
    else {
        glColor3f(1.0, 1.0, 1.0);
    }
}

void Fenetre::segment(const DemiCote& da, const DemiCote& db) const {
    Point a = da.coordonnees();
    Point b = db.coordonnees();
    glBegin(GL_LINES);

    //glColor3f(0.0, 1.0, 0.0);

    getColor(a.z());
    glVertex3d(GLFW_x(a), GLFW_y(a), GLFW_z(a));

    getColor(b.z());
    glVertex3d(GLFW_x(b), GLFW_y(b), GLFW_z(b));

    glEnd();
}

void Fenetre::segment(const Point& a, const Point& b) const {
    glBegin(GL_LINES);

    glColor3f(1.0, 0.0, 0.0);

    glVertex3f(GLFW_x(a), GLFW_y(a), GLFW_z(a));
    glVertex3f(GLFW_x(b), GLFW_y(b), GLFW_z(b));

    printf("X: %f, Y: %f\n", GLFW_x(a), GLFW_y(a));
    printf("X: %f, Y: %f\n\n", GLFW_x(b), GLFW_y(b));

    glEnd();
}

void Fenetre::trace(const Carte& C) {

    for (int i = 0; i < C.nbDemiCotes(); ++i) {
        DemiCote* demiCote = C.demiCote(i);

        if (demiCote->marque() == 2) continue;

        DemiCote* oppose = demiCote->oppose();

        segment(*demiCote, *oppose);

        demiCote->changeMarque(2);
        oppose->changeMarque(2);
    }

    for (int i = 0; i < C.nbDemiCotes(); ++i) {
        C.demiCote(i)->changeMarque(0);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Fenetre::drawAll(const vector<Point>& vector, const Carte& carte) {
    Fenetre::clear();
    //drawPoints(vector);
    trace(carte);
}
