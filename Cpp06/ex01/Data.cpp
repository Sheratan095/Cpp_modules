/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:03:21 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Data.hpp>

Data::Data() : strValue("Default"), changes(0)
{
}

Data::Data(const Data &data) : strValue(data.strValue), changes(data.changes)
{
}

Data::~Data()
{
}

Data &Data::operator=(const Data &rhs)
{
	if (this == &rhs)
		return (*this);

	this->strValue = rhs.strValue;
	this->changes = rhs.changes;

	return (*this);
}

void	Data::setStrValue(std::string str)
{
	this->strValue = str;
	this->changes++;
}

std::string	Data::getStrValue() const
{
	return (this->strValue);
}


int	Data::getChanges() const
{
	return (this->changes);
}

std::ostream &operator<<(std::ostream &os, const Data &data)
{
	os << "Data: " << data.getStrValue() << ", changes: " << data.getChanges();

	return (os);
}
