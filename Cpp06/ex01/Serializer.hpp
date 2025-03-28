#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <ostream>
#include <stdint.h>

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

		Serializer();
		Serializer(const Serializer &other);
		virtual	~Serializer() = 0;

		Serializer	&operator=(const Serializer &rhs);
};

#endif