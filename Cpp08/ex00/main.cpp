/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:43:24 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:43:26 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	try
	{
		std::cout << easyfind(v, 1) << std::endl;
		std::cout << easyfind(v, 423424) << std::endl;
		std::cout << easyfind(v, 0) << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return (0);
}