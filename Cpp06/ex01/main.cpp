/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:03:59 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serializer.hpp>
#include <iostream>
#include <ostream>
#include <stdint.h>

//uintptr_t is an unsigned integer type defined in the <stdint.h>.
// It is designed to be large enough to hold any pointer value. 
int main (void)
{
	std::cout << std::endl << "TRY WITH NULL POINTER" << std::endl;

	Data* ptr1 = NULL;
	uintptr_t nullSerializedValue = Serializer::serialize(ptr1);
	std::cout << "Serialized value of nullptr: " << nullSerializedValue << std::endl;
	Data *nullDeserializedSomeData = Serializer::deserialize(nullSerializedValue);
	std::cout << "Deserialized value of nullptr: " << nullDeserializedSomeData << std::endl;


	std::cout << std::endl << "TRY WITH VALID POINTER" << std::endl;

	Data *someData = new Data();
	someData->setStrValue("Hello World");
	std::cout << *someData << std::endl;
	uintptr_t serializedValue = Serializer::serialize(someData);
	std::cout << "Serialized value:\t" << serializedValue << " (a.k.a. addr " << std::hex << serializedValue << ")" << std::dec << std::endl;
	Data *deserializedSomeData = Serializer::deserialize(serializedValue);
	std::cout << "Deserialized " << *deserializedSomeData << std::endl;

	delete (someData);
}
