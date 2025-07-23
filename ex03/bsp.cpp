#include "Point.h"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    const Point vecAB = calcVector(a, b);
    const Point vecBC = calcVector(b, c);
    const Point vecCA = calcVector(c, a);

    const Point vecAP = calcVector(a, point);
    const Point vecBP = calcVector(b, point);
    const Point vecCP = calcVector(c, point);

    const float crossAB = cross(vecAB, vecAP);
    const float crossBC = cross(vecBC, vecBP);
    const float crossCA = cross(vecCA, vecCP);

    return (crossAB > 0 - 1e-15 && crossBC > 0 - 1e-15 && crossCA > 0 - 1e-15) ||
           (crossAB < 1e-15 && crossBC < 1e-15 && crossCA < 1e-15);
}
