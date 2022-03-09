#include <iostream>
#include "Vector.h"

int main()
{
    Number nine(9);
    Vector one = ONE_V;
    Vector c(nine, nine);

    std::cout << "c(" <<c.x.value << "," << c.y.value << ")\n";

    std::cout << "r = " << c.r().value << ", angle = " << c.angle().value <<'\n';

    std::cout << "c(" << c.x.value << "," << c.y.value << ") + o(1,1) = ";

    c = Vector::add(c, one);

    std::cout << "c(" << c.x.value << "," << c.y.value << ")\n";
    return 0;
}
