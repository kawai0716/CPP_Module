/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:16:45 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 16:16:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("noname"), floor_count_(0) 
{
    std::cout << "Character default constructor called" << std::endl;
    for(int i = 0; i < 4; ++i)
        inventory_[i] = 0;
    for(int i = 0; i < 100; ++i)
        floor_[i] = 0;
}

Character::Character(const std::string& name) : name_(name), floor_count_(0) 
{
    std::cout << "Character parameterized constructor called" << std::endl;
    for(int i = 0; i < 4; ++i)
        inventory_[i] = 0;
    for(int i = 0; i < 100; ++i)
        floor_[i] = 0;
}

Character::Character(const Character& other) : name_(other.name_), floor_count_(0) 
{
    std::cout << "Character copy constructor called" << std::endl;
    for(int i = 0; i < 100; ++i)
        floor_[i] = 0;
    cloneFrom(other);
}

Character& Character::operator=(const Character &other) 
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &other) {
        clearInventory();
        name_ = other.name_;
        cloneFrom(other);
    }
    return *this;
}

Character::~Character() 
{
    std::cout << "Character destructor called" << std::endl;
    clearInventory();
    for(int i = 0; i < floor_count_; ++i)
        delete floor_[i];
}

void Character::clearInventory() 
{
    for (int i = 0; i < 4; ++i)
    {
        delete inventory_[i];
        inventory_[i] = 0;
    }
}

void Character::cloneFrom(const Character& other) 
{
    for (int i = 0; i < 4; ++i) {
        if (other.inventory_[i])
            inventory_[i] = other.inventory_[i]->clone();
        else
            inventory_[i] = 0;
    }
}

void Character::dropToFloor(AMateria* m)
{
    std::cout << "Dropping materia to floor" << std::endl;

    if(!m)
        return;

    if(floor_count_ == 100)
        floor_count_ = 0;
    
    if(floor_[floor_count_])
        delete floor_[floor_count_];

    floor_[floor_count_++] = m;
}

const std::string& Character::getName() const 
{
    return name_;
}

void Character::equip(AMateria* m)
{
    if(!m)       
        return;
    for(int i = 0; i < 4; ++i)
    {
        if(!inventory_[i])
        {
            inventory_[i] = m;
            std::cout << "Equipped " << m->getType() << " materia in slot " << i << std::endl;
            return;
        }
    }
    std::cout << "Inventory full, cannot equip " << m->getType() << " materia" << std::endl;
    dropToFloor(m);
}

void Character::unequip(int idx) 
{
    if (idx < 0 || idx >= 4)
        return;
    if (!inventory_[idx]) {
        std::cout << "No materia to unequip in slot " << idx << std::endl;
        return;
    }
    std::cout << "Unequipping " << inventory_[idx]->getType() << " materia from slot " << idx << std::endl;
    dropToFloor(inventory_[idx]);
    inventory_[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if(idx < 0 || idx >= 4)
        return;
    if(!inventory_[idx])
    {
        std::cout << "No materia to use in slot " << idx << std::endl;
        return;
    }
    inventory_[idx]->use(target);
}