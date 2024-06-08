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
		~Fixed();

		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const ;
		void setRawBits(int const raw);
	private:
		int _fp_value;
		static const int _fp_frac_bits;
};
	std::ostream & operator<<(std::ostream &out, const Fixed &fp);
#endif
