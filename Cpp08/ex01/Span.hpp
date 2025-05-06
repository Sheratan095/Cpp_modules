/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:31:45 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 15:31:46 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;

	public:
		Span(unsigned int n);
		Span(const Span &other);
		~Span();

		Span &operator=(const Span &rhs);
}

#endif
