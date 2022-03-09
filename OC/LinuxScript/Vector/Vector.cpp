#include "Vector.h"
#include <iostream>

Number Vector::r() {
    return Number::sqrtNumber(x * x + y * y);
}

Number Vector::angle() {
    Number r = Vector::r();
    if (r.value != 0)
        return Number::asinNumber(x / r);
    else
        return ZERO_N;
}

Vector Vector::add(Vector v1, Vector v2) {
    return Vector(v1.x + v2.x, v1.y + v2.y);
}