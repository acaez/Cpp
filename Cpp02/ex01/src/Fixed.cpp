#include "../inc/Fixed.hpp"

Fixed::Fixed() : _value(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) 
{
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value) 
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &src) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_value = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const 
{
    return this->_value;
}

void Fixed::setRawBits(int const raw) 
{
    this->_value = raw;
}

float Fixed::toFloat(void) const 
{
    return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const 
{
    return this->_value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}