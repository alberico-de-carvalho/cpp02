#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int rawBits;
        static const int fracionalBits = 8;
    public:
        Fixed();
        Fixed(Fixed const &other);
        Fixed &operator=(Fixed const &other);
        
};