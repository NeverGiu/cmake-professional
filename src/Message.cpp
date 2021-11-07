#include "Message.h"

#include <iostream>

#ifdef HAVE_UUID
#include <uuid/uuid.h>
#endif// HAVE_UUID

namespace Lib 
{
	std::ostream &Message::printObject(std::ostream &os)
	{
		os << "This is my message: " << std::endl;
		os << message_ << std::endl;
		os << "...and here is its UUID: " << getUUID();
		return os;
	}

#ifdef HAVE_UUID
	std::string getUUID()
	{
		uuid_t uuid;
		uuid_generate(uuid);
		char uuid_str[37];
		uuid_unparse_lower(uuid, uuid_str);
		uuid_clear(uuid);
		std::string uuid_cxx(uuid_str);
		return uuid_cxx;
	}
#else
	std::string getUUID()
	{
		return "Ooooops, no UUID for you!";
	}
#endif// HAVE_UUID
}
