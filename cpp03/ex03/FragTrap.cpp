/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:45:55 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/16 16:45:56 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
    hitPoints = fragTrap.hitPoints;
    energyPoints = fragTrap.energyPoints;
    attackDamage = fragTrap.attackDamage;
    std::cout << "FragTrap " << name << " copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    if (this != &fragTrap)
    {
        name = fragTrap.name;
        hitPoints = fragTrap.hitPoints;
        energyPoints = fragTrap.energyPoints;
        attackDamage = fragTrap.attackDamage;
    }
    std::cout << "FragTrap " << name << " assigned" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a HIGH FIVE ✋" << std::endl;
}
