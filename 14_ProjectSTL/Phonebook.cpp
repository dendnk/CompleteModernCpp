#include "Phonebook.h"
#include <iostream>
#include <algorithm>


bool Phonebook::AddContact(const FContactConfig& ContactConfig)
{
	auto Result = false;

	if (ContactConfig.FirstName.empty())
	{
		if (ContactConfig.LastName.empty())
		{
			std::cout << "First Name or Last Name must be specified!" << std::endl;
			return Result;
		}
	}

	Records.push_back(ContactConfig);
	Result = true;

	return Result;
}

bool Phonebook::RemoveContact(const std::string& ContactName)
{
	bool Result = false;

	if (ContactName.empty())
		return Result;

	auto Iterator = std::find_if(Records.begin(), Records.end(),
		[&ContactName](const FContactConfig& Contact)
		{
			if (!Contact.FirstName.empty())
			{
				return Contact.FirstName == ContactName;
			}
			else
			{
				return Contact.LastName == ContactName;
			}
		});

	if (Iterator != Records.end())
	{
		Records.erase(Iterator);
		Result = true;
	}

	return Result;
}

size_t Phonebook::GetRecordsCount()
{
	return Records.size();
}

void Phonebook::DisplayAllContacts(EDisplayMode DisplayMode)
{
	std::for_each(Records.begin(), Records.end(),
		[&DisplayMode](const FContactConfig& Contact)
		{
			Contact.DisplayInfo(DisplayMode);
		});

	std::cout << "Count : " << GetRecordsCount() << std::endl;
}

void Phonebook::SortContacts(EFilterType SortType, ESortOrder SortOrder)
{
	std::sort(Records.begin(), Records.end(), SortByType(SortType, SortOrder));
}

FContactConfig Phonebook::GetContactByName(const std::string& Name, bool bFirstName)
{
	FContactConfig Result{};

	if (Name.empty())
		return Result;

	auto itr = std::find_if(Records.begin(), Records.end(),
		[&Name, &bFirstName](const FContactConfig& Contact)
		{
			if (bFirstName)
			{
				return Contact.FirstName == Name;
			}

			return Contact.LastName == Name;
		});

	if (itr != Records.end())
	{
		Result = *itr;
	}

	std::cout << "Contact with " << (bFirstName ? "First Name" : "Last Name") << " " << Name;
	std::cout << " was " << (Result.IsEmpty() ? "not " : "") << "found!" << std::endl;

	return Result;
}

Phonebook Phonebook::GetContactsByTypeName(EFilterType Type, const std::string& TypeName)
{
	Phonebook Result{};

	if (Records.empty())
		return Result;

	std::for_each(Records.begin(), Records.end(),
		[&Result, &Type, &TypeName](const FContactConfig& Contact)
		{
			if (Type == EFilterType::FirstName && Contact.FirstName == TypeName ||
				Type == EFilterType::LastName && Contact.LastName == TypeName ||
				Type == EFilterType::Company && Contact.Company == TypeName ||
				Type == EFilterType::Group && EGroupToString(Contact.Group) == TypeName)
			{
				Result.AddContact(Contact);
			}
		});

	return Result;
}
