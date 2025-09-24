/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:21:22 by marvin            #+#    #+#             */
/*   Updated: 2025/08/26 13:21:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>


class Weapon
{
    private:
        std::string type;
    public:
        Weapon(const std::string &t);
        const std::string &getType() const;
        void setType(const std::string &t);
};

#endif