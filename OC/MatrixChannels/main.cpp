#include <chrono>
#include <iostream>

#include "Matrix.h"
#include "Multiply.h"

int main() {
    int N = 10;

    Matrix a(N,N);
    a.generate_random();
    Matrix b(N,N);
    b.generate_random();

    auto start_1 = std::chrono::high_resolution_clock::now();
    multiply(a, b);
    auto stop_1 = std::chrono::high_resolution_clock::now();
    auto delta_1 = std::chrono::duration_cast<std::chrono::microseconds>(stop_1 - start_1);
    std::cout << "Without blocks: time = " << delta_1.count() << '\n';

    for(int k = 1; k<=N; ++k){ // k - amount of blocks in row/column
        if(N%k == 0) {
            auto start_2 = std::chrono::high_resolution_clock::now();
            multiply_blocks(a, b, k, k, k);
            auto stop_2 = std::chrono::high_resolution_clock::now();
            auto delta_2 = std::chrono::duration_cast<std::chrono::microseconds>(stop_2 -start_2);
            std::cout << "k: " << k << ",\t time = " << delta_2.count() << '\n';
        }
    }

    return 0;
}
