#pragma once
#include "ContactConfig.h"
#include <vector>


enum class ESortOrder
{
	AZ = 1,
	ZA
};

enum class EFilterType
{
	FirstName = 1,
	LastName,
	Company,
	Group
};

struct SortByType
{
	EFilterType SortType;
	ESortOrder SortOrder;

public:
	SortByType(EFilterType InitSortType, ESortOrder InitSortOrder)
		: SortType(InitSortType)
		, SortOrder(InitSortOrder)
	{}

	bool operator()(const FContactConfig& Contact1, const FContactConfig& Contact2) const
	{
		if (SortType == EFilterType::FirstName)
		{
			if (SortOrder == ESortOrder::AZ)
			{
				return Contact1.FirstName < Contact2.FirstName;
			}

			return Contact1.FirstName > Contact2.FirstName;
		}
		else if (SortType == EFilterType::LastName)
		{
			if (SortOrder == ESortOrder::AZ)
			{
				return Contact1.LastName < Contact2.LastName;
			}

			return Contact1.LastName > Contact2.LastName;
		}
		else if (SortType == EFilterType::Company)
		{
			if (SortOrder == ESortOrder::AZ)
			{
				return Contact1.Company < Contact2.Company;
			}

			return Contact1.Company > Contact2.Company;
		}
		else if (SortType == EFilterType::Group)
		{
			if (SortOrder == ESortOrder::AZ)
			{
				return EGroupToString(Contact1.Group) < EGroupToString(Contact2.Group);
			}

			return EGroupToString(Contact1.Group) > EGroupToString(Contact2.Group);
		}

		return false;
	}
};


class Phonebook
{
	std::vector<FContactConfig> Records{};

public:
	bool AddContact(const FContactConfig& ContactConfig);
	bool RemoveContact(const std::string& ContactName);
	size_t GetRecordsCount();

	void DisplayAllContacts(EDisplayMode DisplayMode = EDisplayMode::FullName);
	void SortContacts(EFilterType SortType, ESortOrder SortOrder);

	Phonebook GetContactsByTypeName(EFilterType Type, const std::string& Name);
	FContactConfig GetContactByName(const std::string& Name, bool bFirstName = true);
};
