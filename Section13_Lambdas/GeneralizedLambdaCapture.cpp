#include "GeneralizedLambdaCapture.h"
#include <iostream>
#include <fstream>


void GeneralizedLambdaCaptureMain()
{
	int x{ 5 };
	auto f = [y = x](int arg)
	{
		return y + arg;
	};

	std::cout << f(9) << std::endl;

	std::ofstream out{ "file.txt" };

	auto write = [out = std::move(out)](int x) mutable
	{
		out << x;
	};

	write(200);
}
