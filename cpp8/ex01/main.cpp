#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span big(10000);
    std::vector<int> data;
    data.reserve(10000);
    for (int i = 0; i < 10000; ++i)
        data.push_back(i * 3);

    big.addNumber(data.begin(), data.end());
    std::cout << "big shortest: " << big.shortestSpan() << std::endl;
    std::cout << "big longest: " << big.longestSpan() << std::endl;

    try
    {
        big.addNumber(1);
    }
    catch (const std::exception &e)
    {
        std::cout << "overflow: " << e.what() << std::endl;
    }

    return 0;
}
