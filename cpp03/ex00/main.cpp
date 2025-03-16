/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:44:50 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/16 16:44:51 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap player("zez");

    player.attack("ayaz");
    player.takeDamage(5);
    player.beRepaired(3);
    player.takeDamage(10);
    player.attack("ayaz");
    player.beRepaired(5);

    return 0;
}