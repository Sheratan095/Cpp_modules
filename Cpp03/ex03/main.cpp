/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:49:48 by maceccar          #+#    #+#             */
/*   Updated: 2025/01/27 16:49:48 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap pippo ("pippo");

	DiamondTrap pluto = pippo;

	pippo.attack("sAMU");
	pippo.whoAmI();
}
