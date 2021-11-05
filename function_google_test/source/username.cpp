#include "username.h"

namespace test 
{
	std::string username::gmessage(int &i, std::string &s)
	{
		return s + std::to_string(i);
	}
}
