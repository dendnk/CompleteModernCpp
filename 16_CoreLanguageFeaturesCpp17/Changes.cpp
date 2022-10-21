#include "Changes.h"
#include <initializer_list>


void ChangesMain()
{
    // Direct List Initialization

    auto a{ 1 };        // int
    //auto b{ 1,2 };      // ill-formed;
    auto c = { 1 };     // std::initializer list
    auto d = { 1, 2 };  // std::initializer list

    // Range-based for loop

    /*
    *   begin() and end() iterators can be of different types,
    *   but must provide operator != for comparison
    *   (until c++14 begin & end iterators must be same)
    */

    // static_assert

    /*
    *   Was introduced in C++11 for compile time assertions
    *   It accepts 2 paramteres :
    *   one condition and other is the message
    *
    *   In C++17 the message is optional
    */

    //static_assert(5 != 5);
    //static_assert(5 != 5, "5!=5");
}
