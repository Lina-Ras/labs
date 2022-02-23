#pragma once
#include <cmath>
#include "NumberLib.h"

    Number::Number(double val) : value(val) {};
    Number::Number() :value(0) {};

    Number Number::add(Number a) {
        return Number(a.value + this->value);
    }
    Number Number::operator+(Number a) {
        return Number(a.value + this->value);
    }

    Number Number::substract(Number a) {
        return Number(a.value - this->value);
    }
    Number Number::operator-(Number a) {
        return Number(this->value - a.value);
    }

   Number Number::multiply(Number a) {
        return Number(a.value * this->value);
    }
    Number Number::operator*(Number a) {
        return Number(a.value * this->value);
    }

    Number Number::divide(Number a) {
        return Number(this->value / a.value);
    }
    Number Number::operator/(Number a) {
        return Number(this->value / a.value);
    }

    Number Number::sqrtNumber(Number a) {
        return Number(sqrt(a.value));
    }

    Number Number::asinNumber(Number a) { //uses degrees
        return Number(asin(a.value) * 180 / 3.1416);
    }

    Number Number::createNumber(double val) {
        return Number(val);
    }
