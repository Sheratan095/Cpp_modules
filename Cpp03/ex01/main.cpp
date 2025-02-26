/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:57:33 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:41 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap pippo("Pippo");
	std::cout << std::endl;


	ScavTrap originalMario("OrigMario");
	ScavTrap mario = originalMario;
	std::cout << std::endl;


	pippo.attack("Mario");
	std::cout << std::endl;
	pippo.takeDamage(400);
	std::cout << std::endl;
	pippo.takeDamage(666);
	std::cout << std::endl;
	pippo.beRepaired(4);
	pippo.beRepaired(1);
	pippo.beRepaired(0);
	pippo.beRepaired(0);
	std::cout << std::endl;
	pippo.guardGate();
	std::cout << std::endl;
	pippo.beRepaired(0);
	pippo.beRepaired(0);
	pippo.beRepaired(1);
	pippo.beRepaired(0);
	pippo.beRepaired(0);
	std::cout << std::endl;
	pippo.guardGate();
	std::cout << std::endl;
	pippo.takeDamage(666);

	std::cout << std::endl;
	pippo.attack("Mario");
	std::cout << std::endl;
	pippo.beRepaired(101);
}
