#include "ClassTemplatePartialSpec.h"

void ClassTemplatePartialSpecMain()
{
	int data = 800;
	PrettyPrinter<int, 80> p{ &data };
	p.Print();

	SmartPointer<int[]> sp1{ new int[5] };
	sp1[0] = 56;
	std::cout << sp1[0] << std::endl;
}
