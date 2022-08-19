#include "Fixed.hpp"
#include <iomanip>
#include <bitset>


int main( void ) {
	Fixed const a(1234.1234f);
	Fixed const b(10);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << "a = " << a.toInt() << " (integer)" << std::endl;
	std::cout << "b = " << b.toInt() << " (integer)" << std::endl;
	return 0;
}
