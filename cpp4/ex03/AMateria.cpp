/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:28:17 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 14:28:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type_("undefined") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) :type_(type) {
    std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type_(other.type_) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other) {
    std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &other) {
        type_ = other.type_;
    }
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

const std::string& AMateria::getType() const {
    return type_;
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "* does nothing *" << std::endl;
}
