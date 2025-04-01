/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 04:47:48 by maceccar          #+#    #+#             */
/*   Updated: 2025/03/10 15:26:12 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

static float	calculateArea(const Point &p1, const Point &p2, const Point &p3);

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float triangleArea = calculateArea(a, b, c);

	float pab = calculateArea(point, a, b);
	float pac = calculateArea(point, a, c);
	float pbc = calculateArea(point, b, c);

	// Point on the edge
	if (pab == 0 || pac == 0 || pbc == 0)
		return (false);

	return ((pab + pac + pbc) == triangleArea);
}

static float	calculateArea(const Point &p1, const Point &p2, const Point &p3)
{
	float area = Fixed(((p1.getX() * (p2.getY() - p3.getY())) +
						(p2.getX() * (p3.getY() - p1.getY())) +
						(p3.getX() * (p1.getY() - p2.getY()))) /
					   Fixed(2)
	).toFloat();

	// absolute value of the area
	return (area < 0.0f ? -area : area);
}
