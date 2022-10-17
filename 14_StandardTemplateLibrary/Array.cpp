#include "Array.h"
#include <array>
#include <iostream>


void Array()
{
	/** Cannot grow in runtime */
	std::array<int, 5> arr{ 3,1,8,9,6 };
	for (int i(0); i < arr.size(); ++i)
	{
		arr[i] = i;
	}
	auto itr = arr.begin();

	for (auto x : arr)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
	arr.data();
}

void ArrayMain()
{
	Array();
}
