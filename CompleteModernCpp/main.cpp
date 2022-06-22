//
//  main.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 22.06.2022.
//

#include <iostream>
#include "Integer.h"

Integer operator + (int x, const Integer & y)
{
    Integer Temp;
    Temp.SetValue(x + y.GetValue());
    return Temp;
    
}

std::ostream & operator << (std::ostream & out, const Integer & obj)
{
    out << obj.GetValue();
    return out;
}

std::istream & operator >> (std::istream & in, Integer & obj)
{
    int k;
    in >> k;
    
    /*
        If we cannot set value via separate function and we need to get access to private memebers of class, we neeed to use keyword "friend" for function in class declaration
     */
    //obj.SetValue(k);
    *obj.PValue = k;
    
    return in;
}

int main(int argc, const char * argv[])
{
    Integer A(1);
    Integer B(3);
    
    Integer Sum1 = A + 5; // A.operator(5)
    Integer Sum2 = 5 + A;
    
    //std::cout << Sum1.GetValue() << std::endl;
    //std::cout << Sum2.GetValue() << std::endl;
    std::cout << Sum1 << std::endl;
    
//    std::cin >> A;
//    std::cout << A << std::endl;
    
    B();
    
    return 0;
}
