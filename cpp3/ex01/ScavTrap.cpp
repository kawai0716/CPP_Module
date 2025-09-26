/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:04:52 by marvin            #+#    #+#             */
/*   Updated: 2025/09/25 12:04:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitpoints = 100;
    energy_points = 50;
    attack_damage = 20;

    std::cout << "ScavTrap " << name << " created." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " deleted." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_points <= 0 || hitpoints <= 0)
    {
        std::cout << "ScavTrap " << name << " has no energy or hit points left to attack." << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
