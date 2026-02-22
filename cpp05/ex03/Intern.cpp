/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:15:11 by zayaz             #+#    #+#             */
/*   Updated: 2026/02/22 16:05:38 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other){
    *this = other;
}

Intern& Intern::operator=(const Intern &other){
    if(this != &other)
        return *this;
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