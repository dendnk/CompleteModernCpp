//
//  main_section88.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 25.06.2022.
//

#include <stdio.h>
#include <iostream>
#include <string>

std::string ToUpper(const std::string &str)
{
    std::string Result;
    for (int i(0); i < str.length(); ++i)
    {
        Result += toupper(str[i]);
    }
    return Result;
}

//std::string ToLower(const std::string &str)
//{
//    std::string Result;
//    for (int i(0); i < str.length(); ++i)
//    {
//        Result += tolower(str[i]);
//    }
//    return Result;
//}
//
//
//enum class Case
//{
//    SENSITIVE,
//    INSENSITIVE
//};
// 
//size_t Find(
// const std::string &source,         //Source string to be searched
// const std::string &search_string,  //The string to search for
// Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
// size_t offset = 0 )
//{
//    std::string TempSource = source;
//    std::string TempSearchString = search_string;
//    
//    if (searchCase == Case::INSENSITIVE)
//    {
//        TempSource = ToLower(TempSource);
//        TempSearchString = ToLower(TempSearchString);
//    }
//    
//    auto ResultPosition = TempSource.find(TempSearchString,offset);
//    
//    return ResultPosition;
//}

//int main(int argc, const char * argv[])
//{
//    std::string InputString("H_aRRy Potter");
//    std::string SearchString("aRRy");
//    
//    auto SubstrPos = Find(InputString,SearchString, Case::SENSITIVE, 1);
//    
//    if (SubstrPos == std::string::npos)
//    {
//        std::cout << "Substring was not found!" << std::endl;
//    }
//    else
//    {
//        std::cout << SubstrPos << std::endl;
//    }
//    
//    return 0;
//}
