#include "StringView.h"
#include <string_view>
#include <iostream>


void StringViewMain()
{
	using namespace std::string_view_literals;
	// One way to initialize string view :
	std::string_view sv1 = "Hello world!";

	// Other way to initialize string view : using std::string
	std::string str1{ "Hello C++17!" };
	std::string_view sv2{ str1 };

	// Another way to initialize string view : using literals
	auto sv3 = "Using\0literals"sv; // we can embed mu;tiple null characters

	std::cout << "Size : " << sv3.length() << std::endl; // Size : 14
	std::cout << sv3 << std::endl; // Usingliterals

	// data() can return a null pointer if sv3 not initialized
	std::cout << "data() : " << sv3.data() << std::endl; // data() : Using

	std::cout << sv3[0] << std::endl; // no checking - cangive undefined bjavor with wrong index
	std::cout << sv3.at(0) << std::endl; // throw out_of_range exception

	auto f = sv3.find("literals");
	if (f != std::string::npos)
	{
		std::cout << "Found at index : " << f << std::endl;
	}

	// Not remove the first n characters from the string, but simly point to the position after the first n characters
	sv3.remove_prefix(3);
	std::cout << sv3 << std::endl;

	sv3.remove_suffix(2);
	std::cout << sv3 << std::endl;


	auto sv4 = sv1.substr(0, 5);

	std::cout << sv4 << std::endl; // will print Hello
	std::cout << sv4.data() << std::endl; // will print the entire string : Hello world!
}
