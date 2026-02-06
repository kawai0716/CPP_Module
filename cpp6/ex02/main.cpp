#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Base.hpp"

int main(void) {
	std::srand(static_cast<unsigned int>(std::time(0)));

	for (int i = 0; i < 5; ++i) {
		Base* p = generate();
		std::cout << "identify(Base*): ";
		identify(p);
		std::cout << "identify(Base&): ";
		identify(*p);
		delete p;
	}
	return 0;
}
