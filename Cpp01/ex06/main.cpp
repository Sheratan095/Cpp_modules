/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:20 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string.h>

int main (int argc, char *argv[])
{
	Harl		harl;
	std::string	input;


	if (argc != 2 || strlen(argv[1]) == 0)
	{
		std::cout << "Error invalid input" << std::endl;
		return (1);
	}

	input = argv[1];
	harl.complain(input);
}
