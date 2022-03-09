#ifndef NUMBER_NUMBER_H
#define NUMBER_NUMBER_H

class Number {
public:
    double value;
    Number(double val);
    Number();

    Number add(Number a);
    Number operator+(Number a);

    Number substract(Number a);
    Number operator-(Number a);

    Number multiply(Number a);
    Number operator*(Number a);

    Number divide(Number a);
    Number operator/(Number a);

    static Number sqrtNumber(Number a);
    static Number asinNumber(Number a);

    static Number createNumber(double val);
};


const Number ZERO_N(0);
const Number ONE_N(1);

#endif
