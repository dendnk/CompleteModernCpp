#pragma once

#include "Integer.h"

class Employee
{
	std::string Name;
	Integer ID;


public:
	/*Employee(const std::string& NewName, const Integer& NewID)
		: Name{ NewName }
		, ID{ NewID }
	{
		std::cout << "Employee(const std::string & NewName, const Integer & NewID)" << std::endl;
	}*/

	template<typename T1, typename T2>
	Employee(T1&& NewName, T2&& NewID)
		: Name{ std::forward<T1>(NewName) }
		, ID{ std::forward<T2>(NewID) }
	{
		std::cout << "Employee(const std::string&& NewName, const Integer&& NewID)" << std::endl;
	}

};

template <typename T1, typename T2>
Employee* Create(T1&& Name, T2&& Id)
{
	return new Employee(std::forward<T1>(Name), std::forward<T2>(Id));
}

void PerfectForwardingMain();
