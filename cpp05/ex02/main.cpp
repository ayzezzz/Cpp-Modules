#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(NULL)); 
    try {
        Bureaucrat zerrin("Zerrin", 1);
        ShrubberyCreationForm f1("garden");
        RobotomyRequestForm f2("bed");
        PresidentialPardonForm f3("ntern");

        zerrin.signForm(f1);
        zerrin.executeForm(f1);

        zerrin.signForm(f2);
        zerrin.executeForm(f2);

        zerrin.signForm(f3);
        zerrin.executeForm(f3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
