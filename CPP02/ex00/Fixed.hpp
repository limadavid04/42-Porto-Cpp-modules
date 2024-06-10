#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed &cpy);
		Fixed & operator=(const Fixed &src);

		~Fixed();

		int getRawBits(void) const ;
		void setRawBits(int const raw);

	private:
		int _fp_value;
		static const int _fp_frac_bits;
};
#endif
