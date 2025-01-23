/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:55:58 by maceccar          #+#    #+#             */
/*   Updated: 2025/01/21 18:55:58 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(Fixed()), y(Fixed())
{}

Point::Point(Fixed x, Fixed y) : x(Fixed(x)), y(Fixed(y))
{}

Point::Point(Point &p) : x(Fixed(p.x)), y(Fixed(p.y))
{}

Point &Point::operator=(const Point &p)
{
	(void)p;

	return (*this);
}

Point::~Point()
{}

const Fixed Point::getX(void) const
{
	return (this->x);
}

const Fixed Point::getY(void) const
{
	return (this->y);
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
	os << "(" << p.getX() << ";" << p.getY() << ")";

	return (os);
}
