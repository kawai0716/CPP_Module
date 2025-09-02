/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:15:02 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 19:15:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if(ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for(int i = 1; i < ac; ++i)
    {
        for(int j = 0; av[i][j] ; ++j)
        {
            unsigned char c = (unsigned char)av[i][j];
            std::cout << (char)(std::toupper(c));
        }
        if(i + 1 < ac)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
