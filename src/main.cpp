#include "sum_integers.h"

#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	std::cout << "The nums ";
	std::vector<int> integers;
	for(int i = 1; i < argc; i++)
	{
		integers.push_back(std::stoi(argv[i]));
	}
	for(auto j = 0; j < integers.size(); j++)
	{
		if(j != integers.size()-1)
			std::cout << integers[j] << "+";
		else
			std::cout << integers[j];
	}
	
	calculate::sum_integers	print_sum(integers);
	std::cout << " = " << print_sum << std::endl;

	return EXIT_SUCCESS;
}
