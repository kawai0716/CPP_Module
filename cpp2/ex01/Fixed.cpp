/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:35:19 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 20:35:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other._value);
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits; //（= n * 256）
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

int Fixed::toInt() const
{
    return _value >> _fractionalBits; //（= _value / 256）
}

float Fixed::toFloat() const
{
    return static_cast<float>((float)_value / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
