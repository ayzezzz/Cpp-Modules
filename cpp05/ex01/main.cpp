#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat zerrin("Zerrin", 25);
        Form holidayForm("holiday Form", 30, 50); 

        std::cout << zerrin << std::endl;
        std::cout << holidayForm << std::endl;

        zerrin.signForm(holidayForm);
        std::cout << "statü: " << holidayForm << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "err: \n" << e.what() << std::endl;
    }

    try {
        Bureaucrat intern("intern", 140);
        Form cokGizliForm("hidden form", 5, 10);

        std::cout << intern << std::endl;
        std::cout << cokGizliForm << std::endl;

        intern.signForm(cokGizliForm);
    }
    catch (std::exception &e) {
        std::cerr << "err: \n" << e.what() << std::endl;
    }

    try {
        Form gecersiz("err Form", 0, 151);
    }
    catch (std::exception &e) {
        std::cerr << "err Form : \n" << e.what() << std::endl;
    }

    return 0;
}