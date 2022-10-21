#include "FeatureTestMacro.h"
#include <iostream>

#ifdef __has_include
#	if __has_include(<filesystem>)
#		include <filesystem>
		namespace fs = std::filesystem;
#	else
#		include <experimental/filesystem>
		namespace fs = std::experimental::filesystem;
#	endif
#endif


void FeatureTestMacroMain()
{
	fs::path p{ "C:" };

	// C++ 20 standard
	// These macros return year and month when it was added to work draft
	std::cout << __cpp_inline_variables << std::endl;
	std::cout << __cpp_capture_star_this << std::endl;
}
