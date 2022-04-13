#include <ctime>
#include "Matrix.h"

Matrix::Matrix(int rows, int columns): _rows(rows), _columns(columns){
    _m.resize(_rows);
    for(auto& el : _m){
        el.resize(_columns);
    }
}

Matrix Matrix::operator+(const Matrix &b){
    if(_columns!=b._columns || _rows!=b._rows){
        throw std::invalid_argument("These matrices can't be added!");
    }
    Matrix c(_rows, _columns);
    for(int i=0; i<_rows; ++i){
        for(int j=0; j < _columns; ++j){
            c._m[i][j] = b._m[i][j] + _m[i][j];
        }
    }
    return c;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for(auto& vec: matrix._m){
        for(auto& el: vec){
            out << el << '\t';
        }
        out << '\n';
    }
    return out;
}

std::istream& operator>>(std::istream& in, Matrix& matrix) {
    for(int i=0; i< matrix._rows; ++i){
        for(int j=0; j<matrix._columns; ++j){
            in >> matrix._m[i][j];
        }
    }
    return in;
}


void Matrix::generate_random() {
    srand(time(nullptr));
    for(auto& vec: _m){
        for(auto& el: vec){
            el = rand()%100+1;
        }
    }
}
