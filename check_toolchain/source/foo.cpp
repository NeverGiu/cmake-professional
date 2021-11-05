#include "foo.h"

namespace obj
{
	std::string foo::countFunc(int &i)
	{
		return "you've got " + std::to_string(i+1) + " items.";
	}
}
