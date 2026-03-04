#include "Array.hpp"
#include <iostream>

int main() {
    Array<int> numbers(5);
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;
    
    std::cout << "numbers array: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;


    const Array<int> constNumbers = numbers;
    std::cout << "const index : " << constNumbers[2] << std::endl;

    std::cout << "\n exception " << std::endl;
    try {
        std::cout << "trying index 10" << std::endl;
        std::cout << numbers[10] << std::endl; 
    }
    catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }

    std::cout << "\n deep Copy " << std::endl;
    Array<int> copyTest = numbers;
    numbers[0] = 999;
    std::cout << "original num: " << numbers[0] << " - copy num: " << copyTest[0] << std::endl;

    return 0;
}