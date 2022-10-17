#pragma once
#include <iostream>


template<typename T, int columns>
class PrettyPrinter
{
	T* pData;

public:
	PrettyPrinter(T* Data)
		: pData(Data)
	{}

	void Print()
	{
		std::cout << "Columns : " << columns << std::endl;
		std::cout << "{" << *pData << "}" << std::endl;
	}

	T* GetData()
	{
		return pData;
	}
};

template<typename T>
class PrettyPrinter<T, 80>
{
	T* pData;

public:
	PrettyPrinter(T* Data)
		: pData(Data)
	{}

	void Print()
	{
		std::cout << "Using 80 Columns" << std::endl;
		std::cout << "{" << *pData << "}" << std::endl;
	}

	T* GetData()
	{
		return pData;
	}
};

template<typename T>
class SmartPointer
{
	T* pData;
public:
	SmartPointer(T* ptr)
		: pData(ptr)
	{}

	T* operator->()
	{
		return pData;
	}

	T& operator*()
	{
		return *pData;
	}

	~SmartPointer()
	{
		delete pData;
	}
};

template<typename T>
class SmartPointer<T[]>
{
	T* pData;
public:
	SmartPointer(T* ptr)
		: pData(ptr)
	{}

	T& operator[](int index)
	{
		return pData[index];
	}

	~SmartPointer()
	{
		delete[] pData;
	}
};


void ClassTemplatePartialSpecMain();
