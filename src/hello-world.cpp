#include <cstdlib>
#include <iostream>

#include "Message.h"

int main()
{
	Lib::Message say_hello("Hello, CMake World!");
	std::cout << say_hello << std::endl;

	Lib::Message say_goodbye("Goodbye, CMake World!");
	std::cout << say_goodbye << std::endl;

	return EXIT_SUCCESS;
}
