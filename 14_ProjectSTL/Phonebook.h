#pragma once
#include "ContactConfig.h"
#include <map>


class Phonebook
{
	std::map<std::string, FContactConfig> Records{};

public:
	bool AddContact(const std::string& ContactName, FContactConfig& ContactConfig);
	bool RemoveContact(const std::string& ContactName);
};
