#include "Message.h"

#include <iostream>

namespace Lib 
{
	std::ostream &Message::printObject(std::ostream &os)
	{
		os << "This is my message: " << std::endl;
		os << message_;

		return os;
	}
}
