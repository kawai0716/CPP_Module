/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:45:15 by marvin            #+#    #+#             */
/*   Updated: 2025/09/25 09:45:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("kawai");
    DiamondTrap b("you");

    a.attack("you");
    b.FragTrap::takeDamage(30);
    
    b.attack("kawai");
    a.ScavTrap::takeDamage(30);

    a.ScavTrap::beRepaired(10);
    b.FragTrap::beRepaired(30);

    a.whoAmI();
    b.whoAmI();

    return 0;
}
