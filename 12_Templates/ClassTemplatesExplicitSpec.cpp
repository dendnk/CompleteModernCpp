#include "ClassTemplatesExplicitSpec.h"
#include <vector>


// Specialization Print() function for std::vector<int> type
template<>
void PrettyPrinter<std::vector<int>>::Print()
{
	std::cout << "{ ";
	for (const auto& Temp : *pData)
	{
		std::cout << Temp << " ";
	}

	std::cout << "}" << std::endl;
}

// Specialization Print() function for std::vector<std::vector<int>> type
template<>
void PrettyPrinter<std::vector<std::vector<int>>>::Print()
{
	for (const auto& CurVector : *pData)
	{
		std::cout << "{ ";

		for (const auto& CurElement : CurVector)
			std::cout << CurElement << " ";

		std::cout << "}" << std::endl;
	}
}

// Explicit specialization for strings
template<>
class PrettyPrinter<const char*>
{
	const char* pData;

public:
	PrettyPrinter(const char* Data)
		: pData(Data)
	{}

	void Print()
	{
		std::cout << "{" << pData << "}" << std::endl;

	}

	const char* GetData()
	{
		return pData;
	}
};


void ClassTemplatesExplicitSpecMain()
{
	//int data = 12;
	//float f = 1.2f;

	//PrettyPrinter<int> p1(&data);
	//PrettyPrinter<float> p2(&f);

	//p1.Print();
	//p2.Print();

	//const char* str{ "Hello world!" };

	//PrettyPrinter<const char*> p3(str);
	//p3.Print();
	//const char* pData = p3.GetData();

	//std::vector<int> v{ 1,2,3,4 };

	//PrettyPrinter<std::vector<int>> pv(&v);
	//pv.Print();

	std::vector<std::vector<int>> vv{ {1,2,3,4}
									, {5,6,7,8}
									, {9,10} };

	PrettyPrinter<std::vector<std::vector<int>>> pvv(&vv);
	pvv.Print();
}
