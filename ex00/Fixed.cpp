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
        this->rawBits = other.rawBits;
    return(*this);
}
Fixed::~Fixed()
{
    std::cout<<"Destrutor called"<<std::endl;
}
int Fixed::getRawBits() const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return(rawBits);
}
void Fixed::setRawBits(int const raw)
{
    this->rawBits = raw;
}