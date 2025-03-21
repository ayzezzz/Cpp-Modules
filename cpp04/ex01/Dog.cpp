#include "Dog.hpp"

Dog::Dog(){
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    this->brain = new Brain(*copy.brain);
    this->type = copy.type;
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
    if (this != &copy) {
        this->type = copy.type; 
        delete this->brain; 
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Dog Assignment Operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof 🐶" << std::endl;
}
void Dog::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return this->brain->getIdea(index);
}
