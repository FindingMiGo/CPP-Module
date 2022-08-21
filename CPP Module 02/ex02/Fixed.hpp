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

		bool operator>(const Fixed &f) const;
		bool operator<(const Fixed &f) const;
		bool operator<=(const Fixed &f) const;
		bool operator>=(const Fixed &f) const;
		bool operator==(const Fixed &f) const;
		bool operator!=(const Fixed &f) const;
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed operator+(const Fixed &f) const;
		Fixed operator-(const Fixed &f) const;
		Fixed operator*(const Fixed &f) const;
		Fixed operator/(const Fixed &f) const;

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
	private:
		int	_value;
		static const int _bit = 8;
};

std::ostream &operator<<(std::ostream &ost, Fixed const &f);

#endif
