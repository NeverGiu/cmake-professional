#include "other.h"

namespace obj
{
	std::string other::printOtherFunc(int& i)
	{
		return "(mark " + std::to_string(i+1) + ") ";
	}
}
