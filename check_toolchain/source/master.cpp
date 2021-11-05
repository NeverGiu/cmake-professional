#include "foo.h"

#include <iostream>

int main()
{
	using namespace obj;
	foo f;
	for(int i=0; i<3; i++)
	{
		std::cout << "(Debug Message): " << f.countFunc(i) << std::endl;
	}

	return 0;
}
