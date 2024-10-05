#include <iostream>
#include <vector>
#include <chrono>
#include "matmul.h"

int main() {
    unsigned int n = 1000; // Size of the matrices

    // Dynamically allocate matrices A, B, and C
    std::vector<double> A(n * n);
    std::vector<double> B(n * n);
    std::vector<double> C1(n * n);
    std::vector<double> C2(n * n);
    std::vector<double> C3(n * n);
    std::vector<double> C4(n * n);

    // Fill A and B with random values
    for (unsigned int i = 0; i < n * n; ++i) {
        A[i] = static_cast<double>(rand()) / RAND_MAX;
        B[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    // Time mmul1
    auto start = std::chrono::high_resolution_clock::now();
    mmul1(A.data(), B.data(), C1.data(), n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration1 = end - start;
    std::cout << duration1.count() << std::endl;
    std::cout << C1[n * n - 1] << std::endl;

    // Time mmul2
    start = std::chrono::high_resolution_clock::now();
    mmul2(A.data(), B.data(), C2.data(), n);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration2 = end - start;
    std::cout << duration2.count() << std::endl;
    std::cout << C2[n * n - 1] << std::endl;

    // Time mmul3
    start = std::chrono::high_resolution_clock::now();
    mmul3(A.data(), B.data(), C3.data(), n);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration3 = end - start;
    std::cout << duration3.count() << std::endl;
    std::cout << C3[n * n - 1] << std::endl;

    // Time mmul4
    start = std::chrono::high_resolution_clock::now();
    mmul4(A, B, C4.data(), n);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration4 = end - start;
    std::cout << duration4.count() << std::endl;
    std::cout << C4[n * n - 1] << std::endl;

    return 0;
}
