/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:00:46 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/22 16:00:47 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copied" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat assigned" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat makes Meeooww.. 🐙" << std::endl;
}
