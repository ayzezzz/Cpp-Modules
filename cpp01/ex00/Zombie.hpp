/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:34:23 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/09 18:34:56 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie(std::string name);
        ~Zombie();

        void announce();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
