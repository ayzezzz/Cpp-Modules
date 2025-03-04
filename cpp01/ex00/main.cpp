#include "Zombie.hpp"

int main()
{
    Zombie *heapZombie = newZombie("heapZombiee 🌚");
    heapZombie->announce();
    delete heapZombie;

    randomChump("stackZombie 🌚");

    return 0;
}