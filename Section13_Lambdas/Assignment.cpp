#include "Assignment.h"
#include <iostream>
#include <vector>


template<typename T>
struct MaxFO
{
	T operator()(T x, T y) const
	{
		return x > y ? x : y;
	}
};

template<typename T>
struct GreaterFO
{
	bool operator()(T x, T y) const
	{
		return x > y;
	}
};

template<typename T>
struct LessFO
{
	bool operator()(T x, T y) const
	{
		return x < y;
	}
};

template<typename T>
struct MinMaxFO
{
	auto operator()(T ItrBegin, T ItrEnd) const
	{
		auto Min{ *ItrBegin };
		auto Max{ *ItrBegin };

		if (ItrBegin != ItrEnd)
		{
			for (; ItrBegin != ItrEnd; ++ItrBegin)
			{
				auto CurrentValue = *ItrBegin;
				if (CurrentValue < Min)
				{
					Min = CurrentValue;
				}

				if (CurrentValue > Max)
				{
					Max = CurrentValue;
				}
			}
		}

		return std::make_pair(Min, Max);
	}
};


void AssignmentMain()
{
	auto MaxLambda = [](auto x, auto y)
	{
		return (x > y) ? x : y;
	};

	std::cout << "Max Lambda" << std::endl;
	std::cout << MaxLambda(5, 7) << std::endl;
	std::cout << MaxLambda(33.1f, 33.7f) << std::endl;
	std::cout << MaxLambda("abc", "ABC") << std::endl;

	MaxFO<int> MaxInt;
	MaxFO<float> MaxFloat;
	MaxFO<std::string> MaxString;

	std::cout << "Max Functional Object" << std::endl;
	std::cout << MaxInt(5, 7) << std::endl;
	std::cout << MaxFloat(33.1f, 33.7f) << std::endl;
	std::cout << MaxString("abc", "ABC") << std::endl;


	auto GreaterLambda = [](auto x, auto y)->bool
	{
		return x > y;
	};

	std::cout << "Greater Lambda" << std::endl;
	std::cout << (GreaterLambda(5, 7) ? "true" : "false") << std::endl;
	std::cout << (GreaterLambda(33.1f, 33.7f) ? "true" : "false") << std::endl;
	std::cout << (GreaterLambda("abc", "ABC") ? "true" : "false") << std::endl;

	GreaterFO<int> GreaterInt;
	GreaterFO<float> GreaterFloat;
	GreaterFO<std::string> GreaterString;

	std::cout << "Greater Functional Object" << std::endl;
	std::cout << (GreaterInt(5, 7) ? "true" : "false") << std::endl;
	std::cout << (GreaterFloat(33.1f, 33.7f) ? "true" : "false") << std::endl;
	std::cout << (GreaterString("abc", "ABC") ? "true" : "false") << std::endl;


	auto LessLambda = [](auto x, auto y)->bool
	{
		return x < y;
	};

	std::cout << "Less Lambda" << std::endl;
	std::cout << (LessLambda(5, 7) ? "true" : "false") << std::endl;
	std::cout << (LessLambda(33.1f, 33.7f) ? "true" : "false") << std::endl;
	std::cout << (LessLambda("abc", "ABC") ? "true" : "false") << std::endl;

	LessFO<int> LessInt;
	LessFO<float> LessFloat;
	LessFO<std::string> LessString;

	std::cout << "Less Functional Object" << std::endl;
	std::cout << (LessInt(5, 7) ? "true" : "false") << std::endl;
	std::cout << (LessFloat(33.1f, 33.7f) ? "true" : "false") << std::endl;
	std::cout << (LessString("abc", "ABC") ? "true" : "false") << std::endl;


	auto MinMaxLambda = [](auto ItrBegin, auto ItrEnd)
	{
		auto Min{ *ItrBegin };
		auto Max{ *ItrBegin };

		if (ItrBegin != ItrEnd)
		{
			for (; ItrBegin != ItrEnd; ++ItrBegin)
			{
				auto CurrentValue = *ItrBegin;
				if (CurrentValue < Min)
				{
					Min = CurrentValue;
				}

				if (CurrentValue > Max)
				{
					Max = CurrentValue;
				}
			}
		}

		return std::make_pair(Min, Max);
	};

	std::vector<int> v1 = { -1, -2, -3, -4, 5, -6 };
	std::vector<int>::iterator it1 = v1.begin();
	std::vector<int>::iterator it2 = v1.end();
	auto ResultMinMax = MinMaxLambda(it1, it2);

	std::cout << "Min Max Lambda" << std::endl;
	std::cout << "Min : " << ResultMinMax.first << " Max : " << ResultMinMax.second << std::endl;

	MinMaxFO<std::vector<int>::iterator> MinMaxInt;
	auto ResultMinMaxFO = MinMaxInt(it1, it2);

	std::cout << "Min Max Functional Object" << std::endl;
	std::cout << "Min : " << ResultMinMax.first << " Max : " << ResultMinMax.second << std::endl;
}
