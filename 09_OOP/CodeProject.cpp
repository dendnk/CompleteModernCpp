#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>

int main()
{
    Savings CheckingAccount("Bob", 100.f, 50);

	try
	{
		Transact(CheckingAccount);
	}
	catch (const std::exception& ex)
	{
		std::cout << "Exception : " << ex.what() << std::endl;
	}

    return 0;
}
