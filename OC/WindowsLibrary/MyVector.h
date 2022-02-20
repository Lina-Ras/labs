#pragma once

#include"NumberLib.h"

#ifdef MYVECTOR_EXPORTS
#define MYVECTOR_API __declspec(dllexport)
#else
#define MYVECTOR_API __declspec(dllimport)
#endif


extern "C" class MYVECTOR_API Vector{

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