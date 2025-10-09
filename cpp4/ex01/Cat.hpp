/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 21:42:51 by marvin            #+#    #+#             */
/*   Updated: 2025/09/26 21:42:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat &other);
        virtual ~Cat();

        void makeSound() const;

        void setIdea(int index, const std::string &idea);
        std::string getIdea(int index) const;
};

#endif
