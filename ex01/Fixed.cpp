#include "Fixed.hpp"

Fixed::Fixed():rawBits(0) 
{
    std::cout<<"Default constructor called"<<std::endl;
} 

Fixed::Fixed(Fixed const &other)
{   
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other;
}

Fixed &Fixed::operator=(Fixed const &other)
{   
    std::cout<<"Copy assigment operator called"<<std::endl;
    if (this != &other)
    {
        this->rawBits = other.rawBits;
    }
    return(*this);
}

Fixed::Fixed(int const number)
{   
    std::cout<<"Int constructor called"<<std::endl;
    this->rawBits = number << fractionalBits;
} 

Fixed::Fixed(float const number)
{   
    std::cout<<"Float construtor called"<<std::endl;
    this->rawBits = static_cast<int>(roundf(number * (1 << fractionalBits)));
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out<<fixed.toFloat();
    return(out);
}
