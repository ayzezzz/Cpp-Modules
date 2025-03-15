#include "ClapTrap.hpp"

int main() {
    ClapTrap player("zez");

    player.attack("ayaz");
    player.takeDamage(5);
    player.beRepaired(3);
    player.takeDamage(10);
    player.attack("ayaz");
    player.beRepaired(5);

    return 0;
}