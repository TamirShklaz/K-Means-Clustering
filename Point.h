//
// Created by tamir on 2019/08/15.
//

#ifndef AS2_POINT_H
#define AS2_POINT_H


#include <cmath>
#include <ostream>

class Point {
private:
    double x;
    double y;

public:
    Point(double x, double y);

    Point();

    double getX() const;

    double getY() const;

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    double getDistance(Point &p) {
        return sqrt(pow(p.x - this->x, 2) + pow(p.y - this->y, 2));
    }


};


#endif //AS2_POINT_H
