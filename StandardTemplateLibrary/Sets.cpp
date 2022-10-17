#include "Sets.h"
#include <iostream>
#include <set>
#include <functional>


void SetsMain()
{
	std::set<int> s{ 8,2,9,5,6,9 };

	std::set<int,std::greater<int>> s2{ 8,2,9,5,6,9 };

	std::multiset<int, std::greater<int>> s3{ 1,1,3,3,5,5 };

	s.insert(1);
	s.insert(7);
	s.insert(3);
	s.insert(4);

	auto itr = s.begin();
	//*itr = 3; - connot be done

	while (itr != s.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	s.erase(7);
	s.erase(s.begin());

	itr = s.begin();
	while (itr != s.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	itr = s.find(5);
	if (itr != s.end())
	{
		std::cout << *itr << std::endl;
	}
	std::cout << std::endl;

	itr = s2.begin();
	while (itr != s2.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	itr = s3.begin();
	while (itr != s3.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	auto founded = s3.equal_range(3);

	while (founded.first != founded.second)
	{
		std::cout << *founded.first++ << " ";
	}
	std::cout << std::endl;
}
