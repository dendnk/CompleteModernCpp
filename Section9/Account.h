#pragma once
#include <string>

class Account
{
	std::string Name;
	int Number;
	static int AccountNumberGenerator;


protected:
	float Balance;


public:
	Account(const std::string& Name, float Balance);
	virtual ~Account();


public:
	const std::string GetName() const;
	const float GetBalance() const;
	const int GetAccountNumber() const;

	virtual void AccumulateInterest();
	virtual void Withdraw(float Amount);
	void Deposit(float Amount);
	virtual float GetInterestRate() const;
};
