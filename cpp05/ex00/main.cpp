#include "Bureaucrat.hpp"

int main()
{
    std::cout << "---  Normal ---" << std::endl;
    try {
        Bureaucrat zerrin("Zerrin", 0);
        std::cout << zerrin << std::endl;
        
        zerrin.incrementGrade(); 
        std::cout << "after  incrementGrade: " << zerrin << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "err: " << e.what() << std::endl;
    }

    std::cout << "\n---  Grade Too High (0) ---" << std::endl;
    try {
        Bureaucrat ceo("ceo", 0); 
    }
    catch (std::exception & e) {
        std::cerr << "err: " << e.what() << std::endl;
    }

    std::cout << "\n--- Grade Too Low (151) ---" << std::endl;
    try {
        Bureaucrat intern1("intern1", 151); 
    }
    catch (std::exception & e) {
        std::cerr << "err: " << e.what() << std::endl;
    }

    return 0;
}