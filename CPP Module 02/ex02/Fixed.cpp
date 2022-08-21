#include "Fixed.hpp"

Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value){
	this->_value = value << this->_bit;
}

Fixed::Fixed(const float value){
	this->_value = roundf(value * (1 << this->_bit));
}

Fixed::Fixed(const Fixed &other){
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	// std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		setRawBits(other.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
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

bool Fixed::operator>(const Fixed &f) const{
	return _value > f.getRawBits();
}

bool Fixed::operator<(const Fixed &f) const{
	return _value < f.getRawBits();
}

bool Fixed::operator>=(const Fixed &f) const{
	return _value >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed &f) const{
	return _value >= f.getRawBits();
}

bool Fixed::operator==(const Fixed &f) const{
	return _value == f.getRawBits();
}

bool Fixed::operator!=(const Fixed &f) const{
	return _value != f.getRawBits();
}

Fixed &Fixed::operator++() {
	_value++;
	return *this;
}

Fixed &Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed prev = *this;
	++(*this);
	return prev;
}

Fixed Fixed::operator--(int) {
	Fixed prev = *this;
	--(*this);
	return prev;
}

Fixed Fixed::operator+(const Fixed &f) const {
	Fixed ret;
	ret.setRawBits(this->_value + f.getRawBits());
	return ret;
}	

Fixed Fixed::operator-(const Fixed &f) const {
	Fixed ret;
	ret.setRawBits(this->_value - f.getRawBits());
	return ret;
}	

Fixed Fixed::operator*(const Fixed &f) const {
	Fixed ret;
	long tmp = (long)this->_value * (long)f._value;
	ret.setRawBits(tmp / (1 << this->_bit));
	return ret;
}	

Fixed Fixed::operator/(const Fixed &f) const {
	Fixed ret;
    if(f._value == 0)
        return Fixed(0);
	long tmp = ((long)this->_value << this->_bit) / (long)f._value;
    ret._value = tmp;
	return ret;
}	

Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b)
		return a;
	return b;
}
