#pragma once

#include <iostream>

template<typename T>
T Max(T X, T Y)
{
	std::cout << typeid(T).name() << std::endl;
	return X > Y ? X : Y;
}

// Explicit instantiation
template char Max(char x, char y);

template<int size> // size - non type argument, should be constant expressions and should be computed at compile time
void Print()
{
	std::cout << size << std::endl;
}

//template<typename T>
//T ArraySum(T* Array, int size)
//{
//	T Sum{};
//
//	for (int i(0); i < size; ++i)
//	{
//		Sum += Array[i];
//	}
//	return Sum;
//}

template<typename T, int size>
T ArraySum(T (&Array)[size])
{
	T Sum{};

	for (int i(0); i < size; ++i)
	{
		Sum += Array[i];
	}
	return Sum;
}

void TemplateArgumentDeductionMain();
