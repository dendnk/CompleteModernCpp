//
//  main_section89.cpp
//  CompleteModernCpp
//
//  Created by Denis Kruchok on 25.06.2022.
//

#include <iostream>

class Distance
{
    long double Kilometers;
public:
    Distance(long double km) : Kilometers(km) {}
    
    long double GetKm() const { return Kilometers; }
    void SetKm(long double NewValue) { Kilometers = NewValue; }
};

// Always global function
Distance operator"" _mi(long double ValueInMiles)
{
    return Distance(ValueInMiles * 1.6);
}
// Always global function
Distance operator"" _meters(long double ValueInMiles)
{
    return Distance(ValueInMiles / 1000);
}

//int main(int argc, const char * argv[])
//{
//    Distance Dist1(32.0_mi);
//    Distance Dist2(7532.0_meters);
//    
//    std::cout << Dist1.GetKm() << std::endl;
//    std::cout << Dist2.GetKm() << std::endl;
//    
//    return 0;
//}
