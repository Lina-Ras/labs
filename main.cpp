#include <iostream>
#include "fraction.h"


int main() {
    fraction x(0,1);
    x.input();
    fraction y(0, 1);
    y.input();

    fraction result(1,1);
    std::cout << "Result for sum: ";
    result=x.sum(y);
    result.output();

    std::cout << "Result for multipl: ";
    result=x.multipl(y);
    result.output();

    std::cout << "Result for div: ";
    result.div(x,y);
    result.output();

    return 0;
}
