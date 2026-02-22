/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:14:16 by zayaz             #+#    #+#             */
/*   Updated: 2026/02/22 13:17:57 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(NULL)); 
    try {
        Bureaucrat zerrin("Zerrin", 150);
        
        ShrubberyCreationForm f1("home");
        
        RobotomyRequestForm f2("robot");

        PresidentialPardonForm f3("pardon");

        zerrin.signForm(f1);
        zerrin.executeForm(f1);
        std::cout << "------------------" << std::endl;


        zerrin.signForm(f2);
        zerrin.executeForm(f2);
        std::cout << "------------------" << std::endl;

        zerrin.signForm(f3);
        zerrin.executeForm(f3);
        std::cout << "------------------" << std::endl;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

