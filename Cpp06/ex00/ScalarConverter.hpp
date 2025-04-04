/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:04:33 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
	public:
		static void	convert(const std::string &rawValue);

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);

		// Used to make the class abstract
		virtual	~ScalarConverter() = 0;

		ScalarConverter	&operator=(const ScalarConverter &rhs);
};

#endif
