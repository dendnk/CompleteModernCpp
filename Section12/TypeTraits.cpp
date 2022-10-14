#include "TypeTraits.h"
#include <iostream>
#include <type_traits>

template <typename T>
T Divide(T a, T b)
{
	static_assert(std::is_floating_point<T>::value, "Only floating point type supported!");
	if (std::is_floating_point<T>::value == false)
	{
		std::cout << "Use floating types only!" << std::endl;
		return 0;
	}
	return a / b;
}

template<typename T>
void Check(T&&)
{
	std::cout << std::boolalpha;
	std::cout << "Is reference ? " << std::is_reference<T>::value << std::endl;

	std::cout << "After removing: " <<
		std::is_reference<std::remove_reference<T>::type>::value << std::endl;
}

void TypeTraitsMain()
{
	/*static_assert(sizeof(void*) == 4, "Compile in 32-bit mode only!");

	if (sizeof(void*) != 4)
	{
		std::cout << "Not 32-bit" << std::endl;
		return;
	}*/

	//Check(5);
	//int value{};
	//Check(value);

	//std::cout
	//<< std::boolalpha
	// << "Is integer?" << std::is_integral<int>::value << std::endl;

	//std::cout << Divide(5, 2) << std::endl;
	std::cout << Divide(5.1, 2.3) << std::endl;
}
