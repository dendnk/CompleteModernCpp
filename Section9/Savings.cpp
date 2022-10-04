#include "Savings.h"
#include <iostream>

Savings::Savings(const std::string& InName, float InBalance, float InRate)
    : Account(InName, InBalance), Rate(InRate)
{
    std::cout << "Savings()\n";
}

Savings::~Savings()
{
    std::cout << "~Savings()\n";
}

float Savings::GetInterestRate() const
{
    return Rate;
}

void Savings::AccumulateInterest()
{
    Balance += Balance * Rate;
}
