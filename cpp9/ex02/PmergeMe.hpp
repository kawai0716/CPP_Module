#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool parse(int argc, char** argv);
    void run();

private:
    std::vector<int> _input;

    bool parsePositiveInt(const std::string& s, int& out) const;
    void printSequence(const std::string& label, const std::vector<int>& seq) const;

    void sortVector(std::vector<int>& data) const;
    void sortDeque(std::deque<int>& data) const;
};

#endif
