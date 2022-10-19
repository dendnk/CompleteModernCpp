#pragma once
#include <string>
#include <iostream>
#include <iomanip>


enum class EGroup
{
	None = 0,
	Family,
	Friends,
	Coworker,
	Acquaintance
};

enum class EDisplayMode
{
	Full = 1,
	FirstNamePhone,
	FullName,
	FullNameCompanyGroup
};

static const char* EGroupToString(EGroup InGroup)
{
	switch (InGroup)
	{
	case EGroup::None: return "None";
		break;
	case EGroup::Friends: return "Friends";
		break;
	case EGroup::Family: return "Family";
		break;
	case EGroup::Coworker: return "Coworker";
		break;
	case EGroup::Acquaintance: return "Acquaintance";
		break;
	default: return "Undefined";
		break;
	}
}

struct FContactConfig
{
	std::string FirstName{};
	std::string LastName{};
	std::string PrimaryPhoneNumber{};
	std::string SecondaryPhoneNumber{};
	std::string EmailId{};
	std::string Address{};
	std::string Company{};
	EGroup Group{ EGroup::None };


	bool IsEmpty() const
	{
		return FirstName.empty() && LastName.empty();
	}

	void DisplayInfo(EDisplayMode DisplayMode = EDisplayMode::FullName) const
	{
		if (IsEmpty())
		{
			std::cout << "You try to display empty contact!" << std::endl;
			return;
		}

		if (DisplayMode == EDisplayMode::FirstNamePhone)
		{
			std::cout << "First Name : " << std::setw(10) << FirstName;
			std::cout << " | Phone : " << PrimaryPhoneNumber << std::endl;
			return;
		}
		else if (DisplayMode == EDisplayMode::FullName)
		{
			std::cout << "Full Name : " << FirstName << " " << LastName << std::endl;

			return;
		}
		else if (DisplayMode == EDisplayMode::FullNameCompanyGroup)
		{
			std::cout << "Full Name : " << std::setw(8) << FirstName << " " << std::setw(8) << LastName;
			std::cout << " | Company : " << std::setw(8) << Company;
			std::cout << " | Group : " << std::setw(8)<< EGroupToString(Group) << std::endl;

			return;
		}


		std::cout << "First Name : " << std::setw(8) << FirstName << std::endl;
		std::cout << "*" << "Last Name : " << std::setw(8) << LastName << std::endl;
		std::cout << "*" << "Primary Phone Number : " << std::setw(8) << PrimaryPhoneNumber << std::endl;
		std::cout << "*" << "Secondary Phone Number : " << SecondaryPhoneNumber << std::endl;
		std::cout << "*" << "Email Id : " << std::setw(8) << EmailId << std::endl;
		std::cout << "*" << "Address : " << std::setw(8) << Address << std::endl;
		std::cout << "*" << "Company : " << std::setw(8) << Company << std::endl;
		std::cout << "*" << "Group : " << std::setw(8) << EGroupToString(Group) << std::endl;
	}
};
