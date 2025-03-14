#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
    Fixed x1 = a.getX(), y1 = a.getY();
    Fixed x2 = b.getX(), y2 = b.getY();
    Fixed x3 = c.getX(), y3 = c.getY();
    Fixed determinant = Fixed(fabs(((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1)).toFloat()));
    return (determinant * Fixed(0.5f));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);
    if (A == A1 + A2 + A3)
        return true;
    return false;
}