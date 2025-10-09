/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 00:53:21 by marvin            #+#    #+#             */
/*   Updated: 2025/10/06 00:53:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for(int i = 0; i < 4; ++i)
        book_[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for(int i = 0; i < 4; ++i)
        book_[i] = 0;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &other) {
        for(int i = 0; i < 4; ++i)
            delete book_[i];
        for(int i = 0; i < 4; ++i)
            if (other.book_[i])
                book_[i] = other.book_[i]->clone();
            else
                book_[i] = 0;
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for(int i = 0; i < 4; ++i)
    {
        delete book_[i];
        book_[i] = 0;
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if(!m)
        return;
    for(int i = 0; i < 4; ++i)
    {
        if(!book_[i])
        {
            book_[i] = m;
            std::cout << "Learned materia of type: " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << "Materia book full, cannot learn more materia" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for(int i = 0;i < 4; ++i)
    {
        if(book_[i] && book_[i]->getType() == type)
        {
            std::cout << "Creating materia of type: " << type << std::endl;
            return book_[i]->clone();
        }
    }
    std::cout << "Materia of type: " << type << " not found" << std::endl;
    return 0;
}