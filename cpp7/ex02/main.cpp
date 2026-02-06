#include <iostream>
#include <string>

#include "Array.hpp"

int main(void)
{
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = static_cast<int>(i) * 10;

	std::cout << "numbers:" << std::endl;
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << std::endl;

	Array<int> copy(numbers);
	numbers[0] = 999;
	std::cout << "copy (after original change):" << std::endl;
	for (unsigned int i = 0; i < copy.size(); ++i)
		std::cout << copy[i] << std::endl;

	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "template";
	words[2] = "array";
	std::cout << "words:" << std::endl;
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << std::endl;

	try {
		std::cout << "out of bounds: " << numbers[42] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	return 0;
}
