#include "../inc/Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value)
{
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value) 
{
    _value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &src) 
{
    *this = src;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        this->_value = copy.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &copy) const 
{
    return this->_value > copy.getRawBits();
}

bool Fixed::operator<(const Fixed &copy) const
{
    return this->_value < copy.getRawBits();
}

bool Fixed::operator>=(const Fixed &copy) const
{
    return this->_value >= copy.getRawBits();
}

bool Fixed::operator<=(const Fixed &copy) const
{
    return this->_value <= copy.getRawBits();
}

bool Fixed::operator==(const Fixed &copy) const
{
    return this->_value == copy.getRawBits();
}

bool Fixed::operator!=(const Fixed &copy) const
{
    return this->_value != copy.getRawBits();
}


Fixed Fixed::operator+(const Fixed &copy) const 
{
    Fixed result;
    result.setRawBits(this->_value + copy.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &copy) const 
{
    Fixed result;
    result.setRawBits(this->_value - copy.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &copy) const 
{
    Fixed result;
    long temp = (long)this->_value * (long)copy.getRawBits();
    result.setRawBits(temp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &copy) const 
{
    if (copy.getRawBits() == 0)
        throw std::runtime_error("Division by zero");
    Fixed result;
    long temp = ((long)this->_value << _fractionalBits) / copy.getRawBits();
    result.setRawBits(temp);
    return result;
}


Fixed &Fixed::operator++() 
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() 
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    --(*this);
    return temp;
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


Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}