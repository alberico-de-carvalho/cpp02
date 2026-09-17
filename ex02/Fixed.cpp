#include "Fixed.hpp"

Fixed::Fixed():rawBits(0) {}

Fixed::Fixed(Fixed const &other)
{
    *this = other;
}

Fixed &Fixed::operator=(Fixed const &other)
{
    if (this != &other)
        this->rawBits = other.rawBits;
    return(*this);
}

Fixed::Fixed(int const number)
{
    this->rawBits = number << fractionalBits;
}

Fixed::Fixed(float const number)
{
    this->rawBits = static_cast<int>(roundf(number * (1 << fractionalBits)));
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void)const
{
    return(this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
    this->rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return(static_cast<float>(this->rawBits) / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return(this->rawBits >> fractionalBits);
}

bool Fixed::operator>(Fixed const &other) const
{
    return(this->rawBits > other.rawBits);
}

bool Fixed::operator<(Fixed const &other) const
{
    return(this->rawBits < other.rawBits);
}

bool Fixed::operator>=(Fixed const &other) const
{
    return(this->rawBits >= other.rawBits);
}

bool Fixed::operator<=(Fixed const &other) const
{
    return(this->rawBits <= other.rawBits);
}

bool Fixed::operator==(Fixed const &other) const
{
    return(this->rawBits == other.rawBits);
}   

bool Fixed::operator!=(Fixed const &other) const
{
    return(this->rawBits != other.rawBits);
}

Fixed Fixed::operator+(Fixed const &other)
{   
    Fixed result;

    result.setRawBits(this->rawBits + other.rawBits);
    return(result);
}

Fixed Fixed::operator-(Fixed const &other)
{   
    Fixed result;

    result.setRawBits(this->rawBits + other.rawBits);
    return(result);
}

Fixed Fixed::operator*(Fixed const &other)
{   
    Fixed result;

    result.setRawBits(static_cast<int>(static_cast<long long>(this->rawBits) * other.rawBits) >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(Fixed const &other)
{
    Fixed result;

    result.setRawBits(static_cast<int>((static_cast<long long>(this->rawBits) << fractionalBits) / other.rawBits));
    return(result);
}

Fixed Fixed::operator++()
{
    ++this->rawBits;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++this->rawBits;
    return(temp);
}

Fixed Fixed::operator--()
{
    --this->rawBits;
    return(*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --this->rawBits;
    return(temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a > b)
        return(b);
    else
        return(a);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out<<fixed.toFloat();
    return(out);
}

Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return(const_cast<Fixed &>(b));
    else
        return(const_cast<Fixed &>(a));
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return(a);
    else
        return(b);
}

Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return(const_cast<Fixed &>(a));
    else    
        return(const_cast<Fixed &>(b));
}
