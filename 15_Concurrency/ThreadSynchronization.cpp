#include "ThreadSynchronization.h"
#include <iostream>
#include <list>
#include <thread>
#include <mutex>


std::list<int> Data;
const int SIZE = 10000;
std::mutex Mutex;


void Download()
{
	for (int i = 0; i < SIZE;++i)
	{
		std::lock_guard<std::mutex> mtx(Mutex);
		//Mutex.lock();
		Data.push_back(i);
		if (i == 500) return;
		//Mutex.unlock();
	}
}

void Download2()
{
	for (int i = 0; i < SIZE;++i)
	{
		std::lock_guard<std::mutex> mtx(Mutex);
		//Mutex.lock();
		Data.push_back(i);
		//Mutex.unlock();
	}
}


void ThreadSynchronizationMain()
{
	std::thread ThreadDownloder(Download);
	std::thread ThreadDownloder2(Download2);

	ThreadDownloder.join();
	ThreadDownloder2.join();

	std::cout << Data.size() << std::endl;
}
