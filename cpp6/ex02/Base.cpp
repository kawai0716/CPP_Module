#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base::~Base() {}

Base* generate(void) {
	int choice = std::rand() % 3;
	if (choice == 0)
		return new A();
	if (choice == 1)
		return new B();
	return new C();
}

void identify(Base* p) {
	if (p == 0) {
		std::cout << "null" << std::endl;
		return;
	}
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception&) {
	}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception&) {
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (const std::exception&) {
	}
	std::cout << "Unknown" << std::endl;
}
