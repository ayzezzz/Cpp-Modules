/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:00:19 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/22 16:00:20 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copied" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof 🐶" << std::endl;
}
