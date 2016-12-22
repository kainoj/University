#include <iostream>
#include <vector>
#include "divided_difference.h"

int main() {
	//div_diff x({-2,-1,0,1}, {2,0,2,-4});
	//div_diff y({1,2,-1,-2,0}, {-4,27,0,2,2});

	div_diff z( {-2,-1, 1, 2}, 
				{32, 8,24,16});
	z.show();;

	std::cout<< z.getValue(1,1) << "\n";
	return 0;
}