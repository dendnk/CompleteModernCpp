#include "CTAD.h"
#include <iostream>
#include <vector>
#include <mutex>


template<typename T>
class Data
{
public:
	Data(const T& InitT)
	{}
};

// Custom deduction guide
Data(const char*)->Data<std::string>;
Data(int)->Data<long>;


void CTAD_Main()
{
	// without CTAD
	Data<int> D1{ 5 };

	// with CTAD
	Data D2{ 8.2f };
	Data D3 = D1;
	auto D4 = new Data{ "Hello" };

	Data D5{ "Hello" };
	Data D6{ 5 };


	// without CTAD
	std::pair<int, int> P1{ 2,5 };
	auto P2 = std::make_pair(2, 5);

	// with CTAD
	std::pair P3{ 2,5 };
	std::vector V1{ 1,2,3,4,5 };

	std::mutex M;
	std::lock_guard Lock{ M };
}
