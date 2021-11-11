#pragma once

#include <iosfwd>
#include <vector>

namespace calculate
{
	class sum_integers
	{
	public:
		sum_integers(const std::vector<int>& i): integers_(i){}
		friend std::ostream& operator<<(std::ostream& os, sum_integers& obj)
		{
			return obj.objValue(os);
		}
	private:
		std::vector<int> integers_;
		std::ostream& objValue(std::ostream& os);
	};

	int test_sum(const std::vector<int>& integers);
}
