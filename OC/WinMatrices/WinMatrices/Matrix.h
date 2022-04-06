#ifndef MATRIXCHANNELS_MATRIX_H
#define MATRIXCHANNELS_MATRIX_H
#pragma once

#include <vector>
#include <fstream>

class Matrix {
public:
    //Matrix()= default;
    Matrix(int rows, int columns);

    Matrix operator+(const Matrix& b);

    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& in, Matrix& matrix);

    void generate_random();

    std::vector<std::vector<double>> _m;
    int _rows;
    int _columns;
};


#endif

