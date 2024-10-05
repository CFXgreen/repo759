#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>  // For setting precision
#include "scan.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " n" << std::endl;
        return 1;
    }

    std::size_t n = std::atoi(argv[1]);

    float* input = new float[n];
    float* output = new float[n];

    std::srand(static_cast<unsigned>(std::time(0)));

    for (std::size_t i = 0; i < n; ++i) {
        input[i] = 2.0f * (static_cast<float>(std::rand()) / RAND_MAX) - 1.0f;
    }

    auto start = std::chrono::high_resolution_clock::now();
    scan(input, output, n);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float, std::milli> duration = end - start;

    // Set output precision to 2 decimal places
    std::cout << std::fixed << std::setprecision(2);

    std::cout << duration.count()<< std::endl;

    // Print the first and last elements of the scanned output array
    if (n > 0) {
        std::cout << output[0] << std::endl;
        std::cout << output[n - 1] << std::endl;
    }

    delete[] input;
    delete[] output;

    return 0;
}