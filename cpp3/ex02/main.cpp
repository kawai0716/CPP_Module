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

#include "FragTrap.hpp"

int main()
{
    FragTrap a("kawai");
    FragTrap b("you");

    a.attack("you");
    b.takeDamage(30);
    
    b.attack("kawai");
    a.takeDamage(30);

    a.beRepaired(1);
    b.beRepaired(3);

    a.highFivesGuys();
    b.highFivesGuys();

    return 0;
}
