#include "Harl.hpp"
#include <map>

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	// Define the map of levels to member function pointers
	std::map<std::string, void (Harl::*)()> levelMap;

	// {first (key), second(value)}
	levelMap["DEBUG"] = &Harl::debug;
	levelMap["INFO"] = &Harl::info;
	levelMap["WARNING"] = &Harl::warning;
	levelMap["ERROR"] = &Harl::error;

	//Iterator to pass through the map
	std::map<std::string, void (Harl::*)()>::iterator	it;

	// Search for the level in the map
	it = levelMap.find(level);

	//map.end() is is a special iterator that represents one past the last valid element in the map
	if (it != levelMap.end())
	{
		// Reach the end of the map => print all level
		for (; it != levelMap.end(); ++it)
			(this->*(it->second))(); // Call the corresponding function
	}
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}