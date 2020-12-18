#include <iostream>
#include <cassert>
#include "fraction.h"

void fraction::reduction(){

    int nod;
    int a(fraction::numerator), b(fraction::denominator);
    if(a<0){
        a=-a;
    }
    if(b<0){
        b=-b;
    }
    while(a!=0 && b!=0){
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }
    }
    nod=a+b;
    fraction::numerator=fraction::numerator/nod;
    fraction::denominator=fraction::denominator/nod;

    if(fraction::denominator<0) {
        fraction::numerator = -fraction::numerator;
        fraction::denominator = -fraction::denominator;
    }
}

void fraction::error() {
    if(fraction::numerator==0){
        std::cout<< "Be careful! You tried to divide by 0\n";
    }
}

void fraction::input(){
    std::cout << "Please, enter numerator: ";
    std::cin>>fraction::numerator;
    std::cout << "Please, enter denominator: ";
    std::cin>>fraction::denominator;

    while (fraction::denominator==0){
        std::cout<< "Wrong value(0). Please, enter denominator: ";
        std::cin>>fraction::denominator;
    }

    fraction::reduction();
    std::cout<<'\n';
}


void fraction::output(){
    int z=(int)(fraction::numerator/fraction::denominator);
    if((abs(fraction::numerator) >= abs(fraction::denominator)) || (fraction::numerator==0)){
        std::cout<<z;
        std::cout<<' ';
    }
    if((fraction::numerator-abs(z)*fraction::denominator)!=0){
    std::cout << ((fraction::numerator)-abs(z)*fraction::denominator) << '/' << fraction::denominator;
    }
    std::cout<< '\n';
}


int fraction::get_num(){
    return fraction::numerator;
}

int fraction::get_denom(){
    return fraction::denominator;
}


fraction fraction::sum(fraction frac){
    fraction result;
    result.numerator=fraction::numerator*frac.denominator+fraction::denominator*frac.numerator;
    result.denominator=fraction::denominator*frac.denominator;
    result.reduction();
    return result;

}

fraction fraction::multipl(fraction frac){
    fraction result;
    result.numerator=fraction::numerator*frac.numerator;
    result.denominator=fraction::denominator*frac.denominator;
    result.reduction();
    return result;
}

fraction fraction::div(fraction frac) {  //небяспечная!! (а/0)
        fraction result;
        frac.error();
        result.numerator = fraction::numerator * frac.denominator;
        result.denominator = fraction::denominator * frac.numerator;
        result.reduction();
        return result;
}




void fraction::sum(fraction &frac1,fraction &frac2){
    fraction::numerator=frac1.numerator*frac2.denominator+frac1.denominator*frac2.numerator;
    fraction::denominator=frac1.denominator*frac2.denominator;
    fraction::reduction();

}

void fraction::multipl(fraction &frac1,fraction &frac2){
    fraction::numerator = frac1.numerator * frac2.numerator;
    fraction::denominator = frac1.denominator * frac2.denominator;
    fraction::reduction();
}

void fraction::div(fraction &frac1,fraction &frac2){   //небяспечна!!!! (а/0)
    frac2.error();
    fraction::numerator = frac1.numerator * frac2.denominator;
    fraction::denominator = frac1.denominator * frac2.numerator;
    fraction::reduction();
}



fraction operator+(fraction &frac1, fraction &frac2) {
    fraction result;
    result.numerator=frac1.numerator*frac2.denominator+frac1.denominator*frac2.numerator;
    result.denominator=frac1.denominator*frac2.denominator;
    result.reduction();
    return result;
}

fraction operator*(fraction &frac1, fraction &frac2) {
    fraction result;
    result.numerator = frac1.numerator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;
    result.reduction();
    return result;
}

fraction operator/(fraction &frac1, fraction &frac2) {  //небяспечна!!!! (а/0)
    fraction result;
    frac2.error();
    result.numerator = frac1.numerator * frac2.denominator;
    result.denominator = frac1.denominator * frac2.numerator;
    result.reduction();
    return result;
}

