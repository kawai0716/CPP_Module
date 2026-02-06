#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

static std::string trim(const std::string& s) {
    std::string::size_type start = s.find_first_not_of(" \t\r\n");
    std::string::size_type end = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos) {
        return "";
    }
    return s.substr(start, end - start + 1);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    if (!exchange.loadDatabase("data.csv")) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(input, line)) {
        std::string trimmed = trim(line);
        if (trimmed.empty()) {
            continue;
        }
        if (trimmed == "date | value") {
            continue;
        }
        std::string::size_type pipe = trimmed.find('|');
        if (pipe == std::string::npos) {
            std::cerr << "Error: bad input => " << trimmed << std::endl;
            continue;
        }
        std::string date = trim(trimmed.substr(0, pipe));
        std::string valueStr = trim(trimmed.substr(pipe + 1));
        if (date.empty() || valueStr.empty() || !exchange.isValidDate(date)) {
            std::cerr << "Error: bad input => " << trimmed << std::endl;
            continue;
        }

        double value = 0.0;
        if (!BitcoinExchange::parseValue(valueStr, value)) {
            std::cerr << "Error: bad input => " << trimmed << std::endl;
            continue;
        }
        if (value < 0.0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000.0) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = 0.0;
        if (!exchange.tryGetRate(date, rate)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }

    return 0;
}
