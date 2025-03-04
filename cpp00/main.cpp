/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:06:09 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/03 16:06:11 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        {
            if(phonebook.addContact() == 0)
                break;
        }
        else if (command == "SEARCH")
        {
            if(phonebook.searchContact() == 0)
                break;
        }
        else if (command == "EXIT")
        {
            std::cout << "Goodbye, baby 🍄" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command, baby 🦕 Try ADD, SEARCH, or EXIT\n";
    }

    return 0;
}

