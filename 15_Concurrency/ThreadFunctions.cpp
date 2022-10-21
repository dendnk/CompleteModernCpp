#include "ThreadFunctions.h"
#include <iostream>
#include <thread>
#include <Windows.h>


void Process()
{
	std::cout << "Thread Id : " << std::this_thread::get_id() << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i << ' ';
	}
}

void ThreadFunctionsMain()
{
	std::thread T1(Process);
	auto Handle = T1.native_handle();
	SetThreadDescription(Handle, L"MyThread");
	auto Id = T1.get_id();
	std::cout << "T1.get_id() : " << Id << std::endl;

	auto CoresNum = std::thread::hardware_concurrency();
	std::cout << "Cores : " << CoresNum << std::endl;

	T1.join();
}

/*
*  Native handle - returns type on the corresponding platform
*  Widnows - handle
*  Linux - pthread_t
*  Need if you want to invoke some native API of platform
*/
