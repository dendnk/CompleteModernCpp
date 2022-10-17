#pragma once

#include <vector>
#include <iostream>

template<typename T>
T Max(T x, T y)
{
    return x > y ? x : y;
}

template<typename T>
T Add(T& x, T& y)
{
    return x + y;
}

template<typename T>
T ArraySum(const T* pArray, size_t arrSize)
{
    T Sum{};

    for (int i(0); i < arrSize; ++i)
    {
        Sum += pArray[i];
    }

    return Sum;
}

template<typename T>
T ArrayMax(const T* pArray, size_t arrSize)
{
    T Max = pArray[0];

    for (int i(1); i < arrSize; ++i)
    {
        if (pArray[i] > Max)
        {
            Max = pArray[i];
        }
    }

    return Max;
}

template<typename T>
T ArrayMin(const T* pArray, size_t arrSize)
{
    T Min = pArray[0];

    for (int i(1); i < arrSize; ++i)
    {
        if (pArray[i] < Min)
        {
            Min = pArray[i];
        }
    }

    return Min;
}

template<typename T>
std::pair<T, T> ArrayMinMax(const T* pArray, size_t arrSize)
{
    return std::pair<T, T> { ArrayMin(pArray, arrSize)
        , ArrayMax(pArray, arrSize)};
}

void IntroductionMain()
{
    std::cout << Max(3.3f, 4.5f) << " " << Max(9, 55) << std::endl;

    int a[]{ 0, 1, 298, -353, 4, 5, -6, 7, -8, -9 };
    float b[]{ 5.1f, -2.5f, 3.9f, -4.6f };

    auto Sum1 = ArraySum(a, sizeof(a) / sizeof(int));
    auto Sum2 = ArraySum(b, sizeof(b) / sizeof(float));

    std::cout << Sum1 << std::endl;
    std::cout << Sum2 << std::endl;

    auto Max1 = ArrayMax(a, sizeof(a) / sizeof(int));
    auto Max2 = ArrayMax(b, sizeof(b) / sizeof(float));

    std::cout << Max1 << std::endl;
    std::cout << Max2 << std::endl;

    auto MinMax1 = ArrayMinMax(a, sizeof(a) / sizeof(int));
    auto MinMax2 = ArrayMinMax(b, sizeof(b) / sizeof(float));

    std::cout << MinMax1.first << " " << MinMax1.second << std::endl;
    std::cout << MinMax2.first << " " << MinMax2.second << std::endl;
}
