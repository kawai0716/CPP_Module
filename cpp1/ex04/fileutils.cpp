/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileutils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:58:32 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 11:58:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileutils.hpp"

bool readfile(const std::string &filename, std::string &out)
{
    std::ifstream ifs(filename.c_str());
    if(!ifs)
        return false;
    std::string line;
    std::string buf;
    while(std::getline(ifs,line))
    {
        buf += line;
        if(!ifs.fail())
            buf+='\n';
    }
    if(buf.empty())
        return false;
    out.swap(buf);
    return true;
}

std::string replace_all(const std::string &str, const std::string &s1, const std::string &s2)
{
    std::string out;
    out.reserve(str.size());
    std::string::size_type pos = 0;
    while(true)
    {
        std::string::size_type found = str.find(s1,pos);
        if(found == std::string::npos)
        {
            out.append(str,pos);
            break;
        }
        out.append(str,pos,found - pos);
        out.append(s2);
        pos = found + s1.size();
    }
    return out;
}

bool write_all(const std::string &filename, const std::string &data)
{
    std::ofstream ofs(filename.c_str());
    if(!ofs)
        return false;
    ofs << data;
    return static_cast<bool>(ofs);
}