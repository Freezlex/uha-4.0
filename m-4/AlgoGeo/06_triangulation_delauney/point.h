#ifndef POINT_H
#define POINT_H

class Point
{

public:
	// constructeurs
	Point() : d_x{0},d_y{0},d_z{0} {}
	Point(long x, long y, long z) : d_x{x},d_y{y},d_z{z} {}
	// accesseurs
	long x() const {return d_x;}
    long y() const {return d_y;}
    long z() const {return d_z;}

	// renvoie 1, -1 ou 0 selon que le point auquel la m�thode est appliqu�e est
	// � gauche de, � droite de, ou sur la droite (ab) orient�e de a vers b.
    double aGauche(const Point &a, const Point &b) const;

    bool operator<(const Point &r) const { if(d_x != r.d_x){return d_x < r.d_x;} else {return d_y < r.d_y; } }

    bool operator==(const Point &r) const { return (d_x == r.d_x && d_y == r.d_y); }

    double dansCercle(const Point &a, const Point &b, const Point &c);

private:
    // coordonn�es
    long d_x, d_y, d_z;
};

#endif
