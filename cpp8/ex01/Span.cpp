#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : _maxSize(n), _numbers()
{
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int value)
{
    if (_numbers.size() >= _maxSize)
        throw FullException();
    _numbers.push_back(value);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughException();

    std::vector<int> copy = _numbers;
    std::sort(copy.begin(), copy.end());

    unsigned int minSpan = static_cast<unsigned int>(copy[1] - copy[0]);
    for (std::size_t i = 1; i + 1 < copy.size(); ++i)
    {
        unsigned int span = static_cast<unsigned int>(copy[i + 1] - copy[i]);
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughException();

    int minValue = *std::min_element(_numbers.begin(), _numbers.end());
    int maxValue = *std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(maxValue - minValue);
}

const char *Span::FullException::what() const throw()
{
    return "Span is full";
}

const char *Span::NotEnoughException::what() const throw()
{
    return "Not enough numbers to compute span";
}
