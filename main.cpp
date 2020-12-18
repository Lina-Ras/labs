#include <iostream>
#include "fraction.h"


int main() {
    fraction x(-20,48);
    x.input();
    fraction y(34,55);
    y.input();

    fraction result(1,1);
    std::cout << "Result for sum: \n";
    result=x.sum(y);
    result.output();
    result.sum(x, y);
    result.output();
    result=x+y;
    result.output();
    std::cout << '\n';

    std::cout << "Result for div: \n";
    result=x.div(y);
    result.output();
    result.div(x,y);
    result.output();
    result=x/y;
    result.output();

    std::cout << "Result for multipl: \n";
    result=x.multipl(y);
    result.output();
    result.multipl(x, y);
    result.output();
    result=x*y;
    result.output();
    std::cout << '\n';

    return 0;
}
