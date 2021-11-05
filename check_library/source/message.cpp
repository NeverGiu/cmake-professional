#include "message.h"
#include "component.h"

namespace obj
{
	void message::printMsg()
	{
		component cop;
		for(int i=1; i<10; i++)
		{
			std::cout << cop.stringBase(i) 
				<< "You have picked up an item(you've already got "
				<< i << " items)." << std::endl;
		}

		return;
	}
}
