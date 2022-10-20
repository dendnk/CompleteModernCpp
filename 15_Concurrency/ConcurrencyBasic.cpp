#include "ConcurrencyBasic.h"
#include <iostream>
#include <list>
#include <thread>

std::list<int> DataBasic;
const int SIZE_Basic = 5000000;

class String
{
public:
	String()
	{
		std::cout << "String()" << std::endl;
	}

	String(const String&)
	{
		std::cout << "String(const String&)" << std::endl;
	}

	String& operator = (const String&)
	{
		std::cout << "operator = (const String&)" << std::endl;

		return *this;
	}

	~String()
	{
		std::cout << "~String()" << std::endl;
	}
};

void DownloadBasic(const String& file)
{
	//std::cout << "[Downloader] Started download of file : " << file <<  std::endl;
	for (int i = 0; i < SIZE_Basic;++i)
	{
		DataBasic.push_back(i);
	}
	std::cout << "[Downloader] Finished download" << std::endl;
}

void ConcurrencyBasicMain()
{
	String file;
	std::cout << "[Main] User started an operation" << std::endl;
	std::thread ThreadDownloader(DownloadBasic, std::cref(file));
	//ThreadDownloader.detach();

	std::cout << "[Main] User started another operation" << std::endl;

	if (ThreadDownloader.joinable())
	{
		ThreadDownloader.join();
	}

	//system("pause");
}
