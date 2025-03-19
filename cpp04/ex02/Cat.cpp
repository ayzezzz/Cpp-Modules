#include "Cat.hpp"

Cat::Cat()
{
    this->brain = new Brain();
    this->type = "Cat";
    std::cout << "Cat Default Constructor called!" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
    this->brain = new Brain(*copy.brain);
    this->type = copy.type;
    std::cout << "Cat Copy Constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
        delete this->brain;
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Cat Assignment Operator called!" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat Destructor called!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}
