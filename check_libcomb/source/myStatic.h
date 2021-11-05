#include "mine_export.h"
#include <string>

namespace obj
{
	class MINE_EXPORT myStatic
	{
	public:
		std::string printStaticFunc(std::string&& str);
	};
}
