//
//  main_section92.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 25.06.2022.
//

#include <iostream>
#include <vector>

std::string ToLower(const std::string &str)
{
    std::string Result;
    for (int i(0); i < str.length(); ++i)
    {
        Result += tolower(str[i]);
    }
    return Result;
}


enum class Case
{
    SENSITIVE,
    INSENSITIVE
};
 
size_t Find(
 const std::string &source,         //Source string to be searched
 const std::string &search_string,  //The string to search for
 Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
 size_t offset = 0 )
{
    std::string TempSource = source;
    std::string TempSearchString = search_string;
    
    if (searchCase == Case::INSENSITIVE)
    {
        TempSource = ToLower(TempSource);
        TempSearchString = ToLower(TempSearchString);
    }
    
    auto ResultPosition = TempSource.find(TempSearchString,offset);
    
    return ResultPosition;
}
 
std::vector<int>
FindAll(
 const std::string &target,              //Target string to be searched
 const std::string &search_string,       //The string to search for
 Case searchCase = Case::INSENSITIVE,    //Choose case sensitive/insensitive search
 size_t offset = 0)
{
    std::vector<int> Results;
    size_t ResultOffset = offset;
    
    while (ResultOffset != std::string::npos)
    {
        ResultOffset = Find(target,search_string,searchCase,ResultOffset);
        if (ResultOffset != std::string::npos)
        {
            Results.push_back(ResultOffset++);
        }
    }

    return Results;
}

void PrintVector(std::vector<int> values)
{
    for (const auto x : values)
    {
        std::cout << x << " ";
    }
    
    std::cout << std::endl;
}

int main(int argc, const char * argv[])
{
    std::string source("abc ab ac ad baab");
    std::string substr("Ab");
    
    PrintVector(FindAll(source,substr,Case::INSENSITIVE));
    
    return 0;
}
