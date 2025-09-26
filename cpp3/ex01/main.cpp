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

#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("kawai");
    ScavTrap b("you");

    a.attack("you");
    b.takeDamage(20);
    
    b.attack("kawai");
    a.takeDamage(20);

    a.beRepaired(0);
    b.beRepaired(30);

    a.guardGate();
    b.guardGate();

    return 0;
}
