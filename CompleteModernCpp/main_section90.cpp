//
//  main_section90.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 25.06.2022.
//

#include <stdio.h>

constexpr int GetNumber()
{
    return 7;
}

constexpr int Add (int x, int y)
{
    return x+y;
}

int main(int argc, const char * argv[])
{
    // Behaves as constexpr function (computed at compile time)
    constexpr int i = GetNumber();
    int arr[i];
    
    // Behaves as constexpr function (computed at compile time)
    const int j = GetNumber();
    int arr1[j];
    
    // Behaves as normal function
    int x = GetNumber();
    
    // Behaves as constexpr function (computed at compile time)
    constexpr int sum = Add(3,5);
    
    // Behaves as normal function
    int sum2 = Add(sum,5);
    
    return 0;
}

// Constexpr function should accept and return only literal types
// Literal types
// void, scalar, types(int,float,char), references and etc.

// Should contain only single line statement that should be a return statement.

// All constexpr are implicity inline, defined in header
