/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:35:17 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/09 18:35:18 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() 
{
    std::cout << name << "knrya: created 🌚" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << ": destroyed 🌚" << std::endl;
}
void Zombie::setName(std::string name)
{
    this->name = name;
}
void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}