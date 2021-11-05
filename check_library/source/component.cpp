#include "component.h"

namespace obj 
{
	std::string component::stringBase(int &i)
	{
		std::string&& result = "(Debug message " + std::to_string(i) + "): ";
		return result;	
	}
}
