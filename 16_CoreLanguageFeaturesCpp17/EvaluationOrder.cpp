#include "EvaluationOrder.h"
#include <iostream>


class EvaluationOrder
{
public:
	EvaluationOrder& First(int)
	{
		std::cout << __FUNCSIG__ << std::endl; // print function name
		return *this;
	}

	EvaluationOrder& Second(int)
	{
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
};

int FirstSubExpression(int)
{
	std::cout << __FUNCSIG__ << std::endl;
	return 0;
}

int SecondSubExpression(int)
{
	std::cout << __FUNCSIG__ << std::endl;
	return 0;
}


void EvaluationOrderMain()
{
	EvaluationOrder EO;

	EO.First(FirstSubExpression(0)).Second(SecondSubExpression(0));
}
