#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT), baby 🍄: ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            return 0;
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
        {
            std::cout << "Goodbye, baby 🍄" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command, baby 🦧 Try ADD, SEARCH, or EXIT\n";
    }

    return 0;
}

