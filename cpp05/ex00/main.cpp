/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:13:21 by zayaz             #+#    #+#             */
/*   Updated: 2026/02/22 12:35:35 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "---  Normal ---" << std::endl;
    try {
        Bureaucrat zerrin("Zerrin", 1);
        std::cout << zerrin << std::endl;
        
        zerrin.incrementGrade(); 
        std::cout << "after  incrementGrade: " << zerrin << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "err1: " << e.what() << std::endl;
    }

    try {
        Bureaucrat zerrin("Bureaucrat2", 0);
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
        std::cerr << "err2: " << e.what() << std::endl;
    }

    std::cout << "\n--- Grade Too Low (151) ---" << std::endl;
    try {
        Bureaucrat intern1("intern1", 151); 
    }
    catch (std::exception & e) {
        std::cerr << "err3: " << e.what() << std::endl;
    }

    return 0;
}
