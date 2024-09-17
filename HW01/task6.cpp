#include <iostream>
#include <cstdio>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " N" << std::endl;
        return 1;
    }

    int N = std::stoi(argv[1]);

    // Print 0 to N
    for(int i = 0; i <= N; i++) {
        std::printf("%d ", i);
    }
    std::printf("\n");

    // Print N to 0
    for(int i = N; i >= 0; i--) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
