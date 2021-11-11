#include "sum_integers.h"

int main()
{
	auto integers = {1, 2, 3, 4, 5};

	int sum = calculate::test_sum(integers);
	if(sum == 15)
		return 0;// Passed
	else
		return 1;// Failed
}
