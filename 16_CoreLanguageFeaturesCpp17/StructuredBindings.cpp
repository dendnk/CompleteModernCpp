#include "StructuredBindings.h"
#include <iostream>
#include <map>


struct Person
{
	std::string Name;
	int Age;

	Person() = default;
	Person(const std::string& InitName, int InitAge)
		: Name(InitName)
		, Age(InitAge)
	{}
};


struct StructWithArray
{
	int Arr1[8];
	char Ch1[256];
};


void StructuredBindingsMain()
{
	Person Pers{ "Andrew", 14 };

	//Assign to different variables

	auto TempName1 = Pers.Name;
	auto TempAge1 = Pers.Age;

	//Initialize with structure binding

	auto [TempName2, TempAge2] = Pers; // here will be created the anonymous entity - copy of Person object and copy of the members
	auto &[TempName3, TempAge3] = Pers; // here will be created the anonymous entity - the reference of Pers

	const auto &[TempName4, TempAge4] = Pers; // here will be created the anonymous entity - the reference of Pers

	TempAge3 = 10; // it will also reflect in the Person object Pers
	//TempAge4 = 10; // you cannot modify Age and Name cause the const qualifier

	std::cout << Pers.Age << std::endl;

	std::pair<int, int> pi{ 3,5 };
	auto [key, value] = Pers;

	std::map<int, std::string> ErrorTypes{
		{1, "Not available"},
		{2, "Not in use"}
	};

	for (auto Error : ErrorTypes)
	{
		std::cout << Error.first << " : " << Error.second << std::endl;
	}

	// With structure binding

	std::cout << "With structure binding" << std::endl;
	for (auto [ErrorNum, ErrorInfo] : ErrorTypes)
	{
		std::cout << ErrorNum << " : " << ErrorInfo << std::endl;
	}

	int Array[] = { 1,2,3 };
	auto [a, b, c] = Array; // Number of variables should match the number of elemnts in the object. It should exactly match

	auto Array2 = Array; // if we use auto here, Array2 is a pointer, not Array; Array automatically decays to a pointer



	StructWithArray Str;

	auto [s1, s2] = Str; // s1 and s2 will be array types. Arrays inside structure not decay to a pointers
}
