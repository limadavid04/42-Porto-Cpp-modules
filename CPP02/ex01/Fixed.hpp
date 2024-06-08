#ifndef FIXED_HPP
#define FIXED_HPP

// • A constructor that takes a constant integer as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.
// • A constructor that takes a constant floating-point number as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.
// • A member function float toFloat( void ) const;
// that converts the fixed-point value to a floating-point value.
// • A member function int toInt( void ) const;
// that converts the fixed-point value to an integer value


class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed &cpy);
		Fixed(const int n);
		Fixed(const float n);
		Fixed & operator=(const Fixed &src);
		~Fixed();

		int getRawBits(void) const ;
		void setRawBits(int const raw);

	private:
		int _fp_value;
		static const int _fp_frac_bits;
};
#endif
