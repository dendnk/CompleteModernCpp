#include "Deque.h"
#include <iostream>
#include <deque>

void DequeMain()
{
	std::deque<int> coll;

	for (int i(0); i < 5; ++i)
	{
		coll.push_back(i * 10);
	}
	for (int i(0); i < 5; ++i)
	{
		coll.push_front(i * 10);
	}

	coll[0] = 100;

	auto itr = coll.begin();
	while (itr != coll.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	coll.insert(coll.begin(), 700);
	coll.erase(coll.end() - 5);
	coll.pop_back();
	coll.pop_front();
}
