#include "FragTrap.hpp"

int main() {
    FragTrap frag("fragisto");

    frag.attack("buumb");

    frag.highFivesGuys();

    FragTrap frag2 = frag;
    frag2.highFivesGuys();

    FragTrap frag3("ups");
    frag3 = frag;
    frag3.attack("last frag");

    return 0;
}
