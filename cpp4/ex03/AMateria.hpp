/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:55:28 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 20:55:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria 
{
    protected:
        std::string type_;
    public:
        AMateria();
        AMateria(const std::string& type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria &other);
        virtual ~AMateria();

        const std::string& getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
