//
//  main_section65.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 22.06.2022.
//

#include <stdio.h>
#include "Integer.h"
#include <memory>


void DoSmth(std::shared_ptr<Integer> ptr)
{
    std::cout << ptr->GetValue() << std::endl;
}

void CreateInteger65()
{
    std::shared_ptr<Integer> p (new Integer);
    (*p).SetValue(3);
    
    DoSmth(p);
}


//int main(int argc, const char * argv[])
//{
//    CreateInteger65();
//    return 0;
//}
