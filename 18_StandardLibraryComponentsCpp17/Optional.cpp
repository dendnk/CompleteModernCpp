#include "Optional.h"
#include <iostream>
#include <optional>


/*
*   std::optional - new type, used when function may or may not return a value
*   it si also called a nullable type
*
*   No value is represented by std::nullopt
*   std::optional is a value type - so, it can be copied through deep copy
*   it doesnt need to allocate any memory on heap
*   you cannot stroe references inside std::optional. If you do that, then the program is  ill-formed and it will not compile
*
*   std::optional provides several overloaded operators and fucntions to access the value inside safely
*   may throw std::bad_optional_access if it does not contain any value inside
*
*/


const char* GetErrorString(int ErrorNumber)
{
	switch (ErrorNumber)
	{
	case 0:
		return "Invalid input\n";
		break;
	case 1:
		return "Connection not established yet\n";
		break;
	default:
		return "";
		break;
	}
}

std::optional<const char*> GetErrorStringOp(int ErrorNumber)
{
	switch (ErrorNumber)
	{
	case 0:
		return "Invalid input\n";
		break;
	case 1:
		return "Connection not established yet\n";
		break;
	default:
		return std::nullopt;
		break;
	}
}

class ContactName
{
	std::string First;
	std::optional<std::string> Middle;
	std::string Last;

public:
	ContactName(const std::string& InitFirst, const std::optional<std::string> InitMiddle, const std::string& InitLast)
		: First(InitFirst)
		, Middle(InitMiddle)
		, Last(InitLast)
	{}

	void Print()
	{
		std::cout << First << ' ';
		std::cout << Middle.value_or("") << ' ';
		std::cout << Last << std::endl;
	}

};


void OptionalMain()
{
	ContactName Name1{ "Radjesh", "Amarian", "Kutrapali" };
	ContactName Name2{ "Leonard", std::nullopt, "Hophstedder" };

	Name1.Print();
	Name2.Print();


	std::optional Value{5};
	auto Value2 = std::make_optional(36.f);

	if (Value.has_value())
	{
		std::cout << Value.value() << std::endl; // if value is empty, it will throw bad_optional_access exception while invoke value() - safe way
	}

	if (Value2)
	{
		std::cout << *Value2 << std::endl; // if value is empty, the behavior is undefined while application dereference operator
	}

	auto Message = GetErrorString(1);
	if (strlen(Message) != 0)
	{
		std::cout << Message;
	}
	else
	{
		std::cout << "Unknown error number!\n";
	}

	// optional can be reused. Old variable will be destroyed
	Value = 100;
	Value.reset();

	try
	{
		auto ErrorMessage = GetErrorStringOp(4);

		std::cout << ErrorMessage.value_or("value or() : Unknown error number!\n"); // if it not contains value it returns the input argument value

		//std::cout << *ErrorMessage; // undefined behavior
		std::cout << ErrorMessage.value(); // without checking it should throw exception (with value == 4)

		if (ErrorMessage.has_value())
		{
			std::cout << ErrorMessage.value();
		}
		else
		{
			std::cout << "Unknown error number!\n";
		}

		if (ErrorMessage)
		{
			std::cout << ErrorMessage.value();
		}
		else
		{
			std::cout << "Unknown error number!\n";
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
