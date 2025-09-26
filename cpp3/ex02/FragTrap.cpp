/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:29:53 by marvin            #+#    #+#             */
/*   Updated: 2025/09/25 14:29:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitpoints = 100;
    energy_points = 100;
    attack_damage = 30;

    std::cout << "FragTrap " << name << " created." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " deleted." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
