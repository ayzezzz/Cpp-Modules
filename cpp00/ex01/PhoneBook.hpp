/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:05:46 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/03 16:08:48 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>

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
