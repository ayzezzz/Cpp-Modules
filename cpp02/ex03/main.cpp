#include "Point.hpp"

int main()
{
    Point A(0, 0);
    Point B(10, 0);
    Point C(5, 5);

    // Point p(3.5f, 3.0f);
    //  Point p(4.9f, 2.9f)
    //  Point p(11, 10);
    //  Point p(5, 0);
    Point p(7, 7);

    if (bsp(A, B, C, p))
        std::cout << "That's true, man 🦅 🦅 " << std::endl;
    else
        std::cout << "False, man 🦃 🦃" << std::endl;

    return 0;
}
