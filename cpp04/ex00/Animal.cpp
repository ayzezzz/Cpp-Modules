/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:59:59 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/22 17:40:30 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& other) {
    *this = other;
    std::cout << "Animal copied" << std::endl;
}


Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        type = other.type;
    std::cout << "Animal assigned" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Some animal sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}