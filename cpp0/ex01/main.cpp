/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:42:53 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 20:42:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <sstream>

static bool getline_prompt(const char* label, std::string& out)
{
    std::cout << label;
    if(!std::getline(std::cin, out))
        return false;
    return true;
}

static bool do_add(Phonebook& pb)
{
    std::string f,l,n,p,s;
    if(!getline_prompt("First Name: ", f)) return false;
    if(!getline_prompt("Last Name: ", l)) return false;
    if(!getline_prompt("Nickname: ", n)) return false;
    if(!getline_prompt("Phone Number: ", p)) return false;      
    if(!getline_prompt("Darkest Secret: ", s)) return false;
    Contact c;
    if(!c.setField(f, l, n, p, s))
    {
        std::cout << "Invalid contact information." << std::endl;
        return true; // 無効な情報は無視して続行
    }
    if(!pb.add(c))
    {
        std::cout << "Phonebook is full." << std::endl;
    }
    return true;
}

static bool prase_int_string(const std::string& s, int& out)
{
    std::istringstream iss(s);
    int v; char extra;
    if (!(iss >> v)) return false;           // 数字で始まらない
    if (iss >> extra) return false;          // 末尾に余計な文字
    out = v;
    return true;
}

static bool do_search(const Phonebook& pb)
{
    pb.list();
    if(pb.size() == 0)
    { 
        std::cout << "No contacts available." << std::endl;
        return true; // 空のときは何もしないで続行
    }
    std::string idx;
    if(!getline_prompt("Index: ", idx))
        return false; // 入力エラー
    
    int i;
    if(!prase_int_string(idx,i))
    {
        std::cout << "Invalid index" << std::endl;
        return true; // 無効なインデックスは無視して続行
    }
    pb.showDetail(i);
    return true; // 成功したので true を返す
}

int main()
{
    Phonebook pb;
    std::string cmd;

    while(true)
    {
        std::cout << "Command (ADD / SEARCH / EXIT): ";
        if(!std::getline(std::cin, cmd))
            break;
        if(cmd == "ADD")
        {
            if(!do_add(pb))
                break;
        }
        else if(cmd == "SEARCH")
        {
            if(!do_search(pb))
                break;
        }
        else if(cmd == "EXIT")
        {
            break;
        }
        else if(cmd.empty())
        {
        }
        else{}
    }
    return 0;
}