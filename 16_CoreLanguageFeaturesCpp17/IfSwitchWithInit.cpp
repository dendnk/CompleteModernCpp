#include "IfSwitchWithInit.h"
#include <iostream>
#include <fstream>
#include <filesystem>


void Alloc()
{
	int* p = (int*)malloc(sizeof(int));

	if (p != nullptr)
	{
		*p = 50;

		// do smth

		free(p);
	}

	if (int* p = (int*)malloc(sizeof(int)); p != nullptr)
	{
		*p = 50;

		// do smth

		free(p);
	}
	else
	{
		// here p will be accessable and be null
	}
}

void Write(const std::string& Data)
{
	if (std::ofstream Out{ "file.txt" }; Out && !Data.empty())
	{
		std::cout << "Writing data into the file\n";
		Out << Data;
	}
	else
	{
		Out << "Not data to write\n";
		Out << "#####";
	}
}

class EFileInfo
{
public:
	enum Type
	{
		Executable,
		Text
	};

	Type GetFileType() const
	{
		return {};
	}

	size_t GetFileSize() const
	{
		return 0;
	}
};

EFileInfo GetInfo(const std::string& File)
{
	return {};
}

void Operate(const std::string& File)
{
	switch (auto Info = GetInfo(File); Info.GetFileType())
	{
	case EFileInfo::Executable:
		break;
	case EFileInfo::Text:
		break;

	default:
		break;
	}

	// Info not visible here
}


void IfSwitchWithInitMain()
{
	Write("123");
}
