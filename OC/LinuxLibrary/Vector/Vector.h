#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include "../Number/Number.h"

class Vector{
public:
	Number x, y;
	Vector(Number a, Number b): x(a), y(b){}
	Vector(): x(ZERO_N), y(ONE_N){}

	Number r();
	Number angle();

	static Vector add(Vector v1, Vector v2);
};

const Vector ZERO_V(ZERO_N, ZERO_N);
const Vector ONE_V(ONE_N, ONE_N);

#endif //VECTOR_VECTOR_H
