/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:35:00 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 19:35:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int                _value;
        static const int    _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed &other);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
        Fixed(const int n);
        Fixed(const float f);
        int toInt() const;
        float toFloat() const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
