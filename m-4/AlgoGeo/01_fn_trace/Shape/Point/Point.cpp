//
// Created by Freezlex on 14/11/2022.
//

#include "Point.h"

int Shape::Point::aGauche(const Point &a, const Point &b) const {
    return (b.x() - a.x())*(this->y() - a.y())-(this->x() - a.x())*(b.y() - a.y()); // (xb - xa)(yc - ya) - (xc - xa)(yb - ya)
}