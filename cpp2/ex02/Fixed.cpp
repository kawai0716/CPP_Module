/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:09 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 21:50:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0){}

Fixed::Fixed(const Fixed &other) : _value(other._value){}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->setRawBits(other._value);
    return *this;
}

Fixed::~Fixed(){}

int Fixed::getRawBits() const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

Fixed::Fixed(const int n)
{
    _value = n << _fractionalBits; //（= n * 256）
}

Fixed::Fixed(const float f)
{
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

bool Fixed::operator>(const Fixed &other) const
{
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_value++;
    return tmp;
}

Fixed& Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_value--;
    return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

