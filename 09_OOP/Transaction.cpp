#include "Transaction.h"
#include "Checking.h"
#include <iostream>

using namespace std;

void Transact(Account* InAccount)
{
	cout << "Transcation started : " << endl;
	cout << "Initial balance : " << InAccount->GetBalance() << endl;
	InAccount->Deposit(100);
	InAccount->AccumulateInterest();

	//if (typeid(*InAccount) == typeid(Checking))
	//{
	//	Checking* CheckingPointer = static_cast<Checking*>(InAccount);
	//	cout << "Minimum Balance :  " << CheckingPointer->GetMinimumBalance() << endl;
	//}

	if (Checking* CheckingPointer = dynamic_cast<Checking*>(InAccount))
	{
		cout << "Minimum Balance :  " << CheckingPointer->GetMinimumBalance() << endl;
	}

	InAccount->Withdraw(170);
	cout << "Interest rate :  " << InAccount->GetInterestRate() << endl;
	cout << "Final balance : " << InAccount->GetBalance() << endl;
}

void Transact(Account& InAccount)
{
	cout << "Transcation started : " << endl;
	cout << "Initial balance : " << InAccount.GetBalance() << endl;
	InAccount.Deposit(100);
	InAccount.AccumulateInterest();

	//if (typeid(*InAccount) == typeid(Checking))
	//{
	//	Checking* CheckingPointer = static_cast<Checking*>(InAccount);
	//	cout << "Minimum Balance :  " << CheckingPointer->GetMinimumBalance() << endl;
	//}

	Checking& CheckingObj = dynamic_cast<Checking&>(InAccount);
	cout << "Minimum Balance : " << CheckingObj.GetMinimumBalance() << endl;

	InAccount.Withdraw(170);
	cout << "Interest rate :  " << InAccount.GetInterestRate() << endl;
	cout << "Final balance : " << InAccount.GetBalance() << endl;
}
