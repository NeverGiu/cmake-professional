#include "app.h"
#include "foobar_version.h"

namespace obj 
{
	void app::printVersion()
	{
		std::cout << "FOOBAR GIT HASH: " << getFooBarGitHash() << std::endl;
		std::cout << "FOOBAR COMMITS SINCE VERSION CHANGE: " << getFooBarCommitsSinceVersionChange() << std::endl;

		return;
	}
}
