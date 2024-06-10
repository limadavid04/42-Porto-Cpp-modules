#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed &cpy);
		Fixed(const int n);
		Fixed(const float n);
		Fixed & operator=(const Fixed &src);
		Fixed operator+(const Fixed &src) const;
		Fixed operator-(const Fixed &src) const;
		Fixed operator*(const Fixed &src) const;
		Fixed operator/(const Fixed &src) const;
		bool operator<(const Fixed &src) const;
		bool operator<=(const Fixed &src) const;
		bool operator>(const Fixed &src) const;
		bool operator>=(const Fixed &src) const;
		bool operator==(const Fixed &src) const;
		bool operator!=(const Fixed &src) const;
		Fixed & operator++(void); //prefix increment
		Fixed & operator--(void); //prefix decrement
		Fixed operator++(int); //postfix increment
		Fixed operator--(int); //postfix decrement
		~Fixed();
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const ;
		void setRawBits(int const raw);
		static Fixed & min(Fixed &a, Fixed &b);
		static Fixed & max(Fixed &a, Fixed &b);
		static const Fixed & min(const Fixed &a, const Fixed &b);
		static const Fixed & max(const Fixed &a, const Fixed &b);
	private:
		int _fp_value;
		static const int _fp_frac_bits;
};
	std::ostream & operator<<(std::ostream &out, const Fixed &fp);
#endif
