/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:45:27 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/16 16:45:28 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap frag("fragisto");

    frag.attack("buumb");

    frag.highFivesGuys();

    FragTrap frag2 = frag;
    frag2.highFivesGuys();

    FragTrap frag3("ups");
    frag3 = frag;
    frag3.attack("last frag");

    return 0;
}
