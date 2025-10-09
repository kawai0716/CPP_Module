/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:37:44 by marvin            #+#    #+#             */
/*   Updated: 2025/09/27 17:37:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog &other);
        virtual ~Dog();

        virtual void makeSound() const;
};

#endif
