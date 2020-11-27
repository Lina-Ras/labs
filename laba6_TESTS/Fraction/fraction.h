#include<iostream>

class fraction {
private:
    int numerator;
    int denominator;
    fraction() {
    }
    void error();
    void reduction();
public:
    void input();
    void output(std::ostream &out);
    std::string StringOutput();

    int get_num();
    int get_denom();

    friend fraction operator+(fraction &frac1,fraction &frac2);
    friend fraction operator*(fraction &frac1,fraction &frac2);
    friend fraction operator/(fraction &frac1,fraction &frac2);


    fraction(int a, int b) {
        if(b){
            numerator = a;
            denominator = b;
            fraction::reduction();
        }
        else
            throw std::invalid_argument("Be careful! You tried to divide by 0");
    }

    fraction (fraction& a){
        numerator=a.numerator;
        denominator=a.denominator;
    }

};


