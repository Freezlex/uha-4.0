#include "point.h"

// renvoie 1, -1 ou 0 selon que le point auquel la méthode est appliquée est
// à gauche de, à droite de, ou sur la droite (ab) orientée de a vers b.
int Point::aGauche(const Point &a, const Point &b) const
{
	return (b.x() - a.x())*(this->y() - a.y())-(this->x() - a.x())*(b.y() - a.y()); // (xb - xa)(yc - ya) - (xc - xa)(yb - ya)
}

int Point::dansCercle(const Point &a, const Point &b, const Point &c) {

    return 0;
}
