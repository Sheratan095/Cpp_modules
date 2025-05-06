/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 00:58:55 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:32:37 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate( void )
{
	// Generate a random number between 0 and 2
	int	rndNumber = rand() % 3;

	switch (rndNumber)
	{
		case 0:
			return (new A());
			break;
	
		case 1:
			return (new B());
			break;

		case 2:
			return (new C());
			break;
	}

	return (NULL);
}

// dynamic_cast, if used with pointers, will return a null pointer if the cast fails
// 	and will return a valid pointer if the cast is successful
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "\"A\"" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "\"B\"" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "\"C\"" << std::endl;
	else
		std::cout << "UNKNOWN" << std::endl;
}

// (void)a/b/c is used to avoid unused variable warnings
// dynamic_cast, if used with references, will throw an exception if the cast fails
// 	and will return a valid reference if the cast is successful
void	identify(Base& p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		std::cout << "\"A\"" << std::endl;
		(void)a;
		return ;
	}
	catch (std::exception &ex){}

	try
	{
		B	&b = dynamic_cast<B&>(p);
		std::cout << "\"B\"" << std::endl;
		(void)b;
		return ;
	}
	catch (std::exception &ex){}

	try
	{
		C	&c = dynamic_cast<C&>(p);
		std::cout << "\"C\"" << std::endl;
		(void)c;
		return ;
	}
	catch (std::exception &ex){}

	std::cout << "UNKNOWN" << std::endl;
}

int main()
{
	// Used to get a different random number each time the program runs
	std::srand(std::time(0));

	Base *prova1 = generate();
	Base *prova2 = generate();
	Base *prova3 = generate();

	identify(prova1);
	identify(prova2);
	identify(prova3);

	std::cout << std::endl << "";

	identify(*prova1);
	identify(*prova2);
	identify(*prova3);

	delete (prova1);
	delete (prova2);
	delete (prova3);
}
