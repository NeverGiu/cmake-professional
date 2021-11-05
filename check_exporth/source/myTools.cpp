#include "myTools.h"
#include <string>

namespace obj
{
	std::string myTools::countMessage(int& i)
	{
		std::string&& result = std::to_string(i+1);
		return result + " items.";
	}
	void myTools::doInternalThings()
	{
		std::cout << "(Debug Message): ";
		return;
	}

#ifndef OMIT_DEPRECATED
	void myTools::oldImpl()
	{
		std::cout << "(Deprecated Message): Congratulations." << std::endl;
		return;
	}
#endif// OMIT_DEPRECATED

	// MYTOOLS_EXPORT void printMessage()
	API_MYTOOLS void printMessage()
	{
		myTools m;
		m.doInternalThings();

		std::cout << "You have got ";
		return;
	}
}
