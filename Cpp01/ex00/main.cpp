/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:22:44 by maceccar          #+#    #+#             */
/*   Updated: 2025/01/21 18:55:58 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie *zombie = newZombie("Zomviee");
	
	zombie->announce();

	randomChump("we");

	delete zombie;
}
