/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:54:26 by maceccar          #+#    #+#             */
/*   Updated: 2025/03/10 15:26:12 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// This is the default constructor of the Contact class.
// It doesn't take any parameters and doesn't perform any actions (empty body {}).
// If no arguments are passed when creating an instance of Contact,
// 		this constructor will be called
Contact::Contact()
{}

// Constructor (initializer list)
// Initializer list is a special syntax used in the constructor
// 	to initialize class members directly when the object is created.
// This list appears after the constructor’s parameter list and before the constructor’s body.
Contact::Contact(
	std::string firstName, std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret)
	: firstName(firstName), lastName(lastName), nickname(nickname), 
		phoneNumber(phoneNumber), darkestSecret(darkestSecret)
{}

// Destructor
Contact::~Contact()
{
}

//---------------------GETTERS---------------------

std::string Contact::getFirstName()
{
	return this->firstName;
}

std::string Contact::getLastName()
{
	return this->lastName;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

std::string Contact::getPhoneNumber()
{
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return this->darkestSecret;
}
