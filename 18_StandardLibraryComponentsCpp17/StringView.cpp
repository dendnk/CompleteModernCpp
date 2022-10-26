#include "StringView.h"
#include <string_view>
#include <iostream>


using namespace std::string_view_literals;

void BasicUsage()
{
	// One way to initialize string view :
	std::string_view sv1 = "Hello world!";

	// Other way to initialize string view : using std::string
	std::string str1{ "Hello C++17!" };
	std::string_view sv2{ str1 };

	// Another way to initialize string view : using literals
	auto sv3 = "Using\0literals"sv; // we can embed mu;tiple null characters

	std::cout << "Size : " << sv3.length() << std::endl; // Size : 14
	std::cout << sv3 << std::endl; // Usingliterals

	// data() can return a null pointer if sv3 not initialized
	std::cout << "data() : " << sv3.data() << std::endl; // data() : Using

	std::cout << sv3[0] << std::endl; // no checking - cangive undefined bjavor with wrong index
	std::cout << sv3.at(0) << std::endl; // throw out_of_range exception

	auto f = sv3.find("literals");
	if (f != std::string::npos)
	{
		std::cout << "Found at index : " << f << std::endl;
	}

	// Not remove the first n characters from the string, but simly point to the position after the first n characters
	sv3.remove_prefix(3);
	std::cout << sv3 << std::endl;

	sv3.remove_suffix(2);
	std::cout << sv3 << std::endl;


	auto sv4 = sv1.substr(0, 5);

	std::cout << sv4 << std::endl; // will print Hello
	std::cout << sv4.data() << std::endl; // will print the entire string : Hello world!
}


#pragma region Example1
/*
*	void PrettyPrint(const std::string& Message, char ch)
*
*	Here the const std::string can be replaced by std::string_view ,
*	because when not modify the string inside function, and when we call PrettyrPrint("Abcd", '$') it construct std::string object
*	We can save the cost of construction of standard string object
*
*	void PrettyPrint(std::string_view Message, char ch)
*/
void PrettyPrint(std::string_view Message, char ch)
{
	for (int x(0); x < Message.length(); ++x)
	{
		std::cout << ch;
	}

	std::cout << std::endl;
	std::cout << Message << std::endl;
}
#pragma endregion

#pragma region Example2

/*
*	std::string& CombineName(std::string& Name, const std::string& Last, ETitle Title)
*
*	In this example we can use std::string_view for the Last name, because we will not change it^
*
*	std::string& CombineName(std::string& Name, std::string_view Last, ETitle Title)
*/

enum class ETitle
{
	Mr,
	Mrs,
	Ms
};

std::string& CombineName(std::string& Name, std::string_view Last, ETitle Title)
{
	switch (Title)
	{
	case ETitle::Mr:
		Name.insert(0, "Mr. ");
		break;
	case ETitle::Mrs:
		Name.insert(0, "Mrs. ");
		break;
	case ETitle::Ms:
		Name.insert(0, "Ms. ");
		break;
	default:
		break;
	}

	return Name += Last;
}

#pragma endregion

#pragma region Example3
class Person
{
	std::string Name;
public:
	Person(std::string InitName) : Name(std::move(InitName))
	{}

	void Print() const
	{
		std::cout << Name << std::endl;
	}
};

Person CreatePerson(std::string_view Name)
{
	std::string N{ Name };
	Person P{ N };
	return P;
}

void WithClass()
{
	//std::string n{};
	// if we costruct like this, than it will construct std::string object here and than copy inside class member Name object
	Person P{ "Bruce Wayne" };

	// If we replace name member in Person class to std::string_view and its constructor,
	// when we create a person like this
	// Person P {"Batman"s}; - it will cause construction of temporary std::string here
	// and then it will be assigned to std::string_view in constructor and
	// Name will internnaly point to the buffer of the std::string that holds string "Batman"
	// but after the constructor returns the temporary std::string will be destroyed
	// and Name will left with a dangling pointer

	// If we will use a factory method CreatePerson(std::string_view Name)
	// it will return Person object by value, so it will create a copy of object in P :  Person P{n};
	// But at the end of the scope CreatePerson()
	// local variable std::string N{ Name } will be destroyed
	// and the string_view inside P object will be dangling


	P.Print();
}
#pragma endregion

void StringViewMain()
{
	PrettyPrint("Hello world !", '#');
}
