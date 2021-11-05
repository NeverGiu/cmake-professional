#include "username.h"
#include <vector>

int main()
{
	test::username gt;

	std::vector<std::string> vStr = {"Master", "NeverGiu", "NGlift", "Jim"};
	for(int i=0; i<vStr.size(); i++)
	{
		if(gt.gmessage(i, vStr[i]).compare("NeverGiu0") == 0)
			return 0;// Pasted

		if(gt.gmessage(i, vStr[i]).compare("NGlift2") == 0)
			return 2;// Skiped

	}

	return 1;// Failed
}
