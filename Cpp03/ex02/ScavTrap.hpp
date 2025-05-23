/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:18:33 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	guardGateStatus;

	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavTrap); //copy constructor
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &scavTrap); //copy assignment operator

		void	attack(const std::string& target);
		void	guardGate();
};

#endif
