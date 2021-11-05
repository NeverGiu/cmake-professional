#include "net.h"
#include "util.h"

#include <iostream>

int main()
{
	std::cout << "Start working..." << std::endl;

	using namespace obj;
	net n;
	util u;

	for(int i=1; i<10; i++)
	{
		std::cout << n.netFunc(i) << std::endl;
		std::cout << u.utilFunc(i) << std::endl;
	}
	
	std::cout << "Working End." << std::endl;

	return 0;
}
