/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:11:19 by maceccar          #+#    #+#             */
/*   Updated: 2025/01/21 18:55:58 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void		setName(const std::string& newName);
		std::string	getName( void ) const;

	void	announce( void );
};

Zombie	*zombieHorde(int N, std::string name);

#endif
