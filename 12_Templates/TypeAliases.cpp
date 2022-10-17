#include "TypeAliases.h"
#include <iostream>
#include <vector>
#include <list>

class Employee;

const char* GetErrorMessage(int ErrorNumber)
{
	return "Empty";
}

//typedef const char* (*PFN)(int);
using PFN = const char* (*)(int);

void ShowError(PFN pfn)
{

}

//typedef std::vector<std::list<std::string>> Names;


// Alias can be tepltized
template<typename T>
using Names = std::vector<std::list<T>>;

void TypeAliasesMain()
{
	Names<std::string> names;
	Names<Names<std::string>> nnames;

	PFN pfn = GetErrorMessage;
	ShowError(pfn);
}
