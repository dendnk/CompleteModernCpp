//
//  main.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 22.06.2022.
//

#include <iostream>
#include "Integer.h"

int main(int argc, const char * argv[])
{
    Integer a(1);
    Integer b(3);
    
    Integer c;
    a = a;
    
    std::cout << a.GetValue() << std::endl;
    
    return 0;
}
