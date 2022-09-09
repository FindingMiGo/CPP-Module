#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bit;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bit));
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		_value = other._value;
	return *this;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw){
	_value = raw;
}

int Fixed::toInt(void) const{
	int ret = this->_value / (1 << this->_bit);
	return ret;
}

float Fixed::toFloat(void) const{
	float ret = (float)this->_value / (1 << this->_bit);
	return ret;
}

std::ostream &operator<<(std::ostream &ost, const Fixed &f){
	ost << f.toFloat();
	return ost;
}
