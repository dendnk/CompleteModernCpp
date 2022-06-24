//
//  main_section86.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 24.06.2022.
//

#include <iostream>
#include <string>
#include <cstring>

std::string ToUpper(const std::string &str)
{
    std::string Result;
    for (int i(0); i < str.length(); ++i)
    {
        Result += toupper(str[i]);
    }
    return Result;
}

std::string ToLower(const std::string &str)
{
    std::string Result;
    for (int i(0); i < str.length(); ++i)
    {
        Result += tolower(str[i]);
    }
    return Result;
}

int main(int argc, const char * argv[])
{
    std::string InputString;
    std::getline(std::cin, InputString);
    
    std::cout << ToLower(InputString) << std::endl;
    std::cout << ToUpper(InputString) << std::endl;
    
    return 0;
}
