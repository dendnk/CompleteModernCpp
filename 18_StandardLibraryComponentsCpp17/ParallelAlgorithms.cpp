#include "ParallelAlgorithms.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <execution>


/*
*	Let's compare performance of serial and parallelized algorithms
*/


class Timer
{
	std::chrono::steady_clock::time_point Start;
public:
	Timer() : Start(std::chrono::steady_clock::now())
	{}

	void ShowResult(std::string_view Message = "")
	{
		auto End = std::chrono::steady_clock::now();
		auto TimeDifference = End - Start;

		std::cout << Message << " : "
			<< std::chrono::duration_cast<std::chrono::microseconds>(TimeDifference).count()
			<< std::endl;
	}
};

constexpr unsigned VectorSize{ 100 };
std::vector<long> CreateVector()
{
	std::vector<long> Vector;
	Vector.reserve(VectorSize);

	std::default_random_engine RandomEngine{ std::random_device{}() };
	std::uniform_int_distribution<long> Distribution{ 0,VectorSize };

	for (unsigned int i(0); i < VectorSize; ++i)
	{
		Vector.push_back(Distribution(RandomEngine));
	}

	return Vector;
}

void ParallelAlgorithmsMain()
{
	auto DataSet = CreateVector();
	Timer T1;

	std::sort(DataSet.begin(), DataSet.end()); // 2 mks for 100 elements
	//std::sort(std::execution::par, DataSet.begin(), DataSet.end()); // 1112 mks for 100 elements

	//auto Result = std::accumulate(DataSet.begin(), DataSet.end(), 0L);
	//auto Result = std::reduce(DataSet.begin(), DataSet.end(), 0L);

	//T1.ShowResult("Sorting Time");
	T1.ShowResult("Time");

	//std::cout << "Result : " << Result << std::endl;
}
