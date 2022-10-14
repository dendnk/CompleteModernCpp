#include "ClassTemplates.h"
#include <iostream>

void ClassTemplatesMain()
{
	auto s = Stack<float, 10>::Create();

	s.Push(3.3f);
	s.Push(1);
	s.Push(7);
	s.Push(888);

	auto s2(s);

	while (!s2.IsEmpty())
	{
		std::cout << s2.GetTop() << " ";
		s2.Pop();
	}
}
