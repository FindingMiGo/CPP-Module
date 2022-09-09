#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "=====" << std::endl;
	{
		Fixed a(0.5f);
		Fixed b(1);
		Fixed c(a);

		std::cout << "0.5 > 1  \t: " << (a > b) << std::endl;
		std::cout << "0.5 > 0.5\t: " << (a > c) << std::endl;
		std::cout << "0.5 < 1  \t: " << (a < b) << std::endl;
		std::cout << "0.5 < 0.5\t: " << (a < c) << std::endl;
		std::cout << "0.5 <= 1\t: " << (a <= b) << std::endl;
		std::cout << "0.5 <= 0.5\t: " << (a <= a) << std::endl;
		std::cout << "0.5 >= 1\t: " << (a >= b) << std::endl;
		std::cout << "0.5 >= 0.5\t: " << (a >= c) << std::endl;
		std::cout << "0.5 == 0.5\t: " << (a == c) << std::endl;
		std::cout << "0.5 == 1\t: " << (a == b) << std::endl;
		std::cout << "0.5 != 1\t: " << (a != b) << std::endl;
		std::cout << "0.5 != 0.5\t: " << (a != c) << std::endl;
		std::cout << "0.5 + 0.5\t: " << (a + c) << std::endl;
		std::cout << "1 - 0.5 \t: " << (b - a) << std::endl;
		std::cout << "1 / 0.5 \t: " << (b / a) << std::endl;
		std::cout << "0.5 * 0.5 \t: " << (a * c) << std::endl;
		std::cout << "min(1, 0.5) \t: " << Fixed::min(b, a) << std::endl;
		std::cout << "max(1, 0.5) \t: " << Fixed::max(b, a) << std::endl;
	}
	return 0;
}
