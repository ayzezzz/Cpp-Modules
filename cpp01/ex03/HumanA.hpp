/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:34:21 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/09 18:36:32 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA 
{
    private:
        std::string name;
        Weapon& weapon; 

    public:
        HumanA(std::string name, Weapon& weapon);
        void attack() const;
};

#endif
