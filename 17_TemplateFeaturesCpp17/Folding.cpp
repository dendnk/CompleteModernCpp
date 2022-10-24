#include "Folding.h"
#include <iostream>


auto Sum()
{
	return 0;
}

template<typename T, typename... Args>
auto Sum(T A, Args... Arguments)
{
	return A + Sum(Arguments...);
}

/*
*	Sum(1,2,3,4,5,6)
*	return 1 + Sum(2,3,4,5,6);
*	return 2 + Sum(3,4,5,6);
*	return 3 + Sum(4,5,6);
*	return 4 + Sum(5,6);
*	return 5 + Sum(6);
*	return 6 + Sum();
*	return 6 + 0;
*
*
*	1 + (2 + (3 + (4 + (5 + (6 + 0))))) - this process call folding/reduce or accumulate
*	apply binary operator to a list of elements
*
*	1 + (2 + (3 + (4 + (5 + 6))))
*	1 + (2 + (3 + (4 + 11)))
*	1 + (2 + (3 + 15))
*	1 + (2 + 18)
*	1 + 20
*	21
*
*	To implement folding we need to use recursion and overload this variadic template
*
*
*	In C++17 the fold expressions were introduced and we no need to overload variadic template
*
*	(pack op ...)			- unary right fold
*	(...op pack)			- unary left fold
*	(pack op ... op init)	- binary right fold
*	(init op ... op pack)	- binary left fold
*
*/

template<typename... Args>
auto SumFoldExpression(Args... Arguments)
{
	// Unary right fold
	return (Arguments + ...);

	// Unary left fold
	return (... + Arguments);
}

/*
*	Unary right fold expansion
*	SumFoldExpression(1, 2, 3, 4, 5, 6)
*	1 + (2 + (3 + (4 + (5 + (6 + 0)))))
*
*	Unary left fold expansion
*	(((((1 + 2) + 3) + 4) + 5) + 6) + 0
*/

template<typename... Args>
auto SumBinaryFoldExpression(Args... Arguments)
{
	// Binary right fold
	return (Arguments + ... + 0);

	// Binary left fold
	//return (0 + ... + Arguments);
}

/*
*	Binary right fold expand
*	1 + (2 + (3 + (4 + (5 + (6 + 0)))))
*
*	Binary left fold
*	((((((0 + 1) + 2) + 3) + 4) + 5) + 6)
*
*/


/*
*	These operators can be used with fold expressions:
*	+ - * / % ^ | =  < > << >>
*	+= -= *= /= %=  ^= &= |= <<= >>=
*	== !=  <= >= && || , .* ->*
*
*	&&				-	true
*	||				-	false
*	,				-	void()
*	Others			- ill-formed
*
*/

template<typename ... Args>
bool AnyOf(Args... Arguments)
{
	return (... || (Arguments % 2 == 0));
}

template<typename ... Args>
bool AllOf(Args... Arguments)
{
	return (... && (Arguments % 2 == 0));
}

template<typename ... Args, typename Predicate>
bool AnyOfPredicate(Predicate Pred, Args... Arguments)
{
	return (... || (Pred(Arguments)));
}

template<typename ... Args>
void CustomPrint(Args&&... Arguments)
{
	((std::cout << Arguments << ' '), ...);
}


void FoldingMain()
{
	auto Result = Sum(1, 2, 3, 4, 5, 6);
	auto Result2 = SumFoldExpression(1, 2, 3, 4, 5, 6);
	auto Result3 = SumBinaryFoldExpression(1, 2, 3, 4, 5, 6);

	std::cout << Result << std::endl;
	std::cout << Result2 << std::endl;
	std::cout << Result3 << std::endl;

	//SumFoldExpression() - if you will try pass 0 arguments it will not compile


	std::cout << std::boolalpha;
	std::cout << "Any even? " << AnyOf(10, 2, 3, 4) << std::endl;
	std::cout << "All even? " << AllOf(10, 2, 3, 4) << std::endl;
	std::cout << "AnyOfPredicate even? " << AnyOfPredicate([](const auto x) { return x % 2 == 0;}, 10, 2, 3, 4) << std::endl;

	int Count{ 6 };
	float Height{ 180.9f };
	CustomPrint("Tom has", ++Count, "friends; His height is", Height, "\n");
}
