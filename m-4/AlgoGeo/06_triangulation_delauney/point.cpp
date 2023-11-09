#include "point.h"
#include <vector>
#include <math.h>

// renvoie 1, -1 ou 0 selon que le point auquel la méthode est appliquée est
// à gauche de, à droite de, ou sur la droite (ab) orientée de a vers b.
double Point::aGauche(const Point &a, const Point &b) const
{
	return (b.x() - a.x())*(this->y() - a.y())-(this->x() - a.x())*(b.y() - a.y()); // (xb - xa)(yc - ya) - (xc - xa)(yb - ya)
}

double Point::dansCercle(const Point &a, const Point &b, const Point &c) {

    long long mathA = (a.x() - this->x());
    long long mathB = (a.y() - this->y());
    long long mathC = (pow(a.x() - this->x(), 2) + pow(a.y() - this->y(), 2));
    long long mathD = (b.x() - this->x());
    long long mathE = (b.y() - this->y());
    long long mathF = (pow(b.x() - this->x(), 2) + pow(b.y() - this->y(), 2));
    long long mathG = (c.x() - this->x());
    long long mathH = (c.y() - this->y());
    long long mathI = (pow(c.x() - this->x(), 2) + pow(c.y() - this->y(), 2));
    long long resultat = (mathA*mathE*mathI)-(mathA*mathF*mathH)+(mathB*mathF*mathG)-(mathB*mathD*mathI)+(mathC*mathD*mathH)-(mathC*mathE*mathG);
    if(resultat > 0){
        //Dans le cercle
        return 1;
    }else if(resultat < 0){
        //Ext du cercle
        return -1;
    }else{
        //Sur le cercle
        return 0;
    }
}
