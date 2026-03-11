#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _rates = other._rates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& s) {
    std::string::size_type start = s.find_first_not_of(" \t\r\n");
    std::string::size_type end = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos) {
        return "";
    }
    return s.substr(start, end - start + 1);
}

bool BitcoinExchange::parseDateParts(const std::string& date, int& year, int& month, int& day) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    for (std::string::size_type i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (date[i] < '0' || date[i] > '9') {
            return false;
        }
    }
    year = std::atoi(date.substr(0, 4).c_str());
    month = std::atoi(date.substr(5, 2).c_str());
    day = std::atoi(date.substr(8, 2).c_str());
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    int year = 0;
    int month = 0;
    int day = 0;

    if (!parseDateParts(date, year, month, day)) {
        return false;
    }
    if (year <= 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    std::tm tmDate;
    std::memset(&tmDate, 0, sizeof(tmDate));
    tmDate.tm_year = year - 1900;
    tmDate.tm_mon = month - 1;
    tmDate.tm_mday = day;
    tmDate.tm_hour = 12;
    tmDate.tm_isdst = -1;

    std::time_t normalized = std::mktime(&tmDate);
    if (normalized == static_cast<std::time_t>(-1)) {
        return false;
    }
    if (tmDate.tm_year != year - 1900
        || tmDate.tm_mon != month - 1
        || tmDate.tm_mday != day) {
        return false;
    }
    return true;
}

bool BitcoinExchange::parseValue(const std::string& s, double& out) {
    std::stringstream ss(s);
    ss >> out;
    if (ss.fail()) {
        return false;
    }
    ss >> std::ws;
    if (!ss.eof()) {
        return false;
    }
    return true;
}

bool BitcoinExchange::loadDatabase(const std::string& path) {
    std::ifstream file(path.c_str());
    if (!file) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty()) {
            continue;
        }
        if (line == "date,exchange_rate") {
            continue;
        }
        std::string::size_type comma = line.find(',');
        if (comma == std::string::npos) {
            continue;
        }
        std::string date = trim(line.substr(0, comma));
        std::string rateStr = trim(line.substr(comma + 1));
        double rate = 0.0;
        if (!isValidDate(date) || !parseValue(rateStr, rate)) {
            continue;
        }
        _rates[date] = rate;
    }
    return !_rates.empty();
}

bool BitcoinExchange::tryGetRate(const std::string& date, double& rate) const {
    if (_rates.empty()) {
        return false;
    }
    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
    if (it != _rates.end() && it->first == date) {
        rate = it->second;
        return true;
    }
    if (it == _rates.begin()) {
        return false;
    }
    --it;
    rate = it->second;
    return true;
}
