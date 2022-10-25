#include "StdAny.h"
#include <any>
#include <iostream>

/*
*	C++17 introduced std::any - wrapper class that can hold value of any arbitary type in a type-safe way
*	we can think about it as replcaement of void*
*	It contains both the value and its type
*	The value inside any can be accessed through : any_cast<>
*	May allocate memory on a heap to store the value
*	Throws an exception of type bad_any_cast on wrong type access
*
*	Need to call reset() when we finished work with std::any, because it may allocate memory on the heap.
*	It will destrouy the underlying object.
*
*	Before accessing to std::any we can check if it does contains any value
*	has_value() and get info about type using function type()
*
*	By default std::any_cast return copy of object. So if you want to modify object inside any you can apply reference cast
*	(for example std::any_cast<int&>)
*
*	We can also get a pointer to the object inside any_cast
*	just need to pass the address of the object
*
*	auto p = std::any_cast<int>(&Num);
*
*/


struct Number
{
	int Num;

	Number()
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	Number(int InitNumber)
		: Num(InitNumber)
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	~Number()
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	Number(const Number& Other)
	{
		std::cout << __FUNCSIG__ << std::endl;
		Num = Other.Num;
	}

	Number(Number&& Other) noexcept
	{
		std::cout << __FUNCSIG__ << std::endl;
		Num = Other.Num;
		Other.Num = 0;
	}

	Number& operator=(const Number& Other)
	{
		std::cout << __FUNCSIG__ << std::endl;

		if (this == &Other)
			return *this;

		Num = Other.Num;

		return *this;
	}

	Number& operator=(Number&& Other) noexcept
	{
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &Other)
			return *this;

		Num = Other.Num;

		return *this;
	}

	friend std::ostream& operator << (std::ostream& Out, const Number& InNum)
	{
		Out << InNum.Num;
		return Out;
	}
};

void Basics()
{
	std::any v1 = 123;
	//v1 = "Hello"s;

	if (v1.has_value())
	{
		if (v1.type() == typeid(int))
		{
			std::cout << "Int : " << std::any_cast<int>(v1) << std::endl;
		}
	}

	try
	{
		std::cout << std::any_cast<std::string>(v1) << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << "Exception : " << ex.what() << std::endl;
	}

	v1.reset();
}


void StdAnyMain()
{
	using namespace std::string_literals;

	//std::any Num1{ Number{100500} };

	auto Num1 = std::make_any<Number>(2022);

	//Num1.reset();

	Num1 = 2021;

	auto &Num2 = std::any_cast<int&>(Num1); // get reference and we could modify the value

	Num2 = 111;

	std::cout << std::any_cast<int>(Num1) << std::endl;

	auto p = std::any_cast<int>(&Num1);
	*p = 222;
	std::cout << std::any_cast<int*>(p) << std::endl;
	std::cout << std::any_cast<int>(Num1) << std::endl;
}
