/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:01:47 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/02 01:01:47 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer::~Serializer()
{}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	if (this == &rhs)
		return (*this);

	return (*this);
}

//----------------------------------------------------------------------------------------------

// The reinterpret_cast operator allows you to convert between types by reinterpreting the underlying bit pattern.
// Convert between unrelated types, such as pointers and integers 
// Convert between pointer types, such as pointers to objects, functions, or members 
// Convert between integral types and pointers 
// Convert a null pointer value to the null pointer value of the destination type 
uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	raw = reinterpret_cast<uintptr_t>(ptr);

	return (raw);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data*	dataPtr = reinterpret_cast<Data*>(raw);

	return (dataPtr);
}
