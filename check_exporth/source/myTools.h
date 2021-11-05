// #include "mytools_export.h"
#include "export_myTools.h"
#include <string>
#include <iostream>

namespace obj
{
	// class MYTOOLS_EXPORT myTools
	class API_MYTOOLS myTools
	{
	public:
		REALLY_PRIVATE void doInternalThings();

		std::string countMessage(int& i);
		int someGlobalVar;

#ifndef OMIT_DEPRECATED
		MYTOOLS_DEPRECATED void oldImpl();
#endif// OMIT_DEPRECATED
	};

	API_MYTOOLS void printMessage();
	// MYTOOLS_EXPORT extern int someGlobalVar;
	// API_MYTOOLS extern int someGlobalVar;
}
