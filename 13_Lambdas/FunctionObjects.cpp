#include "FunctionObjects.h"
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

bool Comp1(int x, int y)
{
    return x > y;
}

template<typename T, int size>
void PrintArray(T(&arr)[size])
{
    for (auto x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

struct Comp2
{
    bool operator()(int x, int y)
    {
        return x > y;
    }
};


void FunctionObjectsMain()
{
    Comp1(3, 5); // Global function call
    Comp2 comp;
    comp(3, 5);  //comp.operator()(3,5) Member function call

    int arr[]{ 1,6,8,4,9,555,3,0,5,6 };
    PrintArray(arr);
    Sort(arr, comp);
    PrintArray(arr);
}
