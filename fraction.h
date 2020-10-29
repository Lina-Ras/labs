#ifndef LABA6_CLASS_FRACTION_H
#define LABA6_CLASS_FRACTION_H


class fraction {
private:
public:
    int numerator;
    int denominator;


    void reduction();
    void input();
    fraction input(int a, int b);
    void output();

    int get_num();
    int get_denom();

    fraction sum(fraction frac);
    fraction multipl(fraction frac);
    fraction division(fraction frac); //функцыя небяспечная!! Можна падзяліць на 0 і атрымаць смецце

    void sum(fraction frac1,fraction frac2);
    void multipl(fraction frac1,fraction frac2);
    void div(fraction frac1,fraction frac2); //падыходзіць лдя дзялення на 0


    fraction(int a, int b) {
        if(b){
            numerator = a;
            denominator = b;
            fraction::reduction();
        }
    }

    fraction (fraction& a){
        numerator=a.numerator;
        denominator=a.denominator;
    }

};


#endif
