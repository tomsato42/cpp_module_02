#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
public:
    Point();

    Point(float x, float y);

    ~Point();

    Point(const Point &other);

    Point &operator=(const Point &other);

    void print() const;

    Fixed getX() const;

    Fixed getY() const;

private:
    Fixed const x;
    Fixed const y;
};

Point calcVector(const Point &a, const Point &b);

float cross(const Point &a, const Point &b);
#endif // POINT_H
