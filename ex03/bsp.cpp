#include "Point.h"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    const Point vecAB = calcVector(a, b);
    const Point vecBC = calcVector(b, c);
    const Point vecCA = calcVector(c, a);

    const Point vecAP = calcVector(a, point);
    const Point vecBP = calcVector(b, point);
    const Point vecCP = calcVector(c, point);

    const float crossAB = cross(vecAB, vecAP);
    const float crossBC = cross(vecBC, vecBP);
    const float crossCA = cross(vecCA, vecCP);

    return (crossAB > 0 && crossBC > 0 && crossCA > 0) ||
           (crossAB < 0 && crossBC < 0 && crossCA < 0);
}
