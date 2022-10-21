#include "TaskBasedConcurrency.h"
#include <iostream>
#include <thread>
#include <future>

using namespace std::chrono_literals;

int Operation(int count)
{
	int Sum{};
	for (int i = 0; i < count; ++i)
	{
		Sum += i;
		std::cout << '.';
		std::this_thread::sleep_for(300ms); // s - std::chrono::seconds(1)
	}

	std::cout << std::endl;
	return Sum;
}

void TaskBasedConcurrencyMain()
{
	std::future<int> Result = std::async(std::launch::async, Operation, 10); // std::launch::async | std::launch::deferred - task will execute sync
 	std::this_thread::sleep_for(1s);
	std::cout << "main() threading continues execution" << std::endl;

	if (Result.valid())
	{
		auto TimePoint = std::chrono::system_clock::now();
		TimePoint += 1s;

		//auto Status = Result.wait_for(4s);
		auto Status = Result.wait_until(TimePoint);

		switch (Status)
		{
		case std::future_status::ready:
			std::cout << "Status Ready : task is ready!\n";
			break;
		case std::future_status::timeout:
			std::cout << "Status TimeOut : task in progress!\n";
			break;
		case std::future_status::deferred:
			std::cout << "Status Deferred : task is synchronous!\n";
			break;
		default:
			break;
		}

		Result.wait();
		// Operation(10);
		auto Sum = Result.get(); // make the main thread wait
		std::cout << Sum << std::endl;
	}
}
