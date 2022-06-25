//
//  main_section91.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 25.06.2022.
//

#include <iostream>
#include <initializer_list>

class Bag
{
    int Arr[10];
    int Size{};
public:
    Bag(std::initializer_list<int> values)
    {
        assert(values.size() < 10);
        auto it = values.begin();
        while (it != values.end())
        {
            Add(*it++);
        }
    }
    
    void Add(int value)
    {
        assert(Size < 10);
        Arr[Size++] = value;
    };
    
    void Remove()
    {
        --Size;
    }
    
    int operator [](int index)
    {
        return Arr[index];
    }
    
    int GetSize() const { return Size; }
    
};

void PrintList(std::initializer_list<int> values)
{
    for (auto x : values)
    {
        std::cout << x << " ";
    }
    
    std::cout << std::endl;
}

//int main(int argc, const char * argv[])
//{
//    int x {0};
//    float y{3.1f};
//    int arr[5]{3,1,2,6};
//
//    std::string str{"Hello world!"};
//
//    std::initializer_list<int> data = {1,2,35};
//    auto values = {1,2,35};
//
//    Bag b {3,1,2};
//
//    PrintList({3,1,4,5});
//
//    return 0;
//}
