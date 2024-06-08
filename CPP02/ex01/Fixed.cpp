#include "Fixed.hpp"
#include <iostream>
#include <cmath>
Fixed::Fixed(void) : _fp_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed(const int n) : _fp_value(n) {
	std::cout << "const int constructor called" << std::endl;
}

Fixed::Fixed(const float n) {
	std::cout << "const float constructor called" << std::endl;
	_fp_value = roundf(n * (1 << _fp_frac_bits));
}


Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &src) {
	if (this != &src)
	std::cout << "Copy assignment operator called" << std::endl;
		_fp_value = src._fp_value;
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fp_value);
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fp_value = raw;

}
const int Fixed::_fp_frac_bits = 8;

