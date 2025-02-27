#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT), baby: ";
        std::getline(std::cin, command);

        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
        {
            std::cout << "Goodbye, baby\n";
            break;
        }
        else
            std::cout << "Invalid command, baby Try ADD, SEARCH, or EXIT\n";
    }

    return 0;
}

