/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:04:37 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:32:37 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	// Test for constructor
	DiamondTrap diamond1("Diamond1");
	std::cout << "----- Created Diamond1 -----" << std::endl;

	// Test for Copy Constructor
	DiamondTrap diamond2(diamond1); // Invokes the copy constructor
	std::cout << "----- Created Diamond2 using Copy Constructor -----" << std::endl;

	// Test for Copy Assignment Operator
	DiamondTrap diamond3("Diamond3");
	std::cout << "----- Created Diamond3 -----" << std::endl;

	diamond3 = diamond1; // Invokes the copy assignment operator
	std::cout << "----- Assigned Diamond1 to Diamond3 using Copy Assignment Operator -----" << std::endl;

	// Verify object states
	std::cout << "\n[VERIFYING OBJECT STATES]\n";
	std::cout << "Diamond1 -> "; diamond1.whoAmI();
	std::cout << "Diamond2 -> "; diamond2.whoAmI();
	std::cout << "Diamond3 -> "; diamond3.whoAmI();

	return (0);
}
