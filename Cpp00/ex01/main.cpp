
#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iomanip>
#include <sstream>
#include <cstdlib>

static std::string	readInput(std::string prompt);
static void			add(PhoneBook *phoneBook);
static void			search(PhoneBook phonebook);
static std::string	formatField(const std::string &field);

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	while (true)
	{
		input = readInput(">");
		if (input.compare("ADD") == 0)
			add(&phoneBook);
		else if (input.compare("SEARCH") == 0)
			search(phoneBook);
		else if (input.compare("EXIT") == 0)
			break;
		else
			std::cout << input << ": command not found\n" << std::endl;
	}
}

static std::string	readInput(std::string prompt)
{
	std::string	result;

	do
	{
		std::cout << prompt;
		std::getline(std::cin, result);
		if (std::cin.eof())
		{
			std::cerr << "Input error or EOF detected" << std::endl;
			std::exit(1);
		}
		std::cin.clear();
	}
	while (std::cin.eof() || result.empty());

	return (result);
}

static void	add(PhoneBook *phoneBook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickame;
	std::string	phoneNumber;
	std::string	darkestSecret;

	firstName = readInput("\tFirst Name: ");
	lastName = readInput("\tLast Name: ");
	nickame = readInput("\tNickname: ");
	phoneNumber = readInput("\tPhone number: ");
	darkestSecret = readInput("\tDarkest secret: ");

	phoneBook->addContact(Contact(firstName, lastName, nickame, phoneNumber, darkestSecret));
	std::cout << "\tContact Added\n" << std::endl;
}

static void	search(PhoneBook phonebook)
{
	int		i = 0;
	Contact	*current_contact = phonebook.getContactByIndex(i);

	if (current_contact == NULL)
	{
		std::cout << "\tThe phonebook is empty" << std::endl;
		return ;
	}

	//header row
	std::cout << std::setw(10) << std::right << "Index" << "|"
			<< std::setw(10) << std::right << "First Name" << "|"
			<< std::setw(10) << std::right << "Last Name" << "|"
			<< std::setw(10) << std::right << "Nickname" << std::endl;

	//print all the rows
	while (current_contact != NULL)
	{
		std::cout << std::setw(10) << std::right << i << "|"
				<< std::setw(10) << std::right << formatField(current_contact->getFirstName()) << "|"
				<< std::setw(10) << std::right << formatField(current_contact->getLastName()) << "|"
				<< std::setw(10) << std::right << formatField(current_contact->getNickname()) << std::endl;
	
		current_contact = phonebook.getContactByIndex(++i);
	}

	std::cout << std::endl;

	//atoi return 0 if the input is a string => return the first contact
	int	index_to_search = atoi(readInput("\tindex to display > ").c_str());
	current_contact = phonebook.getContactByIndex(index_to_search);
	if (current_contact)
	{
		std::cout << "\tIndex: " << index_to_search << std::endl;
		std::cout << "\tFirst name: " << current_contact->getFirstName() << std::endl;
		std::cout << "\tLast name: " << current_contact->getLastName() << std::endl;
		std::cout << "\tNickname: " << current_contact->getNickname() << std::endl;
		std::cout << "\tPhone number: " << current_contact->getPhoneNumber() << std::endl;
		std::cout << "\tDarkest secret:" << current_contact->getDarkestSecret() << std::endl;
	}
	else
		std::cout << "\tContact at index not found"<< std::endl;

	std::cout << std::endl;
}

static std::string formatField(const std::string &field)
{
	int width = 10;

	if (field.size() > (size_t)width)
	{
		return field.substr(0, width - 1) + ".";
	}
	return field;
}
