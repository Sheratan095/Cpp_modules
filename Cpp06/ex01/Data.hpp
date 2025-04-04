/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:54:57 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Data
{
	private:
		std::string	strValue;
		int			changes;

	public:
		Data();
		Data(const Data &data);
		virtual	~Data();

		Data	&operator=(const Data &data);

		void		setStrValue(std::string str);
		std::string	getStrValue() const;
		int			getChanges() const;
};

std::ostream &operator<<(std::ostream &os, const Data &data);
