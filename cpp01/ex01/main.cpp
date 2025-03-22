/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:35:05 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/10 14:28:53 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 3;
    Zombie* horde = zombieHorde(N, "knrya 🤡");
    for(int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete [] horde;

    return 0;
}
