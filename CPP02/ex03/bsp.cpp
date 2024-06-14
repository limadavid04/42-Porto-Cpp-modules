#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed w1;
	Fixed w2;
	std::cout << "Point a: (" << a.get_x() << ", " << a.get_y() << ")" << std::endl;
	std::cout << "Point b: (" << b.get_x() << ", " << b.get_y() << ")" << std::endl;
	std::cout << "Point c: (" << c.get_x() << ", " << c.get_y() << ")" << std::endl;
	std::cout << "Point point: (" << point.get_x() << ", " << point.get_y() << ")" << std::endl;
	w1 = (a.get_x() * (c.get_y() - a.get_y()) +
	(point.get_y() - a.get_y()) * (c.get_x() - a.get_x()) -
	point.get_x() * (c.get_y()- a.get_y())) / ((b.get_y() - a.get_y()) *
	(c.get_x() - a.get_x()) - (b.get_x() - a.get_x()) * (c.get_y() - a.get_y()));
	std::cout << "w1: " << w1 << std::endl;
	w2 = (point.get_y() - a.get_y() - w1 *(b.get_y() - a.get_y())) / (c.get_y() - a.get_y());

	std::cout << "w2: " << w2 << std::endl;
	if (w1 > 0 && w2 > 0 && (w1 + w2) < 1)
		return (true);
	return (false);
}

