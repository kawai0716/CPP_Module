#include "RPN.hpp"

#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    long long result = 0;
    if (!RPN::evaluate(argv[1], result)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << result << std::endl;
    return 0;
}
