#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fp_value(0) {
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const Fixed &cpy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_fp_value = src.getRawBits();
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

