#include "TypeTraitsSuffixes.h"

#include <iostream>
#include <type_traits>


template<typename T>
T Divide(T a, T b)
{
	if (std::is_floating_point_v<T> == false)
	{
		std::cout << "Use floating point types only";
		return 0;
	}
	return a / b;
}

template<typename T>
void Check(T&&)
{
	std::cout << std::boolalpha;
	std::cout << "Is reference? " << std::is_reference_v<T> << std::endl;
	std::cout << "After removing : " << std::is_reference_v<typename std::remove_reference_t<T>> << std::endl;
}

class Number
{
	int Value;
public:
	Number() = default;
	Number(int InitValue)
		: Value(InitValue)
	{}
};


void TypeTraitsSuffixesMain()
{
	// _v replace ::value
	static_assert(std::is_default_constructible<Number>::value, "Only objects with default constructor can be deseialized");
	static_assert(std::is_default_constructible_v<Number>, "Only objects with default constructor can be deseialized"); // _v replace ::value

	Check(5);

	int value{};
	Check(value);
}
