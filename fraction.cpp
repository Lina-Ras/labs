#include <iostream>
#include "fraction.h"

void input_blin(fraction &y){
    std::cout << "Please, enter numerator: ";
    std::cin>>y.numerator;
    std::cout<<'\n';
    std::cout << "Please, enter denominator: ";
    std::cin>>y.denominator;

    while (y.denominator==0){
        std::cout<<'\n';
        std::cout<< "Wrong value(0). Please, enter denominator: ";
        std::cin>>y.denominator;
    }
}
