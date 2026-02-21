#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(NULL));

    Intern  someRandomIntern;
    Bureaucrat boss("Zerrin", 1);
    AForm* rrf = NULL;

    std::cout << "successful Robotomy Request ---" << std::endl;
    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n invalid Form Name ---" << std::endl;
    try {
        rrf = someRandomIntern.makeForm("coffee request", "Intern");
        if (rrf) delete rrf;
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n presidential Pardon ---" << std::endl;
    try {
        rrf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}