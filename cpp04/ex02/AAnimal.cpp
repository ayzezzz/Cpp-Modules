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