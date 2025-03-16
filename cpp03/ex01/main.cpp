/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:45:01 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/16 16:45:02 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    ScavTrap scav1("Serena"); 
    ScavTrap scav2 = scav1; 
    ScavTrap scav3;           
    scav3 = scav1;          

    scav1.attack("zez");  
    scav2.guardGate();   

    return 0; 
}