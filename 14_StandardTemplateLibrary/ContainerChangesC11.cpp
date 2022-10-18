#include "ContainerChangesC11.h"
#include "Integer.h"
#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <fstream>
#include <filesystem>


void Emplace()
{
	// Brace initialization
	std::vector<int> vInt1{ 1,2,3,4 };

	std::vector<Integer> vInt;
	//vInt.push_back(5); // Create Integer and move to vector container
	vInt.emplace_back(4); // Create Integer directly in vector container

	/** In such case no difference */
	Integer val{ 7 }; // Create Integer
	//vInt.emplace_back(val); // Get copied inside the vector
	//vInt.push_back(val); // Get copied inside the vector

	std::vector<std::pair<int, std::string>> data;
	data.push_back(std::pair<int, std::string>{100, "C++"});

	data.emplace_back(100, "C++"); // no need to specifiy std pair and other stuff

	std::vector<Integer> vInt2;
	vInt2.emplace_back(1);
	vInt2.emplace_back(2);
	vInt2.emplace_back(3);
}

void Shrink()
{
	std::vector<int> vInt3;

	for (size_t i = 0; i < 100; ++i)
	{
		vInt3.emplace_back(i);
	}

	std::cout << "Size : " << vInt3.size() << std::endl;
	std::cout << "Capacity : " << vInt3.capacity() << std::endl;

	vInt3.erase(vInt3.begin(), vInt3.end() - 10);
	vInt3.shrink_to_fit();

	std::cout << "After erase and shrink: " << std::endl;
	std::cout << "Size : " << vInt3.size() << std::endl;
	std::cout << "Capacity : " << vInt3.capacity() << std::endl;
}

void BufferImplementations()
{
	std::ifstream input("ContainerChangesC11.cpp");
	if (!input)
	{
		std::cout << "Could not open file\n";
		return;
	}

	auto size = std::filesystem::file_size("ContainerChangesC11.cpp");
	//std::vector<char> buffer;
	std::string buffer;

	buffer.resize(size);
	//char* buffer = new char[size] {};
	input.read(buffer.data(), size);
	std::cout << buffer.data() << std::endl;

	//delete[] buffer;
}

template<typename Container>
void Print(const Container& cont, const char* msg = "")
{
	std::cout << msg << "\n";
	for (const auto& element : cont)
	{
		std::cout << element << "\n";
	}
}

void Erase()
{
	std::vector<int> vInt{ 1, 2, 3, 4, 2 };
	std::list<int> lstInt{ 1, 2, 3, 4, 2 };
	std::deque<int> deqInt{ 1, 2, 3, 4, 2 };

	std::erase(vInt, 2);
	std::erase(lstInt, 2);
	std::erase(deqInt, 2);

	Print(vInt, "Vector");
	Print(lstInt, "List");
	Print(deqInt, "Deque");
}

void ContainerChangesC11Main()
{
	// Part I & PartII

	//Emplace();

	// Part III

	//Shrink();

	//BufferImplementations();

	// Part IV

	//Erase();

	// Part V

	std::set<int> data{1, 2, 6, 3};
	data.emplace_hint(data.begin(), 0);
	auto it = data.find(6);

	auto found = data.contains(6);


	std::set<std::string> names{ "Andrew", "Bob", "Rachel" };
	auto itr = names.find("Andrew");
	auto name = *itr;
	name[0] = 'E';
	names.erase(itr);
	names.insert(name);

	auto node = names.extract(itr);
	node.value()[0] = 'U';
	names.insert(std::move(node));

	Print(names, "Set");
}
