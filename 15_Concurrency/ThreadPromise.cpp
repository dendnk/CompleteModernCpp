#include "ThreadPromise.h"
#include <iostream>
#include <thread>
#include <future>


using namespace std::chrono_literals;

int Operation(std::promise<int>& Data)
{
	auto Future = Data.get_future();
	std::cout << "[Task] Waiting for count...\n";

	try
	{
		auto Count = Future.get();
		std::cout << "[Task] Count acquired!\n";

		int Sum{};

		for (int i = 0; i < Count; ++i)
		{
			Sum += i;
			std::cout << ".";
			std::this_thread::sleep_for(300ms);
		}

		throw std::runtime_error("Error in task!");

		return Sum;
	}
	catch (const std::exception& ex)
	{
		std::cout << "[Task] Exception : " << ex.what() << std::endl;
	}
}

void ThreadPromiseMain()
{
	std::promise<int> Data;
	std::future<int> Result = std::async(std::launch::async, Operation, std::ref(Data));
	std::this_thread::sleep_for(1s);
	std::cout << "[main] thread continues execution" << std::endl;

	try
	{
		//throw std::runtime_error("Data not available!");

		Data.set_value(10);

		if (Result.valid())
		{
			auto Sum = Result.get();
			std::cout << "Result get : " << Sum << std::endl;
		}
	}
	catch (const std::exception& ex)
	{
		Data.set_exception(std::make_exception_ptr(ex));
	}
}
