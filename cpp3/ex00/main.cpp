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

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("kawai");
    ClapTrap b("you");

    a.attack("you");
    b.takeDamage(0);
    
    b.attack("kawai");
    a.takeDamage(0);

    a.beRepaired(1);
    b.beRepaired(3);

    return 0;
}
