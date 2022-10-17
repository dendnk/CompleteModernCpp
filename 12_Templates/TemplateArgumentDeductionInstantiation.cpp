#include "TemplateArgumentDeductionInstantiation.h"

// Explicit Specialization
template<> const char* Max<const char*>(const char* x, const char* y)
{
	std::cout << "Max<const char*> ()" << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}

void TemplateArgumentDeductionMain()
{
	//Instantation examples
	//Max(static_cast<float>(3), 5.f);
	//Max<double>(3, 5.6);
	//int (*pfn)(int, int) = Max;

	//const char* B{ "B" };
	//const char* A{ "A" };
	//auto s = Max(A, B);
	//std::cout << s << std::endl;

	//Print<3>();

	int Arr[] = { 3,1,9,7 };
	//int(&ref)[4] = Arr;
	//auto it = std::begin(Arr);
	auto sum = ArraySum(Arr);
	std::cout << sum << std ::endl;
}
