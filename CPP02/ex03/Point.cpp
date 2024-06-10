#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &cpy) : _x(cpy._x), _y(cpy._y) {
}

Point & Point::operator=(const Point &src) {
	(void)src;
	return (*this);
}
Point::~Point() {}
Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

const Fixed & Point::get_x(void) const {
	return (_x);
}
const Fixed & Point::get_y(void) const {
	return (_y);
}
