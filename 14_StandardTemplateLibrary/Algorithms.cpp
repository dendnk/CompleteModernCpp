#include "Algorithms.h"
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>


class Employee
{
	std::string Name;
	int Id;
	std::string ProgramLanguage;

public:
	Employee(const std::string& InitName, int InitId, const std::string& InitProgramLanguage)
		: Name(InitName)
		, Id(InitId)
		, ProgramLanguage(InitProgramLanguage)
	{}

	const std::string& GetName() const { return Name; }

	int GetId() const { return Id; }

	const std::string& GetProgramLanguage() const { return ProgramLanguage; }

	/*bool operator<(const Employee& OtherEmp) const
	{
		return Id < OtherEmp.GetId();
	}*/
};

void Vector()
{
	std::vector<Employee> Employees{
		Employee{"Rachel", 1314, "Python"},
		Employee{"Andrew", 101, "C++"},
		Employee{"Bob", 11, "Java"} };

	std::sort(Employees.begin(), Employees.end(),
		[](const auto& emp1, const auto& emp2)
		{
			return emp1.GetName() < emp2.GetName();
		});

	for (const auto& emp : Employees)
	{
		std::cout
			<< " Id : " << emp.GetId()
			<< " | Name : " << emp.GetName()
			<< " | Program Language : " << emp.GetProgramLanguage()
			<< std::endl;
	}
}

struct EmpCompare
{
	bool operator () (const Employee& Emp1, const Employee& Emp2) const
	{
		return Emp1.GetId() < Emp2.GetId();
	}
};

void Set()
{
	std::set<Employee, EmpCompare> Employees{
		Employee{"Rachel", 1314, "Python"},
		Employee{"Andrew", 101, "C++"},
		Employee{"Bob", 11, "Java"} };

	for (const auto& emp : Employees)
	{
		std::cout
			<< " Id : " << emp.GetId()
			<< " | Name : " << emp.GetName()
			<< " | Program Language : " << emp.GetProgramLanguage()
			<< std::endl;
	}
}


void AlgorithmsMain()
{
	Set();
}
