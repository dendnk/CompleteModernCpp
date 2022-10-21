#include "NestedNamespaces.h"

namespace X
{
	namespace Y
	{
		namespace Z
		{

		}
	}
}

// New variant C++17
namespace A::B::C
{
	void Foo()
	{

	}
}

void NestedNamespacesMain()
{
	A::B::C::Foo();
}
