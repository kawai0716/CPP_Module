/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:14 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 21:50:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    Fixed x(10.5f), y(10.5000f), z(3);
    std::cout << std::boolalpha
              << (x == y) << " " << (x != z) << " "
              << (x > z) << " " << (x <= y) << std::endl;

    std::cout << (x + z) << " " << (x - z) << " "
              << (x * z) << " " << (x / z) << std::endl;

    Fixed i( 10 ), j( 20 );
    Fixed k = Fixed::min(i, j);
    std::cout << "min(i,j) = " << k << std::endl;
    k.setRawBits(256);
    std::cout << "k = " << k << "\ni = " << i << std::endl;

    Fixed& m = Fixed::min(i, j);
    std::cout << "min(i,j) = " << m << std::endl;
    m.setRawBits(256);
    std::cout << "m = " << m << "\ni = " << i << std::endl;

    return 0;
}
