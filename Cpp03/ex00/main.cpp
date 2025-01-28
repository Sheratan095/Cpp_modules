/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:46:52 by maceccar          #+#    #+#             */
/*   Updated: 2025/01/27 16:55:12 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

void	testCreation();
void	testCopyConstructor();
void	testCopyAssignment();
void	testAttack();
void	testTakeDamage();
void	testBeRepaired();
void	testSelfAssignment();
void	testChainedAssignment();

int main()
{
	std::cout << "\n--- Test 1: Object Creation ---\n";
	testCreation();

	std::cout << "\n--- Test 2: Copy Constructor ---\n";
	testCopyConstructor();

	std::cout << "\n--- Test 3: Copy Assignment ---\n";
	testCopyAssignment();

	std::cout << "\n--- Test 4: Attack ---\n";
	testAttack();

	std::cout << "\n--- Test 5: Take Damage ---\n";
	testTakeDamage();

	std::cout << "\n--- Test 6: Be Repaired ---\n";
	testBeRepaired();

	std::cout << "\n--- Test 7: Self-Assignment ---\n";
	testSelfAssignment();

	std::cout << "\n--- Test 8: Chained Assignment ---\n";
	testChainedAssignment();

	return (0);
}

// Test 1: Object Creation
void	testCreation()
{
	ClapTrap obj1("Robot1");
	obj1.attack("Enemy1");
	obj1.takeDamage(5);
	obj1.beRepaired(3);
}

// Test 2: Copy Constructor
void	testCopyConstructor()
{
	ClapTrap obj1("Robot1");
	ClapTrap obj2(obj1);  // Calls copy constructor
	obj2.attack("Enemy2");
	obj2.takeDamage(3);
	obj2.beRepaired(2);
}

// Test 3: Copy Assignment
void	testCopyAssignment()
{
	ClapTrap obj1("Robot1");
	ClapTrap obj2("Robot2");
	obj2 = obj1;  // Calls copy assignment operator
	obj2.attack("Enemy3");
	obj2.takeDamage(2);
	obj2.beRepaired(1);
}

// Test 4: Attack
void	testAttack()
{
	ClapTrap obj1("Robot1");
	obj1.attack("Enemy1");
	obj1.attack("Enemy2");
}

// Test 5: Take Damage
void	testTakeDamage()
{
	ClapTrap obj1("Robot1");
	obj1.takeDamage(5);
	obj1.takeDamage(6);
}

// Test 6: Be Repaired
void	testBeRepaired()
{
	ClapTrap obj1("Robot1");
	obj1.takeDamage(5);
	obj1.takeDamage(5);
	obj1.beRepaired(3);  // Try repairing with some health restored
	obj1.beRepaired(10); // Try repairing more than the max health (which is 10)
	obj1.beRepaired(10); // Try repairing more than the max health (which is 10)
	obj1.beRepaired(10); // Try repairing more than the max health (which is 10)
	obj1.beRepaired(10); // Try repairing more than the max health (which is 10)
	obj1.beRepaired(10); // Try repairing more than the max health (which is 10)
	obj1.beRepaired(10); // Try repairing more than the max health (which is 10)
	obj1.beRepaired(10); // Try repairing more than the max health (which is 10)
	obj1.beRepaired(10); // Try repairing more than the max health (which is 10)
	obj1.beRepaired(10); // Try repairing more than the max health (which is 10)
	obj1.beRepaired(10); // Try repairing more than the max health (which is 10)
}

// Test 7: Self-Assignment
void	testSelfAssignment()
{
	ClapTrap obj1("Robot1");
	obj1 = obj1;  // Self-assignment test
	obj1.attack("Enemy4");
	obj1.takeDamage(1);
	obj1.beRepaired(4);
}

// Test 8: Chained Assignment
void	testChainedAssignment()
{
	ClapTrap obj1("Robot1");
	ClapTrap obj2("Robot2");
	ClapTrap obj3("Robot3");

	obj3 = obj2 = obj1;  // Chained assignment
	obj1.attack("Enemy5");
	obj2.takeDamage(5);
	obj3.beRepaired(2);
}
