#include "Assignment3.h"

//// Explicit Specialization ArraySum for an array of strings (const char *)
//template<size_t arrSize> const char* ArraySum(const char* (&ArrayRef)[arrSize])
//{
//    std::string Sum{ "" };
//
//    for (int i(0); i < arrSize; ++i)
//    {
//        Sum += ArrayRef[i];
//    }
//
//    auto ResultSize = Sum.length() + 1;
//
//    char* Result = new char[ResultSize];
//    strcpy_s(Result, ResultSize, &Sum.front());
//
//    return Result;
//}
//
//// Explicit Specialization ArrayMax for an array of strings (const char *)
//template<size_t arrSize> const char* ArrayMax(const char* (&ArrayRef)[arrSize])
//{
//   auto Max = ArrayRef[0];
//
//    for (int i(1); i < arrSize; ++i)
//    {
//        if (strcmp(ArrayRef[i], Max) > 0)
//        {
//            Max = ArrayRef[i];
//        }
//    }
//
//    return Max;
//}
//
//// Explicit Specialization ArrayMin for an array of strings (const char *)
//template<size_t arrSize> const char* ArrayMin(const char* (&ArrayRef)[arrSize])
//{
//    auto Min = ArrayRef[0];
//
//    for (int i(1); i < arrSize; ++i)
//    {
//        if (strcmp(ArrayRef[i], Min) < 0)
//        {
//            Min = ArrayRef[i];
//        }
//    }
//
//    return Min;
//}
//
//// Explicit Specialization ArrayMinMax for an array of strings (const char *)
//template<size_t arrSize> std::pair<const char*, const char*> ArrayMinMax(const char* (&ArrayRef)[arrSize])
//{
//    return std::pair<const char*, const char*> { ArrayMin(ArrayRef), ArrayMax(ArrayRef)};
//}


void Assignment3_Main()
{
    // Array of strings (const char*)

    //const char* msg1{ "Hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello " };
    //const char* msg2{ "World" };
    //const char* msg3{ "!" };
    //const char* ArrString[] = { msg1, msg2, msg3 };

    //auto ResultSum = ArraySum(ArrString);
    //auto ResultMax = ArrayMax(ArrString);
    //auto ResultMin = ArrayMin(ArrString);
    //auto ResultMinMax = ArrayMinMax(ArrString);

    //std::cout << "ArraySum : " << ResultSum << std::endl;
    //std::cout << "ArrayMax : " << ResultMax << std::endl;
    //std::cout << "ArrayMin : " << ResultMin << std::endl;
    //std::cout << "ArrayMinMax : " << ResultMinMax.first << " " << ResultMinMax.second << std::endl;

    // Array of std::strings
    std::string str1{ "Complete complete complete complete complete complete complete complete complete complete complete complete complete " };
    std::string str2{ "modern modern modern modern modern modern modern modern modern modern modern modern modern modern modern modern modern " };
    std::string str3{ "C++" };
    std::string str4{ "z" };
    std::string str5{ "Z" };

    std::string ArrString2[] = { str1, str2, str3, str4, str5 };

    auto ResultSum = ArraySum(ArrString2);
    auto ResultMax = ArrayMax(ArrString2);
    auto ResultMin = ArrayMin(ArrString2);
    auto ResultMinMax = ArrayMinMax(ArrString2);

    std::cout << "ArraySum : " << ResultSum << std::endl;
    std::cout << "ArrayMax : " << ResultMax << std::endl;
    std::cout << "ArrayMin : " << ResultMin << std::endl;
    std::cout << "ArrayMinMax : " << ResultMinMax.first << " " << ResultMinMax.second << std::endl;
}
