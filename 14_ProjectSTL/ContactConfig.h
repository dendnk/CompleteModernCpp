#pragma once
#include <string>

enum class EGroup
{
	None = 0,
	Friends,
	Family,
	Coworker,
	Acquaintance
};

struct FContactConfig
{
	//std::string FirstName{}; it will be used as key in map
	std::string LastName{};
	std::string PrimaryPhoneNumber{};
	std::string SecondaryPhoneNumber{};
	std::string EmailId{};
	std::string Address{};
	std::string Company{};
	EGroup Group{ EGroup::None };
};
