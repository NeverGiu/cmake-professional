#include "msg.h"

namespace info
{
	std::string msg::message(int &i, std::string &s)
	{
		return s + std::to_string(i);
	}
}
