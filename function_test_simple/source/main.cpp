#include "msg.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
	// Debug:
	// for(int i=1; i<3; i++)
	// {
	//         auto s = argv[i];
	//         std::cout << "(Debug Message): 'argv["
	//                 << i << "]'" << argv[i] << std::endl;
	// }
	info::msg m;
	std::string s = argv[2];
	int a = std::stoi(argv[1]);

	std::cout << "(Print Message): "
		<< m.message(a, s) << std::endl;

	return EXIT_SUCCESS;
}
