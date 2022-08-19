#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits( int const raw );
		int toInt(void) const;
    	float toFloat(void) const;
	private:
		int	_value;
		static const int _bit = 8;
};

std::ostream &operator<<(std::ostream &ost, Fixed const &f);

#endif
