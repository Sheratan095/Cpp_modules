#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point(void);
		Point(const Fixed x, const Fixed y);
		Point(Point &p);
		~Point();

		Point &operator=(const Point &p);

		const Fixed getX(void) const;
		const Fixed getY(void) const;
};

std::ostream &operator<<(std::ostream &os, const Point &p);

#endif //POINT_HPP