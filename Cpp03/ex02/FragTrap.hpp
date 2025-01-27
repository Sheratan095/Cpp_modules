/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:18:33 by maceccar          #+#    #+#             */
/*   Updated: 2025/01/27 16:45:54 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragTrap); //copy constructor
		~FragTrap();

		FragTrap	&operator=(const FragTrap &fragTrap); //copy assignment operator

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
