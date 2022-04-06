#pragma once
#include <windows.h>
#include <iostream>
#include "Matrix.h"

struct KASTYL {
    Matrix& a;
    Matrix& b;
    Matrix& c;
    int I;
    int J;
    int K;
    int n;
    int m;
    int l;
    HANDLE mutex;
    KASTYL(Matrix& _a, Matrix& _b, Matrix& _c, int _I, int _J, int _K, int _n, int _m, int _l, HANDLE _mu):
        a(_a), b(_b), c(_c), I(_I), J(_J), K(_K), n(_n), m(_m), l(_l), mutex(_mu){}
};

Matrix multiply(Matrix& a, Matrix& b) {
    if (a._columns != b._rows) {
        throw std::invalid_argument("these matrices can't be multiplied!");
    }
    Matrix c(a._rows, b._columns);

    for (int i = 0; i < c._rows; ++i) {
        for (int j = 0; j < c._columns; ++j) {
            for (int k = 0; k < a._columns; ++k) {
                c._m[i][j] += a._m[i][k] * b._m[k][j];
            }
        }
    }
    return c;
}
DWORD WINAPI multiply(void* kastyl) {
    KASTYL* kas = static_cast<KASTYL*>(kastyl);
    for (int i = kas->I; i < kas->I + kas->n; ++i) {
        for (int j = kas->J; j < kas->J + kas->l; ++j) {
            for (int k = kas->K; k < kas->K + kas->m; ++k) {
                WaitForSingleObject(kas->mutex, INFINITE);
                kas->c._m[i][j] += kas->a._m[i][k] * kas->b._m[k][j];
                ReleaseMutex(kas->mutex);
            }
        }
    }
    ExitThread(0);
}
Matrix multiply_blocks(Matrix& a, Matrix& b, int nk, int mk, int lk) {
    if (a._columns != b._rows) {
        throw std::invalid_argument("these matrices can't be multiplied!");
    }
    if (a._rows % nk != 0 || a._columns % mk != 0 || b._columns % lk != 0) {
        throw std::invalid_argument("these matrices can't be multiplied with this "
            "block size!");
    }

    int n = a._rows / nk; //rows in blocks(a)
    int m = a._columns / mk; //columns in blocks(a) || rows in blocks(b)
    int l = b._columns / lk; //columns in blocks (b)

    Matrix c(a._rows, b._columns);
    CONST HANDLE mutex = CreateMutex(NULL, FALSE, NULL);
    std::vector<HANDLE> th;
    std::vector<KASTYL*> kasVector;

    int counter = 0;
    for (int I = 0; I < c._rows; I += n) {
        for (int J = 0; J < c._columns; J += l) {
            for (int K = 0; K < a._columns; K += m) {
                KASTYL* kas = new KASTYL(a,b,c,I,J,K,n,m,l,mutex);
                kasVector.emplace_back(kas);
                th.emplace_back(CreateThread(NULL, 0, &multiply, &kas, 0, NULL));
                if (NULL == th[counter]) {
                    throw std::runtime_error("Thread wasn't created!");
                }
                ++counter;
            }
        }
    }
    WaitForMultipleObjects(counter, &th[0], TRUE, INFINITE);

    for (int i = 0; i < counter; ++i) {
        CloseHandle(th[i]);
    }
    for (auto kas: kasVector) {
        delete kas;
    }
    CloseHandle(mutex);
    return c;
}