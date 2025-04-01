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
