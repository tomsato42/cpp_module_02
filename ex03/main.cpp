#include <iostream>
#include <iomanip>

#include "Fixed.h"
#include "Point.h"

static std::string printBool(const bool b) {
    return b ? std::string(" inside of triangle") : std::string("outside of triangle");
}

bool bsp(Point const a, Point const b, Point const c, Point const point);

void printLog(const Point &point1, const bool result) {
    std::cout << "Point " << std::setw(10) << std::fixed << std::setprecision(7) << point1.getX().toFloat() << ", "
            << std::setw(10) << point1.getY().toFloat()
            << " is " << printBool(result) << std::endl;
}

int main() {
    const Point a(0, 0);
    const Point b(5, 0);
    const Point c(0, 5);

    std::cout << "Point a: " << a.getX().toFloat() << ", " << a.getY().toFloat() << std::endl;
    std::cout << "Point b: " << b.getX().toFloat() << ", " << b.getY().toFloat() << std::endl;
    std::cout << "Point c: " << c.getX().toFloat() << ", " << c.getY().toFloat() << std::endl;

    std::cout << std::endl;

    const Point point1(1, 1);
    const bool result = bsp(a, b, c, point1);
    printLog(point1, result);

    const Point point2(6, 6);
    const bool result2 = bsp(a, b, c, point2);
    printLog(point2, result2);

    const Point point3(-1, -1);
    const bool result3 = bsp(a, b, c, point3);
    printLog(point3, result3);

    const Point point4(0.1,0.1);
    const bool result4 = bsp(a, b, c, point4);
    printLog(point4, result4);

    const Point point5(0,0);
    const bool result5 = bsp(a, b, c, point5);
    printLog(point5, result5);


    return 0;
}
