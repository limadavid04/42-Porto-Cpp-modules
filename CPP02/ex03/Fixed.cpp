#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <climits>

Fixed::Fixed(void) : _fp_value(0) {}

Fixed::Fixed(const Fixed &cpy) {
	*this = cpy;
}

Fixed::Fixed(const int n) {
	_fp_value = n << _fp_frac_bits;
}

Fixed::Fixed(const float n) {
	_fp_value = roundf(n * (float)(1 << _fp_frac_bits));
}

Fixed::~Fixed() {}

Fixed & Fixed::operator=(const Fixed &src) {
	if (this != &src)
		_fp_value = src._fp_value;
	return (*this);
}
Fixed Fixed::operator+(const Fixed &src) const {
	Fixed tmp;
	tmp.setRawBits(this->_fp_value + src._fp_value);
	return (tmp);
}
Fixed Fixed::operator-(const Fixed &src) const {
	Fixed tmp;
	tmp.setRawBits(this->_fp_value - src._fp_value);
	return (tmp);
}
Fixed Fixed::operator*(const Fixed &src) const {
	return (Fixed(this->toFloat() * src.toFloat()));
}
Fixed Fixed::operator/(const Fixed &src) const {
	return (Fixed(this->toFloat() / src.toFloat()));
}
bool Fixed::operator<(const Fixed &src) const {
	return (_fp_value < src._fp_value);
}
bool Fixed::operator<=(const Fixed &src) const {
	return (_fp_value <= src._fp_value);
}
bool Fixed::operator>(const Fixed &src) const {
	return (_fp_value > src._fp_value);
}
bool Fixed::operator>=(const Fixed &src) const {
	return (_fp_value >= src._fp_value);
}
bool Fixed::operator==(const Fixed &src) const {
	return (_fp_value == src._fp_value);
}
bool Fixed::operator!=(const Fixed &src) const {
	return (_fp_value != src._fp_value);
}
Fixed & Fixed::operator++(void) {
	_fp_value++;
	return (*this);
}

Fixed & Fixed::operator--(void){
	_fp_value--;
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	_fp_value++;
	return (tmp);
}

Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	_fp_value--;
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
	return ((float)_fp_value / (float)(1 << _fp_frac_bits));
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
