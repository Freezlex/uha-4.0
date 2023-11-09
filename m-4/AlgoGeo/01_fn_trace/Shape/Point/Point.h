//
// Created by Freezlex on 14/11/2022.
//

#ifndef ALGOGEO_POINT_H
#define ALGOGEO_POINT_H


namespace Shape{
    class Point {

    public:
        Point() : d_x{0}, d_y{0} {}
        Point(int x, int y) : d_x{x},d_y{y} {}

        int x() const {return d_x;}
        int y() const {return d_y;}

        // renvoie 1, -1 ou 0 selon que le point auquel la méthode est appliquée est
        // à gauche de, à droite de, ou sur la droite (ab) orientée de a vers b.
        int aGauche(const Point &a, const Point &b) const;

        bool operator<(const Point &r) const { if(d_x != r.d_x){return d_x < r.d_x;} else {return d_y < r.d_y; } }

    private:
        int d_x, d_y;
    };
}


#endif //ALGOGEO_POINT_H
