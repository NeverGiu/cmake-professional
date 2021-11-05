#include "username.h"

#include <iostream>

int main(int argc, char* argv[])
{
	test::username gt;

	int i = std::stoi(argv[1]);
	std::string s = argv[2];
	if(gt.gmessage(i, s).compare("NeverGiu17") == 0)
	{
		std::cout << "Main Testing Pasted." << std::endl;
		return 0;// Pasted
	}

	if(gt.gmessage(i, s).compare("NGlift23") == 0)
	{
		std::cout << "Main Testing Skiped." << std::endl;
		return 2;// Skiped
	}

	std::cout << "Main Testing Failed." << std::endl;
	return 1;// Failed
}
