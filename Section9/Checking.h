#pragma once
#include "Account.h"

class Checking : public Account
{
	float MinimumBalance = 50.f;


public:
	using Account::Account;
	Checking(const std::string& InName, float InBalance, float InMinimumBalance);
	~Checking();
	virtual void Withdraw(float Amount) override;
	float GetMinimumBalance() const;
};
