#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
private:
    Contact contacts[8];
    int index;
    int totalContacts;

public:
    PhoneBook();
    int addContact();
    int searchContact();
};
#endif
