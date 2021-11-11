#pragma once

#include <iosfwd>
#include <string>

/*! \file Message.h */ 

/*! \class Message
 * \brief Forwards string to screen
 * \author NeverGiu
 * \date 2021/11/11
 */

namespace Lib
{
	class Message
	{
	public:
		/*! \brief Constructor from a string
		 * \param[in] m a message
		 */
		Message(const std::string& m): message_(m){}

		/*! \brief Constructor from a character array
		 * \param[in] m a message
		 */
		Message(const char* m): message_(std::string(m)){}

		friend std::ostream& operator<<(std::ostream& os, Message& obj)
		{
			return obj.printObject(os);
		}
	
	private:
		/*! The message to be forwarded to screen */
		std::string message_;

		/*! \brief Function to forward message to screen 
		 * \param[in, out] os output stream
		 */
		std::ostream& printObject(std::ostream& os);
	};
}
