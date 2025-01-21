/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:54:26 by maceccar          #+#    #+#             */
/*   Updated: 2024/12/09 16:31:50 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
