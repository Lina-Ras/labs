#ifndef MATRIXCHANNELS_MULTIPLY_H
#define MATRIXCHANNELS_MULTIPLY_H

#include "Matrix.h"

Matrix multiply(Matrix& a, Matrix& b);
Matrix multiply(Matrix& a, Matrix& b, Matrix& c,int I, int J, int K, int n, int m, int l);
Matrix multiply_blocks(Matrix& a, Matrix& b, int nk, int mk, int lk);

#endif
