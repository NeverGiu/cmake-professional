#include "msg.h"
#include <vector>

int main()
{
	info::msg m;
	std::vector<std::string> strV = {"NGlift", "Mason", "NeverGiu", "Master"};
	for(int i=0; i<strV.size(); i++)
	{
		std::string a = m.message(i, strV[i]);
		if(a.compare("Mason2") == 0)
			return 2;// Skipped

		if(a.compare("NeverGiu0") == 0)
			return 0;// Passed
	}
	
	return 1;// Failed
}
