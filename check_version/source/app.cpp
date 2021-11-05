#include "app.h"
#include "foobar_version.h"

namespace obj 
{
	void app::printVersion()
	{
		std::cout << "FOOBAR VERSION: " << getFooBarVersion() << "\n"
			<< "MAJOR = " << getFooBarVersionMajor() << "\n"
			<< "MINOR = " << getFooBarVersionMinor() << "\n"
			<< "PATCH = " << getFooBarVersionPatch() << "\n"
			<< "TWEAK = " << getFooBarVersionTweak()
			<< std::endl;

		return;
	}
}
