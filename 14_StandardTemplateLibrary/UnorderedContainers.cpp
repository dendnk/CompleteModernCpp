#include "UnorderedContainers.h"
#include <iostream>
#include <unordered_set>
#include <unordered_map>


void UnorderSet()
{
	//std::unordered_set<std::string> setcon; - not allow duplicates
	std::unordered_multiset<std::string> setcon; // allow duplicates

	setcon.insert("Luke");
	setcon.insert("Obi-Wan Kenobi");
	setcon.insert("Leya");
	setcon.insert("Anakin");
	setcon.insert("Padme");
	setcon.insert("Qui-Gon Jinn");
	setcon.insert("Jar Jar");
	setcon.insert("Yoda");
	setcon.insert("Yoda");
	setcon.insert("Yoda");
	setcon.insert("Mace Windy");

	for (const auto& current : setcon)
	{
		std::cout << "Bucket #: " << setcon.bucket(current) << " contains : " << current << std::endl;
	}

	std::cout << "Bucket count : " << setcon.bucket_count() << std::endl;
	std::cout << "Number of elements : " << setcon.size() << std::endl;
	std::cout << "Load factor : " << setcon.load_factor() << std::endl;
}

void UnorderMap()
{
	//std::unordered_map<std::string, std::string> coll; // not allow duplicates
	std::unordered_multimap<std::string, std::string> coll; // allow duplicates

	// subscript [] operator not overloaded for multimap
	//coll["Yoda"] = "Grand master";
	//coll["Mace Windy"] = "Jedi Master";
	//coll["Qui-Gon Jinn"] = "Jedi Master";
	//coll["Obi-Wan Kenobi"] = "Jedi Knight";
	//coll["Anakin"] = "Youngling";

	coll.insert(std::make_pair("Yoda", "Grand master"));
	coll.insert(std::make_pair("Yoda", "Grand master"));
	coll.insert(std::make_pair("Mace Windy", "Jedi Master"));
	coll.insert(std::make_pair("Mace Windy", "Jedi Master"));

	for (const auto& x : coll)
	{
		std::cout << "Bucket # : " << coll.bucket(x.first) << " -> ";
		std::cout << x.first << " : " << x.second << std::endl;
	}
}

class Employee
{
	std::string Name;
	int Id;
public:
	Employee(const std::string& InitName, int InitId)
		: Name(InitName)
		, Id(InitId)
	{}

	const std::string& GetName() const
	{
		return Name;
	}

	const int GetId() const
	{
		return Id;
	}
};

struct EmployeeHash
{
	size_t operator()(const Employee& emp) const
	{
		auto s1 = std::hash<std::string>{}(emp.GetName());
		auto s2 = std::hash<int>{}(emp.GetId());

		return s1 ^ s2;
	}
};

struct EmpEquality
{
	bool operator()(const Employee& emp1, const Employee& emp2) const
	{
		return emp1.GetId() == emp2.GetId()	&& emp1.GetName() == emp2.GetName();
	}
};

void Hashes()
{
	std::hash<std::string> h;
	std::cout << "Hash : " << h("Hello") << std::endl;

	std::unordered_set<Employee, EmployeeHash, EmpEquality> coll;

	coll.insert(Employee{ "Bob", 123 });
	coll.insert(Employee{ "Rohn", 456 });
	coll.insert(Employee{ "John", 789 });

	for (const auto& x : coll)
	{
		std::cout << x.GetId() << " : " << x.GetName() << std::endl;
	}
}

void UnorderedContainersMain()
{
	//UnorderSet();
	//UnorderMap();

	Hashes();
}
