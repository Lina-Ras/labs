#pragma once
#include <cmath>

struct Number {
public:
    double value;
    Number(double val) : value(val) {};
    Number():value(0){};
};

static Number add(Number a, Number b) {
    return Number(a.value + b.value);
}
Number operator+(Number a, Number b) {
    return Number(a.value + b.value);
}

static Number substract(Number a, Number b) {
    return Number(a.value - b.value);
}
static Number operator-(Number a, Number b) {
    return Number(a.value - b.value);
}

static Number multiply(Number a, Number b) {
    return Number(a.value * b.value);
}
static Number operator*(Number a, Number b) {
    return Number(a.value * b.value);
}

static Number divide(Number a, Number b) {
    return Number(a.value / b.value);
}
static Number operator/(Number a, Number b) {
    return Number(a.value / b.value);
}

static Number sqrtNumber(Number a) {
    return Number(sqrt(a.value));
}

static Number asinNumber(Number a) { //uses degrees
    return Number(asin(a.value)*180/3.1416);
}

static Number createNumber(double val) {
    return Number(val);
}


const Number ZERO_N(0);
const Number ONE_N(1);
