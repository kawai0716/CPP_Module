/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileutils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:51:52 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 11:51:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEUTILS_HPP
#define FILEUTILS_HPP

#include <string>
#include <fstream>
#include <iostream>

bool readfile(const std::string &filename, std::string &out);

std::string replace_all(const std::string &str, const std::string &s1, const std::string &s2);

bool write_all(const std::string &filename, const std::string &data);

#endif