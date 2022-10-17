#include "Lists.h"
#include <iostream>
#include <list>
#include <forward_list>

void ListsMain()
{
	std::list<int> coll;

	for (int i(0); i < 5; ++i)
	{
		coll.push_back(i * 10);
	}

	auto itr = coll.begin();
	while (itr != coll.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	itr = coll.begin();
	coll.insert(itr, 800);
	coll.erase(itr);

	std::cout << "=== Forward List ===" << std::endl;

	std::forward_list<int> coll2;
	for (int i(0); i < 10; ++i)
	{
		coll2.push_front(i * 10);
	}

	for (auto x : coll2)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	coll2.insert_after(coll2.begin(), 10);

	for (auto x : coll2)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	coll2.erase_after(coll2.begin());

	for (auto x : coll2)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
