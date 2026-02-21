#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
    *this = copy;
}

Intern& Intern::operator=(const Intern& src) {
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Error: Intern couldn't find the form name!";
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    AForm* (Intern::*formCreators[3])(const std::string&) = {
        &Intern::createPresidential, 
        &Intern::createRobotomy, 
        &Intern::createShrubbery
    };

    std::string forms[] = {
        "presidential pardon", 
        "robotomy request", 
        "shrubbery creation"
    };

    for (int i = 0; i < 3; i++) {
        if (forms[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    throw Intern::FormNotFoundException();
}