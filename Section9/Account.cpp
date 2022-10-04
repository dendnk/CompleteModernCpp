#include "Account.h"
#include <iostream>

int Account::AccountNumberGenerator = 1000;

Account::Account(const std::string& InName, float InBalance)
	: Name(InName), Balance(InBalance)
{
	Number = ++AccountNumberGenerator;
	std::cout << "Account()\n";
}

Account::~Account()
{
	std::cout << "~Account()\n";
}

const std::string Account::GetName() const
{
	return Name;
}

const float Account::GetBalance() const
{
	return Balance;
}

const int Account::GetAccountNumber() const
{
	return Number;
}

void Account::AccumulateInterest()
{
}

void Account::Withdraw(float Amount)
{
	if (Amount <= Balance)
	{
		Balance -= Amount;
	}
	else
	{
		std::cout << "Insufficient balance\n";
	}
}

void Account::Deposit(float Amount)
{
	Balance += Amount;
}

float Account::GetInterestRate() const
{
	return 0.0f;
}
