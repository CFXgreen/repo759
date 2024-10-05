#include "matmul.h"
#include <vector>

void mmul1(const double* A, const double* B, double* C, const unsigned int n) {
    // Initialize C to all zeros
    for (unsigned int i = 0; i < n * n; ++i) {
        C[i] = 0.0;
    }

    // Perform matrix multiplication C = A * B
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            for (unsigned int k = 0; k < n; ++k) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}

void mmul2(const double* A, const double* B, double* C, const unsigned int n) {
    // Initialize C to all zeros
    for (unsigned int i = 0; i < n * n; ++i) {
        C[i] = 0.0;
    }

    // Perform matrix multiplication with swapped inner loops
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int k = 0; k < n; ++k) {
            for (unsigned int j = 0; j < n; ++j) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}

void mmul3(const double* A, const double* B, double* C, const unsigned int n) {
    // Initialize C to all zeros
    for (unsigned int i = 0; i < n * n; ++i) {
        C[i] = 0.0;
    }

    // Perform matrix multiplication with the outer loop iterating over columns
    for (unsigned int j = 0; j < n; ++j) {
        for (unsigned int i = 0; i < n; ++i) {
            for (unsigned int k = 0; k < n; ++k) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}

void mmul4(const std::vector<double>& A, const std::vector<double>& B, double* C, const unsigned int n) {
    // Initialize C to all zeros
    for (unsigned int i = 0; i < n * n; ++i) {
        C[i] = 0.0;
    }

    // Perform matrix multiplication C = A * B
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            for (unsigned int k = 0; k < n; ++k) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}
