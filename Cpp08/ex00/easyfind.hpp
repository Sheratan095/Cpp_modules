/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:41:08 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:43:26 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

// for std::find
#include <algorithm>
#include <iostream>

template<typename T>
int	easyfind(const T &container, int value)
{
	typename T::const_iterator	it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (std::out_of_range("Value not found"));

	// * access the element value by dereferencing the iterator
	return (*it);
}

#endif
