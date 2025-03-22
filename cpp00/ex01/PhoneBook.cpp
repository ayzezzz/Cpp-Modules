/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:06:00 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/03 16:06:03 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    index = 0;
    totalContacts = 0;
}

bool isDigitOnly(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

int PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    while (true)
    {
        std::cout << "Enter First Name:";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return 0;
        if (!input.empty())
            break;
        std::cout << "Empty, sorry baby 🦕" << std::endl;
    }
    newContact.setFirstName(input);

    while (true)
    {
        std::cout << "Enter Last Name:";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return 0;
        if (!input.empty())
            break;
        std::cout << "Empty, sorry baby 🦕" << std::endl;
    }
    newContact.setLastName(input);

    while (true)
    {
        std::cout << "Enter Nickname:";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return 0;
        if (!input.empty())
            break;
        std::cout << "Empty, sorry baby 🦕" << std::endl;
    }
    newContact.setNickName(input);

    while (true)
    {
        std::cout << "Enter Phone Number:";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return 0;
        if (isDigitOnly(input))
            break;
        std::cout << "Only numbers allowed, baby 🦕" << std::endl;
    }
    newContact.setPhoneNumber(input);

    while (true)
    {
        std::cout << "Enter Darkest Secret:";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return 0;
        if (!input.empty())
            break;
        std::cout << "Empty, sorry baby 🦕" << std::endl;
    }
    newContact.setDarkestSecret(input);

    contacts[index] = newContact;
    index = (index + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
    std::cout << "Contact added, baby 🍄" << std::endl;
    return 1;
}

std::string formatWidth(std::string text)
{
    return (text.length() > 10) ? text.substr(0, 9) + "." : text;
}

int PhoneBook::searchContact()
{
    if (totalContacts == 0)
    {
        std::cout << "Phonebook is empty, baby 🦕" << std::endl;
        return 1;
    }
    std::cout << "🍄=======================================🍄" << std::endl;
    std::cout << "  Index   |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << "|" << std::setw(10) << i << "|"
                  << std::setw(10) << formatWidth(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatWidth(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatWidth(contacts[i].getNickName()) << "|" << std::endl;
    }

    std::string input;
    int selectedIndex = -1;

    while (true)
    {
        std::cout << "Enter index (0-" << totalContacts - 1 << "), baby 🍄: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return 0;

        if (!isDigitOnly(input) ||input.empty())
        {
            std::cout << "Invalid input, baby. Enter only numbers 🦕" << std::endl;
            continue;
        }

        selectedIndex = atoi(input.c_str()); 

        if (selectedIndex < 0 || selectedIndex >= totalContacts)
        {
            std::cout << "Invalid index, baby 🦕 Choose a number between 0 and " << totalContacts - 1 << std::endl;
            continue;
        }
        break;
    }

    std::cout << "First Name: " << contacts[selectedIndex].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[selectedIndex].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[selectedIndex].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[selectedIndex].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[selectedIndex].getDarkestSecret() << std::endl;

    return 1;
}