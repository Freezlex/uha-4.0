#include <iostream>
#include <vector>
#include "includes/graphics.h"
#include "point.h"
#include "carte.h"
#include "affichage.h"

int main() {
    opengraphsize(1000, 1000);

    Point p1 {0, 0};
    Point p2 { 450, 720};
    Point p3 {820, 810};

    Carte ca {};

    auto c1 = ca.ajouteCote(p1, p2);
    auto c2 = ca.ajouteCote(c1, p3);*
    ca.ajouteCote(c1->oppose(), c2->oppose());
    trace(ca);
    delay(500000);

    return 0;
}
