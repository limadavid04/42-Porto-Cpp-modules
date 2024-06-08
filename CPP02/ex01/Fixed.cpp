#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <climits>

Fixed::Fixed(void) : _fp_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_fp_value = n << _fp_frac_bits;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	_fp_value = roundf(n * (1 << _fp_frac_bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &src) {
	if (this != &src)
		_fp_value = src._fp_value;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (_fp_value);
}

void Fixed::setRawBits(int const raw)
{
	_fp_value = raw;
}

float Fixed::toFloat(void) const {
	return ((float)_fp_value / (1 << _fp_frac_bits));
}

int	Fixed::toInt(void) const {
	return (_fp_value >> _fp_frac_bits);
}

const int Fixed::_fp_frac_bits = 8;

std::ostream & operator<<(std::ostream &out, const Fixed &fp) {
	out << fp.toFloat();
	return (out);
}
