/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:19 by maceccar          #+#    #+#             */
/*   Updated: 2024/12/09 16:31:50 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	int			n = 5;
	std::string	name = "zombie";

	Zombie *horde = zombieHorde(n, name);

	for (int i = 0; i < n; i++)
		horde[i].announce();

	delete[]horde;
}
