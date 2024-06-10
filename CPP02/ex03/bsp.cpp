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

// bool bsp(Point a, Point b, Point c, Point point) {
//     Fixed alpha = ((b.get_y() - c.get_y()) * (point.get_x() - c.get_x()) + (c.get_x() - b.get_x()) * (point.get_y() - c.get_y())) / ((b.get_y() - c.get_y()) * (a.get_x() - c.get_x()) + (c.get_x() - b.get_x()) * (a.get_y() - c.get_y()));
//     Fixed beta = ((c.get_y() - a.get_y()) * (point.get_x() - c.get_x()) + (a.get_x() - c.get_x()) * (point.get_y() - c.get_y())) / ((b.get_y() - c.get_y()) * (a.get_x() - c.get_x()) + (c.get_x() - b.get_x()) * (a.get_y() - c.get_y()));
//     Fixed gamma = Fixed(1.0f) - alpha - beta;

// 	std::cout << alpha <<std::endl;
// 	std::cout << gamma<<std::endl;
// 	std::cout << beta<<std::endl;

//     // The point is inside the triangle if all Barycentric coordinates are between 0 and 1
//     return alpha > 0 && beta > 0 && gamma > 0;
// }



// #include "Point.hpp"

// bool	bsp(const Point a, const Point b, const Point c, const Point point) {
// 	const Fixed	area = Fixed(0.5f) * (Fixed(-1) *b.get_y() * c.get_x() + a.get_y() * ( c.get_x()-b.get_x()) + a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * c.get_y());
// 	const Fixed	s = Fixed(1) / (Fixed(2) * area) * (a.get_y() * c.get_x() - a.get_x() * c.get_y() + (c.get_y() - a.get_y()) * point.get_x() + (a.get_x() - c.get_x()) * point.get_y());
// 	const Fixed	t = Fixed(1) / (Fixed(2) * area) * (a.get_x() * b.get_y() - a.get_y() * b.get_x() + (a.get_y() - b.get_y()) * point.get_x() + (b.get_x() - a.get_x()) * point.get_y());

// 	std::cout << "trig area: " << area << std::endl;
// 	std::cout << "s: " << s << std::endl;
// 	std::cout << "t " << t << std::endl;
// 	return s > Fixed(0) && t > Fixed(0) && (Fixed(1) - s - t) > Fixed(0);
// }
