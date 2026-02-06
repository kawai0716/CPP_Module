#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>
#include <cstddef>

class Span
{
public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int value);

    template <typename It>
    void addNumber(It first, It last)
    {
        std::size_t count = static_cast<std::size_t>(std::distance(first, last));
        if (count > (_maxSize - _numbers.size()))
            throw FullException();
        _numbers.insert(_numbers.end(), first, last);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class FullException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class NotEnoughException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

private:
    Span();

    unsigned int _maxSize;
    std::vector<int> _numbers;
};

#endif
