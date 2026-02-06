#include <iostream>
#include <string>

#include "iter.hpp"

void printInt(const int& value)
{
	std::cout << value << std::endl;
}

void incrementInt(int& value)
{
	++value;
}

void printString(const std::string& value)
{
	std::cout << value << std::endl;
}

void appendBang(std::string& value)
{
	value += "!";
}

int main(void)
{
	int numbers[] = {1, 2, 3, 4};
	std::size_t n = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "ints (original):" << std::endl;
	iter(numbers, n, printInt);

	iter(numbers, n, incrementInt);
	std::cout << "ints (incremented):" << std::endl;
	iter(numbers, n, printInt);

	const int constNumbers[] = {10, 20, 30};
	std::size_t cn = sizeof(constNumbers) / sizeof(constNumbers[0]);
	std::cout << "const ints:" << std::endl;
	iter(constNumbers, cn, printInt);

	std::string words[] = {"hello", "cpp", "template"};
	std::size_t wn = sizeof(words) / sizeof(words[0]);
	iter(words, wn, appendBang);
	std::cout << "strings:" << std::endl;
	iter(words, wn, printString);

	return 0;
}
