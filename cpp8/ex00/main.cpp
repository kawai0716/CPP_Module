#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "found in vector: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "vector error: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << "found in list: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "list error: " << e.what() << std::endl;
    }

    return 0;
}
