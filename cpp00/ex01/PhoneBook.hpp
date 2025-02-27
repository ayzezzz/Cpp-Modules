#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
    Contact contacts[8];
    int index;
    int totalContacts;

public:
    PhoneBook();
    void addContact();
    void searchContact();
};
#endif
