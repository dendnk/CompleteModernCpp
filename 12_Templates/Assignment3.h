#pragma once

#include <iostream>


template<typename T, size_t arrSize>
T ArraySum(const T(&ArrayRef)[arrSize])
{
    T Sum{};

    for (int i(0); i < arrSize; ++i)
    {
        Sum += ArrayRef[i];
    }

    return Sum;
}

template<typename T, size_t arrSize>
T ArrayMax(const T(&ArrayRef)[arrSize])
{
    T Max = ArrayRef[0];

    for (int i(1); i < arrSize; ++i)
    {
        if (ArrayRef[i] > Max)
        {
            Max = ArrayRef[i];
        }
    }

    return Max;
}

template<typename T, size_t arrSize>
T ArrayMin(const T(&ArrayRef)[arrSize])
{
    T Min = ArrayRef[0];

    for (int i(1); i < arrSize; ++i)
    {
        if (ArrayRef[i] < Min)
        {
            Min = ArrayRef[i];
        }
    }

    return Min;
}

template<typename T, size_t arrSize>
std::pair<T, T> ArrayMinMax(T(&ArrayRef)[arrSize])
{
    return std::pair<T, T> { ArrayMin(ArrayRef), ArrayMax(ArrayRef)};
}

// Explicit Specialization ArraySum for an array of strings (const char *)
template<size_t arrSize> const char* ArraySum(const char* (&ArrayRef)[arrSize])
{
    std::string Sum{ "" };

    for (int i(0); i < arrSize; ++i)
    {
        Sum += ArrayRef[i];
    }

    auto ResultSize = Sum.length() + 1;

    char* Result = new char[ResultSize];
    strcpy_s(Result, ResultSize, &Sum.front());

    return Result;
}

// Explicit Specialization ArrayMax for an array of strings (const char *)
template<size_t arrSize> const char* ArrayMax(const char* (&ArrayRef)[arrSize])
{
    auto Max = ArrayRef[0];

    for (int i(1); i < arrSize; ++i)
    {
        if (strcmp(ArrayRef[i], Max) > 0)
        {
            Max = ArrayRef[i];
        }
    }

    return Max;
}

// Explicit Specialization ArrayMin for an array of strings (const char *)
template<size_t arrSize> const char* ArrayMin(const char* (&ArrayRef)[arrSize])
{
    auto Min = ArrayRef[0];

    for (int i(1); i < arrSize; ++i)
    {
        if (strcmp(ArrayRef[i], Min) < 0)
        {
            Min = ArrayRef[i];
        }
    }

    return Min;
}

// Explicit Specialization ArrayMinMax for an array of strings (const char *)
template<size_t arrSize> std::pair<const char*, const char*> ArrayMinMax(const char* (&ArrayRef)[arrSize])
{
    return std::pair<const char*, const char*> { ArrayMin(ArrayRef), ArrayMax(ArrayRef)};
}


void Assignment3_Main();

/*
* The specialization is only for the typename parameter & not for non-type template parameter.
So, this is not technically an explicit specialization. In explicit specialization, ALL the template parameters are specialized.
That's why there are no build errors.
You can put this explicit specialization in the header file and it will cause the build to fail:
template<>
const char ArraySum(const char (&arr_ref)[10])
{ //specialized for char & size 10
    return ' ' ;
}
*/
