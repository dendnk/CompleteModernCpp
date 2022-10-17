#include "Maps.h"
#include <iostream>
#include <map>


void MapsMain()
{
	std::map<int, std::string> m{ {1, "Harry"}
								, {2, "Hermione"}
								, {3, "Ron"} };

	m.insert(std::pair<int, std::string>(10, "Simus"));
	m.insert(std::make_pair(11, "Din"));

	m[0] = "Draco";
	m[0] = "Albus";

	m.erase(0);

	for (const auto& current : m)
	{
		std::cout << current.first << ":" << current.second << std::endl;
	}

	auto findresult = m.find(1);
	if (findresult != m.end())
	{
		std::cout << "Found : " << findresult->second << std::endl;
	}

	m[100] = "Dolores";
	m[100] = "Dolores";

	for (const auto& current : m)
	{
		std::cout << current.first << ":" << current.second << std::endl;
	}

	std::multimap<int, std::string> mm{ {1, "Ironman"}
									, {2, "Hulk"}
									, {3, "Thor"} };

	//mm[3] = "Thor"; - subscript not overloaded
	mm.insert(std::make_pair(3, "Thor"));

	for (const auto& current : mm)
	{
		std::cout << current.first << ":" << current.second << std::endl;
	}

	std::cout << " Search : " << std::endl;;

	auto foundedrange = mm.equal_range(3);
	while (foundedrange.first != foundedrange.second)
	{
		std::cout << foundedrange.first->first << ":" << foundedrange.first->second << std::endl;
		foundedrange.first++;
	}
}
