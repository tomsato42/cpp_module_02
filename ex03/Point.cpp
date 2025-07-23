#include "Point.h"
#include <iostream>

Point::Point() : x(Fixed(0)), y(Fixed(0)) {
}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {
}

Point::~Point() {
}

Point::Point(const Point &other) : x(other.x), y(other.y) {
}

Point &Point::operator=(const Point &other) {
    if (this != &other) {
    }
    return *this;
}

void Point::print() const {
    std::cout << "Point(" << x.toFloat() << ", " << y.toFloat() << ")" << std::endl;
}

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}

Point calcVector(const Point &a, const Point &b) {
    return Point(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
}

float cross(const Point &a, const Point &b) {
    return (a.getX().toFloat() * b.getY().toFloat()) - (a.getY().toFloat() * b.getX().toFloat());
}
