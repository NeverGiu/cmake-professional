#include <cstdlib>
#include <iostream>

#include <message/Message.h>

int main()
{
	Lib::Message say_hello("Hello, CMake Test!");
	std::cout << say_hello << std::endl;

	Lib::Message say_goodbye("Goodbye, CMake Test!");
	std::cout << say_goodbye << std::endl;

	return EXIT_SUCCESS;
}
