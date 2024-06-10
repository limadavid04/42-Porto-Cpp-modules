#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const Point &cpy);
		~Point();

		Point(const float x, const float y);
		const Fixed & get_x(void) const;
		const Fixed & get_y(void) const;
	private:
		Point & operator=(const Point &src);
		const Fixed _x;
		const Fixed _y;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif

