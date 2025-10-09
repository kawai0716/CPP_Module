/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:55:17 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 15:55:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name_;
        AMateria* inventory_[4];

        AMateria* floor_[100];
        int floor_count_;
        
        void clearInventory();
        void cloneFrom(const Character& other);
        void dropToFloor(AMateria* m);
    public:
        Character();
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character &other);
        ~Character();

        virtual const std::string& getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif
