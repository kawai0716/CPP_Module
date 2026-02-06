#include <iostream>

#include "Serializer.hpp"

int main(void) {
	Data data;
	data.id = 42;
	data.value = 3.14;
	data.tag = 'A';

	Data* original = &data;
	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "original: " << original << std::endl;
	std::cout << "restored: " << restored << std::endl;
	std::cout << "equal: " << (original == restored ? "yes" : "no") << std::endl;
	std::cout << "data.id: " << restored->id << std::endl;
	std::cout << "data.value: " << restored->value << std::endl;
	std::cout << "data.tag: " << restored->tag << std::endl;
	return 0;
}
