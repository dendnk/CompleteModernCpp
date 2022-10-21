#include "Attributes.h"


/*
*	Attributes - used to be compiler specific commands that give additional info to the compiler
*	They might be utilised for optimization or checks
*	Before C++11, different vendors used keywords for attributes eg.
*	MSVC uses	__declspec
*	GCC uses	__attribute
*	C++11 inroduced some standardized attributes that work with all compilers
*	C++14 and C++17 introduced more attributes that you can use in your code
*	We cannot create custom attributes
*/

// Deprecated attribute
[[deprecated("Use the new version instead")]]
int* CreateIntArray(size_t size)
{
	return new int[size];
}

template<typename T>
[[nodiscard]]
T* CreateArray(size_t size)
{
	return new T[size];
}

class [[deprecated("This class is replaced by NewTest class")]] Test
{

};

namespace [[deprecated("Do not this namespace")]] A
{

}

class [[nodiscard]] Number
{

};

Number GetNumber(int x)
{
	return Number{};
}

void AttributesMain()
{
	//CreateIntArray(5);
	//Test t1;
	//using namespace A;

	//CreateArray<int>(3);
	/*
		Create integers on the heap
		We are not storing the return value of the function
		and so memory that is allocated there will leaked.

		To make importatnt for compiler to store the return value from function
		we can use attribute [[nodiscard]]
	*/

	auto p = CreateArray<int>(3);

	//GetNumber(3);
}
