#pragma once

#include <iosfwd>
#include <string>

#include "messageExport.h"

namespace Lib
{
	// The 'message_EXPORT' preprocessor directive is introduced in the declaration
	// of the Message class. This directive will allow the compiler to generate
	// symbols visible to users of the library.
	class message_EXPORT Message
	{
	public:
		Message(const std::string& m): message_(m){}
		friend std::ostream& operator<<(std::ostream& os, Message& obj)
		{
			return obj.printObject(os);
		}
	
	private:
		std::string message_;
		std::ostream& printObject(std::ostream& os);
	};

	// std::string getUUID();
}
