#include "Vector.h"
#include <vector>
#include <iostream>


void VectorMain()
{
	std::vector<int> coll{ 1,2,3,4 };

	for (int i(0); i < 5; ++i)
	{
		coll.push_back(i * 10);
		std::cout << coll.size() << std::endl;
	}

	coll[0] = 100;

	for (int i(0); i < 5; ++i)
	{
		std::cout << coll[i] << " ";
	}
	std::cout << std::endl;

	auto itr = coll.begin();

	while (itr != coll.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	coll.insert(coll.begin(), 700);
	coll.erase(coll.end() - 5);
}
