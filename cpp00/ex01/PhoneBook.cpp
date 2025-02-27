#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    index = 0;
    totalContacts = 0;
}
void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    newContact.setNickName(input);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);
    contacts[index] = newContact;
    index = (index + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
    std::cout << "yess baby contact added successfully" << std::endl;
}
void PhoneBook::searchContact()
{
    if (totalContacts == 0)
    {
        std::cout << "sorry baby phonebook is empty" << std::endl;
        return;
    }
    std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << " | " << i << " | "
        << contacts[i].getFirstName() << " | "
        << contacts[i].getLastName() << " | "
        << contacts[i].getNickName() << " | " << std::endl;
    }
    std::cout << " baby enter the index of the contact you want to view: ";
    std::string input;
    std::getline(std::cin, input);

   // int selectedIndex;
 
}