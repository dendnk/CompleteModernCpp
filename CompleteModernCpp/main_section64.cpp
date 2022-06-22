//
//  main_section64.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 22.06.2022.
//

#include <stdio.h>
#include "Integer.h"

class IntPtr
{
    Integer * m_p;
public:
    IntPtr(Integer *p) : m_p(p) {}
    ~IntPtr()
    {
        delete m_p;
    }
    
    Integer * operator -> ()
    {
        return m_p;
    }
    
    Integer & operator * ()
    {
        return *m_p;
    }
};

void CreateInteger()
{
    IntPtr p = new Integer;
    (*p).SetValue(3);
//    std::cout << p->GetValue() << std::endl;
}

//int main(int argc, const char * argv[])
//{
//    CreateInteger();
//    return 0;
//}
