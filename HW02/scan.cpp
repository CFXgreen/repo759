#include "scan.h"

void scan(const float *arr, float *output, std::size_t n) {
    // Initialize the first element of the output array to be the same as the input
    if (n > 0) {
        output[0] = arr[0];
    }

    // For each subsequent element, compute the inclusive scan
    for (std::size_t i = 1; i < n; ++i) {
        output[i] = output[i - 1] + arr[i]; // Sum of the current and previous elements
    }
}