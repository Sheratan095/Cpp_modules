/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:44 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/07 13:24:44 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"
#include <unistd.h>
#include "WrongCat.hpp"

int main ( void )
{
	// AAnimal Animal;

	AAnimal *animals[6];

	for (int i = 0; i < 3; i++)
		animals[i] = new Dog();

	for (int i = 3; i < 6; i++)
	{
		animals[i] = new Cat();
		std::cout << animals[i]->getBrain()->getIdea(1) << std::endl;
		}

	for (int i = 0; i < 6; i++)
		delete animals[i];

	Dog dog1;
	dog1.getBrain()->setIdea(0, "I love running!");
	
	Dog dog2 = dog1;  // Deep copy

	// Change dog1's idea
	dog1.getBrain()->setIdea(0, "I love eating!");

	// Check if dog2's idea remains unchanged
	std::cout << "Dog1 Brain Idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 Brain Idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;


	return 0;
}
