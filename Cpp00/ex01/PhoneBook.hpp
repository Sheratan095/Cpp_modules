#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACT 8

class PhoneBook
{
	private:
		Contact	contacts[MAX_CONTACT];
		int		currentIndex;
		int		contactsNumber;

		void updateIndex();
	
	public:
		PhoneBook();
		~PhoneBook();

		int		addContact(Contact newContact);
		Contact	*getContactByIndex(int index);

};

#endif