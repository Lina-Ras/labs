#include <iostream>
#include <sstream>
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
        throw std::invalid_argument("Be careful! You tried to divide by 0");
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

void fraction::output(std::ostream &out){
    out << StringOutput();
}


std::string fraction::StringOutput(){
    std::stringstream result;
    std::string Output;
    int z=(int)(fraction::numerator/fraction::denominator);
    if(fraction::numerator<0){
        result << '-';
    }
    if((abs(fraction::numerator) >= abs(fraction::denominator)) || (fraction::numerator==0)){
        result<<abs(z);
    }
    if((abs(fraction::numerator)-abs(z*fraction::denominator))!=0){
        if(z!=0){
            result << ' ';
        }
        result<< (abs(fraction::numerator)-abs(z*fraction::denominator))<<'/'<< fraction::denominator;
    }
    Output = result.str();
    return Output;
}



int fraction::get_num(){
    return fraction::numerator;
}

int fraction::get_denom(){
    return fraction::denominator;
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



