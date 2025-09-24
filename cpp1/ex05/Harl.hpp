/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:07:10 by marvin            #+#    #+#             */
/*   Updated: 2025/09/22 19:07:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Harl {
   private:
    void debug();
    void info();
    void warning();
    void error();

   public:
    void complain(const std::string &level);
};

#endif
