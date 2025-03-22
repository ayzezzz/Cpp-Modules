/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:00:07 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/22 16:00:08 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copied" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow 🐱 " << std::endl;
}
