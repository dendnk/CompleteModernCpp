#pragma once
#include "Account.h"

class Savings : public Account
{
	float Rate;


public:
	Savings(const std::string& InName, float InBalance, float InRate);
	~Savings();

	virtual float GetInterestRate() const override;
	virtual void AccumulateInterest() override;
};
