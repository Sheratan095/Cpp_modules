/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:44 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:32:37 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string	type;
		Brain*		brain;

	public:
		AAnimal();
		AAnimal(const AAnimal &animal);
		virtual ~AAnimal();

		AAnimal			&operator=(const AAnimal &rhs);

		std::string		getType() const;
		Brain*			getBrain() const;

		virtual void	makeSound() const = 0;
};

#endif
