/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:44:41 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/22 16:44:42 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal") {
    std::cout << "AAnimal created" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destroyed" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    *this = other;
    std::cout << "Animal copied" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal assigned" << std::endl;
    return *this;
}

std::string AAnimal::getType() const {
    return type;
}