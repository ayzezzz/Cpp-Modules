#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "=== Abstract Class Test ===" << std::endl;

    //AAnimal *meta = new AAnimal();

    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();

    delete j;
    delete i;

    return 0;
}
