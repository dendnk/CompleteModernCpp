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
    
    Integer sum = a+b;
    
    std::cout << (sum++).GetValue() << std::endl;
    
    return 0;
}
