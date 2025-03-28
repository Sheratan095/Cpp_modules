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

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	raw = reinterpret_cast<uintptr_t>(ptr);

	return (raw);
}

static Data*	deserialize(uintptr_t raw)
{
	Data*	dataPtr = reinterpret_cast<Data*>(raw);

	return (dataPtr);
}
