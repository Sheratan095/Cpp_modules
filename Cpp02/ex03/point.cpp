#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		Point(const Point& other);
		Point(Fixed const x, Fixed const y);
		~Point();
		Point& operator=(const Point& other);
		Fixed getX() const;
		Fixed getY() const;
		void setX(Fixed const x);
		void setY(Fixed const y);

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif