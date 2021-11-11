#include "sum_integers.h"

#include <numeric>

int main()
{
	std::vector<int> integers(1000);
	std::iota(integers.begin(), integers.end(), 1);

	int sum = calculate::test_sum(integers);
	if(sum == 500500)
		return 0;// Passed
	else
		return 1;// Failed
}
