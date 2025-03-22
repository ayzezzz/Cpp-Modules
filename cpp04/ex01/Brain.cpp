/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:01:38 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/22 16:01:39 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    std::cout << "Brain Copy Constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& copy) {
    if (this != &copy) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    }
    std::cout << "Brain Assignment Operator called" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain Destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return this->ideas[index];
    return "";
}
