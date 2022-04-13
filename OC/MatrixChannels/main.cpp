#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>

#include "Matrix.h"

const int N = 100;

Matrix a(N,N);
Matrix b(N,N);
Matrix res(N,N);
std::mutex mutex;

Matrix multiply(){
    if(a._columns != b._rows){
        throw std::invalid_argument("these matrices can't be multiplied!");
    }

    for(int i=0; i<res._rows; ++i){
        for(int j=0; j<res._columns; ++j){
            for(int k=0; k<a._columns; ++k){
                res._m[i][j] += a._m[i][k]*b._m[k][j];
            }
        }
    }
    return res;
}
Matrix multiply(int I, int J, int K, int n, int m, int l){
    for(int i = I; i< I+n; ++i){
        for(int j = J; j<J+l; ++j){
            for(int k=K; k<K+m; ++k){
                mutex.lock();
                res._m[i][j] += a._m[i][k]*b._m[k][j];
                mutex.unlock();
            }
        }
    }
    return res;
}
Matrix multiply_blocks(int nk, int mk, int lk){
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

    std::vector<std::thread> th;

    for(int I=0; I<res._rows; I+=n){
        for(int J=0; J<res._columns; J+=l){
            for(int K=0; K<a._columns; K+=m){
                Matrix (&mr)(int, int, int, int, int, int) = multiply;
                th.emplace_back(mr, I, J, K, n, m, l);
            }
        }
    }
    for(auto& thread: th){
        thread.join();
    }
    return res;
}

int main() {
    a.generate_random();
    b.generate_random();
    auto start_1 = std::chrono::high_resolution_clock::now();
    multiply();
    auto stop_1 = std::chrono::high_resolution_clock::now();
    auto delta_1 = std::chrono::duration_cast<std::chrono::microseconds>(stop_1 - start_1);
    std::cout << "Without blocks: time = " << delta_1.count() << '\n';

    for(int k = 1; k<=N; ++k){ // k - amount of blocks in row/column
        if(N%k == 0) {
            auto start_2 = std::chrono::high_resolution_clock::now();
            multiply_blocks( k, k, k);
            auto stop_2 = std::chrono::high_resolution_clock::now();
            auto delta_2 = std::chrono::duration_cast<std::chrono::microseconds>(stop_2 -start_2);
            std::cout << "k: " << k << ",\t time = " << delta_2.count() << '\n';
        }
    }

    return 0;
}
