#include "UpdateLambdas.h"
#include <iostream>
#include <sstream>


template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback Operation)
{
	for (int i = 0; i < size; ++i)
	{
		Operation(arr[i]);
	}
}

class Product
{
	std::string Name;
	float Price;
public:
	Product(const std::string & InitName, float InitPrice)
		: Name(InitName)
		, Price(InitPrice)
	{}

	float GetPrice() const
	{
		return Price;
	}

	void AssignFinalPrice()
	{
		float Taxes[]{ 12,5,5 };
		float BasePrice{ Price };

		ForEach(Taxes, [BasePrice, this](float Tax)
			{
				float TaxedPrice = BasePrice * Tax / 100;
				Price += TaxedPrice;
			});
	}

	auto GetDescription() const
	{
		return [*this](const std::string& Header)
		{
			std::ostringstream ost;
			ost << Header << std::endl;
			ost << "Name : " << Name << std::endl;
			ost << "Price : " << Price << std::endl;

			return ost.str();
		};
	}
};


void UpdateLambdasMain()
{
	Product* P = new Product{ "PlayStation", 1000 };
	P->AssignFinalPrice();
	auto Description = P->GetDescription();

	delete P;

	std::cout << Description("###") << std::endl;

	/* using [this] in capture list in lambda in description function
	*	[this] means a Product pointer is created inside lambda expression that is initialized to
	*	the address that inside [this] pointer, so the lambda internally will have a Product pointer
	*	that will have the same address as [this] pointer
	*
	*	This can cause a problem :
	*
	*	if we create Product on a heap, copy GetDescription() result to Description varibale and invoke later,
	*	but delete Product object before calling.
	*
	*	The pointer that the lambda expression internally has willb ecome dangling because
	*	the object that it is pointing to has already been destroyed.
	*
	*	In C++17 we have a solution.
	*	[*this] - the object is captured by value. So the copy of the Product object will be created inside lambda
	*	(Product object must be copyable)
	*/


	auto f = [](int x, int y)
	{
		return x + y;
	};

	/*
	*	Lambda will become constexpr automatically, if it satisfied criteria of constexpr (can be computed at compile time)
	*/

	constexpr auto sum = f(3, 5);

	//auto sum = f(3, 5); - if use in such case the sum will not be computed at compile time

	printf("%d", sum);
}
