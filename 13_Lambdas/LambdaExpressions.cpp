#include "LambdaExpressions.h"
#include <iostream>


template<typename T>
struct Unnamed
{
	T operator()(T x, T y) const
	{
		return x + y;
	}
};


void LambdaExpressionsMain()
{
	auto fn = []()
	{
		std::cout << "Welcome to lambda epressions!" << std::endl;
	};

	fn();

	std::cout << typeid(fn).name() << std::endl;

	// Generic lambda (was introduced in c++ 14)
	auto SumLambda = [](auto x, auto y) noexcept(false)
	{
		return x + y;
	};

	std::cout << SumLambda(3, 9) << std::endl;
	std::cout << SumLambda(5.6, 9) << std::endl;

	Unnamed<int> UnnamedStruct;
	std::cout << UnnamedStruct(3, 9) << std::endl;
}
