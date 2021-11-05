#include "myShared.h"
#include "myStatic.h"
#include "other.h"

namespace obj
{
	void myShared::printSharedFunc()
	{
		myStatic ms;
		using namespace obj;
		other ot;
		for(int i=0; i<3; i++)
		{
			std::cout << "Shared func() depend on: " 
				<< ot.printOtherFunc(i)
				<< ms.printStaticFunc("--> static func().") << std::endl;
		}
		return;
	}
}
