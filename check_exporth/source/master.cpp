#include "myTools.h"

int main()
{
	using namespace obj;
	printMessage();

	myTools m;
	m.someGlobalVar = 17;

	std::cout << m.countMessage(m.someGlobalVar) << std::endl;

#ifndef OMIT_DEPRECATED
	m.oldImpl();
#endif// OMIT_DEPRECATED

	return 0;
}
