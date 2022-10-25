#include "Variant.h"
#include <iostream>
#include <variant>


struct Number
{
	int Num;

	Number()
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	Number(int InitNumber)
		: Num(InitNumber)
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	~Number()
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	Number(const Number& Other)
	{
		std::cout << __FUNCSIG__ << std::endl;
		Num = Other.Num;
	}

	Number(Number&& Other) noexcept
	{
		std::cout << __FUNCSIG__ << std::endl;
		Num = Other.Num;
		Other.Num = 0;
	}

	Number& operator=(const Number& Other)
	{
		std::cout << __FUNCSIG__ << std::endl;

		if (this == &Other)
			return *this;

		Num = Other.Num;

		return *this;
	}

	Number& operator=(Number&& Other) noexcept
	{
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &Other)
			return *this;

		Num = Other.Num;

		return *this;
	}

	friend std::ostream& operator << (std::ostream& Out, const Number& InNum)
	{
		Out << InNum.Num;
		return Out;
	}
};


struct VisitorRead
{
	void operator()(const std::string& String) const
	{
		std::cout << "String : " << String << std::endl;
	}

	void operator()(int x) const
	{
		std::cout << "Int : " << x << std::endl;
	}

	void operator()(const Number& Num) const
	{
		std::cout << "Number : " << Num << std::endl;
	}
};

struct Modifier
{
	void operator()(std::string& String) const
	{
		String += " modified";
	}

	void operator()(int& x) const
	{
		x += 9999;
	}

	void operator()(Number& Num) const
	{
		Num = 132;
	}
};


void VariantMain()
{
	/*
	*	Other way through which we can modify or read active members in the variant is through visitation
	*	We use function called visit.
	*	visit requires a visitor.
	*	Visitor - class that provide function call operator for each possible type
	*/

	try
	{
		std::variant<std::string, int, Number> v{ 7 };
		std::visit(Modifier{}, v);
		std::visit(VisitorRead{}, v);

		v = "C++";
		std::visit(Modifier{}, v);
		std::visit(VisitorRead{}, v);

		v.emplace<Number>(100);
		std::visit(Modifier{}, v);
		std::visit(VisitorRead{}, v);

		// We can use lambda as visitor function

		auto VisitorLambda = [](auto& x)
		{
			// Use alias to get type of x
			//using T = decltype(x);

			// decltype(x) will return the type as a reference, but we not compare referemce types
			// so we need to decay this expression to the basic type
			// using decay_t

			using T = std::decay_t<decltype(x)>;

			if constexpr (std::is_same_v<T, int>)
			{
				// to do if integer
				std::cout << "Int : " << x << std::endl;
			}
			else if constexpr (std::is_same_v<T, std::string>)
			{
				// to do if std::string
				std::cout << "String : " << x << std::endl;
			}
			else if constexpr (std::is_same_v<T, Number>)
			{
				// to do if Number
				std::cout << "Number : " << x << std::endl;
			}

		};

		v = "using lambda";
		std::visit(VisitorLambda, v);

		v = 100500;
		std::visit(VisitorLambda, v);

		v = Number{ 500100 }; // assignment
		std::visit(VisitorLambda, v);

		v.emplace<Number>(2022); // using emplace
		std::visit(VisitorLambda, v);
	}
	catch (const std::exception& ex)
	{
		std::cout << "Exception : " << ex.what() << std::endl;
	}


	//try
	//{
	//	//std::variant<std::string, int, Number> v{ Number{5} };

	//	//v = Number{ 1 }; // here we construct Number temporary object

	//	//std::get<Number>(v) = 100; // here we no need to construct temporary Number object and can assigned new value directly

	//	//std::variant<std::string, int, Number> v2{ 7 };

	//	//// here the variant will construct and initialized the Number member
	//	////v2 = Number{ 1 };

	//	//// here we cannot construct and init Number, because we try use reference, that cannot be returned because we have no constructed Number
	//	//// it will throw an exception : bad variant access
	//	//std::get<Number>(v2) = 100;


	//	// Alternatively way to initialize of each member - use emplace() function
	//	std::variant<std::string, int, Number> v3{ 7 };
	//	v3.emplace<Number>(100);
	//	std::get<Number>(v3) = 100;

	//}
	//catch (const std::exception& ex)
	//{
	//	std::cout << "Exception : " << ex.what() << std::endl;
	//}


	//try
	//{
	//	// This will automatically construct and initialized the first member using default initialization
	//	// The second memeber will not be constructed
	//	std::variant<std::string, int> v1;

	//	// We can initilize any member of the variant
	//	// This will automatically construct and initialize the second member
	//	// First member will not be constructed
	//	std::variant<std::string, int> v{ 5 };

	//	// get returns a reference to active member

	//	// We can get the value if specified the type of active member
	//	auto val = std::get<int>(v);

	//	// Try to pass the other type - it will throw an exception : bad variant access
	//	//auto val2 = std::get<std::string>(v);

	//	// If you try to get type that not eexist in a variant - it will not compile
	//	//auto val3 = std::get<float>(v);

	//	// We can get the value if specified the index of active member
	//	val = std::get<1>(v);

	//	// If we pass no active member - it will throw an exception : bad variant access
	//	//val2 = std::get<0>(v);

	//	// auto val3 = std::get<3>(v); // it will not compile

	//	// This will return the index of active member
	//	auto ActiveIndex = v.index();

	//	std::cout << ActiveIndex << std::endl;

	//	// get_if returns a pointer to active element
	//	auto p = std::get_if<int>(&v);
	//	std::cout << *p << std::endl;

	//	auto p1 = std::get_if<1>(&v);
	//	std::cout << *p1 << std::endl;

	//	// It will not compiled
	//	//auto p3 = std::get_if<10>(&v);
	//	//auto p4 = std::get_if<float>(&v);

	//	// if it pass inactive type - it will return nullptr
	//	auto p5 = std::get_if<std::string>(&v);
	//	if (p5 == nullptr)
	//	{
	//		std::cout << "No active type" << std::endl;
	//	}
	//}
	//catch (const std::exception& ex)
	//{
	//	std::cout << "Exception : " << ex.what() << std::endl;
	//}


}
