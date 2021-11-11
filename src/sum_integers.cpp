#include "sum_integers.h"
#include <ostream>

namespace calculate
{
	// class sum_integers
	// {
	// public:
	//         sum_integers(const std::vector<int>& i): integers_(i){}
	//         friend std::ostream& operator<<(std::ostream& os, sum_integers& obj)
	//         {
	//                 return obj.objValue(os);
	//         }
	// private:
	//         std::vector<int> integers_;
	//         std::ostream& objValue(std::ostream& os);
	// };
	std::ostream &sum_integers::objValue(std::ostream &os)
	{
		auto sum = 0;
		for(int i = 0; i < integers_.size(); i++)
		{
			sum += integers_[i];
		}

		os << sum;
		return os;
	}

	int test_sum(const std::vector<int>& integers)
	{
		auto sum = 0;
		for(int i = 0; i < integers.size(); i++)
		{
			sum += integers[i];
		}

		return sum;
	}
}
