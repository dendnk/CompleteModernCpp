#include <iostream>
#include <memory>
#include <vector>
#include <random>


//class Test
//{
//public:
//    Test()
//    {
//        std::cout << "Test() : Acquire resources" << std::endl;
//    }
//
//    ~Test()
//    {
//        std::cout << "~Test() : Release resources" << std::endl;
//    }
//};
//
//int ProcessRecords(int count)
//{
//    std::unique_ptr<Test> t(new Test);
//
//    if (count < 10)
//        throw std::out_of_range("Count should be greater than 10");
//
//    std::vector<int> p;
//    p.reserve(count);
//
//    std::vector<int> pArray;
//    pArray.reserve(count);
//
//    for (int i(0); i < count; ++i)
//        pArray.push_back(i);
//
//    std::default_random_engine RandomEngine;
//    std::bernoulli_distribution Disribution;
//    int ErrorsNum{};
//
//    for (int i(0); i < count; ++i)
//    {
//        try
//        {
//            std::cout << "Processing record # : " << i << " ";
//
//            if (!Disribution(RandomEngine))
//            {
//                ++ErrorsNum;
//                throw std::runtime_error("Could not process the record!");
//            }
//
//            std::cout << std::endl;
//        }
//        catch (std::exception& ex)
//        {
//            std::cout << "[ERROR : " << ex.what() << "]" << std::endl;
//            if (ErrorsNum > 4)
//            {
//                std::runtime_error Error("Too many errors. Abonding operation");
//                ex = Error;
//                throw;
//            }
//        }
//    }
//
//    return 0;
//}


//class A
//{
//public:
//    A() { std::cout << "A()" << std::endl; }
//    ~A() { std::cout << "~A()" << std::endl; }
//};
//
//class B
//{
//public:
//    B() { std::cout << "B()" << std::endl; }
//    ~B() { std::cout << "~B()" << std::endl; }
//};
//
//class Test
//{
//    std::unique_ptr<A> pA{};
//    B b{};
//    std::unique_ptr<int> pInt{};
//    std::string pStr{};
//    std::vector<int> pArr{};
//
//
//public:
//    Test()
//    {
//        std::cout << "Test()" << std::endl;
//        pA.reset(new A);
//        throw std::runtime_error("Failed to initialize");
//        //pA = new A;
//        //pInt = new int;
//        //throw std::runtime_error("Failed to initialize");
//        //pStr = new char[1000];
//        //pArr = new int[50000];
//    }
//
//    ~Test()
//    {
//        std::cout << "~Test()" << std::endl;
//        //delete pA;
//        //delete pInt;
//        //delete[] pStr;
//        //delete[] pArr;
//    }
//};

void TestWithThrough(int x) noexcept(false)
{
    std::cout << x << std::endl;
    //throw x;
}

int Sum(int x, int y) noexcept(noexcept(TestWithThrough(x)))
{
    TestWithThrough(x);
    return x + y;
}

int main()
{
    std::cout << std::boolalpha << noexcept(TestWithThrough(5)) << std::endl;
    try
    {
        Sum(3, 5);
    }
    catch (int x)
    {
        std::cout << x << std::endl;
    }

    /*try
    {
        Test t;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }*/

    //try
    //{
    //    //ProcessRecords(std::numeric_limits<int>::max());
    //    ProcessRecords(10);
    //}
    //catch (std::runtime_error &ex)
    //{
    //    std::cout << ex.what() << std::endl;
    //}
    //catch (std::out_of_range& ex)
    //{
    //    std::cout << ex.what() << std::endl;
    //}
    //catch (std::bad_alloc& ex)
    //{
    //    std::cout << ex.what() << std::endl;
    //}
    //catch (std::exception& ex)
    //{
    //    std::cout << ex.what() << std::endl;
    //}
    ///*catch (...)
    //{
    //    std::cout << "Exception" << std::endl;
    //}*/

    return 0;
}
