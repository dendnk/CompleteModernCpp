#include "CaptureList.h"
#include <iostream>


template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp)
{
    for (int i(0); i < size - 1; ++i)
        for (int j(0); j < size - 1; ++j)
        {
            if (comp(arr[j], arr[j + 1]))
            {
                T Temp = std::move(arr[j]);
                arr[j] = std::move(arr[j + 1]);
                arr[j + 1] = std::move(Temp);
            }
        }

}

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation)
{
    for (int i(0); i < size; ++i)
    {
        operation(arr[i]);
    }
}

template<typename T, int size>
void PrintArray(T(&arr)[size])
{
    ForEach(arr, [](auto x)
        {
            std::cout << x << " ";
        });

    std::cout << std::endl;
}


void CaptureListMain()
{
    int arr[]{ 1,6,8,4,9,555,3,0,5,6 };

    PrintArray(arr);

    auto comp = [](auto x, auto y)
    {
        return x > y;
    };

    Sort(arr, comp);
    PrintArray(arr);

    int offset = 3;
    ForEach(arr, [offset](auto& x) mutable
        {
            x += offset;
            ++offset;
        });
    PrintArray(arr);
}
