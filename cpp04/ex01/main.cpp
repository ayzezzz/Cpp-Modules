#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "=== Basic Tests ===" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "=== Array Test ===" << std::endl;

    Animal* animals[4];

    for (int i = 0; i < 2; i++)
        animals[i] = new Dog(); 

    for (int i = 2; i < 4; i++)
        animals[i] = new Cat(); 

    for (int i = 0; i < 4; i++)
        delete animals[i];
    std::cout << "=== Deep Copy Test ===" << std::endl;

    Dog originalDog;
    originalDog.setIdea(0, "I want to eat a bone");
    originalDog.setIdea(1, "I want to sleep!");

    Dog copiedDog = originalDog;

    std::cout << "Original Dog Idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0: " << copiedDog.getIdea(0) << std::endl;

    originalDog.setIdea(0, "New Idea");

    std::cout << "After modification - Original Dog Idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "After modification - Copied Dog Idea 0: " << copiedDog.getIdea(0) << std::endl;

    std::cout << "=== Destructor Call Order Test ===" << std::endl;

    Dog* heapDog = new Dog();
    delete heapDog; 

    return 0;
}
