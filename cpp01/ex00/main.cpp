/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:32:41 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/09 18:32:42 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *heapZombie = newZombie("heapZombiee 🌚");
    heapZombie->announce();
    delete heapZombie;

    randomChump("stackZombie 🌚");

    return 0;
}