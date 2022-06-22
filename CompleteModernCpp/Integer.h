//
//  Integer.h
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 22.06.2022.
//

#ifndef Integer_h
#define Integer_h

class Integer
{
    int * PValue;
public:
    Integer();
    Integer(int NewValue);
    Integer(const Integer & Obj);
    Integer(Integer && Obj);
    int GetValue() const;
    void SetValue(int NewValue);
    ~Integer();
    
    Integer operator +(const Integer & Obj) const;
    Integer & operator ++();
    Integer operator ++(int);
    bool operator == (const Integer & Obj) const;
    
    Integer & operator = (const Integer & Obj);
    Integer & operator = (Integer && Obj);
};

#endif /* Integer_h */
