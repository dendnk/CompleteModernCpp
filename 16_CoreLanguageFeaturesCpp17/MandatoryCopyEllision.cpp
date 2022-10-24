#include "MandatoryCopyEllision.h"
#include <iostream>


#define DELETE_COPY_MOVE
class Number
{
public:
	Number(int InitNum)
	{
		std::cout << "Parametrized contrsuctor\n";
	}

#ifdef DELETE_COPY_MOVE
	Number(const Number&) = delete;
	Number(Number&&) = delete;
#else

	Number(const Number&)
	{
		std::cout << "Copy contrsuctor\n";
	}

	Number(Number &&)
	{
		std::cout << "Move contrsuctor\n";
	}
#endif
};


void Foo(Number Num)
{

}

Number Create()
{
	//Number Num{ 0 };
	//return Num; // compiler applies copy ellision that is called as named return value optimization

	return Number{ 0 }; // this is return value optimization
}


template<typename T, typename ...Args>
T CreateObject(Args&&... Arguments)
{
	return T(Arguments...);
}


void MandatoryCopyEllisionMain()
{
	//Number N1 = 3; // compiler will apply copy ellision
	/*
	*	It will be evaluated like this
	*	Number N1 = Number{3};
	*	but because of copy ellision this temporary will be elided or omitted
	*
	*	For copy ellision to work, the class shouldhave the copy constructor or the move constructor
	*
	*/

	//Foo(3);
	/*
	*	It will be like : Foo(Number{3});
	*
	*/

	//auto N2 = Create();

	auto n3 = CreateObject<Number>(0);
}
