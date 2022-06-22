//
//  Integer.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 22.06.2022.
//

#include "Integer.h"
#include <iostream>


Integer::Integer() : Integer(0)
{
    std::cout << "Integer()" << std::endl;
}

Integer::Integer(int NewValue)
{
    std::cout << "Integer(int NewValue)" << std::endl;
    PValue = new int (NewValue);
}

Integer::Integer(const Integer &Obj)
{
    std::cout << "Integer(const Integer &Obj)" << std::endl;
    PValue = new int (*Obj.PValue);
}

Integer::Integer(Integer &&Obj)
{
    std::cout << "Integer(Integer &&Obj)" << std::endl;
    PValue = Obj.PValue;
    Obj.PValue = nullptr;
}

int Integer::GetValue() const
{
    std::cout << "GetValue()" << std::endl;
    if (PValue != nullptr)
    {
        return *PValue;
    }
    else
    {
        std::cout << "PValue = nullptr!" << std::endl;
        return -1;
    }
        
}

void Integer::SetValue(int NewValue)
{
    std::cout << "SetValue(int NewValue)" << std::endl;
    if (PValue == nullptr)
    {
        PValue = new int (NewValue);
    }
    else
    {
        *PValue = NewValue;
    }
}

Integer::~Integer()
{
    std::cout << "~Integer()" << std::endl;
}

Integer Integer::operator +(const Integer &Obj) const
{
    std::cout << "operator +(const Integer &SecondOperand)" << std::endl;
    Integer Result;
    Result.SetValue(GetValue() + Obj.GetValue());
    return Result;
}

Integer & Integer::operator++()
{
    if (PValue == nullptr)
    {
        PValue = new int (1);
    }
    else
    {
        ++(*PValue);
    }
    return *this;
}

Integer Integer::operator++(int)
{
    Integer Temp(*this);
    ++(*PValue);
    return Temp;
}

bool Integer::operator==(const Integer &Obj) const
{
    return *PValue == *Obj.PValue;
}

Integer &Integer::operator=(const Integer &Obj)
{
    if (this != &Obj)
    {
        delete PValue;
        PValue = new int (*Obj.PValue);

    }
    
    return *this;
}

Integer &Integer::operator=(Integer &&Obj)
{
    if (this != &Obj)
    {
        delete PValue;
        PValue = Obj.PValue;
        Obj.PValue = nullptr;
    };
    return *this;
}
