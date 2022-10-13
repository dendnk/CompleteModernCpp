#include <iostream>

#include "VariadicTemplates.h"
#include "Integer.h"


//template<typename T>
//void Print(std::initializer_list<T> args)
//{
//	for (const auto& x : args)
//	{
//		std::cout << x << std::endl;
//	}
//}


void Print()
{
	std::cout << std::endl;
}

// Template parameter pack
template<typename T, typename... Params>
// Function parameter pack
void Print(T &&a, Params&&... args)
{
	std::cout << a;

	if (sizeof...(args) != 0)
	{
		std::cout << ", ";
	}
	Print(std::forward<Params>(args)...);
}

/*
* 1. Print(1, 2.f, 3, 4, "Den");
* 2. Print(2.f, 3, 4, "Den");
* 3. Print(3, 4, "Den");
* 4. Print(4, "Den");
* 5. Print("Den");
* 6. Print();
*/


template<typename T>
T* CreateObject()
{
	return new T;
}




void VariadicTemplates::Main()
{
	//Print(1, 2.f, 3, 4, "Den");

	Integer val{ 1 };
	Print(0, val, Integer{ 2 });
}
