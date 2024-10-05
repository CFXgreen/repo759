#include "convolution.h"

// Computes the result of applying a mask to an image (convolution process)
void convolve(const float *image, float *output, std::size_t n, const float *mask, std::size_t m) {
    // m is always odd, so we can compute half of the mask size
    std::size_t half_m = m / 2;

    for (std::size_t x = 0; x < n; ++x) {
        for (std::size_t y = 0; y < n; ++y) {
            float sum = 0.0f;

            for (std::size_t i = 0; i < m; ++i) {
                for (std::size_t j = 0; j < m; ++j) {
                    // Calculate the corresponding pixel in the image
                    int image_x = static_cast<int>(x) + static_cast<int>(i) - static_cast<int>(half_m);
                    int image_y = static_cast<int>(y) + static_cast<int>(j) - static_cast<int>(half_m);

                    // Check if within bounds (now image_x and image_y are ints)
                    if (image_x >= 0 && image_x < static_cast<int>(n) && image_y >= 0 && image_y < static_cast<int>(n)) {
                        sum += image[image_x * n + image_y] * mask[i * m + j];
                    } else {
                        // Handle out-of-bounds cases
                        if ((image_x < 0 || image_x >= static_cast<int>(n)) && (image_y < 0 || image_y >= static_cast<int>(n))) {
                            // Corner case: add 0
                            sum += 0;
                        } else {
                            // Edge case: add 1
                            sum += 1.0f * mask[i * m + j];
                        }
                    }
                }
            }

            output[x * n + y] = sum;
        }
    }
}
