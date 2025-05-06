/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:54:24 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:32:37 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// template define types that can be used in this function
template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T	min(T a, T b)
{
	return ((a < b) ? a : b);
}

template <typename T>
T	max(T a, T b)
{
	return ((a > b) ? a : b);
}

#endif
