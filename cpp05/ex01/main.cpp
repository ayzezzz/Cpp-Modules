/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:13:55 by zayaz             #+#    #+#             */
/*   Updated: 2026/02/22 12:57:39 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("Alice", 50);
	Bureaucrat b("Bob", 150);
	
	Form f1("Form1", 75, 100);
	Form f2("Form2", 50, 60);

	std::cout << a;
	std::cout << b;

	std::cout << std::endl << "---------------------------------------" << std::endl;

	std::cout << f1;
	std::cout << f1.getName() << " sign grade is " << f1.getGradeToSign() << std::endl;
	std::cout << f2;
	std::cout << f2.getName() << " sign grade is " << f2.getGradeToSign() << std::endl;


	std::cout << std::endl << "---------------------------------------" << std::endl;

	a.signForm(f1);
	std::cout << f1;

	std::cout << std::endl << "---------------------------------------" << std::endl;

	b.signForm(f2);
	std::cout << f2;
	
	std::cout << std::endl << "---------------------------------------" << std::endl;

	a.signForm(f2);
	std::cout << f2;

	return 0;
}