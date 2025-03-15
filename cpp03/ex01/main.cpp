#include "ScavTrap.hpp"

int main() {
    ScavTrap scav1("Serena"); 
    ScavTrap scav2 = scav1; 
    ScavTrap scav3;           
    scav3 = scav1;          

    scav1.attack("zez");  
    scav2.guardGate();   

    return 0; 
}