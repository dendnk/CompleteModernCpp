#pragma once

#include <iostream>


template<typename T>
class PrettyPrinter
{
	T* pData;

public:
	PrettyPrinter(T* Data)
		: pData(Data)
	{}

	void Print()
	{
		std::cout << "{" << *pData << "}" << std::endl;

	}

	T* GetData()
	{
		return pData;
	}
};

void ClassTemplatesExplicitSpecMain();
