#include "UpdateNoException.h"

void Foo() noexcept
{

}

void Bar()
{

}

void UpdateNoExceptionMain()
{
	//void (*p)()noexcept;
	//p = Foo;
	//p = Bar; // will not compile in C++17

	void (*p)();
	p = Foo;
	p();
}
