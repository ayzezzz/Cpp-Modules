/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:45:06 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/16 16:45:07 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
ScavTrap::ScavTrap() : ClapTrap("Default")
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << "  created" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
        std::cout << "ScavTrap Assignment operator called" << std::endl;
    }
    return *this;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << "  destroyed" << std::endl;
}
void ScavTrap::attack(const std::string &target)
{
    if (this->energyPoints <= 0 || this->hitPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " can't attack" << std::endl;

        return;
    }
    this->energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode" << std::endl;
}