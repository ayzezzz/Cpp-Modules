/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:45:14 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/22 17:51:28 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "=== Abstract Class Test ===" << std::endl;

   // AAnimal *meta = new AAnimal();

    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();

    delete j;
    delete i;

    return 0;
}
