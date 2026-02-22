/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:14:43 by zayaz             #+#    #+#             */
/*   Updated: 2026/02/22 12:14:44 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    this->checkRequirements(executor);
    std::ofstream file((this->target + "_shrubbery").c_str());
    if (!file)
    {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }
    if (file.is_open())
    {
        file << "      _  _  _" << std::endl;
        file << "    (        )" << std::endl;
        file << "  (   o    o   )" << std::endl;
        file << " (      __      )" << std::endl;
        file << "  (____/  \\____)" << std::endl;
        file << "       |  |" << std::endl;
        file << "       |  |" << std::endl;
        file << "      /____\\" << std::endl;
        file << std::endl;
        file.close();
    }
}