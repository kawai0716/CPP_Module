/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:45:13 by marvin            #+#    #+#             */
/*   Updated: 2025/09/25 09:45:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hitpoints(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " deleted." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points <= 0 || hitpoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to attack." << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitpoints -= amount;
    if (hitpoints > 0) 
    {
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitpoints << std::endl;
        return;
    }
    hitpoints = 0;
    std::cout << "ClapTrap " << name << " died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points <= 0 || hitpoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to repair." << std::endl;
        return;
    }
    else if(amount == 0)
    {
        std::cout << "ClapTrap " << name << " cannot repair for 0 points." << std::endl;
        return;
    }
    energy_points--;
    hitpoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " points! New hit points: " << hitpoints << std::endl;
}
