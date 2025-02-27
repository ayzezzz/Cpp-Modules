#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    index = 0;
    totalContacts = 0;
}
bool isAlphaOnly(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isalpha(str[i]))
            return false;
    }
    return !str.empty();
}

bool isDigitOnly(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return !str.empty();
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    while (true)
    {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
        if (isAlphaOnly(input))
            break;
        std::cout << "Only letters allowed.\n";
    }
    newContact.setFirstName(input);
    while (true)
    {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
        if (isAlphaOnly(input))
            break;
        std::cout << "Only letters allowed.\n";
    }
    newContact.setLastName(input);
    while (true)
    {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
        if (isAlphaOnly(input))
            break;
        std::cout << "Only letters allowed.\n";
    }
    newContact.setNickName(input);

    while (true)
    {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
        if (isDigitOnly(input))
            break;
        std::cout << "Only numbers allowed.\n";
    }
    newContact.setPhoneNumber(input);

    while (true)
    {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
        if (!input.empty())
            break;
        std::cout << "This field can't be empty.\n";
    }
    newContact.setDarkestSecret(input);

    contacts[index] = newContact;
    index = (index + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
    std::cout << "Contact added baby" << std::endl;
}

std::string formatWidth(std::string text)
{
    if (text.length() > 10)
        return text.substr(0, 9) + ".";
    return text;
}

void PhoneBook::searchContact()
{
    if (totalContacts == 0)
    {
        std::cout << "sorry baby phonebook is empty" << std::endl;
        return;
    }
    std::cout << "| Index | First Name | Last Name  | Nickname  |\n";
    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << "| " << std::setw(10) << i << " | "
                  << std::setw(10) << formatWidth(contacts[i].getFirstName()) << " | "
                  << std::setw(10) << formatWidth(contacts[i].getLastName()) << " | "
                  << std::setw(10) << formatWidth(contacts[i].getNickName()) << " |" << std::endl;
    }
    std::string input;
    int selectedIndex;
    while (true)
    {
        std::cout << "Enter index baby: ";
        std::getline(std::cin, input);
        
    }
}