#include "net.h"

namespace obj
{
	std::string net::netFunc(int& i)
	{
		return "Net working..." + std::to_string(i);
	}
}
