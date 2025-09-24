/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:49:47 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 11:49:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileutils.hpp"

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cout << "Invalid parameters" << std::endl;
        return 1;
    }

    const std::string filename = av[1];
    const std::string target  = av[2];
    const std::string change = av[3];

    if(target.empty())
    {
        std::cout << "Target or change string must not be empty" << std::endl;
        return 1;
    }

    std::string input;
    if(!readfile(filename,input))
    {
        std::cout << "Failed to read file: " << filename << std::endl;
        return 1;
    }

    const std::string output = replace_all(input,target,change);
    const std::string outfilename = filename + ".replace";
    if(!write_all(outfilename,output))
    {
        std::cout << "Failed to write file: " << outfilename << std::endl;
        return 1;
    }
    return 0;
}