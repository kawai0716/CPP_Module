#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& path);
    bool isValidDate(const std::string& date) const;
    bool tryGetRate(const std::string& date, double& rate) const;

    static bool parseValue(const std::string& s, double& out);

private:
    std::map<std::string, double> _rates;

    static std::string trim(const std::string& s);
    static bool parseDateParts(const std::string& date, int& year, int& month, int& day);
    static bool isLeapYear(int year);
    static int  daysInMonth(int year, int month);
};

#endif
