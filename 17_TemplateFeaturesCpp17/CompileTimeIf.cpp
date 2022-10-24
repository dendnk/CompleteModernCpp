#include "CompileTimeIf.h"
#include <iostream>
#include <type_traits>
#include <string>


template<typename T>
void Print(const T& Value)
{
	if constexpr (std::is_array_v<T>)
	{
		std::cout << "Array : " << std::endl;
		for (auto Temp : Value)
		{
			std::cout << Temp << " ";
		}
		std::cout << std::endl;
	}
	else if constexpr (std::is_pointer_v<T>)
	{
		std::cout << "Pointer with value : " << *Value << std::endl;
	}
	else
	{
		std::cout << "Value : " << Value << std::endl;
	}
}

template<typename T>
std::string ToString(T Value)
{
	if constexpr (std::is_arithmetic_v<T>)
	{
		return std::to_string(Value);
	}
	else
	{
		return std::string{ Value };
	}
}

void CheckMode()
{
	if constexpr (sizeof(void*) == 4)
	{
		std::cout << "32-bit" << std::endl;
	}
	else if constexpr (sizeof(void*) == 8)
	{
		std::cout << "64-bit" << std::endl;
	}
	else
	{
		std::cout << "Unknown mode" << std::endl;
	}

	/*
	*	While using compile time if statements
	*	Compiler will discard the statements of those conditions
	*	that have been evaluated to false at compile time
	*	but the code in discarded blocks should be valid code
	*/
}


void CompileTimeIfMain()
{
	CheckMode();

	int Value2{ 5 };
	auto Str = ToString(Value2);

	Print(Str);


	int value{ 10 };

	Print(value);

	Print(&value);

	int Arr[] = { 1,2,3,4,5 };
	Print(Arr);

	auto Str1 = std::string{"Hello Iren!"};
	Print(Str1);
}
