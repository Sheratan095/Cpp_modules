/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:54:26 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:41 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->currentIndex = 0;
	this->contactsNumber = 0;
}

PhoneBook::~PhoneBook()
{}

void PhoneBook::updateIndex()
{
	if (this->currentIndex == MAX_CONTACT - 1)
		this->currentIndex = 0;
	else
		this->currentIndex++;
}

//Return the number of index of the contact
int	PhoneBook::addContact(Contact newContact)
{
	int	result;

	this->contacts[this->currentIndex] = newContact;
	result = this->currentIndex;

	if (this->contactsNumber  != MAX_CONTACT)
		this->contactsNumber++;

	updateIndex();
	return (result);
}

Contact *PhoneBook::getContactByIndex(int index)
{
	if (this->contactsNumber == 0 || index >= contactsNumber || index < 0)
		return (NULL);
	
	return (&contacts[index]);
}
