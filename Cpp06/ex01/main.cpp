#include <Serializer.hpp>
#include <iostream>
#include <ostream>

int main (void)
{
	Data *someData = new Data();
	someData->setStrValue("Hello World");

	std::cout << "Some Data:\t\t" << *someData << std::endl;


	uintptr_t serializedValue = Serializer::serialize(someData);
	std::cout << "Serialized value:\t" << serializedValue << " (a.k.a. addr " << std::hex << serializedValue << ")" << std::dec << std::endl;

	someData->setStrValue("Bella");

	Data *deserializedSomeData = Serializer::deserialize(serializedValue);
	std::cout << "Deserialized some Data:\t" << *deserializedSomeData << std::endl;

	delete someData;
}
