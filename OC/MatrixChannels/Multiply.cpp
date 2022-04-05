#include <thread>
#include <mutex>

#include "Multiply.h"

Matrix multiply(Matrix& a, Matrix& b){
    if(a._columns != b._rows){
        throw std::invalid_argument("these matrices can't be multiplied!");
    }
    Matrix c(a._rows, b._columns);

    for(int i=0; i<c._rows; ++i){
        for(int j=0; j<c._columns; ++j){
            for(int k=0; k<a._columns; ++k){
                c._m[i][j] += a._m[i][k]*b._m[k][j];
            }
        }
    }
    return c;
}
Matrix multiply(Matrix& a, Matrix& b, Matrix& c,
                int I, int J, int K, int n, int m, int l, std::mutex& mutex){
    for(int i = I; i< I+n; ++i){
        for(int j = J; j<J+l; ++j){
            for(int k=K; k<K+m; ++k){
                mutex.lock();
                c._m[i][j] += a._m[i][k]*b._m[k][j];
                mutex.unlock();
            }
        }
    }
    return c;
}
Matrix multiply_blocks(Matrix& a, Matrix& b, int nk, int mk, int lk){
    if(a._columns != b._rows){
        throw std::invalid_argument("these matrices can't be multiplied!");
    }
    if(a._rows%nk != 0 || a._columns%mk != 0 || b._columns%lk !=0){
        throw std::invalid_argument("these matrices can't be multiplied with this "
                                    "block size!");
    }
    int n = a._rows/nk; //rows in blocks(a)
    int m = a._columns/mk; //columns in blocks(a) || rows in blocks(b)
    int l = b._columns/lk; //columns in blocks (b)

    Matrix c(a._rows, b._columns);
    std::mutex mutex;
    std::vector<std::thread> th;

    for(int I=0; I<c._rows; I+=n){
        for(int J=0; J<c._columns; J+=l){
            for(int K=0; K<a._columns; K+=m){
                Matrix (&mr)(Matrix&, Matrix&, Matrix&,
                        int, int, int, int, int, int, std::mutex&) = multiply;
                th.emplace_back(mr, std::ref(a), std::ref(b), std::ref(c),
                                                I, J, K, n, m, l, std::ref(mutex));
            }
        }
    }
    for(auto& thread: th){
        thread.join();
    }
    return c;
}