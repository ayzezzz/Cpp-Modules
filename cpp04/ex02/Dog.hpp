/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:45:10 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/22 16:45:11 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
    Brain* brain; 

public:
    Dog();
    Dog(const Dog& copy);
    Dog& operator=(const Dog& copy);
    ~Dog();

    void makeSound() const;
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif
