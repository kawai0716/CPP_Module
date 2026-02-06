#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>

namespace {

struct Pair {
    int big;
    int small;
    Pair(int b, int s) : big(b), small(s) {}
};

static std::vector<size_t> buildJacobsthalOrder(size_t count) {
    std::vector<size_t> order;
    if (count == 0) {
        return order;
    }
    order.push_back(1);
    size_t prev = 1; // J1
    size_t curr = 1; // J2
    while (curr < count) {
        size_t next = curr + 2 * prev; // J(n) = J(n-1) + 2*J(n-2)
        size_t start = curr + 1;
        size_t end = next;
        if (end > count) {
            end = count;
        }
        for (size_t i = end; i >= start; --i) {
            order.push_back(i);
            if (i == start) {
                break;
            }
        }
        prev = curr;
        curr = next;
    }
    return order;
}

static void binaryInsertVector(std::vector<int>& chain, int value, int upperBoundValue) {
    std::vector<int>::iterator bound = std::upper_bound(chain.begin(), chain.end(), upperBoundValue);
    std::vector<int>::iterator pos = std::lower_bound(chain.begin(), bound, value);
    chain.insert(pos, value);
}

static void binaryInsertVectorFull(std::vector<int>& chain, int value) {
    std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), value);
    chain.insert(pos, value);
}

static void mergeInsertSortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    std::vector<Pair> pairs;
    pairs.reserve(arr.size() / 2);
    bool hasStraggler = (arr.size() % 2 == 1);
    int straggler = 0;

    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        pairs.push_back(Pair(a, b));
    }
    if (hasStraggler) {
        straggler = arr.back();
    }

    std::vector<int> mainChain;
    mainChain.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].big);
    }

    mergeInsertSortVector(mainChain);

    std::vector<Pair> sortedPairs;
    sortedPairs.reserve(pairs.size());
    std::vector<bool> used(pairs.size(), false);
    for (size_t i = 0; i < mainChain.size(); ++i) {
        int big = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].big == big) {
                used[j] = true;
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }

    std::vector<int> pending;
    pending.reserve(sortedPairs.size());
    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        pending.push_back(sortedPairs[i].small);
    }

    if (!pending.empty()) {
        binaryInsertVector(mainChain, pending[0], sortedPairs[0].big);
        std::vector<size_t> order = buildJacobsthalOrder(pending.size());
        for (size_t i = 0; i < order.size(); ++i) {
            size_t idx = order[i];
            if (idx == 1) {
                continue;
            }
            binaryInsertVector(mainChain, pending[idx - 1], sortedPairs[idx - 1].big);
        }
    }

    if (hasStraggler) {
        binaryInsertVectorFull(mainChain, straggler);
    }

    arr.swap(mainChain);
}

static void binaryInsertDeque(std::deque<int>& chain, int value, int upperBoundValue) {
    std::deque<int>::iterator bound = std::upper_bound(chain.begin(), chain.end(), upperBoundValue);
    std::deque<int>::iterator pos = std::lower_bound(chain.begin(), bound, value);
    chain.insert(pos, value);
}

static void binaryInsertDequeFull(std::deque<int>& chain, int value) {
    std::deque<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), value);
    chain.insert(pos, value);
}

static void mergeInsertSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    std::deque<Pair> pairs;
    bool hasStraggler = (arr.size() % 2 == 1);
    int straggler = 0;

    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        pairs.push_back(Pair(a, b));
    }
    if (hasStraggler) {
        straggler = arr.back();
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].big);
    }

    mergeInsertSortDeque(mainChain);

    std::deque<Pair> sortedPairs;
    std::vector<bool> used(pairs.size(), false);
    for (size_t i = 0; i < mainChain.size(); ++i) {
        int big = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].big == big) {
                used[j] = true;
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }

    std::deque<int> pending;
    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        pending.push_back(sortedPairs[i].small);
    }

    if (!pending.empty()) {
        binaryInsertDeque(mainChain, pending[0], sortedPairs[0].big);
        std::vector<size_t> order = buildJacobsthalOrder(pending.size());
        for (size_t i = 0; i < order.size(); ++i) {
            size_t idx = order[i];
            if (idx == 1) {
                continue;
            }
            binaryInsertDeque(mainChain, pending[idx - 1], sortedPairs[idx - 1].big);
        }
    }

    if (hasStraggler) {
        binaryInsertDequeFull(mainChain, straggler);
    }

    arr.swap(mainChain);
}

} // namespace

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _input(other._input) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _input = other._input;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parsePositiveInt(const std::string& s, int& out) const {
    if (s.empty()) {
        return false;
    }
    char* end = NULL;
    long value = std::strtol(s.c_str(), &end, 10);
    if (*end != '\0') {
        return false;
    }
    if (value <= 0 || value > INT_MAX) {
        return false;
    }
    out = static_cast<int>(value);
    return true;
}

bool PmergeMe::parse(int argc, char** argv) {
    if (argc < 2) {
        return false;
    }
    _input.clear();
    for (int i = 1; i < argc; ++i) {
        int value = 0;
        if (!parsePositiveInt(argv[i], value)) {
            return false;
        }
        _input.push_back(value);
    }
    return !_input.empty();
}

void PmergeMe::printSequence(const std::string& label, const std::vector<int>& seq) const {
    std::cout << label;
    for (size_t i = 0; i < seq.size(); ++i) {
        std::cout << seq[i];
        if (i + 1 < seq.size()) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

void PmergeMe::sortVector(std::vector<int>& data) const {
    mergeInsertSortVector(data);
}

void PmergeMe::sortDeque(std::deque<int>& data) const {
    mergeInsertSortDeque(data);
}

void PmergeMe::run() {
    printSequence("Before: ", _input);

    clock_t startVec = clock();
    std::vector<int> vec(_input.begin(), _input.end());
    sortVector(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    std::deque<int> deq(_input.begin(), _input.end());
    sortDeque(deq);
    clock_t endDeq = clock();

    printSequence("After: ", vec);

    double timeVec = static_cast<double>(endVec - startVec) * 1000000.0 / CLOCKS_PER_SEC;
    double timeDeq = static_cast<double>(endDeq - startDeq) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << _input.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _input.size()
              << " elements with std::deque : " << timeDeq << " us" << std::endl;
}
