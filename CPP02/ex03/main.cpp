#include "Point.hpp"
#include "Fixed.hpp"
#include <cassert>

int main() {
	// Define some points
	Point a(0.0f, 0.0f);
	Point b(1.0f, 0.0f);
	Point c(0.0f, 1.0f);

	// Test 1: Point inside the triangle

	Point p1(0.4, 0.4);
	assert(bsp(a, b, c, p1)==true);

	// Test 2: Point outside the triangle
	Point p2(1.5, 1.5);
	assert(bsp(a, b, c, p2) == false);

	// Test 3: Point on the triangle's edge
	Point p3(0.5, 0);
	assert(bsp(a, b, c, p3) == false);

	// Test 4: Point at the triangle's vertex
	Point p4(0, 0);
	assert(bsp(a, b, c, p4) == false);

	// std::cout << "All tests passed!" << std::endl;

	return 0;
}
