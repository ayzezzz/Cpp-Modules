#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>
// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }

int main() {
    try {
        unsigned int limit = 10000;
        Span bigSpan(limit);
        std::vector<int> numbers;
        
        std::srand(std::time(0));
        for (unsigned int i = 0; i < limit; i++) {
            numbers.push_back(std::rand());
        }

        bigSpan.addNumbers(numbers.begin(), numbers.end());

        std::cout << "10k Test - Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "10k Test - Longest: " << bigSpan.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Span small(1);
        small.addNumber(10);
        small.shortestSpan(); 
    } catch (std::exception &e) {
        std::cout << "Expected Exception: " << e.what() << std::endl;
    }

    return 0;
}