#include "Checking.h"
#include <iostream>

Checking::Checking(const std::string& InName, float InBalance, float InMinimumBalance)
	: MinimumBalance(InMinimumBalance), Account(InName, InBalance)
{
}

Checking::~Checking()
{
}

void Checking::Withdraw(float Amount)
{
	auto NewBalance = Balance - Amount;
	if (NewBalance >= MinimumBalance)
	{
		Balance = NewBalance;
	}
	else
	{
		std::cout << "Insufficient balance. You should keep " << MinimumBalance << " on account" << std::endl;
	}
}

float Checking::GetMinimumBalance() const
{
	return MinimumBalance;
}
