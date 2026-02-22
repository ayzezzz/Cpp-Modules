/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:15:24 by zayaz             #+#    #+#             */
/*   Updated: 2026/02/22 16:20:37 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(std::time(NULL));

    Intern intern;
    Bureaucrat boss("Zerrin", 1);
    AForm* form = NULL;

    try {
        // Shrubbery
        form = intern.makeForm("shrubbery creation", "Home");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;

        // Robotomy
        form = intern.makeForm("robotomy request", "Bender");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;

        // Presidential
        form = intern.makeForm("presidential pardon", "Ford Prefect");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;

    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        if (form) delete form;
    }

    return 0;
}