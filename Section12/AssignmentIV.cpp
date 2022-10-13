#include "AssignmentIV.h"
#include <string>
#include "Integer.h"


/*
* In Steps:
* Step 1 - simple function to create intance of integer classs and initialize it with argument
*
*	int* CreateObject(int arg)
*	{
*		return new int{arg};
*	}
*
* Step 2 - make this function for any class
*
*	template<typename T>
*	T* CreateObject(int arg)
*	{
*		return new T{arg};
*	}
*
* Step 3 - make this function with any class of argument
*
*	template<typename T, typename Arg>
*	T* CreateObject(const Arg& arg)
*	{
*		return new T{arg};
*	}
*
* Step 4 - make this function with any number of arguments (use variadic argument)
*
*	template<typename T, typename... Args>
*	T* CreateObject(const Args&... args)
*	{
*		return new T{args};
*	}
*
* Step 5 - improve by forwarding arguments into the constructor (final implementation)
*
*	template<typename T, typename...Arg>
*	T* CreateObject(Arg&&... args)
*	{
*		return new T{ std::forward<Arg>(args)... };
*	}
*
*/

template<typename T, typename...Arg>
T* CreateObject(Arg&&... args)
{
	return new T{ std::forward<Arg>(args)... };
}


class Employee {
	std::string Name;
	int Id;
	int Salary;
public:
	Employee(std::string Name, int Id, int Salary)
		: Name(Name)
		, Id(Id)
		, Salary(Salary)
	{}
};

class Contact {
	std::string Name;
	long int Phone;
	std::string Address;
	std::string Email;
public:
	Contact(std::string Name, long int Phone, std::string Address, std::string Email)
		: Name(Name)
		, Phone(Phone)
		, Address(Address)
		, Email(Email)
	{}
};


void AssignmentIV_Main()
{
	std::string* s = CreateObject<std::string>();//Default construction

	int* p1 = CreateObject<int>(5);

	auto p2 = CreateObject<Integer>(9);

	Employee* emp = CreateObject<Employee>(
		"Bob",    //Name
		101,      //Id
		1000);   //Salary

	Contact* p = CreateObject<Contact>(
		"Joey",                //Name
		987654321,             //Phone number
		"Boulevard Road, Sgr", //Address
		"joey@poash.com");    //Email
}
