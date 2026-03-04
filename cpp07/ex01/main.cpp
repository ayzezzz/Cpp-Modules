#include "Iter.hpp"
#include <string>

template <typename T>
void multiplyTwo(T &index)
{
    index *= 2;
}
int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Int dizi: " << std::endl;
    ::iter(intArray, 5, multiplyTwo<int>);
    ::iter(intArray, 5, printIter<int>);
    std::cout << std::endl;

    // int intArray[] = {1, 2, 3, 4, 5};
    // std::cout << "Int dizi: " << std::endl;
    // ::iter(intArray, 5, printIter<int>);
    // std::cout << std::endl;

    // std::string strArray[] = {"Merhaba", "C++", "42", "Istanbul"};
    //  std::cout << "String dizi: " << std::endl;
    //  ::iter(strArray, 4, printIter<std::string>);
    //  std::cout << std::endl;

    // const int constArray[] = {10, 20, 30};
    // std::cout << "Const dizi: " << std::endl;
    // ::iter(constArray, 3, printIter<const int>);
    // std::cout << std::endl;

    return 0;
}