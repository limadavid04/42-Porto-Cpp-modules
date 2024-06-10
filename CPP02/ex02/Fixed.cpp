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
Fixed Fixed::operator+(const Fixed &src) const {
	return (Fixed(this->_fp_value + src._fp_value));
}
Fixed Fixed::operator-(const Fixed &src) const {
	return (Fixed(this->_fp_value - src._fp_value));
}
Fixed Fixed::operator*(const Fixed &src) const {
	return (Fixed(this->toFloat() * src.toFloat()));
}
Fixed Fixed::operator/(const Fixed &src) const {
	return (Fixed(this->toFloat() / src.toFloat()));
}
bool Fixed::operator<(const Fixed &src) const {
	return (this->toFloat() < src.toFloat());
}
bool Fixed::operator<=(const Fixed &src) const {
	return (this->toFloat() <= src.toFloat());
}
bool Fixed::operator>(const Fixed &src) const {
	return (this->toFloat() > src.toFloat());
}
bool Fixed::operator>=(const Fixed &src) const {
	return (this->toFloat() >= src.toFloat());
}
bool Fixed::operator==(const Fixed &src) const {
	return (this->toFloat() == src.toFloat());
}
bool Fixed::operator!=(const Fixed &src) const {
	return (this->toFloat() != src.toFloat());
}
Fixed & Fixed::operator++(void) {

	float fl = this->toFloat();
	++fl;
	_fp_value = roundf(fl * (1 << _fp_frac_bits));
	return (*this);
}
Fixed & Fixed::operator--(void){
	float fl = this->toFloat();
	--fl;
	_fp_value = roundf(fl * (1 << _fp_frac_bits));
	return (*this);
}
Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	float fl = this->toFloat();
	fl++;
	_fp_value = roundf(fl * (1 << _fp_frac_bits));
	return (tmp);
}

Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	float fl = this->toFloat();
	fl--;
	_fp_value = roundf(fl * (1 << _fp_frac_bits));
	return (tmp);
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
Fixed & Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}
Fixed & Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}
 const Fixed & Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}
const Fixed & Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}
const int Fixed::_fp_frac_bits = 8;

std::ostream & operator<<(std::ostream &out, const Fixed &fp) {
	out << fp.toFloat();
	return (out);
}
