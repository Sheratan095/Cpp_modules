/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:44 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:42 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat &cat);
		~Cat();

		Cat		&operator=(const Cat &rhs);

		void	makeSound() const;
};

#endif
